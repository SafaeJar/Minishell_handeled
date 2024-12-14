/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_rdr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:17:16 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/14 02:22:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	get_heredoc_l(char *f, int fd, char *line, bool expand)
{
	t_token	expanded;
	t_lexer	*lexer;

	if (expand)
	{
		lexer = lex_init(line);
		expanded = lex_var(*lexer, ft_strlen(lexer->input_string));
		if (!expanded.position)
		{
			close(fd);
			unlink(f);
			free(f);
			free(line);
			return (-1);
		}
		put_line(expanded.position, fd);
		free(lexer);
		free(expanded.position);
	}
	else
		put_line(line, fd);
	return (0);
}

static int	heredoc_handler(char *f, char *delim, bool expand)
{
	int		fd;
	char	*line;

	fd = open(f, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("minishel: ", 2);
		ft_putstr_fd(f, 2);
		ft_putstr_fd(": ", 2);
		printf("minishell: %s:\n", strerror(errno));
		return (-1);
	}
	line = readline(">");
	while (line)
	{
		signal(SIGINT, SIG_IGN);
		if (g_var.check_sigint == 1 || !ft_strcmp(line, delim))
			break ;
		if (get_heredoc_l(f, fd, line, expand))
			return (-1);
		free(line);
		line = readline(">");
	}
	free(line);
	close(fd);
	return (0);
}

static char	*heredoc_filename(t_token t, char *delim)
{
	char		*file;
	static int	i = 0;
	bool		exp;
	char		*n_file;

	exp = !ft_memchr(t.position, DEF_SINGEL_Q, t.len);
	exp = (exp && !ft_memchr(t.position, DEF_DOUBEL_Q, t.len));
	n_file = ft_itoa(i);
	if (delim)
		remove_q(delim);
	if (n_file)
		file = ft_strjoin("/tmp/minishell-heredoc-", n_file);
	free(n_file);
	if (!delim || !n_file || !file || heredoc_handler(file, delim, exp))
	{
		printf("minishell: %s:\n", strerror(errno));
		free(delim);
		free(file);
		return (NULL);
	}
	free(delim);
	i++;
	return (file);
}

static char	*rdr_filename(t_token file)
{
	char	*s;

	if (file.type == VARIABLE)
		s = ft_substr(file.position, 0, ft_strlen(file.position));
	else
		s = ft_substr(file.position, 0, file.len);
	return (s);
}

t_redirect_node	*collect_rdr(t_lexer *lexer, t_redirect_node *rdr,
		t_token token)
{
	token = get_next_token(lexer);
	if (token.type != WORD && token.type != VARIABLE)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token", 2);
		if (token.position && token.len > 0)
		{
			write(2, "'", 1);
			ft_putnstr(token.position, token.len, 2);
			write(2, "'\n", 2);
		}
		else
		{
			ft_putstr_fd("`newline'\n", 2);
		}
		return ((void *)-1);
	}
	rdr = malloc(sizeof(t_redirect_node));
	if (!rdr)
	{
		perror("minishell");
		return (NULL);
	}
	rdr->next = NULL;
	rdr->type = lexer->prev_token.type;
	if (rdr->type == HEREDOC)
		rdr->file = heredoc_filename(token, ft_substr(token.position, 0,
					token.len));
	else
		rdr->file = rdr_filename(token);
	if (rdr->file)
		return (rdr);
	free(rdr);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_rdr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarfi <sjarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:14:17 by sjarfi            #+#    #+#             */
/*   Updated: 2024/12/15 00:15:42 by sjarfi           ###   ########.fr       */
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
		heredoc_handler_helper(f);
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
		collect_rdr_helper(token);
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

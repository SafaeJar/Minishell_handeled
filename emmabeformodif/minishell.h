#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
#include <stddef.h>

# define DEF_SINGEL_Q -1
# define DEF_DOUBEL_Q -2
// typedef struct	s_envi_node
// {
//     char	*name;
//     char	*content;
//     int		len;
//     struct	s_envi_node *next;
// }				t_envi_node;
// typedef struct s_cmd
// {
// 	char			**arg;
// 	int				argc;
// 	char			**file;//Store redirection files.
// 	char			**heredoc;//Store heredocs.
// 	char			*path;// cmd line
// 	char			**cmd_path;//the path where they can execute 
// 	char			*valid_cmd_path;//the path where it found the cmd line
// }					t_cmd;
// /* echo "hello, world" > output.txt
//     .arg = {"echo", "Hello, world", NULL},
//     .argc = 2,
//     .file = {"output.txt", NULL},
//     .heredoc = NULL,
//     .path = "echo",
//     .cmd_path = {"/bin/echo", "/usr/bin/echo", NULL},
//     .valid_cmd_path = "/bin/echo"
// };*/

// typedef enum e_token_type// Defines types of tokens recognized by the shell.helping to categorize different parts of a command.
// {
// 	TYPE_PIPE,// |
// 	TYPE_COMMAND,// ls - echo - cat
// 	TYPE_ARG,// hello - ... (args that come with the cmd)
// 	TYPE_REDIRECT,// >>
// 	TYPE_REDIRECT_IN,//< cat < imane.txt
// 	TYPE_REDIRECT_OUT,//> echo hello > imane.txt
// 	TYPE_HEREDOC,// << delimeter cat << EOF
// 	TYPE_QUOTES,// " " ' ' echo "Hello, world"
// 	TYPE_ENV_VAR//$USER  that represents an environment variable.
// }								t_token_type;

// typedef struct s_node//: Represents a node in the command parse tree.
// {
// 	t_cmd			*cmd;
// 	t_token_type	type;
// 	int				fd_in;//: File descriptors for redirection.
// 	int				fd_out;//: File descriptors for redirection.
// 	struct s_node	*left;
// 	struct s_node	*right;
// }					t_node;
// typedef struct s_shell//The main shell structure holding all runtime data.
// {
// 	t_envi_node				*env;//Linked list of environment variables.
// 	int						status;//exit status.
// 	bool					heredoced;//Flags if heredoc was used.
// 	char					*line;//Stores the current input line from the user (echo hello)
// 	char					**env_arr;//Environment variables in an array.
// 	t_node					*node;//Root nodes for command trees.
// 	t_node					*new_tree;//Root nodes for command trees.
// 	t_lexer					*lexer;
// 	t_parser				*parser;
// 	t_history_entry			*history;//Command history.
// 	bool					signal;//Tracks signal handling status.
// }							t_shell;
///////////////////////////////////////////
typedef enum e_sig_state
{
	SIG_DEFAULT = 1,
	SIG_HEREDOC,
	SIG_CHILD,
	SIG_PARENT
}								t_sig_state;

typedef struct s_envi_node {
    char *name;
    char *content;
    int len;
    struct s_envi_node *next;
}			t_envi_node;

typedef enum token_type
{
	CHAR_NULL,
	TOK,
	ENDF,
	CMD,
	VAR,
	RD_IN,
	RD_OUT,
	HERDOC,
	RD_APP,
	PIPE,
	WORD,
	ERROR,
	END,
}					t_token_type;
typedef struct token
{
	int				len;
	char			*pos;
	t_token_type	type;
}					t_token;

typedef struct s_lexer
{
	char			*full_str;
	char			*str;
	t_token			prev_type;
	t_token			curent_type;
}					t_lexer;
typedef struct s_rdr_node
{
	t_token_type			type;
	char					*file;
	struct s_rdr_node		*next;
}			t_rdr_node;
typedef struct s_parser_node
{
	t_token_type			type;
	char					**av;
	int						ac;
	t_rdr_node				*rdrlst;
	struct s_parser_node	*left;
	struct s_parser_node	*right;
}			t_parser_node;
typedef struct s_wc_node
{
	char				*d_name;
	int					len;
	struct s_wc_node	*next;
}						t_wc_node;

typedef struct s_cmd
{
	t_wc_node			*wc;
	char				*word;
	struct s_cmd		*next;
}						t_cmd;
typedef struct s_out_in_file
{
	int	input_file;
	int	output_file;
}		t_out_in_file;
typedef struct s_shell_vars
{
	t_envi_node			*list;
	int				check_sigint;
	int				check_sigquit;
	int				exit_status;
}					t_shell_vars;

extern t_shell_vars		se;

//int			access_args(char **argv, int argc);
char *get_user_input(char *prompt);
void afficher_liste_env(void);
void        ft_list_remove_if(t_envi_node   **begin_list,void *data_ref);
t_envi_node *var_find(t_envi_node *env, char *s);
void	delete_env(t_envi_node *node);
int         env_listsize(t_envi_node *env);
t_envi_node *nv_node(char *content, char *name, int len);
t_envi_node *lstlast(t_envi_node *lst);
void add_dernier(t_envi_node **lst, t_envi_node *new);
t_envi_node *creer_envi(char **env);
void	_set_pwd(t_envi_node **lst);
void	_shell_level(t_envi_node **lst);
t_envi_node *add_env_node(t_envi_node *var, char *s);
void	handler(int signum);
void	child_sigint(int sig);
void	heredoc_sigint(int sig);
void	df_sigint(int sig);
// void	free_env(void);
void	execution(t_parser_node *node);
void	ft_pipe(t_parser_node *node);
void execute_right_cmd(int *fd, t_parser_node *right);
void execute_left_cmd(int *fd, t_parser_node *left);
void	run_command(t_parser_node *node);
void	ft_unset(t_parser_node *node);
void	unset_variable(char *argv, int *check);
void ft_pwd(void);
void	ft_exit(t_parser_node *node);
long long	ft_atol(char *str);
int	check_args(char *argv);
void ft_env(t_parser_node *node,int argc);
void	ft_check(void);
void ft_echo(t_parser_node *node,int argc);
int ft_check_n(char *str);
int	parse_export_variable(t_envi_node *node, int _op_error);
void	*concatenate_variable(t_envi_node *node);
int	validate_identifier(char *name, char *content, int len, int err_opt);
int	check_plus(char *name, char *content);
int	handle_parse_errors(t_envi_node *new, int parse_result, int *i);
void	ft_export(char **argv,int argc);
void	print_sorted_env(void);
void	intialise_len(void);
void	add_variables_to_env(char **argv, int index);
int	remove_variable_if_path_empty(t_envi_node *var_node, int *index);
t_envi_node	*create_new_node(char *variable_content);
t_envi_node	*find_min_variable();
t_envi_node	*find_max_variable(void);
void ft_cd(char *path,int argc);
void go_to_newpath(const char *path,char *current_dir);
void go_to_oldpath(t_envi_node *oldpwd,char *current_dir);
void go_to_home(char *current_dir);
void update_env_var(t_envi_node **env_list, char *name, char *content);
void    add_new_env_var(t_envi_node **env_list, char *name, char *content);
/////////////////////////////////
void	*rdr_input(t_parser_node *n, t_rdr_node *l, t_out_in_file *file, int v);
void	*rdr_output(t_parser_node *n, t_rdr_node *l, t_out_in_file *file, int v);
void	*herdoc_(t_parser_node *n, t_rdr_node *l, t_out_in_file *file, int v);
char	*get_herdoc_file(t_rdr_node *rdrlst);
void	redirection(t_parser_node *node);
int		check_path(char *path);
void	*launch_executabl(t_parser_node *root, int size);
char	**copy_env(int size, int index);
void	copy_argv_for_execve(char **root_argv, char **args, char *first_arg);
int		execute_file(char *path, char **argv, char **env, int v);
void	*searsh_in_path(char *path, char **argv, char **env, char **args);
void	free_path_content(char **split_content);
t_parser_node	*check_pipe(t_lexer *lexer);
t_parser_node	*ft_pipe_line(t_lexer *lexer);
t_parser_node	*collect_cmd(t_lexer *lexer);
t_parser_node	*parse(char *input);
t_parser_node	*parse_input(t_lexer *lexer);
t_cmd			*cmd_ccomponents(t_lexer *lexer, t_rdr_node	**rdr);
t_parser_node	*node_create(t_cmd **av, t_rdr_node *rdrlist, t_token_type tp);
char			**av_creat(t_cmd **list);
t_rdr_node		*collect_rdr(t_lexer	*lexer, t_rdr_node	*rdr,
					t_token	token);
void			rdr_addback(t_rdr_node **lst, t_rdr_node *_new);
void			node_del(t_parser_node **node);
void			node_ptr(t_parser_node **node, t_parser_node *left,
					t_parser_node *right);
void			rdr_clear(t_rdr_node **lst);
void			print_error(t_token token);
void			handle_signal(int state);
int					change_mode(int i, char c);
char				*quote_def(char *str);
t_token				t_init(t_token_type _tp, int len, char *p);
t_token				lex_search(t_lexer lexer);
t_lexer				*lex_init(char *s);
t_token				word_collect(t_lexer *lexer, int var, int len);
t_token				get_token(t_lexer *lexer);
t_token				get_next_token(t_lexer *lexer);
t_token				check_next_token(t_lexer lexer, int i);
t_token				t_wc_init(t_token_type type, int len, t_wc_node *p,
						char *pos);
t_token				lex_var(t_lexer lexer, int len);
int					change_mode2(int i, char c);
char				*exp_var(char **sp);
char				*exit_status(char **s);
char				*ft_exp(char *expnd, char **s);
t_cmd					*ft_new_cmd(char *content, t_wc_node **list);
void					cmd_addback(t_cmd **lst, t_cmd *new);
t_cmd					*cmd_lstlast(t_cmd *lst);
t_wc_node				*lstlast_dir(t_wc_node *lst);
void					lstadd_back_dir(t_wc_node **lst, t_wc_node *new_ld);
t_wc_node				*lstnew_dir(char *content, int len);
int						wc_size(t_wc_node *lst);
int						cmd_size(t_cmd *lst);
void					wc_clear(t_wc_node **lst);
void					cmd_clear(t_cmd **lst);
char					*remove_q(char *s);
void					ft_clear_av(char **str);
void					put_line(char *line, int fd);
int						readline_hook(void);
void					intialize_signal(void);
void					check_sigquit_(void);
void					free_env_list(void);
const char				*get_wd(char *path);
char	*env_find2(t_envi_node *env, char *s, int len);
int	env_find3(t_envi_node *env, char *s);
void	delone_env(t_envi_node *node);
void	free_env(char **env, int index);
#endif
# Nom de l'exécutable
NAME = minishell

# Compilateur et options de compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

# Bibliothèque nécessaire pour readline
LIBS = -lreadline

# Fichiers source
SRCS = 	envirenement/creation_envi.c \
		envirenement/envi_list_util.c \
		envirenement/envi_utils2.c \
		envirenement/find_env.c \
		libft/ft_isdigit.c libft/ft_memset.c\
		libft/ft_strjoin.c libft/ft_strtrim.c\
		libft/ft_isprint.c libft/ft_strnstr.c\
		libft/ft_putchar_fd.c libft/ft_strlcat.c\
		libft/ft_substr.c libft/ft_atoi.c\
		libft/ft_itoa.c libft/ft_putendl_fd.c\
		libft/ft_strlcpy.c libft/ft_tolower.c\
		libft/ft_bzero.c libft/ft_putnbr_fd.c\
		libft/ft_strlen.c libft/ft_strchr.c\
		libft/ft_toupper.c libft/ft_calloc.c\
		libft/ft_memchr.c libft/ft_putstr_fd.c\
		libft/ft_strmapi.c libft/ft_isalnum.c\
		libft/ft_memcmp.c libft/ft_strncmp.c\
		libft/ft_isalpha.c libft/ft_split.c\
		libft/ft_memcpy.c libft/ft_memmove.c\
		libft/ft_lstadd_back.c libft/ft_lstadd_front.c\
		libft/ft_lstlast.c libft/ft_lstnew.c\
		libft/ft_lstsize.c\
		libft/ft_striteri.c\
		libft/ft_strdup.c libft/ft_strrchr.c\
		lexer/change_mode.c\
		lexer/ft_exp.c\
		lexer/ft_expand_var.c\
		lexer/get_next_token.c\
		lexer/get_token.c\
		lexer/initialisation.c\
		lexer/lex_search.c\
		lexer/quote_def.c\
		utils/utils.c\
		utils/cmd_list.c\
		utils/remove_q.c\
		utils/put_line.c\
		utils/wc_ld.c\
		utils/ft_clear_av.c\
		parsing/av_creat.c\
		parsing/check_pipe.c\
		parsing/cmd_components.c\
		parsing/collect_cmd.c\
		parsing/collect_rdr.c\
		parsing/ft_pipe_line.c\
		parsing/node_creat.c\
		parsing/node_del.c\
		parsing/parse_input.c\
		parsing/parser_start.c\
		parsing/rdr_addback.c\
		parsing/print_error.c\
		execution/execution_utils.c\
		execution/execution_utils2.c\
		execution/execution.c\
		execution/builtins/cd/ft_cd_utils.c\
		execution/builtins/cd/ft_cd.c\
		execution/builtins/ft_echo.c\
		execution/builtins/ft_env.c\
		execution/builtins/ft_pwd.c\
		execution/builtins/ft_unset.c\
		execution/builtins/export/ft_export_utils.c\
		execution/builtins/export/ft_parse_export.c\
		execution/builtins/export/ft_export.c\
		execution/builtins/ft_exit.c\
		execution/free_env.c \
		redirection/redirection.c\
		redirection/heredoc.c\
		redirection/rdr_input.c\
		redirection/rdr_output.c\
		signals.c main.c # Ajoute ici les autres fichiers source .c nécessaires

# Fichiers objets générés à partir des sources
OBJS = $(SRCS:.c=.o)

# Commande de nettoyage pour supprimer les fichiers objets
RM = rm -f

# Règle par défaut (compiler l'exécutable)
all: $(NAME)

# Règle pour créer l'exécutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

# Règle pour compiler les fichiers objets (.o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	$(RM) $(OBJS)

# Nettoyage complet, y compris l'exécutable
fclean: clean
	$(RM) $(NAME)

# Reconstruire entièrement
re: fclean all

# Éviter que "clean", "fclean", et "re" soient interprétés comme des fichiers
.PHONY: all clean fclean re

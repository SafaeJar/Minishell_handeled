#include "../minishell.h"

void	execute_rdr_output_cmd(t_parser_node *node, t_out_in_file *file)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		printf("minishell: %s\n", strerror(errno));
	else if (pid == 0)
	{
		dup2(file->output_file, STDOUT_FILENO);
		dup2(file->input_file, STDIN_FILENO);
		run_command(node);
		exit(0);
	}
	waitpid(pid, NULL, 0);
}

int	get_output_file(t_parser_node *node, t_rdr_node *head, t_out_in_file *file)
{
	if (head->type == RD_OUT && file->input_file != -1
		&& file->output_file != -1)
	{
		if (file->output_file != 1)
			close(file->output_file);
		file->output_file = open(head->file, O_CREAT | O_RDWR | O_TRUNC, 0777);
	}
	else if (head->type == RD_APP && file->input_file != -1
		&& file->output_file != -1)
	{
		if (file->output_file != 1)
			close(file->output_file);
		file->output_file = open(head->file, O_CREAT | O_RDWR | O_APPEND, 0777);
	}
	else if (head->type == RD_IN && file->output_file != -1
		&& file->input_file != -1)
		rdr_input(node, head, file, 0);
	if (file->output_file == -1 || file->input_file == -1)
	{
		if (head->file[0] == '\0')
			return (printf("minishell: !! ambiguous redirect\n"));
		return (printf("minishell: %s\n", strerror(errno)));
	}
	return (0);
}
void *rdr_output(t_parser_node *n, t_rdr_node *l, t_out_in_file *file, int v) {
    t_rdr_node *head = l;

    while (head) {
		get_output_file(n, head, file);
        if (file->output_file == -1 || file->input_file == -1) {
            return NULL; // Stop immediately on error
        }
        head = head->next;
    }

    if (v == 1 && file->input_file != -1 && file->output_file != -1) {
        execute_rdr_output_cmd(n, file); // Execute only once
    }
    return NULL;
}

// void	*rdr_output(t_parser_node *n, t_rdr_node *l, t_out_in_file *file, int v)
// {
// 	t_rdr_node	*head;

// 	head = l;
// 	while (head)
// 	{
// 		get_output_file(n, head, file);
// 		if (file->output_file == -1 || file->input_file == -1)
// 			return (NULL);
// 		head = head->next;
// 	}
// 	if (v == 1 && file->input_file != -1 && file->output_file != -1)
// 		execute_rdr_output_cmd(n, file);
// 	return (NULL);
//}

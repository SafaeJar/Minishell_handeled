#include "../../../minishell.h"


int handle_digit_start(char *name, char *content) {
    if (!*content)
        return printf("minishell: export: `%s': not a valid identifier\n", name);
    return printf("minishell: export: `%s=%s': not a valid identifier\n", name, content);
}


int handle_invalid_option(char *name) {
    printf("minishell: export: %s: invalid option\n", name);
    return printf("export: usage: export [name[=value]...] or export\n"), -1;
}


int check_invalid_characters(char *name, int len) {
    int j = -1;
    while (name[++j]) {
        if (((name[j] <= 64 && !ft_isdigit(name[j])) || (name[j] >= 91 && name[j] <= 96 && name[j] != '_') || name[j] >= 123)
            && name[len - 1] != '+') {
            return printf("export:: command not found\n");
        }
    }
    return 0;
}

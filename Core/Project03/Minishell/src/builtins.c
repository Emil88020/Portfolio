/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonarze <kkonarze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:27:08 by kkonarze          #+#    #+#             */
/*   Updated: 2025/02/12 10:01:48 by kkonarze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (0);
	printf("%s\n", cwd);
	return (1);
}

int	ft_cd(char *text, int *status)
{
	if (chdir(text) != 0)
	{
		*status = 2;
		printf("Error: No such file or directory\n");
	}
	return (1);
}

int	ft_echo(char **text, t_env_var *envp, int *status)
{
	int		i;
	int		new_line;

	new_line = 0;
	i = 0;
	while (!ft_strncmp(text[++i], "-n ", 3))
		new_line = 1;
	handle_special(text + 1, envp, 0, status);
	while (text[i])
	{
		if (check_redirections(text, i, envp))
			continue ;
		printf("%s", text[i++]);
	}
	if (!new_line)
		printf("\n");
	return (1);
}

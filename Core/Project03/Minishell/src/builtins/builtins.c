/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonarze <kkonarze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:27:08 by kkonarze          #+#    #+#             */
/*   Updated: 2025/02/13 11:26:59 by kkonarze         ###   ########.fr       */
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
	char	*tmp;

	new_line = 0;
	i = 0;
	while (!ft_strncmp(text[++i], "-n ", 3))
		new_line = 1;
	handle_special(&text, envp, 0, status);
	while (text[i])
	{
		tmp = ft_strdup(text[i]);
		free(text[i]);
		text[i] = ft_strtrim(tmp, " ");
		if (chck_redirc(text, i, envp))
		{
			free(tmp);
			continue ;
		}
		free(text[i]);
		text[i] = tmp;
		printf("%s", text[i++]);
	}
	new_line = !new_line && printf("\n");
	return (1);
}

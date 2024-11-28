/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonarze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:11:02 by kkonarze          #+#    #+#             */
/*   Updated: 2024/08/21 16:15:36 by kkonarze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	c;
	int		i;

	i = '0';
	while (i <= '9')
	{
		c = i;
		write(1, &c, 1);
		i++;
	}
}

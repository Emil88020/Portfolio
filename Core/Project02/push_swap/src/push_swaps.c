/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonarze <kkonarze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:30:59 by kkonarze          #+#    #+#             */
/*   Updated: 2025/01/09 14:29:35 by kkonarze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_stacks *stacks)
{
	int	tmp;

	if (stacks->size_a < 2)
		return ;
	tmp = stacks->st_a[0];
	stacks->st_a[0] = stacks->st_a[1];
	stacks->st_a[1] = tmp;
}

void	sb(t_stacks *stacks)
{
	int	tmp;

	if (stacks->size_b < 2)
		return ;
	tmp = stacks->st_b[0];
	stacks->st_b[0] = stacks->st_b[1];
	stacks->st_b[1] = tmp;
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}

void	pa(t_stacks *stacks)
{
	size_t	i;

	if (stacks->size_b == 0)
		return ;
	i = stacks->size_a;
	while (i > 0)
	{
		stacks->st_a[i] = stacks->st_a[i - 1];
		i--;
	}
	stacks->st_a[0] = stacks->st_b[0];
	stacks->size_a++;
	i = 0;
	while (i < stacks->size_b - 1)
	{
		stacks->st_b[i] = stacks->st_b[i + 1];
		i++;
	}
	stacks->size_b--;
}

void	pb(t_stacks *stacks)
{
	size_t	i;

	if (stacks->size_a == 0)
		return ;
	i = stacks->size_b;
	while (i > 0)
	{
		stacks->st_b[i] = stacks->st_b[i - 1];
		i--;
	}
	stacks->st_b[0] = stacks->st_a[0];
	stacks->size_b++;
	i = 0;
	while (i < stacks->size_a - 1)
	{
		stacks->st_a[i] = stacks->st_a[i + 1];
		i++;
	}
	stacks->size_a--;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonarze <kkonarze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:33:23 by kkonarze          #+#    #+#             */
/*   Updated: 2025/03/14 08:56:50 by kkonarze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrixes.h"

int	main(void)
{
	int matrix[3][3] = {
        {10,   23,  456},
        {789, 10,  11},
        {121, 314, 15}
    };
	print_matrix(matrix);
    
    return 0;
}

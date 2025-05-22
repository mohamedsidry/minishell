/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:31:57 by msidry            #+#    #+#             */
/*   Updated: 2025/05/15 14:40:15 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	ft_2dfree(char **arr)
{
	int	idx;

	idx = 0;
	if (!arr)
		return ;
	while (arr[idx])
	{
		free (arr[idx]);
		arr[idx] = NULL;
		idx++;
	}
	free (arr);
}

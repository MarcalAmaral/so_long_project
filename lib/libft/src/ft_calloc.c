/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:06:07 by myokogaw          #+#    #+#             */
/*   Updated: 2023/10/28 16:25:38 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	if (size == 0x0 || nmemb == 0x0)
		return (malloc(0));
	if ((nmemb * size) / size != nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr != NULL)
	{
		i = 0;
		while (i < (nmemb * size))
		{
			ptr[i] = 0x0;
			i++;
		}
	}
	return ((void *) ptr);
}

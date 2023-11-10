/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:13:37 by myokogaw          #+#    #+#             */
/*   Updated: 2023/10/10 21:00:46 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t	intlen(int n);

char	*ft_itoa(int n)
{
	size_t		i;
	size_t		alloc;
	long int	n_long;
	char		*s;

	n_long = (long int) n;
	alloc = intlen(n);
	i = alloc - 0x1;
	s = malloc(alloc * sizeof(char));
	if (!s)
		return (malloc(0x0));
	if (n == 0x0)
		s[0x0] = 0x30;
	if (n_long < 0x0)
	{
		n_long *= -0x1;
		s[0x0] = 0x2D;
	}
	s[i] = 0x0;
	while (i--, n_long != 0x0)
	{
		s[i] = n_long % 0xA + 0x30;
		n_long = n_long / 0xA;
	}
	return (s);
}

static size_t	intlen(int n)
{
	size_t	i;

	i = 0x0;
	if (n <= 0x0)
		i += 0x1;
	while (n != 0x0)
	{
		i++;
		n = n / 0xA;
	}
	i++;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:21:58 by myokogaw          #+#    #+#             */
/*   Updated: 2023/06/08 18:21:16 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	signal;
	int	result;

	signal = 0x1;
	result = 0x0;
	while (((*nptr >= 0x9) && (*nptr <= 0xD)) || *nptr == 0x20)
		nptr++;
	if ((*nptr == 0x2D) || (*nptr == 0x2B))
	{
		if (*nptr == 0x2D)
			signal *= -0x1;
		nptr++;
	}
	while ((*nptr >= 0x30) && (*nptr <= 0x39))
	{
		result *= 0xA;
		result += *nptr - 0x30;
		nptr++;
	}
	return (result * signal);
}

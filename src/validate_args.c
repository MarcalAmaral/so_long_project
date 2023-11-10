/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:09:38 by marvin            #+#    #+#             */
/*   Updated: 2023/11/05 12:09:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	arg_is_ext_ber(char *path)
{
	int		len;
	char	*extension;

	len = (int)ft_strlen(path);
	extension = ".ber";
	if (ft_strncmp(&path[len - 4], extension, 4) == 0)
		return (TRUE);
	else
		return (FALSE);
}

int	check_args(int argc, char **argv)
{
	if (argc == 2)
	{
		if (arg_is_ext_ber(*(argv + 1)))
			return (TRUE);
		else
			ft_printf("ERROR\n - Need a file with extension .ber.\n");
	}
	else
		ft_printf("ERROR\n - Wrong number of args.\n");
	return (FALSE);
}

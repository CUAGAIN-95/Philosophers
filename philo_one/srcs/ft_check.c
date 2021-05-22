/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:04:59 by yeonhlee          #+#    #+#             */
/*   Updated: 2021/05/22 20:46:26 by yeonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int		check_sign_num(char *str)
{
	int		i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isnum(str[i]))
			return (KO);
		i++;
	}
	return (OK);
}

static int		check_int_range(char *str)
{
	long	value;

	value = ft_atol(str);
	if (value < 0 || value > 2147483647)
		return (KO);
	return (OK);
}

static int		check_argv(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!check_sign_num(argv[i]) || !check_int_range(argv[i]))
			return (KO);
		i++;
	}
	return (OK);
}

int				check_argument(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (KO);
	if (!check_argv(argc, argv))
		return (KO);
	return (OK);
}

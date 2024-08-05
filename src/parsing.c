/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <mabboud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:30:21 by mabboud           #+#    #+#             */
/*   Updated: 2024/07/28 11:30:21 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	len_check_allowed_char(char	*str)
{
	int	i;
	int	only_space;

	i = 0;
	only_space = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9')
			&& str[i] != ' ' && str[i] != '+'
			&& str[i] != '-')
			error(false);
		if ((str[i] == '-' || str[i] == '+')
			&& (!(str[i + 1] >= '0' && str[i + 1] <= '9')))
			error(false);
		if (str[i] == ' ')
			only_space++;
		i++;
	}
	if (i == only_space)
		error(false);
	return (i);
}

static int	len_and_check_arg(int ac, char **arg)
{
	int		len;
	int		i;

	len = 0;
	i = 1;
	while (i < ac)
	{
		len += len_check_allowed_char(arg[i]);
		i++;
	}
	return (len);
}

char	*parsing(int ac, char **arg)
{
	char	*clean;
	int		len;
	int		i;
	int		j;

	len = len_and_check_arg(ac, arg);
	clean = malloc(sizeof(char) * (len + ac));
	if (!clean)
		return (NULL);
	i = 1;
	j = 0;
	while (i < ac)
	{
		while (*arg[i])
			clean[j++] = *arg[i]++;
		clean[j++] = ' ';
		i++;
	}
	clean[j] = '\0';
	return (clean);
}

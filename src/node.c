/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <mabboud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:30:15 by mabboud           #+#    #+#             */
/*   Updated: 2024/07/28 11:30:15 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	set_higher_lower(t_ht_list *ht_list, int nbr)
{
	if (nbr > ht_list->highest_a->nbr)
	{
		ht_list->highest_a = ht_list->bottom_a;
		ht_list->highest_a->nbr = nbr;
	}
	if (nbr < ht_list->lowest_a->nbr)
	{
		ht_list->lowest_a = ht_list->bottom_a;
		ht_list->lowest_a->nbr = nbr;
	}
}

static t_node	*append_node(int value, t_ht_list *ht_list)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->nbr = value;
	new->next = NULL;
	new->prev = ht_list->bottom_a;
	new->index = ht_list->length_a;
	if (ht_list->head_a == NULL)
	{
		ht_list->head_a = new;
		ht_list->bottom_a = new;
		ht_list->highest_a = new;
		ht_list->lowest_a = new;
	}
	else
	{
		ht_list->bottom_a->next = new;
		ht_list->bottom_a = new;
	}
	ht_list->length_a++;
	set_higher_lower(ht_list, value);
	return (new);
}

static char	*check_dup(int nbr, t_ht_list *ht_list, char	**arg_split)
{
	t_node	*current;
	t_node	*next;

	current = ht_list->head_a;
	while (current != NULL)
	{
		next = current->next;
		if (nbr == current->nbr)
		{
			ft_free(arg_split);
			error(ht_list);
		}
		current = next;
	}
	return (NULL);
}

static void	check_max(t_ht_list *ht_list, char	**arg_split)
{
	int	i;
	int	j;

	i = 0;
	while (arg_split[i])
	{
		j = 0;
		while (arg_split[i][j] == '0' || arg_split[i][j] == '+'
				|| arg_split[i][j] == '-')
			j++;
		if (ft_strlen(&arg_split[i][j]) > 11)
		{
			ft_free(arg_split);
			error(ht_list);
		}
		i++;
	}
}

void	init_node(char *arg, t_ht_list *ht_list)
{
	char	**arg_split;
	int		i;
	int		err;
	int		nbr;

	arg_split = ft_split(arg, ' ');
	free(arg);
	i = 0;
	err = 0;
	check_max(ht_list, arg_split);
	while (arg_split[i])
	{
		nbr = ft_atoi(arg_split[i++], &err);
		check_dup(nbr, ht_list, arg_split);
		append_node(nbr, ht_list);
		if (err)
		{
			ft_free(arg_split);
			error(ht_list);
		}
	}
	ft_free(arg_split);
}

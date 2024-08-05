/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <mabboud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:29:56 by mabboud           #+#    #+#             */
/*   Updated: 2024/07/28 11:29:56 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	free_target_list(t_ht_list *ht_list, char list)
{
	t_node	*current;
	t_node	*next;

	current = NULL;
	if (list == 'a')
		current = ht_list->head_a;
	else if (list == 'b')
		current = ht_list->head_b;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	free_list(t_ht_list *ht_list)
{
	free_target_list(ht_list, 'a');
	free_target_list(ht_list, 'b');
	free(ht_list);
}

void	error(t_ht_list *ht_list)
{
	write(1, "Error\n", 6);
	if (ht_list)
		free_list(ht_list);
	exit(1);
}

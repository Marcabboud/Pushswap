/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <mabboud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:30:37 by mabboud           #+#    #+#             */
/*   Updated: 2024/07/28 11:30:37 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_target(t_ht_list *ht_list, int target)
{
	int		index;
	t_node	*current;

	index = 0;
	current = ht_list->head_a;
	while (current->nbr != target)
	{
		index++;
		current = current->next;
	}
	if (index < ht_list->length_a / 2)
		while (ht_list->head_a->nbr != target)
			rotate(ht_list, 'a');
	else
		while (ht_list->head_a->nbr != target)
			reverse_rotate(ht_list, 'a');
	pb(ht_list);
}

static void	sort_three(t_ht_list *ht_list)
{
	if (ht_list->highest_a == ht_list->head_a)
		rotate(ht_list, 'a');
	else if (ht_list->head_a->next == ht_list->highest_a)
		reverse_rotate(ht_list, 'a');
	if (ht_list->head_a->nbr > ht_list->head_a->next->nbr)
		swap(ht_list, 'a');
}

static void	sort_four_five(t_ht_list *ht_list)
{
	push_target(ht_list, ht_list->lowest_a->nbr);
	push_target(ht_list, ht_list->lowest_a->nbr);
	if (ht_list->head_b->next
		&& ht_list->head_b->nbr < ht_list->head_b->next->nbr)
	{
		swap(ht_list, 'b');
	}
	sort_three(ht_list);
	while (ht_list->head_b)
		pa(ht_list);
}

static void	sort_big(t_ht_list *ht_list)
{
	int		*arr;
	int		higher_index;
	int		higher_nbr;

	arr = do_bubble(copy_arr(ht_list), ht_list->length_a);
	if (!arr)
		error(ht_list);
	set_b(ht_list, arr, ht_list->length_a);
	free(arr);
	while (ht_list->head_b)
	{
		higher_index = ht_list->highest_b->index;
		higher_nbr = ht_list->highest_b->nbr;
		if (higher_index != 0)
		{
			while (ht_list->head_b->nbr != higher_nbr)
			{
				if (higher_index <= (ht_list->length_b / 2))
					rotate(ht_list, 'b');
				else
					reverse_rotate(ht_list, 'b');
			}
		}
		pa(ht_list);
	}
}

void	sort(t_ht_list *ht_list)
{
	if (ht_list->length_a == 2)
		swap(ht_list, 'a');
	else if (ht_list->length_a == 3)
		sort_three(ht_list);
	else if (ht_list->length_a == 4 || ht_list->length_a == 5)
		sort_four_five(ht_list);
	else
		sort_big(ht_list);
}

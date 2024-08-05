/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <mabboud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:50:51 by mabboud           #+#    #+#             */
/*   Updated: 2024/07/28 11:50:51 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reverse_rotate(t_ht_list *ht_list, char list)
{
	t_node	*head;
	t_node	*bottom;
	t_node	*temp_bottom;

	head = get_head(ht_list, list);
	bottom = get_bottom(ht_list, list);
	if (!head || !head->next || !bottom)
		return ;
	temp_bottom = bottom;
	bottom = bottom->prev;
	if (bottom)
		bottom->next = NULL;
	temp_bottom->next = head;
	head->prev = temp_bottom;
	head = temp_bottom;
	update_headbottom(ht_list, head, bottom, list);
	if (list == 'a')
		write(1, "rra\n", 4);
	else if (list == 'b')
		write(1, "rrb\n", 4);
}

void	swap(t_ht_list *ht_list, char list)
{
	t_node	*head;
	t_node	*bottom;
	int		head_nbr;

	head = get_head(ht_list, list);
	bottom = get_bottom(ht_list, list);
	if (!head || !head->next || !bottom)
		return ;
	head_nbr = head->nbr;
	head->nbr = head->next->nbr;
	head->next->nbr = head_nbr;
	update_headbottom(ht_list, head, bottom, list);
	if (list == 'a')
		write(1, "sa\n", 3);
	else if (list == 'b')
		write(1, "sb\n", 3);
}

void	rotate(t_ht_list *ht_list, char list)
{
	t_node	*head;
	t_node	*bottom;
	t_node	*temp_head;

	head = get_head(ht_list, list);
	bottom = get_bottom(ht_list, list);
	if (!head || !bottom || !head->next)
		return ;
	temp_head = head;
	head = temp_head->next;
	head->prev = NULL;
	temp_head->prev = bottom;
	temp_head->next = NULL;
	bottom->next = temp_head;
	bottom = temp_head;
	update_headbottom(ht_list, head, bottom, list);
	if (list == 'a')
		write(1, "ra\n", 3);
	else if (list == 'b')
		write(1, "rb\n", 3);
}

void	pa(t_ht_list *ht_list)
{
	t_node	*head_b;

	if (ht_list->head_b == NULL)
		return ;
	head_b = ht_list->head_b;
	ht_list->head_b = ht_list->head_b->next;
	if (ht_list->head_b != NULL)
		ht_list->head_b->prev = NULL;
	head_b->next = ht_list->head_a;
	if (ht_list->head_a != NULL)
		ht_list->head_a->prev = head_b;
	ht_list->head_a = head_b;
	head_b->prev = NULL;
	if (ht_list->bottom_a == NULL)
	{
		ht_list->bottom_a = ht_list->head_a;
		if (ht_list->bottom_a->next != NULL)
			ht_list->bottom_a->next->prev = ht_list->bottom_a;
	}
	if (ht_list->head_b == NULL)
		ht_list->bottom_b = NULL;
	update_highest_lowest(ht_list);
	ht_list->length_a++;
	ht_list->length_b--;
	write(1, "pa\n", 3);
}

void	pb(t_ht_list *ht_list)
{
	t_node	*head_a;

	if (ht_list->head_a == NULL)
		return ;
	head_a = ht_list->head_a;
	ht_list->head_a = ht_list->head_a->next;
	if (ht_list->head_a != NULL)
		ht_list->head_a->prev = NULL;
	head_a->next = ht_list->head_b;
	if (ht_list->head_b != NULL)
		ht_list->head_b->prev = head_a;
	ht_list->head_b = head_a;
	head_a->prev = NULL;
	if (ht_list->bottom_b == NULL)
	{
		ht_list->bottom_b = ht_list->head_b;
		if (ht_list->bottom_b->next != NULL)
			ht_list->bottom_b->next->prev = ht_list->bottom_b;
	}
	if (ht_list->head_a == NULL)
		ht_list->bottom_a = NULL;
	update_highest_lowest(ht_list);
	ht_list->length_b++;
	ht_list->length_a--;
	write(1, "pb\n", 3);
}

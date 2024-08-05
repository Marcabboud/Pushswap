/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <mabboud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:29:46 by mabboud           #+#    #+#             */
/*   Updated: 2024/07/28 11:41:03 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*do_bubble(int *tab, int size)
{
	int		i;
	int		j;
	int		tmp;

	if (size <= 1 || tab == NULL)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

void	set_b(t_ht_list *ht_list, int *arr, int length_a)
{
	int		i;
	int		nbr;
	int		range;

	i = 0;
	range = get_ranges(ht_list);
	while (ht_list->head_a)
	{
		nbr = ht_list->head_a->nbr;
		if (range + i >= length_a)
			range = length_a - 1 - i;
		else if ((nbr > arr[i] && nbr <= arr[range + i]) || nbr <= arr[i])
		{
			pb(ht_list);
			if (nbr <= arr[i])
				rotate(ht_list, 'b');
			else
				if (ht_list->length_b >= 2
					&& ht_list->head_b->nbr < ht_list->head_b->next->nbr)
					swap(ht_list, 'b');
			i++;
		}
		else
			is_reversed(ht_list);
	}
}

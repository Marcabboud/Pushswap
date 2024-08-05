/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <mabboud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:31:03 by mabboud           #+#    #+#             */
/*   Updated: 2024/07/28 11:31:03 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct ht_list
{
	struct s_node	*highest_a;
	struct s_node	*highest_b;
	struct s_node	*lowest_a;
	struct s_node	*lowest_b;
	int				length_a;
	int				length_b;
	struct s_node	*head_a;
	struct s_node	*head_b;
	struct s_node	*bottom_a;
	struct s_node	*bottom_b;
}	t_ht_list;

typedef struct s_node
{
	int				nbr;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* errors.c */
void	error(t_ht_list *ht_list);
void	free_list(t_ht_list *ht_list);

/* parsing.c */
char	*parsing(int ac, char **arg);

/* node.c */
void	init_node(char *arg, t_ht_list *ht_list);

/* head_bottom.c */
t_node	*get_head(t_ht_list *ht_list, char list);
t_node	*get_bottom(t_ht_list *ht_list, char list);
void	update_headbottom(t_ht_list *ht_list, t_node *head,
			t_node *bottom, char list);

/* algo_utils.c*/
void	update_highest_lowest(t_ht_list *ht_list);

/* sorting.c */
void	sort(t_ht_list *ht_list);

/* commands.c */
void	swap(t_ht_list *ht_list, char list);
void	rotate(t_ht_list *ht_list, char list);
void	reverse_rotate(t_ht_list *ht_list, char list);
void	pa(t_ht_list *ht_list);
void	pb(t_ht_list *ht_list);

/* algos.c*/
int		*do_bubble(int *tab, int size);
void	set_b(t_ht_list *ht_list, int *arr, int length_a);

/* algo_utils.c*/
void	is_reversed(t_ht_list *ht_list);
bool	check_is_sort(t_node *a);
int		get_ranges(t_ht_list *ht_list);
int		*copy_arr(t_ht_list *ht_list);

int		ft_atoi(const char	*nptr, int *error_limits);
void	*ft_free(char **strs);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *c);

#endif

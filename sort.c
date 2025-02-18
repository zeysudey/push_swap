/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyilmaz <zyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:10:14 by zyilmaz           #+#    #+#             */
/*   Updated: 2025/02/18 17:22:10 by zyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_list **a)
{
	t_list	*new_node;

	new_node = *a;
	while (new_node && new_node->next)
	{
		if (new_node->value > new_node->next->value)
			return (0);
		new_node = new_node->next;
	}
	return (1);
}

void input_sort(t_list **a, t_list **b)
{
	int size;
	
	//burda bi daha sort kontrolü gerekli mi ki
	size = ft_lstsizepush(a);
	if (size == 2)
		ft_sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a);
	else if (size == 5)
		sort_five(a);
	else
		radix(a, b);
	
}
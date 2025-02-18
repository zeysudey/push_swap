/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyilmaz <zyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:57:21 by zyilmaz           #+#    #+#             */
/*   Updated: 2025/02/18 17:12:40 by zyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_split(char **tokens)
{
	int i;

	if (!tokens)
		return;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]); // Her bir stringi serbest bırak
		i++;
	}
	free(tokens); // Dizinin kendisini serbest bırak
}

void freelists(t_list **a)
{
	t_list *temp;

	while (*a)
	{
		temp = *a;
		*a = (*a)->next;
		free(temp);
	}
	*a = NULL; // Listenin başını NULL yap
}

void freelist(t_list **a)
{
	t_list *temp;

	while (*a)
	{
		temp = *a;
		*a = (*a)->next;
		free(temp);
	}
	free(a);
}

static t_list **createstack(t_list **a)
{
	a = malloc(sizeof(t_list *));
	if (!a)
	{
		freelist(a);
		put_err();
	}
	*a = NULL;
	return (a);
}
#include <stdio.h>

/*void print_stack(t_list **stack)
{
    t_list *temp;

    if (!stack || !*stack)
    {
        printf("Stack boş!\n");
        return;
    }

    temp = *stack; // Stack'in başlangıcına erişiyoruz
    while (temp)
    {
        printf("Value: %d, Index: %d\n", temp->value, temp->index);
        temp = temp->next;
    }
}*/


int main(int ac, char **av)
{
	t_list **a;
	t_list **b;

	if (ac == 1)
		return (0);
	if (av[1][0] == '\0')
		return (0);
	if (ac < 2)
		return (-1);
	a = NULL;
	b = NULL;
	a = createstack(a);
	b = createstack(b);
//trim fulspace kontrollerim yok sayılar tekrar ediyor mu vs bakmadım
	if (ac == 2)
		arg_count_two(av, a, b);
	else if (ac > 2)
		arg_count_t_plus(av, a, b);
	if (check_sort(a) == 0)
	{
		freelist(a);
		freelist(b);

		return (0);
	}
	//print_stack(a);
	b = malloc(sizeof(t_list *));
	b = NULL;
	input_sort(a,b);
	if (a)
		freelist(a);
	if (b)
		freelist(b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_counts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyilmaz <zyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:30:10 by zyilmaz           #+#    #+#             */
/*   Updated: 2025/02/18 18:07:08 by zyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void put_err()
{
	write(1, "Eroor\n", 6);
	exit(1);
}

static void push(t_list **a, int x)
{
    t_list *new;

    new = ft_lstnews(x); // Yeni bir düğüm oluştur
    ft_lstadd_backst(a, new); // Bağlı listenin sonuna ekle
	ft_index(a);

}


static void check_as(char **tokens, t_list **a, t_list **b)
{
	int i;

	i = 0;
	while (tokens[i])
	{
		if ((ft_atoi(tokens[i]) > 2147483647) || (ft_atoi(tokens[i]) < -2147483648) || ft_strlen(tokens[i]) > 11)
		{
			freelist(a);
			freelist(b);
			free_split(tokens);
			put_err();
		}
		push(a, ft_atoi(tokens[i]));
		i++;
	}
}

void arg_count_t_plus(char **av, t_list **a, t_list **b)
{
	int i;

	i = 1;
	while (av[i])
	{

		if ((ft_atoi(av[i]) > 2147483647) || (ft_atoi(av[i]) < -2147483648) || ft_strlen(av[i]) > 11)
		{
			freelist(a);
			freelist(b);
			put_err(); // bunu yaz
			exit(1);   // Bellek temizliği sonrası çıkış
		}
		push(a, ft_atoi(av[i]));
		i++;
	}
}

void arg_count_two(char **av, t_list **a, t_list **b)
{
	char **as;
	as = ft_split(av[1], ' ');
	if (!as) // Split başarısız olduysa çıkış yap
	{
		put_err();
		exit(1);
	}
	check_as(as, a, b);
	free_split(as);
}
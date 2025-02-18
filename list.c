/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyilmaz <zyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:38:06 by zyilmaz           #+#    #+#             */
/*   Updated: 2025/02/18 18:05:24 by zyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_lstsizepush(t_list **lst)
{
    t_list *stl;
    size_t i;

    stl = *lst;
    i = 0;
    while (stl != NULL)
    {
        stl = stl->next;
        i++;
    }
    return (i);
}
// Yeni düğüm oluşturma fonksiyonu
t_list *ft_lstnews(int content)
{
    t_list *node;

    node = (t_list *)malloc(sizeof(t_list));
    if (node == NULL)
        return (NULL);
    node->value = content;
    node->next = NULL;
    return (node);
}

// Bağlı listenin son elemanını bulma fonksiyonu
t_list *ft_lstlaststac(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next != NULL)
        lst = lst->next;
    return (lst);
}

// Bağlı listenin sonuna yeni bir düğüm ekleme fonksiyonu
void ft_lstadd_backst(t_list **lst, t_list *new)
{
    if (!*lst)
    {
        *lst = new;
        return;
    }
    ft_lstlaststac(*lst)->next = new;
}
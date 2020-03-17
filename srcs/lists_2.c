/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:40:11 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/23 17:40:47 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
----File lists_2.c----
Здесь описаны функции для работы с листами.

ft_new_room
Функция создает новый элемент листа, содержащий информацию о комнате.

ft_new_link
Функция создает новый элемент листа, содержащий информацию о всех линках комнаты
*/

#include <lem_in.h>

t_rooms		*ft_new_room()
{
	t_rooms	*new;

	new = (t_rooms *)ft_memalloc(sizeof(t_rooms));
    new->out_links = 0;
    new->inp_links = 0;
    new->lvl = -1;
	return (new);
}

t_ln		*ft_new_link(char *name)
{
	t_ln	*ln;

	ln = (t_ln *)malloc(sizeof(t_ln));
	ln->next = NULL;
	ln->name = ft_strdup(name);
	return (ln);
}

void        ft_links_del(t_ln **lnk)
{
    ft_strdel(&((*lnk)->name));
    //free((*lnk)->next);                 //<-------------abort
    (*lnk)->next = NULL;
}

void        ft_rm_del(t_rooms **room)
{
    t_ln    *tmp;
    t_ln    *pr_tmp;

    tmp = (*room)->links;
    ft_strdel(&((*room)->name));
    free((*room)->next);
    (*room)->next = NULL;
    while (tmp)
    {
        pr_tmp = tmp;
        tmp = tmp->next;
        ft_links_del(&pr_tmp);
    }
    free((*room)->links);
    (*room)->links = NULL;
}

void		ft_room_del(t_tb *table)
{
	t_rooms	*iter;
	t_rooms	*iter_pr;
	
	iter = table->rooms;
	while (iter)
	{
		iter_pr = iter;
		iter = iter->next;
		ft_rm_del(&iter_pr);
	}
    free(table->rooms);
}

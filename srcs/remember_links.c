/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remember_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:26:41 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/23 19:21:43 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
----File remember_links.c----
В этом файле описаны функции, записывающие все связи для каждой комнаты.
Если приходит строка: Name1-Name2, то для комнаты Name1 создастся связь с Name2 и наоборот одновременно.
Если связь уже существует, то ничего не произойдет.
*/

int		ft_write_link(t_ln *links, char *name)
{
	t_ln	*tmp;

	tmp = links;
	if (!tmp->next)
		if (ft_strcmp(tmp->name, name) == 0)
			return (0);
	while (tmp->next)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (0);
		tmp = tmp->next;
	}
	tmp->next = ft_new_link(name);
	return (1);
}

void	ft_write_links(t_rooms *room, char *r_name, char *l_name)
{
	while (ft_strcmp(room->name, r_name) != 0)
		room = room->next;
	if (room->num_of_links == 0)
		room->links = ft_new_link(l_name);
	else
		if (ft_write_link(room->links, l_name) == 0)
			return ;
	room->num_of_links++;
}

void	ft_remember_link(t_tb *table, char **args)
{
	t_rooms *room;

	room = table->rooms;
	ft_write_links(room, args[0], args[1]);
	ft_write_links(room, args[1], args[0]);
}

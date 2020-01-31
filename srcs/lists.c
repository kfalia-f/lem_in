/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:23:44 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/01/27 18:01:25 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_map	*ft_new_list()
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(*map));
	map->cont = NULL;
	map->next = NULL;
	return (map);
}

void	ft_new_tb(t_tb *table)
{
	table = (t_tb *)malloc(sizeof(*table));
	table->flag = 0;
	table->head = table->map;
}

void	ft_list_del(t_map **list)
{
	if ((*list)->cont)
		ft_strdel(&((*list)->cont));
	free(*list);
	*list = NULL;
}

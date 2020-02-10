/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:23:44 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/10 21:10:19 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_map			*ft_new_list()
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

void			ft_list_del(t_map **list)
{
	if ((*list)->cont)
		ft_strdel(&((*list)->cont));
	free(*list);
	*list = NULL;
}

unsigned int	ft_lst_lenght(t_map *map)
{
	unsigned int	i;
	t_map			*tmp;

	i = 0;
	tmp = map;
	while (tmp->cont)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void			ft_table_del(t_tb *table)
{
	t_map	*tmp;

	ft_putstr(table->head->cont);
	if (table->map)
		tmp = table->map->next;
	while (table->map->cont)
	{
		ft_list_del(&(table->map));           ////////////Bag
		ft_putstr("FLAG\n");
		table->map = tmp;
		if (table->map->next)
			tmp = table->map->next;
	}
	//free(table->map);
	//free(table->head);
	free(table);
}

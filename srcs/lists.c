/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:23:44 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/23 16:16:29 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_map			*ft_new_list(t_tb *table)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(*map));
	map->cont = NULL;
	map->next = NULL;
	table->map_len++;
	return (map);
}

void	ft_new_tb(t_tb *table)
{
	//table = (t_tb *)malloc(sizeof(*table));
	ft_bzero(table, sizeof(t_tb));
	table->flag = -1;
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
	while (tmp)
	{
		i++;
		//printf("%s\n", tmp->cont);
		tmp = tmp->next;
	}
	return (i);
}

void			ft_table_del(t_tb *table)
{
	t_map	*iter;
	t_map	*iter_pr;
	
	iter = table->map;
	while (iter)
	{
		iter_pr = iter;
		iter = iter->next;
		ft_list_del(&iter_pr);
	}
}

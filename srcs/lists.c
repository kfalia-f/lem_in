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

/*
----File lists.c----
Файл содержит функции для работы с листами

ft_new_list
Функция создает новый элемент листа, в который будет записан весь ввод из stdin
Здесь объявляются поля:
	map->cont - содержание входящей строки
	map->next - указатель на следующий элемент листа
	table->nap_len - увеличивается счетчик полученных строк

ft_new_tb
Функция объявляет и зануляет все поля таблицы
table->flag - флаг, определяющий на каком этапе находится валидация:
	0 - обработка количества муравьев
	1 - валидация комнат и их координат
	2 - валидация связей комнат
Флаг может принимать значения 3 (определяет следующий элемент как ##start) и 4 (##end)

ft_list_del
Функция чистит лист map

ft_lst_lenght
Функция определяет длину листа

ft_table_del
Функция очищает выделенную память под структуру table
*/

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
    ft_room_del(table);
}

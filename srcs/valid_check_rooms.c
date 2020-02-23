/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_rooms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:54:29 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/23 16:57:05 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		ft_check_arg(char *str, int i)
{
	int		num;

	if (str[i] == '\0')
		return (0);
	if ((num = ft_atoi(str + i)) < 0)
		return (0);
	while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_coord(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	if ((i += 1) && ft_check_arg(str, i) == 0)
		return (0);
	while (str[i] && str[i] != ' ')
		i++;
	if ((i += 1) && ft_check_arg(str, i) == 0)
		return (0);
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int     ft_check_room_help(char *str)
{
	int     i;
	int     sp;

	i = 0;
	sp = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			sp++;
		if (str[i] == '-')
			return (0);
		if (sp >= 3)
		{
			while (str[i] && (str[i] == ' ' || str[i] == '\t'))
				i++;
			if (str[i] != '\0')
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_write_to_room(t_rooms *tmp, char *str, int i, int flag)
{
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_new_room();
	tmp->next->name = ft_strndup(str, i); // <------------- here is sega
	if (flag == 4)
		tmp->next->r_flag = 2;
	else if (flag == 3)
		tmp->next->r_flag = 1;
	else
		tmp->next->r_flag = 0;
	//printf("%d, name = %s\n", tmp->next->r_flag, tmp->next->name);
}

void	ft_room(t_tb *table, char *str)
{
	unsigned int		i;
	t_rooms				*tmp;

	i = 0;
	tmp = table->rooms;
	while (str[i] && str[i] != ' ')
		i++;
	if (table->room_num != 0)
		ft_write_to_room(tmp, str, i, table->flag);
	else
	{
		tmp->name = ft_strndup(str, i);
	//printf ("i = %d, str = %s\n", i, str);
		if (table->flag == 4)
			tmp->r_flag = 2;
		else if (table->flag == 3)
			tmp->r_flag = 1;
		else
			tmp->r_flag = 0;
	}
	table->flag = 0;
}

int     ft_check_room(t_tb *table, char *str)
{
	if (ft_check_command(str) == 2)
		table->flag = 4;
	if (ft_check_command(str) == 1)
		table->flag = 3;
	if (ft_check_command(str) != 0)
		return (1);
	if (ft_check_lnk(str) == 1)
		return ((table->flag = 1));
	if (ft_check_room_help(str) == 0)
		return (0);
	if (ft_check_coord(str) == 0)
		return (0);
	if (table->room_num == 0)
	{
		table->rooms = ft_new_room();
		table->r_head = table->rooms;
	}
	ft_room(table, str);
//	if (table->flag == 4)
//		table->flag = 1;
	table->room_num++;
	return (1);
}

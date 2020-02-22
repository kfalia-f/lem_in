/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_rooms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:54:29 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/22 20:09:46 by kfalia-f         ###   ########.fr       */
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

void	ft_room(t_tb *table, char *str)
{
	unsigned int		i;
	t_rooms				*tmp;

	i = 0;
	tmp = table->rooms;
	if (table->room_num != 0)
	{
		while (tmp)
			tmp = tmp->next;
		tmp = ft_new_room();
	}
	while (str[i] && str[i] != ' ')
		i++;
	//printf ("i = %d, str = %s\n", i, str);
	tmp->name = ft_strndup(str, i); // <------------- here is sega
	if (table->flag == 4)
		tmp->r_flag = 2;
	else if (table->flag == 3)
		tmp->r_flag = 1;
	else
		tmp->r_flag = 0;
	printf("%d, name = %s\n", tmp->r_flag, tmp->name);
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
		table->rooms = ft_new_room();
	ft_room(table, str);
//	if (table->flag == 4)
//		table->flag = 1;
	table->room_num++;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_links.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:14:49 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/23 17:41:44 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		ft_check_lnk(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_minus(char *str)
{
	int		i;
	int		minus;

	i = 0;
	minus = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			if (minus != 0)
				return (0);
			else
				minus++;
		}
		i++;
	}
	if (minus == 0)
		return (0);
	return (1);
}

int		ft_check_largs(t_tb *table, t_rooms *head, char *str)
{
	int		i;
	char	**args;
	int		arg[2] = {0, 0};

	i = 0;
	args = ft_strsplit(str, '-');
	while (head)
	{
		//printf("arg = %s, name = %s\n", args[0], head->name);
		if (ft_strcmp(head->name, args[0]) == 0)
			arg[0] = 1;
		//printf("arg = %s, name = %s\n", args[1], head->name);
		if (ft_strcmp(head->name, args[1]) == 0)
			arg[1] = 1;
		head = head->next;
	}
	if (arg[0] == 1 && arg[1] == 1)
		ft_remember_link(table, args);
	ft_mass2del(&args);
	if (arg[0] == 1 && arg[1] == 1)
		return (1);
	return (0);
}

int		ft_check_start_end(t_rooms *head)
{
	t_rooms	*tmp;
	int		i;

	i = 0;
	tmp = head;
	while (tmp)
	{
		if (tmp->r_flag == 1)
			i++;
		if (tmp->r_flag == 2)
			i++;
		tmp = tmp->next;
	}
	//printf("I == %d\n", i);
	if (i != 2)
		return (0);
	return (1);
}

int		ft_check_links(t_tb *table, char *str)
{
	if (ft_check_minus(str) == 0)
		return (0);
	if (ft_check_start_end(table->rooms) == 0)
		ft_error_input(table, 3);
	if (ft_check_largs(table, table->r_head, str) == 0)
		return (0);
	return (1);
}

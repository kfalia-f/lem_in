/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_links.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:14:49 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/18 21:20:33 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

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

int		ft_check_largs(t_rooms *head, char *str)
{
	int		i;
	char	**args;
	int		arg[2] = {0, 0};

	i = 0;
	args = ft_strsplit(str, '-');
	while (head)
	{
		if (ft_strcmp(head->name, args[0]) == 0)
			arg[0] = 1;
		if (ft_strcmp(head->name, args[1]) == 0)
			arg[1] = 1;
		head = head->next;
	}
	ft_mass2del(&args);
	if (arg[0] == 1 && arg[1] == 1)
		return (1);
	return (0);
}

int		ft_check_links(t_tb *table, char *str)
{
	if (ft_check_minus(str) == 0)
		return (0);
	if (ft_check_largs(table->rooms, str) == 0)
		return (0);
	return (1);
}

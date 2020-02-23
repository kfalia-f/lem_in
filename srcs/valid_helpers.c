/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:09:49 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/23 16:36:45 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	ft_error_input(t_tb *table, int num)
{
	ft_putstr_fd("Error: Wrong input ", 2);
	if (num == 0)
		ft_putstr_fd("(wrong num of ants)\n", 2);
	else if (num == 1)
		ft_putstr_fd("(wrong room syntax)\n", 2);
	else if (num == 2)
		ft_putstr_fd("(wrong links syntax)\n", 2);
	else if (num == 3)
		ft_putstr_fd("(not enough information)\n", 2);
	ft_table_del(table);
	exit(EXIT_FAILURE);
}

int		ft_check_command(char *str) //-1 - comment or invalid command, 0 - not command, 1 - start, 2 - end
{
	if (!ft_strcmp(str, "##start"))
		return (1);
	else if (!ft_strcmp(str, "##end"))
		return (2);
	else if (str[0] == '#')
		return (-1);
	else
		return (0);
}

int		ft_check_first(t_tb *table, char *str)
{
	long long int		num;
	int					i;

	i = 0;
	if (ft_check_command(str) != 0)
		return (0);
	num = ft_atoi(str);
	if (num < 0)
		return (0);
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	table->flag = 0;
	return (1);
}

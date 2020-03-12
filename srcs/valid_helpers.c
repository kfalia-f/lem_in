/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:09:49 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/23 18:10:01 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
----File valid_helpers.c----
Все функции в файле - функции-помощники. Мелкие функции, необходимые
для работы валидации. Эти функции нельзя включить ни в один другой файл.

ft_error_input
Функция предназначена для вывода ошибки на экран, очистки памяти и завершения
выполнения программы с ошибкой.

ft_check_command
Функция определяет тип команды:
	-1 - комментарий или невалидная команда
	0 - любая строка, не являющаяся командой
	1 - команда ##start
	2 - команда ##end

ft_check_first
Функция проверяет, что первая поданная строка содержит число >= 0.
Это число записывается как num_of_ants в структуру table.
*/

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
    else if (num == 4)
		ft_putstr_fd("(duplicate room name)\n", 2);
	ft_table_del(table);
	exit(EXIT_FAILURE);
}

int		ft_check_command(char *str)
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
	table->num_of_ants = num;
	table->flag = 0;
	return (1);
}

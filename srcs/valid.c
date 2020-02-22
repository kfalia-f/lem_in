/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:31:30 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/22 20:11:23 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Reading map from stdin and validation

#include <lem_in.h>

void	ft_validation(t_tb *table)
{
	unsigned int	lst_len;

	lst_len = ft_lst_lenght(table->map);
	ft_putchar('\n');
	printf("table->map_len = %d\n", table->map_len);
	printf("table->room_num = %d\n", table->room_num);
	while (table->rooms)
	{
		printf("%s\n", table->rooms->name);
		table->rooms = table->rooms->next;
	}
	//ft_putnbr(lst_len);
	
}

int		ft_str_valid(t_tb *table, char *str)
{
	/*ft_putstr("\n\n");
	while (table->map)
	{
		printf("%s", table->map->cont);
		ft_putchar('\n');
		table->map = table->map->next;
	}
*/
	if (table->flag != -1 && (str[0] == '\n' || str[0] == ' ' || str[0] == '\t'))
		return (0);
	if (table->flag  == -1)
	{
		if (ft_check_first(table, str) == 0)
			ft_error_input(table, 0);
	}
	else if (table->flag == 0 || table->flag == 4 || table->flag == 3)
	{
		if (ft_check_room(table, str) == 0)
			ft_error_input(table, 1);
	}
	if (table->flag == 1)
		if (ft_check_links(table, str) == 0)
			ft_error_input(table, 2);
	return (1);
}

void	ft_read_stdin(t_tb *table)
{
	char	*str;
	t_map	*tmp;

	str = NULL;
	table->map = ft_new_list(table);
	tmp = table->map;
	get_next_line(0, &str);
	while (str && *str != '\0')
	{
		if (!ft_str_valid(table, str))
			break ;
		tmp->cont = str;
		str = NULL;
		if (get_next_line(0, &str) > 0)
		{
			tmp->next = ft_new_list(table);
			tmp = tmp->next;
		}
	}
	ft_strdel(&str);
	table->head = table->map;
	ft_validation(table);
}

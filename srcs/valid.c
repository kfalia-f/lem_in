/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:31:30 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/01/31 20:40:05 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

//void	ft_valid_room(char *str, t_tb *table)
//{
//
//}
/*void	ft_write_list(t_tb *table, char **str)
{
	t_map	*tmp;

	tmp = table->map;
}
*/
int		ft_valid(t_tb *table)
{
	char	*str;
	//int		ret;
	t_map	*tmp;
	//char	buf[2];

	str = NULL;
	table->map = ft_new_list(NULL);
	tmp = table->map;
	/*while ((ret = read(1, buf, 1)) > 0)
	{
		if (str == NULL)
			str = ft_strnew(0);
		buf[ret] = '\0';
		str = ft_strjoinre(str, buf, 1);
		if (buf[0] == '\n')
		{
			tmp->cont = ft_strdup(str);
		//	printf("\nCHECK %s\n", tmp->cont);
		//	printf("\nCHECK %s\n", table->map->cont);
			tmp->next = ft_new_list();
			tmp = tmp->next;
			ft_strdel(&str);
		}
	}*/
	while (get_next_line(0, &str) > 0)
	{
		tmp->cont = str;
		tmp->next = ft_new_list();
		tmp = tmp->next;
	}
	table->head = table->map;
	/*	ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
	*///table->map = table->map->next;
	/*while (table->map)
	{
		if (table->map->cont)
			ft_putstr(table->map->cont);
		ft_putchar('\n');
		table->map = table->map->next;
	}*/
	if (str)
		ft_strdel(&str);
	return (0);
}

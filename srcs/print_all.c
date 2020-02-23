/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:51:42 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/23 18:10:47 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	ft_print_links(t_ln *ln)
{
	while (ln)
	{
		printf("%s, ", ln->name);
		ln = ln->next;
	}
	//ft_putchar('\n');
}

void	ft_print_rooms(t_rooms *room)
{
	t_rooms	*tmp;

	tmp = room;
	printf("\n--LINKS--\n");
	while (tmp)
	{
		printf("\nroom name - %s, num of links = %d status - %d\n", tmp->name, tmp->num_of_links, tmp->r_flag);
		ft_print_links(tmp->links);
		tmp = tmp->next;
	}
}

void	ft_print_all(t_tb *table)
{
	printf("\n\n--INFO--\n");
	printf("\nnum of ants = %d, num of rooms = %d, map len = %d\n", table->num_of_ants, table->room_num, table->map_len);
	ft_print_rooms(table->rooms);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:20:38 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/23 16:57:32 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		main()
{
	t_tb	table;

	ft_new_tb(&table);
	ft_read_stdin(&table);
	while (table.rooms->links)
	{
		printf("LINK - %s\n", table.rooms->links->name);
		table.rooms->links = table.rooms->links->next;
	}
	ft_table_del(&table);
	return (0);
}

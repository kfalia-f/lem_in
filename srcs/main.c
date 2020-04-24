/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:20:38 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/23 17:43:07 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		main()
{
	t_tb	table;

	ft_new_tb(&table);
	ft_read_stdin(&table);
	set_lvl_vert(&table);
	rm_unnecessary_links(&table);
	ft_table_del(&table);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:31:30 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/13 22:10:57 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Reading map from stdin and validation

#include <lem_in.h>

void	ft_validation(t_tb *table)
{
	unsigned int	lst_len;

	lst_len = ft_lst_lenght(table->map);
	ft_putnbr(lst_len);
}

void	ft_read_stdin(t_tb *table)
{
	char	*str;
	t_map	*tmp;

	str = NULL;
	table->map = ft_new_list(NULL);
	tmp = table->map;
	get_next_line(0, &str);
	while (str && *str != '\0')
	{
		tmp->cont = str;
		str = NULL;
		if (get_next_line(0, &str) > 0)
		{
			tmp->next = ft_new_list();
			tmp = tmp->next;
		}
	}
	ft_strdel(&str);
	table->head = table->map;
	ft_validation(table);
}

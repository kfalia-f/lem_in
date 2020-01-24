/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:31:30 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/01/24 19:31:03 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	ft_valid_room(char *str, t_tb *table)
{

}

void	ft_valid_str(char **str, t_tb *table)
{
	if (table->flag == 0)
		ft_valid_room(*str, table);
	else
		ft_valid_com(*str, table);
	ft_strdel(str);
}

int		ft_valid(t_tb *table)
{
	char	*str;
	int		ret;
	char	buf[2];

	str = NULL;
	while ((ret = read(1, buf, 1)) > 0)
	{
		if (str == NULL)
			str = ft_strnew(0);
		buf[ret] = '\0';
		//if (buf[0] == '\n')
		//	break ;
		str = ft_strjoinre(str, buf, 1);
		if (buf[0] == '\n')
			ft_valid_str(&str, table);
	}
	if (str)
		ft_strdel(&str);
	return (0);
}

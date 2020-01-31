/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:18:40 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/01/27 17:59:30 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# include <libft.h>
# include <stdio.h>
# include <unistd.h>

typedef struct		s_map
{
	char			*cont;
	struct s_map	*next;
}					t_map;

typedef struct		s_tb
{
	int				flag;
	t_map			*map;
	t_map			*head;
}					t_tb;

//valid.c
int					ft_valid(t_tb *table);

//lists.c
void				ft_new_tb(t_tb *table);
t_map				*ft_new_list();
void				ft_list_del(t_map **list);

# endif

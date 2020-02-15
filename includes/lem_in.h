/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:18:40 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/15 19:52:46 by kfalia-f         ###   ########.fr       */
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
	unsigned int	room_num;
	unsigned int	map_len;
	t_map			*map;
	t_map			*head;
}					t_tb;

//valid.c
void				ft_read_stdin(t_tb *table);

//lists.c
void				ft_new_tb(t_tb *table);
t_map				*ft_new_list();
void				ft_list_del(t_map **list);
unsigned int		ft_lst_lenght(t_map *map);
void				ft_table_del(t_tb *table);

//helpers
int					ft_check_first(t_tb *table, char *str);
int					ft_check_room(t_tb *table, char *str);
int					ft_check_command(char *str);
void				ft_error_input(t_tb *table);

# endif

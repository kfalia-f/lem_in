/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:18:40 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/18 20:46:12 by kfalia-f         ###   ########.fr       */
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

typedef struct		s_ln
{
	char			*name;
	struct s_ln		*next;
}					t_ln;

typedef struct		s_rooms
{
	char			*name;
	size_t			r_flag;
	t_ln			*links;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_tb
{
	int				flag;
	unsigned int	room_num;
	unsigned int	map_len;
	t_map			*map;
	t_map			*head;
	t_rooms			*rooms;
	t_rooms			*r_head;
}					t_tb;

//valid.c
void				ft_read_stdin(t_tb *table);

//lists.c
void				ft_new_tb(t_tb *table);
t_map				*ft_new_list();
t_rooms				*ft_new_room(char *str, int n);
void				ft_list_del(t_map **list);
unsigned int		ft_lst_lenght(t_map *map);
void				ft_table_del(t_tb *table);

//helpers
int					ft_check_first(t_tb *table, char *str);
int					ft_check_room(t_tb *table, char *str);
int					ft_check_command(char *str);
int					ft_check_links(t_tb *table, char *str);
void				ft_error_input(t_tb *table);

# endif

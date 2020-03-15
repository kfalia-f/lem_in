/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:18:40 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/23 18:10:18 by kfalia-f         ###   ########.fr       */
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
	t_ln			*links;
	unsigned int	num_of_links;
	char			*name;
	int				level;
	int				r_flag;
	int				busy;
	struct s_rooms	*next;
}					t_rooms;

typedef struct			s_queue
{
	t_rooms				*room;
	struct s_queue		*next;
}						t_queue;

typedef struct		s_tb
{
	int				flag;
	unsigned int	room_num;
	unsigned int	map_len;
	unsigned int	num_of_ants;
	t_map			*map;
	t_map			*head;
	t_rooms			*rooms;
	t_rooms			*r_head;
	t_rooms			*start;
	t_rooms 		*end;
}					t_tb;

//valid.c
void				ft_read_stdin(t_tb *table);
int					ft_check_room(t_tb *table, char *str);
int					ft_check_command(char *str);
int					ft_check_links(t_tb *table, char *str);
int					ft_check_lnk(char *str);
void				ft_error_input(t_tb *table, int num);

//lists.c
void				ft_new_tb(t_tb *table);
t_map				*ft_new_list();
t_rooms				*ft_new_room();
t_ln				*ft_new_link(char *name);
void				ft_list_del(t_map **list);
unsigned int		ft_lst_lenght(t_map *map);
void				ft_table_del(t_tb *table);

//helpers
int					ft_check_first(t_tb *table, char *str);
void				ft_remember_link(t_tb *table, char **args);

void				ft_print_all(t_tb *table);          //<------------ delete it


//algo
void find_path(t_tb *table);

# endif

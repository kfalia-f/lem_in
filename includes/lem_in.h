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
    struct s_rooms  **lnk_to_room;
	unsigned int	num_of_links;
	char			*name;
	int				r_flag;
    unsigned int    inp_links;
    unsigned int    out_links;
    int   			lvl;
	int				busy;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_link
{
	t_rooms				*start;
	t_rooms				*end;
	struct s_link		*next;
}					t_link;

typedef struct		s_tb
{
	int				flag;
	int				lvl;
	unsigned int	room_num;
	unsigned int	map_len;
	unsigned int	num_of_ants;
	t_map			*map;
	t_map			*head;
	t_link			*links;
	t_rooms			*rooms;
    t_rooms         *r_end;
	t_rooms			*r_head;

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
void                ft_room_del(t_tb *table);

//helpers
int					ft_check_first(t_tb *table, char *str);
void				ft_remember_link(t_tb *table, char **args);
void                ft_build_map(t_tb *table);

void				ft_print_all(t_tb *table);          //<------------ delete it


//algo
typedef struct			s_mp
{
	t_rooms				*room;
	struct s_mp			*next;
}						t_mp;



void				set_lvl_vert(t_tb *table);
void				rm_unnecessary_links(t_tb *table);

# endif

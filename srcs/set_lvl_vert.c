#include "lem_in.h"

static t_mp		*mp_create_vert(t_rooms *room)
{
	t_mp	*tmp;

	if (!(tmp = (t_mp *)ft_memalloc(sizeof(t_mp))))
		exit(EXIT_FAILURE);
	tmp->room = room;
	tmp->next = NULL;
	return (tmp);
}

static t_mp		*mp_get_head(t_mp **prev)
{
	t_mp	*elem;

	elem = NULL;
	if (prev && *prev)
	{
		elem = (*prev);
		(*prev) = (*prev)->next;
	}
	return (elem);
}

static void		mp_add_vert(t_mp **prev, t_mp *elem)
{
	t_mp	*cur;

	if (prev && *prev)
	{
		cur = (*prev);
		while (cur->next)
			cur = cur->next;
		cur->next = elem;
	}
	else if (cur)
		(*prev) = elem;
}

static void		mp_add_linked_vert(t_tb *table, t_mp **prev, t_rooms *room)
{
	int i;
	unsigned int tmp_num_links;
	t_rooms *tmp_room;

	tmp_room = table->rooms;

	while (tmp_room)
	{
		i = 0;
		if (tmp_room == room)
		{
			tmp_num_links = tmp_room->num_of_links;
			while (tmp_room->num_of_links > 0)
			{
				if (tmp_room->lnk_to_room[i]->lvl == -1)
				{
					tmp_room->lnk_to_room[i]->lvl = table->lvl + 1;
					mp_add_vert(prev, mp_create_vert(tmp_room->lnk_to_room[i]));
					i++;
				}
				tmp_room->num_of_links--;
			}
			tmp_room->num_of_links = tmp_num_links;
		}
		else if (tmp_room == table->r_end)
		{
			while (tmp_room->num_of_links > 0)
			{
				if (tmp_room->lnk_to_room[i]->lvl == -1)
				{
					tmp_room->lnk_to_room[i]->lvl = table->lvl + 1;
					mp_add_vert(prev, mp_create_vert(tmp_room->lnk_to_room[i]));
					i++;
				}
				tmp_room->num_of_links--;
			}
		}
		tmp_room = tmp_room->next;
	}
}

void			set_lvl_vert(t_tb *table)
{
	t_mp		*prev;
	t_mp		*current;

	prev = NULL;
	table->rooms->lvl = 0;
	mp_add_vert(&prev, mp_create_vert(table->rooms));
	while (prev != NULL)
	{
		current = mp_get_head(&prev);
		if (current->room != table->r_end)
		{
			mp_add_linked_vert(table, &prev, current->room);
			table->lvl = current->room->lvl;
		}
		else
			table->r_end->lvl = INT32_MAX;
		free(current);
	}
}



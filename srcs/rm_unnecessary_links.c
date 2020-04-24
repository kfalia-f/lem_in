#include "lem_in.h"

void	rm_link(t_tb *table, t_rooms *room, unsigned int i)
{
	t_rooms *prev;
	t_rooms *cur;

	prev = NULL;
	cur = table->rooms;
	while (cur && cur != room)
	{
		prev = cur;
		cur = cur->next;
	}
	if (!prev && cur)
		table->rooms = cur->next;
	else if (cur)
		prev->next = cur->next;
	room->lnk_to_room[i] = NULL;
}

void	rm_unnecessary_links(t_tb *table)
{
	int i;
	unsigned int tmp_num_links;
	t_rooms *cur_link_room;
	t_rooms *del_link_room;


	cur_link_room = table->rooms;
	while(cur_link_room)
	{
		i = 0;
		tmp_num_links = cur_link_room->num_of_links;
		del_link_room = cur_link_room;
		cur_link_room = cur_link_room->next;
		while (cur_link_room && cur_link_room->num_of_links > 0)
		{
			if (del_link_room->lvl == -1 || del_link_room->lnk_to_room[i]->lvl == -1
				|| del_link_room->lvl ==  del_link_room->lnk_to_room[i]->lvl)
				rm_link(table, del_link_room, i);
			i++;
			cur_link_room->num_of_links--;
		}
		if (cur_link_room)
			cur_link_room->num_of_links = tmp_num_links;
	}
}

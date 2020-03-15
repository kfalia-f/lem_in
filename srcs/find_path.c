#include "lem_in.h"

t_queue *all_create_vert(t_rooms *room)
{
    {
        t_queue	*queue;

        if (!(queue = (t_queue *)ft_memalloc(sizeof(t_queue))))
        {
            write(1, "Error malloc\n", 13);
            exit(EXIT_FAILURE);
        }
        queue->room = room;
        queue->next = NULL;
        return (queue);
    }
}

void		all_add_vert(t_queue **queue, t_queue *elem)
{
    t_queue	*current;

    if (queue && *queue)
    {
        current = (*queue);
        while (current->next)
            current = current->next;
        current->next = elem;
    }
    else if (queue)
        (*queue) = elem;
}

t_queue *all_get_head(t_queue **all)
{
    t_queue		*elem;

    elem = NULL;
    if (all && *all)
    {
        elem = (*all);
        (*all) = (*all)->next;
    }
    return (elem);
}

void		all_add_linked_vert  (t_tb *table, t_queue **all, t_rooms *room)
{
  t_rooms *current;

  current = room;
  while (current->num_of_links)
  {
      all_add_vert(all, all_create_vert(current));

      current->num_of_links--;
  }

}

void find_path(t_tb *table)
{
    t_queue *all;
    t_queue *current;

    while(table->rooms)
    {
        if (table->rooms->r_flag == 1)
        {
            table->start =ft_new_room();
            table->start->name = table->rooms->name;
            table->start->links = table->rooms->links;
            table->start->num_of_links = table->rooms->num_of_links;
            table->start->r_flag = table->rooms->r_flag;

        }
        if (table->rooms->r_flag == 2)
        {
            table->end =ft_new_room();
            table->end->name = table->rooms->name;
            table->end->links = table->rooms->links;
            table->end->num_of_links = table->rooms->num_of_links;
            table->end->r_flag = table->rooms->r_flag;
        }
        table->rooms = table->rooms->next;
    }
    table->rooms = table->r_head;

    all = NULL;
    all_add_vert(&all, all_create_vert(table->start));
    while (all != NULL)
    {
        current = all_get_head(&all);
        if (current->room != table->end)
        {
            all_add_linked_vert(table, &all, current->room);
//            table->_level = current->room->bfs_level;
        }
        else
            table->end->level = INT32_MAX;
        free(current);
    }
}
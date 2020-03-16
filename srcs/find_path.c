#include "lem_in.h"

void put_level_vert(t_tb *table)
{
    t_rooms *tmp;
    int i;

    i = 0;
    tmp = table->rooms;
    while (tmp)
    {
        if (tmp->r_flag == table->start->r_flag)
        {
            tmp->level = 0;
            while (tmp->links)
            {
                tmp->lnk_to_room[i]->level = tmp->level + 1;
                i++;
                tmp->links--;
            }
        }
        tmp = tmp->next;
    }
}

void find_path(t_tb *table)
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
    put_level_vert(table);
}
#include <lem_in.h>

t_rooms **ft_remake_links(t_tb *table, t_ln *links, int num, char *name)
{
    t_rooms **new_links;
    t_rooms *tmp;
    int     i;

    i = 0;
    new_links = malloc(sizeof(t_rooms *) * (num + 1));
    while (i < num)
        new_links[i++] = malloc(sizeof(t_rooms));
    new_links[i] = NULL;
    i = 0;
    while (links)
    {
        tmp = table->rooms;
        while (ft_strcmp(tmp->name, links->name) != 0 && tmp)
            tmp = tmp->next;
        if (tmp)
            new_links[i++] = tmp;
        links = links->next;
    }

    i = 0;
    printf("\n----%s----\n", name);
    while (new_links[i])
    {
        printf("new_link[%d] = %s\n", i, new_links[i]->name);
        i++;
    }

    return (new_links);
}

void    ft_rebuild_map(t_tb *table, t_rooms *tmp, t_rooms *tmp_pr, t_rooms *end)
{
    tmp = table->rooms;
    end = tmp;
    while (end->next)
        end = end->next;
    while (tmp->next)
    {
        tmp_pr = tmp;
        tmp->lnk_to_room = ft_remake_links(table, tmp->links, tmp->num_of_links, tmp->name);
        tmp = tmp->next;
        if (tmp->r_flag == 1)
        {
            tmp_pr->next = tmp->next;
            tmp->next = table->rooms;
            table->rooms = tmp;
        }
        else if (tmp->r_flag == 2)
        {
            tmp_pr->next = tmp->next;
            tmp->next = NULL;
            end->next = tmp;
        }
    }
}

void    ft_build_map(t_tb *table)
{
    ft_rebuild_map(table, NULL, NULL, NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:40:11 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/22 19:45:42 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_rooms		*ft_new_room()
{
	t_rooms	*new;

	new = (t_rooms *)malloc(sizeof(*new));
	new->name = NULL;
	new->next = NULL;
	new->links = NULL;
	new->num_of_links = 0;
	new->r_flag = 0;
	new->busy = 0;
	return (new);
}

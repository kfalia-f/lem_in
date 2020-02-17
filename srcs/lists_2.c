/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:40:11 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/17 20:46:23 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_rooms		*ft_new_room(char *str)
{
	t_rooms	*new;

	new = (t_rooms *)malloc(sizeof(*new));
	new->name = ft_strdup(str);
	new->next = NULL;
	new->links = NULL;
	return (new);
}

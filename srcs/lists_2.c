/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:40:11 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/18 20:45:54 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_rooms		*ft_new_room(char *str, int n)
{
	t_rooms	*new;

	new = (t_rooms *)malloc(sizeof(*new));
	new->name = ft_strndup(str, n);
	new->next = NULL;
	new->links = NULL;
	return (new);
}
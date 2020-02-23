/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:40:11 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/23 17:40:47 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_rooms		*ft_new_room()
{
	t_rooms	*new;

	new = (t_rooms *)ft_memalloc(sizeof(t_rooms));
	return (new);
}

t_ln		*ft_new_link(char *name)
{
	t_ln	*ln;

	ln = (t_ln *)malloc(sizeof(t_ln));
	ln->next = NULL;
	ln->name = ft_strdup(name);
	return (ln);
}

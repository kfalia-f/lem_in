/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:42:08 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/18 20:45:26 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(char *str, int n)
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(char) * n + 1);
	i = 0;
	while (i < n)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

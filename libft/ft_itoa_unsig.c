/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:38:16 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/09/19 19:32:31 by dfalena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_unsig(unsigned long long int n)
{
	char	s[21];
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (n > 9)
	{
		s[i++] = '0' + (n % 10);
		n = n / 10;
	}
	s[i++] = '0' + n;
	if ((res = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	res[i] = '\0';
	while (i--)
		res[i] = s[j++];
	return (res);
}

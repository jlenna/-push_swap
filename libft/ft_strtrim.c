/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:23:01 by jlenna            #+#    #+#             */
/*   Updated: 2021/11/14 13:35:10 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	int		k;
	size_t	len;
	char	*s;

	i = 0;
	k = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen((char *)s1) - 1;
	while ((s1[i]) && (ft_strchr(set, s1[i])))
		i++;
	if (i == len + 1)
		return (ft_calloc(1, sizeof(char)));
	while ((len >= 0) && (ft_strchr(set, s1[len])))
		len--;
	s = (char *)malloc(sizeof(char) * (len + 2 - i));
	if (!s)
		return (NULL);
	while (i <= len)
		s[k++] = s1[i++];
	s[k] = '\0';
	return (s);
}

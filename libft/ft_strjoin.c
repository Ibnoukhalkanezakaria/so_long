/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:41:54 by zibnoukh          #+#    #+#             */
/*   Updated: 2023/11/24 18:19:23 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	usewhile(char *result, const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (*s1 != '\0')
	{
		result[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		result[i] = *s2;
		i++;
		s2++;
	}
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	result = (char *)malloc(total_len + 1);
	if (result == NULL)
		return (NULL);
	usewhile(result, s1, s2);
	result[total_len] = '\0';
	return (result);
}

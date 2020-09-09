/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pminne <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 16:52:23 by pminne       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 14:17:57 by pminne      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		check_set(char const c, char const *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (0);
		i++;
	}
	return (1);
}

static int		check_start(char const *s, char const *set)
{
	size_t i;

	i = 0;
	while (check_set(s[i], set) == 0 && s[i])
		i++;
	return (i);
}

static int		check_end(char const *s, char const *set)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	while (s[i - 1] && check_set(s[i - 1], set) == 0)
		i--;
	return (i);
}

char			*ft_strtrim(char const *s, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;

	if (!s || !set)
		return (NULL);
	i = 0;
	start = check_start(s, set);
	end = check_end(s, set);
	if (start == (int)ft_strlen(s))
		start = 0;
	if (!(str = malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	while (s[start] && start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

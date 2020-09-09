/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pminne <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 17:43:11 by pminne       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 16:48:57 by pminne      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

static size_t	check_nb_str(char const *s, char c)
{
	size_t i;
	size_t nstr;

	i = 0;
	nstr = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == '\0')
			nstr++;
		else if (s[i] != c && s[i + 1] == c)
			nstr++;
		i++;
	}
	return (nstr);
}

static char		*put_str(char const *s, char c, size_t w)
{
	char		*str;
	size_t		i;
	size_t		a;

	i = 0;
	a = w;
	while (s[a] != c)
		a++;
	if (!(str = malloc(sizeof(char) * a + 1)))
		return (NULL);
	while (s[w] != c)
	{
		str[i] = s[w];
		i++;
		w++;
	}
	str[i] = '\0';
	return (str);
}

static char		**free_arr(char **arr, size_t i)
{
	while (i--)
	{
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}

static char		**filling_arr(char const *s, char **arrstr, size_t nstr, char c)
{
	size_t i;
	size_t w;

	i = 0;
	w = 0;
	while (s[w] && s[w] != c)
		w++;
	if (w == ft_strlen(s))
	{
		if (!(arrstr[0] = ft_strdup(s)))
			return (NULL);
		arrstr[1] = NULL;
		return (arrstr);
	}
	w = 0;
	if (s[w] != c)
		if (!(arrstr[i++] = put_str(s, c, w)))
			return (free_arr(arrstr, i));
	while (i < nstr)
		if (s[w++] == c && s[w] != c)
			if (!(arrstr[i++] = put_str(s, c, w)))
				return (free_arr(arrstr, i - 1));
	arrstr[nstr] = NULL;
	return (arrstr);
}

char			**ft_split(char const *s, char c)
{
	char	**arrstr;
	size_t	i;
	size_t	w;
	size_t	nstr;

	i = 0;
	w = 0;
	if (!s)
	{
		if (!(arrstr = malloc(sizeof(char *) * 1)))
			return (NULL);
		arrstr[0] = NULL;
		return (arrstr);
	}
	nstr = check_nb_str(s, c);
	if (!(arrstr = malloc(sizeof(char *) * (nstr + 1))))
		return (NULL);
	if (nstr == 0)
	{
		arrstr[0] = NULL;
		return (arrstr);
	}
	else
		return (filling_arr(s, arrstr, nstr, c));
}

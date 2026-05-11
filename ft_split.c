#include "push_swap.h"

void	free_split(char **res, int m)
{
	int	i;

	i = 0;
	while (i < m)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static int	count_word(char const *s, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			word++;
		else if (s[i] != c && s[i - 1] == c)
			word++;
		i++;
	}
	return (word);
}

static char	*get_word(char const *s, char c, int *index)
{
	int		start;
	int		len;
	char	*word;

	while (s[*index] && s[*index] == c)
		(*index)++;
	start = *index;
	while (s[*index] && s[*index] != c)
		(*index)++;
	len = *index - start;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + start, len + 1);
	return (word);
}


char	**ft_split(char const *s, char c)
{
	int		len;
	char	**res;
	int		i;
	int		index;

	if (!s)
		return (NULL);
	len = count_word(s, c);
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = NULL;
	i = 0;
	index = 0;
	while (i < len)
	{
		res[i] = get_word(s, c, &index);
		if (!res[i])
			return (free_split(res, i), NULL);
		i++;
	}
	return (res);
}

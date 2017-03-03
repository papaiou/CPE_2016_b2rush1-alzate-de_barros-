/*
** str_to_word_tab.c for to_wor_tab in /home/alzate_j/usefull
** 
** Made by jacques alzate
** Login   <alzate_j@epitech.net>
** 
** Started on  Wed Jan  4 15:25:31 2017 jacques alzate
** Last update Wed Jan  4 15:27:05 2017 jacques alzate
*/

int	end_of_unalphanum(char *str, int i)
{
  while (str[i] < '0' || str[i] > '9' && str[i] < 'A' ||
      str[i] > 'Z' && str[i] < 'a' || str[i] > 'z')
    {
      if (str[i] == '\0')
	return (i);
      i++;
    }
  return (i);
}

int	word_to_tab(char **tab, int pos, char *str, int i)
{
  int	x;

  x = i;
  while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9' ||
	 str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
    i++;
  tab[pos] = malloc(sizeof(char) * ((i - x) + 1));
  i = 0;
  while (str[x] != '\0' && str[x] >= '0' && str[x] <= '9' ||
	 str[x] >= 'A' && str[x] <= 'Z' || str[x] >= 'a' && str[x] <= 'z')
    tab[pos][i++] = str[x++];
  tab[pos][i] = '\0';
  return (x);
}

int	size_of_tab(char *str, int x)
{
  int	tmp;

  tmp = 1;
  while (str[x] != '\0')
    {
      if (str[x] < '0' || str[x] > '9' && str[x] < 'A' ||
	  str[x] > 'Z' && str[x] < 'a' || str[x] > 'z')
	{
	  x = end_of_unalphanum_char(str, x);
	  tmp++;
	}
      x++;
    }
  return (tmp);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	x;
  int	size;
  char	**tab;

  x = 0;
  i = end_of_unalphanum_char(str, 0);
  size = size_of_tab(str, i);
  tab = malloc(sizeof(char *) * (size + 1));
  while (str[i] != '\0')
    {
      i = word_to_tab(tab, x, str, i);
      i = end_of_unalphanum_char(str, i);
      x++;
    }
  tab[size] = '\0';
  return (tab);
}

/*
** my_str_to_wordtab.c for Minishell_1 in /home/blasto/Epitech/Minishell_1
**
** Made by Blasto
** Login   <blasto@epitech.net>
**
** Started on  Fri Jan 20 17:49:02 2017 Blasto
** Last update Mon Jan 23 19:04:12 2017 Blasto
*/

#include <unistd.h>
#include <stdlib.h>

int			nbr_word(char *str)
{
  int	i;
  int	nb_word;

  i = 0;
  nb_word = 0;
  while (str[i] != '\0')
    {
      if (str[i] != '\n')
	{
	  nb_word++;
	  while (str[i + 1] != '\n' && str[i + 1] != '\0')
	    i++;
	}
      i++;
    }
  return (nb_word);
}

char			**str_to_wordtab(char *str)
{
  int	i;
  int	j;
  int	a;
  int	nb_word;
  char	**tab;

  i = 0;
  a = 0;
  j = 0;
  if (str == NULL)
    return (0);
  nb_word = nbr_word(str);
  tab = malloc((nb_word + 1) * sizeof(*tab));
  while (i < nb_word)
    {
      tab[i] = malloc(strlen(str) * sizeof(*tab[i]));
      while (str[a] != '\n' && str[a] != '\0')
	tab[i][j++] = str[a++];
      tab[i][j] = '\0';
      j = 0;
      a++;
      i++;
    }
  tab[i] = 0;
  return (tab);
}

int 		main(int argc, char **argv)
{
  str_to_wordtab("");
}

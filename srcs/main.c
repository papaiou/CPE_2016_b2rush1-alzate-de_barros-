/*
** main.c for rush in /home/alzate_j/projects/CPE/tar_rush/srcs
** 
** Made by jacques alzate
** Login   <alzate_j@epitech.net>
** 
** Started on  Fri Mar  3 21:29:18 2017 jacques alzate
** Last update Sat Mar  4 14:38:46 2017 jacques alzate
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

/* int	my_archive(char *filename, int type) */
/* { */
  
/* } */

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (!str || !*str)
    return (0);
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

char	**fill_arguments(int ac, char **av, char **arg)
{
  int	i;
  int	j;
  int	size;

  i = 1;
  if ((arg = malloc(sizeof(char *) * ac)) == NULL)
    return (NULL);
  arg[ac - 1] = NULL;
  while (i != ac)
    {
      j = 0;
      size = my_strlen(av[i]) + 1;
      if ((arg[i] = malloc(sizeof(char) * size)) == NULL)
      	return (NULL);
      while (av[i][j] != '\0')
	{
	  arg[i][j] = av[i][j];
	  j++;
	}
      arg[i][size - 1] = '\0';
      i++;
    }
  return (arg);
}

void	free_tab(char **tab, int ac)
{
  int	i;

  i = 0;
  while (i != (ac - 1))
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

int	main(int ac, char **av)
{
  char	**arguments;

  arguments = NULL;
  if (ac < 2)
    {
      write (2, "Not enough arguments\n", 21);
      return (84);
    }
  if ((arguments = fill_arguments(ac, av, arguments)) == NULL)
    return (84);
  if (Check_Arg(arguments) == 84)
    return (84);
  free_tab(arguments, ac);
  return (0);
  /* my_archive(); */
}

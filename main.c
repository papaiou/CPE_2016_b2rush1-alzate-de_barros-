/*
** main.c for rush in /home/alzate_j/projects/CPE/tar_rush/srcs
** 
** Made by jacques alzate
** Login   <alzate_j@epitech.net>
** 
** Started on  Fri Mar  3 21:29:18 2017 jacques alzate
** Last update Fri Mar  3 21:40:02 2017 jacques alzate
*/

#include <stdlib.h>

int	my_archive(char **av)
{
  av[2] = NULL;
  return (0);
}

int	main(int ac, char **av)
{
  if (ac < 2)
    return (84);
  my_archive(av);
  return (0);
}

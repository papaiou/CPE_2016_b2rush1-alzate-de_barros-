/*
** get_next_line.c for get_next_line in /home/exoarma/Epitech/CPE_2016_getnextline/
**
** Made by Exoarma
** Login   <aurel.ghirenghelli@epitech.eu>
**
** Started on  Mon Jan  9 14:39:11 2017 Exoarma
** Last update Tue Jan 17 14:45:31 2017 Exoarma
*/
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char *my_realloc (char *ret, int i)
{
  char *stock;
  int	ptr;

  ptr = 0;
  stock = malloc(sizeof(char)* i + 1);
  while (ret[ptr] != '\0')
    {
      stock[ptr] = ret[ptr];
      ptr++;
    }
  free(ret);
  return (stock);
}

char *get_next_line (const int fd)
{
  static int ptr = 0;
  static int b = 0;
  int	i;
  char *ret;
  static char buf[READ_SIZE];

  i = 0;
  ret = malloc(sizeof(char) * READ_SIZE + 1);
  if (ret == NULL)
    return (NULL);
  if (b == 0)
    {
      b = read (fd, buf, READ_SIZE);
      ptr = 0;
    }
  if (b == -1 || b == 0)
    return (NULL);
  while (buf[ptr] != '\n' && buf[ptr] != '\0')
    {
      ret[i++] = buf[ptr++];
      if (--b == 0)
	{
	  b = read(fd, buf, READ_SIZE);
	  ret[i] = '\0';
	  ret = my_realloc(ret, i + READ_SIZE);
	  ptr = 0;
	}
    }
  ret[i] = '\0';
  ptr++;
  b--;
  return (ret);
}

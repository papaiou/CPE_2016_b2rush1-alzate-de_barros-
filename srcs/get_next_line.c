/*
** gnl.c for get_next_line in /home/hazard_v/rendu/CPE/CPE_2016_getnextline
** 
** Made by Victor Hazard
** Login   <hazard_v@epitech.net>
** 
** Started on  Thu Jan  5 09:48:24 2017 Victor Hazard
** Last update Tue Feb  7 15:45:57 2017 Victor Hazard
*/

#include "gnl.h"
#include <unistd.h>
#include <stdlib.h>

int	my_memset(char buff[READ_SIZE + 1], int fd)
{
  int	i;

  i = 0;
  while (i < READ_SIZE + 1)
    buff[i++] = '\0';
  return (read(fd, buff, READ_SIZE));
}

char	*my_realloc(char *str, int size)
{
  char	*new;
  int	i;
  int	y;

  i = 0;
  if (str == NULL)
    {
      new = malloc(sizeof(char) * (size + 1));
      while (i < size)
	new[i++] = '\0';
    }
  else
    {
      while (str[i])
	i++;
      new = malloc(sizeof(char) * (1 + size + i));
      y = -1;
      while (++y < i)
	new[y] = str[y];
      new[y] = '\0';
      free (str);
    }
  return (new);
}

char	*fill_str(char *str, char buff[READ_SIZE], int start, int end)
{
  int	i;

  i = 0;
  if (str)
    while (str[i] != '\0')
      i++;
  while (start < end)
    str[i++] = buff[start++];
  str[i] = '\0';
  return (str);
}

int	get_line(char buff[READ_SIZE], int pos, int read_ret)
{
  while (pos < read_ret)
    {
      if (buff[pos] == '\0' || buff[pos] == '\n')
	return (pos);
      pos++;
    }
  return (pos);
}

char		*get_next_line(const int fd)
{
  static int	pos = 0;
  static int	rd_ret;
  static char	buff[READ_SIZE + 1];
  int		next_pos;
  char		*str;

  str = NULL;
  buff[READ_SIZE + 1] = '\0';
  if (pos == 0 && (rd_ret = my_memset(buff, fd)) <= 0)
    return (NULL);
  if (pos >= rd_ret && !(pos = 0))
    if ((rd_ret = my_memset(buff, fd)) <= 0)
      return (0);
  while (rd_ret != 0 && (next_pos = get_line(buff, pos, rd_ret)) == rd_ret)
    {
      str = my_realloc(str, (1 + (rd_ret - pos)));
      fill_str(str, buff, pos, rd_ret);
      pos = 0;
      rd_ret = my_memset(buff, fd);
    }
  str = my_realloc(str, (next_pos - pos));
  fill_str(str, buff, pos, next_pos);
  pos = next_pos + 1;
  return (str);
}

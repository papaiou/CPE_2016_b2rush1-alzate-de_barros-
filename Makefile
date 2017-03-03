##
## Makefile<tar_rush> for rush in /home/alzate_j/projects/CPE/tar_rush
## 
## Made by jacques alzate
## Login   <alzate_j@epitech.net>
## 
## Started on  Fri Mar  3 21:25:34 2017 jacques alzate
## Last update Fri Mar  3 21:44:55 2017 jacques alzate
##

CC	= @gcc

RM	= @rm -f

NAME1	= my_archive

CFLAGS	+= -W -Werror -Wall -Wextra -I../include

SRCS	= main.c

OBJS	= $(addprefix ./srcs/, $(SRCS:.c=.o))

BONUS1	= @echo -en "  ____                                  _        _   _               _____           _ _ \n" \
	  "/ ___|  ___  __ _ _ __ ___   ___ _ __ | |_ __ _| |_(_) ___  _ __   |  ___|_ _ _   _| | |_ \n" \
	  "\\___ \\ / _ \\/ _\` | '_ \` _ \\ / _ \\ '_ \\| __/ _\` | __| |/ _ \\| '_ \\  | |_ / _\` | | | | | __| \n" \
	  " ___) |  __/ (_| | | | | | |  __/ | | | || (_| | |_| | (_) | | | | |  _| (_| | |_| | | |_  \n" \
	  "|____/ \\___|\\__, |_| |_| |_|\\___|_| |_|\\__\\__,_|\\__|_|\\___/|_| |_| |_|  \\__,_|\\__,_|_|\\__| \n" \
	  "            |___/ \n " 

BONUS2	= @echo -en "   ____ _\n" \
	" / ___| | ___  __ _ _ __\n" \
	"| |   | |/ _ \\/ _\` | '_ \\ \n" \
	"| |___| |  __/ (_| | | | |\n" \
	" \____|_|\___|\\__,_|_| |_|\n"

BONUS3	= @echo -en "  _____    _\n" \
	"|  ___|__| | ___  __ _ _ __\n" \
	"| |_ / __| |/ _ \\/ _\` | '_ \\ \n" \
	"|  _| (__| |  __/ (_| | | | |\n" \
	"|_|  \\___|_|\___|\__,_|_| |_|\n"

BONUS4	= @echo -en "  ____\n" \
	"|  _ \\ ___\\n" \
	"| |_) / _ \\ \n" \
	"|  _ <  __/\n" \
	"|_| \\_\\___|\n"

$(NAME1): $(OBJS)
	$(BONUS1)
	$(CC) $(OBJS) -o $(NAME1)

all: $(NAME1)

clean:
	$(RM) $(OBJS)
	$(BONUS2)

fclean:	clean
	$(BONUS3)
	$(RM) $(NAME1)

do_re:
	$(BONUS4)

re: do_re fclean all

.PHONY: all clean fclean re

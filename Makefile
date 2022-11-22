# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nakanoun <nakanoun@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/22 17:10:36 by nakanoun      #+#    #+#                  #
#    Updated: 2022/11/22 17:10:36 by nakanoun      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = cc
AR = ar

FLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c \
	get_next_line_utils.c

OBJS = ${SRC:.c=.o}

all: ${NAME}

${NAME}:	${OBJS}
	$(AR) -crs $(NAME) $(OBJS)
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
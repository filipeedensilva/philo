# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 11:59:16 by feden-pe          #+#    #+#              #
#    Updated: 2024/03/05 18:13:46 by feden-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = #-Wall -Wextra -Werror

RM = rm -f

SRC = main.c \
      parse_args.c \
	  parse_utils.c \

NAME = philo
OBJ = ${addprefix ./obj/,${SRC:%.c=%.o}}

INCLUDES = -I philo.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

./obj/%.o: ./src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

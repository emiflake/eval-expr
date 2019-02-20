# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nmartins <nmartins@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/20 18:05:21 by nmartins      #+#    #+#                  #
#    Updated: 2019/02/20 18:15:22 by nmartins      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#############
# variables #
#############

# configure
NAME=eval_expr

OBJECT_NAMES=main \
			 ft_atoi \
			 eval_expr

# do not configure
CC=gcc
INCLUDES=-I./includes
SRC=./srcs
CFLAGS=-Werror -Wall -Wextra $(INCLUDES)
OBJECTS=$(patsubst %, %.o, $(OBJECT_NAMES))


#########
# rules #
#########
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: $(SRC)/%.c
	$(CC) -c -o $@ $^ $(CFLAGS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

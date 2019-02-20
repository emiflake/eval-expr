# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: nmartins <nmartins@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/20 18:05:21 by nmartins      #+#    #+#                  #
#    Updated: 2019/02/20 23:18:52 by emiflake         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############
# variables #
#############

# configure
NAME=eval_expr

OBJECT_NAMES=main \
			 eval_expr \
			 ft_putnbr \
			 ft_putchar \
			 ft_putstr \
			 ft_strlen \
			 ft_ignore_whitespaces

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

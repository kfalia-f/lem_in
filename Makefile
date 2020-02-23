# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/22 13:25:32 by kfalia-f          #+#    #+#              #
#    Updated: 2020/02/23 17:53:24 by kfalia-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = lem_in

FLAGS = -Wall -Wextra -Werror

SRC = srcs/

SOURCES = $(SRC)main.c \
		  $(SRC)valid.c \
		  $(SRC)lists.c \
		  $(SRC)lists_2.c \
		  $(SRC)valid_helpers.c \
		  $(SRC)valid_check_rooms.c \
		  $(SRC)valid_check_links.c \
		  $(SRC)remember_links.c \
		  $(SRC)print_all.c

LIB_FOLD = libft/

LIBFT = -L $(LIB_FOLD) -lft

OBJ = $(SOURCES:.c=.o)

HEADERS = -I includes -I $(LIB_FOLD)includes

%.o: %.c includes/lem_in.h libft/includes/libft.h
	@gcc $(FLAGS) $(HEADERS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_FOLD)
	@make -C $(LIB_FOLD) clean
	@gcc $(FLAGS) -o $(NAME) $(HEADERS) $(OBJ) $(LIBFT)

clean:
	@rm -f $(OBJ)
	@make -C $(LIB_FOLD) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_FOLD) fclean

re: fclean all

test:
	##@gcc -g $(FLAGS) -o $(NAME) $(HEADERS) $(OBJ) $(LIBFT)

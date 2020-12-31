# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 15:27:59 by dhorker           #+#    #+#              #
#    Updated: 2020/12/31 15:43:35 by lyahasik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILLER = players/dhorker.filler

WWW = -Wall -Wextra -Werror

LIB = $(DIR_LIB)libft.a

DIR_LIB = libft/

SRC_FILLER =	main.c \
				insert.c \
				player.c \
				board.c \
				heat_map.c \
				token.c \
				indents.c \
				freeing.c

OBJ_FILLER = $(SRC_FILLER:.c=.o)

all: $(FILLER)

%.o : %.c
	gcc $(WWW) -I . -I $(DIR_LIB) -c $^ -o $@

$(LIB):
	make -C libft

$(FILLER): $(LIB) $(OBJ_FILLER)
	gcc $(OBJ_FILLER) $(LIB) $(WWW) -I . -o $(FILLER)

clean:
	@make clean -C libft
	@rm -rf *.o
	@rm -rf $(DIR_FILLER)*.o

fclean: clean
	@make fclean -C libft
	@rm -rf $(FILLER)

re: fclean all

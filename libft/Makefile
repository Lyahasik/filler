# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 14:53:48 by dhorker           #+#    #+#              #
#    Updated: 2019/02/24 18:19:01 by dhorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS =		-Wall -Wextra -Werror
NAME =		libft.a

FT_1 =		ft_memset
FT_2 =		ft_bzero
FT_3 =		ft_memcpy
FT_4 =		ft_memccpy
FT_5 =		ft_memmove
FT_6 =		ft_memchr
FT_7 =		ft_memcmp
FT_8 =		ft_strlen
FT_9 =		ft_strdup
FT_10 =		ft_strcpy
FT_11 =		ft_strncpy
FT_12 =		ft_strcat
FT_13 =		ft_strncat
FT_14 =		ft_strlcat
FT_15 =		ft_strchr
FT_16 =		ft_strrchr
FT_17 =		ft_strstr
FT_18 =		ft_strnstr
FT_19 =		ft_strcmp
FT_20 =		ft_strncmp
FT_21 =		ft_atoi
FT_22 =		ft_isalpha
FT_23 =		ft_isdigit
FT_24 =		ft_isalnum
FT_25 =		ft_isascii
FT_26 =		ft_isprint
FT_27 =		ft_toupper
FT_28 =		ft_tolower
FT_29 =		ft_memalloc
FT_30 =		ft_memdel
FT_31 =		ft_strnew
FT_32 =		ft_strdel
FT_33 =		ft_strclr
FT_34 =		ft_striter
FT_35 =		ft_striteri
FT_36 =		ft_strmap
FT_37 =		ft_strmapi
FT_38 =		ft_strequ
FT_39 =		ft_strnequ
FT_40 =		ft_strsub
FT_41 =		ft_strjoin
FT_42 =		ft_strtrim
FT_43 =		ft_strsplit
FT_44 =		ft_itoa
FT_45 =		ft_putchar
FT_46 =		ft_putstr
FT_47 =		ft_putendl
FT_48 =		ft_putnbr
FT_49 =		ft_putchar_fd
FT_50 =		ft_putstr_fd
FT_51 =		ft_putendl_fd
FT_52 =		ft_putnbr_fd
FT_53 =		ft_lstnew
FT_54 =		ft_lstdelone
FT_55 =		ft_lstdel
FT_56 =		ft_lstadd
FT_57 =		ft_lstiter
FT_58 =		ft_lstmap
FT_59 =		ft_strctrim
FT_60 =		ft_sepchar
FT_61 =		ft_putbyte1
FT_62 =		ft_putbyte2
FT_63 =		ft_putbyte4
FT_64 =		ft_lstdelcut
FT_65 =		ft_delmass
FT_66 =		ft_swap
FT_67 =		ft_numlen
FT_68 =		ft_strchrcnt
FT_69 =		ft_min
FT_70 =		ft_max
FT_71 = 	ft_abs
FT_72 = 	get_next_line

FT_OBJ =	$(FT_1).o	$(FT_2).o	$(FT_3).o	$(FT_4).o	$(FT_5).o\
			$(FT_6).o	$(FT_7).o	$(FT_8).o	$(FT_9).o	$(FT_10).o\
			$(FT_11).o	$(FT_12).o	$(FT_13).o	$(FT_14).o	$(FT_15).o\
			$(FT_16).o	$(FT_17).o	$(FT_18).o	$(FT_19).o	$(FT_20).o\
			$(FT_21).o	$(FT_22).o	$(FT_23).o	$(FT_24).o	$(FT_25).o\
			$(FT_26).o	$(FT_27).o	$(FT_28).o	$(FT_29).o	$(FT_30).o\
			$(FT_31).o	$(FT_32).o	$(FT_33).o	$(FT_34).o	$(FT_35).o\
			$(FT_36).o	$(FT_37).o	$(FT_38).o	$(FT_39).o	$(FT_40).o\
			$(FT_41).o	$(FT_42).o	$(FT_43).o	$(FT_44).o	$(FT_45).o\
			$(FT_46).o	$(FT_47).o	$(FT_48).o	$(FT_49).o	$(FT_50).o\
			$(FT_51).o	$(FT_52).o	$(FT_53).o	$(FT_54).o	$(FT_55).o\
			$(FT_56).o	$(FT_57).o	$(FT_58).o	$(FT_59).o	$(FT_60).o\
			$(FT_61).o	$(FT_62).o	$(FT_63).o	$(FT_64).o	$(FT_65).o\
			$(FT_66).o	$(FT_67).o	$(FT_68).o	$(FT_69).o	$(FT_70).o\
			$(FT_71).o	$(FT_72).o

all: $(NAME)

$(NAME): $(FT_OBJ)
	@ar rc $(NAME) $(FT_OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(FT_OBJ)

fclean: clean
	@/bin/rm -f libft $(NAME)

re: fclean all

%.o : %.c
	@gcc $(FLAGS) -c $^

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 14:20:06 by kiroussa          #+#    #+#              #
#    Updated: 2023/11/11 06:22:23 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB			=	ftprintf
STATIC_LIB	=	lib$(LIB).a
NAME		=	$(STATIC_LIB)	

SRC_FILES	=	flag/ft_hash_mutator.c \
				flag/ft_leftjustify_mutator.c \
				flag/ft_padding_mutator.c \
				flag/ft_precision_mutator.c \
				type/ft_format_char.c \
				type/ft_format_hex.c \
				type/ft_format_int.c \
				type/ft_format_percent.c \
				type/ft_format_pointer.c \
				type/ft_format_string.c \
				type/ft_format_uint.c \
				utils/ft_prepend_sign.c \
				utils/ft_strnjoin.c \
				wrapper/ft_asprintf.c \
				wrapper/ft_dprintf.c \
				wrapper/ft_format.c \
				wrapper/ft_printf.c \
				wrapper/ft_vdprintf.c \
				wrapper/ft_vformat.c \
				wrapper/ft_vprintf.c \
				ft_free_spec.c \
				ft_format_spec.c \
				ft_parse_spec.c \
				ft_vasprintf.c

SRC_FOLDER	= 	src
SRC_FILES	:= 	$(addprefix $(SRC_FOLDER)/, $(SRC_FILES))
OBJ			= 	$(SRC_FILES:.c=.o)

LIBFT_SRC	=	libft
LIBFT		=	$(LIBFT_SRC)/build/output/libft.a

INCLUDE		=	include

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
COPTS		=	-fPIC -I $(INCLUDE) -I $(LIBFT_SRC)/include

AR			=	ar rcs
RM			=	rm -f

all: $(LIBFT) $(NAME)

bonus: all

$(LIBFT):
	make -C $(LIBFT_SRC) -j$(shell nproc)

$(NAME): $(OBJ)
	cp $(LIBFT) $(STATIC_LIB)
	$(AR) $(STATIC_LIB) $(OBJ)

test: test.o 
	$(CC) $(CFLAGS) $(COPTS) test.o $(STATIC_LIB) -o $(LIB)_tests
	./$(LIB)_tests

%.o: %.c
	$(CC) $(CFLAGS) $(COPTS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_SRC)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_SRC)

re: fclean all

.PHONY: all clean fclean re

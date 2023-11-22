# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 14:20:06 by kiroussa          #+#    #+#              #
#    Updated: 2023/11/22 15:35:03 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB			=	ftprintf
STATIC_LIB	=	lib$(LIB).a
NAME		=	$(STATIC_LIB)	

SRC_FILES	=	str/ft_str_append.c \
				str/ft_str_create.c \
				str/ft_str_init.c \
				type/ft_format_char.c \
				type/ft_format_hex.c \
				type/ft_format_int.c \
				type/ft_format_percent.c \
				type/ft_format_pointer.c \
				type/ft_format_string.c \
				type/ft_format_uint.c \
				utils/ft_append.c \
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

BONUS_SRC	=	flag/ft_hash_mutator_bonus.c \
				flag/ft_leftjustify_mutator_bonus.c \
				flag/ft_padding_mutator_bonus.c \
				flag/ft_precision_mutator_bonus.c

BONUS_FOLDER=	src_bonus
BONUS_SRC	+=	$(SRC_FILES:.c=_bonus.c)
BONUS_SRC	:= 	$(addprefix $(BONUS_FOLDER)/, $(BONUS_SRC))
BONUS_OBJ	= 	$(BONUS_SRC:.c=.o)

SRC_FOLDER	= 	src
SRC_FILES	:= 	$(addprefix $(SRC_FOLDER)/, $(SRC_FILES))
OBJ			= 	$(SRC_FILES:.c=.o)

LIBFT_SRC	=	libft
LIBFT		=	$(LIBFT_SRC)/build/output/libft.a

INCLUDE		=	include

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
COPTS		=	-fPIC -I $(INCLUDE) -I $(LIBFT_SRC)/include

AR			=	ar rcs
RM			=	rm -f

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_SRC) -j$(shell nproc) CFLAGS="$(CFLAGS)"

$(NAME): $(OBJ)
	cp $(LIBFT) $(STATIC_LIB)
	$(AR) $(STATIC_LIB) $(OBJ)

bonus: $(LIBFT) $(BONUS_OBJ)
	cp $(LIBFT) $(STATIC_LIB)
	$(AR) $(STATIC_LIB) $(BONUS_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(COPTS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)
	make clean -C $(LIBFT_SRC)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_SRC)

re: fclean all

.PHONY: all clean fclean re bonus

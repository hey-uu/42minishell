# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 11:46:51 by hyeyukim          #+#    #+#              #
#    Updated: 2023/01/14 22:02:33 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# **************************** command and flags ***************************** #

# compile
CC				=		cc
CFLAGS1			=		-Wall -Wextra -Werror
CFLAGS2			=		-fsanitize=address -g3

ifdef FSANITIZE_FLAG
	CFLAGS		=		$(CFLAGS1) $(CFLAGS2)
else
	CFLAGS		=		$(CFLAGS1)
endif

# library archive
AR				=		ar
ARFLAGS			=		crs

# remove
RM				=		rm
RMFLAGS			=		-rf

# ******************************** directory ********************************* #

SRC_DIR			=		src
OBJ_DIR			=		obj
INC_DIR			=		.

# ******************************* header files ******************************* #

INC_PATH		=		$(INC_DIR)
INC				=		libft_internal.h
INC_FLAG		=		-I./$(INC_PATH)

# ******************************* object files ******************************* #

SRC_FILE		=		ft_exit \
						ft_malloc \
						ft_isdigit \
						ft_strlen \
						ft_isalpha \
						ft_abs \
						ft_putstr_fd \
						ft_strlcpy \
						ft_strncmp \
						ft_strchr \
						ft_atoi \
						ft_bzero \
						ft_calloc \
						ft_isalnum \
						ft_isascii \
						ft_isprint \
						ft_memchr \
						ft_memcmp \
						ft_memcpy \
						ft_memmove \
						ft_memset \
						ft_strdup \
						ft_strlcat \
						ft_strnstr \
						ft_strrchr \
						ft_tolower \
						ft_toupper \
						ft_substr \
						ft_strjoin \
						ft_strtrim \
						ft_split \
						ft_itoa \
						ft_strmapi \
						ft_striteri \
						ft_putchar_fd \
						ft_putendl_fd \
						ft_putnbr_fd \
						ft_max \

OBJ				=		$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILE)))

# ******************************* basic rules ******************************** #

.PHONY : all bonus clean fclean re
all : $(NAME)
$(NAME) : $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)

bonus : all

clean :
	$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : 
	make fclean
	make all

# ****************************** compile rules ******************************* #

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC_DIR)/libft_internal.h
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $< $(INC_FLAG) -o $@

# ******************************* assist rules ******************************* #

# build program with flag "-fsanitize=address -g3"
.PHONY: fsanitize_all fsanitize_bonus
fsanitize_all :
	make FSANITIZE_FLAG=1 all

fsanitize_bonus :
	make FSANITIZE_FLAG=1 bonus

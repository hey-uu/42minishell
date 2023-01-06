# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    variables_definition.mk                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:45:38 by hyeyukim          #+#    #+#              #
#    Updated: 2023/01/06 11:21:48 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# commands and flags
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
AR = ar
ARFLAGS = crs
RM = rm
RMFLAGS = -rf

# library
LIB_DIR = lib

### libft
LIBFT_NAME = libft.a
LIBFT_DIR = $(LIB_DIR)/libft
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)
LIBFT_INC_DIR = $(LIBFT_DIR)/includes

# library flags
LIBFLAGS = -lft -L./$(LIBFT_DIR) -lreadline

# directory files
SRC_DIR = src
OBJ_DIR = obj
MAN_DIR = mandatory
BON_DIR = bonus

# header
INC_DIR = inc
MAN_INC_DIR = $(INC_DIR)/$(MAN_DIR)
BON_INC_DIR = $(INC_DIR)/$(BON_DIR)
MAN_INC_FILE =	minishell.h \
				prompt.h
BON_INC_FILE =	

MAN_INC = $(addprefix $(INC_DIR)/$(MAN_DIR)/, $(MAN_INC_FILE))
BON_INC = $(addprefix $(INC_DIR)/$(BON_DIR)/, $(BON_INC_FILE))
MAN_INC_FLAG = -I./$(MAN_INC_DIR) -I./$(LIBFT_INC_DIR)
BON_INC_FLAG = -I./$(BON_INC_DIR) -I./$(LIBFT_INC_DIR)

# file names
MAN_FILE =	main \
			prompt
BON_FILE =	


# object files
MAN_OBJ = $(addprefix $(OBJ_DIR)/$(MAN_DIR)/, $(addsuffix .o, $(MAN_FILE)))
BON_OBJ = $(addprefix $(OBJ_DIR)/$(BON_DIR)/, $(addsuffix .o, $(BON_FILE)))

# bonus
ifdef   WITH_BONUS
    RM_OBJ = $(MAN_OBJ)
    OBJ = $(BON_OBJ)
	INC = $(MAN_INC)
	INC_FLAG = $(MAN_INC_FLAG)
else
    RM_OBJ = $(BON_OBJ)
    OBJ = $(MAN_OBJ)
	INC = $(BON_INC)
	INC_FLAG = $(BON_INC_FLAG)
endif
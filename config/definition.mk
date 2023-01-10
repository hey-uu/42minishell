# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    definition.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:45:38 by hyeyukim          #+#    #+#              #
#    Updated: 2023/01/10 17:09:27 by yeonhkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************** command and flags ***************************** #

# compile
CC				=		cc
CFLAGS1			=		-Wall -Wextra -Werror
CFLAGS2			=		-fsanitize=address -g3

ifdef FSANITIZE_FLAG
	CFLAGS		=		$(CFLAGS1) $(CFLAGS2)
else
	CFLAGS		=		$(CFLAGS1)

# library archive
AR				=		ar
ARFLAGS			=		crs

# remove
RM				=		rm
RMFLAGS			=		-rf

# ******************************** directory ********************************* #

SRC_DIR			=		src
OBJ_DIR			=		obj
INC_DIR			=		include

MAN_DIR			=		mandatory
BON_DIR			=		bonus

SRC_DIR1		=		built-in
SRC_DIR2		=		executor
SRC_DIR3		=		expansion
SRC_DIR4		=		extra
SRC_DIR5		=		lexer
SRC_DIR6		=		parser

# ********************************* library ********************************** #

# directory name
LIB_DIR			=		lib

# libadt
LIBADT_DIR		=		libadt
LIBADT_NAME		=		libadt.a
LIBADT_PATH		=		$(LIB)/$(LIBADT_DIR)/$(LIBADT_NAME)

# libft
LIBFT_DIR		=		libft
LIBFT_NAME		=		libft.a
LIBFT_PATH		=		$(LIB_DIR)/$(LIBFT_DIR)/$(LIBFT_NAME)

# flags
LIBFLAGS		=		-lft -L./$(LIBFT_PATH) -ladt -L.$(LIBADT_PATH) -lreadline

# ******************************* header files ******************************* #

# directory path
LIB_INC_PATH	=		$(LIB_DIR)/$(INC_DIR)
MAN_INC_PATH	=		$(MAN_DIR)/$(INC_DIR)
BON_INC_PATH	=		$(BON_DIR)/$(INC_DIR)

# file name
INC_FILE		=		lexer \
						minishell \
						parser \
						prompt \
						signal

# file name(absolute path)
MAN_INC			=		$(addprefix $(MAN_INC_PATH)/, $(addsuffix .h, $(INC_FILE)))
BON_INC			=		$(addprefix $(BON_INC_PATH), $(addsuffix _bonus.h, $(INC_FILE)))

# flags
MAN_INC_FLAG	=		-I./$(MAN_INC_PATH) -I./$(LIB_INC_PATH)
BON_INC_FLAG	=		-I./$(BON_INC_PATH) -I./$(LIB_INC_PATH)

# ****************************** object files ******************************* #

# directory path
MAN_OBJ_PATH	=		$(MAN_DIR)/$(OBJ_DIR)
BON_OBJ_PATH	=		$(BON_DIR)/$(OBJ_DIR)
MAN_SRC_PATH	=		$(MAN_DIR)/$(SRC_DIR)
BON_SRC_PATH	=		$(BON_DIR)/$(SRC_DIR)

# file name
MAN_FILE		=		$(SRC_DIR1)/* \
						$(SRC_DIR2)/* \
						$(SRC_DIR3)/* \
						$(SRC_DIR4)/* \
						$(SRC_DIR5)/* \
						$(SRC_DIR6)/*
BON_FILE		=		

# file name(absolute path)
MAN_OBJ			=		$(addprefix $(MAN_OBJ_PATH)/, $(addsuffix .o, $(MAN_FILE)))
BON_OBJ			=		$(addprefix $(BON_OBJ_PATH)/, $(addsuffix .o, $(BON_FILE)))


# *********************************** bonus *********************************** #

# bonus flag
ifdef   WITH_BONUS
    RM_OBJ		=	 	$(MAN_OBJ)
    OBJ			=		$(BON_OBJ)
	INC			= 		$(MAN_INC)
	INC_FLAG	= 		$(MAN_INC_FLAG)
else
    RM_OBJ		= 		$(BON_OBJ)
    OBJ			=		$(MAN_OBJ)
	INC			=		$(BON_INC)
	INC_FLAG	=		$(BON_INC_FLAG)
endif

# *********************************** tester ********************************** #

# directory name
TEST_DIR		=		test
TEST_DIR1		=		hyeyukim
TEST_DIR2		=		yona

# directory path
TEST_PATH		=		$(TEST_DIR)
TEST_OBJ_PATH	=		$(TEST_DIR)/$(OBJ_DIR)
TEST_INC_PATH	=		$(TEST_DIR)

# header
TEST_INC_FILE	=		test.h
TEST_INC		=		$(addprefix $(TEST_INC_PATH), $(addsuffix _bonus.h, $(TEST_INC_FILE)))
TEST_INC_FLAG	=		-I./$(TEST_INC_PATH) -I./$(LIB_INC_PATH)

# file name
TEST_FILE		=		lexer_test \
						parser_test
TEST_FILE1		=		
TEST_FILE2		=		

# object file name(absolute path)
TEST_OBJ		=		$(addprefix $(TEST)/$(OBJ_DIR)/, $(addsuffix .o, $(TEST_FILE)))
TEST_OBJ1		=		$(addprefix $(TEST)/$(OBJ_DIR)/, $(addsuffix .o, $(TEST_FILE1)))
TEST_OBJ2		=		$(addprefix $(TEST)/$(OBJ_DIR)/, $(addsuffix .o, $(TEST_FILE2)))
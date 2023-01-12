# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    definition.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:45:38 by hyeyukim          #+#    #+#              #
#    Updated: 2023/01/12 11:47:04 by hyeyukim         ###   ########.fr        #
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
endif

# library archive
AR				=		ar
ARFLAGS			=		crs

# remove
RM				=		rm
RMFLAGS			=		-rf

# ********************************* library ********************************** #

# directory name
LIB_DIR			=		lib

# libadt
LIBADT_DIR		=		libadt
LIBADT_NAME		=		libadt.a
LIBADT_PATH		=		$(LIB_DIR)/$(LIBADT_DIR)
LIBADT			=		$(LIBADT_PATH)/$(LIBADT_NAME)

# libft
LIBFT_DIR		=		libft
LIBFT_NAME		=		libft.a
LIBFT_PATH		=		$(LIB_DIR)/$(LIBFT_DIR)
LIBFT			=		$(LIBFT_PATH)/$(LIBFT_NAME)

# flags
LIBFLAGS		=		-lft -L./$(LIBFT_PATH) -ladt -L./$(LIBADT_PATH) -lreadline

# ******************************** directory ********************************* #

SRC_DIR			=		src
OBJ_DIR			=		obj
INC_DIR			=		include

MAN_DIR			=		mandatory
BON_DIR			=		bonus

BUILTIN_DIR		=		built-in
EXECUTOR_DIR	=		executor
EXTRA_DIR		=		extra
LEXER_DIR		=		lexer
PARSER_DIR		=		parser
TREE_DIR		=		tree
DEV_DIR			=		dev

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
BON_INC			=		$(addprefix $(BON_INC_PATH)/, $(addsuffix _bonus.h, $(INC_FILE)))

# flags
MAN_INC_FLAG	=		-I./$(MAN_INC_PATH) -I./$(LIB_INC_PATH)
BON_INC_FLAG	=		-I./$(BON_INC_PATH) -I./$(LIB_INC_PATH)

# ******************************* object files ******************************* #

# directory path
MAN_OBJ_PATH	=		$(MAN_DIR)/$(OBJ_DIR)
BON_OBJ_PATH	=		$(BON_DIR)/$(OBJ_DIR)
MAN_SRC_PATH	=		$(MAN_DIR)/$(SRC_DIR)
BON_SRC_PATH	=		$(BON_DIR)/$(SRC_DIR)

# file name
BUILTIN_FILE	=		
EXECUTOR_FILE	=		
EXTRA_FILE		=		history \
						prompt \
						signal
LEXER_FILE		=		lexer 
PARSER_FILE		=		parse_list \
						parse_pipeline \
						parse_simple_command \
						parse_subshell \
						parser
TREE_FILE		=		create_execute_unit \
						create_tree_node \
						destroy_tree \
						push_execute_unit_content
SRC_FILE		=		$(addprefix $(BUILTIN_DIR)/, $(BUILTIN_FILE)) \
						$(addprefix $(EXECUTOR_DIR)/, $(EXECUTOR_FILE)) \
						$(addprefix $(EXTRA_DIR)/, $(EXTRA_FILE)) \
						$(addprefix $(LEXER_DIR)/, $(LEXER_FILE)) \
						$(addprefix $(PARSER_DIR)/, $(PARSER_FILE)) \
						$(addprefix $(TREE_DIR)/, $(TREE_FILE)) \
						main

# file name(absolute path)
MAN_OBJ			=		$(addprefix $(MAN_OBJ_PATH)/, $(addsuffix .o, $(SRC_FILE)))
BON_OBJ			=		$(addprefix $(BON_OBJ_PATH)/, $(addsuffix _bonus.o, $(SRC_FILE)))

LEXER_OBJ		=		$(addprefix $(MAN_OBJ_PATH)/$(LEXER_DIR)/, $(addsuffix .o, $(LEXER_FILE)))
PARSER_OBJ		=		$(addprefix $(MAN_OBJ_PATH)/$(PARSER_DIR)/, $(addsuffix .o, $(PARSER_FILE)))

# ************************************ dev ************************************ #

DEV_FILE		=		lexer_test1 \
						lexer_test2 \
						print_token_list \
						show_tree

# *********************************** bonus *********************************** #

# bonus flag
ifdef   WITH_BONUS
	RM_OBJ_DIR	=		$(MAN_OBJ_PATH)
    OBJ			=		$(BON_OBJ)
	INC			= 		$(BON_INC)
	INC_FLAG	= 		$(BON_INC_FLAG)
else
    RM_OBJ_DIR	= 		$(BON_OBJ_PATH)
    OBJ			=		$(MAN_OBJ)
	INC			=		$(MAN_INC)
	INC_FLAG	=		$(MAN_INC_FLAG)
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
TEST_INC_FILE	=		test
TEST_INC		=		$(addprefix $(TEST_INC_PATH)/, $(addsuffix .h, $(TEST_INC_FILE)))
TEST_INC_FLAG	=		-I./$(TEST_INC_PATH) -I./$(LIB_INC_PATH) -I./$(MAN_INC_PATH)

# file name
TEST_FILE		=		lexer_test \
						parser_test
TEST_FILE1		=		
TEST_FILE2		=		

# object file name(absolute path)
TEST_OBJ		=		$(addprefix $(TEST)/$(OBJ_DIR)/, $(addsuffix .o, $(TEST_FILE)))
TEST_OBJ1		=		$(addprefix $(TEST)/$(OBJ_DIR)/, $(addsuffix .o, $(TEST_FILE1)))
TEST_OBJ2		=		$(addprefix $(TEST)/$(OBJ_DIR)/, $(addsuffix .o, $(TEST_FILE2)))

LEXER_TEST_OBJ	=		$(LEXER_OBJ) $(TEST_OBJ_PATH)/lexer_test.o
LEXER_TEST_INC	=		$(MAN_INC_PATH)/lexer.h $(TEST_OBJ_PATH)/lexer_test.o $(TEST_INC_PATH)/test.h
PARSER_TEST_OBJ	=		$(LEXER_OBJ) $(PARSER_OBJ) $(TEST_OBJ_PATH)/parser_test.o
PARSER_TEST_INC	=		$(MAN_INC_PATH)/lexer.h $(MAN_INC_PATH)/parser.h $(TEST_INC_PATH)/test.h
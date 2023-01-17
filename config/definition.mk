# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    definition.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:45:38 by hyeyukim          #+#    #+#              #
#    Updated: 2023/01/17 13:38:07 by hyeyukim         ###   ########.fr        #
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
ENV_DIR			=		env_manager
EXPAND_DIR		=		expansion

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
EXTRA_FILE		=		error \
						history \
						prompt \
						signal \
						utils
LEXER_FILE		=		destroy_token_list \
						extract_token \
						lexer_utils \
						lexer
PARSER_FILE		=		parse_list \
						parse_pipeline \
						parse_simple_command \
						parse_subshell \
						parser \
						process_heredoc
TREE_FILE		=		create_execute_unit \
						create_tree_node \
						destroy_tree \
						push_execute_unit_content
ENV_FILE		=		env_internal \
						env_manager \
						env_utils \
						exit_stat_manager \
						exit_stat_utils
EXPAND_FILE		=		expand_variable \
						expand_word \
						expansion_allocation \
						field_split \
						destroy_expansion \
						words_to_strings
SRC_FILE		=		$(addprefix $(BUILTIN_DIR)/, $(BUILTIN_FILE)) \
						$(addprefix $(EXECUTOR_DIR)/, $(EXECUTOR_FILE)) \
						$(addprefix $(EXTRA_DIR)/, $(EXTRA_FILE)) \
						$(addprefix $(LEXER_DIR)/, $(LEXER_FILE)) \
						$(addprefix $(PARSER_DIR)/, $(PARSER_FILE)) \
						$(addprefix $(TREE_DIR)/, $(TREE_FILE)) \
						$(addprefix $(ENV_DIR)/, $(ENV_FILE)) \
						$(addprefix $(EXPAND_DIR)/, $(EXPAND_FILE))

# file name(absolute path)
MAN_NO_MAIN_OBJ	=		$(addprefix $(MAN_OBJ_PATH)/, $(addsuffix .o, $(SRC_FILE)))
MAN_OBJ			=		$(addprefix $(MAN_OBJ_PATH)/, $(addsuffix .o, $(SRC_FILE))) $(MAN_OBJ_PATH)/main.o
BON_OBJ			=		$(addprefix $(BON_OBJ_PATH)/, $(addsuffix _bonus.o, $(SRC_FILE))) $(BON_OBJ_PATH)/main.o

ERROR_OBJ		=		$(addprefix $(MAN_OBJ_PATH)/$(EXTRA_DIR)/, error.o)
LEXER_OBJ		=		$(addprefix $(MAN_OBJ_PATH)/$(LEXER_DIR)/, $(addsuffix .o, $(LEXER_FILE)))
PARSER_OBJ		=		$(addprefix $(MAN_OBJ_PATH)/$(PARSER_DIR)/, $(addsuffix .o, $(PARSER_FILE)))
TREE_OBJ		=		$(addprefix $(MAN_OBJ_PATH)/$(TREE_DIR)/, $(addsuffix .o, $(TREE_FILE)))
ENV_OBJ			=		$(addprefix $(MAN_OBJ_PATH)/$(ENV_DIR)/, $(addsuffix .o, $(ENV_FILE)))
EXPAND_OBJ		=		$(addprefix $(MAN_OBJ_PATH)/$(EXPAND_DIR)/, $(addsuffix .o, $(EXPAND_FILE)))

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

# ************************************ dev ************************************ #

# directory name
DEV_DIR			=		dev
MODULE_DIR		=		module
TEST_DIR		=		test

# directory path
DEV_PATH		=		$(DEV_DIR)
MODULE_PATH		=		$(DEV_PATH)/$(MODULE_DIR)
TEST_PATH		=		$(DEV_PATH)/$(TEST_DIR)

MODULE_OBJ_PATH	=		$(DEV_PATH)/$(OBJ_DIR)/$(MODULE_DIR)
TEST_OBJ_PATH	=		$(DEV_PATH)/$(OBJ_DIR)/$(TEST_DIR)

MODULE_INC_PATH	=		$(MODULE_PATH)
TEST_INC_PATH	=		$(TEST_PATH)

# header
TEST_INC_FILE	=		test
TEST_INC		=		$(addprefix $(TEST_INC_PATH)/, $(addsuffix .h, $(TEST_INC_FILE)))
TEST_INC_FLAG	=		-I./$(TEST_INC_PATH) -I./$(LIB_INC_PATH) -I./$(MAN_INC_PATH)

MODULE_INC_FILE	=		
MODULE_INC		=		$(addprefix $(TEST_INC_PATH)/, $(addsuffix .h, $(TEST_INC_FILE)))
MODULE_INC_FLAG	=		-I./$(MODULE_INC_PATH) -I./$(LIB_INC_PATH) -I./$(MAN_INC_PATH)

# file name

MODULE_FILE		=		print_token_list \
						show_tree \
						show_hash_table

# object file name(absolute path)
MODULE_OBJ		=		$(addprefix $(MODULE_OBJ_PATH)/, $(addsuffix .o, $(MODULE_FILE)))

LEXER_TEST_OBJ	=		$(ERROR_OBJ) $(LEXER_OBJ) $(MODULE_OBJ) $(TEST_OBJ_PATH)/lexer_test2.o
LEXER_TEST_INC	=		$(MAN_INC_PATH)/lexer.h $(TEST_INC)

PARSER_TEST_OBJ	=		$(MAN_NO_MAIN_OBJ) $(MODULE_OBJ) $(TEST_OBJ_PATH)/parser_test.o
PARSER_TEST_INC	=		$(MAN_INC_PATH)/lexer.h $(MAN_INC_PATH)/parser.h $(TEST_INC)

HASH_TEST_OBJ	=		$(TEST_OBJ_PATH)/hash_table_test2.o $(MODULE_OBJ_PATH)/show_hash_table.o
HASH_TEST_LIBFLAGS =	-lft -L./$(LIBFT_PATH) -ladt -L./$(LIBADT_PATH)

ENV_TEST_OBJ	=		$(TEST_OBJ_PATH)/env_table_test.o \
						$(MODULE_OBJ_PATH)/show_hash_table.o \
						$(ENV_OBJ) \
						$(MAN_OBJ_PATH)/$(EXTRA_DIR)/utils.o
ENV_TEST_LIBFLAGS	=	-lft -L./$(LIBFT_PATH) -ladt -L./$(LIBADT_PATH)

EXPAND_TEST_OBJ	=		$(MODULE_OBJ_PATH)/show_hash_table.o \
						$(ENV_OBJ) \
						$(EXPAND_OBJ) $(TEST_OBJ_PATH)/expansion_test.o \
						$(MAN_OBJ_PATH)/$(EXTRA_DIR)/utils.o
EXPAND_TEST_LIBFLAGS =	-lft -L./$(LIBFT_PATH) -ladt -L./$(LIBADT_PATH)

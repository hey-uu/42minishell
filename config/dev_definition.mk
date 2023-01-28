
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

TEST_INC_FLAG	=		-I./$(TEST_INC_PATH) -I./$(LIB_INC_PATH) \
						-I./$(MAN_INC_PATH) -I./$(MAN_STRUCT_INC_PATH) \
						-I./$(LIB_DIR)/$(LIBADT_DIR)
MODULE_INC_FLAG	=		-I./$(MODULE_INC_PATH) -I./$(LIB_INC_PATH)  \
						-I./$(MAN_INC_PATH) -I./$(MAN_STRUCT_INC_PATH) \
						-I./$(LIB_DIR)/$(LIBADT_DIR)

# file name

MODULE_FILE		=		print_token_list \
						show_tree \
						show_hash_table

# object file name(absolute path)

EXTRA_OBJ				=		$(addprefix $(MAN_OBJ_PATH)/$(EXTRA_DIR)/, $(addsuffix .o, $(EXTRA_FILE)))
ERROR_OBJ				=		$(addprefix $(MAN_OBJ_PATH)/$(EXTRA_DIR)/, error.o)
LEXER_OBJ				=		$(addprefix $(MAN_OBJ_PATH)/$(LEXER_DIR)/, $(addsuffix .o, $(LEXER_FILE)))
PARSER_OBJ				=		$(addprefix $(MAN_OBJ_PATH)/$(PARSER_DIR)/, $(addsuffix .o, $(PARSER_FILE)))
TREE_OBJ				=		$(addprefix $(MAN_OBJ_PATH)/$(TREE_DIR)/, $(addsuffix .o, $(TREE_FILE)))
ENV_MANAGER_OBJ			=		$(addprefix $(MAN_OBJ_PATH)/$(MANAGER_DIR)/$(ENV_MANAGER_DIR)/, $(addsuffix .o, $(ENV_MANAGER_FILE)))
EXIT_MANAGER_OBJ		=		$(addprefix $(MAN_OBJ_PATH)/$(MANAGER_DIR)/$(EXIT_MANAGER_DIR)/, $(addsuffix .o, $(EXIT_MANAGER_FILE)))
HEREDOC_MANAGER_OBJ		=		$(addprefix $(MAN_OBJ_PATH)/$(MANAGER_DIR)/$(HEREDOC_MANAGER_DIR)/, $(addsuffix .o, $(HEREDOC_MANAGER_FILE)))
EXPAND_OBJ				=		$(addprefix $(MAN_OBJ_PATH)/$(EXPAND_DIR)/, $(addsuffix .o, $(EXPAND_FILE)))
HEREDOC_OBJ				=		$(addprefix $(MAN_OBJ_PATH)/$(HEREDOC_DIR)/, $(addsuffix .o, $(HEREDOC_FILE)))
WRAPPED_OBJ				=		$(addprefix $(MAN_OBJ_PATH)/$(WRAPPED_DIR)/, $(addsuffix .o, $(WRAPPED_FILE)))

MODULE_OBJ		=		$(addprefix $(MODULE_OBJ_PATH)/, $(addsuffix .o, $(MODULE_FILE)))

LEXER_TEST_OBJ		=		$(ERROR_OBJ) $(LEXER_OBJ) $(MODULE_OBJ) $(TEST_OBJ_PATH)/lexer_test2.o
LEXER_TEST_INC		=		$(MAN_INC_PATH)/lexer.h $(TEST_INC)

PARSER_TEST_OBJ		=		$(MAN_NO_MAIN_OBJ) $(MODULE_OBJ) $(TEST_OBJ_PATH)/parser_test.o \
						$(TREE_OBJ) $(ENV_MANAGER_OBJ) $(EXIT_MANAGER_OBJ) $(HEREDOC_MANAGER_OBJ) \
						$(EXTRA_OBJ) $(LEXER_OBJ) $(PARSER_OBJ) $(HEREDOC_OBJ) $(WRAPPED_OBJ) $(EXPAND_OBJ)
PARSER_TEST_INC		=		$(MAN_INC_PATH)/lexer.h $(MAN_INC_PATH)/parser_internal.h $(TEST_INC)

HASH_TEST_OBJ		=		$(TEST_OBJ_PATH)/hash_table_test2.o $(MODULE_OBJ_PATH)/show_hash_table.o
HASH_TEST_LIBFLAGS 	=	-lft -L./$(LIBFT_PATH) -ladt -L./$(LIBADT_PATH)

ENV_TEST_OBJ		=		$(TEST_OBJ_PATH)/env_table_test.o \
						$(MODULE_OBJ_PATH)/show_hash_table.o \
						$(ENV_OBJ) \
						$(MAN_OBJ_PATH)/$(EXTRA_DIR)/utils.o
ENV_TEST_LIBFLAGS	=	-lft -L./$(LIBFT_PATH) -ladt -L./$(LIBADT_PATH)

EXPAND_TEST_OBJ	=		$(MODULE_OBJ_PATH)/show_hash_table.o \
						$(ENV_OBJ) \
						$(EXPAND_OBJ) $(TEST_OBJ_PATH)/expansion_test.o \
						$(MAN_OBJ_PATH)/$(EXTRA_DIR)/utils.o
EXPAND_TEST_LIBFLAGS =	-lft -L./$(LIBFT_PATH) -ladt -L./$(LIBADT_PATH)

EXPAND_TEST2_OBJ	=	$(MODULE_OBJ_PATH)/show_hash_table.o \
						$(TEST_OBJ_PATH)/expansion_test2.o \
						$(MAN_OBJ_PATH)/$(EXTRA_DIR)/utils.o \
						$(MAN_OBJ_PATH)/$(EXTRA_DIR)/error.o \
						$(ENV_OBJ) \
						$(LEXER_OBJ) \
						$(TREE_OBJ) \
						$(PARSER_OBJ) \
						$(HEREDOC_OBJ) \
						$(EXPAND_OBJ) 

BUILTIN_CD_TEST_OBJ	=	$(MODULE_OBJ_PATH)/show_hash_table.o \
						$(TEST_OBJ_PATH)/builtin_cd_test.o \
						$(MAN_OBJ_PATH)/$(BUILTIN_DIR)/builtin_cd.o \
						$(MAN_OBJ_PATH)/$(BUILTIN_DIR)/builtin_pwd.o \
						$(MAN_OBJ_PATH)/$(EXTRA_DIR)/utils.o \
						$(MAN_OBJ_PATH)/$(EXTRA_DIR)/error.o \
						$(ENV_OBJ)

BUILTIN_ECHO_TEST_OBJ =	$(TEST_OBJ_PATH)/builtin_echo_test.o \
						$(MAN_OBJ_PATH)/$(BUILTIN_DIR)/builtin_echo.o \
						$(MAN_OBJ_PATH)/$(EXTRA_DIR)/utils.o \
						$(ENV_OBJ)

BUILTIN_ENV_TEST_OBJ =	$(MODULE_OBJ_PATH)/show_hash_table.o \
						$(TEST_OBJ_PATH)/builtin_env_test.o \
						$(MAN_OBJ_PATH)/$(BUILTIN_DIR)/builtin_env.o \
						$(MAN_OBJ_PATH)/$(EXTRA_DIR)/utils.o \
						$(MAN_OBJ_PATH)/$(EXTRA_DIR)/error.o \
						$(ENV_OBJ)

BUILTIN_EXIT_TEST_OBJ =	$(MODULE_OBJ_PATH)/show_hash_table.o \
						$(TEST_OBJ_PATH)/builtin_exit_test.o \
						$(MAN_OBJ_PATH)/$(BUILTIN_DIR)/builtin_exit.o \
						$(MAN_OBJ_PATH)/$(EXTRA_DIR)/utils.o \
						$(MAN_OBJ_PATH)/$(EXTRA_DIR)/error.o \
						$(ENV_OBJ)

TEST				=	lexer_test \
						parser_test \
						hash_test \
						env_test \
						expand_test \
						expand_test2 \
						builtin_cd_test \
						builtin_echo_test \
						builtin_env_test \
						builtin_exit_test

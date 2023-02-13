# **************************** command and flags ***************************** #

# compile
CC						=		cc
CFLAGS1					=		-MMD -MP
CFLAGS2					=		-Wall -Wextra -Werror
CFLAGS3					=		-fsanitize=address -g3
CFLAGS					=		$(CFLAGS1) $(CFLAGS2)

ifdef FSANITIZE_FLAG
	CFLAGS				+=		$(CFLAGS3)
endif

# library archive
AR						=		ar
ARFLAGS					=		crs

# remove
RM						=		rm
RMFLAGS					=		-rf

# ********************************* library ********************************** #

# directory name
LIB_DIR					=		lib

# libadt
LIBADT_DIR				=		libadt
LIBADT_NAME				=		libadt.a
LIBADT_PATH				=		$(LIB_DIR)/$(LIBADT_DIR)
LIBADT					=		$(LIBADT_PATH)/$(LIBADT_NAME)

# libft
LIBFT_DIR				=		libft
LIBFT_NAME				=		libft.a
LIBFT_PATH				=		$(LIB_DIR)/$(LIBFT_DIR)
LIBFT					=		$(LIBFT_PATH)/$(LIBFT_NAME)

# flags
LIBFLAGS				=		-lft -L./$(LIBFT_PATH) -ladt -L./$(LIBADT_PATH) \
								-lreadline -L $(shell brew --prefix readline)/lib/

# ******************************** directory ********************************* #

SRC_DIR					=		src
OBJ_DIR					=		obj
INC_DIR					=		include
STRUCT_DIR				=		struct

MAN_DIR					=		mandatory
BON_DIR					=		bonus

BUILTIN_DIR				=		builtin
EXECUTOR_DIR			=		executor
EXTRA_DIR				=		extra
LEXER_DIR				=		lexer
PARSER_DIR				=		parser
TREE_DIR				=		tree
MANAGER_DIR				=		manager
ENV_MANAGER_DIR			=		env_manager
EXIT_MANAGER_DIR		=		exit_stat_manager
HEREDOC_MANAGER_DIR		=		heredoc_manager
EXPAND_DIR				=		expansion
HEREDOC_DIR				=		heredoc
WRAPPED_DIR				=		wrapped_syscall

DEV_DIR					=		dev

# ******************************* header files ******************************* #

# directory path
LIB_INC_PATH			=		$(LIB_DIR)/$(INC_DIR)
MAN_INC_PATH			=		$(MAN_DIR)/$(INC_DIR)
MAN_STRUCT_INC_PATH		=		$(MAN_DIR)/$(INC_DIR)/$(STRUCT_DIR)
BON_INC_PATH			=		$(BON_DIR)/$(INC_DIR)
BON_STRUCT_INC_PATH		=		$(BON_DIR)/$(INC_DIR)/$(STRUCT_DIR)

# flags
MAN_INC_FLAG			=		-I./$(MAN_INC_PATH) -I./$(MAN_STRUCT_INC_PATH)\
								-I./$(LIB_INC_PATH) -I./$(LIBADT_PATH)\
								-I$(shell brew --prefix readline)/include/
BON_INC_FLAG			=		-I./$(BON_INC_PATH) -I./$(BON_STRUCT_INC_PATH)\
								-I./$(LIB_INC_PATH) -I./$(LIBADT_PATH)\
								-I$(shell brew --prefix readline)/include/

# ******************************* object files ******************************* #

# directory path
MAN_OBJ_PATH			=		$(MAN_DIR)/$(OBJ_DIR)
BON_OBJ_PATH			=		$(BON_DIR)/$(OBJ_DIR)
MAN_SRC_PATH			=		$(MAN_DIR)/$(SRC_DIR)
BON_SRC_PATH			=		$(BON_DIR)/$(SRC_DIR)

include config/filename.mk

SRC_FILE				=		$(addprefix $(BUILTIN_DIR)/, $(BUILTIN_FILE)) \
								$(addprefix $(EXECUTOR_DIR)/, $(EXECUTOR_FILE)) \
								$(addprefix $(EXTRA_DIR)/, $(EXTRA_FILE)) \
								$(addprefix $(LEXER_DIR)/, $(LEXER_FILE)) \
								$(addprefix $(PARSER_DIR)/, $(PARSER_FILE)) \
								$(addprefix $(TREE_DIR)/, $(TREE_FILE)) \
								$(addprefix $(MANAGER_DIR)/$(ENV_MANAGER_DIR)/, $(ENV_MANAGER_FILE)) \
								$(addprefix $(MANAGER_DIR)/$(EXIT_MANAGER_DIR)/, $(EXIT_MANAGER_FILE)) \
								$(addprefix $(MANAGER_DIR)/$(HEREDOC_MANAGER_DIR)/, $(HEREDOC_MANAGER_FILE)) \
								$(addprefix $(EXPAND_DIR)/, $(EXPAND_FILE)) \
								$(addprefix $(HEREDOC_DIR)/, $(HEREDOC_FILE)) \
								$(addprefix $(WRAPPED_DIR)/, $(WRAPPED_FILE)) \
								$(MAIN_FILE)

# file name(absolute path)
MAN_OBJ					=		$(addprefix $(MAN_OBJ_PATH)/, $(addsuffix .o, $(SRC_FILE)))
BON_OBJ					=		$(addprefix $(BON_OBJ_PATH)/, $(addsuffix _bonus.o, $(SRC_FILE)))


# ****************************** dependency files ***************************** #

MAN_DEP					=		$(MAN_OBJ:.o=.d)
BON_DEP					=		$(BON_OBJ:.o=.d)

# *********************************** bonus *********************************** #

# bonus flag
ifdef   WITH_BONUS
	RM_OBJ_DIR			=		$(MAN_OBJ_PATH)
    OBJ					=		$(BON_OBJ)
	INC					= 		$(BON_INC)
	INC_FLAG			= 		$(BON_INC_FLAG)
else
    RM_OBJ_DIR			= 		$(BON_OBJ_PATH)
    OBJ					=		$(MAN_OBJ)
	INC					=		$(MAN_INC)
	INC_FLAG			=		$(MAN_INC_FLAG)
endif

# ************************************ dev ************************************ #

include config/dev_definition.mk

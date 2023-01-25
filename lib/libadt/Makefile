# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 19:19:22 by hyeyukim          #+#    #+#              #
#    Updated: 2023/01/25 11:23:43 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libadt.a
.DEFAULT_GOAL := all

# **************************** command and flags ***************************** #

# compile
CC				=		cc
CFLAGS1			=		-Wall -Wextra -Werror
CFLAGS2			=		-MMD -MP
CFLAGS3			=		-fsanitize=address -g3

ifdef FSANITIZE_FLAG
	CFLAGS		=		$(CFLAGS1) $(CFLAGS2) $(CFLAGS3)
else
	CFLAGS		=		$(CFLAGS1) $(CFLAGS2)
endif

# library archive
AR				=		ar
ARFLAGS			=		crs

# remove
RM				=		rm
RMFLAGS			=		-rf

# ********************************* library ********************************** #

# libft
LIBFT_DIR		=		libft
LIBFT_NAME		=		libft.a
LIBFT_PATH		=		../$(LIBFT_DIR)
LIBFT			=		$(LIBFT_PATH)/$(LIBFT_NAME)

# flags
LIBFLAGS		=		-lft -L./$(LIBFT_PATH)

# ******************************** directory ********************************* #

DARR_DIR		=		dynamic_array
HASH_DIR		=		hash_table
LIST_DIR		=		list
QUEUE_DIR		=		queue

OBJ_DIR			=		obj
INC_DIR			=		include

# ******************************* header files ******************************* #

LIBFT_INC_PATH	=		../$(INC_DIR)
LIBADT_INC_PATH	=		.
DARR_INC_PATH	=		$(DARR_DIR)
HASH_INC_PATH	=		$(HASH_DIR)
LIST_INC_PATH	=		$(LIST_DIR)
QUEUE_INC_PATH	=		$(QUEUE_DIR)

DARR_INC_FLAG	=		-I./$(DARR_DIR) -I./$(LIBFT_INC_PATH) -I./$(LIBADT_INC_PATH)
HASH_INC_FLAG	=		-I./$(HASH_DIR) -I./$(LIBFT_INC_PATH) -I./$(LIBADT_INC_PATH)
LIST_INC_FLAG	=		-I./$(LIST_DIR) -I./$(LIBFT_INC_PATH) -I./$(LIBADT_INC_PATH)
QUEUE_INC_FLAG	=		-I./$(QUEUE_DIR) -I./$(LIBFT_INC_PATH) -I./$(LIBADT_INC_PATH)

# ******************************* object files ******************************* #

DARR_FILE		=		darr_create \
						darr_destroy \
						darr_get_arr \
						darr_push \
						darr_resize \
						darr_pop \
						darr_push \
						darr_resize \
						darr_show
HASH_FILE		=		hash_function \
						hash_table_create \
						hash_table_destroy \
						hash_table_insert \
						hash_table_resize \
						hash_table_search \
						hash_table_update
LIST_FILE		=		list_add \
						list_create \
						list_destroy \
						list_iterate \
						list_map \
						list_utils
QUEUE_FILE		=		queue_create \
						queue_destroy \
						queue_get_arr \
						queue_get \
						queue_pop \
						queue_push \
						queue_resize \
						queue_show

DARR_OBJ		=		$(addprefix $(OBJ_DIR)/$(DARR_DIR)/, $(addsuffix .o, $(DARR_FILE)))
LIST_OBJ		=		$(addprefix $(OBJ_DIR)/$(LIST_DIR)/, $(addsuffix .o, $(LIST_FILE)))
QUEUE_OBJ		=		$(addprefix $(OBJ_DIR)/$(QUEUE_DIR)/, $(addsuffix .o, $(QUEUE_FILE)))
HASH_OBJ		=		$(addprefix $(OBJ_DIR)/$(HASH_DIR)/, $(addsuffix .o, $(HASH_FILE)))
OBJ				=		$(DARR_OBJ) $(HASH_OBJ) $(LIST_OBJ) $(QUEUE_OBJ)

# ***************************** dependency files ***************************** #

DEP				=		$(OBJ:.o=.d)

# ******************************* basic rules ******************************** #

.PHONY : all bonus clean fclean re
all : $(NAME)
$(NAME) : $(LIBFT) $(OBJ)
	cp $(LIBFT) $@
	$(AR) $(ARFLAGS) $@ $(OBJ)

bonus : all

clean :
	make -C $(LIBFT_PATH) fclean
	$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : 
	make fclean
	make all

# **************************** dependency rules ****************************** #

ifeq ($(MAKECMDGOALS), fclean)
else ifeq ($(MAKECMDGOALS), clean)
else
	-include $(DEP)
endif

# ****************************** compile rules ******************************* #

$(OBJ_DIR)/$(DARR_DIR)/%.o : $(DARR_DIR)/%.c $(LIBFT)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(DARR_DIR)
	$(CC) -c $(CFLAGS) $< $(DARR_INC_FLAG) -o $@

$(OBJ_DIR)/$(LIST_DIR)/%.o : $(LIST_DIR)/%.c $(LIBFT)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(LIST_DIR)
	$(CC) -c $(CFLAGS) $< $(LIST_INC_FLAG) -o $@

$(OBJ_DIR)/$(QUEUE_DIR)/%.o : $(QUEUE_DIR)/%.c $(LIBFT)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(QUEUE_DIR)
	$(CC) -c $(CFLAGS) $< $(QUEUE_INC_FLAG) -o $@

$(OBJ_DIR)/$(HASH_DIR)/%.o : $(HASH_DIR)/%.c $(LIBFT)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(HASH_DIR)
	$(CC) -c $(CFLAGS) $< $(HASH_INC_FLAG) -o $@

$(LIBFT) :
	make -C $(LIBFT_PATH) $(FSAN_OPT) all

# ******************************* assist rules ******************************* #

# build program with flag "-fsanitize=address -g3"
.PHONY: fsanitize_all fsanitize_bonus
fsanitize_all :
	make FSANITIZE_FLAG=1 all

fsanitize_bonus :
	make FSANITIZE_FLAG=1 bonus

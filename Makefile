# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:45:28 by hyeyukim          #+#    #+#              #
#    Updated: 2023/01/16 06:43:41 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

include config/definition.mk

# ******************************* basic rules ******************************** #

.PHONY : all bonus
all : $(NAME)
$(NAME) : $(INC) $(OBJ)
	$(RM) $(RMFLAGS) $(RM_OBJ_DIR)
	make -C $(LIBADT_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFLAGS) -o $@

bonus :
	make WITH_BONUS=1 all

include config/rules.mk

.PHONY : clean fclean re
clean :
	$(RM) $(RMFLAGS) $(MAN_OBJ_PATH) $(BON_OBJ_PATH)
	make -C $(LIBADT_PATH) fclean
	make test_fclean

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re :
	make fclean
	make all

# ******************************* assist rules ******************************* #

# build program with flag "-fsanitize=address -g3"
.PHONY: fsanitize_all fsanitize_bonus
fsanitize_all :
	make FSANITIZE_FLAG=1 all

fsanitize_bonus :
	make FSANITIZE_FLAG=1 bonus

# build test program
lexer_test : $(LEXER_TEST_OBJ) $(LEXER_TEST_INC)
	make -C $(LIBADT_PATH)
	$(CC) $(CFLAGS) $(LEXER_TEST_OBJ) $(LIBFLAGS) -o lexer_test

parser_test : $(PARSER_TEST_OBJ) $(PARSER_TEST_INC)
	make -C $(LIBADT_PATH)
	$(CC) $(CFLAGS) $(PARSER_TEST_OBJ) $(LIBFLAGS) -o parser_test

hash_test : $(HASH_TEST_OBJ) $(HASH_TEST_INC)
	make -C $(LIBADT_PATH)
	$(CC) $(CFLAGS) $(HASH_TEST_OBJ) $(HASH_TEST_LIBFLAGS) -o hash_test

env_test : $(ENV_TEST_OBJ) $(ENV_TEST_INC)
	make -C $(LIBADT_PATH)
	$(CC) $(CFLAGS) $(ENV_TEST_OBJ) $(ENV_TEST_LIBFLAGS) -o env_test

expand_test : $(EXPAND_TEST_OBJ)
	make -C $(LIBADT_PATH)
	$(CC) $(CFLAGS) $(EXPAND_TEST_OBJ) $(EXPAND_TEST_LIBFLAGS) -o expand_test

# remove test program
.PHONY : test_clean test_fclean
test_clean :
	$(RM) $(RMFLAGS) $(DEV_PATH)/$(OBJ_DIR)

test_fclean : test_clean
	$(RM) $(RMFLAGS) lexer_test parser_test hash_test env_test expand_test

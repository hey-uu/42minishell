# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:45:28 by hyeyukim          #+#    #+#              #
#    Updated: 2023/01/28 18:44:25 by yeonhkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
.DEFAULT_GOAL := all

include config/definition.mk

# ******************************* basic rules ******************************** #

.PHONY : all bonus
all : $(NAME)
$(NAME) : $(OBJ)
	$(RM) $(RMFLAGS) $(RM_OBJ_DIR)
	make -C $(LIBADT_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFLAGS) -o $@

bonus :
	make WITH_BONUS=1 all

include config/rules.mk

.PHONY : clean fclean re
clean :
	$(RM) $(RMFLAGS) $(MAN_OBJ_PATH) $(BON_OBJ_PATH) 
	$(RM) $(RMFLAGS) $(MAN_DIR)/objFlib $(BON_DIR)/objFlib
	make -C $(LIBADT_PATH) fclean
	make test_fclean

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re :
	make fclean
	make all

# ******************************* assist rules ******************************* #

# build test program
lexer_test : $(LIBADT) $(LEXER_TEST_OBJ) $(LEXER_TEST_INC)
	$(CC) $(CFLAGS) $(LEXER_TEST_OBJ) $(LIBFLAGS) -o lexer_test

parser_test : $(LIBADT)  $(PARSER_TEST_OBJ)
	$(CC) $(CFLAGS) $(PARSER_TEST_OBJ) \
	-lft -L./$(LIBFT_PATH) -ladt -L./$(LIBADT_PATH) -lreadline -L $(shell brew --prefix readline)/lib/ -o parser_test

hash_test : $(LIBADT) $(HASH_TEST_OBJ) $(HASH_TEST_INC)
	$(CC) $(CFLAGS) $(HASH_TEST_OBJ) $(HASH_TEST_LIBFLAGS) -o hash_test

env_test : $(LIBADT) $(ENV_TEST_OBJ) $(ENV_TEST_INC)
	$(CC) $(CFLAGS) $(ENV_TEST_OBJ) $(ENV_TEST_LIBFLAGS) -o env_test

expand_test : $(LIBADT) $(EXPAND_TEST_OBJ)
	$(CC) $(CFLAGS) $(EXPAND_TEST_OBJ) $(EXPAND_TEST_LIBFLAGS) -o expand_test

expand_test2 : $(LIBADT) $(EXPAND_TEST2_OBJ)
	$(CC) $(CFLAGS) $(EXPAND_TEST2_OBJ) $(LIBFLAGS) -o expand_test2

builtin_cd_test : $(LIBADT) $(BUILTIN_CD_TEST_OBJ)
	$(CC) $(CFLAGS) $(BUILTIN_CD_TEST_OBJ) $(LIBFLAGS) -o builtin_cd_test

builtin_echo_test : $(LIBADT) $(BUILTIN_ECHO_TEST_OBJ)
	$(CC) $(CFLAGS) $(BUILTIN_ECHO_TEST_OBJ) $(LIBFLAGS) -o builtin_echo_test

builtin_env_test : $(LIBADT) $(BUILTIN_ENV_TEST_OBJ)
	$(CC) $(CFLAGS) $(BUILTIN_ENV_TEST_OBJ) $(LIBFLAGS) -o builtin_env_test

builtin_exit_test : $(LIBADT) $(BUILTIN_EXIT_TEST_OBJ)
	$(CC) $(CFLAGS) $(BUILTIN_EXIT_TEST_OBJ) $(LIBFLAGS) -o builtin_exit_test

# remove test program
.PHONY : test_clean test_fclean
test_clean :
	$(RM) $(RMFLAGS) $(DEV_PATH)/$(OBJ_DIR)

test_fclean : test_clean
	$(RM) $(RMFLAGS) $(TEST)


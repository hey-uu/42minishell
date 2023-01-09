# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:45:28 by hyeyukim          #+#    #+#              #
#    Updated: 2023/01/09 18:10:23 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

include config/variables_definition.mk

.PHONY : all
all : $(NAME)
$(NAME) : $(INCS) $(OBJ)
	$(RM) $(RMFLAGS) $(RM_OBJ)
	make -C $(LIBFT_DIR) adt
	$(CC) $(CFLAGS) $(OBJ) $(LIBFLAGS) -o $@

.PHONY : bonus
bonus :
	make WITH_BONUS=1 all

include config/compile_rules.mk

# basic rules
.PHONY : clean fclean re
clean :
	$(RM) $(RMFLAGS) $(OBJ_DIR)
	make -C $(LIBFT_DIR) fclean

fclean : clean test_fclean
	$(RM) $(RMFLAGS) $(NAME)
re :
	make fclean
	make all

lexer_test : obj/mandatory/lexer.o $(OBJ_DIR)/$(TEST_HYE_DIR)/lexer_test.o
	make -C $(LIBFT_DIR) adt
	$(CC) $(CFLAGS) $^ $(LIBFLAGS) -o lexer_test

parser_test : obj/mandatory/lexer.o obj/mandatory/parser.o $(OBJ_DIR)/$(TEST_HYE_DIR)/parser_test.o
	make -C $(LIBFT_DIR) adt
	$(CC) $(CFLAGS) $^  $(LIBFLAGS) -o parser_test

.PHONY : test_fclean
test_fclean :
	$(RM) $(RMFLAGS) $(OBJ_DIR)/$(TEST_DIR)
	$(RM) $(RMFLAGS) lexer_test
	$(RM) $(RMFLAGS) parser_test
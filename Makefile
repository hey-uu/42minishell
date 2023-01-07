# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:45:28 by hyeyukim          #+#    #+#              #
#    Updated: 2023/01/07 23:56:59 by hyeyun           ###   ########.fr        #
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

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
re :
	make fclean
	make all

lexer_test : obj/mandatory/lexer.o $(OBJ_DIR)/$(TEST_HYE_DIR)/lexer_test.o
	make -C $(LIBFT_DIR) adt
	$(CC) $(CFLAGS) $^ $(LIBFLAGS) -o lexer_test

.PHONY : test_clean
test_fclean :
	$(RM) $(RMFLAGS) $(OBJ_DIR)/$(TEST_DIR)
	$(RM) $(RMFLAGS) lexer_test

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:45:28 by hyeyukim          #+#    #+#              #
#    Updated: 2023/01/10 18:42:27 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

include config/definition.mk

# ******************************* basic rules ******************************** #

.PHONY : all bonus
all : $(NAME)
$(NAME) : $(INC) $(OBJ)
	$(RM) $(RMFLAGS) $(RM_OBJ_DIR)
	make -C $(LIBFT_PATH)
	make -C $(LIBADT_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFLAGS) -o $@

bonus :
	make WITH_BONUS=1 all

include config/rules.mk

.PHONY : clean fclean re
clean :
	$(RM) $(RMFLAGS) $(MAN_OBJ_PATH) $(BON_OBJ_PATH)
	make -C $(LIBFT_PATH) fclean
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
man_lexer_test :	$(addprefix $(MAN_OBJ_PATH)/$(LEXER_DIR)/, $(addsuffix .o, $(LEXER_FILE))) \
					$(MAN_INC_PATH)/lexer.h \
					$(TEST_OBJ_PATH)/lexer_test.o \
					$(TEST_INC_PATH)/test.h
	make -C $(LIBFT_PATH)
	make -C $(LIBADT_PATH)
	$(CC) $(CFLAGS) $^ $(LIBFLAGS) -o man_lexer_test

man_parser_test :	$(addprefix $(MAN_OBJ_PATH)/$(LEXER_DIR)/, $(addsuffix .o, $(LEXER_FILE))) \
					$(MAN_INC_PATH)/lexer.h \
					$(addprefix $(MAN_OBJ_PATH)/$(PARSER_DIR)/, $(addsuffix .o, $(PARSER_FILE))) \
					$(MAN_INC_PATH)/parser.h \
					$(TEST_OBJ_PATH)/parser_test.o
					$(TEST_INC_PATH)/test.h
	make -C $(LIBFT_PATH)
	make -C $(LIBADT_PATH)
	$(CC) $(CFLAGS) $^  $(LIBFLAGS) -o man_parser_test

# remove test program
.PHONY : test_clean test_fclean
test_clean :
	$(RM) $(RMFLAGS) $(TEST_OBJ_PATH)

test_fclean : test_clean
	$(RM) $(RMFLAGS) man_lexer_test
	$(RM) $(RMFLAGS) man_parser_test

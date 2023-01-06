# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:45:28 by hyeyukim          #+#    #+#              #
#    Updated: 2023/01/06 11:09:34 by hyeyukim         ###   ########.fr        #
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

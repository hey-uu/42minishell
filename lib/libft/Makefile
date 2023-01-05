# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 11:46:51 by hyeyukim          #+#    #+#              #
#    Updated: 2022/11/16 01:52:55 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

include config/variables_definition.mk

.PHONY : all
all : $(NAME)
$(NAME) : $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)

include config/compile_rules.mk

# options for making the libft library
.PHONY : bonus printf gnl printf_gnl
bonus :
	# libft with linked list utils
	make WITH_BONUS=1 all
printf :
	# libft with ft_printf
	make WITH_PRINTF=1 all
gnl :
	# libft with get_next_line
	make WITH_GNL=1 all
printf_gnl :
	# libft with printf and get_next_line
	make WITH_PRINTF=1 WITH_GNL=1 all

# basic rules
.PHONY : clean fclean re
clean :
	$(RM) $(RMFLAGS) $(OBJ_DIR)
fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
re : 
	make fclean
	make all


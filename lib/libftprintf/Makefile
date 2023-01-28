# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 04:10:17 by yona              #+#    #+#              #
#    Updated: 2023/01/28 13:35:38 by yeonhkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	= all

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -MMD -MP
CPPFLAGS		= -I./includes
RM				= rm -f

# ******************************** FT_PRINTF ********************************* #

FTPRINTF 		= libftprintf.a
FILE 			=  \
					printf\
					f_info\
					out\
					put_txt\
					put_num\
					fmt_itoa\
					fmt_lst\
					utils/atoi\
					utils/cmpvalue\
					utils/mem\
					utils/str
SRCS			= $(addprefix ./src/, $(addsuffix $(SUFFIX).c, $(FILE)))
OBJS			= $(SRCS:.c=.o)
DEPS			= $(OBJS:.o=.d)

ifeq ($(MAKECMDGOALS), fclean)
else ifeq ($(MAKECMDGOALS), clean)
else
	-include $(DEPS)
endif

$(FTPRINTF) : $(OBJS)
	ar crs $@ $^

# ******************************** MAKE RULES ******************************* #

all : $(FTPRINTF)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(FTPRINTF) $(OBJS)

re : 
	make fclean
	make all

.PHONY : all clean fclean re
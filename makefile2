# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 02:56:10 by yeonhkim          #+#    #+#              #
#    Updated: 2022/12/05 20:08:12 by yeonhkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	= all

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
CPPFLAGS		= -I./libft
LDFLAGS			= -L./libft
LDLIBS			= -lft

# *********************************** LIBFT ********************************** #

LIBFT			= libft.a

LIBFT_PATH		= ./libft

$(LIBFT):
	make -C $(LIBFT_PATH)

# ********************************** MINITALK ******************************** #

SERVER			= server
CLIENT			= client

ifdef BONUS
MINITALK_PATH	= ./bonus/
SUFFIX			= _bonus
else
MINITALK_PATH	= ./mandatory/
SUFFIX 			= 
endif

SERVER_SRCS		=	server.c\
					common.c
CLIENT_SRCS		=	client.c\
					common.c

$(SERVER): $(addprefix $(MINITALK_PATH), $(SERVER_SRCS:.c=$(SUFFIX).o))
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(CLIENT): $(addprefix $(MINITALK_PATH), $(CLIENT_SRCS:.c=$(SUFFIX).o))
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

# ********************************* MAKE RULES ******************************* #
# **************************************************************************** #

all:
	make -C $(LIBFT_PATH) --silent
	make $(SERVER)
	make $(CLIENT)

bonus:
	make -C $(LIBFT_PATH) --silent
	BONUS=1 make $(SERVER)
	BONUS=1 make $(CLIENT)

clean:
	make -C $(LIBFT_PATH) clean --silent
	rm -f $(addprefix ./mandatory/, $(SERVER_SRCS:.c=.o) $(CLIENT_SRCS:.c=.o))
	rm -f $(addprefix ./bonus/, $(SERVER_SRCS:.c=_bonus.o) $(CLIENT_SRCS:.c=_bonus.o))

fclean:
	make -C $(LIBFT_PATH) fclean --silent
	rm -f $(addprefix ./mandatory/, $(SERVER_SRCS:.c=.o) $(CLIENT_SRCS:.c=.o))
	rm -f $(addprefix ./bonus/, $(SERVER_SRCS:.c=_bonus.o) $(CLIENT_SRCS:.c=_bonus.o))
	rm -f $(SERVER) $(CLIENT)

re: 
	make fclean
	make all

.PHONY: all clean fclean re bonus
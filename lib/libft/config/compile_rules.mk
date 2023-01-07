# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile_rules.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 08:37:47 by hyeyukim          #+#    #+#              #
#    Updated: 2023/01/07 18:39:52 by yeonhkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile rules

$(OBJ_DIR)/$(LIBFT_DIR)/%.o : $(LIBFT_DIR)/%.c $(INC_DIR)/libft.h
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(LIBFT_DIR)
	@$(CC) -c $(CFLAGS) $< -I$(INC_DIR) -o $@

$(OBJ_DIR)/$(BONUS_DIR)/%.o : $(BONUS_DIR)/%.c $(INC_DIR)/libft_bonus.h
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(BONUS_DIR)
	@$(CC) -c $(CFLAGS) $< -I$(INC_DIR) -o $@

$(OBJ_DIR)/$(PRINTF_DIR)/%.o : $(PRINTF_DIR)/%.c $(INC_DIR)/ft_printf.h
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(PRINTF_DIR)
	@$(CC) -c $(CFLAGS) $< -I$(INC_DIR) -o $@

$(OBJ_DIR)/$(GNL_DIR)/%.o : $(GNL_DIR)/%.c $(INC_DIR)/get_next_line.h
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(GNL_DIR)
	@$(CC) -c $(CFLAGS) $< -I$(INC_DIR) -o $@

$(OBJ_DIR)/$(ADT_DIR)/%.o : $(ADT_DIR)/%.c $(INC_DIR)/vector.h
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(ADT_DIR)
	@$(CC) -c $(CFLAGS) $< -I$(INC_DIR) -o $@
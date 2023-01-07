# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile_rules.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:45:44 by hyeyukim          #+#    #+#              #
#    Updated: 2023/01/07 19:49:04 by yeonhkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile rules

$(OBJ_DIR)/$(MAN_DIR)/%.o : $(SRC_DIR)/$(MAN_DIR)/%.c $(MAN_INC)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(MAN_DIR)
	@$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(OBJ_DIR)/$(BON_DIR)/%.o : $(SRC_DIR)/$(BON_DIR)/%.c $(BON_INC)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(BON_DIR)
	@$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

test/hyeyukim/lexer_test.o : test/hyeyukim/lexer_test.c test/hyeyukim/lexer_test.h
	$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@
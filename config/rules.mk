# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile_rules.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:45:44 by hyeyukim          #+#    #+#              #
#    Updated: 2023/01/07 23:57:25 by hyeyun           ###   ########.fr        #
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

$(OBJ_DIR)/$(TEST_HYE_DIR)/%.o : $(TEST_HYE_DIR)/%.c $(TEST_HYE_DIR)/test.h
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/test
	@mkdir -p $(OBJ_DIR)/$(TEST_HYE_DIR)
	$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@
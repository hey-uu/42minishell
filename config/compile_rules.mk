# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile_rules.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:45:44 by hyeyukim          #+#    #+#              #
#    Updated: 2023/01/05 11:45:46 by hyeyukim         ###   ########.fr        #
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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    rules.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:45:44 by hyeyukim          #+#    #+#              #
#    Updated: 2023/01/18 17:42:24 by yeonhkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# mandatory
$(MAN_OBJ_PATH)/$(BUILTIN_DIR)/%.o : $(MAN_SRC_PATH)/$(BUILTIN_DIR)/%.c $(MAN_INC)
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(BUILTIN_DIR)
	@$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(EXECUTOR_DIR)/%.o : $(MAN_SRC_PATH)/$(EXECUTOR_DIR)/%.c $(MAN_INC)
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(EXECUTOR_DIR)
	@$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(EXTRA_DIR)/%.o : $(MAN_SRC_PATH)/$(EXTRA_DIR)/%.c $(MAN_INC)
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(EXTRA_DIR)
	@$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(LEXER_DIR)/%.o : $(MAN_SRC_PATH)/$(LEXER_DIR)/%.c $(MAN_INC)
	mkdir -p $(MAN_OBJ_PATH)
	mkdir -p $(MAN_OBJ_PATH)/$(LEXER_DIR)
	$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(PARSER_DIR)/%.o : $(MAN_SRC_PATH)/$(PARSER_DIR)/%.c $(MAN_INC)
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(PARSER_DIR)
	@$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(TREE_DIR)/%.o : $(MAN_SRC_PATH)/$(TREE_DIR)/%.c $(MAN_INC)
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(TREE_DIR)
	@$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(ENV_DIR)/%.o : $(MAN_SRC_PATH)/$(ENV_DIR)/%.c $(MAN_INC)
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(ENV_DIR)
	@$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(EXPAND_DIR)/%.o : $(MAN_SRC_PATH)/$(EXPAND_DIR)/%.c $(MAN_INC)
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(EXPAND_DIR)
	@$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(HEREDOC_DIR)/%.o : $(MAN_SRC_PATH)/$(HEREDOC_DIR)/%.c $(MAN_INC)
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(HEREDOC_DIR)
	@$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/%.o : $(MAN_SRC_PATH)/%.c $(MAN_INC)
	@mkdir -p $(MAN_OBJ_PATH)
	@$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

# bonus
$(BON_OBJ_PATH)/$(BUILTIN_DIR)/%.o : $(BON_SRC_PATH)/$(BUILTIN_DIR)/%.c $(BON_INC)
	@mkdir -p $(BON_OBJ_PATH)
	@mkdir -p $(BON_OBJ_PATH)/$(BUILTIN_DIR)
	@$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(BON_OBJ_PATH)/$(EXECUTOR_DIR)/%.o : $(BON_SRC_PATH)/$(EXECUTOR_DIR)/%.c $(BON_INC)
	@mkdir -p $(BON_OBJ_PATH)
	@mkdir -p $(BON_OBJ_PATH)/$(EXECUTOR_DIR)
	@$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(BON_OBJ_PATH)/$(EXTRA_DIR)/%.o : $(BON_SRC_PATH)/$(EXTRA_DIR)/%.c $(BON_INC)
	@mkdir -p $(BON_OBJ_PATH)
	@mkdir -p $(BON_OBJ_PATH)/$(EXTRA_DIR)
	@$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(BON_OBJ_PATH)/$(LEXER_DIR)/%.o : $(BON_SRC_PATH)/$(LEXER_DIR)/%.c $(BON_INC)
	@mkdir -p $(BON_OBJ_PATH)
	@mkdir -p $(BON_OBJ_PATH)/$(LEXER_DIR)
	@$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(BON_OBJ_PATH)/$(PARSER_DIR)/%.o : $(BON_SRC_PATH)/$(PARSER_DIR)/%.c $(BON_INC)
	@mkdir -p $(BON_OBJ_PATH)
	@mkdir -p $(BON_OBJ_PATH)/$(PARSER_DIR)
	@$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(BON_OBJ_PATH)/$(TREE_DIR)/%.o : $(BON_SRC_PATH)/$(TREE_DIR)/%.c $(BON_INC)
	@mkdir -p $(BON_OBJ_PATH)
	@mkdir -p $(BON_OBJ_PATH)/$(TREE_DIR)
	@$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(BON_OBJ_PATH)/%.o : $(BON_SRC_PATH)/%.c $(BON_INC)
	@mkdir -p $(BON_OBJ_PATH)
	@$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

# test
$(MODULE_OBJ_PATH)/%.o : $(MODULE_PATH)/%.c
	mkdir -p $(MODULE_OBJ_PATH)
	$(CC) -c $(CFLAGS) $< $(MODULE_INC_FLAG) -o $@

$(TEST_OBJ_PATH)/%.o : $(TEST_PATH)/%.c $(TEST_INC)
	mkdir -p $(TEST_OBJ_PATH)
	$(CC) -c $(CFLAGS) $< $(TEST_INC_FLAG) -o $@

# library
$(LIBADT) :
	make -C $(LIBADT_PATH)

$(LIBFT) :
	make -C $(LIBFT_PATH)
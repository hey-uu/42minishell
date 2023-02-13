
# **************************** dependency rules ****************************** #

ifeq ($(MAKECMDGOALS), fclean)
else ifeq ($(MAKECMDGOALS), clean)
else ifeq ($(MAKECMDGOALS), bonus)
	-include $(BON_DEP)
else
	-include $(MAN_DEP)
endif

# ****************************** compile rules ******************************* #

# mandatory
$(MAN_OBJ_PATH)/$(BUILTIN_DIR)/%.o : $(MAN_SRC_PATH)/$(BUILTIN_DIR)/%.c
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(BUILTIN_DIR)
	$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(EXECUTOR_DIR)/%.o : $(MAN_SRC_PATH)/$(EXECUTOR_DIR)/%.c
	@mkdir -p $(MAN_OBJ_PATH)F$(LIBADT)
	@mkdir -p $(MAN_OBJ_PATH)/$(EXECUTOR_DIR)
	$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(EXTRA_DIR)/%.o : $(MAN_SRC_PATH)/$(EXTRA_DIR)/%.c
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(EXTRA_DIR)
	$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(LEXER_DIR)/%.o : $(MAN_SRC_PATH)/$(LEXER_DIR)/%.c
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(LEXER_DIR)
	$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(PARSER_DIR)/%.o : $(MAN_SRC_PATH)/$(PARSER_DIR)/%.c
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(PARSER_DIR)
	$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(TREE_DIR)/%.o : $(MAN_SRC_PATH)/$(TREE_DIR)/%.c
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(TREE_DIR)
	$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(MANAGER_DIR)/$(ENV_MANAGER_DIR)/%.o : $(MAN_SRC_PATH)/$(MANAGER_DIR)/$(ENV_MANAGER_DIR)/%.c
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(MANAGER_DIR)
	@mkdir -p $(MAN_OBJ_PATH)/$(MANAGER_DIR)/$(ENV_MANAGER_DIR)
	$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(MANAGER_DIR)/$(EXIT_MANAGER_DIR)/%.o : $(MAN_SRC_PATH)/$(MANAGER_DIR)/$(EXIT_MANAGER_DIR)/%.c
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(MANAGER_DIR)
	@mkdir -p $(MAN_OBJ_PATH)/$(MANAGER_DIR)/$(EXIT_MANAGER_DIR)
	$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(MANAGER_DIR)/$(HEREDOC_MANAGER_DIR)/%.o : $(MAN_SRC_PATH)/$(MANAGER_DIR)/$(HEREDOC_MANAGER_DIR)/%.c
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(MANAGER_DIR)
	@mkdir -p $(MAN_OBJ_PATH)/$(MANAGER_DIR)/$(HEREDOC_MANAGER_DIR)
	$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(EXPAND_DIR)/%.o : $(MAN_SRC_PATH)/$(EXPAND_DIR)/%.c
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(EXPAND_DIR)
	$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(HEREDOC_DIR)/%.o : $(MAN_SRC_PATH)/$(HEREDOC_DIR)/%.c
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(HEREDOC_DIR)
	$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(MAN_OBJ_PATH)/$(WRAPPED_DIR)/%.o : $(MAN_SRC_PATH)/$(WRAPPED_DIR)/%.c
	@mkdir -p $(MAN_OBJ_PATH)
	@mkdir -p $(MAN_OBJ_PATH)/$(WRAPPED_DIR)
	$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@


$(MAN_OBJ_PATH)/%.o : $(MAN_SRC_PATH)/%.c
	@mkdir -p $(MAN_OBJ_PATH)
	$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

# bonus
$(BON_OBJ_PATH)/$(BUILTIN_DIR)/%.o : $(BON_SRC_PATH)/$(BUILTIN_DIR)/%.c
	@mkdir -p $(BON_OBJ_PATH)
	@mkdir -p $(BON_OBJ_PATH)/$(BUILTIN_DIR)
	$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(BON_OBJ_PATH)/$(EXECUTOR_DIR)/%.o : $(BON_SRC_PATH)/$(EXECUTOR_DIR)/%.c
	@mkdir -p $(BON_OBJ_PATH)F$(LIBADT)
	@mkdir -p $(BON_OBJ_PATH)/$(EXECUTOR_DIR)
	$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(BON_OBJ_PATH)/$(EXTRA_DIR)/%.o : $(BON_SRC_PATH)/$(EXTRA_DIR)/%.c
	@mkdir -p $(BON_OBJ_PATH)
	@mkdir -p $(BON_OBJ_PATH)/$(EXTRA_DIR)
	$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(BON_OBJ_PATH)/$(LEXER_DIR)/%.o : $(BON_SRC_PATH)/$(LEXER_DIR)/%.c
	@mkdir -p $(BON_OBJ_PATH)
	@mkdir -p $(BON_OBJ_PATH)/$(LEXER_DIR)
	$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(BON_OBJ_PATH)/$(PARSER_DIR)/%.o : $(BON_SRC_PATH)/$(PARSER_DIR)/%.c
	@mkdir -p $(BON_OBJ_PATH)
	@mkdir -p $(BON_OBJ_PATH)/$(PARSER_DIR)
	$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(BON_OBJ_PATH)/$(TREE_DIR)/%.o : $(BON_SRC_PATH)/$(TREE_DIR)/%.c
	@mkdir -p $(BON_OBJ_PATH)
	@mkdir -p $(BON_OBJ_PATH)/$(TREE_DIR)
	$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(BON_OBJ_PATH)/$(MANAGER_DIR)/$(ENV_MANAGER_DIR)/%.o : $(BON_SRC_PATH)/$(MANAGER_DIR)/$(ENV_MANAGER_DIR)/%.c
	@mkdir -p $(BON_OBJ_PATH)
	@mkdir -p $(BON_OBJ_PATH)/$(MANAGER_DIR)
	@mkdir -p $(BON_OBJ_PATH)/$(MANAGER_DIR)/$(ENV_MANAGER_DIR)
	$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(BON_OBJ_PATH)/$(MANAGER_DIR)/$(EXIT_MANAGER_DIR)/%.o : $(BON_SRC_PATH)/$(MANAGER_DIR)/$(EXIT_MANAGER_DIR)/%.c
	@mkdir -p $(BON_OBJ_PATH)
	@mkdir -p $(BON_OBJ_PATH)/$(MANAGER_DIR)
	@mkdir -p $(BON_OBJ_PATH)/$(MANAGER_DIR)/$(EXIT_MANAGER_DIR)
	$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(BON_OBJ_PATH)/$(MANAGER_DIR)/$(HEREDOC_MANAGER_DIR)/%.o : $(BON_SRC_PATH)/$(MANAGER_DIR)/$(HEREDOC_MANAGER_DIR)/%.c
	@mkdir -p $(BON_OBJ_PATH)
	@mkdir -p $(BON_OBJ_PATH)/$(MANAGER_DIR)
	@mkdir -p $(BON_OBJ_PATH)/$(MANAGER_DIR)/$(HEREDOC_MANAGER_DIR)
	$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(BON_OBJ_PATH)/$(EXPAND_DIR)/%.o : $(BON_SRC_PATH)/$(EXPAND_DIR)/%.c
	@mkdir -p $(BON_OBJ_PATH)
	@mkdir -p $(BON_OBJ_PATH)/$(EXPAND_DIR)
	$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(BON_OBJ_PATH)/$(HEREDOC_DIR)/%.o : $(BON_SRC_PATH)/$(HEREDOC_DIR)/%.c
	@mkdir -p $(BON_OBJ_PATH)
	@mkdir -p $(BON_OBJ_PATH)/$(HEREDOC_DIR)
	$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(BON_OBJ_PATH)/$(WRAPPED_DIR)/%.o : $(BON_SRC_PATH)/$(WRAPPED_DIR)/%.c
	@mkdir -p $(BON_OBJ_PATH)
	@mkdir -p $(BON_OBJ_PATH)/$(WRAPPED_DIR)
	$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(BON_OBJ_PATH)/%.o : $(BON_SRC_PATH)/%.c
	@mkdir -p $(BON_OBJ_PATH)
	$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

# test
$(MODULE_OBJ_PATH)/%.o : $(MODULE_PATH)/%.c
	@mkdir -p $(MODULE_OBJ_PATH)
	$(CC) -c $(CFLAGS) $< $(MODULE_INC_FLAG) -o $@

$(TEST_OBJ_PATH)/%.o : $(TEST_PATH)/%.c
	@mkdir -p $(TEST_OBJ_PATH)
	$(CC) -c $(CFLAGS) $< $(TEST_INC_FLAG) -o $@

# library
$(LIBADT) :
	make -C $(LIBADT_PATH)

$(LIBFT) :
	make -C $(LIBFT_PATH)

$(LIBFTPRINTF) :
	make -C $(LIBFTPRINTF_PATH)


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    rules.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:45:44 by hyeyukim          #+#    #+#              #
#    Updated: 2023/01/10 17:10:48 by yeonhkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(MAN_OBJ_PATH)/%.o : $(MAN_SRC_PATH)/%.c $(MAN_INC)
	@mkdir -p $(MAN_OBJ_PATH)
	@$(CC) -c $(CFLAGS) $< $(MAN_INC_FLAG) -o $@

$(BON_OBJ_PATH)/%.o : $(BON_SRC_PATH)/%.c $(BON_INC)
	@mkdir -p $(BON_OBJ_PATH)
	@$(CC) -c $(CFLAGS) $< $(BON_INC_FLAG) -o $@

$(TEST_OBJ_PATH)/%.o : $(TEST_PATH)/%.c $(TEST_INC)
	@mkdir -p $(TEST_OBJ_PATH)
	$(CC) -c $(CFLAGS) $< $(TEST_INC_FLAG) -o $@

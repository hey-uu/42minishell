# ******************************** file names ******************************** #

MAIN_FILE				=		main \
								run_commands
BUILTIN_FILE			=		builtin_cd_utils \
								builtin_cd \
								builtin_pwd \
								builtin_echo \
								builtin_env \
								builtin_exit \
								builtin_export \
								builtin_unset
EXECUTOR_FILE			=		access_command \
								execute_builtin \
								execute_pipeline \
								execute_list \
								execute_simple_command \
								execute_subshell \
								executor \
								pipe_open_close \
								set_standard_stream \
								do_redirecting
EXTRA_FILE				=		handle_error \
								handle_signal \
								print_welcome \
								str_utils
LEXER_FILE				=		destroy_token_list \
								extract_token \
								get_token_type \
								length_of_token_str \
								lexer \
								lexer_utils
PARSER_FILE				=		parse_list \
								parse_pipeline \
								parse_simple_command \
								parse_subshell \
								parser \
								parser_utils
TREE_FILE				=		create_execute_unit \
								create_tree_node \
								destroy_tree \
								push_execute_unit_content
ENV_MANAGER_FILE			=		api_env_get \
								api_env_init \
								api_env_set \
								internal_env_get \
								internal_env_init \
								internal_env_set \
								manager_env
EXIT_MANAGER_FILE		=		api_exit_program \
								api_exit_stat_get \
								api_exit_stat_update \
								manager_exit_stat
HEREDOC_MANAGER_FILE		=		api_heredoc_utils \
								manager_heredoc
EXPAND_FILE				=		do_expansion \
								expand_word \
								field_split \
								get_next_file_name \
								get_pattern_feature \
								get_variable_name \
								match_wildcard_pattern \
								push_quoted_element \
								push_unquoted_element \
								push_words_to_strings \
								words_allocation \
								words_get \
								words_mask \
								words_push
HEREDOC_FILE			=		heredoc_generate \
								heredoc_get_delimiter \
								heredoc_with_expansion
WRAPPED_FILE			=		w_dir \
								w_dup \
								w_file \
								w_fork \
								w_read \
								w_wait \
								w_write \
								w_unlink
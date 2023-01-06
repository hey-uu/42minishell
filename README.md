# minishell

## manual
- POSIX SHELL
  https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html
- BASH MANUAL
  
### readline
- brew install readline
- 컴파일할 때 옵션 설정해줄 것 : -lreadline

### lexical analyzer
- token type
  - WORD
  - OPERATOR
    - BRACE_LEFT((), BRACE_RIGHT()), LOGICAL_AND(&&), LOGICAL_OR(||), 
      PIPELINE(|), RDIR_IN(<), RDIR_OUT(>), RDIR_HEREDOC(<<), RDIR_APPEND(>>)
- split 기준
  - 공백문자: space, tab, newline
  - metacharacter : "(", ")", "|", "||", "&&", "<", ">", "<<", ">>"
### syntax analyzere

### executor
- expansion
  - $VARIABLE
    - $?
    - $변수이름
  - \*
- quote removal
- redirection
- execute
  - cmd 실행시 가능한 에러
    - No such file or directory(/포함 && 존재하지 x)
    - Permission denied(/포함 && 존재 && 권한 x)
    - No such file or directory(/포함 && 존재 && 파일x)
    - command not found(/가 없음 && 존재하지 x)
  
>>>>>>> master

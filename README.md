<<<<<<< HEAD
# minishell
=======
# minishell

### readline

### lexical analyzer

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:04:52 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 09:58:10 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INTERNAL_H
# define LIBFT_INTERNAL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <sys/types.h>

/*------------ DEFINE MACRO CONSTANTS ------------*/

# ifndef FT_SIZE_MAX
#  define FT_SIZE_MAX 9223372036854775807
# endif

# ifndef FT_LONG_MAX
#  define FT_LONG_MAX 9223372036854775807L
# endif

enum e_libft_error
{
	NORMAL = 0,
	BADALLOC,
	OVERSIZE,
	BADENVP
};

enum e_bool
{
	TRUE = 1,
	FALSE = 0
};

/*------------- STRUCT DECLARATIONS --------------*/

typedef enum e_libft_error	t_libft_error;
typedef enum e_bool			t_bool;

/*-------------- FUNCTION PROTOTYPES -------------*/

// libft mandatory
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_isalpha(int c);
int		ft_abs(int x);
void	ft_putstr_fd(const char *s, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);

// memory allocation
void	*ft_malloc(size_t size_of);
void	ft_exit(const char *str, int error_status);

#endif
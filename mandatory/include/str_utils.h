/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:49:22 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/28 15:55:46 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_UTILS_H
# define STR_UTILS_H

/*-------------- FUNCTION PROTOTYPES -------------*/

char	*ft_strndup(char *str, int n);
void	free_str_array(char ***array);
char	*ft_str3join(char *s1, char *s2, char *s3);

#endif
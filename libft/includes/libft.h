/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:40:24 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/28 13:52:10 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void	ft_strdel(char **ap);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_chr(const char *s, const char c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memalloc(size_t size);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:09:12 by jomason           #+#    #+#             */
/*   Updated: 2026/02/06 11:17:58 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> //read
# include <stdlib.h> //malloc, free

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	    	*get_next_line(int fd);

/* utils */
size_t	  	ft_strlen(const char *s);
char	    	*ft_strchr(const char *s, int c);
char	    	*ft_strjoin(const char *s1, const char *s2);
char	  	  *ft_strdup(const char *s1);
size_t	  	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/* internal */
char		    *read_to_buffer(int fd, char *buffer, char *temp);
static char	*get_line_buffer(char *buffer);
static void	buffer_move(char *buffer);

#endif

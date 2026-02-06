/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:09:09 by jomason           #+#    #+#             */
/*   Updated: 2026/02/06 11:22:05 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line_buffer(char *buffer)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static void	buffer_move(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i] != '\0')
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}

static char	*read_to_buffer(int fd, char *buffer, char *temp)
{
	char	buffer_read[BUFFER_SIZE + 1];
	char	*temp_old;
	int		read_bytes;

	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(temp, '\n'))
	{
		read_bytes = read(fd, buffer_read, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(temp), buffer[0] = '\0', NULL);
		if (read_bytes == 0)
			break ;
		buffer_read[read_bytes] = '\0';
		temp_old = temp;
		temp = ft_strjoin(temp_old, buffer_read);
		free(temp_old);
		if (!temp)
			return (NULL);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (buffer[0] = '\0', NULL);
	if (ft_strchr(buffer, '\n'))
		return (line = get_line_buffer(buffer), buffer_move(buffer), line);
	temp = ft_strdup(buffer);
	if (!temp)
		return (NULL);
	buffer[0] = '\0';
	temp = read_to_buffer(fd, buffer, temp);
	if (!temp)
		return (NULL);
	line = get_line_buffer(temp);
	if (line && temp[0])
		ft_strlcpy(buffer, temp + ft_strlen(line), BUFFER_SIZE + 1);
	free(temp);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main()
// {
	// 	int	fd;
	// 	char *line;

	// 	fd = open("test.txt", O_RDONLY);
	// 	if (fd < 0)
	// 		return (printf("I can't read o.o\n"), (fd < 0));
	// 	line = get_next_line(fd);
	// 	if (line != NULL) //if instead of while
	// 	{
		// 		printf("%s", line);
		// 		free(line);
		// 		// line = get_next_line(fd);
		// 	}
		// 	close(fd);
// 	return (0);
// }
// // the gist:
// // BUFFER_SIZE is about how much you read, not how many files exist.
// // Using it to index file descriptors is a category error.

// // hidden dragon: multi-fd read, if that case 
// // then static char *stash[BUFFER_SIZE + 1] is better.
// // Bc each fd is appending to the same stash which
// // will will lead to mixed buffers and
// // lines cross-contaminate.
// // fd1 = open("a.txt", O_RDONLY);
// // fd2 = open("b.txt", O_RDONLY);
// // get_next_line(fd1);
// // get_next_line(fd2);
// // get_next_line(fd1);
// // get_next_line(fd2)
// //
// // The deep conceptual reason:
// // static char *stash; is a state machine buffer.
// // static char *stash[BUFFER_SIZE + 1]; is:
// // a fake fd-indexed cache with incorrect bounds.
// // They are solving different problems.
// // Real solution is static char *stash[OPEN_MAX];
// // #include <limits.h>

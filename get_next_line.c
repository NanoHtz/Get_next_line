/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:03:52 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/09/20 14:04:21 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*bff;
	int		bytes;

	bff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, bff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(bff);
			free(str);
			return (NULL);
		}
		bff[bytes] = '\0';
		str = ft_strjoin(str, bff);
	}
	free(bff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*ln;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (0);
	ln = ft_line(str);
	str = ft_nextstr(str);
	return (ln);
}

/*
int main(int argc, char **argv)
{
    int fd;
    char *line;

	printf("\nPrueba 1: ***************************************42_no_nl***************************************\n\n");
	fd = open("tests/41_no_nl.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);

	printf("\n\nPrueba 2: ***************************************41_with_nl***************************************\n\n");
    fd = open("tests/41_with_nl.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);

	printf("\n\nPrueba 3: ***************************************42_no_nl***************************************\n\n");
	fd = open("tests/42_no_nl.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);

	printf("\n\nPrueba 4: ***************************************42_with_nl***************************************\n\n");
    fd = open("tests/42_with_nl.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);

	printf("\n\nPrueba 5: ***************************************43_no_nl***************************************\n\n");
	fd = open("tests/43_no_nl.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);

	printf("\n\nPrueba 6: ***************************************43_with_nl***************************************\n\n");
    fd = open("tests/43_with_nl.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);

	printf("\n\nPrueba 7: ***************************************alternate_line_nl_no_nl***************************************\n\n");
	fd = open("tests/42_no_nl.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);

    printf("\n\nPrueba 8: ***************************************alternate_line_nl_with_nl***************************************\n\n");
	fd = open("tests/alternate_line_nl_with_nl.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);

	printf("\n\nPrueba 9: ***************************************big_line_no_nl***************************************\n\n");
	fd = open("tests/big_line_no_nl.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);

	printf("\n\nPrueba 10: ***************************************big_line_with_nl***************************************\n\n");
    fd = open("tests/big_line_with_nl.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);

	printf("\n\nPrueba 11: ***************************************empty***************************************\n\n");
	fd = open("tests/empty.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);

	printf("\n\nPrueba 12: ***************************************lorem***************************************\n\n");
    fd = open("tests/lorem.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);

	printf("\n\nPrueba 13: ***************************************multiple_line_no_nl***************************************\n\n");
	fd = open("tests/multiple_line_no_nl.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);

	printf("\n\nPrueba 14: ***************************************multiple_line_with_nl***************************************\n\n");
    fd = open("tests/multiple_line_with_nl.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);

	printf("\n\nPrueba 15: ***************************************multiple_nlx5***************************************\n\n");
	fd = open("tests/multiple_nlx5.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);

	printf("\n\nPrueba 16: ***************************************nl***************************************\n\n");
	fd = open("tests/nl.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
}
*/

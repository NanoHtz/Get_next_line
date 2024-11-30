/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:04:03 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/30 19:27:13 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_read_and_accumulate(int fd, char *str);
char	*get_line(char *str);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *org_str, char *bff);
char	*prepare_next_call(char *str);

/*Get_next_line: Se comprueba primero que el fd y el buffer son correctos
Guardamos en la estática str el resultado de la función read_and_acu
Si no se ha realizado bien, salta error, extrae la linea con get_line y prepara la siguiente llamada

Read and acumulate: Empieza por asignar memoria al buffer establecido + el caracter nulo
Con el nulo nos ahorramos problemas de acceder a memoria no establecida
Haciendo que las funciones con strjoin funcionen bien, con bites = 1
nos aseguramos que el bucle avance, ya que solo sera 0 si read llega al final
del archivo.
Necesitamos de ft_strchr para encontrar el salto de linea, si lo encuentra pero al hacer read bytes da distinto de 0
entonces significa un \n dentro del archivo, lee esos datos y los guarda en buffer con \0 y en str, con strjoin
en str es donde se van guardando todos las llamadas a la funcion y las va liberando.

get_line: Esta funcion busca extraer una linea completa de nuestro str
En esa gran concatenacion anterior, protege, asegurandose
de que almenos ha entrado un elemento, despues la recorre toda
para asegurarse de escoger el tamaño adecuado en la reserva de memoria
despues añade toda la linea y al final añade el salto de linea
y el nulo

prepare the recall: Esta funcion, encuentra y devuelve un puntero al inicio de la siguiente linea
Pasa por el primer salto de linea que encuentre, si entra una cadena vacia, libera str
En caso de encontrarlo reserva memoria para todo lo restante de str, menos lo encontrado antes, despues copia en esa reserva
toda la cadena restante

Deberes: Mover la carpeta tests, copiar la explicacion y el main a otro archivo para poder meterlo luego en la correción
Al subir comprobar qyue no se ha subido nada que no se deba, pasar la norminete y el main una última vez
Ademas probar el tester, asegurarse de que sabes hacer un main.

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
}*/

#endif

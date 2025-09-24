<!-- ===================== BANNER ===================== -->
<p align="center">
  <img src="https://raw.githubusercontent.com/NanoHtz/Assets/main/get_next_line/banner.svg" alt="get_next_line banner">
</p>

<p align="center"><i>📄 get_next_line  — Lectura línea a línea desde un file descriptor con buffer configurable y stash estático.</i></p>

<p align="center">
  <img src="https://raw.githubusercontent.com/NanoHtz/Assets/main/100.png" alt="gnl nota" height="120">
</p>

## Índice
- [Resumen](#resumen)
- [¿Para qué?](#para-que)
- [Explicación](#explicacion)
- [Compilación](#descarga)
- [Pruebas](#pruebas)

---
<a id="resumen"></a>
## ✅ Resumen del proyecto<br>

**get_next_line** implementa una función:
```c
char *get_next_line(int fd);
```

que devuelve la siguiente línea leída de un file descriptor fd, incluyendo el salto de línea ('\n') si existe, o NULL en EOF o error.
La función usa un BUFFER_SIZE y mantiene un stash para conservar restos entre llamadas.

> Este proyecto sigue la **Norma oficial de 42** para estilo en C (Norminette).
> En todos los proyectos de 42, el uso de la gran mayoria de bibliotecas esta prohibido, siendo nuestro propio desarrollo libft el sustituto de las funciones básicas. 
> - Código legible.  
> - Funciones pequeñas (<25 líneas),
> - 4 parámetros por función,
> - Nombres claros en `snake_case` y en inglés.
> - 1 responsabilidad por función.
>  - Variables declaradas al inicio del bloque(maximo 4 por función). 
<a id="para-que"></a>
## 🧩 ¿Para qué?

¿Qué se aprende?

- Lectura incremental con read y buffers.

- Gestión de memoria dinámica: concatenaciones, recortes, fugas y free en error/EOF.

- Guardar memoria entre llamadas, para poder recordar en que punto estabamos.

<a id="explicacion"></a>
<summary><h3> 📝 Explicación </h3></summary>

🔁 get_next_line

- Devuelve un char * nuevo con la siguiente línea (incluye \n si la línea lo tenía).

- Devuelve NULL en EOF y si no quedan restos, o un error (por ejemplo read == -1).

- La función que llama a get_next_line es la responsable de hacer el free(), de esto no se encarga get_next_line.

🧠 Idea clave : acumulador

Se mantiene un acumulador con lo leído hasta el momento que aún no se ha devuelto.

Bucle:

Va recorriendo todas las lineas hasta \n o hasta llenar el buffer, dependiendo cual sea mas limitante.

Segun el tamaño del buffer en realcion a la linea leida, guarda o imprime una linea.

¿Hay \n en el acumulador?

- Sí → cortar hasta \n y devuelve esa línea; guardar el resto.

- No → lee con read(fd, buf, BUFFER_SIZE) hasta cumplir con el tamaño del buffer y concatenar al acumulador.

- Si read == 0 (EOF) y el acumulador no está vacío, devolver lo que quede (sin \n).

- Si read == 0 y acumulador vacío → NULL (fin real).

- Si read == -1 → error: liberar stash de ese fd y NULL.


<a id="descarga"></a>
## ✅ Descarga y compilacion <br>

⬇️ Descarga

```bash
git clone https://github.com/NanoHtz/get_next_line.git
```

🧪 BUFFER_SIZE

El BUFFER_SIZE se define en la compilacion.

```bash
make BUFFER_SIZE=42
# o
gcc -D BUFFER_SIZE=42 -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -I include -o demo
```

🏗️ Compilacion

```bash
make
make clean   # elimina .o
make fclean  # elimina .o y la librería/objetos finales
make re      # recompila desde cero
```
<a id="pruebas"></a>
🏗️ Pruebas
<br>
Uno de los verdaderos objetivos de este proyecto es la gestión de memoria, es indispensable que utilices y te familiarices con herramientas que te ayuden a comprobar los leaks o fugas de memoria, Valgrind o sanitizer son fundamentales.
<br>
Recomiendo mucho este tester para la realizacion de pruebas de funcionamiento:
<br>
https://github.com/Tripouille/gnlTester

<!-- ===================== BANNER ===================== -->
<p align="center">
  <img src="https://raw.githubusercontent.com/NanoHtz/Assets/main/get_next_line/banner.svg" alt="get_next_line banner">
</p>

<p align="center"><i>📄 get_next_line (42 Cursus) — Lectura línea a línea desde un file descriptor con `read(2)`, buffer configurable y stash estático. Bonus: soporte multi-FD.</i></p>

---

## Índice
- [Resumen](#resumen)
- [¿Para qué?](#para-que)
- [Explicación](#explicacion)
- [Compilación](#compilacion)
- [Uso](#uso)
- [Salida esperada y pruebas](#salida)

---
<a id="resumen"></a>
## ✅ Resumen del proyecto<br>

**get_next_line** implementa una función:
```c
char *get_next_line(int fd);
que devuelve la siguiente línea leída de un file descriptor fd, incluyendo el salto de línea ('\n') si existe, o NULL en EOF o error.
La función usa un BUFFER_SIZE y mantiene un stash para conservar restos entre llamadas.
```

<a id="para-que"></a>
## 🧩 ¿Para qué?

¿Qué se aprende?

Lectura incremental con read y buffers.

Gestión de memoria dinámica: concatenaciones, recortes, fugas y free en error/EOF.

Estados persistentes entre llamadas (stash estático).

<a id="explicacion"></a>
<details> <summary><h3> ## 📝 Explicación </h3></summary>

🔁 Contrato de get_next_line

Entrada: fd válido, BUFFER_SIZE > 0.

Salida:

Devuelve un char * nuevo con la siguiente línea (incluye \n si la línea lo tenía).

Devuelve NULL en EOF y si no quedan restos, o en error (por ejemplo read == -1).

Propiedad de memoria: el caller debe hacer free() de cada línea devuelta.

🧠 Idea clave (stash)

Se mantiene un stash (acumulador) con lo leído hasta el momento que aún no se ha devuelto.

Bucle:

¿Hay \n en el stash?

Sí → cortar hasta \n y devolver esa línea; guardar el resto.

No → leer con read(fd, buf, BUFFER_SIZE) y concatenar al stash.

Si read == 0 (EOF) y el stash no está vacío, devolver lo que quede (sin \n).

Si read == 0 y stash vacío → NULL (fin real).

Si read == -1 → error: liberar stash de ese fd y NULL.

</details>

<a id="para-que"></a>
## 🧩 ¿Para qué?

```bash
git clone https://github.com/NanoHtz/get_next_line.git
```


```bash
make
make clean   # elimina .o
make fclean  # elimina .o y la librería/objetos finales
make re      # recompila desde cero
```
🧪

El BUFFER_SIZE se define en la compilacion.
```bash
make BUFFER_SIZE=42
# o
gcc -D BUFFER_SIZE=42 -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -I include -o demo

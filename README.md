# Exercise-CPP

## Resumen

Repositorio con ejercicios de C++ organizados por modulos (`CPPM00`, `CPPM01`, etc.). Cada carpeta suele contener uno o varios ejercicios (`ex00`, `ex01`, ...) junto con su `Makefile` y, en algunos modulos, el PDF del enunciado.

## Contenido

### Que hay en este repositorio

- Ejercicios con codigo desde `CPPM00` hasta `CPPM09`; `CPPM07/ex02` aun tiene pendientes de gestion de memoria y asignacion.
- Enunciados PDF en varios modulos.
- `CPPM08` con `easyfind`, `Span` y `MutantStack` implementados y probados.
- `CPPM09` con Bitcoin Exchange (`ex00`) y RPN (`ex01`) implementados y documentados; `ex02` pendiente.
- Una guia explicativa en [`GUIA_EJERCICIOS.md`](GUIA_EJERCICIOS.md).

### Estructura general

- `CPPM00`: primeros ejercicios de consola, clases basicas y objetos con estado compartido.
- `CPPM01`: memoria dinamica, punteros, referencias, archivos y despacho de comportamiento.
- `CPPM02`: en este repositorio, `ex00` a `ex02` repiten ejercicios de `CPPM00`; `ex03` trabaja geometria y punto fijo.
- `CPPM03`: herencia basica con la familia `ClapTrap`.
- `CPPM04`: polimorfismo, clases abstractas y copia profunda.
- `CPPM05`: excepciones, formularios y patron de factoria simple.
- `CPPM06`: conversion de literales escalares, serializacion de punteros e identificacion de tipos en tiempo de ejecucion.
- `CPPM07`: plantillas de funciones (`swap`, `min`, `max`, `iter`) y clase plantilla `Array<T>` con acceso comprobado y definiciones en `.tpp`.
- `CPPM08`: contenedores STL, busqueda con `std::find`, distancias entre enteros y pilas con iteradores.
- `CPPM09`: mapas para consultar precios historicos y pilas para evaluar expresiones en notacion polaca inversa.

### Como usarlo

En cada ejercicio que tenga `Makefile`, entra en su carpeta y compila:

```bash
cd CPPM08/ex02
make
./ex02
```

El ejemplo ejecuta las pruebas de `MutantStack`. Para otros ejercicios, utiliza el nombre de binario indicado en su documento. En `CPPM08`, `make clean` elimina objetos y dependencias, `make fclean` elimina tambien el ejecutable y `make re` recompila desde cero.

## Referencias

La explicacion de que se aprende en cada carpeta resuelta esta en [`GUIA_EJERCICIOS.md`](GUIA_EJERCICIOS.md).

Todos los documentos siguen la estructura `Resumen`, `Contenido` y `Referencias`. Cada ejercicio se presenta con explicacion poco tecnica, explicacion mas tecnica, archivos de consulta, compilacion y ejecucion, y que observar; se conservan notas de estado cuando existen pendientes.

Cada modulo dispone de su propio documento con explicaciones, archivos de consulta y ejemplos de uso:

- [CPPM00info.md](CPPM00/CPPM00info.md)
- [CPPM01info.md](CPPM01/CPPM01info.md)
- [CPPM02info.md](CPPM02/CPPM02info.md)
- [CPPM03info.md](CPPM03/CPPM03info.md)
- [CPPM04info.md](CPPM04/CPPM04info.md)
- [CPPM05info.md](CPPM05/CPPM05info.md)
- [CPPM06info.md](CPPM06/CPPM06info.md)
- [CPPM07info.md](CPPM07/CPPM07info.md)
- [CPPM08info.md](CPPM08/CPPM08info.md)
- [CPPM09info.md](CPPM09/CPPM09info.md)

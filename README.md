# Exercise-CPP

Repositorio con ejercicios de C++ organizados por modulos (`CPPM00`, `CPPM01`, etc.). Cada carpeta suele contener uno o varios ejercicios (`ex00`, `ex01`, ...) junto con su `Makefile` y, en algunos modulos, el PDF del enunciado.

## Que hay en este repositorio

- Ejercicios implementados desde `CPPM00` hasta `CPPM06`.
- Enunciados PDF en varios modulos.
- `CPPM07`, `CPPM08` y `CPPM09` con el enunciado, pero sin implementacion visible.
- Una guia explicativa en [`GUIA_EJERCICIOS.md`](/home/carlo/VSCodeGit/Exercise-CPP/GUIA_EJERCICIOS.md).

## Estructura general

- `CPPM00`: primeros ejercicios de consola, clases basicas y objetos con estado compartido.
- `CPPM01`: memoria dinamica, punteros, referencias, archivos y despacho de comportamiento.
- `CPPM02`: en este repositorio, `ex00` a `ex02` repiten ejercicios de `CPPM00`; `ex03` trabaja geometria y punto fijo.
- `CPPM03`: herencia basica con la familia `ClapTrap`.
- `CPPM04`: polimorfismo, clases abstractas y copia profunda.
- `CPPM05`: excepciones, formularios y patron de factoria simple.
- `CPPM06`: conversion de literales escalares.

## Como usarlo

En cada ejercicio que tenga `Makefile`, entra en su carpeta y compila:

```bash
cd CPPM01/ex04
make
```

Despues ejecuta el binario que genere ese ejercicio segun su propio `Makefile`.

## Documentacion

La explicacion de que se aprende en cada carpeta resuelta esta en [`GUIA_EJERCICIOS.md`](/home/carlo/VSCodeGit/Exercise-CPP/GUIA_EJERCICIOS.md).

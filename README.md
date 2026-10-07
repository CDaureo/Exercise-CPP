# Exercise-CPP

Repositorio con ejercicios de C++ organizados por modulos (`CPPM00`, `CPPM01`, etc.). Cada carpeta suele contener uno o varios ejercicios (`ex00`, `ex01`, ...) junto con su `Makefile` y, en algunos modulos, el PDF del enunciado.

## Que hay en este repositorio

- Ejercicios con codigo desde `CPPM00` hasta `CPPM07`; `CPPM07/ex02` aun tiene pendientes de gestion de memoria y asignacion.
- Enunciados PDF en varios modulos.
- `CPPM08` y `CPPM09` con el enunciado, pero sin implementacion visible.
- Una guia explicativa en [`GUIA_EJERCICIOS.md`](GUIA_EJERCICIOS.md).

## Estructura general

- `CPPM00`: primeros ejercicios de consola, clases basicas y objetos con estado compartido.
- `CPPM01`: memoria dinamica, punteros, referencias, archivos y despacho de comportamiento.
- `CPPM02`: en este repositorio, `ex00` a `ex02` repiten ejercicios de `CPPM00`; `ex03` trabaja geometria y punto fijo.
- `CPPM03`: herencia basica con la familia `ClapTrap`.
- `CPPM04`: polimorfismo, clases abstractas y copia profunda.
- `CPPM05`: excepciones, formularios y patron de factoria simple.
- `CPPM06`: conversion de literales escalares, serializacion de punteros e identificacion de tipos en tiempo de ejecucion.
- `CPPM07`: plantillas de funciones (`swap`, `min`, `max`, `iter`) y clase plantilla `Array<T>` con acceso comprobado y definiciones en `.tpp`.

## Como usarlo

En cada ejercicio que tenga `Makefile`, entra en su carpeta y compila:

```bash
cd CPPM01/ex04
make
```

Despues ejecuta el binario que genere ese ejercicio segun su propio `Makefile`.

## Documentacion

La explicacion de que se aprende en cada carpeta resuelta esta en [`GUIA_EJERCICIOS.md`](GUIA_EJERCICIOS.md).

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

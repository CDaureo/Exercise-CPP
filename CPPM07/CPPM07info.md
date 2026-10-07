# CPPM07 - Documentacion de ejercicios

[Volver a la guia general](../GUIA_EJERCICIOS.md)

El modulo trabaja plantillas de funciones y clases. Contiene el [enunciado](07.subject.pdf) y los ejercicios `ex00`, `ex01` y `ex02`, todos con Makefile. Los tres ejemplos actuales compilan con C++98 y `-Wall -Wextra -Werror`; `ex02` aun tiene pendientes descritos abajo.

Los comandos siguientes parten de la raiz del repositorio y se ejecutan por separado. Cada Makefile ofrece `all`, `clean`, `fclean` y `re`.

### [`ex00`](ex00/) - Funciones plantilla

Explicacion poco tecnica:
Se escriben funciones que sirven para varios tipos de datos sin repetir el mismo algoritmo. El ejemplo intercambia y compara tanto enteros como cadenas.

Explicacion mas tecnica:
`whatever.hpp` define las plantillas `swap`, `min` y `max`. `swap` recibe referencias modificables; `min` y `max` reciben y devuelven referencias constantes. En caso de igualdad, ambas devuelven el segundo argumento. El tipo utilizado debe soportar las operaciones que ejecuta cada funcion. El `main` usa `::` para seleccionar las funciones del espacio global.

Archivos de consulta: [whatever.hpp](ex00/whatever.hpp), [main.cpp](ex00/main.cpp), [Makefile](ex00/Makefile).

Compilacion y ejecucion:

```bash
cd CPPM07/ex00
make
./whatever
```

Que observar:
Tras intercambiar los enteros, `a` vale `3` y `b` vale `2`; el minimo es `2` y el maximo `3`. Las cadenas quedan como `chaine2` y `chaine1`, con minimo `chaine1` y maximo `chaine2`.

### [`ex01`](ex01/) - iter

Explicacion poco tecnica:
Una misma funcion recorre un array y aplica una accion a cada elemento: mostrarlo, incrementarlo o modificar sus campos.

Explicacion mas tecnica:
`iter(A* array, const std::size_t len, F f)` recibe un puntero, una longitud y una funcion cuyo tipo tambien es un parametro de plantilla. Permite trabajar con elementos modificables y constantes, segun el array y la funcion recibidos. El `main` comprueba enteros, decimales, cadenas, arrays constantes, una estructura `Point`, longitud cero y recorridos parciales mediante salida por consola y `assert`. Quien llama debe proporcionar una longitud que no exceda el array disponible.

Archivos de consulta: [iter.hpp](ex01/iter.hpp), [main.cpp](ex01/main.cpp), [Makefile](ex01/Makefile).

Compilacion y ejecucion:

```bash
cd CPPM07/ex01
make
./iter
```

Que observar:
Los enteros pasan de `1 2 3` a `2 3 4`, las cadenas a `Hola! Mundo!` y los puntos a `(2, 4) (4, 6)`. Las comprobaciones terminan con `Todas las pruebas han pasado.`. Los arrays constantes se recorren para lectura.

### [`ex02`](ex02/) - Array

Explicacion poco tecnica:
Se construye un array cuyo tipo de elementos se elige al usarlo, por ejemplo `Array<int>`. Guarda su numero de elementos y detecta los accesos fuera de sus limites.

Explicacion mas tecnica:
`Array.hpp` declara la clase y al final incluye `Array.tpp`, donde se definen los metodos de la plantilla. El constructor por defecto crea un array vacio; el constructor con tamano reserva exactamente `num` elementos mediante `new T[num]()` y los inicializa por valor. El constructor de copia reserva almacenamiento propio y copia los elementos. Las dos versiones de `operator[]` devuelven `T&` o `const T&` y lanzan `std::exception` si `index >= _size`. `size() const` consulta el tamano sin modificar el objeto. El Makefile contempla `.hpp` y `.tpp` como dependencias; el `.tpp` se incluye, no se compila por separado.

Estado actual:
El ejemplo compila, imprime `42` y `3`, y captura la excepcion al acceder al indice `3` de un array de tres elementos. El destructor esta definido pero vacio: falta liberar `_data` con `delete[]`. El operador de asignacion esta declarado pero no definido; falta implementar la copia independiente tambien para la asignacion. El `main` actual no prueba la copia, la asignacion, el array vacio ni el acceso constante.

Archivos de consulta: [Array.hpp](ex02/Array.hpp), [Array.tpp](ex02/Array.tpp), [main.cpp](ex02/main.cpp), [Makefile](ex02/Makefile).

Compilacion y ejecucion:

```bash
cd CPPM07/ex02
make
./array
```

Que observar:
En el entorno comprobado, el ejemplo muestra:

```text
42
3
Indice fuera de rango: std::exception
```

Los indices validos son `0`, `1` y `2`. La excepcion se lanza antes de acceder a memoria fuera del array; el `catch` del `main` imprime el prefijo y `e.what()`. El texto concreto de `what()` depende de la implementacion de la biblioteca.

Sobre el archivo `.tpp`:
La extension es una convencion para separar las definiciones de una plantilla de sus declaraciones. El compilador necesita ver esas definiciones al instanciar tipos como `Array<int>`, por eso `Array.hpp` incluye `Array.tpp` antes del `#endif`. Cambiar el `.tpp` provoca que el Makefile recompile `main.cpp`.

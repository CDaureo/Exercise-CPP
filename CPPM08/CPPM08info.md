# CPPM08 - Documentacion de ejercicios

## Resumen

El modulo trabaja contenedores, iteradores y algoritmos de la STL. Contiene el [enunciado](08.subject.pdf) y los ejercicios `ex00`, `ex01` y `ex02`, todos implementados con Makefile y compatibles con C++98 y `-Wall -Wextra -Werror`.

Los comandos siguientes parten de la raiz del repositorio y se ejecutan por separado. Cada Makefile ofrece `all`, `clean`, `fclean` y `re`, genera dependencias de cabeceras y evita reenlazar si no hay cambios. Las clases siguen la forma canonica; las definiciones en cabeceras o `.tpp` corresponden a plantillas. Los mensajes se escriben en la salida estandar y terminan con salto de linea.

## Contenido

### [`ex00`](ex00/) - easyfind

Explicacion poco tecnica:
Se busca un numero dentro de un grupo de enteros. La misma funcion sirve para distintos contenedores, sin escribir una busqueda diferente para cada uno.

Explicacion mas tecnica:
`easyfind(T& container, int n)` utiliza `std::find` sobre el intervalo `[begin(), end())`. Devuelve un `T::iterator` a la primera coincidencia y lanza `std::runtime_error` si no encuentra el numero, tambien cuando el contenedor esta vacio. La busqueda es lineal. La plantilla se define en `easyfind.hpp` para que pueda instanciarse desde otros archivos; incluye sus dependencias y esta protegida contra doble inclusion. Esta version recibe contenedores modificables y no ofrece una sobrecarga para contenedores constantes.

Archivos de consulta: [easyfind.hpp](ex00/easyfind.hpp), [main.cpp](ex00/main.cpp), [Makefile](ex00/Makefile).

Compilacion y ejecucion:

```bash
cd CPPM08/ex00
make
./easyfind
```

Que observar:
El ejemplo busca `89` en una `std::list<int>` y muestra:

```text
Numero encontrado: 89
```

El `main` entregado demuestra una busqueda correcta. Durante la comprobacion tambien se probaron `std::vector`, duplicados, un valor ausente y un contenedor vacio; esas comprobaciones auxiliares no forman parte de este `main`.

### [`ex01`](ex01/) - Span

Explicacion poco tecnica:
Se guardan hasta N enteros y se calcula la distancia mas pequena y la mas grande entre dos de ellos. Tambien se puede insertar un grupo completo mediante iteradores.

Explicacion mas tecnica:
`Span(unsigned int n)` fija la capacidad y almacena los valores en un `std::vector<int>`. El constructor por defecto crea una capacidad cero; constructor de copia, asignacion y destructor completan la forma canonica. `addNumber(int)` lanza `std::length_error` cuando la capacidad esta agotada. La sobrecarga plantilla `addNumber(first, last)` acepta un rango valido `[first, last)`, incluidos iteradores de entrada, y prepara los valores en un vector temporal: si no caben, el Span conserva su contenido anterior. Un rango vacio no anade elementos.

`shortestSpan() const` ordena una copia con `std::sort` y compara vecinos, con coste O(n log n), sin alterar el orden almacenado. `longestSpan() const` resta el minimo al maximo, obtenidos con `std::min_element` y `std::max_element`, con coste O(n). Ambas devuelven `unsigned int`, convierten los operandos antes de restar para manejar `INT_MIN` e `INT_MAX` sin desbordamiento con signo, y lanzan `std::logic_error` si hay menos de dos numeros. Los duplicados producen una distancia minima cero.

Archivos de consulta: [Span.hpp](ex01/Span.hpp), [Span.cpp](ex01/Span.cpp), [main.cpp](ex01/main.cpp), [Makefile](ex01/Makefile).

Compilacion y ejecucion:

```bash
cd CPPM08/ex01
make
./ex01
```

Que observar:

```text
2
14
Todas las pruebas superadas (incluidos 20000 numeros).
```

El `main` comprueba el ejemplo, capacidad cero, Span vacio o con un solo elemento, capacidad agotada, duplicados, negativos, extremos de `int`, rangos vacios o demasiado grandes, iteradores de entrada desde un flujo, copias independientes y autoasignacion. Inserta 20.000 numeros desde una lista y verifica distancia minima `3` y maxima `59997`. Un fallo imprime su mensaje y devuelve codigo de salida `1`.

### [`ex02`](ex02/) - MutantStack (Mutated abomination)

Explicacion poco tecnica:
Una pila permite consultar y retirar el ultimo elemento anadido. Este ejercicio mantiene ese comportamiento y permite recorrer todos los elementos sin tener que sacarlos de la pila.

Explicacion mas tecnica:
`MutantStack<T, Container>` hereda publicamente de `std::stack<T, Container>` y usa `std::deque<T>` como contenedor predeterminado. Conserva funciones como `push`, `pop`, `top`, `size` y `empty`. Expone los iteradores del contenedor protegido `c`: `begin()` y `end()` recorren desde la base hasta la cima; `rbegin()` y `rend()` lo hacen en sentido inverso. Hay versiones modificables y constantes, con los tipos `iterator`, `const_iterator`, `reverse_iterator` y `const_reverse_iterator`. Las reglas de invalidacion de iteradores dependen del contenedor subyacente.

La forma canonica copia el estado de la clase base. Existe ademas un constructor desde un contenedor compatible. Las declaraciones estan en `MutantStack.hpp` y las definiciones de plantilla en `MutantStack.tpp`, incluido desde la cabecera; el `.tpp` no se compila por separado. La herencia permite construir un `std::stack<int>` a partir de un `MutantStack<int>`.

Archivos de consulta: [MutantStack.hpp](ex02/MutantStack.hpp), [MutantStack.tpp](ex02/MutantStack.tpp), [main.cpp](ex02/main.cpp), [Makefile](ex02/Makefile).

Compilacion y ejecucion:

```bash
cd CPPM08/ex02
make
./ex02
```

Que observar:

```text
17
1
5
3
5
737
0
Todas las pruebas de MutantStack superadas.
```

El `main` compara la salida del ejemplo con la de una `std::list` que recibe las mismas operaciones. Tambien verifica pila vacia, modificacion por iteradores, recorridos constantes e inversos, orden LIFO, copia a `std::stack`, copias independientes con cadenas, autoasignacion, contenedores `list` y `vector`, y un recorrido de 20.000 elementos. Usa algoritmos STL como `std::equal` y `std::find`. Un fallo imprime su mensaje y devuelve codigo de salida `1`.

## Referencias

[Volver a la guia general](../GUIA_EJERCICIOS.md) · [README](../README.md)

# CPPM08 - Documentacion de ejercicios

## Resumen

El modulo trabaja contenedores, iteradores y algoritmos de la STL. Contiene el [enunciado](08.subject.pdf) y los ejercicios `ex00`, `ex01` y `ex02`, todos implementados con Makefile y compatibles con C++98 y `-Wall -Wextra -Werror`.

Los comandos siguientes parten de la raiz del repositorio y se ejecutan por separado. Cada Makefile ofrece `all`, `clean`, `fclean` y `re`, genera dependencias de cabeceras y evita reenlazar si no hay cambios. Las clases siguen la forma canonica; las definiciones en cabeceras o `.tpp` corresponden a plantillas. Los mensajes se escriben en la salida estandar y terminan con salto de linea.

## Contenido

### [`ex00`](ex00/) - easyfind

Explicacion poco tecnica:
Se busca un numero dentro de un grupo de enteros. La misma funcion sirve para distintos contenedores, sin escribir una busqueda diferente para cada uno.

Explicacion mas tecnica:
`easyfind(T& container, int n)` utiliza `std::find` sobre el intervalo `[begin(), end())`. Devuelve un `T::iterator` a la primera coincidencia y lanza `std::runtime_error` si no encuentra el numero, tambien cuando el contenedor esta vacio. La busqueda es lineal. La plantilla se define en `easyfind.hpp` para que pueda instanciarse desde otros archivos; incluye sus dependencias y esta protegida contra doble inclusion. La sobrecarga para contenedores constantes devuelve un `T::const_iterator`.

Archivos de consulta: [easyfind.hpp](ex00/easyfind.hpp), [main.cpp](ex00/main.cpp), [Makefile](ex00/Makefile).

Compilacion y ejecucion:

```bash
cd CPPM08/ex00
make
./easyfind
```

Que observar:
El ejemplo busca `88` en una `std::list<int>` y muestra:

```text
Numero encontrado: 88
```

El `main` comprueba la primera coincidencia entre duplicados, la busqueda en un `std::vector` constante y las excepciones para un valor ausente y un contenedor vacio.

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

El `main` muestra las distancias `2` y `14` del ejemplo del enunciado y comprueba la excepcion al insertar en un Span lleno. Luego anade 20.000 enteros mediante iteradores de un vector y muestra las distancias `1` y `19999`.

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
Ejemplo del enunciado
Cima tras insertar 5 y 17 = 17
Elementos tras quitar el 17 = 1
Recorrido de la base a la cima = 5 3 5 737 0
El recorrido coincide con std::list.
deque OK (recorrido 10 20 30, cima tras pop = 20)
vector OK (recorrido 10 20 30, cima tras pop = 20)
list OK (recorrido 10 20 30, cima tras pop = 20)
Todas las pruebas de MutantStack.
```

El `main` compara los resultados del ejemplo con los de una `std::list` que recibe las mismas operaciones. Tambien verifica pila vacia, modificacion por iteradores, recorridos constantes e inversos, orden LIFO, copia a `std::stack`, copias independientes con cadenas, y autoasignacion. Ejecuta la misma prueba de insercion, recorrido y extraccion con `std::deque`, `std::vector` y `std::list`. Usa algoritmos STL como `std::equal` y `std::find`. Un fallo imprime su mensaje y devuelve codigo de salida `1`.

## Referencias

[Volver a la guia general](../GUIA_EJERCICIOS.md) · [README](../README.md)

# CPPM04 - Documentacion de ejercicios

[Volver a la guia general](../GUIA_EJERCICIOS.md)

Este documento describe el codigo presente en el modulo. Los ejemplos de terminal parten de la raiz del repositorio y se ejecutan por separado. Los Makefiles usan C++98 y las opciones `-Wall -Wextra -Werror`.

### [`ex00`](ex00/) - Animal, Dog, Cat

Explicacion poco tecnica:
Este ejercicio ensena que varios objetos pueden responder de forma distinta al mismo mensaje. Todos son animales, pero cada uno suena diferente.

Explicacion mas tecnica:
Se organiza una jerarquia con una clase base `Animal` y derivadas `Dog` y `Cat`. En esta implementacion concreta, `makeSound` no aparece virtual en la cabecera, asi que tambien sirve para entender la diferencia entre tener una interfaz comun y tener polimorfismo real.

Archivos de consulta: [Animal.cpp](ex00/Animal.cpp), [Animal.hpp](ex00/Animal.hpp), [Cat.cpp](ex00/Cat.cpp), [Cat.hpp](ex00/Cat.hpp), [Dog.cpp](ex00/Dog.cpp), [Dog.hpp](ex00/Dog.hpp), [main.cpp](ex00/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM04/ex00
make
./animals
```

Que observar:
El `main` llama directamente a los objetos concretos. La cabecera actual no declara virtuales ni `makeSound` ni el destructor; esta version no demuestra despacho dinamico a traves de `Animal*`.

### [`ex01`](ex01/) - Brain y copia profunda

Explicacion poco tecnica:
Aqui se da un paso importante: algunos objetos contienen recursos propios internos, y copiar el objeto mal puede provocar que dos animales compartan la misma "cabeza" sin querer.

Explicacion mas tecnica:
`Dog` y `Cat` almacenan un `Brain` reservado dinamicamente. Por eso implementan constructor de copia, operador de asignacion y destructor para hacer copia profunda y liberar memoria correctamente. Es una aplicacion practica de la regla de tres.

Archivos de consulta: [Animal.cpp](ex01/Animal.cpp), [Animal.hpp](ex01/Animal.hpp), [Brain.cpp](ex01/Brain.cpp), [Brain.hpp](ex01/Brain.hpp), [Cat.cpp](ex01/Cat.cpp), [Cat.hpp](ex01/Cat.hpp), [Dog.cpp](ex01/Dog.cpp), [Dog.hpp](ex01/Dog.hpp), [main.cpp](ex01/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM04/ex01
make
./animals
```

Que observar:
El `main` crea un array de animales y prueba copias de Dog y Cat. Cambiar una idea en la copia debe dejar intacta la del original.

### [`ex02`](ex02/) - Animal abstracto

Explicacion poco tecnica:
La clase base deja de representar un animal "real" y pasa a ser una idea general. Ya no se crea un `Animal` generico; solo animales concretos.

Explicacion mas tecnica:
`Animal` declara `makeSound()` como funcion virtual pura, convirtiendose en clase abstracta. Esto obliga a las derivadas a implementar el comportamiento y permite polimorfismo correcto con destructor virtual.

Archivos de consulta: [Animal.cpp](ex02/Animal.cpp), [Animal.hpp](ex02/Animal.hpp), [Brain.cpp](ex02/Brain.cpp), [Brain.hpp](ex02/Brain.hpp), [Cat.cpp](ex02/Cat.cpp), [Cat.hpp](ex02/Cat.hpp), [Dog.cpp](ex02/Dog.cpp), [Dog.hpp](ex02/Dog.hpp), [main.cpp](ex02/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM04/ex02
make
./animals
```

Que observar:
El `main` mantiene las pruebas de copia y polimorfismo. La construccion de un Animal generico aparece comentada porque la clase es abstracta.

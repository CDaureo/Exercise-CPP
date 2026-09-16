# CPPM02 - Documentacion de ejercicios

[Volver a la guia general](../GUIA_EJERCICIOS.md)

Este documento describe el codigo presente en el modulo. Los ejemplos de terminal parten de la raiz del repositorio y se ejecutan por separado. Los Makefiles usan C++98 y las opciones `-Wall -Wextra -Werror`.

En esta carpeta, `ex00`, `ex01` y `ex02` repiten ejercicios de CPPM00. La documentacion refleja ese contenido; `ex03` trabaja punto fijo y geometria.

### [`ex00`](ex00/) - Megaphone duplicado

Explicacion poco tecnica:
En esta carpeta hay otro ejercicio de transformacion de texto por consola, igual en concepto al `Megaphone` anterior.

Explicacion mas tecnica:
El codigo vuelve a trabajar con argumentos de linea de comandos y conversion a mayusculas caracter a caracter.

Archivos de consulta: [megaphone.cpp](ex00/megaphone.cpp).

Compilacion y ejecucion:

```bash
cd CPPM02/ex00
make
./megaphone "hola mundo"
```

Que observar:
Este contenido repite Megaphone de CPPM00/ex00.

### [`ex01`](ex01/) - PhoneBook duplicado

Explicacion poco tecnica:
Aqui aparece otra vez la agenda de contactos, por lo que vuelve a reforzar la idea de separar datos y logica del programa.

Explicacion mas tecnica:
Repite el uso de clases, capacidad fija, entrada por consola y salida tabulada.

Archivos de consulta: [Contact.cpp](ex01/Contact.cpp), [Contact.hpp](ex01/Contact.hpp), [Main.cpp](ex01/Main.cpp), [PhoneBook.cpp](ex01/PhoneBook.cpp), [PhoneBook.hpp](ex01/PhoneBook.hpp).

Compilacion y ejecucion:

```bash
cd CPPM02/ex01
make
./phonebook
```

Que observar:
Este contenido repite PhoneBook de CPPM00/ex01.

### [`ex02`](ex02/) - Account duplicado

Explicacion poco tecnica:
De nuevo se trabaja el seguimiento individual y global de varias cuentas.

Explicacion mas tecnica:
Repite el uso de miembros `static`, operaciones de deposito y retirada, y el mantenimiento de estadisticas compartidas por todos los objetos.

Archivos de consulta: [Account.cpp](ex02/Account.cpp), [Account.hpp](ex02/Account.hpp), [tests.cpp](ex02/tests.cpp).

Compilacion y ejecucion:

```bash
cd CPPM02/ex02
make
./Account
```

Que observar:
Este contenido repite Account de CPPM00/ex02.

### [`ex03`](ex03/) - BSP / Point / Fixed

Explicacion poco tecnica:
Este es el ejercicio que mas claramente cambia de tema: se empieza a trabajar con numeros y posiciones en un plano. La pregunta central es si un punto cae dentro o fuera de un triangulo.

Explicacion mas tecnica:
Se implementa un tipo `Fixed` para representar valores con precision fija y una clase `Point` con coordenadas inmutables. La funcion `bsp` usa signos de areas o productos cruzados para comprobar si un punto esta estrictamente dentro del triangulo, excluyendo bordes y vertices.

Archivos de consulta: [Fixed.cpp](ex03/Fixed.cpp), [Fixed.hpp](ex03/Fixed.hpp), [Point.cpp](ex03/Point.cpp), [Point.hpp](ex03/Point.hpp), [bsp.cpp](ex03/bsp.cpp), [main.cpp](ex03/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM02/ex03
make
./bsp
```

Que observar:
El `main` comprueba varios puntos respecto a un triangulo. Un punto sobre un borde o vertice debe quedar fuera; `1` representa interior y `0`, exterior.

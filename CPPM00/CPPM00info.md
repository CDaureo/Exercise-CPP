# CPPM00 - Documentacion de ejercicios

## Resumen

Este documento describe el codigo presente en el modulo. Los ejemplos de terminal parten de la raiz del repositorio y se ejecutan por separado. Los Makefiles usan C++98 y las opciones `-Wall -Wextra -Werror`.

## Contenido

### [`ex00`](ex00/) - Megaphone

Explicacion poco tecnica:
Este ejercicio sirve para empezar a tratar un programa como una herramienta de consola. El usuario le pasa palabras al ejecutarlo y el programa las devuelve en mayusculas. Es una primera toma de contacto con leer argumentos y responder por pantalla.

Explicacion mas tecnica:
Se trabaja con `argc` y `argv`, se recorre cada argumento recibido y cada caracter se transforma con `std::toupper`. Tambien introduce `std::cout`, `std::endl` y el flujo basico de ejecucion de un `main`.

Archivos de consulta: [megaphone.cpp](ex00/megaphone.cpp).

Compilacion y ejecucion:

```bash
cd CPPM00/ex00
make
./megaphone "hola mundo"
```

Que observar:
Prueba argumentos con espacios y una ejecucion sin argumentos para observar el mensaje por defecto.

### [`ex01`](ex01/) - PhoneBook

Explicacion poco tecnica:
Aqui se construye una agenda sencilla. El objetivo no es solo guardar datos, sino aprender a organizar un pequeno programa en varias piezas: una para los contactos y otra para la agenda.

Explicacion mas tecnica:
Se usan clases (`Contact` y `PhoneBook`), encapsulacion con getters y setters, lectura segura con `std::getline`, formateo de salida con `iomanip` y una estructura de capacidad fija que va sobrescribiendo contactos antiguos cuando se llena.

Archivos de consulta: [Contact.cpp](ex01/Contact.cpp), [Contact.hpp](ex01/Contact.hpp), [Main.cpp](ex01/Main.cpp), [PhoneBook.cpp](ex01/PhoneBook.cpp), [PhoneBook.hpp](ex01/PhoneBook.hpp).

Compilacion y ejecucion:

```bash
cd CPPM00/ex01
make
./phonebook
```

Que observar:
Usa `ADD`, `SEARCH` y `EXIT`. Anade mas de ocho contactos para observar la sustitucion de los mas antiguos y busca un indice inexistente.

### [`ex02`](ex02/) - Account

Explicacion poco tecnica:
Este ejercicio muestra como varios objetos pueden compartir informacion comun. Cada cuenta bancaria tiene sus propios datos, pero al mismo tiempo el sistema lleva un resumen global de todas las cuentas.

Explicacion mas tecnica:
Se emplean atributos y metodos `static` para contar cuentas, total de dinero, depositos y retiradas. Tambien se practica el ciclo de vida de los objetos, la separacion entre estado individual y estado global, y el registro temporal con marcas de tiempo.

Archivos de consulta: [Account.cpp](ex02/Account.cpp), [Account.hpp](ex02/Account.hpp), [tests.cpp](ex02/tests.cpp).

Compilacion y ejecucion:

```bash
cd CPPM00/ex02
make
./Account
```

Que observar:
El programa ejecuta los casos de `tests.cpp`. Observa los totales compartidos, las retiradas rechazadas y las marcas de tiempo.

## Referencias

[Volver a la guia general](../GUIA_EJERCICIOS.md) · [README](../README.md)

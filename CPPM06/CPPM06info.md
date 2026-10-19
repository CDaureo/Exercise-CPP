# CPPM06 - Documentacion de ejercicios

## Resumen

Este documento describe el codigo presente en el modulo. Los ejemplos de terminal parten de la raiz del repositorio y se ejecutan por separado. Los Makefiles usan C++98 y las opciones `-Wall -Wextra -Werror`.

## Contenido

### [`ex00`](ex00/) - ScalarConverter

Explicacion poco tecnica:
El objetivo es tomar un dato escrito como texto y averiguar de que tipo parece ser, para despues mostrarlo en varios formatos distintos. Es una forma muy clara de aprender conversiones.

Explicacion mas tecnica:
`ScalarConverter` es una clase utilitaria con solo metodos estaticos. Intenta interpretar el literal como `char`, `int`, `float` o `double`, valida errores de parseo y rangos con `strtol`, `strtod`, `errno` y limites numericos, y despues muestra las conversiones posibles. El manejo de pseudoliterales esta incompleto: `nanf`, `+inff` y `-inff` se rechazan, y algunos casts a `int` de las funciones de salida requieren revisar los limites antes de convertir.

Archivos de consulta: [ScalarConverter.cpp](ex00/ScalarConverter.cpp), [ScalarConverter.hpp](ex00/ScalarConverter.hpp), [main.cpp](ex00/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM06/ex00
make
./scalar_converter 42
```

Que observar:
Prueba tambien `a`, `42.0f`, `3.14` y un texto invalido. La logica de parseo y conversion esta en `main.cpp`; `ScalarConverter.cpp` contiene los miembros de construccion, copia y destruccion. La implementacion rechaza `nanf` y los infinitos con sufijo `f`; el tratamiento de pseudoliterales y los casts a `int` fuera de rango necesitan revision.

### [`ex01`](ex01/) - Serialization

Explicacion poco tecnica:
Aqui se trabaja una idea muy concreta: convertir una direccion de memoria en un numero y luego recuperar esa misma direccion desde ese numero. No se copian los datos; solo se transforma el puntero para entender mejor como representar direcciones.

Explicacion mas tecnica:
`Serialization` se ha planteado como clase utilitaria con metodos estaticos `serialize` y `deserialize`, usando `reinterpret_cast` para convertir entre `Data*` y `uintptr_t`. La estructura `Data` no esta vacia y contiene al menos un `int` y un `std::string`, lo suficiente para cumplir el enunciado. En `main.cpp` hay una prueba muy simple que crea un objeto `Data`, lo serializa, lo deserializa y comprueba por salida que el puntero restaurado coincide con el original y que los campos siguen siendo accesibles. El ejercicio ya tiene tambien un `Makefile` minimo para compilar `main.cpp`, `Serialization.cpp` y `Data.cpp`.

Archivos de consulta: [Data.cpp](ex01/Data.cpp), [Data.hpp](ex01/Data.hpp), [Serialization.cpp](ex01/Serialization.cpp), [Serialization.hpp](ex01/Serialization.hpp), [main.cpp](ex01/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM06/ex01
make
./serialization
```

Que observar:
La salida debe incluir `Same pointer:   1` y los datos `42, test`. El entero representa una direccion del proceso: el objeto original debe seguir vivo al recuperar y usar el puntero; no es un formato de almacenamiento de sus campos.

### [`ex02`](ex02/) - Identify real type

Explicacion poco tecnica:
El programa crea al azar un objeto de tipo `A`, `B` o `C` y lo entrega como un puntero a su clase base. Despues averigua que objeto se creo realmente, primero mediante un puntero y despues mediante una referencia.

Explicacion mas tecnica:
`Base` tiene un destructor virtual y las clases `A`, `B` y `C` heredan publicamente de ella. `generate()` usa `rand() % 3` y `new` para devolver una de las tres derivadas. Las dos sobrecargas de `identify` usan `dynamic_cast`: con punteros, una conversion fallida devuelve un puntero nulo; con referencias, lanza una excepcion que el codigo captura con `catch (...)` antes de probar el siguiente tipo. No se usa `typeid`. El `main` inicializa la semilla con la hora, identifica el mismo objeto de ambas formas y libera la memoria con `delete` a traves de `Base*`.

Estado actual:
La carpeta contiene `Base.hpp`, `Base.cpp` y `main.cpp`, pero todavia no tiene `Makefile`. La documentacion del modulo incluye un comando de compilacion manual. Cada ejecucion debe imprimir dos veces la misma letra (`A`, `B` o `C`); no tiene por que cambiar entre ejecuciones.

Archivos de consulta: [Base.cpp](ex02/Base.cpp), [Base.hpp](ex02/Base.hpp), [main.cpp](ex02/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM06/ex02
c++ -Wall -Wextra -Werror -std=c++98 -include cstdlib main.cpp Base.cpp -o identify
./identify
```

Que observar:
Ambas llamadas a `identify` deben imprimir la misma letra. El cast de puntero imprime `NOTHING` si no encuentra A, B o C; la version de referencia termina sin imprimir si fallan los tres casts.

El comando incluye `cstdlib` explicitamente porque `main.cpp` usa `srand` sin incluir su cabecera directamente. La carpeta aun no dispone de Makefile.

## Referencias

[Volver a la guia general](../GUIA_EJERCICIOS.md) · [README](../README.md)

# CPPM01 - Documentacion de ejercicios

## Resumen

Este documento describe el codigo presente en el modulo. Los ejemplos de terminal parten de la raiz del repositorio y se ejecutan por separado. Los Makefiles usan C++98 y las opciones `-Wall -Wextra -Werror`.

## Contenido

### [`ex00`](ex00/) - Zombie

Explicacion poco tecnica:
La idea principal es entender que un objeto puede crearse y desaparecer de distintas maneras. No todos los objetos viven lo mismo ni se destruyen igual.

Explicacion mas tecnica:
Se introduce la diferencia entre reserva dinamica con `new` y liberacion con `delete`, junto con funciones auxiliares que crean objetos y los hacen anunciarse. El ejercicio refuerza el papel del constructor, destructor y el riesgo de fugas de memoria.

Archivos de consulta: [Zombie.cpp](ex00/Zombie.cpp), [Zombie.hpp](ex00/Zombie.hpp), [main.cpp](ex00/main.cpp), [newZombie.cpp](ex00/newZombie.cpp), [randomChump.cpp](ex00/randomChump.cpp).

Compilacion y ejecucion:

```bash
cd CPPM01/ex00
make
./zombie
```

Que observar:
Observa cuando se anuncia cada zombie y cuando se llama a su destructor; la reserva con `new` necesita su correspondiente `delete`.

### [`ex01`](ex01/) - Zombie Horde

Explicacion poco tecnica:
Ya no se crea un solo objeto, sino muchos del mismo tipo de una vez. Eso enseña a pensar en grupos de objetos y en como tratarlos de forma uniforme.

Explicacion mas tecnica:
Se reserva un array dinamico con `new[]`, se inicializa cada elemento en un bucle y luego se libera con `delete[]`. La leccion importante es que la forma de liberar memoria debe coincidir con la forma en que se reservo.

Archivos de consulta: [Zombie.cpp](ex01/Zombie.cpp), [Zombie.hpp](ex01/Zombie.hpp), [ZombieHorde.cpp](ex01/ZombieHorde.cpp), [main.cpp](ex01/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM01/ex01
make
./zombie
```

Que observar:
Comprueba que cada zombie de la horda se anuncia y que al liberar el array se ejecutan sus destructores.

### [`ex02`](ex02/) - Pointers and References

Explicacion poco tecnica:
Este ejercicio aclara una duda muy comun: no es lo mismo tener una variable, tener una direccion hacia ella o tener otro nombre para la misma variable.

Explicacion mas tecnica:
Se compara una `std::string`, un puntero a esa cadena y una referencia a la misma. El programa imprime direcciones y valores para mostrar que el puntero guarda una direccion y necesita desreferenciarse, mientras que la referencia actua como un alias directo.

Archivos de consulta: [main.cpp](ex02/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM01/ex02
make
./ex02
```

Que observar:
Las direcciones de la cadena y de su referencia coinciden con la direccion almacenada en el puntero; los tres accesos muestran el mismo texto.

### [`ex03`](ex03/) - Weapon / HumanA / HumanB

Explicacion poco tecnica:
Aqui se ve como varios objetos pueden estar relacionados entre si. Un personaje usa un arma, y cuando el arma cambia, el comportamiento del personaje cambia tambien.

Explicacion mas tecnica:
Se practica la diferencia entre guardar una referencia (`HumanA`) y guardar un puntero (`HumanB`). `HumanA` necesita arma desde el principio; `HumanB` puede existir sin ella y recibirla despues. Esto ensena dependencias obligatorias frente a opcionales.

Archivos de consulta: [HumanA.cpp](ex03/HumanA.cpp), [HumanA.hpp](ex03/HumanA.hpp), [HumanB.cpp](ex03/HumanB.cpp), [HumanB.hpp](ex03/HumanB.hpp), [Weapon.cpp](ex03/Weapon.cpp), [Weapon.hpp](ex03/Weapon.hpp), [main.cpp](ex03/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM01/ex03
make
./ex03
```

Que observar:
El `main` cambia el tipo del arma despues de crear los personajes. Observa que los ataques reflejan ese cambio.

### [`ex04`](ex04/) - Replacer

Explicacion poco tecnica:
El programa toma un archivo y crea otro cambiando un texto por otro. Es un ejercicio muy util para entender programas que procesan informacion de entrada y generan un resultado nuevo.

Explicacion mas tecnica:
Se usa lectura de archivos con `std::ifstream`, escritura con `std::ofstream`, acumulacion en `std::ostringstream` y reemplazo manual con `std::string::find` y `substr`. Tambien incluye validacion de errores mediante excepciones.

Archivos de consulta: [Replacer.cpp](ex04/Replacer.cpp), [Replacer.hpp](ex04/Replacer.hpp), [main.cpp](ex04/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM01/ex04
make
./replacer entrada.txt hola adios
```

Que observar:
Crea antes un archivo `entrada.txt` con el texto `hola`. El ejemplo genera `entrada.txt.replace`; revisa su contenido. Tambien puedes probar una ruta inexistente.

### [`ex05`](ex05/) - Harl

Explicacion poco tecnica:
Este ejercicio ensena a decidir una accion segun una palabra clave. Es como montar un pequeno menu interno dentro de una clase.

Explicacion mas tecnica:
La clase `Harl` asocia niveles de texto con metodos miembros concretos. Para ello usa un array de cadenas y un array de punteros a funciones miembro, lo que permite despachar comportamiento sin una cadena larga de `if` independientes.

Archivos de consulta: [Harl.cpp](ex05/Harl.cpp), [Harl.hpp](ex05/Harl.hpp), [main.cpp](ex05/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM01/ex05
make
./harl DEBUG
```

Que observar:
Prueba `DEBUG`, `INFO`, `WARNING` y `ERROR`: cada argumento selecciona un unico metodo.

### [`ex06`](ex06/) - Harl Filter

Explicacion poco tecnica:
Es una evolucion del ejercicio anterior: no solo eliges un mensaje, sino que a partir de cierto nivel se muestran varios, como un filtro por severidad.

Explicacion mas tecnica:
Se reutiliza el mapeo entre nivel y funcion, pero ahora se combina con un `switch` y `fallthrough` para ejecutar el nivel pedido y todos los superiores. Eso ensena una forma compacta de expresar comportamiento acumulativo.

Archivos de consulta: [Harl.cpp](ex06/Harl.cpp), [Harl.hpp](ex06/Harl.hpp), [main.cpp](ex06/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM01/ex06
make
./harlFilter WARNING
```

Que observar:
Con `WARNING` se muestran `WARNING` y `ERROR`. Con `DEBUG` se muestran todos los niveles; una palabra desconocida produce un mensaje de nivel no reconocido.

## Referencias

[Volver a la guia general](../GUIA_EJERCICIOS.md) · [README](../README.md)

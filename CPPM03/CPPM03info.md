# CPPM03 - Documentacion de ejercicios

## Resumen

Este documento describe el codigo presente en el modulo. Los ejemplos de terminal parten de la raiz del repositorio y se ejecutan por separado. Los Makefiles usan C++98 y las opciones `-Wall -Wextra -Werror`.

## Contenido

### [`ex00`](ex00/) - ClapTrap

Explicacion poco tecnica:
Aqui se crea un personaje simple con vida, energia y acciones. Es un paso natural para aprender a modelar entidades con estado y comportamiento.

Explicacion mas tecnica:
La clase `ClapTrap` encapsula atributos privados y metodos como `attack`, `takeDamage` y `beRepaired`. El ejercicio trabaja constructores, copia, asignacion y las reglas que impiden actuar cuando no queda vida o energia.

Archivos de consulta: [ClapTrap.cpp](ex00/ClapTrap.cpp), [ClapTrap.hpp](ex00/ClapTrap.hpp), [main.cpp](ex00/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM03/ex00
make
./claptrap
```

Que observar:
El `main` agota la energia y reduce la vida a cero. Observa cuando dejan de permitirse ataques y reparaciones.

### [`ex01`](ex01/) - ScavTrap

Explicacion poco tecnica:
Ahora aparece un personaje mas especializado que hereda lo basico del anterior y anade su propia identidad. La leccion es reutilizar en vez de empezar desde cero.

Explicacion mas tecnica:
Se introduce herencia publica con `ScavTrap : public ClapTrap`, redefinicion de `attack` y un metodo propio (`guardGate`). Tambien ayuda a observar el orden de construccion y destruccion entre clase base y derivada.

Archivos de consulta: [ClapTrap.cpp](ex01/ClapTrap.cpp), [ClapTrap.hpp](ex01/ClapTrap.hpp), [ScavTrap.cpp](ex01/ScavTrap.cpp), [ScavTrap.hpp](ex01/ScavTrap.hpp), [ScravTrap.cpp](ex01/ScravTrap.cpp), [main.cpp](ex01/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM03/ex01
make
./scavtrap
```

Que observar:
Observa la construccion de la base antes de la derivada y la destruccion en orden inverso, ademas de `guardGate()`.

### [`ex02`](ex02/) - FragTrap

Explicacion poco tecnica:
Se sigue ampliando la familia de personajes. Cada uno comparte una base comun, pero cambia sus valores y sus acciones especiales.

Explicacion mas tecnica:
`FragTrap` deriva de `ClapTrap`, ajusta sus estadisticas y agrega `highFivesGuys`. El ejercicio refuerza herencia, especializacion de comportamiento y reutilizacion de codigo de la clase base.

Archivos de consulta: [ClapTrap.cpp](ex02/ClapTrap.cpp), [ClapTrap.hpp](ex02/ClapTrap.hpp), [FragTrap.cpp](ex02/FragTrap.cpp), [FragTrap.hpp](ex02/FragTrap.hpp), [ScavTrap.cpp](ex02/ScavTrap.cpp), [ScavTrap.hpp](ex02/ScavTrap.hpp), [ScravTrap.cpp](ex02/ScravTrap.cpp), [main.cpp](ex02/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM03/ex02
make
./FragTrap
```

Que observar:
El `main` combina ClapTrap, ScavTrap y FragTrap. Observa las acciones especiales y las diferencias de estadisticas. El ejecutable del Makefile se llama `FragTrap`.

## Referencias

[Volver a la guia general](../GUIA_EJERCICIOS.md) · [README](../README.md)

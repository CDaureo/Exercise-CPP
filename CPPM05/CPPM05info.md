# CPPM05 - Documentacion de ejercicios

[Volver a la guia general](../GUIA_EJERCICIOS.md)

Este documento describe el codigo presente en el modulo. Los ejemplos de terminal parten de la raiz del repositorio y se ejecutan por separado. Los Makefiles usan C++98 y las opciones `-Wall -Wextra -Werror`.

### [`ex00`](ex00/) - Bureaucrat

Explicacion poco tecnica:
El foco esta en objetos que tienen reglas estrictas. Un burocrata no puede tener cualquier nivel: si se sale de los limites, el programa debe detectarlo.

Explicacion mas tecnica:
La clase `Bureaucrat` valida que `grade` este entre 1 y 150, y lanza excepciones especificas cuando se intenta construir o modificar el objeto fuera de ese rango. El ejercicio introduce control de errores con clases de excepcion propias.

Archivos de consulta: [Bureaucrat.cpp](ex00/Bureaucrat.cpp), [Bureaucrat.hpp](ex00/Bureaucrat.hpp), [main.cpp](ex00/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM05/ex00
make
./bureaucrat
```

Que observar:
El `main` prueba cambios de grado y construcciones con 0 y 151. El grado 1 es el de mayor autoridad y 150 el de menor.

### [`ex01`](ex01/) - Form

Explicacion poco tecnica:
Ahora ya no basta con que exista un burocrata: tambien hay formularios que pueden o no firmarse dependiendo del nivel de quien lo intenta.

Explicacion mas tecnica:
Se conecta `Bureaucrat` con `Form` mediante `beSigned`. El formulario mantiene estado de firma y dos requisitos numericos: uno para firmar y otro para ejecutar. Se refuerzan colaboracion entre clases, inmutabilidad parcial y propagacion de excepciones.

Archivos de consulta: [Bureaucrat.cpp](ex01/Bureaucrat.cpp), [Bureaucrat.hpp](ex01/Bureaucrat.hpp), [Form.cpp](ex01/Form.cpp), [Form.hpp](ex01/Form.hpp), [main.cpp](ex01/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM05/ex01
make
./bureaucrat
```

Que observar:
Bob no puede firmar Contract con grado 75; Alice si con grado 2. Alice tampoco alcanza el grado 1 de TopSecret.

### [`ex02`](ex02/) - AForm y formularios concretos

Explicacion poco tecnica:
El sistema se vuelve mas realista: distintos formularios hacen cosas distintas, aunque todos comparten la misma idea general de firmarse y ejecutarse.

Explicacion mas tecnica:
`AForm` pasa a ser una base abstracta y las clases derivadas implementan acciones concretas: escribir un arbol ASCII en un archivo, intentar una robotomizacion aleatoria o conceder un perdon presidencial. Se practica polimorfismo, validacion previa a la ejecucion y especializacion por herencia.

Archivos de consulta: [AForm.cpp](ex02/AForm.cpp), [AForm.hpp](ex02/AForm.hpp), [Bureaucrat.cpp](ex02/Bureaucrat.cpp), [Bureaucrat.hpp](ex02/Bureaucrat.hpp), [PresidentialPardonForm.cpp](ex02/PresidentialPardonForm.cpp), [PresidentialPardonForm.hpp](ex02/PresidentialPardonForm.hpp), [RobotomyRequestForm.cpp](ex02/RobotomyRequestForm.cpp), [RobotomyRequestForm.hpp](ex02/RobotomyRequestForm.hpp), [ShrubberyCreationForm.cpp](ex02/ShrubberyCreationForm.cpp), [ShrubberyCreationForm.hpp](ex02/ShrubberyCreationForm.hpp), [main.cpp](ex02/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM05/ex02
make
./bureaucrat
```

Que observar:
El `main` prueba ejecucion sin firma, grados insuficientes y acciones autorizadas. La creacion de arbustos escribe `garden_shrubbery` en el directorio de ejecucion; la robotomizacion es aleatoria.

### [`ex03`](ex03/) - Intern

Explicacion poco tecnica:
Este ejercicio ensena a crear objetos sin que el resto del programa tenga que saber exactamente que clase concreta necesita construir. Es una forma de centralizar la "fabricacion".

Explicacion mas tecnica:
La clase `Intern` actua como una factoria: recibe el nombre textual de un formulario y devuelve una instancia del tipo adecuado. Internamente usa una tabla que relaciona nombres con funciones creadoras, evitando muchos `if` dispersos.

Archivos de consulta: [AForm.cpp](ex03/AForm.cpp), [AForm.hpp](ex03/AForm.hpp), [Bureaucrat.cpp](ex03/Bureaucrat.cpp), [Bureaucrat.hpp](ex03/Bureaucrat.hpp), [Intern.cpp](ex03/Intern.cpp), [Intern.hpp](ex03/Intern.hpp), [PresidentialPardonForm.cpp](ex03/PresidentialPardonForm.cpp), [PresidentialPardonForm.hpp](ex03/PresidentialPardonForm.hpp), [RobotomyRequestForm.cpp](ex03/RobotomyRequestForm.cpp), [RobotomyRequestForm.hpp](ex03/RobotomyRequestForm.hpp), [ShrubberyCreationForm.cpp](ex03/ShrubberyCreationForm.cpp), [ShrubberyCreationForm.hpp](ex03/ShrubberyCreationForm.hpp), [main.cpp](ex03/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM05/ex03
make
./bureaucrat
```

Que observar:
El `main` solicita tres formularios conocidos y uno desconocido, `coffee request`. Libera los formularios creados con `delete`; la creacion de arbustos escribe `Garden_shrubbery`.

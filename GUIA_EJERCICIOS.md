# Guia de ejercicios de Exercise-CPP

## Resumen

Este documento resume, de forma progresiva, que se aprende en cada ejercicio que ya tiene implementacion dentro del repositorio. La idea es empezar con una explicacion poco tecnica y luego bajar a lo que hace realmente el codigo.

### Alcance

Se han documentado las carpetas que contienen codigo fuente:

- `CPPM00/ex00`
- `CPPM00/ex01`
- `CPPM00/ex02`
- `CPPM01/ex00`
- `CPPM01/ex01`
- `CPPM01/ex02`
- `CPPM01/ex03`
- `CPPM01/ex04`
- `CPPM01/ex05`
- `CPPM01/ex06`
- `CPPM02/ex00`
- `CPPM02/ex01`
- `CPPM02/ex02`
- `CPPM02/ex03`
- `CPPM03/ex00`
- `CPPM03/ex01`
- `CPPM03/ex02`
- `CPPM04/ex00`
- `CPPM04/ex01`
- `CPPM04/ex02`
- `CPPM05/ex00`
- `CPPM05/ex01`
- `CPPM05/ex02`
- `CPPM05/ex03`
- `CPPM06/ex00`
- `CPPM06/ex01`
- `CPPM06/ex02`
- `CPPM07/ex00`
- `CPPM07/ex01`
- `CPPM07/ex02`
- `CPPM08/ex00`
- `CPPM08/ex01`
- `CPPM08/ex02`

`CPPM08` contiene los tres ejercicios implementados. `CPPM09` contiene el PDF del enunciado y su documento informativo, pero aun no tiene codigo fuente.

Nota: `CPPM02/ex00`, `CPPM02/ex01` y `CPPM02/ex02` contienen ejercicios equivalentes a los de `CPPM00`, asi que la explicacion refleja lo que realmente hay en la carpeta.

## Contenido

Los ejemplos de terminal parten de la raiz del repositorio y se ejecutan por separado. Cada ejercicio sigue el mismo orden: explicacion poco tecnica, explicacion mas tecnica, archivos de consulta, compilacion y ejecucion, y que observar.

### CPPM00

#### [`CPPM00/ex00`](CPPM00/ex00/) - Megaphone

Explicacion poco tecnica:
Este ejercicio sirve para empezar a tratar un programa como una herramienta de consola. El usuario le pasa palabras al ejecutarlo y el programa las devuelve en mayusculas. Es una primera toma de contacto con leer argumentos y responder por pantalla.

Explicacion mas tecnica:
Se trabaja con `argc` y `argv`, se recorre cada argumento recibido y cada caracter se transforma con `std::toupper`. Tambien introduce `std::cout`, `std::endl` y el flujo basico de ejecucion de un `main`.

Archivos de consulta: [megaphone.cpp](CPPM00/ex00/megaphone.cpp).

Compilacion y ejecucion:

```bash
cd CPPM00/ex00
make
./megaphone "hola mundo"
```

Que observar:
Prueba argumentos con espacios y una ejecucion sin argumentos para observar el mensaje por defecto.

#### [`CPPM00/ex01`](CPPM00/ex01/) - PhoneBook

Explicacion poco tecnica:
Aqui se construye una agenda sencilla. El objetivo no es solo guardar datos, sino aprender a organizar un pequeno programa en varias piezas: una para los contactos y otra para la agenda.

Explicacion mas tecnica:
Se usan clases (`Contact` y `PhoneBook`), encapsulacion con getters y setters, lectura segura con `std::getline`, formateo de salida con `iomanip` y una estructura de capacidad fija que va sobrescribiendo contactos antiguos cuando se llena.

Archivos de consulta: [Contact.cpp](CPPM00/ex01/Contact.cpp), [Contact.hpp](CPPM00/ex01/Contact.hpp), [Main.cpp](CPPM00/ex01/Main.cpp), [PhoneBook.cpp](CPPM00/ex01/PhoneBook.cpp), [PhoneBook.hpp](CPPM00/ex01/PhoneBook.hpp).

Compilacion y ejecucion:

```bash
cd CPPM00/ex01
make
./phonebook
```

Que observar:
Usa `ADD`, `SEARCH` y `EXIT`. Anade mas de ocho contactos para observar la sustitucion de los mas antiguos y busca un indice inexistente.

#### [`CPPM00/ex02`](CPPM00/ex02/) - Account

Explicacion poco tecnica:
Este ejercicio muestra como varios objetos pueden compartir informacion comun. Cada cuenta bancaria tiene sus propios datos, pero al mismo tiempo el sistema lleva un resumen global de todas las cuentas.

Explicacion mas tecnica:
Se emplean atributos y metodos `static` para contar cuentas, total de dinero, depositos y retiradas. Tambien se practica el ciclo de vida de los objetos, la separacion entre estado individual y estado global, y el registro temporal con marcas de tiempo.

Archivos de consulta: [Account.cpp](CPPM00/ex02/Account.cpp), [Account.hpp](CPPM00/ex02/Account.hpp), [tests.cpp](CPPM00/ex02/tests.cpp).

Compilacion y ejecucion:

```bash
cd CPPM00/ex02
make
./Account
```

Que observar:
El programa ejecuta los casos de `tests.cpp`. Observa los totales compartidos, las retiradas rechazadas y las marcas de tiempo.

### CPPM01

#### [`CPPM01/ex00`](CPPM01/ex00/) - Zombie

Explicacion poco tecnica:
La idea principal es entender que un objeto puede crearse y desaparecer de distintas maneras. No todos los objetos viven lo mismo ni se destruyen igual.

Explicacion mas tecnica:
Se introduce la diferencia entre reserva dinamica con `new` y liberacion con `delete`, junto con funciones auxiliares que crean objetos y los hacen anunciarse. El ejercicio refuerza el papel del constructor, destructor y el riesgo de fugas de memoria.

Archivos de consulta: [Zombie.cpp](CPPM01/ex00/Zombie.cpp), [Zombie.hpp](CPPM01/ex00/Zombie.hpp), [main.cpp](CPPM01/ex00/main.cpp), [newZombie.cpp](CPPM01/ex00/newZombie.cpp), [randomChump.cpp](CPPM01/ex00/randomChump.cpp).

Compilacion y ejecucion:

```bash
cd CPPM01/ex00
make
./zombie
```

Que observar:
Observa cuando se anuncia cada zombie y cuando se llama a su destructor; la reserva con `new` necesita su correspondiente `delete`.

#### [`CPPM01/ex01`](CPPM01/ex01/) - Zombie Horde

Explicacion poco tecnica:
Ya no se crea un solo objeto, sino muchos del mismo tipo de una vez. Eso enseña a pensar en grupos de objetos y en como tratarlos de forma uniforme.

Explicacion mas tecnica:
Se reserva un array dinamico con `new[]`, se inicializa cada elemento en un bucle y luego se libera con `delete[]`. La leccion importante es que la forma de liberar memoria debe coincidir con la forma en que se reservo.

Archivos de consulta: [Zombie.cpp](CPPM01/ex01/Zombie.cpp), [Zombie.hpp](CPPM01/ex01/Zombie.hpp), [ZombieHorde.cpp](CPPM01/ex01/ZombieHorde.cpp), [main.cpp](CPPM01/ex01/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM01/ex01
make
./zombie
```

Que observar:
Comprueba que cada zombie de la horda se anuncia y que al liberar el array se ejecutan sus destructores.

#### [`CPPM01/ex02`](CPPM01/ex02/) - Pointers and References

Explicacion poco tecnica:
Este ejercicio aclara una duda muy comun: no es lo mismo tener una variable, tener una direccion hacia ella o tener otro nombre para la misma variable.

Explicacion mas tecnica:
Se compara una `std::string`, un puntero a esa cadena y una referencia a la misma. El programa imprime direcciones y valores para mostrar que el puntero guarda una direccion y necesita desreferenciarse, mientras que la referencia actua como un alias directo.

Archivos de consulta: [main.cpp](CPPM01/ex02/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM01/ex02
make
./ex02
```

Que observar:
Las direcciones de la cadena y de su referencia coinciden con la direccion almacenada en el puntero; los tres accesos muestran el mismo texto.

#### [`CPPM01/ex03`](CPPM01/ex03/) - Weapon / HumanA / HumanB

Explicacion poco tecnica:
Aqui se ve como varios objetos pueden estar relacionados entre si. Un personaje usa un arma, y cuando el arma cambia, el comportamiento del personaje cambia tambien.

Explicacion mas tecnica:
Se practica la diferencia entre guardar una referencia (`HumanA`) y guardar un puntero (`HumanB`). `HumanA` necesita arma desde el principio; `HumanB` puede existir sin ella y recibirla despues. Esto ensena dependencias obligatorias frente a opcionales.

Archivos de consulta: [HumanA.cpp](CPPM01/ex03/HumanA.cpp), [HumanA.hpp](CPPM01/ex03/HumanA.hpp), [HumanB.cpp](CPPM01/ex03/HumanB.cpp), [HumanB.hpp](CPPM01/ex03/HumanB.hpp), [Weapon.cpp](CPPM01/ex03/Weapon.cpp), [Weapon.hpp](CPPM01/ex03/Weapon.hpp), [main.cpp](CPPM01/ex03/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM01/ex03
make
./ex03
```

Que observar:
El `main` cambia el tipo del arma despues de crear los personajes. Observa que los ataques reflejan ese cambio.

#### [`CPPM01/ex04`](CPPM01/ex04/) - Replacer

Explicacion poco tecnica:
El programa toma un archivo y crea otro cambiando un texto por otro. Es un ejercicio muy util para entender programas que procesan informacion de entrada y generan un resultado nuevo.

Explicacion mas tecnica:
Se usa lectura de archivos con `std::ifstream`, escritura con `std::ofstream`, acumulacion en `std::ostringstream` y reemplazo manual con `std::string::find` y `substr`. Tambien incluye validacion de errores mediante excepciones.

Archivos de consulta: [Replacer.cpp](CPPM01/ex04/Replacer.cpp), [Replacer.hpp](CPPM01/ex04/Replacer.hpp), [main.cpp](CPPM01/ex04/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM01/ex04
make
./replacer entrada.txt hola adios
```

Que observar:
Crea antes un archivo `entrada.txt` con el texto `hola`. El ejemplo genera `entrada.txt.replace`; revisa su contenido. Tambien puedes probar una ruta inexistente.

#### [`CPPM01/ex05`](CPPM01/ex05/) - Harl

Explicacion poco tecnica:
Este ejercicio ensena a decidir una accion segun una palabra clave. Es como montar un pequeno menu interno dentro de una clase.

Explicacion mas tecnica:
La clase `Harl` asocia niveles de texto con metodos miembros concretos. Para ello usa un array de cadenas y un array de punteros a funciones miembro, lo que permite despachar comportamiento sin una cadena larga de `if` independientes.

Archivos de consulta: [Harl.cpp](CPPM01/ex05/Harl.cpp), [Harl.hpp](CPPM01/ex05/Harl.hpp), [main.cpp](CPPM01/ex05/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM01/ex05
make
./harl DEBUG
```

Que observar:
Prueba `DEBUG`, `INFO`, `WARNING` y `ERROR`: cada argumento selecciona un unico metodo.

#### [`CPPM01/ex06`](CPPM01/ex06/) - Harl Filter

Explicacion poco tecnica:
Es una evolucion del ejercicio anterior: no solo eliges un mensaje, sino que a partir de cierto nivel se muestran varios, como un filtro por severidad.

Explicacion mas tecnica:
Se reutiliza el mapeo entre nivel y funcion, pero ahora se combina con un `switch` y `fallthrough` para ejecutar el nivel pedido y todos los superiores. Eso ensena una forma compacta de expresar comportamiento acumulativo.

Archivos de consulta: [Harl.cpp](CPPM01/ex06/Harl.cpp), [Harl.hpp](CPPM01/ex06/Harl.hpp), [main.cpp](CPPM01/ex06/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM01/ex06
make
./harlFilter WARNING
```

Que observar:
Con `WARNING` se muestran `WARNING` y `ERROR`. Con `DEBUG` se muestran todos los niveles; una palabra desconocida produce un mensaje de nivel no reconocido.

### CPPM02

#### [`CPPM02/ex00`](CPPM02/ex00/) - Megaphone duplicado

Explicacion poco tecnica:
En esta carpeta hay otro ejercicio de transformacion de texto por consola, igual en concepto al `Megaphone` anterior.

Explicacion mas tecnica:
El codigo vuelve a trabajar con argumentos de linea de comandos y conversion a mayusculas caracter a caracter.

Archivos de consulta: [megaphone.cpp](CPPM02/ex00/megaphone.cpp).

Compilacion y ejecucion:

```bash
cd CPPM02/ex00
make
./megaphone "hola mundo"
```

Que observar:
Este contenido repite Megaphone de CPPM00/ex00.

#### [`CPPM02/ex01`](CPPM02/ex01/) - PhoneBook duplicado

Explicacion poco tecnica:
Aqui aparece otra vez la agenda de contactos, por lo que vuelve a reforzar la idea de separar datos y logica del programa.

Explicacion mas tecnica:
Repite el uso de clases, capacidad fija, entrada por consola y salida tabulada.

Archivos de consulta: [Contact.cpp](CPPM02/ex01/Contact.cpp), [Contact.hpp](CPPM02/ex01/Contact.hpp), [Main.cpp](CPPM02/ex01/Main.cpp), [PhoneBook.cpp](CPPM02/ex01/PhoneBook.cpp), [PhoneBook.hpp](CPPM02/ex01/PhoneBook.hpp).

Compilacion y ejecucion:

```bash
cd CPPM02/ex01
make
./phonebook
```

Que observar:
Este contenido repite PhoneBook de CPPM00/ex01.

#### [`CPPM02/ex02`](CPPM02/ex02/) - Account duplicado

Explicacion poco tecnica:
De nuevo se trabaja el seguimiento individual y global de varias cuentas.

Explicacion mas tecnica:
Repite el uso de miembros `static`, operaciones de deposito y retirada, y el mantenimiento de estadisticas compartidas por todos los objetos.

Archivos de consulta: [Account.cpp](CPPM02/ex02/Account.cpp), [Account.hpp](CPPM02/ex02/Account.hpp), [tests.cpp](CPPM02/ex02/tests.cpp).

Compilacion y ejecucion:

```bash
cd CPPM02/ex02
make
./Account
```

Que observar:
Este contenido repite Account de CPPM00/ex02.

#### [`CPPM02/ex03`](CPPM02/ex03/) - BSP / Point / Fixed

Explicacion poco tecnica:
Este es el ejercicio que mas claramente cambia de tema: se empieza a trabajar con numeros y posiciones en un plano. La pregunta central es si un punto cae dentro o fuera de un triangulo.

Explicacion mas tecnica:
Se implementa un tipo `Fixed` para representar valores con precision fija y una clase `Point` con coordenadas inmutables. La funcion `bsp` usa signos de areas o productos cruzados para comprobar si un punto esta estrictamente dentro del triangulo, excluyendo bordes y vertices.

Archivos de consulta: [Fixed.cpp](CPPM02/ex03/Fixed.cpp), [Fixed.hpp](CPPM02/ex03/Fixed.hpp), [Point.cpp](CPPM02/ex03/Point.cpp), [Point.hpp](CPPM02/ex03/Point.hpp), [bsp.cpp](CPPM02/ex03/bsp.cpp), [main.cpp](CPPM02/ex03/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM02/ex03
make
./bsp
```

Que observar:
El `main` comprueba varios puntos respecto a un triangulo. Un punto sobre un borde o vertice debe quedar fuera; `1` representa interior y `0`, exterior.

### CPPM03

#### [`CPPM03/ex00`](CPPM03/ex00/) - ClapTrap

Explicacion poco tecnica:
Aqui se crea un personaje simple con vida, energia y acciones. Es un paso natural para aprender a modelar entidades con estado y comportamiento.

Explicacion mas tecnica:
La clase `ClapTrap` encapsula atributos privados y metodos como `attack`, `takeDamage` y `beRepaired`. El ejercicio trabaja constructores, copia, asignacion y las reglas que impiden actuar cuando no queda vida o energia.

Archivos de consulta: [ClapTrap.cpp](CPPM03/ex00/ClapTrap.cpp), [ClapTrap.hpp](CPPM03/ex00/ClapTrap.hpp), [main.cpp](CPPM03/ex00/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM03/ex00
make
./claptrap
```

Que observar:
El `main` agota la energia y reduce la vida a cero. Observa cuando dejan de permitirse ataques y reparaciones.

#### [`CPPM03/ex01`](CPPM03/ex01/) - ScavTrap

Explicacion poco tecnica:
Ahora aparece un personaje mas especializado que hereda lo basico del anterior y anade su propia identidad. La leccion es reutilizar en vez de empezar desde cero.

Explicacion mas tecnica:
Se introduce herencia publica con `ScavTrap : public ClapTrap`, redefinicion de `attack` y un metodo propio (`guardGate`). Tambien ayuda a observar el orden de construccion y destruccion entre clase base y derivada.

Archivos de consulta: [ClapTrap.cpp](CPPM03/ex01/ClapTrap.cpp), [ClapTrap.hpp](CPPM03/ex01/ClapTrap.hpp), [ScavTrap.cpp](CPPM03/ex01/ScavTrap.cpp), [ScavTrap.hpp](CPPM03/ex01/ScavTrap.hpp), [ScravTrap.cpp](CPPM03/ex01/ScravTrap.cpp), [main.cpp](CPPM03/ex01/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM03/ex01
make
./scavtrap
```

Que observar:
Observa la construccion de la base antes de la derivada y la destruccion en orden inverso, ademas de `guardGate()`.

#### [`CPPM03/ex02`](CPPM03/ex02/) - FragTrap

Explicacion poco tecnica:
Se sigue ampliando la familia de personajes. Cada uno comparte una base comun, pero cambia sus valores y sus acciones especiales.

Explicacion mas tecnica:
`FragTrap` deriva de `ClapTrap`, ajusta sus estadisticas y agrega `highFivesGuys`. El ejercicio refuerza herencia, especializacion de comportamiento y reutilizacion de codigo de la clase base.

Archivos de consulta: [ClapTrap.cpp](CPPM03/ex02/ClapTrap.cpp), [ClapTrap.hpp](CPPM03/ex02/ClapTrap.hpp), [FragTrap.cpp](CPPM03/ex02/FragTrap.cpp), [FragTrap.hpp](CPPM03/ex02/FragTrap.hpp), [ScavTrap.cpp](CPPM03/ex02/ScavTrap.cpp), [ScavTrap.hpp](CPPM03/ex02/ScavTrap.hpp), [ScravTrap.cpp](CPPM03/ex02/ScravTrap.cpp), [main.cpp](CPPM03/ex02/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM03/ex02
make
./FragTrap
```

Que observar:
El `main` combina ClapTrap, ScavTrap y FragTrap. Observa las acciones especiales y las diferencias de estadisticas. El ejecutable del Makefile se llama `FragTrap`.

### CPPM04

#### [`CPPM04/ex00`](CPPM04/ex00/) - Animal, Dog, Cat

Explicacion poco tecnica:
Este ejercicio ensena que varios objetos pueden responder de forma distinta al mismo mensaje. Todos son animales, pero cada uno suena diferente.

Explicacion mas tecnica:
Se organiza una jerarquia con una clase base `Animal` y derivadas `Dog` y `Cat`. En esta implementacion concreta, `makeSound` no aparece virtual en la cabecera, asi que tambien sirve para entender la diferencia entre tener una interfaz comun y tener polimorfismo real.

Archivos de consulta: [Animal.cpp](CPPM04/ex00/Animal.cpp), [Animal.hpp](CPPM04/ex00/Animal.hpp), [Cat.cpp](CPPM04/ex00/Cat.cpp), [Cat.hpp](CPPM04/ex00/Cat.hpp), [Dog.cpp](CPPM04/ex00/Dog.cpp), [Dog.hpp](CPPM04/ex00/Dog.hpp), [main.cpp](CPPM04/ex00/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM04/ex00
make
./animals
```

Que observar:
El `main` llama directamente a los objetos concretos. La cabecera actual no declara virtuales ni `makeSound` ni el destructor; esta version no demuestra despacho dinamico a traves de `Animal*`.

#### [`CPPM04/ex01`](CPPM04/ex01/) - Brain y copia profunda

Explicacion poco tecnica:
Aqui se da un paso importante: algunos objetos contienen recursos propios internos, y copiar el objeto mal puede provocar que dos animales compartan la misma "cabeza" sin querer.

Explicacion mas tecnica:
`Dog` y `Cat` almacenan un `Brain` reservado dinamicamente. Por eso implementan constructor de copia, operador de asignacion y destructor para hacer copia profunda y liberar memoria correctamente. Es una aplicacion practica de la regla de tres.

Archivos de consulta: [Animal.cpp](CPPM04/ex01/Animal.cpp), [Animal.hpp](CPPM04/ex01/Animal.hpp), [Brain.cpp](CPPM04/ex01/Brain.cpp), [Brain.hpp](CPPM04/ex01/Brain.hpp), [Cat.cpp](CPPM04/ex01/Cat.cpp), [Cat.hpp](CPPM04/ex01/Cat.hpp), [Dog.cpp](CPPM04/ex01/Dog.cpp), [Dog.hpp](CPPM04/ex01/Dog.hpp), [main.cpp](CPPM04/ex01/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM04/ex01
make
./animals
```

Que observar:
El `main` crea un array de animales y prueba copias de Dog y Cat. Cambiar una idea en la copia debe dejar intacta la del original.

#### [`CPPM04/ex02`](CPPM04/ex02/) - Animal abstracto

Explicacion poco tecnica:
La clase base deja de representar un animal "real" y pasa a ser una idea general. Ya no se crea un `Animal` generico; solo animales concretos.

Explicacion mas tecnica:
`Animal` declara `makeSound()` como funcion virtual pura, convirtiendose en clase abstracta. Esto obliga a las derivadas a implementar el comportamiento y permite polimorfismo correcto con destructor virtual.

Archivos de consulta: [Animal.cpp](CPPM04/ex02/Animal.cpp), [Animal.hpp](CPPM04/ex02/Animal.hpp), [Brain.cpp](CPPM04/ex02/Brain.cpp), [Brain.hpp](CPPM04/ex02/Brain.hpp), [Cat.cpp](CPPM04/ex02/Cat.cpp), [Cat.hpp](CPPM04/ex02/Cat.hpp), [Dog.cpp](CPPM04/ex02/Dog.cpp), [Dog.hpp](CPPM04/ex02/Dog.hpp), [main.cpp](CPPM04/ex02/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM04/ex02
make
./animals
```

Que observar:
El `main` mantiene las pruebas de copia y polimorfismo. La construccion de un Animal generico aparece comentada porque la clase es abstracta.

### CPPM05

#### [`CPPM05/ex00`](CPPM05/ex00/) - Bureaucrat

Explicacion poco tecnica:
El foco esta en objetos que tienen reglas estrictas. Un burocrata no puede tener cualquier nivel: si se sale de los limites, el programa debe detectarlo.

Explicacion mas tecnica:
La clase `Bureaucrat` valida que `grade` este entre 1 y 150, y lanza excepciones especificas cuando se intenta construir o modificar el objeto fuera de ese rango. El ejercicio introduce control de errores con clases de excepcion propias.

Archivos de consulta: [Bureaucrat.cpp](CPPM05/ex00/Bureaucrat.cpp), [Bureaucrat.hpp](CPPM05/ex00/Bureaucrat.hpp), [main.cpp](CPPM05/ex00/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM05/ex00
make
./bureaucrat
```

Que observar:
El `main` prueba cambios de grado y construcciones con 0 y 151. El grado 1 es el de mayor autoridad y 150 el de menor.

#### [`CPPM05/ex01`](CPPM05/ex01/) - Form

Explicacion poco tecnica:
Ahora ya no basta con que exista un burocrata: tambien hay formularios que pueden o no firmarse dependiendo del nivel de quien lo intenta.

Explicacion mas tecnica:
Se conecta `Bureaucrat` con `Form` mediante `beSigned`. El formulario mantiene estado de firma y dos requisitos numericos: uno para firmar y otro para ejecutar. Se refuerzan colaboracion entre clases, inmutabilidad parcial y propagacion de excepciones.

Archivos de consulta: [Bureaucrat.cpp](CPPM05/ex01/Bureaucrat.cpp), [Bureaucrat.hpp](CPPM05/ex01/Bureaucrat.hpp), [Form.cpp](CPPM05/ex01/Form.cpp), [Form.hpp](CPPM05/ex01/Form.hpp), [main.cpp](CPPM05/ex01/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM05/ex01
make
./bureaucrat
```

Que observar:
Bob no puede firmar Contract con grado 75; Alice si con grado 2. Alice tampoco alcanza el grado 1 de TopSecret.

#### [`CPPM05/ex02`](CPPM05/ex02/) - AForm y formularios concretos

Explicacion poco tecnica:
El sistema se vuelve mas realista: distintos formularios hacen cosas distintas, aunque todos comparten la misma idea general de firmarse y ejecutarse.

Explicacion mas tecnica:
`AForm` pasa a ser una base abstracta y las clases derivadas implementan acciones concretas: escribir un arbol ASCII en un archivo, intentar una robotomizacion aleatoria o conceder un perdon presidencial. Se practica polimorfismo, validacion previa a la ejecucion y especializacion por herencia.

Archivos de consulta: [AForm.cpp](CPPM05/ex02/AForm.cpp), [AForm.hpp](CPPM05/ex02/AForm.hpp), [Bureaucrat.cpp](CPPM05/ex02/Bureaucrat.cpp), [Bureaucrat.hpp](CPPM05/ex02/Bureaucrat.hpp), [PresidentialPardonForm.cpp](CPPM05/ex02/PresidentialPardonForm.cpp), [PresidentialPardonForm.hpp](CPPM05/ex02/PresidentialPardonForm.hpp), [RobotomyRequestForm.cpp](CPPM05/ex02/RobotomyRequestForm.cpp), [RobotomyRequestForm.hpp](CPPM05/ex02/RobotomyRequestForm.hpp), [ShrubberyCreationForm.cpp](CPPM05/ex02/ShrubberyCreationForm.cpp), [ShrubberyCreationForm.hpp](CPPM05/ex02/ShrubberyCreationForm.hpp), [main.cpp](CPPM05/ex02/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM05/ex02
make
./bureaucrat
```

Que observar:
El `main` prueba ejecucion sin firma, grados insuficientes y acciones autorizadas. La creacion de arbustos escribe `garden_shrubbery` en el directorio de ejecucion; la robotomizacion es aleatoria.

#### [`CPPM05/ex03`](CPPM05/ex03/) - Intern

Explicacion poco tecnica:
Este ejercicio ensena a crear objetos sin que el resto del programa tenga que saber exactamente que clase concreta necesita construir. Es una forma de centralizar la "fabricacion".

Explicacion mas tecnica:
La clase `Intern` actua como una factoria: recibe el nombre textual de un formulario y devuelve una instancia del tipo adecuado. Internamente usa una tabla que relaciona nombres con funciones creadoras, evitando muchos `if` dispersos.

Archivos de consulta: [AForm.cpp](CPPM05/ex03/AForm.cpp), [AForm.hpp](CPPM05/ex03/AForm.hpp), [Bureaucrat.cpp](CPPM05/ex03/Bureaucrat.cpp), [Bureaucrat.hpp](CPPM05/ex03/Bureaucrat.hpp), [Intern.cpp](CPPM05/ex03/Intern.cpp), [Intern.hpp](CPPM05/ex03/Intern.hpp), [PresidentialPardonForm.cpp](CPPM05/ex03/PresidentialPardonForm.cpp), [PresidentialPardonForm.hpp](CPPM05/ex03/PresidentialPardonForm.hpp), [RobotomyRequestForm.cpp](CPPM05/ex03/RobotomyRequestForm.cpp), [RobotomyRequestForm.hpp](CPPM05/ex03/RobotomyRequestForm.hpp), [ShrubberyCreationForm.cpp](CPPM05/ex03/ShrubberyCreationForm.cpp), [ShrubberyCreationForm.hpp](CPPM05/ex03/ShrubberyCreationForm.hpp), [main.cpp](CPPM05/ex03/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM05/ex03
make
./bureaucrat
```

Que observar:
El `main` solicita tres formularios conocidos y uno desconocido, `coffee request`. Libera los formularios creados con `delete`; la creacion de arbustos escribe `Garden_shrubbery`.

### CPPM06

#### [`CPPM06/ex00`](CPPM06/ex00/) - ScalarConverter

Explicacion poco tecnica:
El objetivo es tomar un dato escrito como texto y averiguar de que tipo parece ser, para despues mostrarlo en varios formatos distintos. Es una forma muy clara de aprender conversiones.

Explicacion mas tecnica:
`ScalarConverter` es una clase utilitaria con solo metodos estaticos. Intenta interpretar el literal como `char`, `int`, `float` o `double`, valida errores de parseo y rangos con `strtol`, `strtod`, `errno` y limites numericos, y despues muestra las conversiones posibles. El manejo de pseudoliterales esta incompleto: `nanf`, `+inff` y `-inff` se rechazan, y algunos casts a `int` de las funciones de salida requieren revisar los limites antes de convertir.

Archivos de consulta: [ScalarConverter.cpp](CPPM06/ex00/ScalarConverter.cpp), [ScalarConverter.hpp](CPPM06/ex00/ScalarConverter.hpp), [main.cpp](CPPM06/ex00/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM06/ex00
make
./scalar_converter 42
```

Que observar:
Prueba tambien `a`, `42.0f`, `3.14` y un texto invalido. La logica de parseo y conversion esta en `main.cpp`; `ScalarConverter.cpp` contiene los miembros de construccion, copia y destruccion. La implementacion rechaza `nanf` y los infinitos con sufijo `f`; el tratamiento de pseudoliterales y los casts a `int` fuera de rango necesitan revision.

#### [`CPPM06/ex01`](CPPM06/ex01/) - Serialization

Explicacion poco tecnica:
Aqui se trabaja una idea muy concreta: convertir una direccion de memoria en un numero y luego recuperar esa misma direccion desde ese numero. No se copian los datos; solo se transforma el puntero para entender mejor como representar direcciones.

Explicacion mas tecnica:
`Serialization` se ha planteado como clase utilitaria con metodos estaticos `serialize` y `deserialize`, usando `reinterpret_cast` para convertir entre `Data*` y `uintptr_t`. La estructura `Data` no esta vacia y contiene al menos un `int` y un `std::string`, lo suficiente para cumplir el enunciado. En `main.cpp` hay una prueba muy simple que crea un objeto `Data`, lo serializa, lo deserializa y comprueba por salida que el puntero restaurado coincide con el original y que los campos siguen siendo accesibles. El ejercicio ya tiene tambien un `Makefile` minimo para compilar `main.cpp`, `Serialization.cpp` y `Data.cpp`.

Archivos de consulta: [Data.cpp](CPPM06/ex01/Data.cpp), [Data.hpp](CPPM06/ex01/Data.hpp), [Serialization.cpp](CPPM06/ex01/Serialization.cpp), [Serialization.hpp](CPPM06/ex01/Serialization.hpp), [main.cpp](CPPM06/ex01/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM06/ex01
make
./serialization
```

Que observar:
La salida debe incluir `Same pointer:   1` y los datos `42, test`. El entero representa una direccion del proceso: el objeto original debe seguir vivo al recuperar y usar el puntero; no es un formato de almacenamiento de sus campos.

#### [`CPPM06/ex02`](CPPM06/ex02/) - Identify real type

Explicacion poco tecnica:
El programa crea al azar un objeto de tipo `A`, `B` o `C` y lo entrega como un puntero a su clase base. Despues averigua que objeto se creo realmente, primero mediante un puntero y despues mediante una referencia.

Explicacion mas tecnica:
`Base` tiene un destructor virtual y las clases `A`, `B` y `C` heredan publicamente de ella. `generate()` usa `rand() % 3` y `new` para devolver una de las tres derivadas. Las dos sobrecargas de `identify` usan `dynamic_cast`: con punteros, una conversion fallida devuelve un puntero nulo; con referencias, lanza una excepcion que el codigo captura con `catch (...)` antes de probar el siguiente tipo. No se usa `typeid`. El `main` inicializa la semilla con la hora, identifica el mismo objeto de ambas formas y libera la memoria con `delete` a traves de `Base*`.

Estado actual:
La carpeta contiene `Base.hpp`, `Base.cpp` y `main.cpp`, pero todavia no tiene `Makefile`. La documentacion del modulo incluye un comando de compilacion manual. Cada ejecucion debe imprimir dos veces la misma letra (`A`, `B` o `C`); no tiene por que cambiar entre ejecuciones.

Archivos de consulta: [Base.cpp](CPPM06/ex02/Base.cpp), [Base.hpp](CPPM06/ex02/Base.hpp), [main.cpp](CPPM06/ex02/main.cpp).

Compilacion y ejecucion:

```bash
cd CPPM06/ex02
c++ -Wall -Wextra -Werror -std=c++98 -include cstdlib main.cpp Base.cpp -o identify
./identify
```

Que observar:
Ambas llamadas a `identify` deben imprimir la misma letra. El cast de puntero imprime `NOTHING` si no encuentra A, B o C; la version de referencia termina sin imprimir si fallan los tres casts.

El comando incluye `cstdlib` explicitamente porque `main.cpp` usa `srand` sin incluir su cabecera directamente. La carpeta aun no dispone de Makefile.

### CPPM07

#### [`CPPM07/ex00`](CPPM07/ex00/) - Funciones plantilla

Explicacion poco tecnica:
Se escriben funciones que sirven para varios tipos de datos sin repetir el mismo algoritmo. El ejemplo intercambia y compara tanto enteros como cadenas.

Explicacion mas tecnica:
`whatever.hpp` define las plantillas `swap`, `min` y `max`. `swap` recibe referencias modificables; `min` y `max` reciben y devuelven referencias constantes. En caso de igualdad, ambas devuelven el segundo argumento. El tipo utilizado debe soportar las operaciones que ejecuta cada funcion. El `main` usa `::` para seleccionar las funciones del espacio global.

Archivos de consulta: [whatever.hpp](CPPM07/ex00/whatever.hpp), [main.cpp](CPPM07/ex00/main.cpp), [Makefile](CPPM07/ex00/Makefile).

Compilacion y ejecucion:

```bash
cd CPPM07/ex00
make
./whatever
```

Que observar:
Tras intercambiar los enteros, `a` vale `3` y `b` vale `2`; el minimo es `2` y el maximo `3`. Las cadenas quedan como `chaine2` y `chaine1`, con minimo `chaine1` y maximo `chaine2`.

#### [`CPPM07/ex01`](CPPM07/ex01/) - iter

Explicacion poco tecnica:
Una misma funcion recorre un array y aplica una accion a cada elemento: mostrarlo, incrementarlo o modificar sus campos.

Explicacion mas tecnica:
`iter(A* array, const std::size_t len, F f)` recibe un puntero, una longitud y una funcion cuyo tipo tambien es un parametro de plantilla. Permite trabajar con elementos modificables y constantes, segun el array y la funcion recibidos. El `main` comprueba enteros, decimales, cadenas, arrays constantes, una estructura `Point`, longitud cero y recorridos parciales mediante salida por consola y `assert`. Quien llama debe proporcionar una longitud que no exceda el array disponible.

Archivos de consulta: [iter.hpp](CPPM07/ex01/iter.hpp), [main.cpp](CPPM07/ex01/main.cpp), [Makefile](CPPM07/ex01/Makefile).

Compilacion y ejecucion:

```bash
cd CPPM07/ex01
make
./iter
```

Que observar:
Los enteros pasan de `1 2 3` a `2 3 4`, las cadenas a `Hola! Mundo!` y los puntos a `(2, 4) (4, 6)`. Las comprobaciones terminan con `Todas las pruebas han pasado.`. Los arrays constantes se recorren para lectura.

#### [`CPPM07/ex02`](CPPM07/ex02/) - Array

Explicacion poco tecnica:
Se construye un array cuyo tipo de elementos se elige al usarlo, por ejemplo `Array<int>`. Guarda su numero de elementos y detecta los accesos fuera de sus limites.

Explicacion mas tecnica:
`Array.hpp` declara la clase y al final incluye `Array.tpp`, donde se definen los metodos de la plantilla. El constructor por defecto crea un array vacio; el constructor con tamano reserva exactamente `num` elementos mediante `new T[num]()` y los inicializa por valor. El constructor de copia reserva almacenamiento propio y copia los elementos. Las dos versiones de `operator[]` devuelven `T&` o `const T&` y lanzan `std::exception` si `index >= _size`. `size() const` consulta el tamano sin modificar el objeto. El Makefile contempla `.hpp` y `.tpp` como dependencias; el `.tpp` se incluye, no se compila por separado.

Estado actual:
El ejemplo compila, imprime `42` y `3`, y captura la excepcion al acceder al indice `3` de un array de tres elementos. El destructor esta definido pero vacio: falta liberar `_data` con `delete[]`. El operador de asignacion esta declarado pero no definido; falta implementar la copia independiente tambien para la asignacion. El `main` actual no prueba la copia, la asignacion, el array vacio ni el acceso constante.

Archivos de consulta: [Array.hpp](CPPM07/ex02/Array.hpp), [Array.tpp](CPPM07/ex02/Array.tpp), [main.cpp](CPPM07/ex02/main.cpp), [Makefile](CPPM07/ex02/Makefile).

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

### CPPM08

#### [`CPPM08/ex00`](CPPM08/ex00/) - easyfind

Explicacion poco tecnica:
Se busca un numero dentro de un grupo de enteros. La misma funcion sirve para distintos contenedores, sin escribir una busqueda diferente para cada uno.

Explicacion mas tecnica:
`easyfind(T& container, int n)` utiliza `std::find` sobre el intervalo `[begin(), end())`. Devuelve un `T::iterator` a la primera coincidencia y lanza `std::runtime_error` si no encuentra el numero, tambien cuando el contenedor esta vacio. La busqueda es lineal. La plantilla se define en `easyfind.hpp` para que pueda instanciarse desde otros archivos; incluye sus dependencias y esta protegida contra doble inclusion. Esta version recibe contenedores modificables y no ofrece una sobrecarga para contenedores constantes.

Archivos de consulta: [easyfind.hpp](CPPM08/ex00/easyfind.hpp), [main.cpp](CPPM08/ex00/main.cpp), [Makefile](CPPM08/ex00/Makefile).

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

#### [`CPPM08/ex01`](CPPM08/ex01/) - Span

Explicacion poco tecnica:
Se guardan hasta N enteros y se calcula la distancia mas pequena y la mas grande entre dos de ellos. Tambien se puede insertar un grupo completo mediante iteradores.

Explicacion mas tecnica:
`Span(unsigned int n)` fija la capacidad y almacena los valores en un `std::vector<int>`. El constructor por defecto crea una capacidad cero; constructor de copia, asignacion y destructor completan la forma canonica. `addNumber(int)` lanza `std::length_error` cuando la capacidad esta agotada. La sobrecarga plantilla `addNumber(first, last)` acepta un rango valido `[first, last)`, incluidos iteradores de entrada, y prepara los valores en un vector temporal: si no caben, el Span conserva su contenido anterior. Un rango vacio no anade elementos.

`shortestSpan() const` ordena una copia con `std::sort` y compara vecinos, con coste O(n log n), sin alterar el orden almacenado. `longestSpan() const` resta el minimo al maximo, obtenidos con `std::min_element` y `std::max_element`, con coste O(n). Ambas devuelven `unsigned int`, convierten los operandos antes de restar para manejar `INT_MIN` e `INT_MAX` sin desbordamiento con signo, y lanzan `std::logic_error` si hay menos de dos numeros. Los duplicados producen una distancia minima cero.

Archivos de consulta: [Span.hpp](CPPM08/ex01/Span.hpp), [Span.cpp](CPPM08/ex01/Span.cpp), [main.cpp](CPPM08/ex01/main.cpp), [Makefile](CPPM08/ex01/Makefile).

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

#### [`CPPM08/ex02`](CPPM08/ex02/) - MutantStack (Mutated abomination)

Explicacion poco tecnica:
Una pila permite consultar y retirar el ultimo elemento anadido. Este ejercicio mantiene ese comportamiento y permite recorrer todos los elementos sin tener que sacarlos de la pila.

Explicacion mas tecnica:
`MutantStack<T, Container>` hereda publicamente de `std::stack<T, Container>` y usa `std::deque<T>` como contenedor predeterminado. Conserva funciones como `push`, `pop`, `top`, `size` y `empty`. Expone los iteradores del contenedor protegido `c`: `begin()` y `end()` recorren desde la base hasta la cima; `rbegin()` y `rend()` lo hacen en sentido inverso. Hay versiones modificables y constantes, con los tipos `iterator`, `const_iterator`, `reverse_iterator` y `const_reverse_iterator`. Las reglas de invalidacion de iteradores dependen del contenedor subyacente.

La forma canonica copia el estado de la clase base. Existe ademas un constructor desde un contenedor compatible. Las declaraciones estan en `MutantStack.hpp` y las definiciones de plantilla en `MutantStack.tpp`, incluido desde la cabecera; el `.tpp` no se compila por separado. La herencia permite construir un `std::stack<int>` a partir de un `MutantStack<int>`.

Archivos de consulta: [MutantStack.hpp](CPPM08/ex02/MutantStack.hpp), [MutantStack.tpp](CPPM08/ex02/MutantStack.tpp), [main.cpp](CPPM08/ex02/main.cpp), [Makefile](CPPM08/ex02/Makefile).

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

### Resumen general de aprendizaje

Si se mira el repositorio en conjunto, la progresion de conceptos es esta:

- Entrada y salida por consola.
- Organizacion del codigo en clases y archivos separados.
- Memoria dinamica, punteros y referencias.
- Procesado de texto y archivos.
- Copia de objetos y gestion correcta de recursos.
- Herencia, especializacion y polimorfismo.
- Excepciones y validacion de reglas.
- Creacion flexible de objetos y conversion entre tipos.
- Programacion generica con plantillas de funciones y clases, const y acceso comprobado a arrays.
- Contenedores STL, algoritmos, iteradores, busqueda generica, distancias entre valores y pilas iterables.

## Referencias

[README](README.md)

- [CPPM00info.md](CPPM00/CPPM00info.md)
- [CPPM01info.md](CPPM01/CPPM01info.md)
- [CPPM02info.md](CPPM02/CPPM02info.md)
- [CPPM03info.md](CPPM03/CPPM03info.md)
- [CPPM04info.md](CPPM04/CPPM04info.md)
- [CPPM05info.md](CPPM05/CPPM05info.md)
- [CPPM06info.md](CPPM06/CPPM06info.md)
- [CPPM07info.md](CPPM07/CPPM07info.md)
- [CPPM08info.md](CPPM08/CPPM08info.md)
- [CPPM09info.md](CPPM09/CPPM09info.md)

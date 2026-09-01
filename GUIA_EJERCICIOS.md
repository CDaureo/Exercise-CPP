# Guia de ejercicios de Exercise-CPP

Este documento resume, de forma progresiva, que se aprende en cada ejercicio que ya tiene implementacion dentro del repositorio. La idea es empezar con una explicacion poco tecnica y luego bajar a lo que hace realmente el codigo.

## Alcance

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

`CPPM07`, `CPPM08` y `CPPM09` solo contienen el PDF del enunciado.

Nota: `CPPM02/ex00`, `CPPM02/ex01` y `CPPM02/ex02` contienen ejercicios equivalentes a los de `CPPM00`, asi que la explicacion refleja lo que realmente hay en la carpeta.

## CPPM00

### `CPPM00/ex00` - Megaphone

Explicacion poco tecnica:
Este ejercicio sirve para empezar a tratar un programa como una herramienta de consola. El usuario le pasa palabras al ejecutarlo y el programa las devuelve en mayusculas. Es una primera toma de contacto con leer argumentos y responder por pantalla.

Explicacion mas tecnica:
Se trabaja con `argc` y `argv`, se recorre cada argumento recibido y cada caracter se transforma con `std::toupper`. Tambien introduce `std::cout`, `std::endl` y el flujo basico de ejecucion de un `main`.

### `CPPM00/ex01` - PhoneBook

Explicacion poco tecnica:
Aqui se construye una agenda sencilla. El objetivo no es solo guardar datos, sino aprender a organizar un pequeno programa en varias piezas: una para los contactos y otra para la agenda.

Explicacion mas tecnica:
Se usan clases (`Contact` y `PhoneBook`), encapsulacion con getters y setters, lectura segura con `std::getline`, formateo de salida con `iomanip` y una estructura de capacidad fija que va sobrescribiendo contactos antiguos cuando se llena.

### `CPPM00/ex02` - Account

Explicacion poco tecnica:
Este ejercicio muestra como varios objetos pueden compartir informacion comun. Cada cuenta bancaria tiene sus propios datos, pero al mismo tiempo el sistema lleva un resumen global de todas las cuentas.

Explicacion mas tecnica:
Se emplean atributos y metodos `static` para contar cuentas, total de dinero, depositos y retiradas. Tambien se practica el ciclo de vida de los objetos, la separacion entre estado individual y estado global, y el registro temporal con marcas de tiempo.

## CPPM01

### `CPPM01/ex00` - Zombie

Explicacion poco tecnica:
La idea principal es entender que un objeto puede crearse y desaparecer de distintas maneras. No todos los objetos viven lo mismo ni se destruyen igual.

Explicacion mas tecnica:
Se introduce la diferencia entre reserva dinamica con `new` y liberacion con `delete`, junto con funciones auxiliares que crean objetos y los hacen anunciarse. El ejercicio refuerza el papel del constructor, destructor y el riesgo de fugas de memoria.

### `CPPM01/ex01` - Zombie Horde

Explicacion poco tecnica:
Ya no se crea un solo objeto, sino muchos del mismo tipo de una vez. Eso enseña a pensar en grupos de objetos y en como tratarlos de forma uniforme.

Explicacion mas tecnica:
Se reserva un array dinamico con `new[]`, se inicializa cada elemento en un bucle y luego se libera con `delete[]`. La leccion importante es que la forma de liberar memoria debe coincidir con la forma en que se reservo.

### `CPPM01/ex02` - Pointers and References

Explicacion poco tecnica:
Este ejercicio aclara una duda muy comun: no es lo mismo tener una variable, tener una direccion hacia ella o tener otro nombre para la misma variable.

Explicacion mas tecnica:
Se compara una `std::string`, un puntero a esa cadena y una referencia a la misma. El programa imprime direcciones y valores para mostrar que el puntero guarda una direccion y necesita desreferenciarse, mientras que la referencia actua como un alias directo.

### `CPPM01/ex03` - Weapon / HumanA / HumanB

Explicacion poco tecnica:
Aqui se ve como varios objetos pueden estar relacionados entre si. Un personaje usa un arma, y cuando el arma cambia, el comportamiento del personaje cambia tambien.

Explicacion mas tecnica:
Se practica la diferencia entre guardar una referencia (`HumanA`) y guardar un puntero (`HumanB`). `HumanA` necesita arma desde el principio; `HumanB` puede existir sin ella y recibirla despues. Esto ensena dependencias obligatorias frente a opcionales.

### `CPPM01/ex04` - Replacer

Explicacion poco tecnica:
El programa toma un archivo y crea otro cambiando un texto por otro. Es un ejercicio muy util para entender programas que procesan informacion de entrada y generan un resultado nuevo.

Explicacion mas tecnica:
Se usa lectura de archivos con `std::ifstream`, escritura con `std::ofstream`, acumulacion en `std::ostringstream` y reemplazo manual con `std::string::find` y `substr`. Tambien incluye validacion de errores mediante excepciones.

### `CPPM01/ex05` - Harl

Explicacion poco tecnica:
Este ejercicio ensena a decidir una accion segun una palabra clave. Es como montar un pequeno menu interno dentro de una clase.

Explicacion mas tecnica:
La clase `Harl` asocia niveles de texto con metodos miembros concretos. Para ello usa un array de cadenas y un array de punteros a funciones miembro, lo que permite despachar comportamiento sin una cadena larga de `if` independientes.

### `CPPM01/ex06` - Harl Filter

Explicacion poco tecnica:
Es una evolucion del ejercicio anterior: no solo eliges un mensaje, sino que a partir de cierto nivel se muestran varios, como un filtro por severidad.

Explicacion mas tecnica:
Se reutiliza el mapeo entre nivel y funcion, pero ahora se combina con un `switch` y `fallthrough` para ejecutar el nivel pedido y todos los superiores. Eso ensena una forma compacta de expresar comportamiento acumulativo.

## CPPM02

### `CPPM02/ex00` - Megaphone duplicado

Explicacion poco tecnica:
En esta carpeta hay otro ejercicio de transformacion de texto por consola, igual en concepto al `Megaphone` anterior.

Explicacion mas tecnica:
El codigo vuelve a trabajar con argumentos de linea de comandos y conversion a mayusculas caracter a caracter.

### `CPPM02/ex01` - PhoneBook duplicado

Explicacion poco tecnica:
Aqui aparece otra vez la agenda de contactos, por lo que vuelve a reforzar la idea de separar datos y logica del programa.

Explicacion mas tecnica:
Repite el uso de clases, capacidad fija, entrada por consola y salida tabulada.

### `CPPM02/ex02` - Account duplicado

Explicacion poco tecnica:
De nuevo se trabaja el seguimiento individual y global de varias cuentas.

Explicacion mas tecnica:
Repite el uso de miembros `static`, operaciones de deposito y retirada, y el mantenimiento de estadisticas compartidas por todos los objetos.

### `CPPM02/ex03` - BSP / Point / Fixed

Explicacion poco tecnica:
Este es el ejercicio que mas claramente cambia de tema: se empieza a trabajar con numeros y posiciones en un plano. La pregunta central es si un punto cae dentro o fuera de un triangulo.

Explicacion mas tecnica:
Se implementa un tipo `Fixed` para representar valores con precision fija y una clase `Point` con coordenadas inmutables. La funcion `bsp` usa signos de areas o productos cruzados para comprobar si un punto esta estrictamente dentro del triangulo, excluyendo bordes y vertices.

## CPPM03

### `CPPM03/ex00` - ClapTrap

Explicacion poco tecnica:
Aqui se crea un personaje simple con vida, energia y acciones. Es un paso natural para aprender a modelar entidades con estado y comportamiento.

Explicacion mas tecnica:
La clase `ClapTrap` encapsula atributos privados y metodos como `attack`, `takeDamage` y `beRepaired`. El ejercicio trabaja constructores, copia, asignacion y las reglas que impiden actuar cuando no queda vida o energia.

### `CPPM03/ex01` - ScavTrap

Explicacion poco tecnica:
Ahora aparece un personaje mas especializado que hereda lo basico del anterior y anade su propia identidad. La leccion es reutilizar en vez de empezar desde cero.

Explicacion mas tecnica:
Se introduce herencia publica con `ScavTrap : public ClapTrap`, redefinicion de `attack` y un metodo propio (`guardGate`). Tambien ayuda a observar el orden de construccion y destruccion entre clase base y derivada.

### `CPPM03/ex02` - FragTrap

Explicacion poco tecnica:
Se sigue ampliando la familia de personajes. Cada uno comparte una base comun, pero cambia sus valores y sus acciones especiales.

Explicacion mas tecnica:
`FragTrap` deriva de `ClapTrap`, ajusta sus estadisticas y agrega `highFivesGuys`. El ejercicio refuerza herencia, especializacion de comportamiento y reutilizacion de codigo de la clase base.

## CPPM04

### `CPPM04/ex00` - Animal, Dog, Cat

Explicacion poco tecnica:
Este ejercicio ensena que varios objetos pueden responder de forma distinta al mismo mensaje. Todos son animales, pero cada uno suena diferente.

Explicacion mas tecnica:
Se organiza una jerarquia con una clase base `Animal` y derivadas `Dog` y `Cat`. En esta implementacion concreta, `makeSound` no aparece virtual en la cabecera, asi que tambien sirve para entender la diferencia entre tener una interfaz comun y tener polimorfismo real.

### `CPPM04/ex01` - Brain y copia profunda

Explicacion poco tecnica:
Aqui se da un paso importante: algunos objetos contienen recursos propios internos, y copiar el objeto mal puede provocar que dos animales compartan la misma "cabeza" sin querer.

Explicacion mas tecnica:
`Dog` y `Cat` almacenan un `Brain` reservado dinamicamente. Por eso implementan constructor de copia, operador de asignacion y destructor para hacer copia profunda y liberar memoria correctamente. Es una aplicacion practica de la regla de tres.

### `CPPM04/ex02` - Animal abstracto

Explicacion poco tecnica:
La clase base deja de representar un animal "real" y pasa a ser una idea general. Ya no se crea un `Animal` generico; solo animales concretos.

Explicacion mas tecnica:
`Animal` declara `makeSound()` como funcion virtual pura, convirtiendose en clase abstracta. Esto obliga a las derivadas a implementar el comportamiento y permite polimorfismo correcto con destructor virtual.

## CPPM05

### `CPPM05/ex00` - Bureaucrat

Explicacion poco tecnica:
El foco esta en objetos que tienen reglas estrictas. Un burocrata no puede tener cualquier nivel: si se sale de los limites, el programa debe detectarlo.

Explicacion mas tecnica:
La clase `Bureaucrat` valida que `grade` este entre 1 y 150, y lanza excepciones especificas cuando se intenta construir o modificar el objeto fuera de ese rango. El ejercicio introduce control de errores con clases de excepcion propias.

### `CPPM05/ex01` - Form

Explicacion poco tecnica:
Ahora ya no basta con que exista un burocrata: tambien hay formularios que pueden o no firmarse dependiendo del nivel de quien lo intenta.

Explicacion mas tecnica:
Se conecta `Bureaucrat` con `Form` mediante `beSigned`. El formulario mantiene estado de firma y dos requisitos numericos: uno para firmar y otro para ejecutar. Se refuerzan colaboracion entre clases, inmutabilidad parcial y propagacion de excepciones.

### `CPPM05/ex02` - AForm y formularios concretos

Explicacion poco tecnica:
El sistema se vuelve mas realista: distintos formularios hacen cosas distintas, aunque todos comparten la misma idea general de firmarse y ejecutarse.

Explicacion mas tecnica:
`AForm` pasa a ser una base abstracta y las clases derivadas implementan acciones concretas: escribir un arbol ASCII en un archivo, intentar una robotomizacion aleatoria o conceder un perdon presidencial. Se practica polimorfismo, validacion previa a la ejecucion y especializacion por herencia.

### `CPPM05/ex03` - Intern

Explicacion poco tecnica:
Este ejercicio ensena a crear objetos sin que el resto del programa tenga que saber exactamente que clase concreta necesita construir. Es una forma de centralizar la "fabricacion".

Explicacion mas tecnica:
La clase `Intern` actua como una factoria: recibe el nombre textual de un formulario y devuelve una instancia del tipo adecuado. Internamente usa una tabla que relaciona nombres con funciones creadoras, evitando muchos `if` dispersos.

## CPPM06

### `CPPM06/ex00` - ScalarConverter

Explicacion poco tecnica:
El objetivo es tomar un dato escrito como texto y averiguar de que tipo parece ser, para despues mostrarlo en varios formatos distintos. Es una forma muy clara de aprender conversiones.

Explicacion mas tecnica:
`ScalarConverter` es una clase utilitaria con solo metodos estaticos. Intenta interpretar el literal como `char`, `int`, `float` o `double`, valida errores de parseo y rangos con `strtol`, `strtod`, `errno` y limites numericos, y despues muestra las conversiones posibles manejando casos especiales como `nan` o infinitos.

### `CPPM06/ex01` - Serialization

Explicacion poco tecnica:
Aqui se trabaja una idea muy concreta: convertir una direccion de memoria en un numero y luego recuperar esa misma direccion desde ese numero. No se copian los datos; solo se transforma el puntero para entender mejor como representar direcciones.

Explicacion mas tecnica:
`Serialization` se ha planteado como clase utilitaria con metodos estaticos `serialize` y `deserialize`, usando `reinterpret_cast` para convertir entre `Data*` y `uintptr_t`. La estructura `Data` no esta vacia y contiene al menos un `int` y un `std::string`, lo suficiente para cumplir el enunciado. En `main.cpp` hay una prueba muy simple que crea un objeto `Data`, lo serializa, lo deserializa y comprueba por salida que el puntero restaurado coincide con el original y que los campos siguen siendo accesibles. El ejercicio ya tiene tambien un `Makefile` minimo para compilar `main.cpp`, `Serialization.cpp` y `Data.cpp`.

## Resumen general de aprendizaje

Si se mira el repositorio en conjunto, la progresion de conceptos es esta:

- Entrada y salida por consola.
- Organizacion del codigo en clases y archivos separados.
- Memoria dinamica, punteros y referencias.
- Procesado de texto y archivos.
- Copia de objetos y gestion correcta de recursos.
- Herencia, especializacion y polimorfismo.
- Excepciones y validacion de reglas.
- Creacion flexible de objetos y conversion entre tipos.

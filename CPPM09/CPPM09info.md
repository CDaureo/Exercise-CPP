# CPPM09 - Documentación de ejercicios

## Resumen

Pulsa el nombre de un ejercicio para desplegarlo. En **ex02**, empieza por la explicación de las tarjetas; los detalles técnicos y la guía de defensa tienen sus propios desplegables.

El módulo trabaja con contenedores de la biblioteca estándar de C++. Están implementados `ex00`, Bitcoin Exchange; `ex01`, Reverse Polish Notation; y `ex02`, PmergeMe.

El código debe compilar con `c++ -Wall -Wextra -Werror -std=c++98`. Cada ejercicio requiere contenedores estándar; un contenedor utilizado no se puede reutilizar en los siguientes ejercicios del módulo. En `ex00` hemos elegido `std::map`; en `ex01`, `std::stack` sobre `std::list`. En `ex02` utilizamos `std::vector` y `std::deque`.

<details>
<summary><strong>ex00 - Bitcoin Exchange</strong></summary>

## ex00 - Bitcoin Exchange

### Objetivo y archivos

El programa `btc` calcula cuánto vale una cantidad de bitcoins en una fecha determinada. Multiplica la cantidad solicitada por el precio registrado para ese día o, si no existe, por el de la fecha anterior más cercana.

| Archivo | Función |
| --- | --- |
| [BitcoinExchange.hpp](ex00/BitcoinExchange.hpp) | Declaración de la clase, mapa privado e include guards. |
| [BitcoinExchange.cpp](ex00/BitcoinExchange.cpp) | Forma canónica, lectura de archivos, validaciones y cálculos. |
| [main.cpp](ex00/main.cpp) | Argumentos, carga de la base de datos y gestión de errores generales. |
| [Makefile](ex00/Makefile) | Compilación del ejecutable `btc`. |
| [data.csv](ex00/data.csv) | Base de datos de precios proporcionada para el ejercicio. |
| [input.txt](ex00/input.txt) | Consultas del ejemplo del enunciado. |

### 1. Distinguir los dos archivos de datos

`data.csv` contiene el precio de un bitcoin. Se carga automáticamente desde `main` mediante `loadDatabase("data.csv")`:

```text
date,exchange_rate
2011-01-03,0.3
```

El archivo pasado como argumento contiene las cantidades que queremos valorar:

```text
date | value
2011-01-03 | 3
```

En este ejemplo el resultado es `3 * 0.3 = 0.9`. No debemos ejecutar `./btc data.csv`: el CSV de precios no tiene el formato de las consultas. Además del nombre del campo, cambia el separador: coma para precios y `|` para consultas.

La implementación comprueba las cabeceras exactas. Elimina el retorno de carro final `\r` para aceptar archivos con saltos de línea de Windows, pero no elimina espacios adicionales en las cabeceras.

### 2. Guardar los precios en un mapa

```cpp
#include <map>
#include <string>

std::map<std::string, double> _rates;
```

La clave es la fecha y el valor asociado es el precio. Con fechas válidas en formato fijo `YYYY-MM-DD`, el orden de las cadenas coincide con el cronológico.

```cpp
double rate = convertToDouble(bc);
_rates[date] = rate;
```

Esta asignación inserta el registro. Si la fecha ya existe, sustituye su precio. Las búsquedas e inserciones del mapa tienen complejidad logarítmica respecto al número de registros.

### 3. Cargar el CSV: loadDatabase()

1. Abre `filename` con `std::ifstream rf(filename.c_str())`. En C++98 se utiliza `c_str()` para pasar la ruta al constructor del flujo.
2. Comprueba `is_open()`. Los flujos no lanzan excepciones por defecto ante este fallo, así que lanzamos `std::runtime_error` explícitamente.
3. Lee una única vez la cabecera y comprueba `date,exchange_rate`.
4. Recorre las líneas con `std::getline` y elimina un posible `\r` final.
5. Localiza la coma con `find`. `std::string::npos` significa que no se encontró.
6. Separa fecha y precio mediante `substr`, valida la fecha y convierte el precio.
7. Guarda el resultado en `_rates`.
8. Comprueba los errores de lectura con `bad()` y rechaza una base de datos sin precios.

Los errores de carga llegan al `catch` de `main`. Así no se procesan consultas si la carga falla.

### 4. Validar fechas: isValidDate()

Primero se exige una longitud de diez caracteres y guiones en las posiciones 4 y 7. Los índices de las cadenas empiezan en cero:

```text
Fecha:     2 0 1 2 - 0 2 - 2 9
Posición:  0 1 2 3 4 5 6 7 8 9
```

El bucle omite esas dos posiciones con `continue` y exige dígitos en las restantes. Restar `'0'` convierte un carácter numérico en su valor: `'7' - '0'` produce `7`.

Se extraen año, mes y día. Se exige año mayor que cero, mes entre 1 y 12 y día entre 1 y el máximo del mes. Hay que validar `month > 12`, no `day > 12`, antes de consultar `daysInMonth[month - 1]`.

Febrero tiene 29 días si se cumple:

```cpp
(year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)
```

`2012-02-29` es válida; `2011-02-29` y `2011-04-31` no lo son. Una fecha anterior al primer precio puede ser válida como fecha, aunque después no se encuentre un precio aplicable.

### 5. Convertir texto a número

`convertToDouble()` valida precios del CSV. `parseValue()` valida cantidades de las consultas.

```cpp
std::istringstream ss(text);
double value;
if (!(ss >> value))
    throw std::runtime_error("bad input => " + text);
ss >> std::ws;
if (!ss.eof())
    throw std::runtime_error("bad input => " + text);
```

En un flujo, `>>` extrae datos: aquí interpreta texto como un `double`. La expresión `!(ss >> value)` detecta que la extracción ha fallado. `<<` inserta datos en un flujo, por ejemplo `std::cout << value`.

`std::ws` consume los espacios en blanco restantes. Después, `eof()` permite comprobar que no quede texto: `12abc` no debe aceptarse como `12`.

Los precios deben ser finitos y no negativos; no tienen el límite de 1000. Las cantidades deben estar entre 0 y 1000, incluidos. `parseValue()` diferencia negativos y cantidades demasiado grandes. NaN se rechaza porque no es igual a sí mismo; la conversión también puede rechazarlo antes. Si un número desborda la conversión a `double`, la implementación actual informa de `bad input`.

Las auxiliares están definidas en el `.cpp` con `static`, lo que limita su enlace a ese archivo. No son métodos de la clase.

### 6. Procesar consultas: processInput()

1. Abre el archivo recibido por argumento y comprueba la cabecera `date | value`.
2. Lee cada línea y elimina el posible `\r` final.
3. Comprueba que haya exactamente un separador `|`.
4. Separa los campos y aplica `trim()`, que elimina espacios exteriores mediante `find_first_not_of`, `find_last_not_of` y `substr`.
5. Valida la fecha con `isValidDate()` y la cantidad con `parseValue()`.
6. Busca el precio aplicable en el mapa.
7. Muestra la fecha solicitada, la cantidad y su producto por el precio.

Cada línea tiene su propio `try/catch` dentro del `while`. Una consulta incorrecta imprime `Error: ...` y se continúa con la siguiente.

### 7. Encontrar la fecha exacta o la anterior

```cpp
std::map<std::string, double>::const_iterator it =
    _rates.upper_bound(date);

if (it == _rates.begin())
    throw std::runtime_error("No exchange rate available for " + date);

--it;
double rate = it->second;
```

`upper_bound(date)` devuelve la primera fecha estrictamente posterior a la solicitada. Al retroceder una posición obtenemos la fecha exacta o la anterior más cercana.

| Fechas disponibles | Fecha solicitada | Fecha utilizada |
| --- | --- | --- |
| 2011-01-03 y 2011-01-09 | 2011-01-03 | 2011-01-03 |
| 2011-01-03 y 2011-01-09 | 2011-01-05 | 2011-01-03 |
| 2011-01-03 y 2011-01-09 | 2011-01-10 | 2011-01-09 |
| 2011-01-03 y 2011-01-09 | 2011-01-01 | Error: no hay precio anterior o igual. |

Si devuelve `end()` y el mapa no está vacío, se puede retroceder al último registro. Nunca se debe retroceder desde `begin()`; la comprobación también cubre el mapa vacío. `it->first` es la fecha almacenada y `it->second` su precio. Se usa un `const_iterator` porque `processInput()` no modifica el mapa.

### 8. Forma canónica y errores

La clase define constructor por defecto, constructor de copia, operador de asignación y destructor en el `.cpp`. La cabecera contiene declaraciones e include guards para evitar inclusiones duplicadas.

El constructor de copia inicializa `_rates` con `other._rates`. El operador comprueba la autoasignación, copia el mapa y devuelve `*this` por referencia para permitir asignaciones encadenadas. Los objetos estándar gestionan su memoria; no necesitamos `new` ni `delete`.

Los errores generales de apertura, cabecera o carga llegan a `main`, que imprime el mensaje y devuelve `1`. Los errores de consultas se capturan dentro del bucle: si el archivo termina de procesarse, el programa devuelve `0` aunque algunas líneas sean inválidas. Los mensajes usan `std::cout` y terminan con salto de línea, según las reglas del módulo.

### 9. Compilar y ejecutar

Desde la raíz del repositorio:

```bash
cd CPPM09/ex00
make
./btc input.txt
```

`data.csv` debe estar en el directorio de ejecución, porque `main` utiliza una ruta relativa.

Salida del ejemplo incluido:

```text
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
```

El Makefile genera `btc` con `-Wall -Wextra -Werror -std=c++98`. Compila los `.cpp` a `.o` y enlaza cuando corresponde; ejecutar `make` de nuevo sin cambios no recompila ni vuelve a enlazar. Los objetos dependen también de la cabecera y del Makefile.

| Regla | Acción |
| --- | --- |
| `make` / `make all` / `make btc` | Construir el ejecutable. |
| `make clean` | Borrar los objetos. |
| `make fclean` | Borrar objetos y ejecutable. |
| `make re` | Limpiar y reconstruir. |

### 10. Comprobaciones realizadas y casos para practicar

Se ha comprobado la compilación C++98 con las flags obligatorias, la ausencia de reenlazado sin cambios, el ejemplo del enunciado, límites 0 y 1000, fechas inválidas y bisiestas, texto después de un número, fechas anteriores a la base de datos y propagación de errores de apertura. Estas comprobaciones se hicieron durante el desarrollo; no hay una suite automatizada incluida en `ex00`.

Para practicar, añade consultas con campos vacíos, varios `|`, una fecha entre dos registros o una fecha posterior al último precio. Observa cómo una línea errónea no impide procesar las siguientes.

</details>

<details>
<summary><strong>ex01 - Reverse Polish Notation (RPN)</strong></summary>

## ex01 - Reverse Polish Notation (RPN)

### Objetivo y archivos

El programa `RPN` evalúa una expresión en notación polaca inversa: primero se escriben los operandos y después el operador. Por ejemplo, `8 2 -` significa `8 - 2` y devuelve `6`. No necesita paréntesis ni reglas de prioridad; el orden de los tokens determina las operaciones.

| Archivo | Función |
| --- | --- |
| [RPN.hpp](ex01/RPN.hpp) | Declaración de la clase, pila privada y forma canónica. |
| [RPN.cpp](ex01/RPN.cpp) | Lectura de tokens, evaluación y validación aritmética. |
| [main.cpp](ex01/main.cpp) | Validación de argumentos, salida del resultado y captura de excepciones. |
| [Makefile](ex01/Makefile) | Compilación C++98 del ejecutable `RPN`. |

### 1. Contenedor elegido: una pila

```cpp
std::stack<int, std::list<int> > _operands;
```

`std::stack` es un adaptador de contenedor con comportamiento LIFO: el último valor introducido es el primero que se extrae. Aquí utiliza explícitamente `std::list` como almacenamiento, en lugar del `std::deque` predeterminado. No reutiliza el mapa de `ex00` y deja libres `vector` y `deque` para el siguiente ejercicio. En C++98 se separan los dos cierres de plantilla: `> >`.

**LIFO (Last In, First Out)** significa que el último en entrar es el primero en salir. También puedes llamarlo **FILO (First In, Last Out)**: el primero en entrar es el último en salir.

En nuestra pila:

```text
push(8) → [8]
push(2) → [8, 2]

pop()   → elimina 2; queda [8]
pop()   → elimina 8; queda vacía
```

Es como una pila de platos: el último que colocas encima es el primero que retiras. `pop()` elimina el elemento, pero no devuelve su valor; para guardarlo hay que consultar `top()` antes de llamar a `pop()`.

| Operación | Función |
| --- | --- |
| `push(value)` | Añadir un valor a la cima. |
| `top()` | Consultar el valor de la cima sin retirarlo. |
| `pop()` | Retirar la cima; no devuelve el valor. |
| `size()` | Consultar cuántos valores hay. |
| `empty()` | Comprobar si la pila está vacía. |

### 2. Leer y validar los tokens

`evaluate()` vacía la pila al comenzar, de modo que se pueda reutilizar el mismo objeto incluso después de un error. Después utiliza `std::istringstream` y `input >> token` para leer elementos separados por espacios en blanco. Se permiten espacios repetidos, tabulaciones y saltos de línea.

Cada token debe tener un único carácter: un dígito entre `0` y `9`, o uno de los operadores `+ - / *`. La expresión `'7' - '0'` convierte el carácter en el entero `7`. Se rechazan números de varias cifras, números negativos de entrada, decimales, paréntesis, letras y tokens pegados como `12+`. Sí se permiten resultados intermedios negativos o mayores que nueve.

### 3. Evaluar de izquierda a derecha

Al encontrar un dígito se guarda en la pila. Para un operador hacen falta al menos dos valores: se extrae primero el operando derecho y después el izquierdo, se calcula el resultado y se vuelve a introducir.

Ejemplo con `8 2 - 3 *`, mostrando la pila desde la base hasta la cima:

| Token | Pila después de procesarlo | Acción |
| --- | --- | --- |
| `8` | `[8]` | Guardar 8. |
| `2` | `[8, 2]` | Guardar 2. |
| `-` | `[6]` | Calcular `8 - 2`. |
| `3` | `[6, 3]` | Guardar 3. |
| `*` | `[18]` | Calcular `6 * 3`. |

El orden importa especialmente en resta y división. Al terminar debe quedar exactamente un valor: una pila vacía o con varios operandos indica una expresión incorrecta. El coste es lineal respecto al tamaño de la entrada y el espacio adicional depende del máximo número de operandos pendientes.

### 4. División, límites y errores

Los cálculos utilizan `int`. La división es entera y trunca hacia cero: `7 2 /` produce `3` y `0 7 - 2 /` produce `-3`. El código ajusta el cociente si una implementación C++98 redondea la división negativa hacia abajo.

`calculate()` comprueba la división por cero y el caso especial del mínimo `int` dividido entre `-1`. También comprueba los límites de suma, resta y multiplicación **antes** de ejecutar la operación, utilizando `std::numeric_limits<int>`. Así evita el comportamiento indefinido del desbordamiento con signo; los resultados no están limitados a un dígito, pero deben caber en `int`.

Para comprobar la multiplicación sin calcular un producto que podría desbordar, se divide el límite entre uno de los operandos. `minimum` y `maximum` representan los límites de `int`:

| Signos | Resultado | Condición que detecta desbordamiento |
| --- | --- | --- |
| `left > 0`, `right > 0` | Positivo | `left > maximum / right` |
| `left > 0`, `right < 0` | Negativo | `right < minimum / left` |
| `left < 0`, `right > 0` | Negativo | `left < minimum / right` |
| `left < 0`, `right < 0` | Positivo | `left < maximum / right` |

En el último caso se invierte el sentido de la desigualdad al dividir entre un número negativo. Los `&&` evalúan de izquierda a derecha y se detienen cuando una condición es falsa: las comprobaciones de signo garantizan que nunca se divida entre cero. Si alguno de los operandos es cero, ninguna fila se cumple y el producto es cero. Si se detecta desbordamiento, se lanza `std::overflow_error`; de lo contrario, se devuelve `left * right`.

Los fallos lanzan excepciones estándar. `main` las captura, escribe `Error: ...` en `std::cerr` y devuelve `1`; no imprime un resultado parcial. En caso de éxito, escribe únicamente el resultado y un salto de línea en `std::cout`, y devuelve `0`. Se exige exactamente un argumento.

### 5. Forma canónica

La clase define constructor por defecto, constructor de copia, asignación y destructor. Las copias duplican la pila; el operador de asignación comprueba la autoasignación y devuelve `*this`. Los contenedores gestionan su memoria automáticamente. La función privada estática `calculate()` realiza una operación sin necesitar acceder al estado de un objeto.

### 6. Compilar y ejecutar

Desde la raíz del repositorio:

```bash
cd CPPM09/ex01
make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "7 7 * 7 -"
./RPN "1 2 * 2 / 2 * 2 4 - +"
```

Los resultados son, respectivamente, `42`, `42` y `0`. Las comillas son necesarias para enviar la expresión completa como un argumento y evitar que la shell interprete `*`.

El Makefile incluye `all`, `clean`, `fclean` y `re`, tiene dependencias de la cabecera y no recompila ni reenlaza si no hay cambios.

### 7. Comprobaciones y casos para practicar

Se comprueban los ejemplos del enunciado, el orden de resta y división, resultados negativos, división entera, espacios adicionales y el dígito cero. Los casos de error incluyen argumentos incorrectos, entrada vacía, operandos sobrantes o insuficientes, tokens inválidos, división por cero y desbordamiento. Las pruebas auxiliares de desarrollo no forman parte de los cuatro archivos de entrega.

| Expresión | Resultado esperado |
| --- | --- |
| `8 2 -` | `6` |
| `8 2 /` | `4` |
| `0 7 - 2 /` | `-3` |
| `9 9 *` | `81` |
| `0` | `0` |
| `1 2` | Error: sobran operandos. |
| `1 +` | Error: faltan operandos. |
| `1 0 /` | Error: división por cero. |
| `(1 + 1)` | Error: token inválido. |
| `10 2 +` | Error: número de entrada de varias cifras. |

</details>

<details>
<summary><strong>ex02 - PmergeMe</strong></summary>

## ex02 - PmergeMe

### Empieza aquí: vamos a ordenar tarjetas

Imagina que tienes cinco tarjetas encima de una mesa:

```text
[3] [5] [9] [7] [4]
```

Queremos dejarlas de menor a mayor:

```text
[3] [4] [5] [7] [9]
```

Eso es lo que hace el programa. **Los números no cambian: sólo cambiamos su posición.** El ejercicio nos obliga a seguir una receta concreta para ordenarlos. Esa receta se llama **Ford-Johnson**.

De momento olvida el reloj, los nombres de las librerías y las fórmulas. Primero vamos a entender la receta.

#### Paso 1. Juntar las tarjetas de dos en dos

Formamos parejas siguiendo el orden de entrada:

```text
Pareja 1: [3] [5]
Pareja 2: [9] [7]
Sobra:   [4]
```

En cada pareja preguntamos: «¿Cuál de los dos números es mayor?».

```text
             Pequeño    Grande
Pareja 1:       3          5
Pareja 2:       7          9
```

En el código, los grandes se llaman `winners` y los pequeños `losers`. Son sólo nombres: un pequeño de una pareja puede ser mayor que el grande de otra.

**Lo que hemos aprendido con estas comparaciones:** el `3` debe ir antes del `5`, y el `7` antes del `9`. Guardamos esa información para aprovecharla después.

#### Paso 2. Ordenar los grandes sin olvidar sus parejas

Miramos solamente los grandes:

```text
[5] [9]
```

En este ejemplo ya están ordenados. Si no lo estuvieran, aplicaríamos **la misma receta** a esos grandes: volver a formar parejas, ordenar sus grandes e insertar sus pequeños. Eso se llama **recursión**: resolver una versión más pequeña del mismo problema.

¿Por qué termina? Porque cada vez quedan aproximadamente la mitad de las tarjetas. Cuando queda una, ya está ordenada y no hace falta seguir.

Aunque ordenemos los grandes, cada uno debe recordar quién era su pequeño. Piensa en una cuerda imaginaria que une cada pareja:

```text
3 unido a 5
7 unido a 9
```

#### Paso 3. Empezar una fila que ya sabemos que está ordenada

Ponemos los grandes ordenados en la mesa:

```text
[5] [9]
```

El pequeño del primer grande es `3`. Como sabemos que `3` va antes de `5`, lo colocamos directamente al principio:

```text
[3] [5] [9]
```

Esta fila se llama `chain` en el código. Siempre la mantenemos ordenada. Todavía nos quedan por colocar `7` y `4`.

#### Paso 4. Elegir cuál de los pendientes colocar primero

A los pequeños y a la tarjeta que sobró les ponemos etiquetas de posición:

```text
b1 = 3   → pareja de 5; ya está colocado
b2 = 7   → pareja de 9
b3 = 4   → tarjeta que sobró, sin pareja
```

**Ojo: `b3` no significa el número 3.** Significa «el tercer pendiente». En este ejemplo su valor es `4`.

La receta dice que ahora coloquemos primero `b3` y después `b2`. Por tanto, primero colocamos el `4` y luego el `7`.

Con más tarjetas, la receta continúa así:

```text
b1 ya colocado
b3, b2
b5, b4
b11, b10, b9, b8, b7, b6
...
```

Este orden se obtiene de los números de **Jacobsthal**. Por ahora puedes entenderlo como una lista de turnos diseñada para limitar las preguntas que necesitamos hacer al buscar el sitio de las tarjetas. La fórmula se explica más abajo; primero importa entender qué decide: **qué pendiente insertamos a continuación**.

#### Paso 5. Buscar el sitio del 4

Tenemos:

```text
Fila:     [3] [5] [9]
A colocar: 4
```

Miramos el centro: `5`. Como `4` es menor que `5`, su sitio está a la izquierda. Allí está `3`; como `4` es mayor que `3`, lo colocamos después de él:

```text
[3] [4] [5] [9]
```

Eso es una **búsqueda binaria**: mirar en el centro y descartar la mitad donde el número no puede ir. Como cuando buscas una palabra en un diccionario y decides si debes mirar antes o después de la página abierta.

Esta búsqueda funciona porque la fila ya está ordenada. Si las tarjetas estuvieran mezcladas, no podríamos descartar una mitad con esa información.

#### Paso 6. Buscar el sitio del 7 aprovechando su pareja

Ahora tenemos:

```text
Fila:     [3] [4] [5] [9]
A colocar: 7
```

Recordamos que `7` era el pequeño de la pareja `(7, 9)`. **Ya sabemos que debe ir antes del 9.** No necesitamos volver a preguntarlo.

Por eso buscamos su sitio mirando sólo este trozo:

```text
[3] [4] [5] | [9]
 buscamos    pareja: no hace falta compararla
```

El `7` es mayor que `4`, y después comprobamos que es mayor que `5`. Lo insertamos justo antes del `9`:

```text
[3] [4] [5] [7] [9]
```

¡Ya no queda ninguna tarjeta por colocar!

#### Toda la receta en una frase

**Formamos parejas, ordenamos sus grandes y colocamos los pequeños en sus huecos, aprovechando lo que ya sabemos de cada pareja.**

Jacobsthal decide **el turno** de cada pequeño. La búsqueda binaria decide **su sitio**. Son dos tareas diferentes.

#### ¿Cómo se traduce la mesa al código?

| En nuestra explicación | En el programa |
| --- | --- |
| Una tarjeta con un número y una etiqueta propia. | `Element`: contiene `value` e `id`. |
| Los grandes de las parejas. | `winners`. |
| Los pequeños en el orden en que formamos las parejas. | `losers`. |
| Una foto del orden original de los grandes, para recuperar sus parejas. | `originalWinners`. |
| Los pequeños organizados según sus grandes, más el que sobra. | `pending`. Incluye también el primero, aunque se coloque directamente. |
| La fila ordenada que vamos completando. | `chain`. |
| Repetir la receta con los grandes. | `sortVector(winners)` o `sortDeque(winners)`. |
| Los extremos del trozo donde buscamos. | `left` y `right`. |
| La tarjeta del centro de ese trozo. | `chain[middle]`. |
| Colocar una tarjeta en el hueco encontrado. | `chain.insert(...)`. |

#### ¿Por qué cada tarjeta tiene un `id`?

Imagina que hay dos tarjetas con el número `5`. Tienen el mismo valor, pero son tarjetas distintas y pueden pertenecer a parejas distintas.

Les ponemos una etiqueta según su posición al entrar:

```text
Entrada: [5] [2] [5] [1]
Etiqueta: 0   1   2   3
```

La etiqueta viaja con la tarjeta. Así podemos distinguir «el 5 con etiqueta 0» de «el 5 con etiqueta 2». **Ordenamos por el valor; usamos la etiqueta para reconocer la tarjeta y encontrar su pareja.**

#### ¿Y qué son `vector` y `deque`?

Son dos formas que C++ nos da para guardar nuestras tarjetas en memoria.

- `vector` las guarda en una zona contigua: como una fila de casillas seguidas.
- `deque` las organiza en bloques: como varias filas pequeñas que podemos recorrer como si fueran una sola colección.

Los dos permiten pedir «dame la tarjeta de la posición 3». El ejercicio pide realizar la receta con ambos y medir cuánto tarda cada uno. No mezclamos los contenedores para hacer una sola ordenación: ejecutamos una ordenación completa con cada uno.

#### ¿Qué hacen los cuatro archivos?

| Archivo | Explicación sencilla |
| --- | --- |
| `main.cpp` | Arranca el programa, pide que se ejecute y muestra un error si algo falla. |
| `PmergeMe.hpp` | Presenta nuestra clase: qué datos tiene y qué funciones existen. |
| `PmergeMe.cpp` | Contiene las instrucciones de verdad: leer números, ordenarlos y mostrar los tiempos. |
| `Makefile` | Indica cómo construir el ejecutable a partir de los archivos de C++. |

El recorrido es:

```text
main
  → crea un PmergeMe
  → llama a run
      → valida y guarda los números en vector
      → ordena el vector y mide su tiempo
      → valida y guarda los números en deque
      → ordena el deque y mide su tiempo
      → comprueba que los resultados coincidan
      → muestra Before, After y los dos tiempos
```

Si un argumento es incorrecto, el programa lanza una excepción: una señal de que no puede continuar normalmente. `main` la recoge y escribe el error.

#### Comprueba si has entendido la idea

Antes de memorizar código, intenta responder:

1. En la pareja `(8, 2)`, ¿quién va a `winners` y quién a `losers`?
2. Si sabemos que `2 <= 8`, ¿necesitamos buscar un sitio para el `2` después del `8`?
3. ¿Jacobsthal decide dónde colocar una tarjeta o cuál colocamos primero?
4. ¿Por qué podemos descartar media fila durante una búsqueda binaria?

<details>
<summary>Ver las respuestas</summary>

1. `8` va a `winners` y `2` a `losers`.
2. No. Podemos insertarlo antes de su pareja.
3. Decide cuál colocamos primero. La búsqueda binaria encuentra el sitio.
4. Porque la fila ya está ordenada: la comparación con el centro permite saber qué mitad descartar.

</details>

**Siguiente paso:** abre los detalles del ejercicio para relacionar esta explicación con el algoritmo. Después abre la guía de defensa para estudiar las librerías, las funciones y la sintaxis de C++.


<details>
<summary>Detalles del ejercicio: contenedores, algoritmo, tiempos y pruebas</summary>

### Objetivo y archivos

Ordenar los enteros positivos recibidos por argumentos utilizando **Ford-Johnson (merge-insertion sort)** con dos contenedores diferentes y comparar sus tiempos. No se utiliza `std::sort` en la implementación.

| Archivo | Función |
| --- | --- |
| [PmergeMe.hpp](ex02/PmergeMe.hpp) | Clase, elementos con identidad, contenedores y declaraciones. |
| [PmergeMe.cpp](ex02/PmergeMe.cpp) | Validación, dos implementaciones de Ford-Johnson, medición y salida. |
| [main.cpp](ex02/main.cpp) | Ejecutar el programa y capturar errores. |
| [Makefile](ex02/Makefile) | Compilar `PmergeMe` con C++98 y las flags obligatorias. |

### 1. Qué contenedores usamos

Usamos `std::vector<Element>` y `std::deque<Element>`. No reutilizamos `map`, `stack` ni `list` de los ejercicios anteriores.

| Propiedad | `std::vector` | `std::deque` |
| --- | --- | --- |
| Almacenamiento | Elementos contiguos. | Almacenamiento organizado en bloques. |
| Acceso por índice | Constante, con `operator[]`. | Constante, con `operator[]`. |
| Inserción en medio | Lineal: desplaza elementos. | Lineal: puede desplazar elementos. |
| Reserva anticipada | `reserve()` evita realojos al cargar la entrada. | No dispone de `reserve()`. |

El mismo algoritmo puede tardar distinto según cómo se almacenen y muevan los datos. No hay un ganador garantizado para todas las entradas. `sortVector()` y `sortDeque()` implementan el algoritmo por separado; no hay una función genérica compartida de ordenación. Los auxiliares de cada versión utilizan su mismo tipo de contenedor.

### 2. Validación de los argumentos

Cada argumento debe representar un único entero entre `1` e `INT_MAX`, ambos incluidos. Se aceptan un `+` inicial, ceros a la izquierda y duplicados. Se rechazan cero, negativos, decimales, letras, argumentos vacíos y espacios dentro de un argumento. Por eso se ejecuta `./PmergeMe 3 5 9`, sin agrupar toda la secuencia entre comillas.

`parsePositive()` recorre los caracteres, convierte cada dígito con `*text - '0'` y acumula `value * 10 + digit`. Antes de calcularlo comprueba:

```cpp
value > (std::numeric_limits<int>::max() - digit) / 10
```

Si se cumple, el siguiente paso desbordaría `int`. Comprobarlo antes evita comportamiento indefinido. `main` captura las excepciones, imprime `Error: ...` en `std::cerr` y devuelve `1`. Una ejecución correcta devuelve `0`.

### 3. Ford-Johnson paso a paso

Llamaremos `ai` al mayor de una pareja y `bi` al menor: sabemos que `bi <= ai`.

1. Agrupar los elementos de dos en dos y comparar los miembros de cada pareja. Guardar los mayores en `winners` y los menores en `losers`.
2. Ordenar **recursivamente con Ford-Johnson** los mayores. El caso base es una secuencia con menos de dos elementos.
3. Reconstruir `pending`: los menores deben seguir el nuevo orden de sus respectivas parejas. Si sobra un elemento impar, añadirlo al final de los pendientes.
4. Construir la cadena principal `b1, a1, a2, ...`. Está ordenada: los mayores ya lo están y sabemos que `b1 <= a1`. Añadir `b1` no necesita otra comparación de valores.
5. Insertar los pendientes restantes mediante búsqueda binaria, siguiendo el orden de Jacobsthal.

No basta con ordenar parejas e insertar sus menores de izquierda a derecha: la recursión, la conservación de las parejas, los límites de búsqueda y el orden de inserción forman parte de esta implementación.

### 4. Para qué sirve el identificador

`Element` contiene `value`, el número que ordenamos, e `id`, su posición original. Un identificador no cambia cuando movemos un elemento.

Al ordenar `winners` recursivamente, necesitamos recuperar el menor que acompañaba a cada mayor. `originalWinners` conserva el orden original de los mayores y `losers` conserva sus menores en las mismas posiciones. Buscamos el identificador del mayor para recuperar su pareja.

También usamos el identificador para encontrar la posición actual de la pareja en la cadena después de cada inserción. Buscar sólo por valor sería ambiguo con duplicados. No guardamos iteradores entre inserciones: las modificaciones de los contenedores pueden invalidarlos.

### 5. Jacobsthal: por qué no insertar en orden normal

Los números de Jacobsthal cumplen `J(n) = J(n-1) + 2 * J(n-2)` y empiezan por `0, 1, 1, 3, 5, 11, 21, ...`. Tras colocar `b1`, tomamos límites `3, 5, 11, 21, ...` y recorremos cada bloque hacia atrás:

```text
b3, b2 | b5, b4 | b11, b10, b9, b8, b7, b6 | ...
```

Si faltan elementos para completar un bloque, empezamos por el último pendiente existente. Por ejemplo, con seis pendientes: `b3, b2, b5, b4, b6`.

La búsqueda binaria sobre `2^k - 1` elementos necesita como máximo `k` comparaciones para decidir la posición de inserción. El orden de Jacobsthal aprovecha esos tamaños para limitar el peor número de comparaciones. La implementación comprueba además que la generación del siguiente límite no desborde `std::size_t`.

Referencia técnica con descripción del algoritmo y del orden de inserción: [implementación y explicación de merge-insertion-sort](https://github.com/decidedlyso/merge-insertion-sort).

### 6. Búsqueda binaria limitada por la pareja

Para insertar `bi`, ya sabemos que `bi <= ai`; basta buscar en el prefijo anterior a `ai`. La posición de `ai` es el extremo exclusivo de la búsqueda y también una posición de inserción válida. El elemento impar no tiene pareja, así que utiliza toda la cadena como rango.

En el código, `left` empieza en cero y `right` en la posición de la pareja, o en `chain.size()` si no existe. Se compara con el elemento central, descartando la mitad correspondiente hasta que `left == right`. Entonces se inserta ahí. Esta búsqueda encuentra la primera posición cuyo valor no es menor que el pendiente, como `lower_bound`.

### 7. Ejemplo: `3 5 9 7 4`

```text
Parejas (menor, mayor): (3, 5), (7, 9)
Elemento impar:        4
Mayores ordenados:     5, 9
Pendientes:            b1=3, b2=7, b3=4
Cadena inicial:        3, 5, 9
Insertar b3=4:         3, 4, 5, 9
Insertar b2=7:         3, 4, 5, 7, 9
```

Insertamos `4` antes que `7` por el orden `b3, b2`. Para `4` usamos toda la cadena porque es el impar; para `7` buscamos únicamente antes de su pareja `9`.

### 8. Qué medimos y qué complejidad tiene

Cada medición con `std::clock()` incluye la limpieza del contenedor, lectura y validación de argumentos, carga, ordenación, copias y auxiliares internos. Cada contenedor vuelve a leer los mismos argumentos. La impresión y la comprobación final de igualdad entre resultados quedan fuera de los tiempos; no forman parte de la ordenación. La construcción inicial del objeto y su destrucción final tampoco están cronometradas.

Convertimos los ticks a microsegundos con `ticks * 1000000.0 / CLOCKS_PER_SEC` y mostramos tres decimales. Es tiempo de CPU. Los decimales no aumentan la resolución real del reloj: para entradas pequeñas puede mostrar cero o tiempos iguales. Para comparar conviene usar entradas grandes y repetir ejecuciones.

Ford-Johnson reduce las **comparaciones entre valores**, cuyo crecimiento es `O(n log n)`. Esta implementación tiene un coste temporal global `O(n²)`: localizar parejas por identificador y desplazar elementos al insertar añade trabajo lineal repetido. No hay que confundir pocas comparaciones con poco tiempo total. Los auxiliares ocupan `O(n)` espacio adicional en conjunto, con una profundidad recursiva `O(log n)`.

### 9. Compilar, ejecutar y comprobar

Desde la raíz de este módulo:

```bash
cd ex02
make
./PmergeMe 3 5 9 7 4
./PmergeMe 8 8 2 1
./PmergeMe $(shuf -i 1-100000 -n 3000)
./PmergeMe -1 2
```

La salida correcta contiene cuatro líneas: `Before`, `After`, tiempo de `std::vector` y tiempo de `std::deque`. Se muestra la secuencia completa. El Makefile ofrece `all`, `clean`, `fclean` y `re`, y no reenlaza cuando no hay cambios.

Durante el desarrollo se verificaron todas las permutaciones de tamaños 1 a 8 en ambos contenedores. Se instrumentaron las comparaciones de valores para comprobar los máximos `0, 1, 3, 5, 7, 10, 13, 16`, respectivamente. También se compararon resultados con una ordenación de referencia para entradas aleatorias, repetidas, ordenadas, inversas y de hasta 10 000 elementos, además de argumentos inválidos y límites de `int`. Los auxiliares de prueba están fuera de los archivos de entrega.

### 10. Qué aprendemos

- Elegir contenedores según sus operaciones, almacenamiento y coste.
- Dividir un problema mediante recursión y conservar relaciones entre elementos que cambian de posición.
- Implementar búsqueda binaria con límites exclusivos y aprovechar información de comparaciones anteriores.
- Entender cómo Jacobsthal determina un orden de inserción que reduce comparaciones.
- Distinguir comparaciones, desplazamientos, memoria y tiempo real de ejecución.
- Validar números antes de que se produzca un desbordamiento y propagar errores con excepciones.
- Usar la forma canónica: constructor, copia, asignación y destructor. Los contenedores gestionan su propia memoria sin `new` ni `delete` manuales.

</details>

<details>
<summary>Guía de defensa: librerías, funciones y código explicado paso a paso</summary>

### 11. Guía de defensa: de dónde sale cada cosa

Esta guía sigue el código entregado. Primero conviene distinguir tres orígenes:

- **El lenguaje C++:** `class`, `struct`, `int`, `const`, `static`, `if`, `for`, `throw`, referencias y punteros. No requieren una librería.
- **La biblioteca estándar:** `std::vector`, `std::cout`, `std::clock`, etc. Se declaran en cabeceras que incluimos con `#include`.
- **Nuestro código:** `PmergeMe`, `Element`, `run`, `parsePositive`, `sortVector` y `sortDeque`. Los hemos definido nosotros.

`std` es el espacio de nombres de la biblioteca estándar. `::` permite indicar a qué espacio o clase pertenece un nombre. `std::vector` pertenece a `std`; `PmergeMe::run` pertenece a nuestra clase.

#### 11.1. Cabeceras, una por una

Una cabecera proporciona declaraciones para que el compilador conozca tipos y funciones. `#include` es una directiva del preprocesador: incorpora el contenido de la cabecera antes de compilar.

| Cabecera | Qué usamos de ella | Dónde y para qué |
| --- | --- | --- |
| `"PmergeMe.hpp"` | Nuestra clase `PmergeMe`. | En ambos `.cpp`, para conocer su declaración. |
| `<cstddef>` | `std::size_t`. | En el `.hpp`, para tamaños e identificadores sin signo. |
| `<vector>` | `std::vector<T>`. | En el `.hpp`, para el contenedor vectorial y sus operaciones. |
| `<deque>` | `std::deque<T>`. | En el `.hpp`, para el contenedor de bloques y sus operaciones. |
| `<ctime>` | `std::clock()`, `std::clock_t`, `CLOCKS_PER_SEC`. | En `PmergeMe.cpp`, para medir tiempo de CPU y convertirlo a segundos. |
| `<iomanip>` | `std::setprecision(3)`. | En `PmergeMe.cpp`, para configurar la precisión de impresión. |
| `<iostream>` | `std::cout`, `std::cerr`; acceso a los manipuladores de flujo. | Salida normal y salida de errores. |
| `<limits>` | `std::numeric_limits<T>::max()`. | En `PmergeMe.cpp`, para consultar el máximo de `int` y de `std::size_t`. |
| `<stdexcept>` | `std::invalid_argument`, `std::out_of_range`, `std::runtime_error`, `std::logic_error`. | En `PmergeMe.cpp`, para lanzar errores con un mensaje. |
| `<exception>` | `std::exception`. | En `main.cpp`, para capturar los errores estándar mediante su clase base. |

Precisión sobre los manipuladores: `std::fixed` se declara en `<ios>` y `std::endl` en `<ostream>`, cabeceras disponibles al incluir `<iostream>`. `std::fixed` selecciona formato decimal fijo; en ese formato, `std::setprecision(3)` pide tres cifras después del punto. `std::endl` escribe un salto de línea y fuerza el vaciado del flujo. `'\n'` sólo representa el salto de línea.

`CLOCKS_PER_SEC` es una macro, por eso no lleva `std::`. Es el factor para convertir ticks del reloj a segundos; no garantiza por sí solo la resolución efectiva de la medición. `INT_MAX` se menciona en los mensajes, pero el código no utiliza esa macro de `<climits>`: consulta el máximo con `<limits>`.

Las comillas de `#include "PmergeMe.hpp"` se usan para nuestra cabecera; los ángulos de `#include <vector>` para una cabecera estándar. En este ejercicio no necesitamos instalar librerías externas.

#### 11.2. Qué contiene el `.hpp`

```cpp
#ifndef PMERGEME_HPP
#define PMERGEME_HPP
// Declaración de la clase.
#endif
```

Son protecciones contra inclusiones repetidas: si el preprocesador ya ha definido `PMERGEME_HPP`, no vuelve a incorporar esa declaración en la misma unidad de compilación. No son funciones ni pertenecen a una librería.

`class PmergeMe` define nuestro tipo. `private` oculta detalles de implementación; `public` expone las operaciones que puede utilizar `main`. Así, `main` puede llamar a `run()`, pero no a `sortVector()` directamente.

```cpp
struct Element
{
    int value;
    std::size_t id;
    Element(int number = 0, std::size_t identity = 0);
};
```

`Element` es un tipo creado por nosotros y anidado dentro de `PmergeMe`. Un `struct` tiene miembros públicos por defecto, pero aquí el nombre del tipo está dentro de la zona privada de `PmergeMe`.

- `value`: entero que queremos ordenar.
- `id`: posición original que identifica el elemento, aunque haya valores repetidos.
- `Element(...)`: constructor; los `= 0` son argumentos por defecto, utilizados si no proporcionamos esos argumentos.

`std::size_t` es un tipo entero sin signo adecuado para tamaños e índices. Su anchura depende de la plataforma; no conviene afirmar que siempre es `unsigned int`. Como no representa negativos, cuidamos condiciones como `index > inserted` antes de decrementar.

```cpp
std::vector<Element> _vector;
std::deque<Element> _deque;
```

Los ángulos indican un argumento de plantilla: pedimos un contenedor cuyos elementos son de tipo `Element`. El guion bajo inicial de estos dos nombres es una convención para reconocer atributos; no les da ningún comportamiento especial.

```cpp
static void sortVector(std::vector<Element> &values);
```

`static` en un método significa que no necesita una instancia ni tiene puntero `this`. Sólo trabaja con sus parámetros y variables locales. `void` significa que no devuelve un valor. `&values` es una referencia al contenedor original: ordenar `values` modifica el contenedor que recibió la llamada, sin copiarlo al entrar.

#### 11.3. Constructores, copia, asignación y destructor

```cpp
PmergeMe::Element::Element(int number, std::size_t identity)
    : value(number), id(identity) {}
```

Los `::` indican que definimos el constructor de `Element`, que pertenece a `PmergeMe`. Lo que aparece después de `:` es la lista de inicialización: construye directamente `value` e `id` con los argumentos recibidos.

La forma canónica de `PmergeMe` tiene cuatro piezas:

| Código | Cuándo se utiliza | Qué hace aquí |
| --- | --- | --- |
| `PmergeMe()` | `PmergeMe a;` | Construye los contenedores vacíos automáticamente. |
| `PmergeMe(const PmergeMe &other)` | `PmergeMe b(a);` | Construye copias de los dos contenedores de `a`. |
| `operator=(const PmergeMe &other)` | `b = a;` con ambos ya construidos. | Asigna los dos contenedores. |
| `~PmergeMe()` | Cuando termina la vida del objeto. | Sus contenedores se destruyen automáticamente. |

`const PmergeMe &other` recibe el objeto de origen por referencia y prohíbe modificarlo a través de esa referencia. `this` es un puntero al objeto actual; `&other` obtiene la dirección del objeto recibido. Aquí `&` obtiene una dirección, mientras que en la declaración del parámetro indica una referencia.

`if (this != &other)` evita trabajo si hacemos `a = a`. `return *this` devuelve una referencia al objeto actual; `*this` desreferencia el puntero. Esto permite expresiones como `a = b = c`.

Aunque el destructor tenga cuerpo vacío, después se ejecutan los destructores de los atributos. Los contenedores liberan sus recursos: es gestión automática de recursos, habitualmente llamada RAII. No necesitamos escribir `delete`.

### 12. Recorrido de ejecución: desde `main` hasta la salida

#### 12.1. `argc` y `argv`

```cpp
int main(int argc, char **argv)
```

`main` es el punto de entrada del programa. Los nombres `argc` y `argv` son convenciones; son parámetros, no funciones de una librería.

Para `./PmergeMe 3 5 9`:

```text
argc = 4
argv[0] = "./PmergeMe"
argv[1] = "3"
argv[2] = "5"
argv[3] = "9"
argv[4] = puntero nulo
```

`argc` cuenta también el nombre del programa. `char **argv` permite acceder a una secuencia de punteros a cadenas de caracteres; cada cadena termina con el carácter nulo `'\0'`. El bucle empieza en `1` para saltarse el nombre del ejecutable.

`PmergeMe sorter;` construye el objeto y `sorter.run(argc, argv);` llama a su método. El punto accede a un miembro de un objeto.

#### 12.2. `try`, `throw`, `catch` y `what()`

Estas tres palabras forman parte del lenguaje:

- `try`: delimita el trabajo cuyos errores queremos capturar.
- `throw`: lanza una excepción y abandona la ejecución normal de ese punto.
- `catch`: recibe una excepción compatible con el tipo declarado.

`catch (const std::exception &error)` captura por referencia constante para no copiar ni recortar el objeto de excepción. Las excepciones que lanzamos derivan de `std::exception`, por lo que esta captura puede recibirlas. `error.what()` es un método virtual que proporciona un mensaje como cadena de caracteres.

Al propagarse una excepción se destruyen los objetos locales ya construidos. Por eso los contenedores temporales tampoco necesitan una limpieza manual en el `catch`.

`std::cerr << ...` escribe en la salida de errores. `return 1` comunica fallo al entorno que ejecutó el programa; `return 0` comunica éxito. No son los números que estamos ordenando.

#### 12.3. Lectura de `parsePositive()`

```cpp
static int parsePositive(const char *text);
```

Recibe un puntero a caracteres que no vamos a modificar y devuelve un `int`. `const char *` permite mover el puntero local, pero no cambiar los caracteres mediante él. No es lo mismo que un puntero constante.

| Fragmento | Significado |
| --- | --- |
| `*text` | Lee el carácter señalado actualmente. |
| `if (*text == '+') ++text;` | Omite un signo positivo inicial. |
| `*text == '\0'` | Detecta el final de la cadena: rechaza `""` y `"+"`. |
| `for (; *text; ++text)` | Recorre hasta el carácter nulo; la inicialización del `for` está vacía. |
| `*text < '0' || *text > '9'` | Rechaza cualquier carácter que no sea un dígito decimal. |
| `*text - '0'` | Convierte el carácter del dígito a su valor numérico. |
| `value = value * 10 + digit` | Desplaza lo acumulado una cifra decimal y añade el nuevo dígito. |
| `value == 0` | Rechaza cero porque pedimos enteros estrictamente positivos. |

Ejemplo con `"123"`: el acumulador pasa de `0` a `1`, luego a `12`, y finalmente a `123`. El carácter `'0'` es un dígito; `'\0'` marca el final de una cadena y no es el mismo carácter.

La comprobación de desbordamiento sale de exigir `value * 10 + digit <= máximo`. Reordenando matemáticamente, necesitamos `value <= (máximo - digit) / 10`. Evaluamos esta segunda forma antes de multiplicar. Para enteros no negativos, la división entera proporciona el límite correcto.

`std::numeric_limits<int>` es una especialización de una plantilla de la biblioteca estándar; `max()` es su función estática que devuelve el mayor `int` representable. No asumimos un tamaño fijo para `int`.

#### 12.4. Lectura de `run()`

`run()` coordina el programa:

1. Rechaza que falten números con `argc < 2`.
2. Inicia el reloj para `vector`, vacía datos anteriores y reserva espacio.
3. Convierte cada argumento y construye `Element(valor, i - 1)`; el primer número recibe el identificador `0`.
4. Ordena el vector y registra el instante final.
5. Repite lectura y ordenación con `deque`, usando un reloj independiente.
6. Comprueba que el reloj no haya fallado y que ambos resultados coincidan en valores.
7. Imprime entrada, resultado y tiempos.

La comprobación de igualdad de resultados es una defensa interna, pero no demuestra por sí sola que estén ordenados: dos algoritmos con el mismo error podrían coincidir. Por eso las pruebas de desarrollo también compararon con una ordenación de referencia.

`Before` se imprime desde `argv`, que nunca modificamos. No necesitamos conservar una tercera copia de los números. Si recibimos `+03`, esa escritura aparece en `Before`, mientras que el resultado numérico se imprime como `3`.

### 13. Operaciones de los contenedores: qué hace cada una

Estos métodos pertenecen a `std::vector` y `std::deque`; no los hemos programado nosotros. `reserve()` sólo se utiliza con `vector`.

| Expresión | Qué hace | Detalle para la defensa |
| --- | --- | --- |
| `values.size()` | Devuelve el número de elementos. | No es el número de bytes ni la capacidad reservada. |
| `values[i]` | Accede al elemento en posición `i`. | Los índices empiezan en cero; `operator[]` no comprueba límites. |
| `values.back()` | Accede al último elemento. | Sólo es válido si el contenedor no está vacío. |
| `winners.push_back(element)` | Añade una copia del elemento al final. | Aumenta el tamaño en uno. |
| `_vector.reserve(n)` | Reserva capacidad para al menos `n` elementos. | No crea `n` elementos; el tamaño no cambia. |
| `_vector.clear()` | Elimina todos los elementos. | El vector conserva su capacidad; queda con tamaño cero. |
| `chain.begin()` | Devuelve un iterador al inicio. | Es una posición del contenedor, no el valor del primer elemento. |
| `chain.begin() + left` | Avanza `left` posiciones. | Ambos contenedores tienen iteradores de acceso aleatorio. |
| `chain.insert(pos, element)` | Inserta antes de `pos`. | Si `pos` es el final, añade al final; puede invalidar iteradores. |
| `values.swap(chain)` | Intercambia el contenido de los contenedores. | `values` recibe el resultado y `chain` recibe el contenido anterior. |

`std::vector<Element> chain(winners);` llama al constructor de copia del contenedor. `chain` y `winners` son independientes: insertar en uno no modifica el otro. Lo mismo ocurre con `deque`.

Un iterador es un objeto que representa una posición y permite recorrer un contenedor. No debemos decir que siempre es un puntero: los iteradores de `deque` funcionan sobre almacenamiento por bloques.

Después de `values.swap(chain)`, al salir de la función se destruye `chain`, que ahora contiene los datos antiguos de `values`. Con los asignadores estándar utilizados aquí, intercambiar los contenedores evita copiar de nuevo todos los elementos del resultado.

### 14. Lectura detallada de `sortVector()` y `sortDeque()`

Ambas funciones tienen la misma lógica. Puedes estudiar `sortVector()` y después explicar que `sortDeque()` utiliza exclusivamente `deque` también para sus auxiliares. La repetición es intencionada por la recomendación del enunciado de implementar cada contenedor por separado.

#### 14.1. Diccionario de variables

| Nombre | Significado dentro de una llamada recursiva |
| --- | --- |
| `values` | Secuencia que esa llamada debe ordenar. |
| `winners` | Mayores de las parejas; después se ordenan recursivamente. |
| `losers` | Menores de las parejas, en el orden original de formación. |
| `originalWinners` | Copia de los mayores antes de ordenarlos. Permite recuperar las parejas. |
| `pending` | Menores reordenados según sus mayores, más el impar si existe. |
| `chain` | Cadena ordenada que vamos construyendo. |
| `pair` | Índice de una pareja en el orden original. Es una variable, no `std::pair`. |
| `inserted` | Cantidad de pendientes ya incorporados al terminar un bloque; empieza en uno por `b1`. |
| `previousJacob` | Límite anterior utilizado en la recurrencia de Jacobsthal. |
| `jacob` | Límite del bloque que vamos a procesar. |
| `end` | Último número de pendiente del bloque, limitado por los pendientes existentes. No es el método `end()`. |
| `index` | Número del pendiente en notación desde uno; recorre el bloque hacia atrás. |
| `current` | Índice real del pendiente: `index - 1`, porque C++ empieza en cero. |
| `left`, `right` | Límites de la búsqueda binaria. `right` es exclusivo. |
| `middle` | Posición central que se compara en un paso de búsqueda. |
| `maximum`, `next` | Máximo representable por `size_t` y siguiente límite de Jacobsthal. |

Los nombres `winners` y `losers` sólo significan mayor y menor dentro de una pareja, no máximo y mínimo de toda la entrada.

#### 14.2. Caso base y formación de parejas

```cpp
if (values.size() < 2)
    return;
```

Con cero o un elemento la secuencia ya está ordenada. Este caso detiene la recursión.

```cpp
for (std::size_t i = 0; i + 1 < values.size(); i += 2)
```

Avanza por parejas: posiciones `0 y 1`, `2 y 3`, etc. La condición exige que exista también el segundo miembro. En cada pareja hacemos una comparación de valores y guardamos uno en cada auxiliar. En caso de igualdad, la rama `else` guarda el segundo como mayor y el primero como menor; sigue siendo válido porque menor significa aquí «menor o igual».

Cada llamada recursiva recibe aproximadamente la mitad de los elementos. Sus variables locales son propias: el `winners` de una llamada no es el mismo objeto que el de la siguiente.

#### 14.3. Cómo se recuperan las parejas después de la recursión

Ejemplo con `8 3 2 6`:

```text
Elementos originales (valor, id): (8,0), (3,1), (2,2), (6,3)
originalWinners:                  (8,0), (6,3)
losers:                           (3,1), (2,2)
winners después de ordenar:      (6,3), (8,0)
```

Para el primer mayor ordenado, `(6,3)`, buscamos el identificador `3` en `originalWinners`. Está en la posición `1`, por lo que recuperamos `losers[1]`, el `(2,2)`. Para el mayor `(8,0)` recuperamos `(3,1)`. Así `pending` queda con valores `2, 3`, manteniendo las relaciones `2 <= 6` y `3 <= 8`.

El bucle que busca el identificador no compara valores para ordenarlos. Su final está garantizado por una propiedad del algoritmo: `winners` contiene exactamente los mismos elementos que `originalWinners`, sólo cambia el orden.

```cpp
if (values.size() % 2 != 0)
    pending.push_back(values.back());
```

`%` es el operador resto. Si el tamaño es impar, el último elemento quedó sin pareja y lo añadimos al final de los pendientes. `back()` es seguro aquí porque el caso base ya descartó tamaños menores que dos.

#### 14.4. Cadena inicial y bloques de Jacobsthal

`chain` empieza como una copia de los mayores ordenados. Insertamos `pending[0]` al principio: es el menor asociado al primer mayor, así que no rompe el orden. Por eso `inserted` empieza en `1`.

```cpp
const std::size_t end = jacob < pending.size()
    ? jacob : pending.size();
```

`condición ? valorSiCierto : valorSiFalso` es el operador condicional del lenguaje. Esta expresión calcula el menor entre el límite de Jacobsthal y el número de pendientes disponibles, sin utilizar una función de biblioteca.

Con seis pendientes, los bloques quedan así:

| `inserted` al empezar | `jacob` | `end` | Pendientes procesados |
| --- | --- | --- | --- |
| 1 | 3 | 3 | `b3`, `b2`. |
| 3 | 5 | 5 | `b5`, `b4`. |
| 5 | 11 | 6 | `b6`. |

Dentro del bloque `inserted` no aumenta en cada inserción: conserva el límite inferior del bloque. Al terminar hacemos `inserted = end`. `break` abandona el `while` cuando ya se han incorporado todos los pendientes.

El cálculo del siguiente límite comprueba primero `previousJacob > (maximum - jacob) / 2`. Es la misma idea de validación previa que usamos con los enteros: no calcular `jacob + 2 * previousJacob` si desbordaría. En ese caso utilizamos `pending.size()` para terminar con un último bloque.

#### 14.5. Localizar el límite y hacer la búsqueda binaria

Si `current < winners.size()`, el pendiente tiene pareja. La buscamos en `chain` mediante su identificador, porque las inserciones anteriores pueden haber desplazado su posición. Si no tiene pareja, es el impar y dejamos `right = chain.size()`.

El rango de búsqueda es `[left, right)`: incluye `left` y excluye `right`. Excluir la pareja de las comparaciones no impide insertar justo delante de ella.

```cpp
const std::size_t middle = left + (right - left) / 2;
```

Es el punto medio. Esta forma evita sumar directamente `left + right`, que podría desbordar para índices muy grandes. La división entera descarta la parte fraccionaria.

- Si `chain[middle].value < pending[current].value`, el pendiente debe ir más a la derecha: `left = middle + 1`.
- En caso contrario, puede ir en `middle` o antes: `right = middle`.
- Cuando ambos límites coinciden, hemos encontrado la posición de inserción.

Traza al insertar `7` en `[3, 4, 5, 9]`, siendo `9` su pareja:

```text
left=0, right=3 → middle=1 → 4 < 7 → left=2
left=2, right=3 → middle=2 → 5 < 7 → left=3
left=3, right=3 → fin; insertar en la posición 3
Resultado: [3, 4, 5, 7, 9]
```

No se vuelve a comparar `7` con `9`: la relación se conoce desde que se formó la pareja. Los identificadores nunca se usan para desempatar valores; permiten localizar elementos. Se conservan los duplicados, pero no prometemos una ordenación estable de sus identidades.

### 15. Reloj, conversiones y salida

```cpp
const std::clock_t vectorStart = std::clock();
```

`std::clock_t` es el tipo que utiliza el reloj. `std::clock()` devuelve una medida del tiempo de CPU consumido por el programa; obtenemos la duración del tramo restando dos lecturas. No mide directamente el tiempo de espera real de un reloj de pared.

`std::clock_t(-1)` convierte `-1` al tipo del reloj y representa su indicador de fallo. Los `||` de la comprobación significan «o»: basta con que una lectura falle para lanzar un error.

```cpp
(static_cast<double>(vectorEnd)
    - static_cast<double>(vectorStart)) * 1000000.0 / CLOCKS_PER_SEC
```

`static_cast<double>` es una conversión explícita del lenguaje, no una función de biblioteca. Convertimos las lecturas a coma flotante antes de restar; dividimos por los ticks por segundo y multiplicamos por un millón para obtener microsegundos. Por ejemplo, 50 ticks con un factor de 1 000 000 ticks por segundo representan 50 microsegundos.

`double` es un tipo numérico del lenguaje que permite representar fracciones. No hace que el reloj mida con mayor resolución. Los tiempos pueden variar entre ejecuciones y no debemos prometer que siempre se verá una diferencia con entradas pequeñas.

En `std::cout << valor`, `<<` es el operador de inserción del flujo. Aquí no significa desplazamiento de bits: el comportamiento depende de los tipos de sus operandos. Las operaciones se pueden encadenar porque devuelven el propio flujo.

### 16. Makefile: también hay que saber explicarlo

El Makefile lo interpreta `make`, no el compilador de C++. Sus variables y reglas no pertenecen a una librería de C++.

| Fragmento | Significado |
| --- | --- |
| `NAME = PmergeMe` | Nombre del ejecutable. |
| `CXX = c++` | Compilador utilizado. |
| `-Wall -Wextra` | Activa grupos de avisos del compilador. No significa literalmente todos los avisos posibles. |
| `-Werror` | Trata los avisos como errores. |
| `-std=c++98` | Selecciona el estándar C++98. |
| `SRCS` | Lista de archivos fuente `.cpp`. |
| `$(SRCS:.cpp=.o)` | Sustituye el sufijo `.cpp` por `.o` para formar la lista de objetos. |
| `all: $(NAME)` | El objetivo predeterminado necesita el ejecutable. |
| `$(NAME): $(OBJS)` | El ejecutable depende de los objetos; la receta los enlaza. |
| `%.o: %.cpp PmergeMe.hpp Makefile` | Regla para compilar cada objeto; también depende de la cabecera y del Makefile. |
| `-c` | Compila a objeto sin enlazar todavía. |
| `$<` | Primera dependencia de la regla: el `.cpp` correspondiente. |
| `$@` | Nombre del objetivo que se está construyendo. |
| `-o` | Indica el nombre del archivo de salida. |
| `$(RM)` | Variable de `make` cuyo valor habitual es `rm -f`. |
| `clean` | Elimina los objetos generados. |
| `fclean` | Ejecuta `clean` y elimina también el ejecutable. |
| `re` | Ejecuta `fclean` y después llama a `$(MAKE) all`. |
| `.PHONY` | Declara objetivos que son acciones, no archivos a comprobar por fecha. |

Las recetas empiezan con un tabulador. `make` compara las fechas de modificación de objetivos y dependencias para decidir qué reconstruir. Los `.o` contienen código compilado; el enlazado los une en el ejecutable. El `.hpp` se incluye en los `.cpp`, no se compila como un programa independiente.

### 17. Preguntas habituales de defensa

**¿Por qué utilizas dos contenedores?** Porque lo exige el ejercicio y permite observar cómo cambia el tiempo de un mismo algoritmo según el almacenamiento. Los anteriores ya usan `map` y `stack` sobre `list`, por lo que aquí elegimos `vector` y `deque`.

**¿Por qué no basta con un merge sort o un insertion sort?** Porque el enunciado exige Ford-Johnson. Aquí hay emparejamiento, ordenación recursiva de mayores, conservación de parejas e inserción binaria en orden de Jacobsthal.

**¿Dónde está la recursión?** En `sortVector(winners)` y `sortDeque(winners)`. Cada llamada ordena aproximadamente la mitad de los elementos y termina cuando el tamaño es menor que dos.

**¿Por qué se puede colocar el primer menor directamente al principio?** Porque pertenece al menor de los mayores ordenados: `b1 <= a1 <= a2 <= ...`.

**¿Qué ocurre con el elemento impar?** Se incorpora como último pendiente, participa en el orden de Jacobsthal y, al no tener pareja, busca su posición en toda la cadena disponible.

**¿Para qué sirve Jacobsthal?** Para decidir el orden de inserción y controlar el tamaño de los prefijos en los que se hace búsqueda binaria, reduciendo las comparaciones en el peor caso. No sirve para ordenar directamente los valores.

**¿Qué pasa si hay duplicados?** Los aceptamos y conservamos. Cada elemento tiene un identificador distinto, por lo que seguimos encontrando su pareja aunque los valores coincidan.

**¿Por qué no guardas un iterador a la pareja?** Porque las inserciones pueden invalidarlo. Guardamos la identidad y buscamos su posición actual antes de cada inserción.

**¿Todo el algoritmo es `O(n log n)`?** Las comparaciones de valores crecen así, pero esta implementación realiza búsquedas lineales de identidades e inserciones con desplazamientos: su tiempo global es `O(n²)`. No se deben mezclar ambas medidas.

**¿Por qué no usas `std::sort` o `std::lower_bound`?** La ordenación requerida está implementada por nosotros. También escribimos la búsqueda binaria para hacer visible su rango y funcionamiento; no es una prohibición general de esas funciones.

**¿Qué mide el tiempo mostrado?** La lectura, validación, carga y ordenación de cada contenedor, incluidos los auxiliares del algoritmo. No mide la impresión ni la comparación final de resultados.

**¿Cómo sabes que funciona?** Se probaron resultados contra una referencia, errores, duplicados y entradas grandes. Además, las permutaciones hasta ocho elementos se instrumentaron para comprobar el máximo de comparaciones entre valores; no se contaron ahí las comparaciones de identificadores.

**¿Qué podrías mejorar?** La recuperación de parejas por búsqueda lineal añade coste. Se podría estudiar otra representación que conserve sus relaciones con menos búsquedas, sin perder el orden de inserción ni los límites de Ford-Johnson. La versión actual prioriza que esos pasos sean explícitos.

### 18. Cómo estudiarlo para explicarlo con tus palabras

1. Empieza por `main` y sigue una ejecución de `./PmergeMe 3 5 9 7 4` hasta `run`.
2. Simula `parsePositive` con `"123"`, `"+"`, `"0"` y un número que supere el máximo.
3. Dibuja las parejas de `8 3 2 6` y explica por qué hay que reordenar los menores cuando cambian de orden los mayores.
4. Repite el ejemplo de cinco elementos y señala dónde se inserta el impar.
5. Escribe en papel los bloques `3,2 | 5,4 | 11,10,9,8,7,6` y traduce sus números a índices desde cero.
6. Traza `left`, `right` y `middle` durante una inserción, explicando por qué la pareja queda fuera del rango.
7. Termina explicando las diferencias entre los contenedores, las unidades del reloj y el coste de mover elementos.

Una presentación inicial posible: «El programa valida enteros positivos y los ordena dos veces, con vector y deque. En cada versión agrupa por parejas, ordena recursivamente los mayores e inserta los menores mediante búsqueda binaria en orden de Jacobsthal. Conserva identificadores para encontrar las parejas, incluso con duplicados. Finalmente muestra la entrada, el resultado y el tiempo de procesamiento de cada contenedor».

</details>

</details>

## Referencias

[Enunciado del módulo](09.subject.pdf) · [Volver a la guía general](../GUIA_EJERCICIOS.md) · [README](../README.md)

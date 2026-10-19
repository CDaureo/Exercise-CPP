# CPPM09 - Documentación de ejercicios

## Resumen

El módulo trabaja con contenedores de la biblioteca estándar de C++. Están implementados `ex00`, Bitcoin Exchange, y `ex01`, Reverse Polish Notation. El ejercicio `ex02` queda pendiente.

El código debe compilar con `c++ -Wall -Wextra -Werror -std=c++98`. Cada ejercicio requiere contenedores estándar; un contenedor utilizado no se puede reutilizar en los siguientes ejercicios del módulo. En `ex00` hemos elegido `std::map`; en `ex01`, `std::stack` sobre `std::list`. Reservamos `std::vector` y `std::deque` para `ex02`.

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

## Referencias

[Enunciado del módulo](09.subject.pdf) · [Volver a la guía general](../GUIA_EJERCICIOS.md) · [README](../README.md)

# CPP Module 05 — Repetition and Exceptions

Proyecto de 42 (Common Core, C++98) que introduce el manejo de **excepciones**
en C++: cómo lanzarlas, capturarlas y diseñarlas bien, usando como excusa un
mundo de burócratas, formularios y sellos.

## De qué va la historia

Hay dos tipos de personajes:

- **Bureaucrat** (burócrata): tiene un nombre y un **grado** del 1 al 150,
  donde **1 es el grado más alto** (el jefe) y **150 el más bajo** (el
  becario). Firmar y ejecutar formularios requiere tener un grado
  suficientemente alto (número suficientemente bajo).
- **Form / AForm** (formulario): tiene un nombre, si está firmado o no, y dos
  grados mínimos: uno para poder **firmarlo** y otro para poder **ejecutarlo**.

El hilo conductor es: un burócrata firma un formulario, y si tiene grado
suficiente, luego puede ejecutarlo. Si no tiene grado suficiente en algún
paso, salta una excepción con un mensaje explicativo en vez de reventar el
programa.

## Ejercicio 00 — Bureaucrat

Se crea la clase `Bureaucrat`:
- Nombre constante (no cambia nunca) y grado (1-150).
- Si intentas crear uno con grado fuera de rango, el constructor lanza
  `GradeTooHighException` (si pides un grado mejor que 1, ej. 0) o
  `GradeTooLowException` (si pides un grado peor que 150).
- `incrementGrade()` / `decrementGrade()`: suben o bajan el grado (recuerda,
  "incrementar" el grado significa que el número **baja**, porque 1 es el
  mejor).
- Sobrecarga del operador `<<` para poder hacer `std::cout << bureaucrata`.

## Ejercicio 01 — Form

Se añade la clase `Form`:
- Nombre constante, booleano de "firmado", y dos grados constantes (firmar /
  ejecutar), todos **privados**.
- `Form::beSigned(Bureaucrat)`: si el burócrata tiene grado suficiente, marca
  el formulario como firmado; si no, lanza `GradeTooLowException`.
- `Bureaucrat::signForm(Form)`: intenta firmar y, según el resultado,
  imprime `"<burócrata> signed <form>"` o
  `"<burócrata> couldn't sign <form> because <motivo>"`.

## Ejercicio 02 — Formularios concretos

`Form` pasa a ser una clase **abstracta** y se renombra `AForm`. A partir de
ella se crean tres formularios concretos, cada uno con sus propios grados
mínimos y su propia acción al ejecutarse:

| Formulario                | Grado firmar | Grado ejecutar | Qué hace |
|----------------------------|:---:|:---:|---|
| `ShrubberyCreationForm`    | 145 | 137 | Crea el fichero `<target>_shrubbery` con un árbol ASCII dentro |
| `RobotomyRequestForm`      | 72  | 45  | Hace "ruido de taladro" y robotiza al target con un 50% de probabilidad |
| `PresidentialPardonForm`   | 25  | 5   | Indica que el target ha sido perdonado por el presidente |

Se añade `AForm::execute()` (comprueba que esté firmado y que el grado sea
suficiente) y `Bureaucrat::executeForm()`, que imprime si la ejecución tuvo
éxito o no.

## Ejercicio 03 — Intern

Los burócratas no deberían rellenar formularios ellos mismos para eso están
los becarios. Se crea la clase `Intern`, que no tiene nombre ni grado, y solo
sabe hacer una cosa: `makeForm(nombreDeForm, target)`, que crea y devuelve el
formulario correspondiente. La particularidad pedida por el enunciado es que
esta función **no puede usar una cadena de if/else** para decidir qué
formulario crear: hay que usar un array de punteros a función miembro
(`Form* (Intern::*)(std::string)`), y elegir la función correcta según el
nombre pedido.

## Reglas generales del módulo (por si se te olvidan en la defensa)

- Compilar con `c++ -Wall -Wextra -Werror`, y debe seguir compilando también
  con `-std=c++98` (nada de C++11 en adelante).
- **Prohibido**: STL (`vector`, `map`, `<algorithm>`...) hasta los módulos 08
  y 09, `using namespace`, `friend`, y las funciones `*printf()`, `*alloc()`,
  `free()`.
- Todas las clases (salvo las de excepción) deben seguir la **forma canónica
  ortodoxa**: constructor por defecto, constructor de copia, `operator=` y
  destructor.
- Ninguna función puede implementarse en el `.hpp` (salvo templates).
- Las excepciones deben heredar de `std::exception` para poder capturarse
  como `catch (std::exception &e)`.

## Estado actual del proyecto (revisión rápida)

En una revisión del repo tal como está subido, **ex01, ex02 y ex03 no
compilan** (Makefiles con archivos de otro módulo pegados por error, o rutas
de `include` que no coinciden con la estructura de carpetas real), y hay
varios bugs de lógica en ex02/ex03 (grados de firma/ejecución mal copiados,
lectura fuera de los límites de un array en `Intern::makeForm`, mensajes de
éxito que se imprimen antes de comprobar si la operación falló). El detalle
completo de cada fallo, archivo por archivo, está en la conversación donde se
pidió esta revisión — conviene corregirlos antes de subir el proyecto a
evaluación, porque un Makefile que no compila pone la nota del ejercicio a 0
directamente.

# 🎓 Sistema de Gestión Académica

Aplicación de consola desarrollada en **C++** para administrar información básica de alumnos, maestros, administradores, materias y calificaciones.

El proyecto está diseñado para practicar conceptos fundamentales de **Programación Orientada a Objetos (POO)**, como herencia, encapsulamiento, polimorfismo, sobrecarga de operadores, constructores, manejo de arreglos de objetos y archivos.

## 📌 Descripción

El sistema permite gestionar diferentes tipos de personas dentro de una institución educativa:

- 👨‍🎓 **Alumnos**
- 👨‍🏫 **Maestros**
- 👨‍💼 **Administradores**
- 📚 **Materias**
- 📝 **Calificaciones**

Además, el programa cuenta con un sistema de **persistencia de datos mediante archivos de texto**, permitiendo guardar y cargar automáticamente la información.

Toda la interacción se realiza mediante un **menú de consola**, donde el usuario puede registrar, consultar, modificar, eliminar, comparar, importar y exportar información.

---

## ✨ Características

### 👨‍🎓 Gestión de alumnos

El sistema permite:

- Registrar alumnos.
- Mostrar un alumno específico.
- Mostrar todos los alumnos.
- Buscar alumnos por nombre.
- Modificar información de un alumno.
- Eliminar alumnos.
- Calcular el promedio de edades de los alumnos.

Cada alumno cuenta con:

| Dato | Descripción |
|---|---|
| 👤 Nombre | Nombre del alumno |
| 🎂 Edad | Edad del alumno |
| 🪪 Matrícula | Identificador del alumno |
| 📚 Materias | Materias inscritas |
| 📝 Calificaciones | Notas obtenidas |

---

### 📚 Gestión de materias

Cada alumno puede tener hasta **10 materias**.

Para cada materia se almacena:

- Nombre de la materia.
- Clave de la materia.

Ejemplo:

Materia: Programacion Clave: PROG101


---

### 📝 Gestión de calificaciones

El sistema permite registrar calificaciones asociadas a las materias de cada alumno.

Las calificaciones deben encontrarse dentro del rango:

0 - 10


Antes de registrar una calificación, el programa verifica que la materia correspondiente exista.

---

### 📖 Historial académico

Es posible consultar el historial académico de un alumno.

El sistema muestra:

Historial de Carlos

Materia: Programacion Clave: PROG101 Nota: 9.5


De esta manera, las calificaciones se relacionan con la materia mediante su clave.

---

### 👨‍🏫 Maestros

Los maestros heredan las características básicas de la clase `Persona`.

Además, cuentan con:

- Nombre
- Edad
- Especialidad

---

### 👨‍💼 Administradores

Los administradores también heredan de la clase `Persona`.

Además, cuentan con:

- Nombre
- Edad
- Departamento

---

## 💾 Persistencia de datos

Una de las principales mejoras de esta versión es la incorporación de **archivos de texto**.

El programa puede guardar y recuperar información para que los datos no se pierdan al cerrar el programa.

### 📁 Archivos utilizados

El sistema utiliza los siguientes archivos:

📄 alumnos.txt 📄 maestros.txt 📄 administradores.txt


### 👨‍🎓 alumnos.txt

Almacena información de los alumnos utilizando el formato:

Nombre|Edad|Matricula


Ejemplo:

Carlos|20|A001 Ana|21|A002 Luis|19|A003


### 👨‍🏫 maestros.txt

Almacena:

Nombre|Edad|Especialidad


Ejemplo:

Juan|40|Programacion Maria|35|Matematicas


### 👨‍💼 administradores.txt

Almacena:

Nombre|Edad|Departamento


Ejemplo:

Pedro|45|ControlEscolar Laura|38|Administracion


---

## 🔄 Cargar datos automáticamente

Al iniciar el programa se ejecuta:

cargarDatos();


Esta función busca los archivos:

alumnos.txt maestros.txt administradores.txt


Si existen, la información se carga automáticamente en el programa.

Esto permite conservar los datos entre diferentes ejecuciones.

---

## 💾 Guardar datos automáticamente

Cuando el usuario selecciona la opción **Salir**, el programa ejecuta:

guardarDatos();


Esta función guarda la información actual en los archivos correspondientes.

El flujo es:

INICIO │ ▼ cargarDatos() │ ▼ Mostrar menú │ ▼ Trabajar con datos │ ▼ Salir │ ▼ guardarDatos() │ ▼ FIN


---

## 📤 Exportar datos

El programa permite exportar alumnos, maestros y administradores a un archivo personalizado.

La opción correspondiente es:

    Exportar Datos.


El usuario introduce el nombre del archivo:

Nombre del archivo a exportar: respaldo.txt


El archivo generado utiliza el siguiente formato:

ALUMNO|Carlos|20|A001 MAESTRO|Juan|40|Programacion ADMINISTRADOR|Pedro|45|ControlEscolar


Cada registro comienza indicando su tipo.

---

## 📥 Importar datos

También es posible cargar información desde un archivo externo.

La opción correspondiente es:

    Importar Datos.


El programa solicita el nombre del archivo:

Nombre del archivo a importar: respaldo.txt


Posteriormente identifica cada registro mediante su tipo:

ALUMNO MAESTRO ADMINISTRADOR


Por ejemplo:

ALUMNO|Carlos|20|A001


se convierte automáticamente en un objeto `Alumno`.

---

## 🧠 Conceptos de Programación Orientada a Objetos

Este proyecto implementa diferentes conceptos de **POO**.

### 🔒 Encapsulamiento

Los atributos de las clases se encuentran definidos como `private` o `protected`.

El acceso se realiza mediante métodos `set` y `get`.

Ejemplo:

class Materia { private: string nombre; string clave;

public: void setNombre(string n) { nombre = n; }

string getNombre() { return nombre; } };


---

### 🧬 Herencia

Las clases:

Alumno Maestro Administrador


heredan de:

Persona


La estructura puede representarse de la siguiente manera:

Persona │ ┌────────────┼────────────┐ │ │ │ ▼ ▼ ▼ Alumno Maestro Administrador


Esto permite reutilizar atributos y métodos comunes.

---

### 🔄 Polimorfismo

La clase `Persona` utiliza métodos virtuales:

virtual void mostrarInformacion();

virtual bool operator==(const Persona& otra) const;

virtual ~Persona();


Las clases derivadas pueden proporcionar su propia implementación.

---

### ⚖️ Sobrecarga del operador `==`

El proyecto permite comparar objetos mediante:

==


Por ejemplo:

if (personas[i - 1] == personas[j - 1]) { cout << "Son iguales." << endl; }


Cada clase utiliza diferentes criterios para realizar la comparación.

---

### 🖨️ Sobrecarga del operador `<<`

También se utiliza la sobrecarga del operador `<<` para mostrar objetos directamente.

Ejemplo:

cout << alumnos[i];


Esto facilita la impresión de la información almacenada.

---

### 🧠 Memoria dinámica

Los maestros y administradores se almacenan mediante punteros:

Persona* personas[100];


Cuando se registra una persona se reserva memoria utilizando:

new Maestro(...)


o:

new Administrador(...)


Finalmente, al terminar el programa se libera la memoria:

delete personas[i];


---

### 🔍 `dynamic_cast`

El programa utiliza `dynamic_cast` para identificar qué tipo de objeto está almacenado dentro de un puntero `Persona`.

Por ejemplo:

Maestro* m = dynamic_cast<Maestro*>(personas[i]);


Esto permite determinar si una persona corresponde a un maestro.

También se utiliza para identificar administradores:

Administrador* a = dynamic_cast<Administrador*>(personas[i]);


---

## 🏗️ Estructura de clases

El proyecto está compuesto por las siguientes clases:

### `Materia`

Representa una materia académica.

**Atributos:**

string nombre; string clave;


**Funciones principales:**

- `setNombre()`
- `getNombre()`
- `setClave()`
- `getClave()`
- `mostrar()`

---

### `Calificacion`

Representa una calificación asociada a una materia.

**Atributos:**

string claveMateria; float nota;


**Funciones principales:**

- `setClaveMateria()`
- `getClaveMateria()`
- `setNota()`
- `getNota()`
- `mostrar()`

---

### `Persona`

Es la clase base para representar a una persona.

**Atributos:**

string nombre; int edad;


**Funciones principales:**

- `setNombre()`
- `getNombre()`
- `setEdad()`
- `getEdad()`
- `mostrarInformacion()`
- `operator==`
- `operator<<`

---

### `Alumno`

Hereda de `Persona`.

**Atributos adicionales:**

string matricula; Materia materias[10]; Calificacion calificaciones[10]; int numMaterias; int numCalificaciones;


Permite administrar las materias y calificaciones de cada alumno.

---

### `Maestro`

Hereda de `Persona`.

**Atributo adicional:**

string especialidad;


---

### `Administrador`

Hereda de `Persona`.

**Atributo adicional:**

string departamento;


---

## 🗂️ Funciones principales

Función	Descripción
registrarAlumno()	Registra un nuevo alumno
mostrarAlumno()	Muestra un alumno específico
mostrarTodos()	Muestra todos los alumnos
buscarAlumno()	Busca un alumno por nombre
eliminarAlumno()	Elimina un alumno
modificarAlumno()	Modifica los datos de un alumno
agregarMateria()	Agrega una materia a un alumno
registrarCalificacion()	Registra una calificación
mostrarHistorial()	Muestra el historial académico
registrarMaestro()	Registra un maestro
registrarAdministrador()	Registra un administrador
mostrarPersonas()	Muestra maestros y administradores
compararPersonas()	Compara dos personas
calcularPromedio()	Calcula el promedio de edades
guardarDatos()	Guarda información en archivos
cargarDatos()	Carga información desde archivos
exportarDatos()	Exporta información a un archivo
importarDatos()	Importa información desde un archivo
🎮 Menú del programa

El sistema cuenta actualmente con 17 opciones:

===== MENU =====
1. Registrar Alumno.
2. Mostrar un Alumno.
3. Mostrar Todos los Alumnos.
4. Calcular Promedio.
5. Buscar Alumno por nombre.
6. Eliminar Alumno.
7. Modificar Alumno.
8. Agregar Materia.
9. Registrar Calificacion.
10. Mostrar Historial Academico.
11. Registrar Maestro.
12. Registrar Administrador.
13. Mostrar Maestros y Administradores.
14. Comparar Personas.
15. Exportar Datos.
16. Importar Datos.
17. Salir.

💾 Límites del sistema

El programa utiliza arreglos de tamaño fijo.
Elemento	Capacidad
👨‍🎓 Alumnos	10
📚 Materias por alumno	10
📝 Calificaciones por alumno	10
👥 Maestros y administradores	100

Los alumnos y sus elementos internos utilizan el límite:

const int MAX = 10;

Mientras que maestros y administradores utilizan:

Persona* personas[100];

⚙️ Requisitos

Para compilar y ejecutar el proyecto necesitas:

    💻 Un compilador compatible con C++
    🛠️ GCC, MinGW, Clang o Visual Studio
    🖥️ Terminal o consola

Librerías utilizadas

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

Se utilizan:
Librería	Función
iostream	Entrada y salida
string	Manejo de cadenas
fstream	Lectura y escritura de archivos
sstream	Procesamiento de cadenas

No se utilizan librerías externas.
🚀 Compilación

Guarda el código como:

main.cpp

Compila utilizando:

g++ main.cpp -o sistema

🐧 Linux / macOS

./sistema

🪟 Windows

sistema.exe

🧪 Ejemplo de uso
Registrar un alumno

===== MENU =====
1. Registrar Alumno.
...

Opcion: 1

Nombre: Carlos
Edad: 20
Matricula: A001

Alumno registrado.

Agregar una materia

Nombre del alumno: Carlos
Nombre de la materia: Programacion
Clave de la materia: PROG101

Materia agregada.

Registrar una calificación

Nombre del alumno: Carlos
Clave de la materia: PROG101
Nota: 9.5

Calificacion registrada.

Exportar información

Nombre del archivo a exportar: respaldo.txt

Datos exportados.

Importar información

Nombre del archivo a importar: respaldo.txt

Datos importados.

📁 Estructura de archivos

Al ejecutar el programa pueden generarse los siguientes archivos:

📦 SistemaGestionAcademica
│
├── 📄 main.cpp
│
├── 📄 alumnos.txt
├── 📄 maestros.txt
└── 📄 administradores.txt

También es posible crear archivos personalizados mediante la opción de exportación:

📄 respaldo.txt

🔄 Flujo general del programa

                    ┌───────────────┐
                    │    INICIO     │
                    └───────┬───────┘
                            │
                            ▼
                    ┌───────────────┐
                    │ cargarDatos() │
                    └───────┬───────┘
                            │
                            ▼
                    ┌───────────────┐
                    │     MENÚ      │
                    └───────┬───────┘
                            │
             ┌──────────────┼──────────────┐
             │              │              │
             ▼              ▼              ▼
         Alumnos         Personas       Archivos
             │              │              │
             └──────────────┼──────────────┘
                            │
                            ▼
                    ┌───────────────┐
                    │  Operación    │
                    │ seleccionada  │
                    └───────┬───────┘
                            │
                            ▼
                    ┌───────────────┐
                    │ ¿Salir?       │
                    └───────┬───────┘
                            │
                           Sí
                            │
                            ▼
                    ┌───────────────┐
                    │ guardarDatos()│
                    └───────┬───────┘
                            │
                            ▼
                    ┌───────────────┐
                    │      FIN      │
                    └───────────────┘

🎯 Objetivo académico

El objetivo principal del proyecto es poner en práctica los fundamentos de Programación Orientada a Objetos en C++ mediante un sistema de gestión académica.
Conceptos utilizados

    Clases y objetos
    Encapsulamiento
    Herencia
    Polimorfismo
    Constructores
    Destructores
    Sobrecarga de operadores
    Arreglos de objetos
    Punteros
    Memoria dinámica
    dynamic_cast
    Métodos set y get
    Lectura de archivos
    Escritura de archivos
    Importación de datos
    Exportación de datos
    Persistencia de información

🔮 Mejoras futuras

Algunas mejoras que podrían implementarse:

    💾 Guardar también materias y calificaciones en archivos.
    📊 Calcular promedio real de calificaciones.
    🔍 Buscar alumnos mediante matrícula.
    📦 Utilizar vector en lugar de arreglosCaptura de pantalla de 2026-10-07 16-30-07 estáticos.
    🧹 Separar las clases en archivos .h y .cpp.
    🛡️ Mejorar la validación de entradas.
    🧠 Utilizar smart pointers.
    🖥️ Crear una interfaz gráfica.
    🔐 Implementar diferentes niveles de acceso.
    📈 Generar reportes académicos.

👨‍💻 Tecnologías
Tecnología	Uso
C++	Lenguaje principal
POO	Arquitectura del proyecto
iostream	Entrada y salida
string	Manejo de texto
fstream	Manejo de archivos
sstream	Procesamiento de cadenas
Terminal	Interfaz del programa
📄 Licencia

Este proyecto fue desarrollado con fines educativos y académicos.

Puedes modificarlo, estudiarlo y utilizarlo como base para continuar aprendiendo C++ y Programación Orientada a Objetos.

<div align="center">
🎓 Sistema de Gestión Académica

Desarrollado en C++ | Programación Orientada a Objetos

⭐ ¡Gracias por visitar el proyecto!

</div>

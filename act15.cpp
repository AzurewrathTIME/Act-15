#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

const int MAX = 10;

class Materia {
private:
    string nombre;
    string clave;

public:
    Materia() {
        nombre = "";
        clave = "";
    }

    void setNombre(string n) {
        nombre = n;
    }

    string getNombre() {
        return nombre;
    }

    void setClave(string c) {
        clave = c;
    }

    string getClave() {
        return clave;
    }

    void mostrar() {
        cout << "Materia: " << nombre << endl;
        cout << "Clave: " << clave << endl;
    }
};

class Calificacion {
private:
    string claveMateria;
    float nota;

public:
    Calificacion() {
        claveMateria = "";
        nota = 0.0;
    }

    void setClaveMateria(string c) {
        claveMateria = c;
    }

    string getClaveMateria() {
        return claveMateria;
    }

    void setNota(float n) {
        if (n >= 0 && n <= 10) {
            nota = n;
        } else {
            cout << "Nota invalida." << endl;
        }
    }

    float getNota() {
        return nota;
    }

    void mostrar() {
        cout << "Clave Materia: " << claveMateria << endl;
        cout << "Nota: " << nota << endl;
    }
};

class Persona {
protected:
    string nombre;
    int edad;

public:
    Persona() {
        nombre = "";
        edad = 0;
    }

    Persona(string n, int e) {
        nombre = n;
        edad = e;
    }

    void setNombre(string n) {
        nombre = n;
    }

    string getNombre() {
        return nombre;
    }

    void setEdad(int e) {
        if (e >= 0) {
            edad = e;
        } else {
            cout << "Edad invalida." << endl;
        }
    }

    int getEdad() {
        return edad;
    }

    virtual void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }

    virtual bool operator==(const Persona& otra) const {
        return nombre == otra.nombre;
    }

    friend ostream& operator<<(ostream& os, const Persona& p);

    virtual ~Persona() {
    }
};

ostream& operator<<(ostream& os, const Persona& p) {
    os << "Nombre: " << p.nombre << endl;
    os << "Edad: " << p.edad << endl;
    return os;
}

class Alumno : public Persona {
private:
    string matricula;
    Materia materias[10];
    Calificacion calificaciones[10];
    int numMaterias;
    int numCalificaciones;

public:
    Alumno() : Persona() {
        matricula = "";
        numMaterias = 0;
        numCalificaciones = 0;
    }

    Alumno(string n, int e, string m) : Persona(n, e) {
        matricula = m;
        numMaterias = 0;
        numCalificaciones = 0;
    }

    void setMatricula(string m) {
        matricula = m;
    }

    string getMatricula() {
        return matricula;
    }

    int getNumMaterias() {
        return numMaterias;
    }

    int getNumCalificaciones() {
        return numCalificaciones;
    }

    void agregarMateria(Materia m) {
        if (numMaterias < 10) {
            materias[numMaterias] = m;
            numMaterias++;
        } else {
            cout << "No hay espacio para mas materias." << endl;
        }
    }

    Materia getMateria(int i) {
        return materias[i];
    }

    void registrarCalificacion(Calificacion c) {
        if (numCalificaciones < 10) {
            calificaciones[numCalificaciones] = c;
            numCalificaciones++;
        } else {
            cout << "No hay espacio para mas calificaciones." << endl;
        }
    }

    Calificacion getCalificacion(int i) {
        return calificaciones[i];
    }

    int buscarMateria(string clave) {
        for (int i = 0; i < numMaterias; i++) {
            if (materias[i].getClave() == clave) {
                return i;
            }
        }
        return -1;
    }

    void mostrarInformacion() {
        cout << "=== ALUMNO ===" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Matricula: " << matricula << endl;
    }

    bool operator==(const Alumno& otro) const {
        return matricula == otro.matricula;
    }

    friend ostream& operator<<(ostream& os, const Alumno& a);
};

ostream& operator<<(ostream& os, const Alumno& a) {
    os << "Nombre: " << a.nombre << endl;
    os << "Edad: " << a.edad << endl;
    os << "Matricula: " << a.matricula << endl;
    return os;
}

class Maestro : public Persona {
private:
    string especialidad;

public:
    Maestro() : Persona() {
        especialidad = "";
    }

    Maestro(string n, int e, string esp) : Persona(n, e) {
        especialidad = esp;
    }

    void setEspecialidad(string esp) {
        especialidad = esp;
    }

    string getEspecialidad() {
        return especialidad;
    }

    void mostrarInformacion() {
        cout << "=== MAESTRO ===" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Especialidad: " << especialidad << endl;
    }

    bool operator==(const Maestro& otro) const {
        return especialidad == otro.especialidad;
    }

    friend ostream& operator<<(ostream& os, const Maestro& m);
};

ostream& operator<<(ostream& os, const Maestro& m) {
    os << "Nombre: " << m.nombre << endl;
    os << "Edad: " << m.edad << endl;
    os << "Especialidad: " << m.especialidad << endl;
    return os;
}

class Administrador : public Persona {
private:
    string departamento;

public:
    Administrador() : Persona() {
        departamento = "";
    }

    Administrador(string n, int e, string d) : Persona(n, e) {
        departamento = d;
    }

    void setDepartamento(string d) {
        departamento = d;
    }

    string getDepartamento() {
        return departamento;
    }

    void mostrarInformacion() {
        cout << "=== ADMINISTRADOR ===" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Departamento: " << departamento << endl;
    }

    bool operator==(const Administrador& otro) const {
        return departamento == otro.departamento;
    }

    friend ostream& operator<<(ostream& os, const Administrador& a);
};

ostream& operator<<(ostream& os, const Administrador& a) {
    os << "Nombre: " << a.nombre << endl;
    os << "Edad: " << a.edad << endl;
    os << "Departamento: " << a.departamento << endl;
    return os;
}

Persona* personas[100];
int numPersonas = 0;

Alumno alumnos[MAX];
int cantidadAlumnos = 0;

void guardarDatos() {
    ofstream archivoAlumnos("alumnos.txt");
    for (int i = 0; i < cantidadAlumnos; i++) {
        archivoAlumnos << alumnos[i].getNombre() << "|"
                       << alumnos[i].getEdad() << "|"
                       << alumnos[i].getMatricula() << "\n";
    }
    archivoAlumnos.close();

    ofstream archivoMaestros("maestros.txt");
    ofstream archivoAdmins("administradores.txt");
    for (int i = 0; i < numPersonas; i++) {
        Maestro* m = dynamic_cast<Maestro*>(personas[i]);
        if (m != NULL) {
            archivoMaestros << m->getNombre() << "|"
                            << m->getEdad() << "|"
                            << m->getEspecialidad() << "\n";
        }
        Administrador* a = dynamic_cast<Administrador*>(personas[i]);
        if (a != NULL) {
            archivoAdmins << a->getNombre() << "|"
                          << a->getEdad() << "|"
                          << a->getDepartamento() << "\n";
        }
    }
    archivoMaestros.close();
    archivoAdmins.close();
}

void cargarDatos() {
    ifstream archivoAlumnos("alumnos.txt");
    if (archivoAlumnos.is_open()) {
        string linea;
        while (getline(archivoAlumnos, linea)) {
            stringstream ss(linea);
            string nombre, edadStr, matricula;
            getline(ss, nombre, '|');
            getline(ss, edadStr, '|');
            getline(ss, matricula, '|');
            if (nombre != "" && edadStr != "" && matricula != "" && cantidadAlumnos < MAX) {
                alumnos[cantidadAlumnos].setNombre(nombre);
                alumnos[cantidadAlumnos].setEdad(stoi(edadStr));
                alumnos[cantidadAlumnos].setMatricula(matricula);
                cantidadAlumnos++;
            }
        }
        archivoAlumnos.close();
    }

    ifstream archivoMaestros("maestros.txt");
    if (archivoMaestros.is_open()) {
        string linea;
        while (getline(archivoMaestros, linea)) {
            stringstream ss(linea);
            string nombre, edadStr, especialidad;
            getline(ss, nombre, '|');
            getline(ss, edadStr, '|');
            getline(ss, especialidad, '|');
            if (nombre != "" && edadStr != "" && especialidad != "" && numPersonas < 100) {
                personas[numPersonas] = new Maestro(nombre, stoi(edadStr), especialidad);
                numPersonas++;
            }
        }
        archivoMaestros.close();
    }

    ifstream archivoAdmins("administradores.txt");
    if (archivoAdmins.is_open()) {
        string linea;
        while (getline(archivoAdmins, linea)) {
            stringstream ss(linea);
            string nombre, edadStr, departamento;
            getline(ss, nombre, '|');
            getline(ss, edadStr, '|');
            getline(ss, departamento, '|');
            if (nombre != "" && edadStr != "" && departamento != "" && numPersonas < 100) {
                personas[numPersonas] = new Administrador(nombre, stoi(edadStr), departamento);
                numPersonas++;
            }
        }
        archivoAdmins.close();
    }
}

void exportarDatos() {
    string nombreArchivo;
    cout << "Nombre del archivo a exportar: ";
    cin >> nombreArchivo;

    ofstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        cout << "No se pudo crear el archivo." << endl;
        return;
    }

    for (int i = 0; i < cantidadAlumnos; i++) {
        archivo << "ALUMNO|" << alumnos[i].getNombre() << "|"
                << alumnos[i].getEdad() << "|"
                << alumnos[i].getMatricula() << "\n";
    }
    for (int i = 0; i < numPersonas; i++) {
        Maestro* m = dynamic_cast<Maestro*>(personas[i]);
        if (m != NULL) {
            archivo << "MAESTRO|" << m->getNombre() << "|"
                    << m->getEdad() << "|"
                    << m->getEspecialidad() << "\n";
        }
        Administrador* a = dynamic_cast<Administrador*>(personas[i]);
        if (a != NULL) {
            archivo << "ADMINISTRADOR|" << a->getNombre() << "|"
                    << a->getEdad() << "|"
                    << a->getDepartamento() << "\n";
        }
    }
    archivo.close();
    cout << "Datos exportados." << endl;
}

void importarDatos() {
    string nombreArchivo;
    cout << "Nombre del archivo a importar: ";
    cin >> nombreArchivo;

    ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string tipo, nombre, edadStr, extra;
        getline(ss, tipo, '|');
        getline(ss, nombre, '|');
        getline(ss, edadStr, '|');
        getline(ss, extra, '|');

        if (tipo == "ALUMNO" && cantidadAlumnos < MAX) {
            alumnos[cantidadAlumnos].setNombre(nombre);
            alumnos[cantidadAlumnos].setEdad(stoi(edadStr));
            alumnos[cantidadAlumnos].setMatricula(extra);
            cantidadAlumnos++;
        } else if (tipo == "MAESTRO" && numPersonas < 100) {
            personas[numPersonas] = new Maestro(nombre, stoi(edadStr), extra);
            numPersonas++;
        } else if (tipo == "ADMINISTRADOR" && numPersonas < 100) {
            personas[numPersonas] = new Administrador(nombre, stoi(edadStr), extra);
            numPersonas++;
        }
    }
    archivo.close();
    cout << "Datos importados." << endl;
}

void registrar(Alumno a) {
    if (cantidadAlumnos >= MAX) {
        cout << "No hay espacio para mas alumnos." << endl;
        return;
    }
    alumnos[cantidadAlumnos] = a;
    cantidadAlumnos++;
    cout << "Alumno registrado." << endl;
}

void registrar(Maestro m) {
    if (numPersonas >= 100) {
        cout << "No hay espacio." << endl;
        return;
    }
    personas[numPersonas] = new Maestro(m);
    numPersonas++;
    cout << "Maestro registrado." << endl;
}

void registrar(Administrador adm) {
    if (numPersonas >= 100) {
        cout << "No hay espacio." << endl;
        return;
    }
    personas[numPersonas] = new Administrador(adm);
    numPersonas++;
    cout << "Administrador registrado." << endl;
}

int buscarIndiceAlumno(string nombre) {
    for (int i = 0; i < cantidadAlumnos; i++) {
        if (alumnos[i].getNombre() == nombre) {
            return i;
        }
    }
    return -1;
}

void registrarAlumno() {
    string n;
    int e;
    string m;

    cout << "Nombre: ";
    cin >> n;
    cout << "Edad: ";
    cin >> e;
    cout << "Matricula: ";
    cin >> m;

    Alumno a(n, e, m);
    registrar(a);
}

void registrarMaestro() {
    string n;
    int e;
    string esp;

    cout << "Nombre: ";
    cin >> n;
    cout << "Edad: ";
    cin >> e;
    cout << "Especialidad: ";
    cin >> esp;

    Maestro m(n, e, esp);
    registrar(m);
}

void registrarAdministrador() {
    string n;
    int e;
    string d;

    cout << "Nombre: ";
    cin >> n;
    cout << "Edad: ";
    cin >> e;
    cout << "Departamento: ";
    cin >> d;

    Administrador adm(n, e, d);
    registrar(adm);
}

void mostrarAlumno() {
    if (cantidadAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    int indice;
    cout << "Indice del alumno (1 a " << cantidadAlumnos << "): ";
    cin >> indice;
    if (indice < 1 || indice > cantidadAlumnos) {
        cout << "Indice invalido." << endl;
        return;
    }
    cout << alumnos[indice - 1];
}

void mostrarTodos() {
    if (cantidadAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    for (int i = 0; i < cantidadAlumnos; i++) {
        cout << "Alumno " << i + 1 << ":" << endl;
        cout << alumnos[i];
        cout << "---------------------" << endl;
    }
}

void calcularPromedio() {
    if (cantidadAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    double suma = 0;
    for (int i = 0; i < cantidadAlumnos; i++) {
        suma += alumnos[i].getEdad();
    }
    double promedio = suma / cantidadAlumnos;
    cout << "Promedio de edades: " << promedio << endl;
}

void buscarAlumno() {
    if (cantidadAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    string buscar;
    cout << "Nombre del alumno a buscar: ";
    cin >> buscar;

    int indice = buscarIndiceAlumno(buscar);

    if (indice != -1) {
        cout << "Alumno encontrado en la posicion " << indice + 1 << ":" << endl;
        cout << alumnos[indice];
    } else {
        cout << "Alumno no encontrado." << endl;
    }
}

void eliminarAlumno() {
    if (cantidadAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    string buscar;
    cout << "Nombre del alumno a eliminar: ";
    cin >> buscar;

    int indice = buscarIndiceAlumno(buscar);

    if (indice == -1) {
        cout << "Alumno no encontrado." << endl;
        return;
    }

    for (int i = indice; i < cantidadAlumnos - 1; i++) {
        alumnos[i] = alumnos[i + 1];
    }
    cantidadAlumnos--;
    cout << "Alumno eliminado." << endl;
}

void modificarAlumno() {
    if (cantidadAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    string buscar;
    cout << "Nombre del alumno a modificar: ";
    cin >> buscar;

    int indice = buscarIndiceAlumno(buscar);

    if (indice == -1) {
        cout << "Alumno no encontrado." << endl;
        return;
    }

    string n;
    int e;
    string m;

    cout << "Nuevo nombre: ";
    cin >> n;
    cout << "Nueva edad: ";
    cin >> e;
    cout << "Nueva matricula: ";
    cin >> m;

    alumnos[indice].setNombre(n);
    alumnos[indice].setEdad(e);
    alumnos[indice].setMatricula(m);

    cout << "Alumno modificado." << endl;
}

void agregarMateria() {
    if (cantidadAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    string buscar;
    cout << "Nombre del alumno: ";
    cin >> buscar;

    int indice = buscarIndiceAlumno(buscar);

    if (indice == -1) {
        cout << "Alumno no encontrado." << endl;
        return;
    }

    if (alumnos[indice].getNumMaterias() >= 10) {
        cout << "No hay espacio para mas materias." << endl;
        return;
    }

    string nombreMateria;
    string clave;

    cout << "Nombre de la materia: ";
    cin >> nombreMateria;
    cout << "Clave de la materia: ";
    cin >> clave;

    Materia m;
    m.setNombre(nombreMateria);
    m.setClave(clave);

    alumnos[indice].agregarMateria(m);
    cout << "Materia agregada." << endl;
}

void registrarCalificacion() {
    if (cantidadAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    string buscar;
    cout << "Nombre del alumno: ";
    cin >> buscar;

    int indice = buscarIndiceAlumno(buscar);

    if (indice == -1) {
        cout << "Alumno no encontrado." << endl;
        return;
    }

    if (alumnos[indice].getNumCalificaciones() >= 10) {
        cout << "No hay espacio para mas calificaciones." << endl;
        return;
    }

    string clave;
    float nota;

    cout << "Clave de la materia: ";
    cin >> clave;

    if (alumnos[indice].buscarMateria(clave) == -1) {
        cout << "La materia no existe." << endl;
        return;
    }

    cout << "Nota: ";
    cin >> nota;

    Calificacion c;
    c.setClaveMateria(clave);
    c.setNota(nota);

    alumnos[indice].registrarCalificacion(c);
    cout << "Calificacion registrada." << endl;
}

void mostrarHistorial() {
    if (cantidadAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    string buscar;
    cout << "Nombre del alumno: ";
    cin >> buscar;

    int indice = buscarIndiceAlumno(buscar);

    if (indice == -1) {
        cout << "Alumno no encontrado." << endl;
        return;
    }

    cout << "Historial de " << alumnos[indice].getNombre() << endl;

    for (int i = 0; i < alumnos[indice].getNumMaterias(); i++) {
        Materia m = alumnos[indice].getMateria(i);
        cout << "Materia: " << m.getNombre() << endl;
        cout << "Clave: " << m.getClave() << endl;

        for (int j = 0; j < alumnos[indice].getNumCalificaciones(); j++) {
            Calificacion c = alumnos[indice].getCalificacion(j);
            if (c.getClaveMateria() == m.getClave()) {
                cout << "Nota: " << c.getNota() << endl;
            }
        }
        cout << "---------------------" << endl;
    }
}

void mostrarPersonas() {
    if (numPersonas == 0) {
        cout << "No hay maestros ni administradores registrados." << endl;
        return;
    }
    for (int i = 0; i < numPersonas; i++) {
        cout << "Persona " << i + 1 << ":" << endl;
        cout << *personas[i];
        cout << "---------------------" << endl;
    }
}

void compararPersonas() {
    if (numPersonas < 2) {
        cout << "Se necesitan al menos 2 personas." << endl;
        return;
    }

    int i, j;
    cout << "Primera persona (1 a " << numPersonas << "): ";
    cin >> i;
    cout << "Segunda persona (1 a " << numPersonas << "): ";
    cin >> j;

    if (i < 1 || i > numPersonas || j < 1 || j > numPersonas) {
        cout << "Indices invalidos." << endl;
        return;
    }

    if (*personas[i - 1] == *personas[j - 1]) {
        cout << "Son iguales." << endl;
    } else {
        cout << "Son diferentes." << endl;
    }
}

void menu() {
    int opcion;
    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Registrar Alumno." << endl;
        cout << "2. Mostrar un Alumno." << endl;
        cout << "3. Mostrar Todos los Alumnos." << endl;
        cout << "4. Calcular Promedio." << endl;
        cout << "5. Buscar Alumno por nombre." << endl;
        cout << "6. Eliminar Alumno." << endl;
        cout << "7. Modificar Alumno." << endl;
        cout << "8. Agregar Materia." << endl;
        cout << "9. Registrar Calificacion." << endl;
        cout << "10. Mostrar Historial Academico." << endl;
        cout << "11. Registrar Maestro." << endl;
        cout << "12. Registrar Administrador." << endl;
        cout << "13. Mostrar Maestros y Administradores." << endl;
        cout << "14. Comparar Personas." << endl;
        cout << "15. Exportar Datos." << endl;
        cout << "16. Importar Datos." << endl;
        cout << "17. Salir." << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            registrarAlumno();
        } else if (opcion == 2) {
            mostrarAlumno();
        } else if (opcion == 3) {
            mostrarTodos();
        } else if (opcion == 4) {
            calcularPromedio();
        } else if (opcion == 5) {
            buscarAlumno();
        } else if (opcion == 6) {
            eliminarAlumno();
        } else if (opcion == 7) {
            modificarAlumno();
        } else if (opcion == 8) {
            agregarMateria();
        } else if (opcion == 9) {
            registrarCalificacion();
        } else if (opcion == 10) {
            mostrarHistorial();
        } else if (opcion == 11) {
            registrarMaestro();
        } else if (opcion == 12) {
            registrarAdministrador();
        } else if (opcion == 13) {
            mostrarPersonas();
        } else if (opcion == 14) {
            compararPersonas();
        } else if (opcion == 15) {
            exportarDatos();
        } else if (opcion == 16) {
            importarDatos();
        } else if (opcion == 17) {
            cout << "Saliendo del programa." << endl;
        } else {
            cout << "Opcion no valida." << endl;
        }
    } while (opcion != 17);
}

int main() {
    cargarDatos();
    menu();
    guardarDatos();

    for (int i = 0; i < numPersonas; i++) {
        delete personas[i];
    }

    return 0;
}
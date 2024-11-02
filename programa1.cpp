#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Persona {
    char nombre[100];
    int edad;
    int id;
    float peso;
    float altura;
    char genero;
};

int main() {
    int cantidadPersonas;
    Persona persona;

    cout << "Cuantas personas desea registrar?: ";
    cin >> cantidadPersonas;

    fstream archivo("datos_personas.bin", ios::out | ios::binary);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de registro." << endl;
        return 1;
    }

    for (int i = 0; i < cantidadPersonas; i++) {
        cout << "Registro de la persona #" << (i + 1) << endl;

        cout << "Nombre: ";
        cin >> ws;  // Limpiar cualquier espacio en blanco antes de leer
        cin.getline(persona.nombre, 100);

        cout << "Edad: ";
        cin >> persona.edad;

        cout << "Numero de identificacion (cedula): ";
        cin >> persona.id;

        cout << "Peso (en kg): ";
        cin >> persona.peso;

        cout << "Altura (en metros): ";
        cin >> persona.altura;

        cout << "Genero (m/f): ";
        cin >> persona.genero;

        if (persona.genero == 'm') {
            cout << "Registrado como Masculino." << endl;
        } else if (persona.genero == 'f') {
            cout << "Registrado como Femenino." << endl;
        } else {
            cout << "Entrada no valida. Género registrado como 'Otro'." << endl;
        }

        archivo.write(reinterpret_cast<char*>(&persona), sizeof(Persona));
    }

    cout << "Tamaño de cada registro: " << sizeof(Persona) << " bytes." << endl;
    archivo.close();

    return 0;
}

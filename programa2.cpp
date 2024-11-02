#include <iostream>
#include <fstream>

using namespace std;

struct Persona {
    char nombre[100];
    int edad;
    int id;
    float peso;
    float altura;
    char genero;
    int numeroRegistro;  
};

int main() {
    int registroID;
    Persona persona;

    cout << "Ingrese el numero de registro que desea consultar: ";
    cin >> registroID;

    fstream archivo("datos_personas.bin", ios::in | ios::binary);

    if (!archivo) {
        cerr << "No fue posible abrir el archivo." << endl;
        return 1;
    }

   
    archivo.seekg(sizeof(Persona) * registroID, ios::beg);

   
    archivo.read(reinterpret_cast<char*>(&persona), sizeof(Persona));

    if (archivo) {
        cout << "Datos del registro #" << registroID << ":\n";
        cout << "Nombre: " << persona.nombre << endl;
        cout << "Cedula: " << persona.id << endl;
        cout << "Edad: " << persona.edad << " años" << endl;
        cout << "Peso: " << persona.peso << " kg" << endl;
        cout << "Altura: " << persona.altura << " m" << endl;
        cout << "Genero: " << (persona.genero == 'm' ? "Masculino" : (persona.genero == 'f' ? "Femenino" : "Otro")) << endl;
        cout << "Numero de Registro: " << persona.numeroRegistro << endl;
    } else {
        cout << "No se encontraron datos para el registro #" << registroID << "." << endl;
    }

    archivo.close();
    return 0;
}

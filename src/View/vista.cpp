#include "../Model/owner.cpp"
#include "../Model/mascota.cpp"
#include<iostream>
using namespace std;

void mostrarMenu(){
    cout << "Seleccione una opcion: " << endl;
    cout << "1. insertar mascota" << endl
         << "2. actualizar mascota" << endl
         << "3. leer mascota" << endl
         << "4. borrar mascotas" << endl
         << "5. insertar owner" << endl
         << "6. actualizar owner" << endl
         << "7. leer owner" << endl
         << "8. borrar owners" << endl
         << "9. realiza consultas especificas" << endl
         << "10. salir del programa" << endl;
}
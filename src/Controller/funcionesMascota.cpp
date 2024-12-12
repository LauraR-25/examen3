#include"../Model/mascota.h"
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

extern mascotas* mascotaPtr;
extern int mascotaCount;

void leerMascota() {
    ifstream file("../bin/mascota.csv");
    string line;

    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    getline(file, line);
    while (getline(file, line)) {
        mascotas pet;
        stringstream ss(line);
        string tempStr;
        int tempInt;

        getline(ss, tempStr, ',');
        pet.setMascotaID(tempStr);
        getline(ss, tempStr, ',');
        pet.setnameMascota(tempStr);
        getline(ss, tempStr, ',');
        pet.setEspecie(tempStr);
        getline(ss, tempStr, ',');
        pet.setRaza(tempStr);
        ss >> tempInt;
        pet.setEdad(tempInt);
        ss.ignore();
        ss >> tempInt;
        pet.setOwnerID(tempInt);

        mascotas* temp = new mascotas[mascotaCount + 1];
        for (int i = 0; i < mascotaCount; i++) {
            temp[i] = mascotaPtr[i];
        }
        temp[mascotaCount] = pet;
        delete[] mascotaPtr;
        mascotaPtr = temp;
        mascotaCount++;
    }
    file.close();
}

void guardarMascota(const string &filename) {
    ofstream file(filename);
    file << "mascotaID, nameMascota, especie, edad, raza, ownerID\n";
    for (int i = 0; i < mascotaCount; i++){
        file << mascotaPtr[i].getMascotaID() << ","
             << mascotaPtr[i].getnameMascota() << ","
             << mascotaPtr[i].getEspecie() << ","
             << mascotaPtr[i].getEdad() << ","
             << mascotaPtr[i].getRaza() << ","
             << mascotaPtr[i].getOwnerID() << "\n";
    }
    file.close();
}

void insertarMascota() {
    mascotas mascota;
    cout << "Ingrese datos de la mascota: " << endl;
    string mascotaID, nameMascota, especie, raza;
    int edad, ownerID;
    cin >> mascotaID >> nameMascota >> especie >> raza >> edad >> ownerID;
    mascota.setMascotaID(mascotaID);
    mascota.setnameMascota(nameMascota);
    mascota.setEspecie(especie);
    mascota.setRaza(raza);
    mascota.setEdad(edad);
    mascota.setOwnerID(ownerID);

    cout << "Confirma la insercion de la mascota? (si/no): ";
    char confirmacion;
    cin >> confirmacion;
    
    if (confirmacion == 's' || confirmacion == 'S') {
        mascotas* temp = new mascotas[mascotaCount + 1];
        for (int i = 0; i < mascotaCount; i++) {
            temp[i] = mascotaPtr[i];
        }
        temp[mascotaCount] = mascota;
        delete[] mascotaPtr;
        mascotaPtr = temp;
        mascotaCount++;
        guardarMascota("../bin/mascota.csv");
        cout << "Mascota insertada" << endl;

    } else {
        cout << "Insercion cancelada" << endl;
    }
}

void actualizarMascota(const string &id){
    for (int i = 0; i < mascotaCount; i++){
        if (mascotaPtr[i].getMascotaID() == id){
            mascotas original = mascotaPtr[i];
            mascotas &mascota = mascotaPtr[i];
            cout << "Ingrese nuevos datos: " << endl;
            string nameMascota, raza, especie;
            int edad, ownerID;
            cin >> nameMascota >> especie >> raza >> edad >> ownerID;
            mascota.setnameMascota(nameMascota);
            mascota.setEspecie(especie);
            mascota.setRaza(raza);
            mascota.setEdad(edad);
            mascota.setOwnerID(ownerID);

            cout << "Confirma los cambios? (si/no): ";
            char confirmacion;
            cin >> confirmacion;

            if (confirmacion == 's' || confirmacion == 'S') {
                guardarMascota("../bin/mascota.csv");
                cout << "los cambios fueron confirmados y guardados" << endl;

            } else {
                mascotaPtr[i] = original;
                cout << "Cambios revertidos" << endl;
            }
            return;
        }
    }
    cout << "Mascota no fue encontrada" << endl;
}

void borrarMascota(const string &id) {
    for (int i = 0; i < mascotaCount; i++) {
        if (mascotaPtr[i].getMascotaID() == id) {
            cout << "Esta seguro que desea borrar la mascota con ID " << id << "? (si/no): ";
            char confirmacion;
            cin >> confirmacion;

            if (confirmacion == 's' || confirmacion == 'S') {
                mascotas* temp = new mascotas[mascotaCount - 1];
                for (int j = 0, k = 0; j < mascotaCount; j++) {
                    if (j != i) {
                        temp[k++] = mascotaPtr[j];
                    }
                }
                delete[] mascotaPtr;
                mascotaPtr = temp;
                mascotaCount--;
                guardarMascota("../bin/mascota.csv");
                cout << "La mascota fue eliminada" << endl;

            } else {
                cout << "Eliminacion cancelada" << endl;
            }
            return;
        }
    }
    cout << "Mascota no encontrada" << endl;
}
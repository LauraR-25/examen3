#include"../Model/owner.h"
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

extern owners* ownerPtr;
extern int ownerCount;

void leerOwners(const string &ownerFile){
    ifstream archivoOwner("../bin/owners.csv");
    string line;

    if (!archivoOwner.is_open()){
        cout << "No se pudo abrir el archivo " << ownerFile << endl;
        return;
    }

    getline(archivoOwner, line);
    while (getline(archivoOwner, line)){
        owners owner;
        stringstream ss(line);
        string tempStr;

        getline(ss, tempStr, ',');
        owner.setOwnerID(stoi(tempStr));
        getline(ss, tempStr, ',');
        owner.setNombre(tempStr);
        getline(ss, tempStr, ',');
        owner.setApellido(tempStr);
        getline(ss, tempStr, ',');
        owner.setDireccion(tempStr);
        getline(ss, tempStr, ',');
        owner.setTelefono(tempStr);
        getline(ss, tempStr, ',');
        owner.setCorreo(tempStr);

        owners* temp = new owners[ownerCount + 1];
        for (int i = 0; i < ownerCount; ++i) {
            temp[i] = ownerPtr[i];
        }
        temp[ownerCount] = owner;
        delete[] ownerPtr;
        ownerPtr = temp;
        ownerCount++;

    }
    archivoOwner.close();
}

void guardarOwners(const string &ownersFile) {
    ofstream file("../bin/owners.csv");
    file << "OwnerID, nombre, apellido, direccion, telefono, correo\n";
    for (int i = 0; i < ownerCount; i++){
        file << ownerPtr[i].getOwnerID() << ","
             << ownerPtr[i].getNombre() << ","
             << ownerPtr[i].getApellido() << ","
             << ownerPtr[i].getTelefono() << ","
             << ownerPtr[i].getCorreo() << ","
             << ownerPtr[i].getDireccion() << "\n";
    }
    file.close();
}

void insertarOwners() {
    owners owner;
    cout << "Ingrese los datos del owner: " << endl;
    string OwnerID, nombre, apellido, direccion, telefono, correo;
    cin >> OwnerID >> nombre >> apellido >> direccion >> telefono >> correo;
    owner.setOwnerID(stoi(OwnerID));
    owner.setNombre(nombre);
    owner.setApellido(apellido);
    owner.setDireccion(direccion);
    owner.setTelefono(telefono);
    owner.setCorreo(correo);

    cout << "desea confirmar la insercion del owner? (si/no): ";
    char confirmacion;
    cin >> confirmacion;

    if (confirmacion == 's' || confirmacion == 'S') {
        owners* temp = new owners[ownerCount + 1];
        for (int i = 0; i < ownerCount; i++) {
            temp[i] = ownerPtr[i];
        }

        temp[ownerCount] = owner;
        delete[] ownerPtr;
        ownerPtr = temp;
        ownerCount++;
        guardarOwners("../bin/owners.csv");
        cout << "Owner insertado" << endl;
    } else {
        cout << "Insercion cancelada" << endl;
    }
}

void actualizarOwners(const string &cedula){
    for (int i=0; i<ownerCount; i++){
        if (ownerPtr[i].getOwnerID() == stoi(cedula)){
            owners original = ownerPtr[i];
            owners &owner = ownerPtr[i];
            cout << "Ingrese nuevos datos: " << endl;
            string nombre, apellido, direccion, telefono, correo;
            cin >> nombre >> apellido >> direccion >> telefono;
            cin.ignore();
            getline(cin, correo);
            owner.setNombre(nombre);
            owner.setApellido(apellido);
            owner.setDireccion(direccion);
            owner.setTelefono(telefono);
            owner.setCorreo(correo);

            cout << "confirma los cambios? (si/no): ";
            char confirmacion;
            cin >> confirmacion;

            if (confirmacion == 's' || confirmacion == 'S'){
                guardarOwners("../bin/owners.csv");
                cout << "cambios confirmados y guardados" << endl;
            } else {
                ownerPtr[i] = original;
                cout << "cambios revertidos" << endl;
            }
            return;
        }
    }
    cout << "Owner no encontrado." << endl;
}

void borrarOwners(const string &cedula){
    for (int i=0; i<ownerCount; i++) {
        if (ownerPtr[i].getOwnerID() == stoi(cedula)){
            cout << "Esta seguro de que desea eliminar el owner con cedula " << cedula << "? (s/n): ";
            char confirmacion;
            cin >> confirmacion;
            if (confirmacion == 's' || confirmacion == 'S'){
                owners* temp = new owners[ownerCount - 1];
                for (int j=0, k=0; j<ownerCount; j++){
                    if (j != i){
                        temp[k++] = ownerPtr[j];
                    }
                }
                delete[] ownerPtr;
                ownerPtr = temp;
                ownerCount--;
                guardarOwners("../bin/owners.csv");
                cout << "Owner ha sido eliminado" << endl;
            } else {
                cout << "Eliminacion cancelada" << endl;
            }
            return;
        }
    }
    cout << "Owner no encontrado." << endl;
}
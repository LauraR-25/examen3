#include "./Model/mascota.cpp"
#include "./Model/owner.cpp"
#include "./Controller/funcionesMascota.cpp"
#include "./Controller/funcionesOwner.cpp"
#include"./View/vista.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

mascotas* pmascotaPtr = nullptr;
int mascotaCount = 0;
owners* ownersPtr = nullptr;
int ownersCount = 0;

int main(){
    leerMascota();
    leerOwners("../bin/owner.csv");
    int opcion;
    string mascotaID, ownerID;

    do{
        mostrarMenu();
        cin >> opcion;

        switch (opcion){
            case 1:
                insertarMascota();
                break;

            case 2:
                cout << "Ingrese el ID de la mascota a actualizar: ";
                cin >> mascotaID;
                actualizarMascota(mascotaID);
                break;

            case 3:
                cout << "Ingrese el ID de la mascota a borrar: ";
                cin >> mascotaID;
                borrarMascota(mascotaID);
                break;

            case 4:
                for (int i = 0; i < mascotaCount; ++i) {
                    const mascotas &mascota = mascotaPtr[i];
                    cout << mascota.getMascotaID()
                         << ", " << mascota.getnameMascota()
                         << ", " << mascota.getEspecie()
                         << ", " << mascota.getRaza()
                         << ", " << mascota.getEdad()
                         << ", " << mascota.getOwnerID() << endl;
                }
                break;

            case 5:
                insertarOwners();
                break;

            case 6:
                cout << "Ingrese la cedula del owner a actualizar: ";
                cin >> ownerID;
                actualizarOwners(ownerID);
                break;

            case 7:
                cout << "Ingrese la cedula del owner a borrar: ";
                cin >> ownerID;
                borrarOwners(ownerID);
                break;

            case 8:
                leerOwners("../bin/owner.csv");
                break;

            case 9:{
                int subOpcion;
                cout << "Seleccione la consulta que desea realizar: " << endl
                     << "1. Consultar una Mascota" << endl
                     << "2. Consultar un Dueño" << endl;
                cin >> subOpcion;

                switch (subOpcion){
                    case 1:
                        cout << "Ingrese el ID de la mascota: ";
                        cin >> mascotaID;
                        for (int i = 0; i < mascotaCount; i++) {
                            if (mascotaPtr[i].getMascotaID() == mascotaID) {
                                const mascotas &mascota = mascotaPtr[i];
                                cout << mascota.getMascotaID() << ", "
                                     << mascota.getnameMascota() << ", "
                                     << mascota.getEspecie() << ", "
                                     << mascota.getRaza() << ", "
                                     << mascota.getEdad() << ", "
                                     << mascota.getOwnerID() << endl;
                                break;
                            }
                        }
                        break;

                    case 2:
                        cout << "Ingrese el ID del owner: ";
                        cin >> ownerID;
                        for (int i = 0; i < ownersCount; ++i) {
                            if (ownersPtr[i].getOwnerID() == stoi(ownerID)) {
                                const owners &owner = ownersPtr[i];
                                cout << owner.getOwnerID() << ", "
                                     << owner.getNombre() << ", "
                                     << owner.getApellido() << ", "
                                     << owner.getDireccion() << ", "
                                     << owner.getTelefono() << ", "
                                     << owner.getCorreo() << endl;
                                break;
                            }
                        }
                        break;
                    default:
                        cout << "Opcion no valida." << endl;
                        break;
                }
            }
            break;

            case 10:
                cout << "Saliendo...";
                return 0;
                break;
            
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    } while (opcion != 10);

    return 0;
}
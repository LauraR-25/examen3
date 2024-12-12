#ifndef PETS_H
#define PETS_H
#include <iostream>
using namespace std;

class mascotas{

    private:
        string mascotaID, nameMascota, especie, raza;
        int edad, ownerID;

    public:
        string getMascotaID() const;
        string getnameMascota() const;
        string getEspecie() const;
        string getRaza() const;
        int getEdad() const;
        int getOwnerID() const;

        void setMascotaID(const string &mascotaID);
        void setnameMascota(const string &nameMascota);
        void setEspecie(const string &especie);
        void setRaza(const string &raza);
        void setEdad(const int &edad);
        void setOwnerID(const int &ownerID);
};

#endif
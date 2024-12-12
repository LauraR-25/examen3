#ifndef OWNER_H
#define OWNER_H
#include<iostream>
using namespace std;

class owners{
    private:
        int OwnerID;
        string nombre, apellido, telefono, correo, direccion;

    public:
        int getOwnerID() const;
        string getNombre() const;
        string getApellido() const;
        string getTelefono() const;
        string getCorreo() const;
        string getDireccion() const;

        void setOwnerID(const int &OwnerID);
        void setNombre(const string &nombre);
        void setApellido(const string &apellido);
        void setTelefono(const string &telefono);
        void setCorreo(const string &correo);
        void setDireccion(const string &direccion);
};

#endif
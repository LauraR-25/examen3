#include "owner.h"

int owners::getOwnerID() const { return OwnerID; }
string owners::getNombre() const { return nombre; }
string owners::getApellido() const { return apellido; }
string owners::getTelefono() const { return telefono; }
string owners::getCorreo() const { return correo; }
string owners::getDireccion() const { return direccion; }

void owners::setOwnerID(const int &OwnerID) { this->OwnerID = OwnerID; }
void owners::setNombre(const string &nombre) { this->nombre = nombre; }
void owners::setApellido(const string &apellido) { this->apellido = apellido; }
void owners::setTelefono(const string &telefono) { this->telefono = telefono; }
void owners::setDireccion(const string &direccion) { this->direccion = direccion; }
void owners::setCorreo(const string &correo) { this->correo = correo; }
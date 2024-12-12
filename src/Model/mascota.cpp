#include"mascota.h"

string mascotas:: getMascotaID()const{return mascotaID;};
string mascotas:: getnameMascota()const{return nameMascota;};
string mascotas:: getEspecie()const{return especie;};
string mascotas:: getRaza()const{return raza;};
int mascotas:: getEdad()const{return edad;};
int mascotas:: getOwnerID()const{return ownerID;};

void mascotas:: setMascotaID(const string &mascotaID){this->mascotaID = mascotaID;};
void mascotas:: setnameMascota(const string &namenombreMascota){this->nameMascota = nameMascota;};
void mascotas:: setEspecie(const string &especie){this->especie = especie;};
void mascotas:: setRaza(const string &raza){this->raza = raza;};
void mascotas:: setEdad(const int &edad){this->edad = edad;};
void mascotas:: setOwnerID(const int &ownerID){this->ownerID = ownerID;};
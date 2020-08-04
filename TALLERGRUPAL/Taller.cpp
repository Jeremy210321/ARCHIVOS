#include <iostream>

//LIBRERIA PARA TRABAJAR CON ARCHIVOS
#include <fstream>

using namespace std;
int main() {
  string nombre, apellido,celular,cedula,sangre;
  int e;
  char r;
  ofstream archivoPrueba;
  string nombreArchivo;
  cout << "Ingrese el nombre del archivo: ";
  getline(cin, nombreArchivo);

  archivoPrueba.open(nombreArchivo.c_str(), ios::app);

  do
  {
    cout << "\tIngrese el nombre: ";
    getline(cin, nombre, '\n');
    cout << "\tIngrese el apellido: ";
    getline(cin, apellido, '\n');
    cout << "Ingresa tu edad: ";
    cin >> e;
    cin.ignore();
    cout << "\tIngrese el número de celular: ";
    getline(cin, celular, '\n');
    cout << "\tIngrese el Tipo de sangre: ";
    getline(cin, sangre, '\n');
    cout << "Ingresa la cedula: ";
    getline (cin, cedula, '\n');
    archivoPrueba << nombre << " " << apellido << " " << e <<" "<< celular << " " <<" "<< sangre <<" "<< cedula << '\n';

    cout << "Desea agregar otro contacto s/n ";
    cin >> r;
    cin.ignore();

  }while ( r == 's');

  archivoPrueba.close();

  ifstream archivoLectura("Datos.txt");
  string texto;
  while(!archivoLectura.eof())
  {
    archivoLectura >> nombre >> apellido >> e>>celular>>sangre>>cedula;
    if(!archivoLectura.eof())
    {
      getline(archivoLectura, texto);
      cout << "\n***" << endl;
      cout << "Nombre es: " << nombre << endl;
      cout << "Apellido es: " << apellido << endl;
      cout << "Edad es: " << e << endl;
      cout << "celular es: " << celular << endl;
      cout << "Tipo de sangre es: " << sangre << endl;
      cout << "cedula es: " << cedula<< endl;
    }
  }
  archivoLectura.close();
  return 0;
}

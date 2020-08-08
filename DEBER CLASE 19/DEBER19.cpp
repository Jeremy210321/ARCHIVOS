#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int menu();
string nombre;
string apellido;
string nombrearchivo;
char r;
void Parte();
void FUNCION1();
ofstream archivoprueba;
int edad;


int main() 
{
	
	int opcion;
  do 
  {
    opcion = menu();
    switch (opcion)
    {
      case 1:
      {
       Parte();
      break;
      }
      case 2:
      {
        FUNCION1();
      break;
      }
  }
  } while (opcion != 3);
  cout << "\n\t\t\t\t-------- FIN DE LA PRÁCTICA--------" << endl;
  return 0;
}

void Parte(){
	
	cout<<"INGRESE EL NOMBRE DEL ARCHIVO: ";
	cin.ignore();
   getline(cin,nombrearchivo);
	ofstream archivoprueba;
   
   archivoprueba.open(nombrearchivo.c_str(),ios::app);
   do
    {
    cout<<"\tIngrese el nombre: ";
    getline(cin,nombre,'\n');

    cout<<"\tIngrese el apellido: ";
    getline(cin,apellido,'\n');

    cout<<"\tIngrese la edad: ";
    cin>>edad;

    archivoprueba<<nombre<<" "<<apellido<<" "<<edad<<"\n";

    cout<<"¿DESEA INGRESAR OTRO CONTACTO? s/n: ";
    cin>>r;

    cin.ignore();
    }

   while(r=='s');
}
   
  void FUNCION1(){

    archivoprueba.close();
	ifstream archivolectura("Contactos.txt");
   string texto;

   while(!archivolectura.eof())
    {
        archivolectura>>nombre>>apellido>>edad;

        if(!archivolectura.eof())
            {
        getline(archivolectura,texto);
        cout<<"NOMBRE ES: "<<nombre<<"\n";
        cout<<"APELLIDO ES: "<<apellido<<"\n";
        cout<<"EDAD ES: "<<edad<<"\n";

            }

    }
   archivolectura.close();
}

int menu()
{
  int op = 0;
  while ((op < 1) || (op > 3))
  {
	cout << "\n\t\t\t***DEBER CLASE 19-- ***" << endl;
    cout << "1. Escribir Archivo" << endl;
    cout << "2. Leer Archivo" << endl;
    cout << "3. salir" << endl;
    cout << "Eliga una opción: ";
    cin >> op;
    if ((op < 1) || (op > 3))
    {
      cout << "\nEliga una opción correcta del menú" << endl;
    }
  } 
  return op;
}

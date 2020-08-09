#include <iostream>
#include <fstream>

using namespace std;

char linea(int par);
void guardar();

int main() {
  guardar();
  return 0;
}
char linea(int par)
{
  char simbolo;
  if (par % 2 == 0)
  {
    simbolo = '*';
  }
  else
  {
    simbolo = '-';
  }
  return simbolo;
}
void guardar()
{
  string nombreArch;
  int numero;
  char nivel;
  ofstream Archivo_piramide;
  cout << "Ingrese el nombre del archivo txt: ";
  getline(cin, nombreArch); 

  Archivo_piramide.open(nombreArch.c_str(), ios::out);

  if(Archivo_piramide.fail())
  {
    cout << "El archivo no se abrio correctamente" << endl;
  }
  cout << "\nIngrese el número de niveles de la pirámide: ";
  cin >> numero;
  cout << endl;
  for(int i = numero; i > 0; --i)
  {
    nivel = linea(i);
    for(int j = 0; j < i; j++)
    {
      cout << nivel << " "; 
      Archivo_piramide << nivel << " ";  
    }
    cout << endl;  
    Archivo_piramide << '\n';
  }
  Archivo_piramide.close();
}

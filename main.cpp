#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <fstream>
#include "ListasSimLig.h"
#include "Productos.h"

using namespace std;

template <class T>
void guardarListaEnArchivo(Lista<T>& lista)
{
    fstream archivo;
    archivo.open("prod_electronicos.dat", ios::out | ios::binary);
    if (archivo.fail()) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    NodoLista<T> * actual = lista.RegresaPrimero();
    while (actual != NULL)
    {
        archivo.write(reinterpret_cast<char*>(&actual->Info), sizeof(T));
        actual = actual->Liga;
    }

    archivo.close();
}

template <class T>
void CargarListaDesdeArchivo(Lista<T>& lista)
{
    fstream archivo;
    archivo.open("prod_electronicos.dat", ios::in | ios::binary);
    if (!archivo.is_open())
    {
        cout << "Error al abrir archivo\n";
        return;
    }

    T dato;
    while (archivo.read((char*)&dato, sizeof(T)))
    {
        lista.InsertaInicio(dato);
    }

    archivo.close();
}



int Menu()
{
int Opc;
system("cls");
cout<<"\nMenu - Bienvenido al sistema de registro de productos electrónicos"<< endl;
cout<<"1. Registrar un nuevo producto"<<endl;
cout<<"2. Dar de baja un producto"<<endl;
cout<<"3. Verificar si un producto ya fue registrado"<<endl;
cout<<"4. Imprimir la lista de productos registrados"<<endl;
cout<<"5. Salir"<<endl;
cout<<"Seleccione: ";
cin>>Opc;
return Opc;
}




int main()
{
Lista<Producto> ListaProds;
Producto ObjProd;
NodoLista<Producto> *Apunt;
int Opc, Res, Clave;
bool continuarPrograma = true;

CargarListaDesdeArchivo(ListaProds);

do{
Opc= Menu();
switch (Opc)
{
case 1: {
system("cls");
cout<<"**Ingrese datos del producto a registrar**"<<endl;
cin>>ObjProd;
ListaProds.InsertaOrdenCrec(ObjProd);
system("pause");
break;
}
case 2: {
system("cls");
cout<<"\n\nIngrese la clave del producto a eliminar:\n";
cin>>Clave;
Producto Produc(Clave,"", 0);
Res= ListaProds.EliminaUnNodo(Produc);
switch (Res)
{
case 1: cout<<"\n\nEl producto ya fue eliminado.\n";
break;
case 0: cout<<"\n\nEse producto no se encuentra registrado.\n";
break;
case -1: cout<<"\n\nNo hay productos registrados.\n";
}
system("pause");
}
break;
case 3: {
system("cls");
cout<<"\n\nIngrese la clave del producto a buscar:\n";
cin>>Clave;
Producto Produc(Clave,"",0);
Apunt= ListaProds.BuscaOrdenada(Produc);
if (!Apunt)
cout<<"\n\nEse producto no está registrado.\n\n";
else
{
cout<<"\n\nEse producto está registrado.\n";
ListaProds.ImprimeUnNodo(Apunt);
}
system("pause");
}
break;
case 4: system("cls"); ListaProds.ImprimeRecursivo(ListaProds.RegresaPrimero()); system("pause");
break;
case 5: {guardarListaEnArchivo(ListaProds); continuarPrograma = false; break;}
}
}while(continuarPrograma);
}

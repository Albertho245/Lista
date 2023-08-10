#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

using namespace std;

class Producto
{
private:
int Clave;
char NomProd[64];
double Precio;
public:
Producto();
Producto(int, char[], double);
double RegresaPrecio();
int operator == (Producto);
int operator != (Producto);
int operator > (Producto);
int operator < (Producto);
friend istream &operator>> (istream &, Producto &);
friend ostream &operator<< (ostream &, Producto &);
};

Producto::Producto()
{ }

Producto::Producto(int Cla, char NomP[], double Pre)
{
Clave= Cla;
strcpy(NomProd, NomP);
Precio= Pre;
}

double Producto::RegresaPrecio()
{
return Precio;
}

int Producto::operator == (Producto Prod)
{
int Resp=0;
if (Clave == Prod.Clave)
Resp= 1;
return Resp;
}

int Producto::operator != (Producto Prod)
{
int Resp=0;
if (Clave != Prod.Clave)
Resp= 1;
return Resp;
}

int Producto::operator > (Producto Prod)
{
int Resp=0;
if (Clave > Prod.Clave)
Resp= 1;
return Resp;
}

int Producto::operator < (Producto Prod)
{
int Resp=0;
if (Clave < Prod.Clave)
Resp= 1;
return Resp;
}

istream &operator>> (istream &Lee, Producto &ObjProd)
{
cout<<"\n\nIngrese clave del producto: ";
Lee>> ObjProd.Clave;
cout<<"\n\nIngrese nombre del producto: ";
Lee>> ObjProd.NomProd;
cout<<"\n\nIngrese precio: ";
Lee>> ObjProd.Precio;
return Lee;
}

ostream &operator<< (ostream &Escribe, Producto &ObjProd)
{
Escribe<<"\n\nDatos del producto\n";
Escribe<<"\nClave: "<<ObjProd.Clave;
Escribe<<"\nNombre: "<<ObjProd.NomProd;
Escribe<<"\nPrecio: "<<ObjProd.Precio<<"\n";
return Escribe;
}



#endif // PRODUCTOS_H_INCLUDED

#ifndef LISTASSIMLIG_H_INCLUDED
#define LISTASSIMLIG_H_INCLUDED

using namespace std;

template <class T>
class Lista;

template <class T>
class NodoLista
{
public:
NodoLista<T> * Liga;
T Info;
NodoLista();
T RegresaInfo();
friend class Lista<T>;
};

template <class T>
NodoLista<T>::NodoLista()
{
Liga= NULL;
}

template <class T>
T NodoLista<T>::RegresaInfo()
{
return Info;
}

template <class T>
class Lista
{
private:
NodoLista<T> * Primero;
public:
Lista ();
NodoLista<T> * RegresaPrimero();
void CreaInicio();
void CreaFinal();
void ImprimeIterativo();
void ImprimeRecursivo(NodoLista<T> * );
void ImprimeUnNodo(NodoLista<T> * );
void InsertaInicio(T);
void InsertaOrdenCrec(T);
int EliminaPrimero();
int EliminaUnNodo(T);
int EliminaAnterior(T);
int EliminaDespues(T);
NodoLista<T> * BuscaDesordenada(T);
NodoLista<T> * BuscaOrdenada(T);
NodoLista<T> * BuscaRecursivo(T, NodoLista<T> *);
};

template <class T>
Lista<T>::Lista()
{
Primero= NULL;
}

template <class T>
NodoLista<T> * Lista<T>::RegresaPrimero()
{
return Primero;
}

template <class T>
void Lista<T>::CreaInicio()

{
NodoLista<T> * P;
T Dato;
char Resp;
Primero= new NodoLista<T>();
cout<< "Ingrese la información a almacenar: \n";
cin>>Dato;
Primero->Info= Dato;
cout<< "\n¿Desea ingresar otro elemento (S/N)? ";
cin>>Resp;
while (Resp == 'S' || Resp == 's')
{
cout<< "Ingrese la información: \n";
cin>> Dato;
P = new NodoLista<T>();
P->Info= Dato;
P->Liga= Primero;
Primero= P;
cout<< "\n¿Desea ingresar otro elemento (S/N)? ";
cin>>Resp;
}
}

template <class T>
void Lista<T>::CreaFinal()
{
NodoLista<T> * P, *Ultimo;
T Dato;
char Resp;
Primero= new NodoLista<T>();
cout<<"Ingrese la información a almacenar: \n";
cin>>Dato;
Primero->Info= Dato;

Ultimo= Primero;
cout<<"\n¿Desea ingresar otro elemento (S/N)? ";
cin>>Resp;
while (Resp == 'S' || Resp == 's')
{
cout<< "\nIngrese la información \n";
cin>>Dato;
P= new NodoLista<T>();
P->Info= Dato;
Ultimo->Liga= P;
Ultimo= P;
cout<< "\n¿Desea ingresar otro elemento (S/N)? ";
cin>>Resp;
}
}

template <class T>
void Lista<T>::ImprimeIterativo()
{
NodoLista<T> * P;
P= Primero;
while (P)
{
cout<< "\nInformación: "<< P->Info;
P= P->Liga;
}
cout<< '\n';
}

template <class T>
void Lista<T>::ImprimeRecursivo(NodoLista<T> * P)
{
if (P)
{
cout<<"\nInformación: "<< P->Info;
ImprimeRecursivo(P->Liga);
}
cout<<'\n';
}

template <class T>
void Lista<T>::ImprimeUnNodo(NodoLista<T> * P)
{
if (P)
cout<< P->Info;
}

template <class T>
void Lista<T>::InsertaInicio(T Dato)
{
    NodoLista<T> *P = new NodoLista<T>();
    P->Info = Dato;
    P->Liga = Primero;
    Primero = P;
}

template <class T>
void Lista<T>::InsertaOrdenCrec(T Dato)
{
NodoLista<T> * P, *Q, *Ant;
if (!Primero || Primero->Info > Dato)
InsertaInicio(Dato);
else
{
Q= Primero;
while (Q && Q->Info < Dato)
{
Ant= Q;
Q= Q->Liga;
}
P= new NodoLista<T>();
P->Info= Dato;
Ant->Liga= P;
P->Liga= Q;
}
}


template <class T>
int Lista<T>::EliminaUnNodo(T Ref)
{
    NodoLista<T> * P, *Ant;
    int Resp= 0;
    if (Primero)
    {
        if (Primero->Info == Ref)
        {
            P= Primero;
            Primero= Primero->Liga;
            delete P;
            Resp= 1;
        }
        else
        {
            P= Primero;
            Ant= Primero;
            while ((P) && (P->Info != Ref))
            {
                Ant= P;
                P= P->Liga;
            }
            if (P)
            {
                Ant->Liga= P->Liga;
                delete P;
                Resp= 1;
            }
        }
    }
    return Resp;
}


template <class T>
int Lista<T>::EliminaAnterior(T Ref)
{
NodoLista<T> * Q, *Ant, *P;
int Resp= 1;
if (Primero)
{
if (Primero->Info == Ref)

Resp= 2;
else
{
Q= Primero;
Ant= Primero;

while ((Q->Info != Ref) && (Q->Liga))
{
P= Ant;
Ant= Q;
Q= Q->Liga;
}

if (Q->Info != Ref)

Resp= 3;
else
if (Primero->Liga == Q)
{
delete (Primero);
Primero= Q;
}
else
{
P->Liga= Q;
delete (Ant);
}
}
}
else

Resp= 4;
return Resp;
}

template <class T>
NodoLista<T> * Lista<T>::BuscaDesordenada(T Ref)
{
NodoLista<T> * Q, *Resp= NULL;
if (Primero)
{
Q= Primero;
while ((Q->Info != Ref) && (Q->Liga))
Q= Q->Liga;

if (Q->Info == Ref)
Resp= Q;
}
return Resp;
}

template <class T>
NodoLista<T> * Lista<T>::BuscaOrdenada(T Ref)
{
NodoLista<T> * Q, *Resp= NULL;
if (Primero)

{
Q= Primero;
while ((Q->Info < Ref) && (Q->Liga))
Q= Q->Liga;

if (Q->Info == Ref)
Resp= Q;
}
return Resp;
}

template <class T>
NodoLista<T> * Lista<T>::BuscaRecursivo(T Dato, NodoLista<T> * Q)
{
if (Q)
if (Q->Info == Dato)
return Q;
else
return BuscaRecursivo(Dato, Q->Liga);
else
return NULL;
}


#endif // LISTASSIMLIG_H_INCLUDED

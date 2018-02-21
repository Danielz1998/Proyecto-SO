#include <iostream>

using namespace std;


class nodo
{
public:
    int procesoID;
    string nombre;
    int prioridad;
    int tiempo;
    int estado = 0;

    nodo * siguiente;
    nodo * anterior;

    nodo (int cprocesoID, string cnombre, int cprioridad, int ctiempo, int cestado)
    {
        procesoID = cprocesoID;
        nombre = cnombre;
        prioridad = cprioridad;
        tiempo = ctiempo;
        estado = cestado;
    }
};

class lista
{
public:
    nodo * pnodo;
    nodo * unodo;

    lista ()
    {
        pnodo = NULL;
        unodo = NULL;
    }

    bool vacia()
    {
        if(pnodo == NULL && unodo == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insertarnodo (nodo * nuevo)
    {
        if(vacia())
        {
            pnodo = nuevo;
            unodo = nuevo;
        }
        else
        {
            unodo -> siguiente = nuevo;
            nuevo -> anterior = unodo;
            unodo = nuevo;
        }
    }

    void imprimir()
    {
        if(vacia())
        {
            nodo * aux;
            aux = pnodo;

            while(aux != NULL)
            {
                cout<<aux->nombre<<endl;
                aux = aux->siguiente;
            }
        }
    }
};


int main()
{
    lista l;
    int cantidad = 0;
    int opc=0;

    cout<<"\t<<Simulador SO>>";
    cout<<"\n";
    cout<<"\nEscoja una opcion:";
    cout<<"\n1.Configuracion de Procesos";
    cout<<"\n2.Definicion de Lista de Ejecucion";
    cout<<"\nOpcion:";
    cin>>opc;
    cout<<"\n";

    if(opc==1)
    {
        cout<<"\t<<Configuracion de Procesos>>";
        cout<<"\n";
        cout<<"\nIngrese la cantidad de procesos: ";
        cin>>cantidad;

        for(int i=0; i< cantidad; i++)
        {
            string u_nombre;
            int u_prioridad;
            int u_tiempo;

            cout<<""<<endl;
            cout<<"\nIngrese el nombre del proceso: ";
            cin>>u_nombre;
            cout<<"\nIngrese el nivel de prioridad del proceso: ";
            cin>>u_prioridad;
            cout<<"\nIngrese el tiempo del preceso: ";
            cin>>u_tiempo;
            cout<<""<<endl;

            nodo * a= new nodo(i, u_nombre, u_prioridad, u_tiempo,0);

        }
    };


    return 0;
}

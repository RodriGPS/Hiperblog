#include <iostream>
#include <conio.h>

using namespace std; 


struct nodo
{
    int dato;
    nodo* siguiente;
} *primero, *ultimo;

void insertarNodo();
void buscarNodo();
void modificarNodo();
void eliminarNodo();

void desplegarLista();

int main()
{
    int menu = 0;
    do
    {
        cout<<"\n|-------------------------------------|";
        cout<<"\n|      LISTA CIRCULAR SIMPLES         |";
        cout<<"\n|-------------------------------------|";
        cout<<"\n|   1. Insertar   |  4. Eliminar      |";
        cout<<"\n|   2. Buscar     |  5. Desplegar     |";
        cout<<"\n|   3. Modificar  |  6. Salir         |";
        cout<<"\n|-------------------------------------|";
        cout<<"\n\n Elija una opcion:_";
        cin>>menu;

        switch (menu)
        {
            case 1:
                cout<<"INSERTE UN NODO EN LA LISTA"<<endl;
                insertarNodo();
                break;
            case 2:
                cout<<"BUSCAR UN NODO EN LA LISTA"<<endl;
                buscarNodo();
                break;
            case 3:
                cout<<"MODIFICAR UN NODO EN LA LISTA"<<endl;
                modificarNodo();
                break;
            case 4:
                cout<<"ELIMINAR UN NODO EN LA LISTA"<<endl;
                eliminarNodo();
                break;
            case 5:
                cout<<"MOSTRAR LOS ELEMENTOS DE LA LISTA"<<endl;
                desplegarLista();
                break;
            case 6:
                cout<<"Programa finalizado.....";
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
    } while (menu!=6);
    return 0;
}

// Primero =null  ultimo ==nuell

/* lista ciurcular simple */
void insertarNodo(){
    nodo* nuevo = new nodo();
    cout<<"Ingrese el dato que contendra el nuevo nodo: ";
    cin>>nuevo->dato;
    if (primero==NULL)
    {   
        primero = nuevo;
        primero->siguiente=primero;
        ultimo = primero;
    }else{
        ultimo->siguiente=nuevo;
        nuevo->siguiente= primero;
        ultimo = nuevo;
        cout<<"\nNodo ingresado"<<endl;
    }   
}


void buscarNodo(){
    nodo* actual= new nodo();
    actual = primero;
    bool encontrado = false;
    int nodoBuscado=0;
    
    cout<<"\n Ingrese el dato del nodo a buscar: ";
    cin>>nodoBuscado;

    if (primero!=NULL)
    {
        do
        {
            if (actual->dato == nodoBuscado)
            {
                cout<<"\n El nodo con el dato [ "<<nodoBuscado<<" ] encontrado "<<endl;
                encontrado = true;
            }
            actual = actual -> siguiente;
        } while (actual!=primero && encontrado!=true);
        if (encontrado == false)
        {
            cout<<"\n Nodo no encontrado";
        }    
    } else{
        cout<<"\n La lista se encuentra vacia"<<endl;
    }
}

void modificarNodo(){
    nodo* actual= new nodo();
    actual = primero;
    bool encontrado = false;
    int nodoBuscado=0;

    cout<<"\n Ingrese el dato del nodo a Modificar ";
    cin>>nodoBuscado;

    if (primero!=NULL)
    {
        do
        {
            if (actual->dato == nodoBuscado)
            {
                cout<<"\n El nodo con el dato [ "<<nodoBuscado<<" ] encontrado "<<endl;
                cout<<"\n Ingrese el nuevo dato para modificar el nodo: ";
                cin>>actual->dato;
                cout<<"\n El nodo ha sido modificado";
                encontrado = true;
            }
            actual = actual -> siguiente;
        } while (actual!=primero && encontrado!=true);
        if (encontrado==false)
        {
            cout<<"\n Nodo no encontrado";
        }    
    }else{
        cout<<"\n La lista se encuentra vacia"<<endl;
    }
}


void eliminarNodo(){
    nodo* actual= new nodo();
    actual = primero;
    nodo* anterior =new nodo();
    anterior = NULL;
    bool encontrado = false;
    int nodoBuscado=0;
    
    cout<<"\n Ingrese el dato del nodo a buscar para eliminar: ";
    cin>>nodoBuscado;

    if (primero!=NULL)
    {
        do
        {
            if (actual->dato == nodoBuscado)
            {
                cout<<"\n El nodo con el dato [ "<<nodoBuscado<<" ] encontrado "<<endl;
                if (actual==primero)
                {
                    primero= primero->siguiente;
                    ultimo->siguiente= primero;
                } else if (actual==ultimo){
                    anterior->siguiente = primero;
                    ultimo=anterior;
                } else{
                    anterior->siguiente = actual->siguiente;
                }

                cout<<"\n Nodo Eliminado"<<endl;
                encontrado = true;
            }
            anterior = actual;
            actual = actual -> siguiente;
        } while (actual!=primero && encontrado!=true);
        if (encontrado==false)
        {
            cout<<"\n Nodo no encontrado";
        }    
    } else{
        cout<<"\n La lista se encuentra vacia"<<endl;
    }
}
void desplegarLista(){
    nodo* actual= new nodo();
    actual = primero;

    if (primero!=NULL)
    {
        do
        {
            cout<<"\n "<<actual->dato;
            actual = actual -> siguiente;
        } while (actual!=primero);
        
    } else{
        cout<<"\n La lista se encuentra vacia"<<endl;
    }
}

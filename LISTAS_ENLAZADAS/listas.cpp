//
//  listas.cpp
//  LISTAS_ENLAZADAS
//
//  Created by Alexander Arturo Baylon Ibanez on 9/12/14.
//  Copyright (c) 2014 Alexander Arturo Baylon Ibanez. All rights reserved.
//

#include "listas.h"

//---------------------------------//
//Metodos de la clase listas_padre.


 char letras[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',};

void listas_padre::buscar_valor(int valor)
{
    nodo * temp = primero;
    while (temp!=nullptr) {
        if (temp->val==valor){
            cout << "El elemento existe en la lista" << endl;
            return;
        }
        else
            temp = temp->punt_sig;
    }
    cout << "El elemento no existe en esta lista" << endl;
}


//---------------------------------//

//Metodos de la clase lista_simple.


lista_simple::lista_simple()
{
    primero = ultimo = nullptr;
}


void lista_simple::insertar_cola(int val)
{
    nodo * nuevo = new nodo(val);
    if(primero==nullptr){
        primero = nuevo;
    }
    else
        ultimo->punt_sig = nuevo;
    ultimo = nuevo;
}

void lista_simple::insertar_cabeza(int val)
{
    nodo * nuevo = new nodo(val);
    if(primero==nullptr){
        ultimo = nuevo;
    }
    else
        nuevo->punt_sig = primero;
    primero = nuevo;
}



int lista_simple::borrar_cabeza()
{
    nodo * temp = primero;
    int val = primero->val;
    primero = primero->punt_sig;
    delete temp;
    return val;
}

int lista_simple::borrar_cola()
{
    nodo * temp = primero;
    int val = ultimo->val;
    while (temp->punt_sig!=nullptr) {
        if (temp->punt_sig==ultimo) {
            delete ultimo;
            ultimo = temp;
            ultimo->punt_sig = nullptr;
            return val;
        }
        temp = temp->punt_sig;
    }
    return 0;
}

void lista_simple::imprimir_lista()
{
    nodo * temp = primero;
    int i=0;
    while(temp!=nullptr)
    {
        cout << letras[i++] << "(" << temp->val << ")" << " -> ";
        temp = temp->punt_sig;
    }
    cout << "end" << endl;
}

//---------------------------------//

//Metodos de la clase lista_doble.


lista_doble::lista_doble()
{
    primero = ultimo = nullptr;
}


void lista_doble::insertar_cola(int val)
{
    nodo * nuevo = new nodo(val);
    if(primero==nullptr){
        primero = nuevo;
    }
    else{
        ultimo->punt_sig = nuevo;
        nuevo->punt_ant = ultimo;
    }
    ultimo = nuevo;
}

void lista_doble::insertar_cabeza(int val)
{
    nodo * nuevo = new nodo(val);
    if(primero==nullptr){
        ultimo = nuevo;
    }
    else{
        primero->punt_ant = nuevo;
        nuevo->punt_sig = primero;
    }
    primero = nuevo;
}



int lista_doble::borrar_cabeza()
{
    nodo * temp = primero;
    int val = primero->val;
    primero = primero->punt_sig;
    primero->punt_ant = nullptr;
    delete temp;
    return val;
}

int lista_doble::borrar_cola()
{
    nodo * temp = ultimo;
    int val = ultimo->val;
    ultimo = ultimo->punt_ant;
    ultimo->punt_sig = nullptr;
    delete temp;
    return val;
}

void lista_doble::imprimir_lista()
{
    nodo * temp = primero;
    int i=0;
    while(temp!=nullptr)
    {
        if(temp->punt_ant==nullptr)
            cout << "null ";
        cout << "<- " << letras[i++] << "(" << temp->val << ")" << " ->";
        temp = temp->punt_sig;
    }
    cout << "end" << endl;
}



//---------------------------------//

//Metodos de la clase lista_circular.

lista_circular::lista_circular()
{
    primero = ultimo = nullptr;
}


void lista_circular::insertar_cola(int val)
{
    nodo * nuevo = new nodo(val);
    if(primero==nullptr){
        primero = ultimo = nuevo;
    }
    else{
        ultimo->punt_sig = nuevo;
        nuevo->punt_sig = primero;
    }
    ultimo = nuevo;
}


int lista_circular::borrar_cola()
{
    
    nodo * temp = primero;
    int val = ultimo->val;
    if (temp == ultimo) {
        delete ultimo;
        delete temp;
        return 0;
    }
    while (temp->punt_sig!=primero) {
        if (temp->punt_sig==ultimo) {
            delete ultimo;
            ultimo = temp;
            ultimo->punt_sig = primero;
            return val;
        }
        temp = temp->punt_sig;
    }
    return 0;
}

void lista_circular::imprimir_lista()
{
    nodo * temp = primero;
    int i=0;
    while(temp!=nullptr)
    {
        cout << letras[i++] << "(" << temp->val << ")" << " -> ";
        temp = temp->punt_sig;
        if (temp==primero) {
            break;
        }
    }
    i = 0;
    cout << letras[i++] << "(" << primero->val << ")" << endl;
    
}

//---------------------------------//

//Metodos de la clase lista_doble_circular


lista_doble_circular::lista_doble_circular()
{
    primero = ultimo = nullptr;
}


void lista_doble_circular::insertar_cola(int val)
{
    nodo * nuevo = new nodo(val);
    if(primero==nullptr){
        primero = ultimo = nuevo;
    }
    else{
        ultimo->punt_sig = nuevo;
        nuevo->punt_ant = ultimo;
        nuevo->punt_sig = primero;
    }
    ultimo = nuevo;
}

void lista_doble_circular::insertar_cabeza(int val)
{
    nodo * nuevo = new nodo(val);
    if(primero==nullptr){
        ultimo = primero = nuevo;
    }
    else{
        primero->punt_ant = nuevo;
        ultimo->punt_sig = nuevo;
        nuevo->punt_sig = primero;
    }
    primero = nuevo;
}



int lista_doble_circular::borrar_cabeza()
{
    nodo * temp = primero;
    int val = primero->val;
    primero = primero->punt_sig;
    primero->punt_ant = nullptr;
    ultimo->punt_sig = primero;
    delete temp;
    return val;
}

int lista_doble_circular::borrar_cola()
{
    nodo * temp = ultimo;
    int val = ultimo->val;
    ultimo = ultimo->punt_ant;
    ultimo->punt_sig = primero;
    delete temp;
    return val;
}

void lista_doble_circular::imprimir_lista()
{
    nodo * temp = primero;
    int i=0;
    while(temp!=nullptr)
    {
        if(temp->punt_ant==nullptr)
            cout << "null ";
        cout << "<- " << letras[i++] << "(" << temp->val << ")" << " ->";
        temp = temp->punt_sig;
        if (temp==primero)
            break;
    }
    i = 0;
    cout << letras[i++] << "(" << temp->val << ") ..." << endl;
}


void menu()
{
    cout << "## LISTAS ENLAZADAS ##" << endl;
    cout << "(Opcion 1)  - Crear una Lista enlazada SIMPLE." << endl;
    cout << "(Opcion 2)  - Crear una Lista DOBLEMENTE enlazada." << endl;
    cout << "(Opcion 3)  - Crear una Lista enlazada CIRCULAR" << endl;
    cout << "(Opcion 4)  - Crear una Lista DOBLEMENTE enlazada CIRCULAR" << endl;
    cout << "(Opcion 0)  - Terminar el Programa." << endl;
}

void menu2()
{
    cout << "ELIJA UN METODO" << endl;
    cout << "## METODOS ##" << endl;
    cout << "(Opcion 1)  - INSERTAR EN COLA." << endl;
    cout << "(Opcion 2)  - INSERTAR EN CABEZA." << endl;
    cout << "(Opcion 3)  - BORRAR COLA" << endl;
    cout << "(Opcion 4)  - BORRAR CABEZA" << endl;
    cout << "(Opcion 5)  - IMPRIMIR LISTA." << endl;
    cout << "(Opcion 0)  - SALIR." << endl;
}

void menu_circ()
{
    cout << "ELIJA UN METODO" << endl;
    cout << "## METODOS ##" << endl;
    cout << "(Opcion 1)  - INSERTAR ELEMENTO." << endl;
    cout << "(Opcion 2)  - BORRAR ELEMENTO" << endl;
    cout << "(Opcion 3)  - IMPRIMIR" << endl;
    cout << "(Opcion 0)  - SALIR." << endl;
}

void pausa()
{
    cout << "Presione una tecla para continuar.... ";
    cin.ignore().get();
}


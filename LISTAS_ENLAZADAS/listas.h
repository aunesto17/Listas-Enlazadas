//
//  lista_simple.h
//  LISTAS_ENLAZADAS
//
//  Created by Alexander Arturo Baylon Ibanez on 9/12/14.
//  Copyright (c) 2014 Alexander Arturo Baylon Ibanez. All rights reserved.
//

#ifndef LISTAS_ENLAZADAS_listas_h
#define LISTAS_ENLAZADAS_listas_h

#include "header.h"



class nodo
{
public:
    int val;
    nodo * punt_sig, * punt_ant;
    nodo()
    {
        punt_sig = punt_ant = nullptr;
        
    }
    nodo(int valor, nodo * punt = nullptr)
    {
        val         = valor;
        punt_sig    = punt_ant = punt;
    }
};


class listas_padre
{
public:
    nodo * primero, * ultimo;
    virtual void imprimir_lista() = 0;
    virtual void buscar_valor(int);
    virtual void insertar_cola(int){};
    virtual void insertar_cabeza(int){};
    virtual int  borrar_cola() = 0;
    virtual int  borrar_cabeza() = 0 ;
   
};


class lista_simple:public listas_padre
{
public:
    lista_simple();
    void insertar_cola(int);
    void insertar_cabeza(int);
    int  borrar_cola();
    int  borrar_cabeza();
    void imprimir_lista();
};

class lista_doble:public listas_padre
{
public:
    lista_doble();
    void insertar_cola(int);
    void insertar_cabeza(int);
    int  borrar_cola();
    int  borrar_cabeza();
    void imprimir_lista();
};


class lista_circular:public listas_padre
{
public:
    lista_circular();
    void insertar_cola(int);
    void insertar_cabeza(int){};
    int  borrar_cola();
    int  borrar_cabeza(){return 0;};
    void imprimir_lista();
    
};

class lista_doble_circular:public listas_padre
{
public:
    lista_doble_circular();
    void insertar_cola(int);
    void insertar_cabeza(int);
    int  borrar_cola();
    int  borrar_cabeza();
    void imprimir_lista();
    
};

void menu();


void menu2();

void menu_circ();


void pausa();




#endif

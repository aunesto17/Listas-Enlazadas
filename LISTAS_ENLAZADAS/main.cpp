//
//  main.cpp
//  LISTAS_ENLAZADAS
//
//  Created by Alexander Arturo Baylon Ibanez on 9/12/14.
//  Copyright (c) 2014 Alexander Arturo Baylon Ibanez. All rights reserved.
//


#include "listas.h"

int ingresar_opcion()
{
    cout << "Ingrese una OPCION : ";
    int val;
    cin >> val;
    return val;    
}

int ingresar_lista()
{
    cout << "Ingrese un VALOR : ";
    int val;
    cin >> val;
    return val;
}

int ingresar_primer()
{
    cout << "Ingrese el primer elemento de la Lista: ";
    int val; cin >> val;
    return val;
}
void elejir_opcion(int op, listas_padre & A)
{
    switch (op) {
        case 1:
            A.insertar_cola(ingresar_lista());
            A.imprimir_lista();
            break;
        case 2:
            A.insertar_cabeza(ingresar_lista());
            A.imprimir_lista();
            break;
        case 3:
            cout << "Se elimino el elemento " << A.borrar_cola() << endl;
            A.imprimir_lista();
            break;
        case 4:
            cout << "Se elimino el elemento " << A.borrar_cabeza() << endl;
            A.imprimir_lista();
            break;
        case 5:
            A.imprimir_lista();
            break;
        default:
            break;
    }
}

void elejir_opcion_circ(int op, listas_padre & A)
{
    switch (op) {
        case 1:
            A.insertar_cola(ingresar_lista());
            A.imprimir_lista();
            break;
        case 2:
            cout << "Se elimino el elemento " << A.borrar_cola() << endl;
            A.imprimir_lista();
            break;
        case 3:
            A.imprimir_lista();
            break;
        default:
            break;
    }
}


int main(int argc, const char * argv[])
{
    int op,op1;
    do {
        menu();
        op = ingresar_opcion();
        switch (op) {
            case 1:{
                lista_simple A;
                listas_padre * simple = &A;
                simple->insertar_cola(ingresar_primer());
                menu2();
                do {
                    
                    op1 = ingresar_opcion();
                    elejir_opcion(op1, *simple);
                    pausa();
                } while (op1!=0);
                break;
            }
            case 2:{
                lista_doble B;
                listas_padre * simple1 = &B;
                simple1->insertar_cola(ingresar_primer());
                menu2();
                do {
                    op1 = ingresar_opcion();
                    elejir_opcion(op1, *simple1);
                    pausa();
                } while (op1!=0);
                break;
            }
            case 3:{
                lista_circular C;
                listas_padre * simple2 = &C;
                simple2->insertar_cola(ingresar_primer());
                menu_circ();
                do {
                    
                    op1 = ingresar_opcion();
                    elejir_opcion_circ(op1, *simple2);
                    pausa();
                } while (op1!=0);
                break;
            }
            case 4:{
                lista_doble_circular D;
                listas_padre * simple3 = &D;
                simple3->insertar_cola(ingresar_primer());
                menu_circ();
                do {
                    op1 = ingresar_opcion();
                    elejir_opcion_circ(op1, *simple3);
                    pausa();
                } while (op1!=0);
                break;
            }
            default:
                break;
        }
    } while (op!=0);
    
    
    
    
    return 0;
}


#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include <unistd.h>
#include "ordenamiento.h"

int main(int argc, char* argv[])
{
  


    int num,val,cantidad,m;
    int op,op2;
    
    timeval start, end;
    
    cout << "\nMetodos de ordenamiento" <<endl;
    cout << "1. Crear Arreglo nuevo ( 10 - 10,000)" <<endl;
    cout << "2. Cargar Arreglo existente" <<endl;

    cin >> op2;
        
    switch(op2)
    {
        case 1:
            cout<< "Cuantos numeros desea crear?"<<endl;
            remove("Datos");
            remove("num");
            cin>>cantidad;
            Guardar(cantidad);
            cout<< "\nEspere un momento...\n" <<endl; 
            sleep(2);
            Cargar(cantidad,false);
            m = cantidad;
        break;
        case 2:
            m = Tamanio();
            Cargar(m,false);
            cout<< "\n\nVector con "<< m <<" numeros cargado exitosamente\n"<<endl;
        break;
    }
    cout<<"\nCualquier Tecla para continuar..."<<endl;

    getchar();
    getchar();
    
    do{
        long double t1 = 0.0,t2 = 0.0;
        cout << "\033[H\033[2J";//Limpia pantalla en linux
        op = menu();
        switch(op)
        {
            case 1:
                Cargar(m,true);                    
            break;

            case 2:
                Mostrar(m);
            break;

            case 3:
                t1 = getTime();
                BubbleSort(m);
                t2 = getTime();
                cout<< t2-t1 <<endl;
            break;
            case 4:
                t1 = getTime();
                MinBubbleSort(m);
                t2 = getTime();
                cout<< t2-t1 <<endl;
            break;
            case 5:
                t1 = getTime();
                SelectionSort(m);
                t2 = getTime();
                cout<< t2-t1 <<endl;
            break;
            case 6:
                t1 = getTime();
                ShakerSort(m);
                t2 = getTime();
                cout<< t2-t1 <<endl;
            break;
            case 7:
                t1 = getTime();
                InsertionSort(m);
                t2 = getTime();
                cout<< t2-t1 <<endl;
            break;
            case 8:
                t1 = getTime();
                BinaryInsertionSort(m);
                t2 = getTime();
                cout<< t2-t1 <<endl;
            break;
            case 9:
                t1 = getTime();
                ShellSort(m);
                t2 = getTime();
                cout<< t2-t1 <<endl;
            break;
            case 10:
                
            break;
            case 11:
                t1 = getTime();
                QuickSort(v,0,m-1,0,0);
                t2 = getTime();
                cout<< t2-t1 <<endl;
            break;
            case 12:
                t1 = getTime();
                mergeSort(v,v2,0,m-1);
                t2 = getTime();
                cout<< t2-t1 <<endl;
            break;
            case 13:
                heapsort(v,m);
                

            break;
            case 0:
                cout<<"adios"<<endl;
                exit(0);
        }
        cout<<"\nCualquier Tecla para continuar..."<<endl;
        getchar();
        getchar();
    }while(op != 0);
    return 0;
}

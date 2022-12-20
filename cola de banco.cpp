#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void menu();
void agregar_clientes();
void eliminar_clientes();
void volver();

int num_cliente = 0;
string cliente[10];

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}

void menu()
{
    int opcion;
    system("cls");
    cout << "\tMenu del banco" << endl;
    cout << "1- Agregar clientes a la cola." << endl;
    cout << "2- Atender clientes de la cola." << endl;
    cout << "3- Salir del programa." << endl;
    cout << "Escriba la opcion a seguir:" << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        agregar_clientes();
        break;
    case 2:
        eliminar_clientes();
        break;
    case 3:
        cout << "En este momento saldra del programa..." << endl;
        exit(1);
        break;
    default:
        cout << "Escriba un numero valido del menu." << endl;
        break;
    }
    volver();
}

void agregar_clientes()
{
    system("cls");
    char x;
    cout << "\tAgregar clientes" << endl;
    cout << "En este modulo usted agregara clientes a la cola (10 clientes maximo por cola)." << endl;
    while (num_cliente < 10)
    {
        cout << "\nEscriba el nombre del cliente No. " << num_cliente + 1 << ": ";
        cin >> cliente[num_cliente];
        num_cliente++;
        if (num_cliente < 10)
        {
            do
            {
                cout << "Desea agregar un cliente mas a la cola? (s/n)" << endl;
                cin >> x;
                if ((x == 's') || (x == 'S'))
                {
                }
                else if ((x == 'n') || (x == 'N'))
                {
                    volver();
                }
                else
                {
                    cerr << "El caracter digitado es invalido, intente de nuevo." << endl;
                }
            } while ((((x != 's') && (x != 'S')) && (x != 'n')) && (x != 'N'));
        }
    }
    cout << "\nUsted ha alcanzado el limite de la cola, es hora de vaciarla." << endl;
}

void eliminar_clientes()
{
    system("cls");
    char x;
    cout << "\tEliminar clientes" << endl;
    cout << "Los clientes formados en la cola pasaran en orden." << endl;
    if (num_cliente == 10)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "\nEl " << i + 1 << "o. cliente en la fila es " << cliente[i] << "... ";
            getch();
            cout << "y ha sido atendido.";
        }
        num_cliente = 0;
        cout << "\nTodos los clientes fueron atendidos exitosamente!" << endl;
    }
    else
    {
        cout << "\nPrimero debe llenar la fila de clientes." << endl;
    }
}

void volver()
{
    cout << endl
         << "Presione cualquier tecla para volver al menu... " << endl;
    getch();
    menu();
}

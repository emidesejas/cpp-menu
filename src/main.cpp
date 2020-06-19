#include "item.h"
#include "menu.h"
#include "menuText.h"
#include <iostream>

using namespace std;

int main()
{
    Menu* principal = new Menu("Principal");

    Menu* administrador = new Menu("Administrador");
    Menu* contratar = new Menu("Contratar a alguien");
        contratar->addItem(0, new MenuText("Contratar a el decia"));
        contratar->addItem(1, new MenuText("Contratar al alvarito y huir"));
    administrador->addItem(0, contratar);
    administrador->addItem(1, new MenuText("Despedir alguien"));
    
    Menu* docente = new Menu("Docente");
    docente->addItem(0, new MenuText("No ser del INCO y enseñar"));
    docente->addItem(1, new MenuText("Ser del INCO y no enseñar"));

    Menu* estudiante = new Menu("Estudiante");
    estudiante->addItem(0, new MenuText("Tener vida y no hacer fing"));
    estudiante->addItem(1, new MenuText("Hacer fing"));

    principal->addItem(0, administrador);
    principal->addItem(1, docente);
    principal->addItem(2, estudiante);
    int opcion = 0;
    while (opcion != 4)
    {
        principal->show();
        cin >> opcion;
        principal->selectOption(opcion);
        switch(opcion)
        {
            case 0:
            {   
                principal->show();
                cin >> opcion;
                principal->selectOption(opcion);
                switch(opcion)
                {
                    case 0:
                        //principal->show();
                        cout << "Ingrese la cedula del decia: ";
                        //cin >> opcion;
                        break;
                    case 1:
                        cout << "Despediste a alguien" << endl;
                        break;
                    default:
                        break;
                }
                principal->back();
                break;
            }
        }
        principal->back();
    }
    delete principal;
    return 0;
}
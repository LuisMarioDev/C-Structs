
#include <iostream>

using namespace std;

int main()
{
    int x=25;
    cout<<"La dirección de x es: \n " << &x;

    int *ptr1; // Apuntador a un dato de tipo entero (int)
    char *cad1, *cad2; // Dos apuntadores a datos de tipo car´acter (char)
    float *ptr2; // Apuntador a un dato de tipo punto-flotante (float)

    int i = 5;
    int *p, *q;
    p = &i; // Se le asigna a ’p’ la direcci´on de ’i’
    q = p; // Se le asigna a ’q’ la direcci´on almacenada en ’p’ (la misma de ’i’)

    int k = 17, y;
    int *u;
    u = &k;
    cout << "El valor de x es: " << *p << endl; // Imprime 17
    y = *u + 3; // A ’y’ se le asigna 20
    cout<<y<<endl;

    struct Data
    {
    char nombre[20];
    int edad;
    };

    Data d;

    Data *pd = &d;
    (*pd).edad = 23; // Acceso al campo ’edad’ utilizando el operador ’.’
    pd->edad = 23; // Acceso al campo ’edad’ utilizando el operador ’->’

    int *p1;
    float *p2;
    int z;
    p1 = &x; // Esto es v´alido
    //p2 = &x; // Esto no es v´alido (el compilador genera un error)

    float *p;
cout << "El valor apuntado por p es: " << *p << endl; // Incorrecto
*p = 3.5; // Incorrecto


    return 0;
}

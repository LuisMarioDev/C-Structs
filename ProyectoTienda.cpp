#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct producto {
    int id;
    string nombre;
    float precioCompra;
    float precioVenta;
    int existencias;
    int reorden;
    bool estado;
    producto *sig;
    producto *ant;
};

producto inventario[20] = {
    {1, "Agua", 13.39, 18.55, 12, 4, true},
    {2, "Arroz", 20.60, 31.55, 30, 8, true},
    {3, "Leche", 12.35, 15.5, 16, 5, true},
    {4, "Pan", 5.5, 7.95, 18, 6, true},
    {5, "Huevo", 22.4, 30.39, 20, 7, true},
    {6, "Aceite", 13.99, 25.75, 25, 7, true},
    {7, "Refresco", 10.99, 14.75, 30, 8, true}
};

void Administrador();
void Ventas();
void Altas();
void Bajas();
void Consultas();
void Modificaciones();
void Mostrar_inventario();
void Administracion_de_cuenta();
void Corte_de_caja_general();

int main() {
    int opcion;
    cout << "\tBIENVENIDO SEA A SU TIENDA\n" << endl;
    do {
        cout << "MENU PRINCIPAL" << endl;
        cout << "1.Administrador" << endl;
        cout << "2.Ventas" << endl;
        cout << "3.Salir" << endl << endl;
        cout << "Opción: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            Administrador();
            break;
        case 2:
            Ventas();
            break;
        case 3:
            cout << "Cerrando sistema" << endl;
            break;
        default:
            cout << "Valor inválido, ingrese una de las opciones" << endl;
        }
    } while (opcion != 3);
    return 0;
}

void Administrador() {
    int opcion;
    cout << "MENU ADMINISTRADOR" << endl;
    cout << "1.Altas" << endl;
    cout << "2.Bajas" << endl;
    cout << "3.Consultas" << endl;
    cout << "4.Modificaciones" << endl;
    cout << "5.Mostrar inventario" << endl;
    cout << "6.Administracion de cuenta" << endl;
    cout << "7.Corte de caja general" << endl;
    cout << "8.Regresar al menú anterior" << endl << endl;
    cout << "Opción: ";
    cin >> opcion;
    switch (opcion) {
    case 1:
        Altas();
        break;
    case 2:
        Bajas();
        break;
    case 3:
        Consultas();
        break;
    case 4:
        Modificaciones();
        break;
    case 5:
        Mostrar_inventario();
        break;
    case 6:
        Administracion_de_cuenta();
        break;
    case 7:
        Corte_de_caja_general();
        break;
    case 8:
        cout << "Regresando al menú anterior" << endl;
        break;
    default:
        cout << "Valor inválido, ingrese una de las opciones" << endl;
    }
}

void Ventas() {
    int opcion;
    cout << "Menu Ventas" << endl;
    cout << "1.Agua 10 litros" << endl;
    cout << "2.Arroz 12 kilos" << endl;
    cout << "3.Leche 13 litros" << endl;
    cout << "4.Pan 20 piezas" << endl;
    cout << "5.Huevo 3 paquetes" << endl;
    cout << "6.Aceite 6 piezas" << endl;
    cout << "7.Refresco 12 piezas" << endl << endl;
    cout << " Opción: ";
    cin >> opcion;
    // Aquí puedes agregar la lógica de ventas basada en la opción seleccionada
}

void Altas() {
    int i = 0;
    string k[20];
    for (i = 7; i < 20; i++) {
        cout << "Añade aquí tu nuevo producto... O presiona * para finalizar" << endl;
        cin >> k[i];
        if (k[i] == "*") {
            break;
        }
        else {
            inventario[i].nombre = k[i];
            cout << "Cual es el ID" << endl;
            cin >> inventario[i].id;
            cout << "Cual es el pc" << endl;
            cin >> inventario[i].precioCompra;
            cout << "Cual es el pv" << endl;
            cin >> inventario[i].precioVenta;
            if (inventario[i].precioCompra >= inventario[i].precioVenta) {
                cout << "El precio de compra debe ser menor al precio de venta\n" << endl;
                break;
            }
            cout << "Cuantas son las existencias" << endl;
            cin >> inventario[i].existencias;
            cout << "Cual es el reorden" << endl;
            cin >> inventario[i].reorden;
            inventario[i].estado = true;
        }
    }
}

void Bajas() {
    int i;
    string k[20];
    for (i = 7; i < 20; i++) {
        cout << "Escribe el nombre del producto a dar de baja o presiona * para finalizar" << endl;
        cin >> k[i];
        if (k[i] == "*") {
            break;
        }
        else {
            inventario[i].nombre = k[i];
            cout << "Cual es el ID" << endl;
            cin >> inventario[i].id;
            cout << "Cual es el precio de compra" << endl;
            cin >> inventario[i].precioCompra;
            cout << "Cual es el precio de venta" << endl;
            cin >> inventario[i].precioVenta;
            cout << "Cuantas son las existencias" << endl;
            cin >> inventario[i].existencias;
            cout << "Cual es el reorden" << endl;
            cin >> inventario[i].reorden;
            inventario[i].estado = true;
            cout << "Este producto ha sido dado de baja exitosamente\n" << endl;
        }
    }
}

void Consultas() {
    int i = 0, k;
    cout << "Favor de ingresar el ID del producto a consultar" << endl;
    cin >> k;
    while (inventario[i].id != k && i < 20) {
        i++;
    }
    if (i < 20) {
        cout << setw(3) << "ID" << setw(15) << "Producto" << setw(6) << "PC" << setw(6) << "PV" << setw(13) << "Existencias" << setw(9) << "Reorden" << setw(3) << "ST" << endl;
        cout << setw(3) << inventario[i].id << setw(15) << inventario[i].nombre << setw(6) << inventario[i].precioCompra << setw(6) << inventario[i].precioVenta << setw(13) << inventario[i].existencias << setw(9) << inventario[i].reorden << setw(3) << inventario[i].estado << endl;
    }
    else {
        cout << "Producto no encontrado" << endl;
    }
}

void Modificaciones() {
    int i = 0, k = 0, id_temp, nuevo_exist, nuevo_reo;
    string product_temp;
    float npc, npv;
    cout << "Introduce el ID del producto a modificar" << endl;
    cin >> id_temp;
    while (i < 20 && inventario[i].id != id_temp) {
        i++;
    }
    if (i < 20 && inventario[i].estado == true) {
        cout << "Ingrese el nuevo producto" << endl;
        cin >> product_temp;
        inventario[i].nombre = product_temp;
        cout << "Ingrese el nuevo precio de compra" << endl;
        cin >> npc;
        inventario[i].precioCompra = npc;
        cout << "Ingrese el nuevo precio de venta" << endl;
        cin >> npv;
        inventario[i].precioVenta = npv;
        cout << "Ingrese la nueva existencia" << endl;
        cin >> nuevo_exist;
        inventario[i].existencias = nuevo_exist;
        cout << "Ingrese el nuevo nivel de reorden" << endl;
        cin >> nuevo_reo;
        inventario[i].reorden = nuevo_reo;
    }
    else {
        cout << "Producto no encontrado o dado de baja" << endl;
    }
}

void Mostrar_inventario() {
    int i;
    cout << "INVENTARIO: \n" << endl;
    cout << setw(3) << "ID" << setw(15) << "Producto" << setw(6) << "PC" << setw(6) << "PV" << setw(13) << "Existencias" << setw(9) << "Reorden" << setw(3) << "ST" << endl;
    for (i = 0; i < 20; i++) {
        cout << setw(3) << inventario[i].id << setw(15) << inventario[i].nombre << setw(6) << inventario[i].precioCompra << setw(6) << inventario[i].precioVenta << setw(13) << inventario[i].existencias << setw(9) << inventario[i].reorden << setw(3) << inventario[i].estado << endl;
    }
}

void Administracion_de_cuenta() {
    string nombre, clave;
    cout << "A nombre de quien esta la nueva cuenta?\n";
    cin >> nombre;
    cout << "Ingrese la clave\n";
    cin >> clave;
}

void Corte_de_caja_general() {
    int agua, arroz, leche, pan, huevo, aceite, refresco;
    cout << "\tEstas son las ventas de hoy\n" << endl;
    cout << "1.Agua 10 litros = 185 pesos" << endl;
    cin >> agua;
    cout << "2.Arroz 12 kilos = 378 pesos" << endl;
    cin >> arroz;
    cout << "3.Leche 13 litros = 424 pesos" << endl;
    cin >> leche;
    cout << "4.Pan 20 piezas = 658 pesos" << endl;
    cin >> pan;
    cout << "5.Huevo 3 paquetes = 455 pesos" << endl;
    cin >> huevo;
    cout << "6.Aceite 6 piezas = 505 pesos" << endl;
    cin >> aceite;
    cout << "7.Refresco 12 piezas = 902 pesos" << endl << endl;
    cin >> refresco;
    // Calcular y mostrar las ventas totales aquí
    int totalVentas = agua + arroz + leche + pan + huevo + aceite + refresco;
    cout << "El total de ventas de hoy es: " << totalVentas << " pesos" << endl;
}



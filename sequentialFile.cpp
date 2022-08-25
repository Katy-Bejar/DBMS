/*
	integrantes :
	 * Béjar Román Edson Bryan
	 * Béjar Román Katherine Nikole
	 * Suni Quispe Yanira Angie
*/
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
using namespace std;
 
typedef struct{
    char id[3], nombre[20], sexo[1], ocupacion[20];
    int edad, cont;
    float est,peso;
} EMPLEADO;
 
int j = 0,i = 1,r = 0,v;
char h[30],z[10],caracter[10];

void insertar();
void consulta1();
void consulta2();
void añadir();
void menu_aux();
void menu();

void menu() {
    cout<<"\t\t MENU" <<endl;
    cout<<"1) Ingresar empleados al sistema"<<endl;
    cout<<"2) Anadir Nuevos Empleados"<<endl;
    cout<<"3) Consulta de informacion por numero de cuenta"<<endl;
    cout<<"4) Salir del sistema"<<endl;
    cout<<"Ingrese un valor: ";
    scanf("%i",&v);
    cout<<""<<endl;
    switch(v){
        case 1: insertar(); break;
        case 2: añadir(); break;
        case 3: consulta1(); break;
        case 4: cout<<"Sistema cerrado" << endl; break;
        default: printf("Numero incorrecto");
    }
}

void menu_aux(){
    cout<<"\nPresione:\n1 -> continuar: \n2 -> Salir\n"; cin>>r;
    switch(r) {
        case 1: menu(); break;
        case 2: cout<<"................................"; break;
        default: cout << "Numero incorrecto" << endl; 
    }
}

void insertar(){
    char M[]="M",m[]="m",F[]="F",f[]="f";
    FILE *file;
    EMPLEADO empleado;
    if ((file = fopen("archivo.txt", "w")) == nullptr) {
        cout << "El archivo no pudo abrirse" << endl;
    } 
    else {
        cout<<"- - - - Ingresar empleados al Sistema - - - - "<< endl;
        cout<<"\nCantidad de empleados: "; cin >> j;
        cout<<""<<endl;
        while(i<=j){ 
            cout << "\n\t\t  Empleado #" << i << endl;
            cout << "Numero de cuenta del empleado: "; cin >> empleado.id;
            cout << "Nombre: "; cin >> empleado.nombre;
            cout << "Sexo M o F: "; cin >> empleado.sexo;
            cout << "Ocupacion: "; cin >> empleado.ocupacion;
            cout << "Edad: "; cin >> empleado.edad;
            cout << "Estatura en Metros: "; cin >> empleado.est;
            cout << "Peso en Kilogramos: "; cin >> empleado.peso;
            fprintf(file,"%s %s %s %s %i %.2f %.2f\n",empleado.id,empleado.nombre,empleado.sexo, empleado.ocupacion, empleado.edad,empleado.est,empleado.peso);
            i++;
        }
        fclose(file);
   	}
	menu_aux();
}
 
void consulta1(){
    FILE *file;
    EMPLEADO empleado;
    if ((file = fopen("archivo.txt", "r")) == nullptr){
        cout << "El archivo no pudo abrirse" << endl;
    } 
    else {
        cout<<" - - - - Consulta de informacion por número de cuenta - - - - "<<endl;
        cout<<"\nIngrese el número de cuenta del empleado a buscar: "; cin>>h; rewind(file);
        int cont = 1;
        cout<<"\n----------------------------------------------------------------------------------\n";
        cout<<"| "<<left<<setw(8)<<"Codigo"<< "| "<<left<<setw(20)<<"Nombre del Empleado"<< "| "<<left<<setw(5)<<"Sexo"<<"| "<< "Ocupacion "<< "| "<<left<<setw(5)<<"Edad"<< "| "<<left<<setw(9)<<"Estatura"<<"| "<<left<<setw(5)<<"Peso "<<"| ";
        cout<<"\n----------------------------------------------------------------------------------\n";
        while (cont <= j) {
            fscanf(file,"%s %s %s %i %f %f\n",empleado.id,empleado.nombre,empleado.sexo,&empleado.edad,&empleado.est,&empleado.peso);
            if (strcmp(empleado.id, h) == 0) {
                cout<<"| "<<left<<setw(7)<<empleado.id<<"| "<<left<<setw(20)<<empleado.nombre<<"| "<<left<<setw(5)<<empleado.sexo<<"| " <<left<<setw(5)<<empleado.ocupacion<<left<<setw(5)<<empleado.edad<<"| "
                <<left<<setw(9)<<empleado.est<<"| "<<left<<setw(5)<<empleado.peso<<"| ";
                cout<<"\n----------------------------------------------------------------------------------\n";
            }
            cont++;
        }
        fclose(file);
    }
    menu_aux();
}
//scanf
void añadir(){
    char M[]="M",m[]="m",F[]="F",f[]="f";
    FILE *file;
    EMPLEADO empleado;
    file = fopen("archivo.txt", "a");
 
    cout<<" - - - - Ingresar mas empleados al Sistema - - - - "<<endl;
    cout<<"\n¿Cuantos empleados desea ingresar en el sistema?: "; cin>>j;
    cout<<""<<endl;
    while(i<=j) {
        cout << "\n\t\t  Empleado #" << i << endl;
        cout << "Numero de cuenta: "; cin >> empleado.id;
        cout << "Nombre : "; cin >> empleado.nombre;
        cout << "Sexo Masculino[M] o Femenino[F]: "; cin >> empleado.sexo;
        cout << "Ocupacion : "; cin >> empleado.ocupacion;
        cout << "Edad : "; cin >> empleado.edad;
        cout << "Estatura en Metros: "; cin >> empleado.est;
        cout << "Peso en Kilogramos: "; cin >> empleado.peso; 
        fprintf(file,"%s %s %s %i %.2f %.2f\n",empleado.id, empleado.nombre, empleado.sexo, empleado.ocupacion, empleado.edad, empleado.est, empleado.peso);
        i++;
    }
    fclose(file);
    menu_aux();
}

int main(){
    menu();
}
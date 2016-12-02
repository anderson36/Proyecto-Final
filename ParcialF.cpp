/* Nombre: Jhon Anderson Sanchez Buritica
    Fecha: 01-12-2016
    Programa: Estructuras de datos
    Docente: Carlos londoño*/

/* NOTA:  PARA INGRESAR AL PROGRAMA REQUIERE USUARIO Y PASSWORD

    USUARIO: "admin"
    PASSWORD: "jhon"
       */
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void CrearU();
void EliminarU();
void Info();
void BuscarU();
void modificaciones();
void salir();
void MenuU();
void login();
void adm();
void menu();
void MenuP();
//Funciones de ventas
void MenuV();
void CrearV();
void EditarV();
void EliminarV();
void ListaV();
//Funciones de productos
void EliminarP();
void EditarP();
void BuscarP();
void CrearP();
//Variables Globales
char nombre[30];
char usuario[10];
char password[30];
char fecha[30];
char tipoU[30];
int id=0;
int auxid=0;
bool encontrado=false;
char auxUS[10];
char auxPASS[10];
//variables Productos
char nombrep[30];
int valor;
int cantidad;
int medida;
int idp;
int auxidp;
//vareables ventas
int ctotal;
int total;

int main(){
    adm();
    login();
    return 0;
    system("PAUSE");
}
void MenuU(){
    int opcion=0;
    do{
        cout << "BIENVENIDOS AL MENU DEL ADMINISTADOR" << endl;
        cout << "1- CREAR USUARIO NUEVO" << endl;
        cout << "2- LISTA DE USUARIOS" << endl;
        cout << "3- EDITAR / MODIFICAR USUARIOS" << endl;
        cout << "4- VER INFORMACION DE USUARIO" << endl;
        cout << "5- ELIMINAR USUARIO" << endl;
        cout << "6- CERRAR SESION" << endl;
        cout << "7- VOLVER AL MENU PRINCIPAL" << endl;
        cout << "8- FINALIZAR PROGRAMA" << endl;
        cout << "Que Deseas Hacer?" << endl;
            cout<<"Que deseas hacer? ";
        cin>>opcion;
        system("cls");
        switch(opcion){
            case 1:
                CrearU();
            break;
            case 2:
                BuscarU();
            break;
            case 3:
                modificaciones();
            break;
            case 4:
                Info();
            break;
            case 5:
                EliminarU();
            break;
            case 6:
                login();
            break;
            case 7:
                menu();
            break;
            default:
                cout<<"¡Opcion Incorrecta!"<<endl;
        }
    }while(opcion!=8);
}//Fin funcion menu
void CrearU(){
    ofstream escritura;
    ifstream consulta;
    bool repetido=false;
    escritura.open("USUARIOS.txt",ios::out|ios::app);
    consulta.open("USUARIOS.txt",ios::in);
    if(escritura.is_open() && consulta.is_open()){
        cout<<"Ingresa la id del usuario: ";
        cin>>auxid;
        consulta>>id;
        while(!consulta.eof()){
            consulta>>nombre>>usuario>>password>>fecha>>tipoU;
            if(id==auxid){
                cout<<"Ya Existe un Registro con esta id"<<endl;
                repetido=true;
                break;
            }
            consulta>>id;
        }
        if(repetido==false){
            cout<<"Ingresa el nombre completo: ";
            cin>>nombre;
            cout<<"Ingresa el usuario: ";
            cin>>usuario;
            cout<<"Ingresa La contrasena: ";
            cin>>password;
            cout<<"Ingresa la fecha de creacion: ";
            cin>>fecha;
            cout<<"Ingresa el tipo de usuario: ";
            cin>>tipoU;
            escritura<<auxid<<" "<<nombre<<" "<<usuario<<" "<<password<<" "<<fecha<<" "<<tipoU<<endl;
            cout<<"Registro Agreagado"<<endl;
        }

    }else{
        cout<<"Error, el Archivo No se Pudo Abrir o No ha sido Creado"<<endl;
    }
    escritura.close();
    consulta.close();
}//Fin funcion altas

void BuscarU(){
    ifstream lectura;
    lectura.open("USUARIOS.txt",ios::out|ios::in);
    if(lectura.is_open()){
        cout<<"Registros del Archivo usuarios.txt"<<endl;
        cout<<"________________________________"<<endl;
        lectura>>id;
        while(!lectura.eof()){
            lectura>>nombre>>usuario>>password>>fecha>>tipoU;
            cout<<"ID: "<<id<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"USUARIO: "<<usuario<<endl;
            cout<<"Password: "<<password<<endl;
            cout<<"Fecha-creacion: "<<fecha<<endl;
            cout<<"Tipo de usuario: "<<tipoU<<endl;
            lectura>>id;
            cout<<"________________________________"<<endl;
        }
    }else{
        cout<<"Error, el Archivo No se Pudo Abrir, No ha sido creado"<<endl;
    }
    lectura.close();
}//Fin funcion consultas


void Info(){
    ifstream lectura;//Creamos la variable de tipo lectura
    lectura.open("USUARIOS.txt",ios::out|ios::in);//Abrimos el archivo
    //validando la apertura del archivo
    encontrado=false;
    if(lectura.is_open()){
        cout<<"Ingresa la Clave del Alumno que deseas Buscar: ";
        cin>>auxUS;
        lectura>>id;//lectura adelantada

        while(!lectura.eof()){
            lectura>>nombre>>usuario>>password>>fecha>>tipoU;//leyendo los campos del registro
            //Comparar cada registro para ver si es encontrado
            if(strcmp(auxUS,usuario)==0){
                cout<<"______________________________"<<endl;
                cout<<"Clave: "<<id<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Semestre: "<<usuario<<endl;
                cout<<"Grupo: "<<password<<endl;
                cout<<"Edad: "<<fecha<<endl;
                cout<<"Edad: "<<tipoU<<endl;
                cout<<"______________________________"<<endl;
                encontrado=true;
            }

            lectura>>id;//lectura adelantada
        }
        if(encontrado==false){
            cout<<"No hay registros con la Clave "<<auxid<<endl;
        }
    }else{
        cout<<"No se pudoAbrir el Archivo, aun no ha sido Creado"<<endl;
    }
    //cerrando el archivo
    lectura.close();
}
void modificaciones(){// Esta funciom me esta presentando algunos inconvenientes que no he podido encontrarle la solucion
    ofstream aux;
    ifstream lectura;
    encontrado=false;
    //int auxid=0;
    char auxNombre[30];
    aux.open("auxiliar.txt",ios::out);
    lectura.open("USUARIOS.txt",ios::in);
    if(aux.is_open() && lectura.is_open()){
        cout<<"Ingresa la ID del usuario que deseas Modificar: ";
        cin>>auxid;
        lectura>>id;
        while(!lectura.eof()){
            lectura>>nombre>>usuario>>password>>fecha>>tipoU;
            if(auxid==id){
                encontrado=true;
                cout<<"__________________________"<<endl;
                cout<<"ID: "<<id<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"usuario: "<<usuario<<endl;
                cout<<"password: "<<password<<endl;
                cout<<"fecha: "<<fecha<<endl;
                cout<<"tipo de usuario: "<<tipoU<<endl;
                cout<<"__________________________"<<endl;
                cout<<"Ingresa el Nuevo Nombre del usuario con id "<<id<<":"<<endl;
                cin>>auxNombre;
                aux<<id<<" "<<auxNombre<<" "<<usuario<<" "<<password<<" "<<fecha<<" "<<tipoU<<endl;
                cout<<"Registro Modificado"<<endl;
            }else{
                aux<<id<<" "<<nombre<<" "<<usuario<<" "<<password<<" "<<fecha<<" "<<tipoU<<endl;
            }
            lectura>>id;
        }
    }else{
        cout<<"No se pudo Abrir el Archivo o aun no ha sido Creado"<<endl;
    }
    if(encontrado==false){
        cout<<"No se encontro ningun registro con id "<<auxid<<endl;
    }
    aux.close();
    lectura.close();
    remove("USUARIOS.txt");
    rename("auxiliar.txt","USUARIOS.txt");

}

void EliminarU(){// Esta funciom me esta presentando algunos inconvenientes que no he podido encontrarle la solucion
    ofstream aux;
    ifstream lectura;
    encontrado=false;
    int auxid=0;
    char auxNombre[30];
    aux.open("auxiliar.txt",ios::out);
    lectura.open("USUARIOS.txt",ios::in);
    if(aux.is_open() && lectura.is_open()){
        cout<<"Ingresa la Clave del Alumno que deseas Modificar: ";
        cin>>auxid;
        lectura>>id;
        while(!lectura.eof()){
            lectura>>nombre>>usuario>>password>>fecha>>tipoU;
            if(auxid==id){
                encontrado=true;

                cout << "EL Usuario" << usuario << "Ha sido Eliminado correctamente" << endl;
            }else{
                aux<<id<<" "<<nombre<<" "<<usuario<<" "<<password<<" "<<fecha<<" "<<tipoU<<endl;
            }
            lectura>>id;
        }
    }else{
        cout<<"No se pudo Abrir el Archivo o aun no ha sido Creado"<<endl;
    }
    if(encontrado==false){
        cout<<"No se encontro ningun registro con id "<<auxid<<endl;
    }
    aux.close();
    lectura.close();

    remove("USUARIOS.txt");
    rename("auxiliar.txt","USUARIOS.txt");

}

void adm(){//Esta funcion Da una Cuenta de administrador predeterminada la cual tiene datos por defecto

    ofstream escritura;
    ifstream consulta;
    bool repetido=false;
    escritura.open("USUARIOS.txt",ios::out|ios::app);
    consulta.open("USUARIOS.txt",ios::in);
    if(escritura.is_open() && consulta.is_open()){
            consulta>>id;
            while(!consulta.eof()){
            consulta>>nombre>>usuario>>password>>fecha>>tipoU;
            if(id==1112781417){

                repetido=true;
                break;
            }
            consulta>>id;
        }
        if(repetido==false){
            escritura<<"1112781417"<<" "<<"Administrador"<<" "<<"admin"<<" "<<"jhon"<<" "<<"19-02-2016"<<" "<<"ADMISTRADOR"<<endl;
            /*escritura<<"Administrador"<<"\t"<<endl;
            escritura<<"admin"<<"\t"<<endl;
            escritura<<"jhon"<<"\t"<<endl;
            escritura<<"01-12-2016"<<"\t"<<endl;
            escritura <<"ADMINISTRADOR"<<"\t"<< endl;*/

        }else{
            cout<<  " LOGIN DE USUARIO" << endl;
        }
        escritura.close();
        consulta.close();
    }
}

void login(){//Funcion que permite loguarse para ingresar al programa
      ifstream lectura;//Creamos la variable de tipo lectura
    lectura.open("USUARIOS.txt",ios::out|ios::in);//Abrimos el archivo
    //validando la apertura del archivo
    encontrado=false;
    if(lectura.is_open()){
        cout<<"USUARIO; ";
        cin>>auxUS;
        cout<<"PASSWORD ";
        cin>>auxPASS;
        lectura>>id;//lectura adelantada

        while(!lectura.eof()){
            lectura>>nombre>>usuario>>password>>fecha>>tipoU;//leyendo los campos del registro
            //Comparar cada registro para ver si es encontrado
            if(strcmp(auxUS,usuario)==0 && strcmp(auxPASS,password)==0){
                cout<<"______________________________"<<endl;
                cout<<"Ha Ingresado al sistema" << endl;
                menu();
                cout<<"______________________________"<<endl;
                auxUS[10]={'a'};
                encontrado=true;
            }

            lectura>>id;//lectura adelantada
        }
        if(encontrado==false){
            cout<<"usuario o contraseña incorrecto "<<auxid<<endl;

            login();
        }
    }else{
        cout<<"No se pudoAbrir el Archivo, aun no ha sido Creado"<<endl;
    }
    //cerrando el archivo
    lectura.close();
}


void salir(){
    cout<<"Programa Finalizado"<<endl;
}

void menu(){// menu principal del programa
    int op=0;
    do{
    cout <<" HAS INIACIADO EL PROGRAMA BIENVENIDO" << endl;
    cout <<" ______________________________________" << endl;

    cout << " ******************************"<< endl;
    cout << " ********MENU PRINCIPAL********"<< endl;
    cout << " ******************************"<< "\t"<< endl;

    cout << "1- Administrar USUARIOS" << endl;
    cout << "2- Administrar PRODUCTOS"<< endl;
    cout << "3- Administrar VENTAS"<< endl;
    cout << "4- CERRAR SESION"<< endl;
    cout << "5- FINALIZAR PROGRAMA"<< endl;
    cout << "Que Desea Hacer?"<< endl;
    cin >> op;
    system("cls");
    switch (op){
            case 1:
                MenuU();
            break;
            case 2:
                MenuP();
            break;
            case 3:
                MenuV();
            break;
            case 4:
                login();
            break;

            default:
                cout<<"¡Opcion Incorrecta!"<<endl;
        }
    }while(op!=5);


}

void MenuV(){//Menu de la venta ventas
    int op1=0;
    do{
    cout << "BIENVENIDOS AL MENU DE VENTAS" << endl;
    cout << "------------------------------" << endl;
    cout << "1- CREAR VENTA" << endl;
    cout << "2- EDITAR VENTA"<< endl;
    cout << "3- ELIMINAR VENTAS"<< endl;
    cout << "4- LISTA DE VENTAS"<< endl;
    cout << "5- VOLVER AL MENU PRINCIPAL"<< endl;
    cout << "Que Desea Hacer?"<< endl;
    cin >> op1;
    system("cls");
    switch (op1){
            case 1:
                CrearV();
            break;
            case 2:
                EditarV();
            break;
            case 3:
                EliminarV();
            break;
            case 4:
                ListaV();
            break;
            case 5:
                menu();
            break;

            default:
                cout<<"¡Opcion Incorrecta!"<<endl;
        }
    }while(op1!=6);


}

void CrearV(){//Crea ventas que parte de la id de algun producto

    ofstream ventas;
    ifstream lectura;
    encontrado=false;

    ventas.open("ventas.txt",ios::out|ios::app);
    lectura.open("productos.txt",ios::in);

    if(lectura.is_open() && ventas.is_open()){
            cout <<"ingrese el id del producto"<<endl;
            cin>>auxidp;
            lectura>>idp;
            while(!lectura.eof()){
            lectura>>nombrep>>valor>>cantidad>>medida>>fecha>>usuario;


            if(auxidp==idp){
                encontrado=true;
                cout<<"ingrese la cantidad que desea comprar" << endl;
                cin>>ctotal;
                total=valor*ctotal;
                ventas<<idp<<" "<<nombrep<<" "<<" "<<valor<<" "<<ctotal<<" "<<total;
                break;
            }
            lectura>>idp;
            }
            if(encontrado==false){
               cout<<"no se encontro ningun producto con esta id"<<endl;
            }
        }else{
        cout<<"Error, el Archivo No se Pudo Abrir o No ha sido Creado"<<endl;
        }
    ventas.close();
    lectura.close();
}

void ListaV(){// muestra las ventas que se han realizado
        ifstream lectura;
        lectura.open("ventas.txt",ios::out|ios::in);
        if(lectura.is_open()){
            cout<<"Registros de los ventas.txt"<<endl;
            cout<<"________________________________"<<endl;
            lectura>>idp;
            while(!lectura.eof()){
                lectura>>nombrep>>valor>>ctotal>>total;
                cout<<"ID: "<<idp<<endl;
                cout<<"Nombre: "<<nombrep<<endl;
                cout<<"Valor del producto: "<<valor<<endl;
                cout<<"cantidad: "<<ctotal<<endl;
                cout<<"Valor a pagar: "<<total<<endl;

                lectura>>idp;
                cout<<"________________________________"<<endl;
            }
        }else{
            cout<<"Error, el Archivo No se Pudo Abrir, No ha sido creado"<<endl;
        }
        lectura.close();
}//Fin funcion consultas

void EditarV(){// edita el nombre de las ventas "por ahora solo permite modificar el nombre

    ofstream aux;
    ifstream lectura;
    encontrado=false;
    int auxidv=0;
    char auxNombrep[30];
    aux.open("auxiliarv.txt",ios::out);
    lectura.open("ventas.txt",ios::in);
    if(aux.is_open() && lectura.is_open()){
        cout<<"Ingresa la ID del usuario que deseas Modificar: ";
        cin>>auxidv;
        lectura>>idp;
        while(!lectura.eof()){
            lectura>>nombrep>>valor>>ctotal>>total;
            if(auxidv==idp){
                encontrado=true;
                cout<<"__________________________"<<endl;
                cout<<"ID: "<<idp<<endl;
                cout<<"Nombre: "<<nombrep<<endl;
                cout<<"valor: "<<valor<<endl;
                cout<<"cantidad: "<<ctotal<<endl;
                cout<<"cantidad total a pagar: "<<total<<endl;

                cout<<"__________________________"<<endl;
                cout<<"Ingresa el Nuevo Nombre del producto con id "<<id<<":"<<endl;
                cin>>auxNombrep;
                aux<<idp<<" "<<auxNombrep<<" "<<valor<<" "<<ctotal<<" "<<total<<endl;
                cout<<"Registro Modificado"<<endl;
            }else{
                aux<<idp<<" "<<nombrep<<" "<<valor<<" "<<ctotal<<" "<<total<<endl;
            }
            lectura>>idp;
        }
    }else{
        cout<<"No se pudo Abrir el Archivo o aun no ha sido Creado"<<endl;
    }
    if(encontrado==false){
        cout<<"No se encontro ningun registro con id "<<auxidp<<endl;
    }
    aux.close();
    lectura.close();
    remove("ventas.txt");
    rename("auxiliarv.txt","ventas.txt");

}

void EliminarV(){// elimina las ventas

    ofstream aux;
    ifstream lectura;
    encontrado=false;
    int auxidv=0;
    char auxNombrep[30];
    aux.open("auxiliarv.txt",ios::out);
    lectura.open("ventas.txt",ios::in);
    if(aux.is_open() && lectura.is_open()){
        cout<<"Ingresa la ID del usuario que deseas Modificar: ";
        cin>>auxidv;
        lectura>>idp;
        while(!lectura.eof()){
            lectura>>nombrep>>valor>>ctotal>>total;
            if(auxidv==idp){
                encontrado=true;

                cout<<"Registro ha sido eliminado"<<endl;
            }else{
                aux<<idp<<" "<<nombrep<<" "<<valor<<" "<<ctotal<<" "<<total<<endl;
            }
            lectura>>idp;
        }
    }else{
        cout<<"No se pudo Abrir el Archivo o aun no ha sido Creado"<<endl;
    }
    if(encontrado==false){
        cout<<"No se encontro ningun registro con id "<<auxidp<<endl;
    }
    aux.close();
    lectura.close();
    remove("ventas.txt");
    rename("auxiliarv.txt","ventas.txt");

}


void MenuP(){//Menu de las venta de productos
    int op2=0;
    do{
    cout << "BIENVENIDO AL MENU DE PRODUCTOS" << endl;
    cout << "-------------------------------" << endl;
    cout << "1- CREAR PRODUCTO"<< endl;
    cout << "2- EDITAR PRODUCTO"<< endl;
    cout << "3- ELIMINAR PRODUCTO"<< endl;
    cout << "4- VER LISTA DE PRODUCTOS"<< endl;
    cout << "5- VOLVER AL MENU PRINCIPAL"<< endl;
    cout << "Que Desea Hacer?"<< endl;
    cin >> op2;
    system("cls");
    switch (op2){
            case 1:
                CrearP();
            break;
            case 2:
                EditarP();
            break;
            case 3:
                EliminarP();
            break;
            case 4:
                BuscarP();
            break;
            case 5:
                menu();
            break;

            default:
                cout<<"¡Opcion Incorrecta!"<<endl;
        }
    }while(op2!=6);

}

void CrearP(){// crear un producto se basa en la id del producto --- no deja crear dos productos con la misma id

    ofstream escritura;
    ifstream consulta;
    bool repetido=false;
    escritura.open("productos.txt",ios::out|ios::app);
    consulta.open("productos.txt",ios::in);
    if(escritura.is_open() && consulta.is_open()){
        cout<<"Ingresa la id del usuario: ";
        cin>>auxidp;
        consulta>>idp;
        while(!consulta.eof()){
            consulta>>nombrep>>valor>>cantidad>>medida>>fecha>>usuario;
            if(idp==auxidp){
                cout<<"Ya Existe un Pruducto con esta id"<<endl;
                repetido=true;
                break;
            }
            consulta>>idp;
        }
        if(repetido==false){
            cout<<"Ingresa el nombre del producto: ";
            cin>>nombrep;
            cout<<"Ingresa el Valor del producto: ";
            cin>>valor;
            cout<<"Ingresa La la cantidad: ";
            cin>>cantidad;
            cout<<"Ingresa la medida: ";
            cin>>medida;
            cout<<"Ingresa el Fecha de creacion: ";
            cin>>fecha;
            cout<<"Ingresa el Nombre del usuario: ";
            cin>>usuario;
            escritura<<auxidp<<" "<<nombrep<<" "<<valor<<" "<<cantidad<<" "<<medida<<" "<<fecha<<" "<<usuario<<endl;
            cout<<"Registro Agreagado"<<endl;
        }

    }else{
        cout<<"Error, el Archivo No se Pudo Abrir o No ha sido Creado"<<endl;
    }
    escritura.close();
    consulta.close();
}//Fin funcion altas

void BuscarP(){// busca productos creados previamente
    ifstream lectura;
    lectura.open("productos.txt",ios::out|ios::in);
    if(lectura.is_open()){
        cout<<"Registros de los productos.txt"<<endl;
        cout<<"________________________________"<<endl;
        lectura>>idp;
        while(!lectura.eof()){
            lectura>>nombrep>>valor>>cantidad>>medida>>fecha>>usuario;
            cout<<"ID: "<<idp<<endl;
            cout<<"Nombre: "<<nombrep<<endl;
            cout<<"Valor: "<<valor<<endl;

            lectura>>idp;
            cout<<"________________________________"<<endl;
        }
    }else{
        cout<<"Error, el Archivo No se Pudo Abrir, No ha sido creado"<<endl;
    }
    lectura.close();
}//Fin funcion consultas

void EditarP(){// edita los productos creado "por ahora solo permite editar los nombre
    ofstream aux;
    ifstream lectura;
    encontrado=false;
    //int auxid=0;
    char auxNombrep[30];
    aux.open("auxiliarp.txt",ios::out);
    lectura.open("productos.txt",ios::in);
    if(aux.is_open() && lectura.is_open()){
        cout<<"Ingresa la ID del usuario que deseas Modificar: ";
        cin>>auxidp;
        lectura>>idp;
        while(!lectura.eof()){
            lectura>>nombrep>>valor>>cantidad>>medida>>fecha>>usuario;
            if(auxidp==idp){
                encontrado=true;
                cout<<"__________________________"<<endl;
                cout<<"ID: "<<idp<<endl;
                cout<<"Nombre: "<<nombrep<<endl;
                cout<<"Valor: "<<valor<<endl;
                cout<<"Cantidad: "<<cantidad<<endl;
                cout<<"Medida: "<<medida<<endl;
                cout<<"fecha-creacion: "<<fecha<<endl;
                cout<<"Usuario: "<<usuario<<endl;
                cout<<"__________________________"<<endl;
                cout<<"Ingresa el Nuevo Nombre del usuario con id "<<id<<":"<<endl;
                cin>>auxNombrep;
                aux<<idp<<" "<<auxNombrep<<" "<<valor<<" "<<cantidad<<" "<<medida<<" "<<fecha<<" "<<usuario<<endl;
                cout<<"Registro Modificado"<<endl;
            }else{
                aux<<idp<<" "<<nombrep<<" "<<valor<<" "<<cantidad<<" "<<medida<<" "<<fecha<<" "<<usuario<<endl;
            }
            lectura>>idp;
        }
    }else{
        cout<<"No se pudo Abrir el Archivo o aun no ha sido Creado"<<endl;
    }
    if(encontrado==false){
        cout<<"No se encontro ningun registro con id "<<auxidp<<endl;
    }
    aux.close();
    lectura.close();
    remove("productos.txt");
    rename("auxiliarp.txt","productos.txt");

}

void EliminarP(){// elimina productos
    ofstream aux;
    ifstream lectura;
    encontrado=false;
    //int auxid=0;
    char auxNombrep[30];
    aux.open("auxiliarp.txt",ios::out);
    lectura.open("productos.txt",ios::in);
    if(aux.is_open() && lectura.is_open()){
        cout<<"Ingresa la ID del usuario que deseas Modificar: ";
        cin>>auxidp;
        lectura>>idp;
        while(!lectura.eof()){
            lectura>>nombrep>>valor>>cantidad>>medida>>fecha>>usuario;
            if(auxidp==idp){
                encontrado=true;
               cout <<"el pruducto se ha eliminado correctamente" << endl;
            }else{
                aux<<idp<<" "<<nombrep<<" "<<valor<<" "<<cantidad<<" "<<medida<<" "<<fecha<<" "<<usuario<<endl;
            }
            lectura>>idp;
        }
    }else{
        cout<<"No se pudo Abrir el Archivo o aun no ha sido Creado"<<endl;
    }
    if(encontrado==false){
        cout<<"No se encontro ningun registro con id "<<auxidp<<endl;
    }
    aux.close();
    lectura.close();
    remove("productos.txt");
    rename("auxiliarp.txt","productos.txt");

}



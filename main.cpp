
/*Proyecto final de Programacion esencial C++
Inventario de dispositivos IOT en el hogas

Proyecto realizado por: 
Javier Sanchez Gomez
Otto Arias Blanco

Sistema para el monitoreo de consumo de 4 
dispositivos IOT

*/







#include<iostream>
#include<stdlib.h>  //incluir librerias
#include<string>


using namespace std;

class Dispositivo{       //Declaracion de variables y metodos                 

private: 
        string nombre, tipo;
        int consumo, tiempoConsumo, tiempoConsumoWH; //Condiciones permanentes del programa
public:
    Dispositivo();

    void setNombre(string _nombre); //Condicion para declarar y representar los 
    string getNombre();              //caracteres ingresados por el usuario

    void setTipo(string _tipo);
    string getTipo();  // metodo para obtener los valores

    void setConsumo(int _consumo);
    int getConsumo();

    void setTiempoConsumo(int _tiempoConsumo);
    int getTiempoConsumo();

    void setTiempoWH(int _consumo, int _tiempoConsumo);
    int getTiempoWH();
};

Dispositivo:: Dispositivo(){

}

void Dispositivo:: setNombre(string _nombre){  //Declaracion de variables
  nombre = _nombre;                            //string y variables int
}

void Dispositivo:: setTipo(string _tipo){
  tipo = _tipo;
}

void Dispositivo:: setConsumo(int _consumo){
  consumo = _consumo;
}

void Dispositivo:: setTiempoConsumo(int _tiempoConsumo){
  tiempoConsumo = _tiempoConsumo;
}

void Dispositivo:: setTiempoWH(int _consumo, int _tiempoConsumo){
  tiempoConsumoWH = _consumo * tiempoConsumo;
}

string Dispositivo:: getNombre(){
  return nombre ;
}

string Dispositivo:: getTipo(){
  return tipo;
}

int Dispositivo:: getConsumo(){
  return consumo;
}

int Dispositivo:: getTiempoConsumo(){
  return tiempoConsumo;
}

int Dispositivo:: getTiempoWH(){
  return tiempoConsumoWH;
}

int main()
{
  // Variables para el menu1 (inventario), menu2 (Seguir o salir), y la posicion de los dispositivos
  int opcion, opc2, posicion = 0;
  string nombre, tipo;
  int consumo, tiempoDeUso;
  int totalWHL, totalWHC, totalWHT, totalWHA = 0;

  Dispositivo dispositivos[4];
  
  Dispositivo dispositivo;

do{
//Mensajes del menu para el inventario
  cout<<"\n*********Inventario de Dispositos IoT*********";
  cout<<"\n1. Agregar inventario";
  cout<<"\n2. Agregar tiempo de consumo por dispositivo..";
  cout<<"\n3. Ver dispositivos agregados.";
  cout<<"\n4. Salir.";
  cout<<"\nIngrese su opcion: ";
  cin>>opcion;
// Case de las diferentes opciones para validar datos ingresados por el usuario
switch(opcion) 
{
  case 1:  

    cout<<"\nIngrese nombre del nuevo dispositivo sin espacios: "; 
    cin>>nombre;

    cout<<"\nIngrese el tipo del dispositivo, digite alguno de estos tipos: Luz, Tomas, Camaras, o Aires."; 
    cin>>tipo;

    cout<<"\nIngrese el consumo del dispositivo: "; 
    cin>>consumo;

    //Se llena el objeto con los datos ingresados por el usuario
    dispositivo.setNombre(nombre);
    dispositivo.setTipo(tipo);
    dispositivo.setConsumo(consumo);

    dispositivos[posicion] = dispositivo;
    posicion++;

    cout<<"\nIngrese 1 para volver al menu y 0 para salir: ";
    cin>>opc2;
  break;

  //Case para agregar el tiempo de funcionamiento de los dispositivos
  case 2:
      
      for(int i = 0; i < 4; i++){
        tiempoDeUso = 0;
        cout<<"\nAgregar tiempo de consumo del dispositivo: "<<dispositivos[i].getNombre()
        <<endl;
        cin>>tiempoDeUso;
        dispositivos[i].setTiempoConsumo(tiempoDeUso);
        dispositivos[i].setTiempoWH(dispositivos[i].getConsumo(), tiempoDeUso);
      }

      cout<<"\nIngrese 1 para volver al menu y 0 para salir: ";
      cin>>opc2;
  break;



// Case para obtener en pantalla los dispositivos registrados
  case 3:
    
    for (int i = 0; i < 4; i++)
      {
        cout<<"\nNombre de dispositivo: "<<dispositivos[i].getNombre()<<endl;
        cout<<"Tipo de dispositivo: "<<dispositivos[i].getTipo()<<endl;
        cout<<"Consumo de dispositivo: "<<dispositivos[i].getConsumo()<<" Watts" <<endl;
        cout<<"Tiempo de consumo del dispositivo: "<< dispositivos[i].getTiempoConsumo()<< " horas" <<endl;
        cout<<"Consumo WH: "<<dispositivos[i].getTiempoWH()<< " Watts-horas" <<endl;
      }
      cout<<"\nIngrese 1 para volver al menu y 0 para salir: ";
      cin>>opc2;
  break;



//Case para volver al menu de inventario o salir del programa
  case 4:

    return 0;
    
  default: cout << "Ha elegido una opcion invalida.";
	cout<<"\nIngrese 1 para volver al menu y 0 para salir: ";
	cin>>opc2;
}
} while(opc2 == 1);

}
#include <iostream>
#include <fstream>

using namespace std;
fstream miArchivo;//variable global para entrada y salida de datos 
string nombreArchivo,escritura,texto;//estructura de cadena de c++ cadenas de caracteres
void escribir();
void leer2();
int main(int argc, char** argv) {
	
	escribir();
	leer2();
	return 0;
}




void escribir(){
//	ofstream miArchivo;//salida
	
cout<<"Como se llama el archivo"<<endl;

	getline(cin,nombreArchivo);//getline se ocupa con string/cadenas
	//miArchivo.open("documento/texto.txt",ios::out);//nos puede ayudar a cambiar la ruta de almacenaje
		nombreArchivo+=".txt";

	//miArchivo.open("texto.txt", ios::out);
	miArchivo.open(nombreArchivo.c_str(), ios::out);//nos puede ayudar a cambiar la ruta de almacenaje
	
	if(!miArchivo.fail()){
		//codigo
		cout<<"todo OK"<<endl;
			
		cout<<"Escribe en el archivo, si ya terminaste escribe'salir'"<<endl;		
		while(true){//ciclo 	
	getline(cin,escritura);
	if(escritura=="salir")//si la escritura es igual a salir se acaba el programa
	break;
	texto+=escritura+'\n';//suma el texto y los saltos de linea
}
			miArchivo<<texto<<endl;//guarda en 'texto' lo que se escribio
	miArchivo.close();//cierra el archivo
	}
	else{
		cout<<"error al abrir el archivo "<<endl;
		exit(2);	
	}			
}

void leer()
{
	
	int linea=0;
//	ifstream miArchivo;//entrada 
	string ruta="lista.txt";
	string texto;
	miArchivo.open(ruta.c_str(),ios::in);
	cout<<"que linea quieres leer";
	cin>>linea;
	int i=0;
	while(i!=linea){
		getline(miArchivo,texto);
		i++;
	}
	cout<<texto<<endl;
	cout<<"tu archivo tiene"<<i<<"lineas"<<endl;
	miArchivo.close();
	while (!miArchivo.eof()){
	
	getline(miArchivo,texto);
	cout<<texto<<endl;
	

}

	miArchivo.close();
}

void leer2(){

cout<<"como se llama el archivo"<<endl;
	getline(cin,nombreArchivo);//getline se ocupa con string/cadenas
	//miArchivo.open("documento/texto.txt",ios::out);//nos puede ayudar a cambiar la ruta de almacenaje
		
		miArchivo.open(nombreArchivo.c_str(), ios::in);
		if(miArchivo.is_open()){
		char c;
		while(!miArchivo.eof())	
		{
			c=miArchivo.get();
			cout<<c;
			
		}miArchivo.close();
		}else{
		
		cout<<"no se encontro el archivo";
	}
		}

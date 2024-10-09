#include <iostream>
using namespace std;

class Pelicula{
	
	private:
		
		string nombre;
		string genero;
		int duracion;
		
	public:
		
		Pelicula(string nombre, string genero, int duracion){
			
			this->nombre = nombre;
			this->genero = genero;
			this->duracion = duracion;
		}
		
		string getNombre(){
			
			return nombre;
		}
		
		string getGenero(){
			
			return genero;
		}
		
		int getDuracion(){
			
			return duracion;
		}
};

class Maraton{
	
	private:
		
		Pelicula *m[10];
		
	public:
		
		Maraton(){
			
			for(int i=0; i<10; i++){
				
				m[i] = NULL;
			}
		}
		
		void agregarPelicula(Pelicula *p){
			
			bool si = false;
			
			for(int i=0; i<10; i++){
				
				if(m[i] == NULL){
					
					si = true;
					m[i] = p;
					break;
				}
			}
			
			if(si){
				
				cout<<"Pelicula ingresada con exito."<<endl;
			}
			else{
				
				cout<<"No queda espacio en la lista."<<endl;
			}
			
			cout<<endl;
		}
		
		void ordenarPelicula(){
			
			for(int i=0; i<10; i++){
				
				for(int j=i+1; j<11; j++){
					
					if(m[i] != NULL && m[j] != NULL){
						
						if(m[i]->getDuracion() > m[j]->getDuracion()){
						
						Pelicula *aux[1];
						
						aux[0] = m[i];
						m[i] = m[j];
						m[j] = aux[0];
						}
					}
				}
			}
		}
		
		void imprimirGenero(string genero){
			
			for(int i=0; i<10; i++){
				
				if(m[i] != NULL){
					
					if(m[i]->getGenero() == genero){
					
					cout<<"Pelicula Nro "<<i<<": "<<m[i]->getNombre()<<endl;
					}
				}
				else{
					
					cout<<"No hay ninguna pelicula registrada."<<endl;
				}
			}
			
			cout<<endl;
		}
		
		void eliminarPelicula(string nombre){
			
			bool si = false;
			
			for(int i=0; i<10; i++){
				
				if(m[i] != NULL){
					
					if(m[i]->getNombre() == nombre){
					
					m[i] = NULL;
					si = true;
					break;
					}
				}
			}
			
			if(si){
				
				cout<<"Pelicula eliminada con exito."<<endl;
			}
			else{
				
				cout<<"No se encontro la pelicula."<<endl;
			}
			
			cout<<endl;
		}
		
		void imprimir(){
			
			int contador = 0;
			
			for(int i=0; i<10; i++){
				
				if(m[i] != NULL){
					
					cout<<"Pelicula Nro "<<i<<": "<<endl;
					cout<<"Nombre: "<<m[i]->getNombre()<<endl;
					cout<<"Genero: "<<m[i]->getGenero()<<endl;
					cout<<"Duracion en minutos: "<<m[i]->getDuracion()<<endl<<endl;
				}
				else{
					
					contador++;
				}
			}
			
			if(contador == 10){
				
				cout<<"No hay ninguna pelicula registrada."<<endl<<endl;
			}
		}
		
};

int main(){
	
	Maraton *m = new Maraton();
	
	int opcion = 0;
	
	while(true){
		
		cout<<"--------MENU DE PELICULAS--------"<<endl<<endl;
		
		cout<<"1) Agregar pelicula"<<endl;
		cout<<"2) Ver peliculas de un genero especifico"<<endl;
		cout<<"3) Eliminar Pelicula"<<endl;
		cout<<"4) Ver toda la lista de peliculas"<<endl;
		cout<<"5) Salir"<<endl;
		cin>>opcion;
		cout<<endl;

		if(opcion == 1){
			
			string nombre, genero;
			int duracion;
			
			cin.ignore();
			cout<<"Ingrese el nombre de la pelicula: ";getline(cin,nombre);
			cout<<"Ingrese el genero de la pelicula: ";getline(cin,genero);
			cout<<"Ingrese la duracion en minutos: ";cin>>duracion;
			
			Pelicula *p = new Pelicula(nombre, genero, duracion);
			
			m->agregarPelicula(p);
			m->ordenarPelicula();
		}
		
		else if(opcion == 2){
			
			string genero;
			
			cin.ignore();
			cout<<"Ingrese el genero que desea ver: ";getline(cin,genero);
			cout<<endl;
			m->imprimirGenero(genero);
		}
		
		else if(opcion == 3){
			
			string nombre;
			
			cin.ignore();
			cout<<"Ingrese el nombre de la pelicula que desea eliminar: ";getline(cin,nombre);
			m->eliminarPelicula(nombre);
		}
		
		else if(opcion == 4){
			
			m->imprimir();
		}
		
		else if(opcion == 5){
			
			break;
		}
		
		else{
			
			cout<<"Opcion invalida."<<endl<<endl;
			continue;
		}
	}
	
	return 0;
}

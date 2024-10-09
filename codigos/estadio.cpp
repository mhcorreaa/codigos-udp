#include <iostream>
using namespace std;

class Hincha{
	
	private:
		
		int rut, nroasiento;
		string nombrecompleto, equipoHincha;
		
	public:
		
		Hincha(string nombrecompleto, string equipoHincha, int rut, int nroasiento){
			
			this->rut = rut;
			this->equipoHincha = equipoHincha;
			this->nroasiento = nroasiento;
			this->nombrecompleto = nombrecompleto;
		}
		
		int getRut(){
			
			return rut;
		}
		
		int getNroAsiento(){
			
			return nroasiento;
		}
		
		string getNombre(){
			
			return nombrecompleto;
		}
		
		string getEquipo(){
			
			return equipoHincha;
		}
		
		void imprimir(){
			
			cout<<"Asiento Nro "<<nroasiento<<endl<<endl;
			cout<<"Nombre: "<<nombrecompleto<<endl;
			cout<<"Rut: "<<rut<<endl;
			cout<<"Equipo: "<<equipoHincha<<endl;
		}
};

class Estadio{
	
	private:
		
		Hincha *arr[40000];
		
	public:
		
		Estadio(){
			
			for(int i=0; i<40000; i++){
				
				arr[i] = NULL;
			}
		}
		
		void registrarAsistencia(Hincha *h){
			
			if(arr[h->getNroAsiento()] == NULL){
				
				arr[h->getNroAsiento()] = h;
				cout<<"Asiento asignado con exito."<<endl;
			}
			else{
				
				cout<<"El asiento ya esta ocupado."<<endl;
			}
		}
		
		int hinchasAsistentes(){
			
			int contador = 0;
			
			for(int i=0; i<40000; i++){
				
				if(arr[i] != NULL){
					
					contador++;
				}
			}
			
			return contador;
		}
		
		float porcentajeOcupacion(){
			
			int contador = 0;
			
			for(int i=0; i<40000; i++){
				
				if(arr[i] != NULL){
					
					contador++;
				}
			}
			
			return contador*100.0/40000.0;
		}
		
		void imprimirHinchada(){
			
			int Acontador = 0, Bcontador = 0, total = 0;
			
			for(int i=0; i<40000; i++){
				
				if(arr[i] != NULL){
					
					if(arr[i]->getEquipo() == "azul" || arr[i]->getEquipo() == "AZUL" || arr[i]->getEquipo() == "azules" || arr[i]->getEquipo() == "AZULES"){
					
					Acontador++;
					}
					else if(arr[i]->getEquipo() == "blanco" || arr[i]->getEquipo() == "BLANCO" || arr[i]->getEquipo() == "blancos" || arr[i]->getEquipo() == "BLANCOS"){
					
					Bcontador++;
					}
				}
			}
			
			total = Acontador + Bcontador;
			
			cout<<"Porcentaje de Hinchas del equipo Blanco: "<<Bcontador*100.0/total<<endl;
			cout<<"Porcentaje de Hinchas del equipo Azul: "<<Acontador*100.0/total<<endl<<endl;
		}
		
		string asientoAsignado(int asiento){
			
			return arr[asiento]->getNombre();
		}
};

int main(){
	
	Estadio *e = new Estadio();
	
	int opcion = 0;
	bool salir = false;
	
	while(salir != true){
		
		cout<<"------MENU DE COMPRA DE ENTRADAS------"<<endl<<endl;
		
		cout<<"1) Registrar asistencia"<<endl;
		cout<<"2) Cantidad de hinchas asistentes"<<endl;
		cout<<"3) Porcentaje de ocupacion del estadio"<<endl;
		cout<<"4) Porcentaje de hinchada"<<endl;
		cout<<"5) Salir del Menu"<<endl<<endl;
		
		cout<<"Ingrese su opcion: ";cin>>opcion;	
		cout<<endl;
		
		switch(opcion){
			
			case 1:{
	
				string nombre, equipo;
				int rut, asiento;
				
				cout<<"Ingrese su Nombre: ";cin>>nombre;
				cout<<"Ingrese su Rut: ";cin>>rut;
				
				while(true){
					
					cout<<"Ingrese el equipo que apoya (blanco o azul): ";cin>>equipo;
					
					if(equipo == "blanco" || equipo == "BLANCO" || equipo == "blancos" || equipo == "BLANCOS" || equipo == "azul" || equipo == "AZUL" || equipo == "azules" || equipo == "AZULES"){
						
						cout<<endl;
						break;
					}
					
					else{
						
						cout<<"Valor invalido."<<endl<<endl;
					}
				}
				
				while(true){
					
					cout<<"Ingrese el asiento que desea (0 - 40000): ";cin>>asiento;
					
					if(asiento>=0 && asiento<40000){
						
						Hincha *h = new Hincha(nombre, equipo, rut, asiento);
						e->registrarAsistencia(h);
						
						if(e->asientoAsignado(asiento) == nombre){
							
							cout<<endl;
							break;
						}
	
					}
					else{
						
						cout<<"Valor invalido."<<endl<<endl;
					}
				}
				cout<<endl;
				break;
			}
			case 2:
				
				cout<<"Cantidad de hinchas asistentes: "<<e->hinchasAsistentes()<<endl<<endl;
				break;
			
			case 3:
				
				cout<<"Porcentaje ocupado del estadio: "<<e->porcentajeOcupacion()<<endl<<endl;
				break;
			
			case 4:
				
				e->imprimirHinchada();
				break;
				
			case 5:
				
				salir = true;
				break;
				
			default:
				
				cout<<"Entrada invalida."<<endl<<endl;
				break;
		}
	}
	
	return 0;
}

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <algorithm>
using namespace std;

class Mesa{
	private:
		int comensales;
		bool libre;
	public:
		Mesa() : comensales(0), libre(true) {}
		
		bool getLibre() const { return libre; }
		
		void Reservar() {
			if (libre==true) {
                cout<<"Ingrese la cantidad de comensales: "<<endl;
                cin>>comensales;
                libre=false;
            }
		    else{
                cout<<"La mesa ya esta ocupada."<<endl;
            }
		}
		
		void Liberar() {
			if(libre==false){
				comensales=0;
			    libre=true;
			}
		}
};

class Restaurante{
	private:
		static const int n=10;
		Mesa mesas[n];
	public:
		void mostrarMesas() {
			int mesaslib=0;
            cout<<"Mesas libres: ";
            for (int i=0; i < n; ++i) {
                if(mesas[i].getLibre() == true){
                    cout<<i+1<<" "; 
                    mesaslib++;
                }
            }
            cout<<endl;
            if(mesaslib == 0) cout<<"Ninguna mesa está libre."<<endl;
		}
		
		void reservarmesa(int num){
		    mesas[num].Reservar();
		}
		void liberarmesa(int num){
			mesas[num].Liberar();
		}
};

int main()
{
	int s=0;
	
	Restaurante a;
	a.mostrarMesas();
	cout<<"Seleccione una mesa para reservar: "<<endl;
	cin>>s;
	s=s-1;
	a.reservarmesa(s);
	s=0;
	a.mostrarMesas();
	cout<<"Seleccione una mesa para liberar: "<<endl;
	cin>>s;
	s=s-1;
	a.liberarmesa(s);
	s=0;
	a.mostrarMesas();
	
	return 0;
}

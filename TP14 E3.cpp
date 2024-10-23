#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <algorithm>
using namespace std;

class Empleado{
	private:
		string name;
		int pay;
		int dept;
	public:
		Empleado(){
			cout<<"Ingrese el nombre del empleado: "<<endl;
			cin.ignore();
			getline(cin, name);
			cout<<"Ingrese el salario del empleado: "<<endl;
			cin>>pay;
			cin.ignore();
			cout<<"Ingrese el numero de departamento del empleado: "<<endl;
			cin>>dept;
			cin.ignore();
		}
		
		string getName() const { return name; }
		int getPay() const { return pay; }
		int getDept() const { return dept; }
};

class Empresa{
	private:
		vector<Empleado> empleados;
	public:
		Empresa(){
			int n;
			cout<<"Ingrese la cantidad de empleados a agregar: "<<endl;
			cin>>n;
			for(int i=0; i < n; i++){
				empleados.push_back(Empleado());
			}
		}
		void st(){
			int salario=0;
			for(int i=0; i < empleados.size(); i++) {
				salario=salario+empleados[i].getPay();
			}
			cout<<"La nomina total de todos los empleados es de: $"<<salario<<endl;
		}
		void mayor(){
			string nombre;
			int mayor=0;
			for(int i=0; i < empleados.size(); i++)
			{
				if(empleados[i].getPay() > mayor){
					mayor=empleados[i].getPay();
					nombre.clear();
					nombre=empleados[i].getName();
				}
			}
			cout<<"El empleado con mayor salario es: "<<nombre<<" ($"<<mayor<<")"<<endl;
		}
		void lista(){
			cout<<"Lista de departamentos y empleados: "<<endl;
			for(int i=0; i < empleados.size(); i++){
				cout<<"Departamento "<<empleados[i].getDept()<<": "<<empleados[i].getName()<<endl;
			}
		}
};

int main()
{
	Empresa a;
	
	a.lista();
	cout<<endl;
	a.st();
	cout<<endl;
	a.mayor();
	cout<<endl;
	
	return 0;
}

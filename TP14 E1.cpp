#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <algorithm>
using namespace std;

class Libro{
	private:
		string nombre;
		int pags;
	public:
		Libro(){
			cout<<"Ingrese el nombre del libro: "<<endl;
			getline(cin, nombre);
			cout<<"Ingrese la cantidad de paginas del libro: "<<endl;
			cin>>pags;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		int getPags() const { return pags; }
	    string getName() const { return nombre; }
};

class Biblioteca{
	private:
		vector<Libro> libros;
	public:
		void addbook() {
			bool verif=false;
			do{
				verif=false;
				libros.push_back(Libro());
				cout<<"Agregar otro? (Y/N) "<<endl;
				char again;
				cin>>again;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if(again == 'Y' || again == 'y'){
					verif=true;
				}
				else{
					verif=false;
					return;
				}
			}while(verif==true);
			libros.push_back(Libro());
			cout<<endl;
		}
		
		void delbook() {
			if (libros.empty()) {
                cout<<"La biblioteca no tiene libros para eliminar"<<endl;
                return;
            }

            int num;
            bool verif=false;

            do{
                cout<<"Lista de libros:"<<endl;
                for (int i=0; i < libros.size(); ++i) {
                    cout<<i+1<<". "<<libros[i].getName()<<endl;
                }

                cout<<"Ingrese el numero del libro a eliminar: ";
                cin>>num;

                if (num > 0 && num <= libros.size()) {
                    libros.erase(libros.begin() + (num-1));
                    verif=true; 
                }
			    else{
                    cout<<"Numero incorrecto. Reintentar? (Y/N)";
                    char r;
                    cin>>r;
                    if (r=='N' || r=='n'){
                        verif=true;
                    }
                }
            }while(!verif);
            cout<<endl;
        }
        
        void lista(){
        	int pagstotal=0;
        	cout<<"Libros: "<<endl;
        	for(int i=0; i < libros.size(); i++){
        		cout<<i+1<<". "<<libros[i].getName()<<endl;
        		pagstotal=pagstotal+libros[i].getPags();
			}
        	cout<<"Total de paginas de todos los libros: "<<pagstotal<<endl;
		}
    };

int main()
{
	Biblioteca a;
	a.addbook();
	a.delbook();
	a.lista();
	
	return 0;
}

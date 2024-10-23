#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <algorithm>
using namespace std;

class Calc{
	public:
	int sumar(int a, int b) {
        return a+b;
    }
    
    float sumar(float a, float b) {
        return a+b;
    }

    int restar(int a, int b) {
        return a-b;
    }

    float restar(float a, float b) {
        return a-b;
    }

    int multiplicar(int a, int b) {
        return a*b;
    }

    float multiplicar(float a, float b) {
        return a*b;
    }

    float dividir(int a, int b) {
        if (b == 0) {
            cout<<"error"<<endl;
        }
        return a/b;
    }

    float dividir(float a, float b) {
        if (b == 0.0) {
            cout<<"error"<<endl;
		}
        return a/b;
    }
		
};

class Comparador{
	public:
		void comparar(int a, int b){
			if(a == b) cout<<"Los dos valores son iguales"<<endl;
			else if(a > b) cout<<a<<" es mayor a "<<b<<endl;
			else cout<<a<<" es menor a "<<b<<endl;
		}
		void comparar(float a, float b){
			if(a == b) cout<<"Los dos valores son iguales"<<endl;
			else if(a > b) cout<<a<<" es mayor a "<<b<<endl;
			else cout<<a<<" es menor a "<<b<<endl;
		}
		void comparar(float a, int b){
			if(a == b) cout<<"Los dos valores son iguales"<<endl;
			else if(a > b) cout<<a<<" es mayor a "<<b<<endl;
			else cout<<a<<" es menor a "<<b<<endl;
		}
		void comparar(int a, double b){
			if(a == b) cout<<"Los dos valores son iguales"<<endl;
			else if(a > b) cout<<a<<" es mayor a "<<b<<endl;
			else cout<<a<<" es menor a "<<b<<endl;
		}
		void comparar(string a, string b){
			if(a.compare(b) == 0) cout<<"Los dos cadenas son iguales"<<endl;
			else if(a.compare(b) > 0) cout<<a<<" es mayor lexicograficamente que "<<b<<endl;
			else cout<<a<<" es menor lexicograficamente que "<<b<<endl;
		}
		template <typename T>
        bool comparar(const T& a, const T& b) {
            return a == b;
        }
};

class Conversor{
	public:
		double masa(double v, string de, string a){
			if ((de == "G" || de == "g") && (a == "KG" || a == "kg" || a == "Kg" || a == "kG")) {
                return v / 1000;
            }
            if ((de == "KG" || de == "kg" || de == "Kg" || de == "kG") && (a == "G" || a == "g")) {
                return v * 1000;
            }
            cout<<"Error"<<endl;
		}
		
		float temperatura(float v, string de, string a) {
        if (de == "c" && a == "f") {
            return (v * 9.0 / 5.0) + 32;
        }
		else if (de == "f" && a == "c") {
            return (v - 32) * 5.0 / 9.0;
        }
		else if (de == "c" && a == "k") {
            return v + 273.15;
        }
		else if (de == "k" && a == "c") {
            return v - 273.15;
        }
        cout<<"Error"<<endl;
        return 0;
    }

    float longitud(float v, string de, string a) {
        if (de == "m" && a == "cm") {
            return v * 100;
        }
		else if (de == "cm" && a == "m") {
            return v / 100;
        }
		else if (de == "km" && a == "m") {
            return v * 1000;
        }
		else if (de == "m" && a == "km") {
            return v / 1000;
        }
        cout<<"Error"<<endl;
        return 0;
    }
};

int main()
{
    Calc calc;
    Comparador comp;
    Conversor conv;

    cout<<"Ejemplo de suma de enteros: "<<calc.sumar(5, 10)<<endl;
    cout<<"Ejemplo de suma de float: "<<calc.sumar(5.5f, 3.3f)<<endl;
    cout<<"Ejemplo de division de enteros: "<<calc.dividir(10, 2)<<endl;
    cout<<"Ejemplo de division de float (con cero): "<<calc.dividir(10.0f, 0.0f)<<endl;

    cout<<"Ejemplo de comparacion de enteros: ";
    comp.comparar(5, 10);
    
    cout<<"Ejemplo de comparacion de flotante e int: ";
    comp.comparar(10.5f, 10);
    
    cout<<"Ejemplo de comparacion de cadenas: ";
    comp.comparar("Hola", "asdsdsa");

    cout<<"Ejemplo de conversion de masa (1000 gramos a kilogramos): "<<conv.masa(1000, "g", "kg")<<" kg"<<endl;
    cout<<"Ejemplo de conversion de temperatura (100 Celsius a Fahrenheit): "<<conv.temperatura(100, "c", "f")<<" grados F"<<endl;
    cout<<"Ejemplo de conversion de longitud (1 kilometro a metros): "<<conv.longitud(1, "km", "m")<<" metros"<<endl;

    return 0;
}

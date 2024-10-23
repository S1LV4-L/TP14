#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <cmath>
using namespace std;

class Figura{
	protected:
		string color;
		double posicion;
	public:
		Figura(){
			cout<<"Ingrese el color de la figura: "<<endl;
			cin.ignore();
			getline(cin, color);
			cout<<"Ingrese la posicion de la figura (grados): "<<endl;
			cin>>posicion;
		}
		
		string getColor() const { return color; }
		double getPosicion() const { return posicion; }
		
		virtual double area() = 0;
		virtual double perimetro() = 0;
		
};

class Circulo : public Figura{
	private:
		double diametro;
		double radio;
	public:
		Circulo() : Figura() {
			cout<<"Ingrese el diametro: "<<endl;
			cin>>diametro;
			cout<<"Ingrese el radio: "<<endl;
			cin>>radio;
		}
		
		double area() override{
		    return M_PI * pow(radio, 2);
		}
		double perimetro() override{
		    return M_PI * diametro;
		}
		
		void datos(){
			cout<<"Figura: Circulo"<<endl;
			cout<<"Color: "<<getColor()<<endl;
			cout<<"Posicion: "<<getPosicion()<<endl;
			cout<<"Area: "<<area()<<endl;
			cout<<"Perimetro: "<<perimetro()<<endl;
		}
};

class Rectangulo : public Figura{
	private:
		double base;
		double altura;
	public:
		Rectangulo() : Figura() {
			cout<<"Ingrese la base: "<<endl;
			cin>>base;
			cout<<"Ingrese la altura: "<<endl;
			cin>>altura;
		}
		
		double area() override{
		    return base*altura;
		}
		double perimetro() override{
		    return 2*(base+altura);
		}
		
		void datos(){
			cout<<"Figura: Rectangulo"<<endl;
			cout<<"Color: "<<getColor()<<endl;
			cout<<"Posicion: "<<getPosicion()<<endl;
			cout<<"Area: "<<area()<<endl;
			cout<<"Perimetro: "<<perimetro()<<endl;
		}
};

class Triangulo : public Figura{
	private:
		double lado1, lado2, lado3;
	public:
		Triangulo() : Figura() {
			cout<<"Ingrese el lado 1: "<<endl;
			cin>>lado1;
			cout<<"Ingrese el lado 2: "<<endl;
			cin>>lado2;
			cout<<"Ingrese el lado 3: "<<endl;
			cin>>lado3;
		}
		
		double area() override{
		    double s = (lado1 + lado2 + lado3) / 2;
            return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
		}
		double perimetro() override{
		    return lado1+lado2+lado3;
		}
		
		void datos(){
			cout<<"Figura: Triangulo"<<endl;
			cout<<"Color: "<<getColor()<<endl;
			cout<<"Posicion: "<<getPosicion()<<endl;
			cout<<"Area: "<<area()<<endl;
			cout<<"Perimetro: "<<perimetro()<<endl;
		}
};

int main()
{
	Circulo a;
	Rectangulo b;
	Triangulo c;
	
	a.datos();
	b.datos();
	c.datos();
	
	return 0;
}

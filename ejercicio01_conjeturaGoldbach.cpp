#include <iostream>

using namespace std;

bool esPrimo;

// ejecuta el programa 
int main(){
	// Declaracion de variables
	int numeron;
	// Solicita un numero dentro de ese rango
	cout << "---> Escriba un numero entre un rango de 3 hasta 100: ";
	cin >> numeron;
	// llama la función evaluarConjeturaGoldbach
	return evaluarConjeturaGoldbach(numeron);
}

// Funcion de conjetura de GoldBach
int evaluarConjeturaGoldbach(int numero) 
{
	// declaramos las variables
	int num1=2, num2 = 2, suma;
	bool salirbucle=false;
	// se evalua si el numero es valido
	if (numero <= 2 && numero >= 100) 
		cout << "Este numero no puede ser evaluado." << endl;
	else
	{
		do
		{
			// Verifica que num1 y num2 no superen el numero a evaluar
			if(num1 >= (numero-2))
			{
				num1 = 2;
				num2++;
			}
			/* Verifica si ambos son primos y la division
			   de la suma de ambos numeros da 0 */
			if((esPrimo(num1) && esPrimo(num2)) && ((num1 + num2) % 2 == 0))
			{
				suma = num1 + num2;
				cout << num1 << " + " << num2 << " = " << suma << endl;
			}
			// suma 1 a num1
			num1++;
			
		} while (suma <= numero);
	}
}

// funcion para evaluar si es primo
bool esPrimo(int numero)
{
	int divisor = 1, divisores;
	do
	{
		/* Divide y luego aumenta los divisores
		   y el divisor si es menor al numero */
		if (numero % divisor == 0) 
			divisores++;
		divisor++;
	} while (divisor <= numero);
	// Si es primo, retorna true, sino, false.	
	if (divisor == 2) return true;
	return false;
}
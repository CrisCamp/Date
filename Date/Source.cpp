#include <iostream>
//#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Date
{
private:
	unsigned int dia, mes, año, longitud;
	string  year, mounth, day, fechatem;
public:
	Date(string fecha)
	{
		longitud = fecha.length();

		stringstream stream(fecha);
		getline(stream, year, '/');
		getline(stream, mounth, '/');
		getline(stream, day, '/');

		char year2[4];
		for (int i = 0; i <= 3; i++)
		{
			year2[i] = year[i];
		}
		char mounth2[2];
		for (int i = 0; i <= 1; i++)
		{
			mounth2[i] = mounth[i];
		}
		char day2[2];
		for (int i = 0; i <= 1; i++)
		{
			day2[i] = day[i];
		}
		año = atoi(year2); 
		mes = atoi(mounth2); https://www.youtube.com/watch?v=PmaBU9jrO08
		dia = atoi(day2);
		/*cout << año << "\n";
		cout << mes << "\n";
		cout << dia << "\n";*/

		/*año = stoi(year);
		mes = stoi(mounth);
		dia = stoi(day);
		cout << año << "\n";
		cout << mes << "\n";
		cout << dia << "\n";*/
	}
	operator const char*()
	{
		ostringstream a;
		a << year << " / " << mounth << " / " << day;
		fechatem = a.str();
		//cout << "\n" << a.str() << "\n";
		return fechatem.c_str();
	}
	void validarFecha()
	{
		if (longitud == 10)
		{
			int ny = año;
			int nm = mes;
			int nd = dia;

			int cy = 0;
			while (ny > 0)
			{
				ny = ny / 10;
				cy++;
			}
			int cm = 0;
			if (nm < 10)
			{
				cm++;
			}
			while (nm > 0)
			{
				nm = nm / 10;
				cm++;
			}
			int cd = 0;
			if (nd < 10)
			{
				cd++;
			}
			while (nd > 0)
			{
				nd = nd / 10;
				cd++;
			}
			int yearEnt = year.length();
			int mounthEnt = mounth.length();
			int dayEnt = day.length();

			if (yearEnt == cy)
			{
				if (mounthEnt == cm)
				{
					if (dayEnt == cd)
					{
						if (año % 4 == 0 and año % 100 != 0 or año % 400 == 0) //Condición de año bisiesto
						{
							cout << "\nEl año introducido es Bisiesto\n" << endl;
							if (mes >= 1 && mes <= 12)
							{
								if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia >= 1 && dia <= 31))
								{
									cout << "Fecha valida\n" << endl;
								}							
								else if  ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia >= 1 && dia <= 30))
								{
									cout << "Fecha valida\n" << endl;
								}
								else if ((mes == 2 && dia >= 1 && dia <= 29))
								{
									cout << "Fecha valida\n" << endl;										
								}
								else 
								{
									cout << "El dia no existe\n" << endl;
								}								
							}
							else
							{
								cout << "El mes no existe\n" << endl;
							}
						}
						else
						{
							cout << "\nEl año introducido no es bisiesto\n" << endl;
							if (mes >= 1 && mes <= 12)
							{
								if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia >= 1 && dia <= 31))
								{
									cout << "Fecha valida\n" << endl;
									cout << dia << endl;
								}
								else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia >= 1 && dia <= 30))
								{
									cout << "Fecha valida\n" << endl;
								}
								else if ((mes == 2 && dia >= 1 && dia <= 28))
								{
									cout << "Fecha valida\n" << endl;
								}
								else
								{
									cout << "El dia o la fecha no existe\n" << endl;
								}
							}
							else
							{
								cout << "El mes no existe\n" << endl;
							}
						}
					}
					else
					{
						cout << "\nDato invalido en dia\n\n";
					}
				}
				else
				{
					cout << "\nDato invalido en mes\n\n";
				}
			}
			else
			{
				cout << "\nDato invalido en año\n\n";
			}
		}
		else
		{
			cout << "\nRecuerde respetar el formato indicado, asegurese de llenar y no 'sobrepasar' los espacios\n\n";
		}
	}
};
	class Inicio
	{
	private:
		int opcion;
		string fecha;
	public:
		Inicio()
		{
			fecha = "";
			opcion = 0;
		}
		void run()
		{
			do {
				cout << "Introduzca la fecha del dia de hoy en formato ISO --> AAAA/MM/DD" << endl;
				cin >> fecha;
				Date* fe = new Date(fecha);
				fe->validarFecha();
				cout << "\n" << fe->operator const char* () << "\n\n";
				cout << "Introduzca la opcion\n1. Seguir en el programa\n2. Salir del programa" << endl;
				cin >> opcion;
				system("cls");
			} while (opcion != 2);
		}
	};
	int main()//llama a todas las funciones
	{
		Inicio menu;
		menu.run();
	}
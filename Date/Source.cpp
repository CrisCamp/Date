#include <iostream>
//#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Date
{
private:
	int dia, mes, año, longitud;
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
	operator const char* ()
	{
		ostringstream a;
		a << limitarAño() << " / " << limitarMes() << " / " << limitarDia();
		fechatem = a.str();
		//cout << "\n" << a.str() << "\n";
		return fechatem.c_str();
	}
	int limitarAño()
	{
		if (año < 1500)
		{
			año = 1500;
		}
		else if (año > 3500)
		{
			año = 3500;
		}
		return año;
	}
	bool biciesto()
	{
		if (limitarAño() % 4 == 0 and limitarAño() % 100 != 0 or limitarAño() % 400 == 0)
		{
			return true;
		}//Condición de año bisiesto
		else
		{
			return false;
		}
	}
	int limitarMes()
	{
		if (mes > 12)
		{
			mes = 12;
		}
		else if (mes <= 0) //el operador "<" esta de mas porque la variable mes esta declara como int, por lo que se pueden presentar numeros negativos
		{
			mes = 1;
		}
		return mes;
	}
	int limitarDia()
	{
		if (limitarMes() == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || limitarMes() == 12)
		{
			if (dia > 31)
			{
				dia = 31;
			}
			else if (dia <= 0)
			{
				dia = 1;
			}
		}
		else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
		{
			if (dia > 30)
			{
				dia = 30;
			}
			else if (dia <= 0)
			{
				dia = 1;
			}
		}
		else if (mes == 2)
		{
			if (biciesto() == true)
			{
				if (dia > 29)
				{
					dia = 29;
				}
			}
			else
			{
				if (dia > 28)
				{
					dia = 28;
				}
			}
			if (dia <= 0)
			{
				dia = 1;
			}
		}		
		return dia;
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
				cm = 1;
			}
			while (nm > 0)
			{
				nm = nm / 10;
				cm++;
			}
			int cd = 0;
			if (nd < 10)
			{
				cd = 1;
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
						if (mes >= 1 && mes <= 12)
						{
							if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia >= 1 && dia <= 31))
							{
								if (biciesto() == true)
								{
									cout << "\nEl año introducido es Bisiesto\n" << endl;
								}
								else
								{
									cout << "\nEl año introducido no es Bisiesto\n" << endl;
								}
							}							
							else if  ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia >= 1 && dia <= 30))
							{
								if (biciesto() == true)
								{
									cout << "\nEl año introducido es Bisiesto\n" << endl;
								}
								else
								{
									cout << "\nEl año introducido no es Bisiesto\n" << endl;
								}
							}
							else if ((biciesto() == true) && mes == 2 && dia >= 1 && dia <= 29)
							{									
								cout << "\nEl año introducido es Bisiesto\n" << endl;
							}
							else if ((biciesto() == false) && mes == 2 && dia >= 1 && dia <= 28)
							{
								cout << "\nEl año introducido no es Bisiesto\n" << endl;
							}
							else 
							{
								if (biciesto() == false)
								{
									cout << "\nEl año introducido no es Bisiesto\n" << endl;
								}
								cout << "la fecha no existe por el dia establecido, por defecto y correspondiente al mes se dejara en: " << limitarDia() << endl;
							}								
						}
						else
						{
							cout << "El mes no existe, por defecto se dejara en: \n"<< limitarMes() << endl;
						}
					}
					else
					{
						cout << "\nDato invalido, por defecto se establecera como: \n";
						//cout << "\nDato invalido en dia\n";
					}
				}
				else
				{
					cout << "\nDato invalido, por defecto se establecera como: \n";
					//cout << "\nDato invalido en mes\n";
				}
			}
			else
			{
				cout << "\nDato invalido, por defecto se establecera como: \n";
				//cout << "\nDato invalido en año\n";
			}
			cout << operator const char* () << "\n";
		}
		else
		{
			cout << "\nRecuerde respetar el formato indicado, asegurese de 'llenar' y no 'sobrepasar' los espacios\n\n";
		}
	}
	void incrementarFecha ()
	{
		cout << "\nSumando el dato establecido mas un dia:\n";
		int diaSum = limitarDia();
		int mesSum = limitarMes();
		int añoSum = limitarAño();

		diaSum++;
		if ((limitarMes() == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || limitarMes() == 12) && limitarDia() == 31)
		{
			diaSum = 1;
			mesSum++;
			if (limitarMes() == 12)
			{
				mesSum = 1;
				añoSum++;
			}
		}
		else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && limitarDia() == 30)
		{
			diaSum = 1;
			mesSum++;
		}
		else if ((biciesto() == true && mes == 2) && limitarDia() == 29)
		{
			diaSum = 1;
			mesSum++;
		}
		else if ((biciesto() == false && mes == 2) && limitarDia() == 28)
		{
			diaSum = 1;
			mesSum++;
		}
		cout << añoSum << " / " << mesSum << " / " << diaSum <<"\n\n";
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
				//cout << "\n" << fe->operator const char* () << "\n\n";
				fe->incrementarFecha();
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
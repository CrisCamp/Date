#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Inicio
{
private:
	unsigned int dia, mes, año, opcion;
	string fecha;
public:
	Inicio()
	{
		dia = 0;
		mes = 0;
		año = 0;
		fecha = "";
		opcion = 0;
	}
	void run()
	{
		do {
			cout << "Introduzca la fecha del dia de hoy en formato ISO --> AAAA/MM/DD" << endl;
			cin >> fecha;
			int longitud = fecha.length();
			//cout << endl << longitud << "\n";
			if (longitud == 10)
			{
				stringstream stream(fecha);
				string day, mounth, year;

				getline(stream, year, '/');
				getline(stream, mounth, '/');
				getline(stream, day, '/');

				año = stoi(year);
				mes = stoi(mounth);
				dia = stoi(day);

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
				if (nm <= 10 && nm >= 1)
				{
					cm = 1;
				}
				while (nm > 0)
				{
					nm = nm / 10;
					cm++;
				}
				int cd = 0;
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
							cout << "Dato Valido :)\n\n";
							if (año % 4 == 0 and año % 100 != 0 or año % 400 == 0) //Condición de año bisiesto
							{
								cout << "El año es Bisiesto\n" << endl;
								if (mes >= 1 && mes <= 12)
								{
									int m = 0;
									int m2 = mes;
									if (m == m2 % 2)
									{
										if ((mes == 2 && dia >= 1 && dia <= 29))
										{
											cout << "CorrectoF\n" << endl;
										}
										else if ((mes > 2 && dia >= 1 && dia <= 30))
										{
											cout << "mes y dia validoA\n" << endl;
										}
										else
										{
											cout << "mes y dia invalidoA\n" << endl;
										}
									}
									else
									{
										if ((mes >= 1 && dia >= 1 && dia <= 31))
										{
											cout << "mes y dia validoA\n" << endl;
										}
										else
										{
											cout << "mes y dia invalidoA\n" << endl;
										}
									}
								}
								else
								{
									cout << "mes invalido no debe ser 0 o mayor a 12\n" << endl;
								}
							}
							else
							{
								cout << "No es bisiesto\n" << endl;
								if (mes >= 1 && mes <= 12)
								{
									int m = 0;
									int m2 = mes;
									if (m == m2 % 2)
									{
										if ((mes == 2 && dia >= 1 && dia <= 28))
										{
											cout << "CorrectoF\n" << endl;
										}
										else if ((mes > 2 && dia >= 1 && dia <= 30))
										{
											cout << "mes y dia validoA\n" << endl;
										}
										else
										{
											cout << "mes y dia invalidoA\n" << endl;
										}
									}
									else
									{
										if ((mes >= 1 && dia >= 1 && dia <= 31))
										{
											cout << "mes y dia validoA\n" << endl;
										}
										else
										{
											cout << "mes y dia invalidoA\n" << endl;
										}
									}
								}
								else
								{
									cout << "mes invalido no debe ser 0 o mayor a 12\n" << endl;
								}
							}
						}
						else
						{
							cout << "\nDato invalidoA\n\n";
						}
					}
					else
					{
						cout << "\nDato invalidoB\n\n";
					}
				}
				else
				{
					cout << "\nDato invalidoC\n\n";
				}
			}
			else
			{
				cout << "\nRecuerde respetar el formato indicado, asegurese de llenar todos los espacios\n\n";
			}
			//cout << endl << fecha << "\n\n";
			//if (fecha)
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
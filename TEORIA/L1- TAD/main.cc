#include "fecha.hh"
#include <ctime>	// time, localtime, tm, ...
#include <fstream>	// Leer y escribir ficheros
#include <iomanip>	// setfill, setw
#include <iostream>
#include <vector>
using namespace std;



int main() {
	Fecha f = {1, 1, 0};
	fecha_escribir(f);
	cout << endl;

	f = fecha_actual();
	cout << "Hoy es: " << f << endl;

	f = fecha_sumar_dias(f, 7);
	cout << "Dentro de una semana será: " << f << endl;

	cout << "Todas las fechas del anyo en curso:" << endl;
	f = {1, 1, f.anyo_};
	for (int i = 0; i < 365; i++) {
		cout << f << endl;
		f = fecha_sumar_dias(f, 1);
	}

    vector<Fecha> fechas = leer_fechas_de_fichero("fechas.dat");
    cout << fechas.size() << " fechas leídas xD" << endl;
}
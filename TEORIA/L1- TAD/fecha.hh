#include <iostream>
#include <vector>
#include <iomanip>

#ifndef FECHA_HH
#define FECHA_HH

struct Fecha {
	int dia_, mes_, anyo_;
};

/**
 * @brief Lee una fecha en formato DD/MM/AAAA.
 */
Fecha fecha_leer();

/**
 * @brief Escribe una fecha en formato DD/MM/AAAA.
 */
void fecha_escribir(const Fecha& f);

/**
 * @brief Determina si un anyo es bisiesto.
 *
 * @param anyo El anyo a comprobar.
 */
bool es_bisiesto(int anyo);

/**
 * @brief Determina el número de días de un mes
 *
 * @param mes El mes a comprobar.
 * @param anyo El anyo al que pertenece el mes.
 *
 * @return El número de días del mes.
 */
int dias_mes(int mes, int anyo);

/**
 * @brief Añade un número de días a una fecha.
 *
 * @param f La fecha a la que añadir los días.
 * @param dias El número de días a añadir.
 */
Fecha fecha_sumar_dias(const Fecha& f, int dias);

/**
 * @brief Operador de escritura para fechas.
 *
 * Este operador define el comportamiento de `cout << f;` donde `f` es una fecha.
 *
 * @param o El `stream` de salida (`cout` u otro).
 * @param f La fecha a escribir.
 *
 * @return El mismo `stream` de salida para permitir encadenar salidas.
 *
 * @pre `f` es una fecha válida.
 */
inline std::ostream& operator<<(std::ostream& out, const Fecha& f) {
	out << std::setfill('0') << std::setw(2) << f.dia_;
	out << '/' << std::setfill('0') << std::setw(2) << f.mes_;
	out << '/' << std::setfill('0') << std::setw(4) << f.anyo_;
	return out;
}

/**
 * @brief Operador de lectura para fechas.
 *
 * Este operador define el comportamiento de `cin >> f;` donde `f` es una fecha.
 *
 * @param in El `stream` de entrada (`cin` u otro).
 * @param f La fecha a leer.
 */
inline std::istream& operator>>(std::istream& in, Fecha& f) {
	char sep;  // Leemos el separador pero no se usa
	in >> f.dia_ >> sep >> f.mes_ >> sep >> f.anyo_;
	return in;
}

/**
 * @brief Devuelve `true` si `a` es anterior a `b`, `false` en caso contrario.
 */
bool fecha_menor(const Fecha& a, const Fecha& b);

/**
 * @brief Devuelve `true` si `a` es posterior a `b`, `false` en caso contrario.
 */
bool fecha_mayor(const Fecha& a, const Fecha& b);

/**
 * @brief Devuelve la fecha actual.
 */
Fecha fecha_actual();
/**
 * @brief Leer secuencia de fechas de un fichero
 * @param filename Nombre del fichero
 * @return `vector` con las fechas leídas
 */
std::vector<Fecha> leer_fechas_de_fichero(const std::string& filename);

#endif
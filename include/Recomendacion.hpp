#include "Articulo.hpp"
#include <cmath>
#include <fstream>

class Recomendacion {

	private:
		// Atributos
		std::vector<Articulo> articulos_;
		std::string fileName_;

	public:
		// Constructores y destructor
		Recomendacion (void);
		Recomendacion (std::string inputFile);
		~Recomendacion (void);

		// Funciones
		void generarArticulos (void);
		void runProgram (void);
		void generarTablas (void);
		void printTables (void);
		void calcularTablaCoseno (void);
		void calcularCosenos (void);
		void printTablaCoseno (void);

};
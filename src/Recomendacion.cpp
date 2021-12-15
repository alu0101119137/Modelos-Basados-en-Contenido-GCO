#include "../include/Recomendacion.hpp"

// Constructor por defecto
Recomendacion::Recomendacion (void) {
}

// Constructor con parametros
Recomendacion::Recomendacion (std::string inputFile) {
	fileName_ = inputFile;
	generarArticulos();
}

// Destructor
Recomendacion::~Recomendacion (void) {
}

// Genera los articulos sacados del fichero de entrada
void Recomendacion::generarArticulos (void){
	std::ifstream file(fileName_, std::ios::in);
	if (file.fail()) {
		std::cout << std::endl << "Error. No se pudo abrir el fichero" << std::endl;
		exit(1);
	}
	while (!file.eof()) {
		std::string linea = "";
		std::getline(file, linea);
		Articulo nuevoArticulo;
		nuevoArticulo.setLinea(linea);
		nuevoArticulo.generarSimbolos();
		articulos_.push_back(nuevoArticulo);
	}
	file.close();
}

// Pone el programa en funcionamiento
void Recomendacion::runProgram (void) {
	generarTablas();
	printTables();
	printTablaCoseno();
}

// Genera las tablas para cada articulo
void Recomendacion::generarTablas (void) {
	unsigned N = articulos_.size();
	for (unsigned art = 0; art < N; art++) {
		for (unsigned i = 0; i < articulos_[art].getSimbolo().size(); i++) {
			unsigned dfx = 0;
			std::string palabra = articulos_[art].getSimbolo()[i].getNombre();
			for (unsigned j = 0; j < N; j++) {
				if (articulos_[j].contienePalabra(palabra)) {
					dfx++;
				}
			}

			articulos_[art].generarMetricasArticulo(i, N, dfx);

		}
		articulos_[art].generarVectorSize();
		articulos_[art].generarValorNormalizado();
	}
	calcularCosenos();
}

// Imprime las tablas
void Recomendacion::printTables (void) {
	for (unsigned art = 0; art < articulos_.size(); art++) {
		std::cout << "\n\n\n\n\nTabla Artículo " << art << ":\n\tIndice\tTermino\t\tTF\t\tIDF\t\tTF-IDF\t\tValorNormalizado";
		for (unsigned i = 0; i < articulos_[art].getSimbolo().size(); i++) {
			std::cout << std::endl;
			std::cout << "\t" << i;
			std::cout << "\t" << articulos_[art].getSimbolo()[i].getNombre();
			if (articulos_[art].getSimbolo()[i].getNombre().length() < 8) {
				std::cout << "\t";
			}
			std::cout << "\t" << articulos_[art].getSimbolo()[i].getTf();
			std::cout << "\t\t" << std::setprecision(4) << articulos_[art].getSimbolo()[i].getIdf();
			std::cout << "\t\t" << std::setprecision(4) << articulos_[art].getSimbolo()[i].getTf_Idf();
			std::cout << "\t\t" << std::setprecision(4) << articulos_[art].getSimbolo()[i].getValorNormalizado();
		}
		std::cout << std::endl << "Longitud del vector: " << articulos_[art].getVectorSize();
	}
}

// Calcula los cosenos
void Recomendacion::calcularCosenos (void) {
	for (unsigned i = 0; i < articulos_.size(); i++) {
		for (unsigned j = 0; j < articulos_.size(); j++) {
			float coseno = 0;
			if (j != i) {
				for (unsigned k = 0; k < articulos_[i].getSimbolo().size(); k++) {
					for (unsigned w = 0; w < articulos_[j].getSimbolo().size(); w++) {
						if (articulos_[i].getSimbolo()[k].getNombre() == articulos_[j].getSimbolo()[w].getNombre()) {
							coseno += (pow(articulos_[i].getSimbolo()[k].getValorNormalizado(), 2));
							break;
						}
					}
				}
			}
			articulos_[i].addCoseno(coseno);
		}
	}
}

// Imprime la tabla del calculo del coseno
void Recomendacion::printTablaCoseno (void) {
	for (unsigned i = 0; i < articulos_.size(); i++) {
		for (unsigned j = 0; j < articulos_.size(); j++) {
			if (i != j) {
				std::cout << "\ncos(" << i << ", " << j << ") = " << articulos_[i].getCosenos()[j];
			}
		}
	}
}
#include "../include/Preprocesador.hpp"


// Cosntructor por defecto
Preprocesador::Preprocesador (void) {
	setString("");
}

// Constructor
Preprocesador::Preprocesador (std::string linea) {
	setString(linea);
}

// Destructor
Preprocesador::~Preprocesador (void) {
}

// Getter del vector de simbolos
std::vector<Simbolo> Preprocesador::getVector (void) const {
	return vector_;
}

// Getter del string
std::string Preprocesador::getString (void) const {
	return string_;
}

// Setter del vector de simbolos
void Preprocesador::setVector (std::vector<Simbolo> nuevoVector) {
	vector_ = nuevoVector;
}

// Setter del string
void Preprocesador::setString (std::string nuevoString) {
	string_ = nuevoString;
}

// Se generan las palabras y se meten en el vector
void Preprocesador::generarPalabras (void) {
	unsigned contador = 0;
	std::string tmp = "";
	while (contador < string_.length()) {
		if (string_[contador] != ' ' and string_[contador] != '\n'  and string_[contador] != '\r') {
			tmp += string_[contador];
		}
		else {
			std::string nuevaPalabra = preprocesar(tmp);	
			int pos = tieneSimbolo(nuevaPalabra);
			if (pos == -1) {
				Simbolo nuevoSimbolo(nuevaPalabra);
				vector_.push_back(nuevaPalabra);
			}
			else {
				vector_[pos].incrementar();
			}
			tmp = "";
		}
		contador++;
	}
}

// Convierte todas las palabras a minusculas y elimina signos de puntuación
std::string Preprocesador::preprocesar (std::string str) {
	std::transform(str.begin(), str.end(),str.begin(), ::tolower);
	std::string result = "";
	for (unsigned i = 0; i < str.length(); i++) {
		if (str[i] != '.' and str[i] != ',' and str[i] != '-' and str[i] != '\'' and str[i] != '%' and str[i] != ';' and str[i] != ':') {
			result += str[i];
		}
	}
	return result;
}

// Imprime el vector
void Preprocesador::imprimirVector (void) {
	for (unsigned i = 0; i < vector_.size(); i++) {
		vector_[i].printSimbolo();
	}
}

// Busca si el simbolo ya existe y en caso de ser así retorna su posicion
int Preprocesador::tieneSimbolo (std::string str) {
	for (unsigned i = 0; i < vector_.size(); i++) {
		if (vector_[i].getNombre() == str) {
			return i;
		}
	}
	return -1;
}
#include "Simbolo.hpp"
#include <ctype.h>
#include <algorithm>
class Preprocesador {

	private:
		std::vector<Simbolo> vector_;
		std::string string_;

	public:
		// Builders & Destroyer
		Preprocesador (void);
		Preprocesador (std::string linea);
		~Preprocesador (void);

		// Getters & Setters
		std::vector<Simbolo> getVector (void) const;
		std::string getString (void) const;

		void setVector (std::vector<Simbolo> nuevoVector);
		void setString (std::string nuevoString);

		// Functions
		void generarPalabras (void);
		std::string preprocesar (std::string str);
		void imprimirVector (void);
		int tieneSimbolo (std::string str);
};
#include <vector>
#include <iostream>
#include "Preprocesador.hpp"

/**
 * @brief      Esta clase describe un Articulo.
 */
class Articulo {

	private:
		unsigned id_;
		std::vector<Simbolo> simbolo_;
		std::string linea_;
		float vectorSize_;
		std::vector<float> cosenos_;

	public:

		// Constructor y destructor por defecto
		Articulo (void);
		~Articulo (void);

		// Getter de la clase
		unsigned getId (void) const;
		std::vector<Simbolo> getSimbolo (void) const;
		std::string getLinea (void) const;
		float getVectorSize (void) const;
		std::vector<float> getCosenos (void) const;

		// Setter de la clase
		void setId (unsigned nuevoID);
		void setSimbolo (std::vector<Simbolo> nuevoSimbolo);
		void setLinea (std::string nuevaLinea);
		void setVectorSize (float nuevoVectorSize);

		// Funciones
		void generarSimbolos (void);
		bool contienePalabra (std::string str);
		void generarMetricasArticulo (unsigned i, unsigned N, unsigned dfx);
		void generarVectorSize (void);
		void generarValorNormalizado (void);
		void addCoseno (float tmp);
};
#pragma once

#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>


/**
 * @brief      This class describes a Simbolo.
 */
class Simbolo {

	private:
		// Atributos
		std::string nombre_;
		unsigned tf_;			
		float idf_;			
		float tf_idf_; 					
		float valorNormalizado_;

	public:
		// Constructor y destructor
		Simbolo (void);
		Simbolo (std::string nombre);
		~Simbolo (void);

		// Getters y Setters
		std::string getNombre (void) const;
		unsigned getTf (void) const;
		float getIdf (void) const;		
		float getTf_Idf (void) const;
		float getValorNormalizado (void) const;

		void setNombre (std::string nombre);
		void setTf (unsigned tf);
		void setIdf (unsigned N, unsigned dfx);
		void setTf_Idf (void);
		void setValorNormalizado (float nuevoValorNormalizado);

		// Operators overload
		bool operator== (const Simbolo& otherSimbolo) const;
		bool operator== (const std::string& str) const;
		Simbolo& operator= (const Simbolo& otherSimbolo);

		// Function
		void incrementar (void);
		
		// Write
		void printSimbolo (void) const;
};
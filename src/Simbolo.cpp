#include "../include/Simbolo.hpp"

// Constructor por defecto
Simbolo::Simbolo (void) {
	setNombre("");
	setTf(0);
}

// Cosntructor al que se le pasa el nombre
Simbolo::Simbolo (std::string name) {
	setNombre(name);
	setTf(1);
}

// Destructor
Simbolo::~Simbolo (void) {
}

// Getter del nombre
std::string Simbolo::getNombre(void) const {
	return nombre_;
}

// Getter del TF
unsigned Simbolo::getTf (void) const {
	return tf_;
}

// Getter del IDF
float Simbolo::getIdf (void) const {
    return idf_;
}   

// Getter del TF-IDF
float Simbolo::getTf_Idf (void) const {
    return tf_idf_;
}

// Getter del valor normalizado
float Simbolo::getValorNormalizado (void) const {
    return valorNormalizado_;
}

// Setter del nombre
void Simbolo::setNombre (std::string nombre) {
	nombre_ = nombre;
}

// Setter del TF
void Simbolo::setTf (unsigned tf) {
	tf_ = tf;
}

// Setter del IDF
void Simbolo::setIdf (unsigned N, unsigned dfx) {
    idf_ = std::log10(N / dfx);
}

// Setter del TF-IDF
void Simbolo::setTf_Idf (void) {
    tf_idf_ = tf_ * idf_;
}

// Setter del valor normalizado
void Simbolo::setValorNormalizado (float nuevoValorNormalizado) {
    valorNormalizado_ = nuevoValorNormalizado;
}

// Sobrecarga del operador =
Simbolo& Simbolo::operator= (const Simbolo& otherSimbolo) {
	this -> setNombre(otherSimbolo.getNombre());
	this -> setTf(otherSimbolo.getTf());
	return *this;
}

// Incrementa a 1 el valor del TF 
void Simbolo::incrementar (void) {
	tf_++;
}

// Imprime el simbolo
void Simbolo::printSimbolo (void) const {
	std::cout << std::endl << "Simbolo Info:" << std::endl << "\t - Name: " << getNombre() << std::endl << "\t - Ammount: " << getTf() << std::endl;
}

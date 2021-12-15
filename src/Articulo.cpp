#include "../include/Articulo.hpp"

// Constructor por defecto de la clase.
Articulo::Articulo (void) {
	setId(0);
}

// Destructor de la clase.
Articulo::~Articulo (void) {
}

// Getter del ID
unsigned Articulo::getId (void) const {
	return id_;
}

// Getter del simbolo
std::vector<Simbolo> Articulo::getSimbolo(void) const {
	return simbolo_;
}

// Getter de la linea 
std::string Articulo::getLinea (void) const {
	return linea_;
}

// Getter del tamaño del vector longitud 
float Articulo::getVectorSize (void) const {
    return vectorSize_;
}

// Getter del vector que almacena los cosenos
std::vector<float> Articulo::getCosenos (void) const {
    return cosenos_;
}

// Setter del ID
void Articulo::setId (unsigned nuevoID) {
	id_ = nuevoID;
}

// Setter del simbolo
void Articulo::setSimbolo (std::vector<Simbolo> nuevoSimbolo) {
	simbolo_ = nuevoSimbolo;
}

// Setter de la linea
void Articulo::setLinea (std::string nuevaLinea) {
	linea_ = nuevaLinea;
}

// Setter del tamaño del vector longitud
void Articulo::setVectorSize (float nuevoVectorSize) {
    vectorSize_ = nuevoVectorSize;
}

// Genera los simbolos
void Articulo::generarSimbolos (void) {
	Preprocesador newPreprocesador(linea_);
	newPreprocesador.generarPalabras();
	simbolo_ = newPreprocesador.getVector();
}

// Busca si el vector de simbolos de un articulo contiene una palabra determinada
bool Articulo::contienePalabra (std::string str) {
    for (unsigned i = 0; i < simbolo_.size(); i++) {
        if (simbolo_[i].getNombre() == str) {
            return true;
        }
    }
    return false;
}

// Genera el IDF y el TF-IDF
void Articulo::generarMetricasArticulo (unsigned i, unsigned N, unsigned dfx) {
    simbolo_[i].setIdf(N, dfx);
    simbolo_[i].setTf_Idf();
}

// Genera el vector longitud
void Articulo::generarVectorSize (void) {
    vectorSize_ = 0.0;
    for (unsigned i = 0; i < simbolo_.size(); i++) {
        vectorSize_ += (pow(simbolo_[i].getTf_Idf(), 2));
    }
    vectorSize_ = std::sqrt(vectorSize_);
}

// Genera el valor normalizado
void Articulo::generarValorNormalizado (void) {
    for (unsigned i = 0; i < simbolo_.size(); i++) {
        simbolo_[i].setValorNormalizado(simbolo_[i].getTf_Idf() / getVectorSize());
    }
}

// Añade los cosenos
void Articulo::addCoseno (float tmp) {
    cosenos_.push_back(tmp);
}
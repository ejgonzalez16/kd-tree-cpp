#include "NodoKD.h"
#include <cstddef>

template <class T>
NodoKD<T>::NodoKD() {
	this->x = 0.0;
	this->y = 0.0;
	this->hijoIzq = NULL;
	this->hijoDer = NULL;
}

template< class T >
NodoKD<T>::NodoKD(float x, float y, T dato) {
	this->x = x;
	this->y = y;
	this->dato = dato;
	this->hijoIzq = NULL;
	this->hijoDer = NULL;
}

template <class T>
float NodoKD<T>::getX() {
	return this->x;
}

template <class T>
void NodoKD<T>::setX(float x) {
	this->x = x;
}

template <class T>
float NodoKD<T>::getY() {
	return this->y;
}

template <class T>
void NodoKD<T>::setY(float y) {
	this->y = y;
}

template <class T>
T NodoKD<T>::getDato() {
	return this->dato;
}

template <class T>
void NodoKD<T>::setDato(T& dato) {
	this->dato = dato;
}

template <class T>
NodoKD<T>* NodoKD<T>::getHijoIzq() {
	return this->hijoIzq;
}

template <class T>
void NodoKD<T>::setHijoIzq(NodoKD<T>* izq) {
	this->hijoIzq = izq;
}

template <class T>
NodoKD<T>* NodoKD<T>::getHijoDer() {
	return this->hijoDer;
}

template <class T>
void NodoKD<T>::setHijoDer(NodoKD<T>* der) {
	this->hijoDer = der;
}

//-----------------------------------------

template <class T>
unsigned int NodoKD<T>::altura() {
	std::vector<unsigned int> alturas;
	alturaRecursion(this, 0, alturas);
	unsigned int mayor = alturas[0];
	for (int i = 1; i < alturas.size(); i++) {
		if (alturas[i] > mayor) {
			mayor = alturas[i];
		}
	}
	return mayor;
}

template <class T>
void NodoKD<T>::alturaRecursion(NodoKD* nodo, unsigned int altura, std::vector<unsigned int>& alturas) {
	if (nodo->obtenerHijoIzq() != NULL) {
		alturaRecursion(nodo->obtenerHijoIzq(), altura + 1, alturas);
	}
	if (nodo->obtenerHijoDer() != NULL) {
		alturaRecursion(nodo->obtenerHijoDer(), altura + 1, alturas);
	}
	else {
		alturas.push_back(altura);
	}
}

template <class T>
int NodoKD<T>::obtenerCantidadHijos() {
	if (this->hijoDer == NULL && this->hijoIzq == NULL) {
		return 0;
	}
	if (this->hijoDer != NULL && this->hijoIzq != NULL) {
		return 2;
	}
	return 1;
}

template <class T>
NodoKD<T>* NodoKD<T>::obtenerMayor() {
	return obtenerMayorRecursion(this);
}

template <class T>
NodoKD<T>* NodoKD<T>::obtenerMayorRecursion(NodoKD* nodo) {
	if (nodo == NULL) {
		return NULL;
	}
	if (nodo->obtenerHijoDer() == NULL) {
		return nodo;
	}
	else {
		return obtenerMayorRecursion(nodo->obtenerHijoDer());
	}
	return NULL;
}

template <class T>
NodoKD<T>* NodoKD<T>::obtenerHijoNoVacio() {
	if (obtenerCantidadHijos() == 1) {
		if (this->hijoIzq != NULL) {
			return this->hijoIzq;
		}
		return this->hijoDer;
	}
	return NULL;
}
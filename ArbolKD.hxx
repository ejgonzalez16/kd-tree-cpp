#include "ArbolKD.h"
#include <queue>
#include <iostream>
#include <cmath>

template <class T>
ArbolKD<T>::ArbolKD() {
	this->raiz = NULL;
}

template <class T>
ArbolKD<T>::ArbolKD(int x, int y, T dato) {
	this->raiz->setX(x);
	this->raiz->setY(y);
}

template <class T>
ArbolKD<T>::~ArbolKD() {
	this->raiz = NULL;
	delete raiz;
}

template <class T>
int ArbolKD<T>::datoX() {
	return this->raiz->getX();
}

template <class T>
int ArbolKD<T>::datoY() {
	return this->raiz->getY();
}

template <class T>
void ArbolKD<T>::setRaiz(int x, int y, T dato) {
	this->raiz->setX(x);
	this->raiz->setY(y);
	this->raiz->setDato(dato);
}

template <class T>
bool ArbolKD<T>::esVacio() {
	return (this->raiz == NULL);
}

template <class T>
bool ArbolKD<T>::insertar(int x, int y, T dato) {
	return insertarRecursion(this->raiz, x, y, dato);
}

template <class T>
bool ArbolKD<T>::insertarRecursion(NodoKD<T>*& nodo, int x, int y, T dato) {
	if (nodo == NULL) {
		nodo = new NodoKD<T>;
		nodo->setX(x);
		nodo->setY(y);
		nodo->setDato(dato);
		return true;
	}
	if (nodo->getX() == x && nodo->getY() == y) return false;
	else {
		if (getNivelNodo(nodo->getX(), nodo->getY()) % 2 != 0) {
			if (nodo->getX() < x) {
				NodoKD<T>* hijoDer = nodo->getHijoDer();
				if (insertarRecursion(hijoDer, x, y, dato)) {
					nodo->setHijoDer(hijoDer);
					return true;
				}
			}
			else {
				NodoKD<T>* hijoIzq = nodo->getHijoIzq();
				if (insertarRecursion(hijoIzq, x, y, dato)) {
					nodo->setHijoIzq(hijoIzq);
					return true;
				}
			}
		}
		else {
			if (nodo->getY() < y) {
				NodoKD<T>* hijoDer = nodo->getHijoDer();
				if (insertarRecursion(hijoDer, x, y, dato)) {
					nodo->setHijoDer(hijoDer);
					return true;
				}
			}
			else {
				NodoKD<T>* hijoIzq = nodo->getHijoIzq();
				if (insertarRecursion(hijoIzq, x, y, dato)) {
					nodo->setHijoIzq(hijoIzq);
					return true;
				}
			}
		}
	}
	return false;
}

template<class T>
NodoKD<T>* ArbolKD<T>::buscar(float x, float y) {
	NodoKD<T>* dato  = new NodoKD<T>;
	if (!esVacio()) {
		float dist = distancia(x, y, this->raiz);
		dato = this->raiz;
		buscarRecursion(this->raiz, x, y, dato, dist);
	}
	return dato;
}

template<class T>
bool ArbolKD<T>::buscarRecursion(NodoKD<T>* nodo, float x, float y, NodoKD<T>*& dato, float& dist) {
	float distDer;
	float distIzq;
	if (nodo == NULL) {
		return false;
	}
	if (nodo->getX() == x && nodo->getY() == y) {
		dato = nodo;
		return true; //Indica si se debe hacer un return completo
	}
	if ((nodo->getHijoIzq() == NULL && nodo->getHijoDer() == NULL)) {
		if (dist == 0) {
			dato = nodo;
		}
		return false;
	}
	distDer = distancia(x,y, nodo->getHijoDer());
	distIzq = distancia(x,y, nodo->getHijoIzq());
	if (dist > distDer || dist > distIzq) {
		if (distDer > distIzq && distIzq != -1) {
			dist = distIzq;
			dato = nodo->getHijoIzq();
		}
		else if (distDer == -1 && distIzq < dist) {
			dist = distIzq;
			dato = nodo->getHijoIzq();
		}
		else if (distDer < distIzq && distDer != -1) {
			dist = distDer;
			dato = nodo->getHijoDer();
		}
		else if (distIzq == -1 && distDer < dist) {
			dist = distDer;
			dato = nodo->getHijoDer();
		}
	}
	if (buscarRecursion(nodo->getHijoIzq(), x, y, dato, dist))
		return true;
	if (buscarRecursion(nodo->getHijoDer(), x, y, dato, dist))
		return true;
	return true;
}

template<class T>
float ArbolKD<T>::distancia(float x, float y, NodoKD<T>* nodo2) {
	if (nodo2 == NULL) {
		return -1;
	}
	float dx = x - nodo2->getX();
	float dy = y - nodo2->getY();
	return std::sqrt((dx * dx) + (dy * dy));
}

template <class T>
int ArbolKD<T>::getNivelNodo(int datoX, int datoY) {
	std::vector<int> niveles;
	int nivel = 0;
	getNivelNodoRecursion(this->raiz, nivel, datoX, datoY, niveles);
	if (niveles.empty() || niveles.size() == 0) 
		return nivel;
	else {
		for (int i = 0; i < niveles.size(); i++) {
			if (niveles[i] != 0) return niveles[i];
		}
	}
}

template <class T>
void ArbolKD<T>::getNivelNodoRecursion(NodoKD<T>* nodo, int& nivel, int datoX, int datoY,
	std::vector<int>& niveles) {
	if (nodo == NULL) {
		nivel = 0;
		niveles.push_back(nivel);
		return;
	}
	if (datoX == nodo->getX() && datoY == nodo->getY()) {
		nivel++;
		niveles.push_back(nivel);
		return;
	}
	nivel++;
	getNivelNodoRecursion(nodo->getHijoIzq(), nivel, datoX, datoY, niveles);
	getNivelNodoRecursion(nodo->getHijoDer(), nivel, datoX, datoY, niveles);
}

template <class T>
void ArbolKD<T>::preOrden() {
	if (!this->esVacio()) {
		preOrdenRecursion(this->raiz);
	}
}

template <class T>
void ArbolKD<T>::preOrdenRecursion(NodoKD<T>* nodo) {
	if (nodo != NULL) {
		std::cout << nodo->getDato() << " ";
		preOrdenRecursion(nodo->getHijoIzq());
		preOrdenRecursion(nodo->getHijoDer());
	}
}

template <class T>
void ArbolKD<T>::inOrden() {
	if (!this->esVacio()) {
		inOrdenRecursion(this->raiz);
	}
}

template <class T>
void ArbolKD<T>::inOrdenRecursion(NodoKD<T>* nodo) {
	if (nodo != NULL) {
		inOrdenRecursion(nodo->getHijoIzq());
		std::cout << nodo->getDato() << " ";
		inOrdenRecursion(nodo->getHijoDer());
	}
}

template <class T>
void ArbolKD<T>::posOrden() {
	if (!this->esVacio()) {
		posOrdenRecursion(this->raiz);
	}
}

template <class T>
void ArbolKD<T>::posOrdenRecursion(NodoKD<T>* nodo) {
	if (nodo != NULL) {
		posOrdenRecursion(nodo->getHijoIzq());
		posOrdenRecursion(nodo->getHijoDer());
		std::cout << nodo->getDato() << " ";
	}
}

template <class T>
void ArbolKD<T>::nivelOrden() {
	if (!this->esVacio()) {
		std::queue<NodoKD<T>*> cola;
		cola.push(this->raiz);
		NodoKD<T>* nodo;
		while (!cola.empty()) {
			nodo = cola.front();
			cola.pop();
			std::cout << nodo->getDato() << " ";
			if (nodo->getHijoIzq() != NULL)
				cola.push(nodo->getHijoIzq());
			if (nodo->getHijoDer() != NULL)
				cola.push(nodo->getHijoDer());
		}
	}
}
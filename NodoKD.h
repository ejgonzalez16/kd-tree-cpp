#ifndef NodoKD_h
#define NodoKD_h

#include <vector>

template<class T>
class NodoKD {
private:
	float x;
	float y;
	T dato;
	NodoKD<T>* hijoIzq;
	NodoKD<T>* hijoDer;

	void alturaRecursion(NodoKD* nodo, unsigned int altura, std::vector<unsigned int>& alturas);
	NodoKD* obtenerMayorRecursion(NodoKD* nodo);
public:
	NodoKD();
	NodoKD(float x, float y, T dato);
	float getX();
	void setX(float x);
	float getY();
	void setY(float y);
	T getDato();
	void setDato(T& dato);
	NodoKD<T>* getHijoIzq();
	void setHijoIzq(NodoKD<T>* NO);
	NodoKD<T>* getHijoDer();
	void setHijoDer(NodoKD<T>* NE);


	unsigned int altura();
	int obtenerCantidadHijos();
	NodoKD* obtenerMayor();
	NodoKD* obtenerHijoNoVacio();
};
#include "NodoKD.hxx"
#endif
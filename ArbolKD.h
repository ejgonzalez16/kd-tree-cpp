#ifndef _ArbolKD_h_
#define _ArbolKD_h_
#include "NodoKD.h"
#include <vector>
#include <list>

template<class T>
class ArbolKD {
private:
	NodoKD<T>* raiz;
	bool insertarRecursion(NodoKD<T>*& nodo, int x, int y, T dato);
	void preOrdenRecursion(NodoKD<T>* nodo);
	void inOrdenRecursion(NodoKD<T>* nodo);
	void posOrdenRecursion(NodoKD<T>* nodo);
	void getNivelNodoRecursion(NodoKD<T>* nodo, int& nivel, int datoX, int datoY,
		std::vector<int>& niveles);
	int getNivelNodo(int datoX, int datoY);
	bool buscarRecursion(NodoKD<T>* nodo, float x, float y, NodoKD<T>*& dato, float& distancia);
	float distancia(float x, float y, NodoKD<T>* nodo2);
public:
	ArbolKD();
	ArbolKD(int x, int y, T dato);
	~ArbolKD();
	int datoX();
	int datoY();
	void setRaiz(int x, int y, T dato);
	bool esVacio();
	bool insertar(int x, int y, T dato);
	NodoKD<T>* buscar(float x, float y);

	void preOrden();
	void inOrden();
	void posOrden();
	void nivelOrden();
};
#include "ArbolKD.hxx"
#endif

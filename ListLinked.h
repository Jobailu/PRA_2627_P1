#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public list<T> {
	private:
		Node<T>* first;
		int n;
	
	public:
		ListLinked(){
			first == nullptr;
			n = 0;
		}
		~ListLinked(){
			while (first != nullptr){
				T aux = first->next;
				delete first;
				first = aux;
			}
		}
		void insert(int pos, T e) override {
			if (pos < 0 || pos > n){
				throw std::out_of_range("Posición erronea");
			}
			if (pos == 0) {
			fist = new Node<T>(e, first);
			}else{
				Node<T>* anterior = obtenerNodo(pos-1);
			anterior -> next = new Node<T>(e, anterior ->next);
			}

			n++;
		}
		void append(T e) override {
			insert(n, e);
		}
		int size() override{
			return n;
		}
		bool empty() override {
			return n == 0;
		}

		T get(int pos) override {
			return obtenerNodo(pos) -> data;
		}
		void set(int pos, T e) override {
			obtenerNodo(pos)->data = e;
		}
		T remove (int pos) override {
			if (pos < 0 || pos >= n) {
				throw std::out_of_range("Posición inválida");
			}
			Node <T>* eliminado;

			if (pos == 0) {
				eliminado = first;
				first = first -> next;
			} else {
				Node<T>* anterior = obtenerNodo(pos -1);
				eliminado = anterior -> next;
				anterior-> next = eliminado->next;
			}

			T valor = eliminado->data;
			delete eliminado;
			n--;

			return valor;
		}
		int search(T e) override {
			Node<T>* actual = first;
			int pos = 0;

			while (actual != nullptr) {
				if (actual->data == e) {
					return pos;
				}

				actual = actual ->next;
				pos++;
			}

			return -1;
		}

		T operator [](int pos) {
			return get(pos);
		}

		friend std::ostream& operator << (std::ostream& out, ListLinked<T>& list){
			out << "[";

			if (list.first != nullptr) {
				out << '\n';

				Node<T>* actual = list.first;

				while (actual != nullptr) {
					out << " " << actual->data << '\n';
					actual = actual -> next;
				}
			}

			return out << "]";
		}
};
#endif

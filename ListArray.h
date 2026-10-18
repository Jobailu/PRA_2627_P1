#include <ostream>
#include <stdexcept>
#include "list.h"

template <typename T>
class ListArray : public list<T> {
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;
		void resize (int new_size){
			T* new_arr = new T [new_size];
			for (int i = 0; i < new_size; i++){
				arr[i] = new_arr[i];		
			}
			delete[] arr;
			arr = new_arr;
			max = new_size;
		}
	public:
		ListArray(){
			arr = new T[MINSIZE];
			max = MINSIZE;
			n = 0;
		}
		virtual ~ListArray() override{
			delete[] arr;
		}
		T operator[] (int pos){
			if (pos > MINSIZE-1){
				throw std::out_of_range("La posición indicada está fuera de rango.");
			}
			return arr[pos];
		}
		friend std::ostream&operator<<( std::ostream &out, ListArray<T> &list){
			out<< "[";
			for ( int i = 0; i < list.n ; i++){
				out << list.arr[i];
				if (i < list.n -1){
				out << ", ";
				}
			}
			out << "]";
			return out;
		}
};

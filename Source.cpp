#include<stdio.h>
#include<iostream>
using namespace std;
template<typename T>
class vector {
	T* data;
	int size;
public:
	vector() {
		size = 0;
		data = NULL;
	}
	vector(const int size) {
		this->size = size;
		data = new T[size];
	}
	vector(const vector& object) {
		size = object.size;
		data = new T[size];
		for (int i = 0; i < size; i++) {
			data[i] = object.data[i];
		}
	}
	~vector() {
		delete[] data;
	}
};
int main() {

}
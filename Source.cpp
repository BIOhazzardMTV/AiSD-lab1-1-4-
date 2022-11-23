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
	T& operator [](const int index) {
		if (index < 0 || index > size) throw("Incorrect index");
		return data[index];
	}
	vector& operator +=(const vector& object) {
		if (size != object.size) throw("Different dimensions");
		for (int i = 0; i < size; i++) {
			data[i] += object.data[i];
		}
		return(*this);
	}
	vector& operator -=(const vector& object) {
		if (size != object.size) throw("Different dimensions");
		for (int i = 0; i < size; i++) {
			data[i] -= object.data[i];
		}
		return(*this);
	}
	vector& operator *=(const T& value) {
		for (int i = 0; i < size; i++) {
			data[i] *= value;
		}
		return(*this);
	}
};
int main() {

}
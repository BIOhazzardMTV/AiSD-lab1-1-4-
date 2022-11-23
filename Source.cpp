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
	vector& operator =(const vector& object) {
		delete[] data;
		size = object.size;
		data = new T[size];
		for (int i = 0; i < size; i++) {
			data[i] = object.data[i];
		}
		return(*this);
	}
	vector operator +(const vector& object) {
		if (size != object.size) throw("Different dimensions");
		vector tmp(*this);
		tmp += object;
		return tmp;
	}
	vector operator -(const vector& object) {
		if (size != object.size) throw("Different dimensions");
		vector tmp(*this);
		tmp -= object;
		return tmp;
	}
	friend std::ostream& operator<<(std::ostream& out, const vector& object) {
		for (int i = 0; i < object.size; i++) {
			out << object.data[i] << "  ";
		}
		return out;
	}
	friend vector operator * (const vector& object, const T& value) {
		vector tmp(object.size);
		for (int i = 0; i < object.size; i++) {
			tmp.data[i] = object.data[i] * value;
		}
		return tmp;
	}
	friend vector operator * (const T& value, const vector& object) {
		vector tmp(object.size);
		for (int i = 0; i < object.size; i++) {
			tmp.data[i] = object.data[i] * value;
		}
		return tmp;
	}
};
int main() {

}
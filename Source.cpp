#include<stdio.h>
#include<iostream>
#include<cmath>
#include<conio.h>
#include<limits>
using namespace std;
const double epsilon = 0.0001;
template<typename T>
class vector{
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
		for (int i = 0; i < size; i++) {
			data[i] = 0;
		}
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
	T& operator [] (const int index) {
		if (index < 0 || index > size) throw("Incorrect index");
		return data[index];
	}
	vector& operator += (const vector& object) {
		if (size != object.size) throw("Different dimensions");
		for (int i = 0; i < size; i++) {
			data[i] += object.data[i];
		}
		return(*this);
	}
	vector& operator -= (const vector& object) {
		if (size != object.size) throw("Different dimensions");
		for (int i = 0; i < size; i++) {
			data[i] -= object.data[i];
		}
		return(*this);
	}
	vector& operator *= (const T& value) {
		for (int i = 0; i < size; i++) {
			data[i] *= value;
		}
		return(*this);
	}
	vector& operator = (const vector& object) {
		delete[] data;
		size = object.size;
		data = new T[size];
		for (int i = 0; i < size; i++) {
			data[i] = object.data[i];
		}
		return(*this);
	}
	vector operator + (const vector& object) {
		if (size != object.size) throw("Different dimensions");
		vector tmp(*this);
		tmp += object;
		return tmp;
	}
	vector operator - (const vector& object) {
		if (size != object.size) throw("Different dimensions");
		vector tmp(*this);
		tmp -= object;
		return tmp;
	}
	friend std::ostream& operator << (std::ostream& out, const vector& object) {
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
	bool operator == (const vector& object) {
		if (size != object.size) throw("Different dimensions");
		for (int i = 0; i < size; i++) {
			if (double(abs(data[i] - object.data[i]) > epsilon)) return false;
		}
		return true;
	}
	bool operator != (const vector& object) {
		if (size != object.size) throw("Different dimensions");
		for (int i = 0; i < size; i++) {
			if (double(abs(data[i] - object.data[i]) <= epsilon)) return false;
		}
		return true;
	}
	vector& operator /= (const T& value) {
		if (value == 0) throw("Divizion by zero");
		for (int i = 0; i < size; i++) {
			data[i] /= value;
		}
		return(*this);
	}
	friend vector operator / (const vector& object, const T& value) {
		vector tmp(object.size);
		for (int i = 0; i < object.size; i++) {
			tmp.data[i] = object.data[i] / value;
		}
		return tmp;
	}
	T operator * (const vector& object) {
		if (size != object.size) throw("Different dimensions");
		T tmp = 0;
		for (int i = 0; i < size; i++) {
			tmp += data[i] * object.data[i];
		}
		return tmp;
	}
	vector<double> perpendicular() {
		vector<double> tmp(size);
		double len = 0;
		tmp[0] = -1 * data[0];
		len += pow(tmp[0], 2);
		for (int i = 1; i < size; i++) {
			tmp[i] = double(data[i]);
			len += pow(tmp[i], 2);
		}
		len = sqrt(len);
		return(tmp /= len);
	}
	int getSize() {
		return size;
	}
};
void ignoreLine() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
template<typename T>
T getT() {
	while (true) {
		T x{};
		std::cin >> x;
		if (std::cin.fail()) {
			std::cin.clear();
			ignoreLine();
			system("cls");
			std::cout << "Oops, that input is invalid.  Please try again.\n" << endl;
		}
		else {
			ignoreLine();
			return x;
		}
	}
}
int getSize() {
	int s = -1;
	system("cls");
	std::cout << "Enter the dimension of vectors: " << endl;
	s = getT<int>();
	while (s <= 0) {
		std::cout << "Oops, that input is invalid.  Please try again.\n" << endl;
		if(_getch());
		s = getT<int>();
	}
	return s;
}
template<typename T>
vector<T> workWithVector(vector<T>& object, char num) {
	int index = -1;
	while (true) {
		system("cls");
		std::cout << "\tWorking with vector #" << num << endl;
		std::cout << "1 - Print vector" << endl;
		std::cout << "2 - Enter value by index" << endl;
		std::cout << "0 - Go back" << endl;
		int ans = _getch();
		system("cls");
		switch (ans){
		case '1':
			system("cls");
			std::cout << object << endl;
			std::cout << "Press any key to continue..." << endl;
			if(_getch());
			break;
		case '2':
			index = -1;
			std::cout << "Enter the index: ";
			index = getT<int>();
			while (index < 0 || index >= object.getSize()) {
				std::cout << "Oops, that input is invalid.  Please try again.\n" << endl;
				index = getT<int>();
			}
			std::cout << "Enter the value : ";
			object[index] = getT<T>();
			break;
		case '0':
			return object;
			break;
		}
	}
}
template<typename T>
void scalarMult(vector<T>& object) {
	std::cout << "Enter the scalar: ";
	T scalar = getT<T>();
	std::cout << object << endl << "*" << endl << scalar << endl << "=" << endl << operator * (object, scalar) << endl;
	std::cout << "Press any key to continue..." << endl;
	if(_getch());
}
template<typename T>
void scalarDiv(vector<T>& object) {
	std::cout << "Enter the scalar: ";
	T scalar = getT<T>();
	std::cout << object << endl << "/" << endl << scalar << endl << "=" << endl << object / scalar << endl;
	std::cout << "Press any key to continue..." << endl;
	if(_getch());
}
int main() {
	int ans2 = -1;
	int size = getSize();
	vector<double> v1(size);
	vector<double> v2(size);
	while (true) {
		try {
			system("cls");
			std::cout << "1 - Working with the 1-st vector" << endl;
			std::cout << "2 - Working with the 2-nd vector" << endl;
			std::cout << "3 - Vector addition (v1 + v2)" << endl;
			std::cout << "4 - Vector subtraction (v1 - v2)" << endl;
			std::cout << "5 - Vector multiplication (v1 * v2)" << endl;
			std::cout << "6 - Multiplication of a vector by a scalar(v1*a or v2*a)" << endl;
			std::cout << "7 - Division of a vector by a scalar(v1/a or v2/a)" << endl;
			std::cout << "8 - Perpendicular vector(for v1 or v2)" << endl;
			std::cout << "9 - Vector equality(v1 == v2)" << endl;
			std::cout << "0 - Exit the program" << endl;
			std::cout << "\n\n\tDimension = " << size << endl;;
			int ans = _getch();
			system("cls");
			switch (ans) {
			case '1':
				v1 = workWithVector(v1, '1');
				break;
			case '2':
				v2 = workWithVector(v2, '2');
				break;
			case '3':
				std::cout << v1 << endl << "+" << endl << v2 << endl << "=" << endl << v1 + v2 << endl;
				std::cout << "Press any key to continue..." << endl;
				if (_getch());
				break;
			case '4':
				std::cout << v1 << endl << "-" << endl << v2 << endl << "=" << endl << v1 - v2 << endl;
				std::cout << "Press any key to continue..." << endl;
				if (_getch());
				break;
			case '5':
				std::cout << v1 << endl << "*" << endl << v2 << endl << "=" << endl << v1 * v2 << endl;
				std::cout << "Press any key to continue..." << endl;
				if (_getch());
				break;
			case '6':
				std::cout << "Select vector(1 or 2)" << endl;
				ans2 = getT<int>();
				system("cls");
				while (ans2 != 1 && ans2 != 2) {
					std::cout << "Oops, that input is invalid.  Please try again.\n" << endl;
					ans2 = getT<int>();
				}
				if (ans2 == 1) scalarMult(v1);
				else scalarMult(v2);
				break;
			case '7':
				std::cout << "Select vector(1 or 2)" << endl;
				ans2 = getT<int>();
				system("cls");
				while (ans2 != 1 && ans2 != 2) {
					std::cout << "Oops, that input is invalid.  Please try again.\n" << endl;
					ans2 = getT<int>();
				}
				if (ans2 == 1) scalarDiv(v1);
				else scalarDiv(v2);
				break;
			case '8':
				std::cout << "Select vector(1 or 2)" << endl;
				ans2 = getT<int>();
				system("cls");
				while (ans2 != 1 && ans2 != 2) {
					std::cout << "Oops, that input is invalid.  Please try again.\n" << endl;
					ans2 = getT<int>();
				}
				if (ans2 == 1) std::cout << "The unit vector perpendicular to the" << endl << v1 << endl << "is" << endl << v1.perpendicular() << endl;
				else std::cout << "The unit vector perpendicular to the" << endl << v2 << endl << "is" << endl << v2.perpendicular() << endl;
				if (_getch());
				break;
			case '9':
				std::cout << "Is" << endl << v1 << endl << "==" << endl << v2 << endl << "?" << endl << ((v1 == v2) ? "True" : "False") << endl;
				if (_getch());
				break;
			case '0':
				std::cout << "See you soon :)" << endl;
				return 0;
			default:
				break;
			}
		}
		catch (const char* msg) {
			std::cout << msg << endl;
			std::cout << "Press any key to continue..." << endl;
			if (_getch());
		}
	}

}

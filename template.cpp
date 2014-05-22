/*
 * result
 *
 * 6 10
 * 6
 * 100
 * 25 0
 *
 */

#include <iostream>
using namespace std;

//template <typename T>

template <class T>
class mypair {
	T value1, value2;
public:
	mypair(T first, T second) {
		value1 = first;
		value2 = second;
	}
	T getmax();
};

template <class T>
T mypair<T>::getmax() {
	T retval;
	retval = value1 > value2 ? value1 : value2;
	return retval;
}

// ----------------------------------------------

template <class T>
class sepair {
	T value1, value2;
public:
	sepair(T first, T second) {
		value1 = first;
		value2 = second;
	}
	T module() {
		return 0;
	}
};

template <>
class sepair<int> {
	int value1, value2;
public:
	sepair(int first, int second) {
		value1 = first;
		value2 = second;
	}
	int module();
};

int sepair<int>::module() {
	return value1 % value2;
}

// ----------------------------------------------

template <class T>
T GetMax(T a, T b) {
	T result;
	result = (a > b) ? a : b;
	return result;
}

template <class T, class U>
T GetMin(T a, U b) {
	return (a < b) ? a : b;
}

int main() {
	int i = 5, j = 6, k;
	long l = 10, m = 5, n;
	k = GetMax(i, j);
	n = GetMax(l, m);
	cout << k << " " << n << endl;
	
	k = GetMin(j, l);
	cout << k << endl;
	
	mypair<int> myobject(100, 75);
	cout << myobject.getmax() << endl;
	
	sepair<int> myints(100, 75);
	sepair<float> myfloats(100.0, 75.0);
	cout << myints.module() << " ";
	cout << myfloats.module() << endl;
	
	return 0;
}

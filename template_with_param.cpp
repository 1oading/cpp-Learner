/*
 * result
 * 100 3.1416
 *
 */

#include <iostream>
using namespace std;

/*
 *
 * template <class T>
 * template <class T, class U>
 * template <class T, int N>
 * template <class T = char> 有一个默认值 
 * template <int Tfunc(int)> 参数为一个函数 
 *
 */

template <class T, int N>
class array {
	T memblock[N];
public:
	void setmember(int x, T value);
	T getmember(int x);
};

template <class T, int N>
void array<T, N>::setmember(int x, T value) {
	memblock[x] = value;
}

template <class T, int N>
T array<T, N>::getmember(int x) {
	return memblock[x];
}

int main() {
	array<int, 5> myints;
	array<float, 5> myfloats;
	myints.setmember(0, 100);
	myfloats.setmember(3, 3.1416);
	cout << myints.getmember(0) << " ";
	cout << myfloats.getmember(3) << endl;
	return 0;
}

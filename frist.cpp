#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

#define PI 3.14159265

class COrigin;

class CVector {
	int myown;
	public:
		static int n;
		int x, y;
		CVector() {myown = 2; x = 0; y = 0; n++;};
		CVector(int, int);
		~CVector() {n--;}
		CVector operator+(CVector);
		CVector& operator=(const CVector& param);
		
		friend CVector multiXY(CVector);
		void convert(COrigin o);
};

class COrigin {
private:
	int origin;
public:
	COrigin() {origin = 0;}
	COrigin(int);
	friend class CVector;
};

COrigin::COrigin(int o) {
	origin = o;
}

int CVector::n = 0;

CVector::CVector(int a, int b) {
	myown = 2;
	x = a;
	y = b;
}

CVector CVector::operator+(CVector param) {
	CVector temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return temp;
}

CVector& CVector::operator=(const CVector& param) {
	x = param.x;
	y = param.y;
	return *this;
}

CVector multiXY(CVector vectorparam) {
	CVector result;
	result.x = vectorparam.x * vectorparam.myown;
	result.y = vectorparam.y * vectorparam.myown;
	return result;
}

void CVector::convert(COrigin o) {
	x += o.origin;
	y += o.origin;
}

void increase(void* data, int type) {
	switch(type) {
	case sizeof(char):
		(*((char*)data))++;
		break;
	case sizeof(short):
		(*((short*)data))++;
		break;
	case sizeof(long):
		(*((long*)data))++;
		break;
	}
}

int addition(int a, int b) {
	return a + b;
}

int subtraction(int a, int b) {
	return a - b;
}

int (*myminus)(int, int) = subtraction;

int operation(int x, int y, int (*functocall)(int, int)) {
	int g;
	g = (*functocall)(x, y);
	return g;
}

int main() {
	int tmp_var(10);
	{
		tmp_var = 11;
		cout << tmp_var << " ";
	}
	cout << tmp_var << endl;
	
	int decimal = 75;
	int octal = 0113;
	int hexadecimal = 0x4b;
	cout << decimal << " ";
	cout << octal << " ";
	cout << hexadecimal << endl;
	
	double tmp_double_1 = 6.03e3;
	cout << tmp_double_1 << endl;
	
	string string_1 = "Hello World!";
	cout << string_1 << endl;
	string string_2 = "Hello World!\b";
	cout << string_2 << endl;
	string string_3 = "Improve your \
	programing.";
	cout << string_3 << endl;
	string string_4 = "\23\40\x20\x4a";
	cout << string_4 << endl;
	string string_5 = "we form" "a single" "string" "of characters";
	cout << string_5 << endl;
	//string wideChar = l"This is a wide character string";
	//cout << wideChar << endl;
	
	const int pi = 3.14159265;
	
	int easy_if = (3 > 2) ? 3 : 2;
	cout << easy_if << endl;
	
	int tmp;
	int instru_with_dot = (tmp = 3, tmp + 2);
	cout << instru_with_dot << endl;
	
	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(double) << endl;
	
	string user_input;
	cout << "Type something int : ";
	getline(cin, user_input);
	cout << "You typed : " << user_input << endl;
	int integer_in_input = 0;
	stringstream(user_input) >> integer_in_input;
	cout << integer_in_input << endl;
	
	char tmpName[20] = "Whats your name\?";
	cout << tmpName << endl;
	
	char tmpbuffer[50];
	cout << "cin.getline : ";
	cin.getline(tmpbuffer, 50);
	cout << tmpbuffer << endl;
	
	int m, n;
	m = operation(7, 5, addition);
	n = operation(20, m, myminus);
	cout << n << endl;
	
	/*
	char input[100];
	int i, n;
	long *l;
	cout << "How many numbers do you want to type in?";
	cin.getline(input, 100);
	i = atoi(input);
	l = new long[i];
	if (l == NULL) {
		exit(1);
	}
	for (n = 0; n < i; n++) {
		cout << "Enter number : ";
		cin.getline(input, 100);
		l[n] = atol(input);
	}
	cout << "You have entered : ";
	for (n = 0; n < i; n++) {
		cout << l[n] << ", ";
	}
	delete[] l;
	*/
	
	/*
	int* tmp_malloc;
	tmp_malloc = (int*)malloc(5 * sizeof(int));
	*tmp_malloc = 123;
	
	int* tmp_calloc;
	tmp_calloc = (int*)calloc(5, sizeof(int));
	
	int* tmp_realloc;
	tmp_realloc = (int*)realloc(tmp_malloc, 10 * sizeof(int));
	if (tmp_realloc == NULL) {
		exit(1);
	}
	
	cout << *tmp_malloc << " " << *tmp_realloc << endl;
	
	free(tmp_malloc);
	free(tmp_calloc);
	free(tmp_realloc);
	*/
	
	/*
	typedef char C;
	typedef unsigned int WORD;
	*/
	
	/*
	union mix_t {
		long l;
		struct {
			short hi;
			short lo;
		} s;
		char c[4];
	} mix;
	*/
	
	/*
	enum colors_t {black, blue, green, cyan, red, purple, yellow, white};
	
	enum mouths_t {january=1, february, march, april,
					may, june, july, august, september,
					october, november, december} y2k;
	*/
	
	// friend
	CVector vect1(2, 3), vect2;
	vect2 = multiXY(vect1);
	cout << vect2.x << " " << vect2.y << endl;
	
	COrigin ogn(3);
	CVector vect3(3, 4);
	vect3.convert(ogn);
	cout << vect3.x << " " << vect3.y << endl;
	
	return 0;
}

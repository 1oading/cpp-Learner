#include <iostream>
using namespace std;

int main() {
	char myarray[10];
	try {
		for (int i = 0; i <= 10; i++) {
			if (i > 9) {
				throw "Out of range";
			}
			myarray[i] = 'z';
		}
	}
	catch(const char* str) {
		cout << "Exception: " << str << endl;
	}
	catch(...) {
		cout << "Exception occurred." << endl;
	}
	return 0;
}

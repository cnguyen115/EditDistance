#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include "EditDistance.h"

using namespace std;

int main()
{
	string input1, input2 = "";
	
	cout << "Enter first string: ";
	cin >> input1;
	
	cout << "Enter second string: ";
	cin >> input2;
	
	EditDistance matrix;
	
	matrix.setInput(input1,input2);
	
	cout << "Distance: " << matrix.calculate() << endl;
	
	cout << "Matrix: " << endl << matrix.printMatrix();
	
	
	return 0;
}

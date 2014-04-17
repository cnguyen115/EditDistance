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
	
	if (!matrix.setInput(input1,input2))
	{
		cout << "Error: Inputs Invalid";
	}
	
	matrix.calculate();
	
	cout << "Matrix: " << endl << matrix.printMatrix() << endl;	
	cout << "Distance: " << matrix.returnDistance() << endl;
	cout << "Alignment: " << endl << matrix.returnAlignment() << endl;
	
	return 0;
}

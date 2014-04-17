#include "EditDistance.h"

#include <iostream>
/**
 * Sets the two inputs to compare
 * @param setInput1, setInput2 - the inputs to compare
 * @return - True if the input is valid and False otherwise
 */
bool EditDistance::setInput(const string& setInput1, const string& setInput2)
{ 	// validate the input, check if its empty
	if ((!setInput1.empty() && !setInput2.empty())) 
	{
		input1 = setInput1;
		input2 = setInput2;
		
		return true;
	}
	else
		return false;
}

/**	
 * Calculate the edit distance
 * @param input1, input2 - the two inputs to be compared
 * @return - the edit distance
 */
int EditDistance::calculate()
{ 
	vector< vector<int> > matrix (input1.size()+1, vector<int> (input2.size()+1, 0));
	
	distance = 0;
	
	// input2 are columns of the matrix, initialize the first row from 0 to size of input2
	for (unsigned int i = 0; i < input2.size()+1; i++)
	{
		matrix[0][i] = i;
	}
	
	// input1 are rows of the matrix, initialize the first column from 0 to size of input1
	for (unsigned int i = 0; i < input1.size()+1; i++)
	{
		matrix[i][0] = i;
	}
	
	//Edit Distance algorithm
	for (unsigned int i = 1; i < input1.size()+1; i++)
	{
		for (unsigned int j = 1; j < input2.size()+1; j++)
		{
			if (input1.compare(i-1,1,input2,j-1,1) == 0)
			{
				
				matrix[i].at(j) = matrix[i-1].at(j-1);
				cout << "match found" << 	endl;
			}
			else
			{
				if (matrix[i].at(j-1) < matrix[i-1].at(j))
				{
					matrix[i].at(j) = matrix[i].at(j-1) + 1;
				}
				else
				{
					matrix[i].at(j) = matrix[i-1].at(j) + 1;
				}
			}
		}
	}
	
	//store the distance which is at the bottom right corner of the matrix
	distance = matrix[input1.size()].at(input2.size());
	
	//Drawing the awful matrix	
	string drawMatrix = "       ";
	
	for (unsigned int i = 0; i < input2.size()+1; i++)
	{
		ostringstream convert;
		convert << i;
		
		if (i < 10)
		{
			drawMatrix = drawMatrix + "   " + convert.str() + "   ";
		}
		else
		{
			drawMatrix = drawMatrix + "  " + convert.str() + "   ";
		}
	}
	
	drawMatrix = drawMatrix + "\n" + "      -";
	
	for (unsigned int i = 0; i < input2.size()+1; i++)
	{
		drawMatrix = drawMatrix + "-------";
	}
	
	drawMatrix = drawMatrix + "\n" + "   0  |";
	
	for (unsigned int i = 0; i < input2.size()+1; i++)
	{
		ostringstream convert;
		convert << i;
		drawMatrix = drawMatrix + "   " + convert.str() + "  |";
	}
	
	for (unsigned int i = 1; i < input1.size()+1; i++)
	{
		ostringstream convert;
		convert << i;
		drawMatrix = drawMatrix + "\n" + "   " + convert.str() + "  |";
		for (unsigned int j = 0; j < input2.size()+1; j++)
		{
			ostringstream convert;
			convert << matrix[i].at(j);
			
			if (j < 10)
			{
				drawMatrix = drawMatrix + "   " + convert.str() + "  |";
			}
			else
			{
				drawMatrix = drawMatrix + "  " + convert.str() + "  |";
			}
		}
	}
	cout << drawMatrix;
	return distance;
}

/**
 * Prints out the Distance, or Alignment
 * @param None
 * @return - the text requested
 */
string EditDistance::printMatrix()
{ 
	return drawMatrix; 
}

int EditDistance::returnDistance()
{ 
	return distance; 
}

string EditDistance::returnAlignment()
{ 
	return alignment; 
}

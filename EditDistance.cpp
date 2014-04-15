#include "EditDistance.h"

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
	vector < vector <int> > matrix;
	
	// input2 are columns of the matrix, initialize the first row from 0 to size of input2
	for (unsigned int i = 0; i < input2.size(); i++)
	{
		matrix[0][i] = i;
	}
	
	// input1 are rows of the matrix, initialize the first column from 0 to size of input1
	for (unsigned int i = 0; i < input1.size(); i++)
	{
		matrix[i][0] = i;
	}
}

/**
 * Prints out the Matrix, Distance, or Alignment
 * @param None
 * @return - the text requested
 */
void EditDistance::returnMatrix()
{ 
	return matrix; 
}

void EditDistance::returnDistance()
{ 
	return distance; 
}

void EditDistance::returnAlignment()
{ 
	return alignment; 
}

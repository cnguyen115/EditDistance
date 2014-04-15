#ifndef EDITDISTANCE_H
#define EDITDISTANCE_H

#include <string>   /* For C++ strings */
#include <stdio.h>  /* For standard I/O */
#include <stdlib.h> /* For miscellenous C functions */
#include <vector>

using namespace std;

/**
 * This class implements the edit distance.
 */

class EditDistance
{
	/** The public members **/
	public:

		/**
		 * The default constructor
		 */
		EditDistance(){}
		
		/**
		 * Sets the two inputs to compare
		 * @param setInput1, setInput2 - the inputs to compare
		 * @return - True if the input is valid and False otherwise
		 */
		bool setInput(const string& setInput1, const string& setInput2){ return false;  }

		/**	
		 * Calculate the edit distance
		 * @param input1, input2 - the two inputs to be compared
		 * @return - the edit distance
		 */
		int calculate(){ return 0; }

		/**
		 * Returns the Matrix, Distance, or Alignment
		 * @param None
		 * @return - the text requested
		 */
		void returnMatrix() { return 0; }
		void returnDistance() { return 0; }
		void returnAlignment() { return 0; }

		/* The protected members */
	protected:
		string input1, input2, matrix, alignment;
		unsigned int distance;

};

#endif

#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;

int main()
{
	int num1 = 0;   //number of commands processed(how many values read from the input file)
	int temp;       //placeholder
	ArrayStack theStack; //stack


	//open input file
	ifstream infile;
	infile.open("input.dat");

	if (!infile) //file could not be opened
	{
		cerr << "Error: file could not be opened.\n";
		system("pause");
		exit(10);
	}

	//Read in the file
	while (!infile.eof())
	{
		num1++;
		infile >> temp;

		if (temp % 2 == 0)
		{
			theStack.push(temp);
		}
		else
		{
			theStack.pop();
		}

	}

	//output printout
	cout << "######################################################################\n";
	cout << "   Assignment 4 - Resizing the Stack\n";
	cout << "   CMPS 3013\n";
	cout << "   Katherine C. McNabb\n\n";

	cout << "   Config Params: " << theStack.params << '\n';
	cout << "   Full Threshold: " << theStack.fullThresh << '\n';
	cout << "   Shrink Threshold: " << theStack.shrinkThresh << '\n';
	cout << "   Grow Ratio: " << theStack.growRatio << '\n';
	cout << "   Shrink Ratio: " << theStack.shrinkRatio << '\n';

	cout << "   Processed " << num1 << " of commands.\n";

	cout << "   Max Stack Size: " << theStack.maxSize << '\n';
	cout << "   End Stack Size: " << theStack.size << '\n';
	cout << "   Stack Resized: " << theStack.resizeTimes << " times\n";

	cout << "######################################################################\n";

	ofstream outfile;
	outfile.open("output.dat");

	if (!outfile) //file could not be opened
	{
		cerr << "Error: file could not be opened.\n";
		system("pause");
		exit(10);
	}

	//outfile printout
	outfile << "######################################################################\n";
	outfile << "   Assignment 4 - Resizing the Stack\n";
	outfile << "   CMPS 3013\n";
	outfile << "   Katherine C. McNabb\n\n";

	outfile << "   Config Params: " << theStack.params << '\n';
	outfile << "   Full Threshold: " << theStack.fullThresh << '\n';
	outfile << "   Shrink Threshold: " << theStack.shrinkThresh << '\n';
	outfile << "   Grow Ratio: " << theStack.growRatio << '\n';
	outfile << "   Shrink Ratio: " << theStack.shrinkRatio << '\n';

	outfile << "   Processed " << num1 << " of commands.\n";

	outfile << "   Max Stack Size: " << theStack.maxSize << '\n';
	outfile << "   End Stack Size: " << theStack.size << '\n';
	outfile << "   Stack Resized: " << theStack.resizeTimes << " times\n";

	outfile << "######################################################################\n";

	//close files
	infile.close();
	outfile.close();

	return 0;
}
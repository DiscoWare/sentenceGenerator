#include "stdafx.h"
#include "Dictionary.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

/*
Author: Steven Steele
Date: February 19, 2018

Assignment: Lab_02
*/
int main()
{
	Dictionary example("nounlist.txt", "verblist.txt",
		"adverblist.txt", "adjectivelist.txt", "prepositionlist.txt", "articlelist.txt");
	bool done = false;

	cout << "          Sentence Generator\n"
		<< "---------------------------------------\n"
		<< "This program generates random sentences\n\n";

	while (!done)
	{
		cout << "Choose an option:\n" << "1. Generate Random Sentence";
		cout << "\n2. Quit\n";
		int input;
		cin >> input;
		if (!cin)
		{
			cout << "\nINVALID INPUT. Please enter '1' or '2'.\n\n";
			cin.clear();
			cin.ignore(100, '\n');
		}
		else
		{
			if (input == 1)
			{
				cout << "\n" << example.generateSentence() << "\n\n";
			}
			else if (input == 2)
			{
				done = true;
			}
			else
			{
				cout << "\nYour input could not be understood. Please enter '1' or '2'.\n\n";
			}
		}
	}
	cout << "\nThanks for playing!\n";
	system("Pause");
	return 0;
}
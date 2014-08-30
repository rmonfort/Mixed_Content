#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;
	// Get a line from input file
	while (getline(ifs, line))
	{
		istringstream iss(line);
		string temp, numbers, words;
		// Seperate each part of the line by commas
		while (getline(iss, temp, ','))
		{
			// Determine if said part of string is a digit or not and copy to appropriate string
			if (isdigit(temp[0]))
			{
				numbers += (temp + ',');
			}
			else
			{
				words += (temp + ',');
			}
		}

		// Format accordingly and output results 
		if (!words.empty() && !numbers.empty())
		{
			words.pop_back();
			numbers.pop_back();
			cout << words << "|" << numbers << endl;
		}
		else if (!words.empty())
		{
			words.pop_back();
			cout << words << endl;
		}
		else if (!numbers.empty())
		{
			numbers.pop_back();
			cout << numbers << endl;
		}
	}

	return 0;
}
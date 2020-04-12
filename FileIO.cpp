/*
 * FileReader.cpp
 *
 *  Created on: march 17th 2020
 *      Author: kboyle
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	//TODO fill in
	ifstream inputFile;
	inputFile.open(filename, ios::in);

	if (inputFile.is_open()) {
		string line;

		// Read line by line until end of file
		while (!inputFile.eof()) {
			getline(inputFile, line);
			contents += line;
		}
		// Close the file and return success
		inputFile.close();
		return SUCCESS;
	}

	return COULD_NOT_OPEN_FILE_TO_READ;
}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	ofstream outputFile;

	// Open the file
	outputFile.open(filename, ios::out);

	// Make sure file is open
	// Iterate through vector to write strings to file
	if(outputFile.is_open()) {
		for(std::vector<std::string>::iterator iter = myEntryVector.begin(); iter != myEntryVector.end(); iter++){
			// Write strings on individual lines. Use endl to pass '\n'.
			outputFile << *iter << endl;
		}

		// Check if write was successful
		if(outputFile.bad()) {
			return COULD_NOT_OPEN_FILE_TO_WRITE;
		}

		// Close the file and return SUCCESS
		outputFile.close();
		return SUCCESS;
	}

	// Otherwise return error
	return COULD_NOT_OPEN_FILE_TO_WRITE;
}



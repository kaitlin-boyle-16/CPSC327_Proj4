/*
 * StringParserClass.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */

#include <string>
#include <string.h>

#include "../327_proj3_test/includes/StringParserClass.h"
#include "../327_proj3_test/includes/constants.h"

// Initialization Method
KP_StringParserClass::StringParserClass::StringParserClass(void) {
	// Initialize variables with default values
	pStartTag = new char(0);
	pEndTag = new char(0);
	areTagsSet = false;
}

// Cleanup Method
KP_StringParserClass::StringParserClass::~StringParserClass(void) {
	cleanup();
}

// setTags Method
int KP_StringParserClass::StringParserClass::setTags(const char *pStart, const char *pEnd) {
	// Make sure pStart and pEnd are not empty, otherwise return error
	if(pStart == NULL || pEnd == NULL) {
		return ERROR_TAGS_NULL;
	}

	// Cleanup any old values
	cleanup();

	// Create copies of pStart and pEnd to pStartTag to pEndTag
	// Set areTags to true
	pStartTag = strdup(pStart);
	pEndTag = strdup(pEnd);
	areTagsSet = true;

	// Return success
	return SUCCESS;
}

//get data between the tags method
int KP_StringParserClass::StringParserClass::getDataBetweenTags(char *pDataToSearchThru, std::vector<std::string> &myVector) {
	//clear vector
	myVector.clear();

	//make sure pStart and pEnd and pDataToSearchthru are not null
	if(pStartTag == NULL || pEndTag == NULL) {
		return ERROR_TAGS_NULL;
	}
	if (pDataToSearchThru == NULL) {
		return ERROR_DATA_NULL;
	}
	//make pointers for values to put into findTag
	char* current = pDataToSearchThru;
	char* start= 0;
	char* end = 0;
	int tagLength = 0;

	while (findTag(current, start, end) == SUCCESS) {
		tagLength = strlen(pStartTag);
		current = strstr(current, pStartTag);

		current += tagLength * sizeof(char);
		end = strstr(current, pEndTag);

		std::string s = std::string(current, end - current);
		current = end + strlen(pEndTag);

		myVector.push_back(s);
		end = 0;
	}
	return SUCCESS;

}

//make sure tags are reset to initial values
void KP_StringParserClass::StringParserClass::cleanup() {
	if (pStartTag != 0) {
		delete pStartTag;
	}
	if (pEndTag != 0) {
		delete pEndTag;
	}
	areTagsSet = false;
}

//find the tag method
int KP_StringParserClass::StringParserClass::findTag(char *pTagToLookFor, char *&pStart, char *&pEnd) {
	if(pStartTag == NULL || pEndTag == NULL) {
		return ERROR_TAGS_NULL;
	}
	//set pStart and pEnd values
	pStart = strstr(pTagToLookFor, pStartTag);
	pEnd = strstr(pTagToLookFor, pEndTag);

	//values need to have something in them other than initial value
	if (pStart == 0 || pEnd == 0) {
		return FAIL;
	}

	return SUCCESS;

}

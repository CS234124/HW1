
#pragma once

#include <string>

using std::string;


/**
 * hash - Hashes a given string according to a given key
 *
 * @param key Hashing key
 * @param value1 First hashing value
 * @param value2 Second hashing value
 *
 * @return The hashed message
 *
*/
string hash(int key, const string& value1, const string& value2);


/**
 * getErrorMessage - Returns the error message for the program
*/
string getErrorMessage();

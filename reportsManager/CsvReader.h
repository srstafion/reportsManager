#pragma once
#include "Header.h"

class CsvReader {
public:
    vector<string> readFile(string path);
    int getLines(string path);
    vector<string> splitString(string input, char splitter);
    string getFileName(string path);
    string extractDate(string filename);
};
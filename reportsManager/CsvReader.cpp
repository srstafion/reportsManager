#include "CsvReader.h"

vector<string> CsvReader::readFile(string path) {
    vector<string> lines;
    ifstream file(path);
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}

int CsvReader::getLines(string path) {
    int count = 0;
    ifstream file(path);
    string line;
    while (getline(file, line)) {
        count++;
    }
    file.close();
    return count;
}

vector<string> CsvReader::splitString(string input, char splitter) {
    vector<string> strings;
    string line;
    for (auto i : input) {
        if (i == splitter) {
            strings.push_back(line);
            line.clear();
        }
        else {
            line.push_back(i);
        }
    }
    strings.push_back(line);
    return strings;
}

string CsvReader::getFileName(string path) {
    string filename;
    int index = 0;
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == '\\') {
            index = i + 1;
        }
    }
    for (int i = index; i < path.size(); i++) {
        filename += path[i];
    }
    return filename;
}

string CsvReader::extractDate(string filename) {
    int firstInstance = 0;
    int lastInstance = 0;
    string num;
    for (int i = 0; i < 2; i++) {
        for (int j = firstInstance; j < filename.size(); j++) {
            if (filename[j] == '_') {
                if (i == 0) {
                    firstInstance = j + 1;
                    break;
                }
                else if (i == 1) {
                    lastInstance = j;
                }
            }
        }
    }
    for (int i = firstInstance; i < lastInstance; i++) {
        num += filename[i];
    }
    return num;
}
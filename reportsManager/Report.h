#pragma once
#include "Header.h"

class Report {
protected:
    string path;

public:
    Report(string filePath);
    virtual void showAllInfo() = 0;
};
#pragma once
#include "Header.h"

class Transaction {
private:
    string item;
    float price;
    bool type;

public:
    Transaction(string item, float price, bool type);
    string getItem();
    float getPrice();
    bool getType();
};
#include "Transaction.h"

Transaction::Transaction(string item, float price, bool type) {
    this->item = item;
    this->price = price;
    this->type = type;
}

string Transaction::getItem() {
    return item;
}

float Transaction::getPrice() {
    return price;
}

bool Transaction::getType() {
    return type;
}
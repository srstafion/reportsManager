#include "MonthReport.h"

MonthReport::MonthReport(string filePath) : Report(filePath) {}

void MonthReport::showAllInfo() {
    cout << month << " Report:" << endl << endl;
    for (int i = 0; i < transactions.size(); i++) {
        cout << "Transaction " << i + 1 << ":" << endl;
        cout << "Item: " << transactions[i].getItem() << endl;
        cout << "Price: " << transactions[i].getPrice() << endl;
        cout << "Type: ";
        if (transactions[i].getType() == true) {
            cout << "Sales";
        }
        else cout << "Purchases";
        cout << endl << endl;
    }
    cout << "Total Sales: " << sales << endl;
    cout << "Total Purchases: " << purchases << endl << endl << endl;
}

void MonthReport::addTransaction(string item, float price, bool type) {
    transactions.push_back(Transaction(item, price, type));
    if (type == true) {
        sales += price;
    }
    else purchases += price;
}

void MonthReport::bulkAdd(vector<string> data, CsvReader reader, string path) {
    for (auto line : data) {
        vector<string> parts = reader.splitString(line, ';');
        string item = parts[0];
        float price = stof(parts[1]);
        bool type;
        if (parts[2] == "true") {
            type = true;
        }
        else {
            type = false;
        }
        addTransaction(item, price, type);
    }
    int m = stoi(reader.extractDate(reader.getFileName(path)));
    switch (m) {
    case 1:
        month = "January";
        break;
    case 2:
        month = "February";
        break;
    case 3:
        month = "March";
        break;
    case 4:
        month = "April";
        break;
    case 5:
        month = "May";
        break;
    case 6:
        month = "June";
        break;
    case 7:
        month = "July";
        break;
    case 8:
        month = "August";
        break;
    case 9:
        month = "September";
        break;
    case 10:
        month = "October";
        break;
    case 11:
        month = "November";
        break;
    case 12:
        month = "December";
        break;
    }
}

float MonthReport::getSales() {
    return sales;
}

float MonthReport::getPurchases() {
    return purchases;
}
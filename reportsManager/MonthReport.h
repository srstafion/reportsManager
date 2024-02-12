#pragma once
#include "Header.h"
#include "Report.h"
#include "Transaction.h"
#include "CsvReader.h"

class MonthReport : public Report {
private:
    vector<Transaction> transactions;
    float sales;
    float purchases;
    string month;

public:
    MonthReport(string filePath);
    void showAllInfo();
    void addTransaction(string item, float price, bool type);
    void bulkAdd(vector<string> data, CsvReader reader, string path);
    float getSales();
    float getPurchases();
};
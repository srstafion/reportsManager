#pragma once
#include "Header.h"
#include "Report.h"
#include "MonthReport.h"

class YearReport : public Report {
private:
    vector<MonthReport> monthReports;
    float totalSales;
    float totalPurchases;

public:
    YearReport();
    void addMonthReport(MonthReport monthReport);
    void showAllInfo();
};
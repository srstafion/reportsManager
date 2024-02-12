#include "YearReport.h"

YearReport::YearReport() : Report("") {}

void YearReport::addMonthReport(MonthReport monthReport) {
    monthReports.push_back(monthReport);
    totalSales += monthReport.getSales();
    totalPurchases += monthReport.getPurchases();
}

void YearReport::showAllInfo() {
    cout << "Yearly Report:" << endl;
    for (int i = 0; i < monthReports.size(); i++) {
        monthReports[i].showAllInfo();
    }
    cout << endl;
    cout << "Total Year Stats: " << endl;
    cout << "Total Sales: " << totalSales << endl;
    cout << "Total Purchases: " << totalPurchases << endl;
}
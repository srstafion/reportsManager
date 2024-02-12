#include "Header.h"
#include "CsvReader.h"
#include "MonthReport.h"
#include "YearReport.h"

int main() {
    CsvReader reader;
    MonthReport m1("m_1_2021.csv");
    MonthReport m2("m_2_2021.csv");
    MonthReport m3("m_3_2021.csv");
    YearReport y1;
    vector<string> data1 = reader.readFile("m_1_2021.csv");
    vector<string> data2 = reader.readFile("m_2_2021.csv");
    vector<string> data3 = reader.readFile("m_3_2021.csv");
    m1.bulkAdd(data1, reader, "m_1_2021.csv");
    m2.bulkAdd(data2, reader, "m_2_2021.csv");
    m3.bulkAdd(data3, reader, "m_3_2021.csv");
    y1.addMonthReport(m1);
    y1.addMonthReport(m2);
    y1.addMonthReport(m3);
    y1.showAllInfo();
    return 0;
}
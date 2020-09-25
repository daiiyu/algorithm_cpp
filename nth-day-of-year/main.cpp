#include <iostream>

using namespace std;
int nthDayOfYear(int year, int month, int day)
{
    int daysOfMonth[] {0,31,28,31,30,31,30,31,31,30,31,30, 31};
    if((year%100==0)||((year%4)==0))
        daysOfMonth[2] +=1;
    if(month > 12
    || day > daysOfMonth[month]
    || month <= 0
    || day <= 0
    || year <= 0)
        return -1;
    int totalDays = 0;
    for(int i=0; i< month;++i)
    {
        totalDays += daysOfMonth[i];
    }
    totalDays+=day;
    return totalDays;
}
int main() {

    cout<<"请输入日期，年 月 日， 以空格隔开，例如：2019 8 5\n" << endl;
    int year = -1;
    int month = -1;
    int  day = -1;

    cin >> year >> month >>day;
    //test input
    cout<<"testing intput: days="<<nthDayOfYear(year,month,day)<<endl;
    //正常功能测试

    std::cout << nthDayOfYear(2020,1,1) << std::endl;
    std::cout << nthDayOfYear(2020,1,2) << std::endl;
    std::cout << nthDayOfYear(2020,1,3) << std::endl;
    std::cout << nthDayOfYear(2020,1,4) << std::endl;
    //闰年测试
    std::cout << nthDayOfYear(2020,2,29) << std::endl;
    std::cout << nthDayOfYear(2019,3,1) << std::endl;
    //边界值测试
    std::cout << nthDayOfYear(2020,13,31) << std::endl;
    std::cout << nthDayOfYear(2020,12,32) << std::endl;
    std::cout << nthDayOfYear(2020,2,30) << std::endl;
    std::cout << nthDayOfYear(2020,0,31) << std::endl;

    //负数测试
    std::cout << nthDayOfYear(2020,-12,31) << std::endl;
    return 0;
}

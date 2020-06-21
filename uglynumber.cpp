//
// Created by daiyu on 2020/6/3.
//


#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool isUgly(int num) {
    while (num % 2 == 0)
        num /= 2;
    while (num % 3 == 0)
        num /= 3;
    while (num % 5 == 0)
        num /= 5;
    return (num == 1) ? true : false;
}

int uglyNumber() {
    int count = 0;
    int num = 2;
    while (count < 100) {
        if (isUgly(num)) {
            cout << num << "\t";
            ++count;
        }
        ++num;
    }
    cout << endl;
    return num - 1;
}

int uglyNumber2() {
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    int index = 1;  //point to 3;

}

int main() {
    uglyNumber();
}
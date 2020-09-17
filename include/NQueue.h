//
// Created by daiyuz on 7/7/20.
//

#ifndef DATASTRUCTURE_NQUEUE_H
#define DATASTRUCTURE_NQUEUE_H
#include <vector>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
class SolutionNQueue {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        init(n);
        backtrace(0);
        return res;
    }
private:
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> board;
    int size;
    int counter;
    void backtrace(int row)
    {
        //找到的一个结果，就打印
        if(row >= size ){
            ++counter;
            res.push_back(board);
            cout<<"find a solution:"<<counter<<endl;
            printBoard(board);
            return;
        }

        for(int i=0; i< size; ++i){
            if(check(row,i)){
                //保存棋盘
                auto tmp = board[row][i];
                board[row][i] = 'Q';
                backtrace(row+1);
                //恢复棋盘
                board[row][i]  = tmp;
            }
        }
    }
    void init(int n)
    {
        board.resize(n, std::string(n,'+'));
        this->size = n;
        counter = 0;
    }

    bool check(int row, int col)
    {
        //因为是一行一行的放，所以， 左下方， 右下方，下方 是不用检测的。
        //只需要检测， 左上， 右上，还有列

        //检查列
        for(int i=0; i < row; ++i){
            if(board[i][col] == 'Q')
                return false;
        }
        //检查主对角， 左上
        for(int i=row-1, j=col-1;i >=0&& j>=0; --i,--j){
            if(board[i][j] == 'Q')
                return false;
        }
        //右上
        for(int i= row-1, j=col+1; i>=0&& j<size; --i, ++j){
            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void printBoard(const std::vector<std::string>& b)
    {
        for(auto& str: b){
            cout<<str<<endl;
        }
        cout<<endl;
    }
};

class SolutionNQueueBetter
{
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        init(n);
        backtrace(0);
        return res;
    }
private:
    std::vector<bool> colColl; //column collision
    std::vector<bool> mainColl; //
    std::vector<bool> secondaryColl;
    int n;
    void init(int size)
    {
        n = size;
        colColl.resize(n, false);
        mainColl.resize(n + n -1, false); //规律是： 行数 + 列数 - 1
        secondaryColl.resize(n+n -1, false);
    }

    void backtrace(int row)
    {

    }
    int check(int row, int col)
    {
        if(colColl[col] || mainColl[row - col + n -1] ||secondaryColl[row + col] )
            return false;

        return true;
    }
    int addQueue(int row, int col)
    {

    }
    int removeQueue(int row, int col)
    {

    }

private:
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> board;

};
#endif //DATASTRUCTURE_NQUEUE_H

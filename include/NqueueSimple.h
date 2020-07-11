//
// Created by daiyuz on 7/11/20.
//

#ifndef ALGORITHM_CPP_NQUEUESIMPLE_H
#define ALGORITHM_CPP_NQUEUESIMPLE_H
#include "base.hpp"
using namespace std;

class NQueenBase
{
public:
    vector<vector<string>> solutionToNQueenSimple(int m, int n)
    {
        init(m, n);
        backtrace(0);
        return result;
    }
protected:
    virtual bool check(int x, int y) = 0;
    // n : current line number
    void backtrace(int n){
        if(n==rows)
        {
            ++counter;
            printBoard();
            return;
        }

        for(int i=0; i<cols; ++i)
        {

            if(check(n,i)){
                auto tmp = board[n][i]; //backup
                board[n][i] = QUEEN;
                backtrace(n+1);
                board[n][i] = tmp; // restore
            }
        }
    }
    void init(int m, int n)
    {
        //初始化为 m x n 的矩阵。
        board.resize(m, string(n,  '+'));
        rows = m;
        cols = n;
    }


    void printBoard()
    {
        for(auto &str: board){
            cout<<str<<endl;
        }
        cout<<counter<<endl;

    }

protected:
    vector<string> board;
    vector<vector<string>> result;
    int rows;
    int cols;
    int counter = 0;
    const char QUEEN='Q';
};

class NQueenSimple: public NQueenBase
{
public:
    bool check(int x, int y) override
    {
        //横向不用检测
        // 只需要检查列向的，上部分
        for(int i=0; i<x;++i){
            if(board[i][y] == QUEEN) //列不变，行改变。 检查第y列。
                return false;
        }
        return true;
    }
};

    //我只要重写check函数，就可以实现真正意义的八皇后。
class NQueenComplex: public NQueenBase
{

};
#endif //ALGORITHM_CPP_NQUEUESIMPLE_H

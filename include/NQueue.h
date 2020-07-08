//
// Created by daiyuz on 7/7/20.
//

#ifndef DATASTRUCTURE_NQUEUE_H
#define DATASTRUCTURE_NQUEUE_H
#include <vector>
;

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
        board.resize(n, string(n,'+'));
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
#endif //DATASTRUCTURE_NQUEUE_H

#include<iostream>
class Sudoku
{
 public:
   void GiveQuestion();//出題
   int correct(int result);//檢查有沒有符合規則
   void ReadIn();//讀題
   void Solve();//解題
   void Backtracking(int num,int x[],int t[],int m[],int n[],int count,int possible[][9]);//暴力解題
 private:
   int sudoku[12][12];//存題目
   int position[12][12];//存空格位置
   int tem[12][12];//不重要
   int multi[1];//用來看是多重解還是唯一解
};

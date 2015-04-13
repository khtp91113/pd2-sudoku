#include<iostream>
class Sudoku
{
 public:
   void GiveQuestion();
   int correct(int result);
   void ReadIn();
   int Multiple(int total[],int count,int m[],int n[]);
   void Solve();
   void Backtracking(int num,int x[],int t[],int m[],int n[],int count,int possible[][9]);
 private:
   int sudoku[12][12];
   int position[12][12];
   int tem[12][12];
   int multi;
};

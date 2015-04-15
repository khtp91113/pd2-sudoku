#include"Sudoku.h"
#include<cstdlib>
#include<ctime>
using namespace std;

void Sudoku::GiveQuestion()
{
 int select,origin[12][12],i,j;
 srand(time(NULL));
 select=rand()%3;//從三個模組中隨機挑一個
 int origin_1[12][12]={{-1,-1,-1, 0, 0, 8, 0, 0, 0, 0, 0, 0},
                       {-1,-1,-1, 0, 0, 4, 0, 9, 0, 0, 0, 1},
                       {-1,-1,-1, 0, 0, 0, 1, 0, 8, 0, 0, 0},
                       { 0, 6, 0, 2, 0, 0,-1,-1,-1, 9, 0, 7},
                       { 0, 0, 0, 0, 3, 0,-1,-1,-1, 0, 0, 0},
                       { 0, 3, 0, 0, 0, 7,-1,-1,-1, 5, 2, 0},
                       { 0, 0, 6,-1,-1,-1, 0, 7, 0, 0, 4, 0},
                       { 0, 9, 0,-1,-1,-1, 0, 0, 0, 2, 0, 8},
                       { 0, 0, 4,-1,-1,-1, 0, 0, 9, 0, 1, 0},
                       { 0, 0, 0, 0, 0, 2, 0, 5, 0,-1,-1,-1},
                       { 0, 8, 1, 3, 0, 9, 0, 4, 2,-1,-1,-1},
                       { 0, 5, 0, 7, 1, 0, 0, 0, 0,-1,-1,-1}};
 int origin_2[12][12]={{ 0, 0, 0, 0, 0, 0,-1,-1,-1, 0, 0, 0},
                       { 0, 0, 0, 0, 1, 0,-1,-1,-1, 2, 3, 5},
                       { 0, 0, 0, 0, 3, 0,-1,-1,-1, 1, 4, 0},
                       {-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 5, 0},
                       {-1,-1,-1, 0, 0, 6, 0, 0, 8, 0, 7, 0},
                       {-1,-1,-1, 0, 0, 0, 0, 9, 0, 0, 0, 0},
                       { 0, 0, 7,-1,-1,-1, 0, 0, 0, 0, 0, 0},
                       { 0, 0, 6,-1,-1,-1, 4, 0, 1, 9, 0, 7},
                       { 0, 0, 0,-1,-1,-1, 0, 2, 0, 3, 1, 0},
                       { 0, 3, 0, 0, 2, 0, 0, 1, 0,-1,-1,-1},
                       { 9, 7, 0, 4, 0, 0, 5, 0, 0,-1,-1,-1},
                       { 4, 0, 0, 0, 5, 3, 0, 0, 0,-1,-1,-1}};
 int origin_3[12][12]={{-1,-1,-1, 0, 0, 0, 0, 4, 0, 5, 9, 8},
                       {-1,-1,-1, 0, 7, 4, 2, 0, 9, 6, 0, 3},
                       {-1,-1,-1, 0, 0, 0, 0, 3, 0, 0, 4, 0},
                       { 0, 3, 0,-1,-1,-1, 0, 0, 4, 9, 0, 0},
                       { 5, 0, 0,-1,-1,-1, 0, 0, 0, 0, 0, 6},
                       { 0, 0, 0,-1,-1,-1, 0, 0, 0, 0, 0, 0},
                       { 9, 2, 0, 0, 0, 0,-1,-1,-1, 0, 0, 0},
                       { 0, 0, 0, 0, 0, 0,-1,-1,-1, 0, 7, 9},
                       { 0, 4, 0, 1, 0, 0,-1,-1,-1, 0, 5, 0},
                       { 0, 7, 0, 0, 3, 0, 0, 0, 0,-1,-1,-1},
                       { 8, 0, 0, 0, 0, 2, 5, 6, 0,-1,-1,-1},
                       { 0, 1, 2, 0, 4, 0, 0, 7, 0,-1,-1,-1}};
 switch(select)
 {
  case 0:for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           origin[i][j]=origin_1[i][j];
          break;
  case 1:for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           origin[i][j]=origin_2[i][j];
          break;
  default:for(i=0;i<12;i++)
           for(j=0;j<12;j++)
            origin[i][j]=origin_3[i][j];
           break;
 }
 int change_num,rotate;
 int n[9],check[9]={0};
 for(i=0;i<9;i++)
 {
  n[i]=rand()%9+1;
  while(check[n[i]-1]>0)
   n[i]=rand()%9+1;
  check[n[i]-1]++;
 }
 for(i=0;i<12;i++)
  for(j=0;j<12;j++)
  {
   if(origin[i][j]==-1||origin[i][j]==0);
   else
    origin[i][j]=n[origin[i][j]-1];
  }
 int temp[12][12];
 srand(time(NULL));
 rotate=rand()%5;//旋轉 有可能是行列互換 或上下左右顛倒
 switch(rotate)
 {
  case 0:for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           temp[i][j]=origin[i][j];
         for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           origin[j][i]=temp[i][j];
         break;
  case 1:for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           temp[i][j]=origin[i][j];
         for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           origin[11-j][11-i]=temp[i][j];
         break;
  case 2:for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           temp[i][j]=origin[i][j];
         for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           origin[11-i][j]=temp[i][j];
         break;
  case 3:for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           temp[i][j]=origin[i][j];
         for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           origin[i][11-j]=temp[i][j];
         break;
  default:break;
 }
 //stdoutput
 for(i=0;i<12;i++)
 {
  for(j=0;j<12;j++)
  {
   if(origin[i][j]==-1)
    cout<<origin[i][j]<<" ";
   else
    cout<<" "<<origin[i][j]<<" ";
  }
  cout<<endl;
 } 
}

void Sudoku::ReadIn()
{
 int i,j;//stdinput
 for(i=0;i<12;i++)
  for(j=0;j<12;j++)
   cin>>sudoku[i][j];
}

int Sudoku::correct(int result)
{
 int i,j,k,check[9]={0};//檢查每一行或列和九宮格中除了0和-1外 有沒有重複的數字
 for(i=0;i<12;i++)//列
 {
  for(j=0;j<12;j++)
  {
   if(sudoku[i][j]==-1||sudoku[i][j]==0);
   else
   {
    if(check[sudoku[i][j]-1]==1)
     result=0;
    else;
    check[sudoku[i][j]-1]++;
   }
  }
  for(j=0;j<9;j++)
   check[j]=0;
 }//行
 for(i=0;i<12;i++)
 {
  for(j=0;j<12;j++)
  {
   if(sudoku[j][i]==-1||sudoku[j][i]==0);
   else
   {
    if(check[sudoku[j][i]-1]==1)
     result=0;
    else;
    check[sudoku[j][i]-1]++;
   }
  }
  for(j=0;j<9;j++)
   check[j]=0;
 }
 int temp1,temp2;//九宮格
 for(i=0;i<4;i++)
  for(j=0;j<4;j++)
  {
   temp1=3*i;
   temp2=3*j;
   for(k=0;k<9;k++)
   {
    if(sudoku[temp1][temp2]!=-1&&sudoku[temp1][temp2]!=0)
    {
     if(check[sudoku[temp1][temp2]-1]>=1)
      result=0;
     else;
     check[sudoku[temp1][temp2]-1]++;
    }
    else;
    temp2++;
    if(temp2%3==0)
    {
     temp1+=1;
     temp2=3*j;
    }
    else;
   }
   for(k=0;k<9;k++)
    check[k]=0;
  }
  return result;
}

void Sudoku::Backtracking(int num,int x[],int t[],int m[],int n[],int count,int possible[][9])
{
 int no=0,i,j;//看還有沒有空格沒填
 for(i=0;i<12;i++)
  for(j=0;j<12;j++)
   if(sudoku[i][j]==0)
    no=1;
 if(no==0&&multi[0]==1)//如果沒有空格且已出現過一次解答 那代表多重解 output 2 並結束程式
 {
  cout<<2<<endl;
  exit(0);
 }

 if(no==0)//沒有空格 第一次出現解答 改multi的值 並將解答暫存到tem中
 {
  multi[0]=1;
  for(i=0;i<12;i++)
   for(j=0;j<12;j++)
    tem[i][j]=sudoku[i][j];
  return;
 }


 for(;t[num]<x[num];t[num]++)//recursion 如果填進去的數字符合規則 就在填下一格 不對就return回上一層
 {
  sudoku[m[num]][n[num]]=possible[num][t[num]];
  if(correct(-1)==-1)
   Backtracking(num+1,x,t,m,n,count,possible);
  sudoku[m[num]][n[num]]=0;
  for(i=num+1;i<count;i++)
   t[i]=0;
 }
}

void Sudoku::Solve()
{
 int result=-1,i,j,k,total=0,pass=0,check[9]={0};
 for(i=0;i<12;i++)//檢查-1的位置有沒有正確
  for(j=0;j<12;j++)
  {
   if(sudoku[i][j]==-1)
   {
    total++;
    if(pass==0)
     if(sudoku[i][j+1]!=-1||sudoku[i][j+2]!=-1||sudoku[i+1][j]!=-1||sudoku[i+1][j+1]!=-1||sudoku[i+1][j+2]!=-1||sudoku[i+2][j]!=-1||sudoku[i+2][j+1]!=-1||sudoku[i+2][j+2]!=-1)
      result=0;
     else;
    else;
    pass=1;
    if(total%9==0)
     pass=0;
    else;
   }
  }
 if(total!=36)//檢查-1的數量有沒有正確
  result=0;
 else;
 result=correct(result);//看數字有沒有符合規則
 if(result==0)//不正確 output 0 結束程式
 {
  cout<<result<<endl;
  return;
 }
 int count=0;//記錄所有空格的位置 和空格數量
 for(i=0;i<12;i++)
  for(j=0;j<12;j++)
   position[i][j]=0;
 for(i=0;i<12;i++)
  for(j=0;j<12;j++)
   if(sudoku[i][j]==0)
   {
    count++;
    position[i][j]++;
   }
 int b=0,c=0,only=0,control=1;
 while(control==1)//將只有一種可能的空格先填好
 {
  control=0;
  for(i=0;i<12;i++)
   for(j=0;j<12;j++)
   {
    if(position[i][j]==1)//在空格上
    {
     //橫只有一個可能
     for(b=i,c=0;c<12;c++)
      if(sudoku[b][c]==0)
       only++;
     if(only==1)
     {
      for(b=i,c=0;c<12;c++)
       if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
        check[sudoku[b][c]-1]++;
      for(k=0;k<9;k++)
       if(check[k]==0)
        break;
      sudoku[i][j]=k+1;
      position[i][j]=0;
      control=1;
      continue;
     }
     //直只有一個可能 
     only=0;
     for(k=0;k<9;k++)
      check[k]=0;
     for(b=0,c=j;b<12;b++)
      if(sudoku[b][c]==0)
       only++;
     if(only==1)
     {
      for(b=0,c=j;b<12;b++)
       if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
        check[sudoku[b][c]-1]++;
      for(k=0;k<9;k++)
       if(check[k]==0)
        break;
      sudoku[i][j]=k+1;
      position[i][j]=0;
      control=1;
      continue;
     }
     //九宮格只有一個可能
     only=0;
     for(k=0;k<9;k++)
      check[k]=0;
     switch((i%3)*10+j%3)
     {
      case 0:for(b=i;b<i+3;b++)
              for(c=j;c<j+3;c++)
               if(sudoku[b][c]==0)
                only++;
             if(only==1)
             {
              for(b=i;b<i+3;b++)
               for(c=j;c<j+3;c++)
                if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
                 check[sudoku[b][c]-1]++;
              for(k=0;k<9;k++)
               if(check[k]==0)
                break;
              sudoku[i][j]=k+1;
              position[i][j]=0;
              control=1;
             }
             break;
      case 1:for(b=i;b<i+3;b++)
              for(c=j-1;c<j+2;c++)
               if(sudoku[b][c]==0)
                only++;
             if(only==1)
             {
              for(b=i;b<i+3;b++)
               for(c=j-1;c<j+2;c++)
                if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
                 check[sudoku[b][c]-1]++;
              for(k=0;k<9;k++)
               if(check[k]==0)
                break;
              sudoku[i][j]=k+1;
              position[i][j]=0;
              control=1;
             }
             break;
      case 2:for(b=i;b<i+3;b++)
              for(c=j-2;c<j+1;c++)
               if(sudoku[b][c]==0)
                only++;
             if(only==1)
             {
              for(b=i;b<i+3;b++)
               for(c=j-2;c<j+1;c++)
                if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
                 check[sudoku[b][c]-1]++;
              for(k=0;k<9;k++)
               if(check[k]==0)
                break;
              sudoku[i][j]=k+1;
              position[i][j]=0;
              control=1;
             }
             break;
      case 10:for(b=i-1;b<i+2;b++)
               for(c=j;c<j+3;c++)
                if(sudoku[b][c]==0)
                 only++;
              if(only==1)
              {
               for(b=i-1;b<i+2;b++)
                for(c=j;c<j+3;c++)
                 if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
                  check[sudoku[b][c]-1]++;
               for(k=0;k<9;k++)
                if(check[k]==0)
                 break;
               sudoku[i][j]=k+1;
               position[i][j]=0;
               control=1;
              }
              break;
      case 11:for(b=i-1;b<i+2;b++)
               for(c=j-1;c<j+2;c++)
                if(sudoku[b][c]==0)
                 only++;
              if(only==1)
              {
               for(b=i-1;b<i+2;b++)
                for(c=j-1;c<j+2;c++)
                 if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
                  check[sudoku[b][c]-1]++;
               for(k=0;k<9;k++)
                if(check[k]==0)
                 break;
               sudoku[i][j]=k+1;
               position[i][j]=0;
               control=1;
              }
              break;
      case 12:for(b=i-1;b<i+2;b++)
               for(c=j-2;c<j+1;c++)
                if(sudoku[b][c]==0)
                 only++;
              if(only==1)
              {
               for(b=i-1;b<i+2;b++)
                for(c=j-2;c<j+1;c++)
                 if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
                  check[sudoku[b][c]-1]++;
               for(k=0;k<9;k++)
                if(check[k]==0)
                 break;
               sudoku[i][j]=k+1;
               position[i][j]=0;
               control=1;
              }
              break;
      case 20:for(b=i-2;b<i+1;b++)
               for(c=j;c<j+3;c++)
                if(sudoku[b][c]==0)
                 only++;
              if(only==1)
              {
               for(b=i-2;b<i+1;b++)
                for(c=j;c<j+3;c++)
                 if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
                  check[sudoku[b][c]-1]++;
               for(k=0;k<9;k++)
                if(check[k]==0)
                 break;
               sudoku[i][j]=k+1;
               position[i][j]=0;
               control=1;
              }
              break;
      case 21:for(b=i-2;b<i+1;b++)
               for(c=j-1;c<j+2;c++)
                if(sudoku[b][c]==0)
                 only++;
              if(only==1)
              {
               for(b=i-2;b<i+1;b++)
                for(c=j-1;c<j+2;c++)
                 if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
                  check[sudoku[b][c]-1]++;
               for(k=0;k<9;k++)
                if(check[k]==0)
                 break;
               sudoku[i][j]=k+1;
               position[i][j]=0;
               control=1;
              }
              break;
      default:for(b=i-2;b<i+1;b++)
               for(c=j-2;c<j+1;c++)
                 if(sudoku[b][c]==0)
                 only++;
              if(only==1)
              {
               for(b=i-2;b<i+1;b++)
                for(c=j-2;c<j+1;c++)
                 if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
                  check[sudoku[b][c]-1]++;
               for(k=0;k<9;k++)
                if(check[k]==0)
                 break;
               sudoku[i][j]=k+1;
               position[i][j]=0;
               control=1;
               }
              break;
     } 
     only=0;
     for(k=0;k<9;k++)
      check[k]=0;
    }
    else;
   }
 }
 only=0;
 for(k=0;k<9;k++)
  check[k]=0;

 //檢查還有沒有空格
 int clear=1;
 for(i=0;i<12;i++)
  for(j=0;j<12;j++)
   if(sudoku[i][j]==0)
    clear=0;
 if(clear==1)//沒有空格的情況下
 {
  result=correct(result);
  if(result==-1)
  {
   cout<<"1"<<endl;//全部剛好能一次解決的沒有不確定答案加上沒有不符合規定
   for(i=0;i<12;i++)
   {
    for(j=0;j<12;j++)
    {
     if(sudoku[i][j]==-1)
      cout<<sudoku[i][j]<<" ";
     else
      cout<<" "<<sudoku[i][j]<<" ";
    }
    cout<<endl;
   } 
   return;
  }
  else
  {
   cout<<"0"<<endl;//全部剛好能一次解決但不符合規定
   return;
  }
 }

 int possible[count][9],count1=0,count2=0,note=0,jump=0;
 for(k=0;k<9;k++)
  check[k]=0;
 for(i=0;i<count;i++)
  for(j=0;j<9;j++)
   possible[i][j]=0;
 control=1;
 while(control==1)//重新存還剩多少空格 和空格的位置
 {
  control=0;
  count=0;
  for(i=0;i<12;i++)
   for(j=0;j<12;j++)
    if(sudoku[i][j]==0)
     count++;
  for(i=0;i<12;i++)
  {
   for(j=0;j<12;j++)
    if(position[i][j]==1)//在空格中 去找這個空格所有可以填的數字 藉由比較行 列 九宮格 三種情況下 皆符合規定的數字就是有可能的數字 存到possible中
    {
     note=0;
     for(k=0;k<9;k++)
      check[k]=0;
     for(b=i,c=0;c<12;c++)
      if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
       check[sudoku[b][c]-1]++;
     for(b=0,c=j;b<12;b++)
      if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
       check[sudoku[b][c]-1]++;
     switch(i%3*10+j%3)
     {
      case 0:for(b=i;b<i+3;b++)
              for(c=j;c<j+3;c++)
               if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
                check[sudoku[b][c]-1]++;
             break;
      case 1:for(b=i;b<i+3;b++)
              for(c=j-1;c<j+2;c++)
               if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
                check[sudoku[b][c]-1]++;
             break;
      case 2:for(b=i;b<i+3;b++)
              for(c=j-2;c<j+1;c++)
               if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
                check[sudoku[b][c]-1]++;
             break;
      case 10:for(b=i-1;b<i+2;b++)
               for(c=j;c<j+3;c++)
                if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
                 check[sudoku[b][c]-1]++;
              break;
      case 11:for(b=i-1;b<i+2;b++)
               for(c=j-1;c<j+2;c++)
                if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
                 check[sudoku[b][c]-1]++;
              break;
      case 12:for(b=i-1;b<i+2;b++)
               for(c=j-2;c<j+1;c++)
                if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
                 check[sudoku[b][c]-1]++;
              break;
      case 20:for(b=i-2;b<i+1;b++)
               for(c=j;c<j+3;c++)
                if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
                 check[sudoku[b][c]-1]++;
              break;
      case 21:for(b=i-2;b<i+1;b++)
               for(c=j-1;c<j+2;c++)
                if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
                 check[sudoku[b][c]-1]++;
              break;
      default:for(b=i-2;b<i+1;b++)
               for(c=j-2;c<j+1;c++)
                if(sudoku[b][c]!=-1&&sudoku[b][c]!=0)
                 check[sudoku[b][c]-1]++;
              break;
     }
     for(k=0;k<9;k++)
      if(check[k]==0)
       note++;
     if(note==1)
     {
      for(k=0;k<9;k++)
       if(check[k]==0)
        break;
      sudoku[i][j]=k+1;
      position[i][j]=0;
      control=1;
      for(b=0;b<count;b++)
       for(c=0;c<9;c++)
        possible[b][c]=0;
      count1=0;
      jump=1;
      break;
     }
     else
     {
      for(k=0;k<9;k++)
       if(check[k]==0)
        {
         possible[count1][count2]=k+1;
         count2++;
        }
      count1++;
      count2=0;
     }
    }
   if(jump==1)
   {
    jump=0;
    break;
   } 
  }
 }
 int impossible=0;//如果有一個空格完全沒有可能的答案 那就代表無解 結束程式
 for(i=0;i<count;i++)
 {
  for(j=0;j<9;j++)
   if(possible[i][j]==0)
    impossible++;
  if(impossible==9)
  {
   cout<<0<<endl;
   return;
  }
  impossible=0;
 }

 k=0;
 int m[count1],n[count1];//m和n 分別存空格的列和行的值
 for(i=0;i<12;i++)
  for(j=0;j<12;j++)
  {

   if(position[i][j]==1)
   {
    m[k]=i;
    n[k]=j;
    k++;
   }
  }
 int x[count],t[count];
 for(i=0;i<count;i++)//t陣列 ex:t[0] 表示第一個空格此時在他的可能數字的第幾個 比如說 如果第一格有3個可能性 那t[0]=1時 就是說把第一個空格填所有可能中的第二個可能的數字
  t[i]=0;
 for(i=0;i<count;i++)//x陣列存每個空格中的可能數字有幾個 當作範圍使用
  x[i]=0;
 for(i=0;i<count;i++)
  for(j=0;j<9&&possible[i][j]!=0;j++)
   x[i]++;
 multi[0]=0;
 Backtracking(0,x,t,m,n,count,possible);
 if(multi[0]==1)//multi為一 代表唯一解 output tem
 {
  cout<<1<<endl;
  for(i=0;i<12;i++)
  {
   for(j=0;j<12;j++)
   {
    if(tem[i][j]==-1)
     cout<<tem[i][j]<<" ";
    else
     cout<<" "<<tem[i][j]<<" ";
   }
   cout<<endl;
  }
  return;
 }

 if(multi[0]==0)//multi為零 代表無解 結束程式
 {
  cout<<0<<endl;
  for(i=0;i<12;i++)
  {
   for(j=0;j<12;j++)
   {
    if(sudoku[i][j]==-1)
     cout<<sudoku[i][j]<<" ";
    else
     cout<<" "<<sudoku[i][j]<<" ";
   }
   cout<<endl;
  }
  return;
 } 
 return;
}

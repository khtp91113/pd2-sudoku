#include"Sudoku.h"
#include<cstdlib>
using namespace std;

void Sudoku::GiveQuestion()
{
 int select,origin[12][12],i,j;
 srand(time(NULL));
 select=rand()%3;
 int origin_1[12][12]={{-1,-1,-1, 1, 9, 8, 5, 2, 4, 7, 6, 3},
                       {-1,-1,-1, 6, 2, 4, 3, 9, 7, 8, 5, 1},
                       {-1,-1,-1, 5, 7, 3, 1, 6, 8, 4, 9, 2},
                       { 5, 6, 8, 2, 4, 1,-1,-1,-1, 9, 3, 7},
                       { 2, 4, 7, 9, 3, 5,-1,-1,-1, 1, 8, 6},
                       { 1, 3, 9, 8, 6, 7,-1,-1,-1, 5, 2, 4},
                       { 8, 1, 6,-1,-1,-1, 2, 7, 5, 3, 4, 9},
                       { 3, 9, 5,-1,-1,-1, 4, 1, 6, 2, 7, 8},
                       { 7, 2, 4,-1,-1,-1, 8, 3, 9, 6, 1, 5},
                       { 9, 7, 3, 4, 8, 2, 6, 5, 1,-1,-1,-1},
                       { 6, 8, 1, 3, 5, 9, 7, 4, 2,-1,-1,-1},
                       { 4, 5, 2, 7, 1, 6, 9, 8, 3,-1,-1,-1}};
 int origin_2[12][12]={{ 5, 1, 3, 2, 6, 4,-1,-1,-1, 7, 9, 8},
                       { 7, 6, 4, 8, 1, 9,-1,-1,-1, 2, 3, 5},
                       { 2, 9, 8, 7, 3, 5,-1,-1,-1, 1, 4, 6},
                       {-1,-1,-1, 3, 7, 2, 1, 4, 6, 8, 5, 9},
                       {-1,-1,-1, 5, 9, 6, 2, 3, 8, 4, 7, 1},
                       {-1,-1,-1, 1, 4, 8, 7, 9, 5, 6, 2, 3},
                       { 1, 4, 7,-1,-1,-1, 3, 8, 9, 5, 6, 2},
                       { 3, 2, 6,-1,-1,-1, 4, 5, 1, 9, 8, 7},
                       { 8, 5, 9,-1,-1,-1, 6, 2, 7, 3, 1, 4},
                       { 6, 3, 5, 9, 2, 7, 8, 1, 4,-1,-1,-1},
                       { 9, 7, 2, 4, 8, 1, 5, 6, 3,-1,-1,-1},
                       { 4, 8, 1, 6, 5, 3, 9, 7, 2,-1,-1,-1}};
 int origin_3[12][12]={{-1,-1,-1, 2, 6, 3, 1, 4, 7, 5, 9, 8},
                       {-1,-1,-1, 8, 7, 4, 2, 5, 9, 6, 1, 3},
                       {-1,-1,-1, 5, 9, 1, 8, 3, 6, 2, 4, 7},
                       { 2, 3, 7,-1,-1,-1, 6, 1, 4, 9, 8, 5},
                       { 5, 8, 1,-1,-1,-1, 7, 9, 2, 4, 3, 6},
                       { 4, 6, 9,-1,-1,-1, 3, 8, 5, 7, 2, 1},
                       { 9, 2, 8, 3, 5, 7,-1,-1,-1, 1, 6, 4},
                       { 1, 5, 3, 4, 2, 6,-1,-1,-1, 8, 7, 9},
                       { 7, 4, 6, 1, 8, 9,-1,-1,-1, 3, 5, 2},
                       { 6, 7, 5, 9, 3, 8, 4, 2, 1,-1,-1,-1},
                       { 8, 9, 4, 7, 1, 2, 5, 6, 3,-1,-1,-1},
                       { 3, 1, 2, 6, 4, 5, 9, 7, 8,-1,-1,-1}};
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
 rotate=rand()%5;
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
 int i,j;
 for(i=0;i<12;i++)
  for(j=0;j<12;j++)
   cin>>sudoku[i][j];
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
}
int Sudoku::correct(int result)
{
 int i,j,k,check[9]={0};
 for(i=0;i<12;i++)
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
 }
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
 int temp1,temp2;
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

int Sudoku::Multiple(int possible[][9],int count,int m[],int n[],int result)
{
 int x[count],time=0;
 unsigned long long int temp=1,i,j,k,y=1;
 for(i=0;i<count;i++)
  x[i]=0;
 for(i=0;i<count;i++)
  for(j=0;j<9&&possible[i][j]!=0;j++)
   x[i]++;
 for(i=0;i<count;i++)//////////////y被玩報了...
  y*=x[i];
 int total[count],echelon[count];
 for(i=0;i<count-1;i++)///////////echelon也被玩爆了...
 {
  for(j=count-1;j>i;j--)
   temp*=x[j];
  echelon[i]=temp;
  temp=1;
 }
 echelon[count-1]=x[count-1];
 int temp1,temp2;
 for(i=0;i<y;i++)
 {
  temp=i;
  for(j=0;j<count-1;j++)
  {
   total[j]=temp/echelon[j];
   temp-=total[j]*echelon[j];
  }
  total[count-1]=temp;
  for(j=0;j<count;j++)
   sudoku[m[j]][n[j]]=possible[j][total[j]];
  temp2=correct(result);
  if(temp2==-1&&time==1)
   return 2;
  if(temp2==-1)
  {
   time=1;
   temp1=y;
  }
 }
 if(time==1)
 {
  temp=temp1;
  for(j=0;j<count-1;j++)
  {
   total[j]=temp/echelon[j];
   temp-=total[j]*echelon[j];
  }
  total[count-1]=temp;
  for(j=0;j<count;j++)
   sudoku[m[j]][n[j]]=possible[j][total[j]];
  return 1;
 }
 if(time==0)
  return 0;
}

void Sudoku::Solve()
{
 int result=-1,i,j,k,total=0,pass=0,check[9]={0};
 for(i=0;i<12;i++)
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
 if(total!=36)
  result=0;
 else;
 result=correct(result);
 int count=0;
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
 while(control==1)
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
 if(clear==1)
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








 
 
 //多空格 暴力解
 int possible[count][9],count1=0,count2=0,note=0,jump=0;
 for(k=0;k<9;k++)
  check[k]=0;
 for(i=0;i<count;i++)
  for(j=0;j<9;j++)
   possible[i][j]=0;
 control=1;
 while(control==1)
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
    if(position[i][j]==1)
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
 //檢查還有沒有空格
 clear=1;
 for(i=0;i<12;i++)
  for(j=0;j<12;j++)
   if(sudoku[i][j]==0)
    clear=0;
 if(clear==1)
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
 k=0;
 int m[count1],n[count1];
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





 result=Multiple(possible,count1,m,n,result);
     

 if(result==2)
 {
  cout<<result<<endl;
  return;
 }


 if(result==1)
 {
  cout<<result<<endl;
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
 } 

 
 if(result==0)
 {
  cout<<result<<endl;
  return;
 } 
}

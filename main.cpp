#include<iostream>
#include<stdio.h>
using namespace std;
bool Issafe(int **arr,int i,int j,int value)
{
    for(int x=0;x<9;x++) //Checking Row If value Is Present Or Not
        if(arr[i][x]==value)// If It Present Already return false 
            return false;
    for(int y=0;y<9;y++)
        if(arr[y][j]==value)
            return false;
    int a=i/3;
    int b=j/3;
    a*=3;
    b*=3;
    for(int x=0;x<3;x++)
    {
        for(int y=0;y<3;y++)
            if(arr[x+a][b+y]==value && x+a!=i && b+y!=j)
                return false;
    }
    return true;
}
bool sudoku(int** arr,int i,int j)
{
    if (i==9)
    {
        return true;
    }
    int x;
    for(x=j;x<9;x++)
        if(arr[i][x]==-1)
            break;
    if(x==9)
        return sudoku(arr,i+1,0);
    for(int test=1;test<10;test++)
    {
        if(Issafe(arr,i,x,test))
        {
            arr[i][x]=test;
            if(sudoku(arr,i,x))
                return true;
            arr[i][x]=-1;
        }
    }
    return false;

}
int main()
{
    int** arr=new int*[9];
    for(int i=0;i<9;i++)
        arr[i]=new int[9];
    #ifndef ONLINE
        freopen("test.txt","r",stdin);
    #endif
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            cin>>arr[i][j];
    
    sudoku(arr,0,0);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

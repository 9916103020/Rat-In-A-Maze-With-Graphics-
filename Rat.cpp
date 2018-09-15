#include<bits/stdc++.h>
#include<graphics.h>
#include<dos.h>
#define n 4

using namespace std;

void print(int sol[n][n]);
void print1(int sol[n][n]);

int z=0;
int gdriver = DETECT,gmode;

void display()
{
    cout<<"\t\t\tALGO PROJECT \n\n\n";
    cout<<"\t\t\tRAT IN A MAZE\n\n";
    cout<<"Submitted by:-\nNikhil Arora  9916103199\nDivyansh Srivastava  9916103020\n\n";
}

void printMsg()
{
    // auto detection
    int gdriver = DETECT,gmode,i;

    // initialize graphics mode
    initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
        setcolor(3);
    settextstyle(3,0,3);
    outtextxy(100,20*3,"ALGO PROJECT");
    delay(500);
    setcolor(2);
    outtextxy(100,20*4,"RAT IN A MAZE");
    delay(500);
    setcolor(4);
    outtextxy(100,20*5,"Submitted By:-");
    delay(500);
    setcolor(1);
    outtextxy(100,20*6,"NIKHIL ARORA");
    delay(500);
    setcolor(5);
    outtextxy(100,20*7,"9916103199");
    delay(500);
    setcolor(6);
    outtextxy(100,20*8,"DIVYANSH SRIVASTAVA");
    delay(500);
    setcolor(7);
    outtextxy(100,20*9,"9916103020");
    delay(500);



    delay(2000);
}

int sol[n][n]= {{0,0,0,0},
                {0,0,0,0},
                {0,0,0,0},
                {0,0,0,0,}};

void print(int sol[n][n]);


int issafe(int maze[n][n], int row, int col)
{
    if(row>=0 && row<n && col>=0 && col<n && maze[row][col]==1)
            return 1;
    return 0;
}

int solvemaze(int maze[n][n], int row, int col, int sol[n][n])
{
    if(row==n-1 && col==n-1)
    {
        sol[row][col]=1;

        return 1;
    }

    if(issafe(maze,row,col) == 1)
    {

        sol[row][col]=1;
            print1(sol);
            print(sol);

        if(solvemaze(maze, row, col+1,sol) == 1)
        {
            return 1;
        }
        if(solvemaze(maze, row+1, col,sol) == 1)
        {
            return 1;
        }
        else
        {
            cout<<"Backtracking step \n";
            sol[row][col]=0;
            print1(sol);
            print(sol);
            return 0;
        }
    }
    return 0;
}

void print(int sol[n][n])
{

    int i,j;
    char msg[128];
    if(z==0)
    {
        initgraph(&gdriver,&gmode,"");
    }
    for(i=0;i<n;i++)
    {
        settextstyle(3,0,3);
        delay(60);
        for(j=0;j<n;j++)
        {
            outtextxy(50*j,20*i," ");
            delay(60);
            sprintf(msg, " %d ", sol[i][j]);
            outtextxy(50*j,20*i,msg);
            delay(60);
            outtextxy(50*j,20*i," ");
            delay(60);
        }
        z=1;

    }
    //delay(2000);

}

void print1(int sol[n][n])
{
    int i,j;

    for(i=0;i<n;i++)
    {
        cout<<"|";
        for(j=0;j<n;j++)
        {
            cout<<" "<<sol[i][j]<<" |";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}
int main()
{
    display();
        int maze[n][n]={{1,1,1,0},
                        {0,1,0,1},
                        {0,1,1,0},
                        {0,1,1,1}};


    cout<<"Maze"<<"\n";
    print1(maze);
    print(maze);

    solvemaze(maze,0,0,sol);

    cout<<"Solution \n";

    print1(sol);
    print(sol);
    delay(2000);
    printMsg();

}

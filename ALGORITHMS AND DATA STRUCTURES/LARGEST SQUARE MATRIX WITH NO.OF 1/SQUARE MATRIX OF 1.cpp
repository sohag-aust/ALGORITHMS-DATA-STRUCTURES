/// TUTORIAL :https://www.youtube.com/watch?v=_Lf1looyJMU&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=28

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row,col;

    cout<<"Enter the size of row: ";
    cin>>row;

    cout<<"Enter the size of column: ";
    cin>>col;

    int square[row+5][col+5];
    int temp[row+5][col+5];

    cout<<"Enter the square matrix -> "<<endl;
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            cin>>square[i][j];

    int max_square = 0;

    for(int i=0; i<row+1; i++)
    {
        for(int j=0; j<col+1; j++)
        {
            if(!i || !j)
            {
                temp[i][j] = 0;
                continue;
            }

            int i1 = i-1, j1 = j-1;

            if(square[i1][j1])
            {
                int up = temp[i1][j];
                int left_up = temp[i1][j1];
                int left = temp[i][j1];

                temp[i][j] = min(up,min(left_up,left)) + 1;
                max_square = max(max_square,temp[i][j]);
            }

            else temp[i][j] = 0;
        }
    }

    cout<<"\nMy temp -> "<<endl;
    for(int i=0; i<row+1; i++)
    {
        for(int j=0; j<col+1; j++)
            cout<<temp[i][j]<<" ";
        cout<<endl;
    }

    cout<<"\nMax Square size: "<<max_square<<endl;
    cout<<"Max number of '1' is: "<<max_square * max_square<<endl;

    return 0;
}

/**
0 0 1 1 1
1 0 1 1 1
0 1 1 1 1
1 0 1 1 1
*/
/**
ans : 3
no. of 1: 9
*/


#include<bits/stdc++.h>
using namespace std;

int sub_array[1010],n;

int maximum,sum;
int max_left,max_right;
int max_up,max_bottom;

void kadanes_algo(int left,int right)
{
    sum = 0;

    int start_index,end_index,search_index;

    start_index = end_index = search_index = 0;

    for(int i=0; i<n; i++)
    {
        sum = sum + sub_array[i];

        if(maximum < sum)
        {
            maximum = sum;

            start_index = search_index;
            end_index = i;

            max_left = left;
            max_right = right;
            max_up = start_index;
            max_bottom = end_index;
        }

        if(sum < 0)
        {
            sum = 0;
            search_index = i+1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    while(cin>>n)
    {
        memset(sub_array,0,sizeof(sub_array));
        string str;
        int num;
        vector<int>v;

        while(true)
        {
            getline(cin,str);

            stringstream ss(str);

            while(ss>>num)
            {
                v.push_back(num);
                if(v.size() == n*n) break;
            }

            if(v.size() == n*n) break;
        }

        int it = 0;

        int matrix[n+5][n+5];

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                matrix[i][j] = v[it++];

        int left,right,cnt,k;

        cnt = left = right = 0;
        max_left = max_right = 0;
        max_up = max_bottom = 0;
        maximum = sum = 0;

        k = 0;

        while(cnt < n)
        {
            if(k == 0)
            {
                memset(sub_array,0,sizeof(sub_array));

                for(int i=0; i<n; i++)
                {
                    sub_array[i] = matrix[i][right];
                }

                kadanes_algo(left,right);
            }

            else
            {
                for(int i=0; i<n; i++)
                {
                    int val = sub_array[i];
                    int mat_val = matrix[i][right];

                    int sum_here = val + mat_val;

                    sub_array[i] = sum_here;
                }

                kadanes_algo(left,right);

                if(right == n-1)
                {
                    k = 0;
                    left ++;
                    right = left;
                    cnt++;
                    continue;
                }
            }

            if(k<n)
            {
                k++;
            }

            if(right<n-1)
            {
                right++;
            }

            if(left == right) break;
        }

        cout<<"\nMaximum Sum: "<<maximum<<endl;

        cout<<"\nMaximum Sub Array in Matrix -> "<<endl;

        for(int i=max_up; i<=max_bottom; i++)
        {
            for(int j=max_left; j<=max_right; j++)
            {
                cout<<matrix[i][j]<<"  ";
            }

            cout<<endl;
        }
    }

    return 0;
}


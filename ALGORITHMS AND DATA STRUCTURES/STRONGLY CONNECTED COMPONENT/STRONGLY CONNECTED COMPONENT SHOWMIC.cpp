#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 9;

vector<pair<int , int> > edges[MAX+9];
vector<pair<int , int> > rEdges[MAX+9];
stack<int>st;
vector<int>temp;

vector<int>ans[MAX+9];

bool visited[MAX+9];

int counter = 0;

void dfs1(int i)
{
    if(visited[i]) return ;

    visited[i] = true;

    int si = edges[i].size();

    for(int j=0;j<si;j++){

        int val=edges[i][j].first;
        //cout<<"val: "<<val<<endl;
        dfs1(val);
    }

    //cout<<"i ->> "<<i<<endl;

    st.push(i);
    //cout<<"size: "<<st.size()<<endl;
}

void dfs2(int i)
{
    if(visited[i]) return ;

    visited[i] = true;
    //cout<<"i: "<<i<<endl;

    temp.push_back(i);

    int si = rEdges[i].size();

    for(int j=0;j<si;j++){

        dfs2(rEdges[i][j].first);
        //cout<<"edge: "<<rEdges[i][j].first<<endl;
        counter+=rEdges[i][j].second;
        //cout<<"cnt: "<<counter<<endl;
    }
}

int main (void)
{
    memset(visited , false , sizeof(visited));

    int n , m;
    cin >> n >> m;

    for(int i=0;i<m;i++){

        int in1 , in2 , in3;
        cin >> in1 >> in2 >> in3;

        edges[in1].push_back(make_pair(in2, in3));
        rEdges[in2].push_back(make_pair(in1 , in3));
    }

    for(int i=1;i<=n;i++){

        if(!visited[i]){
            dfs1(i);
        }
    }

    int l , r;
    cin >> l >> r;

    memset(visited , false , sizeof(visited));

    int c = 0;

    while(!st.empty()){

        int f = st.top();
        st.pop();

        counter = 0;
        temp.clear();
        dfs2(f);

        if(counter>=l && counter<=r){

            int sii = temp.size();

            for(int j=0;j<sii;j++){
                ans[c].push_back(temp[j]);
            }

            c++;
        }
    }

    for(int i=0;i<c;i++){

        int si = ans[i].size();

        for(int j=0;j<si;j++)cout << ans[i][j] << " ";

        cout << endl;
    }

    return 0;
}

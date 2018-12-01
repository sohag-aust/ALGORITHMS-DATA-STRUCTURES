#include<bits/stdc++.h>
using namespace std;

typedef struct tree
{
    int value;
    struct tree *leftchild;
    struct tree *rightchild;

} node;

node *root = NULL;

void _insert(int n)
{
    node *temp;
    node *current = NULL;
    node *parent = NULL;

    temp = (node*)malloc(sizeof(node));
    temp->value = n;
    temp->leftchild = NULL;
    temp->rightchild = NULL;


    if(root == NULL)
    {
        root = temp;
    }

    else
    {
        current = root;
        parent = NULL;

        while(true)
        {
            parent = current;

            if(n <= parent->value)
            {
                current = current->leftchild;

                if(current == NULL)
                {
                    parent->leftchild = temp;
                    break;
                }
            }

            else
            {
                current = current->rightchild;

                if(current == NULL)
                {
                    parent->rightchild = temp;
                    break;
                }
            }
        }
    }

    return ;
}

void _search(int n)
{
    node* temp = root;
    int flag = 0;

    while(true)
    {
        if(temp->value == n)
        {
            flag = 1;
            break;
        }

        else if(temp->value >= n)
        {
            temp = temp->leftchild;
        }

        else
        {
            temp = temp->rightchild;
        }

        if(temp == NULL) break;
    }

    if(flag) cout<<"FOUND"<<endl;
    else cout<<"NOT FOUND"<<endl;

    return ;
}

void _print(node *temp)
{
    if(temp == NULL) return ;

    cout<<temp->value<<" ";

    _print(temp->leftchild);
    _print(temp->rightchild);
}

int _maximum(node *temp,int mx)
{
    if(temp == NULL) return mx;

    mx = temp->value;
    return _maximum(temp->rightchild,mx);
}

int _minimum(node *temp,int mn)
{
    if(temp == NULL) return mn;

    mn = temp->value;
    return _minimum(temp->leftchild,mn);
}


int main()
{
    int n;

    while(cin>>n)
    {
        if(n == -1) break;

        _insert(n);
    }

    node *temp = root;
    _print(temp);

    while(cin>>n)
    {
        if(n == -1) break;

        _search(n);
    }

    int maxi = _maximum(temp,0);
    int mini = _minimum(temp,1e9);

    cout<<"\nMAXIMUM: "<<maxi<<endl;
    cout<<"MINIMUM: "<<mini<<endl;

    return 0;
}

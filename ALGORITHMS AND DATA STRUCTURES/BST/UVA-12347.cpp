#include<bits/stdc++.h>
using namespace std;

typedef struct tree
{
    int value;
    struct tree *leftchild;
    struct tree *rightchild;
} node;

node* root = NULL;

void _insert(int n)
{
    node* temp;
    node* current = NULL;
    node* parent = NULL;

    temp = (node*) malloc(sizeof(node));
    temp->value = n;
    temp->leftchild = NULL;
    temp->rightchild = NULL;

    if(root == NULL)
        root = temp;

    else
    {
        current = root;
        parent = NULL;

        while(true)
        {
            parent = current;

            if(n <= current->value)
            {
                current = current->leftchild;

                if(current == NULL)
                {
                    parent->leftchild = temp;
                    return ;
                }
            }

            else
            {
                current = current->rightchild;

                if(current == NULL)
                {
                    parent->rightchild = temp;
                    return ;
                }
            }
        }
    }
}

void _postorder(node *temp)
{
    if(temp == NULL) return ;

    _postorder(temp->leftchild);
    _postorder(temp->rightchild);

    cout<<temp->value<<endl;
}

int main()
{
    int n;

    while(cin>>n)
    {
        //if(n == -1) break;

        _insert(n);
    }

    _postorder(root);

    return 0;
}


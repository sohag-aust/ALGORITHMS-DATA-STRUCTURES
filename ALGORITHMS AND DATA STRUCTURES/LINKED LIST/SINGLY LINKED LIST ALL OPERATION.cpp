#include<bits/stdc++.h>
using namespace std;

typedef struct link_list node;

struct link_list
{
    int data;
    node *link;
};

node *head = NULL;
node *last = NULL;
int cnt;

void insert_last(int value)
{
    node *temp;

    temp = (node*) malloc(sizeof(node));

    temp->data = value;
    temp->link = NULL;

    if(head == NULL)
    {
        head = temp;
        last = temp;
    }

    else
    {
        last->link = temp;
        last = temp;
    }
}

void insert_first(int value)
{
    node *temp;

    temp = (node*) malloc(sizeof(node));

    temp->data = value;
    temp->link = head;
    head = temp;
}

void insert_middle(int f_key, int value, int l_key)
{
    node *temp;
    node *f_link,*l_link;

    temp = head;

    /// searching first key...

    while(true)
    {
        if(temp->data == f_key)
        {
            f_link = temp;
            //cout<<"f: "<<f_link->data<<endl;
            break;
        }

        temp = temp->link;
    }

    /// searching last key...

    while(true)
    {
        if(temp->data == l_key)
        {
            l_link = temp;
            //cout<<"l: "<<l_link->data<<endl;
            break;
        }

        temp = temp->link;
    }

    free(temp);

    temp = (node*) malloc(sizeof(node));

    temp->data = value;
    temp->link = l_link;

    f_link->link = temp;
}

void delete_value(int value)
{
    node *temp, *f_link=NULL, *l_link;

    temp = head;

    int f=0;
    cnt=0;

    while(true)
    {
        if(temp->data == value)
        {
            f=1;
            break;
        }

        f_link = temp;

        temp = temp->link;

        if(temp==NULL) break;

        cnt++;
    }

    if(!f)
    {
        cout<<"\nValue not found..."<<endl;
        return ;
    }

    if(cnt==0)
    {
        head = temp->link;
    }

    else
    {
        l_link = temp->link;

        if(l_link!=NULL)
        {
            f_link->link = l_link;
        }

        else
        {
            f_link->link = NULL;
        }
    }

    cout<<"\nValue "<<value<<" removed.."<<endl;
}

void search_value(int value)
{
    node *temp;

    temp = head;

    int f=0;

    while(true)
    {
        if(temp->data == value)
        {
            f=1;
            cout<<"\nvalue found at "<<cnt<<" 'th place..."<<endl;
            break;
        }

        temp = temp->link;

        if(temp==NULL) break;

        cnt++;
    }

    if(!f)
        cout<<"\nValue not Found.."<<endl;
}

void print()
{
    node *temp;

    temp = head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->link;
    }

    cout<<endl;
}

int main()
{
    cout<<"\n # 1 -> Press '1' to insert value at last.."<<endl;
    cout<<" # 2 -> press '2' to insert value at first.."<<endl;
    cout<<" # 3 -> press '3' to insert value at middle.."<<endl;
    cout<<" # 4 -> press '4' to delete value from list.."<<endl;
    cout<<" # 5 -> press '5' to search value from list.."<<endl;
    cout<<" # 6 -> press '6' to print the total list.."<<endl;

    while(true)
    {
        int choice,value;
        cout<<"\nEnter your choice: ";
        cin>>choice;

        if(choice>=1 && choice<=5)
        {
            cout<<"\nEnter a value: ";
            cin>>value;
        }

        switch(choice)
        {

        case 1:
        {
            insert_last(value);
            break;
        }

        case 2:
        {
            insert_first(value);
            break;
        }

        case 3:
        {
            int f_key,l_key;

            cout<<"\nEnter first key: ";
            cin>>f_key;

            cout<<"Enter last key: ";
            cin>>l_key;

            insert_middle(f_key,value,l_key);
            break;
        }

        case 4:
        {
            delete_value(value);
            break;
        }

        case 5:
        {
            cnt=1;
            search_value(value);
            break;
        }

        case 6:
        {
            cout<<"\nLinked list contains:  ";
            print();
            cout<<endl;

            break;
        }

        }
    }

    return 0;
}

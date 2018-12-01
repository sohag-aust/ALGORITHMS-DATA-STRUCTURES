#include<bits/stdc++.h>
using namespace std;

typedef struct linked_list node;

struct linked_list
{
    int data;
    node* pre;
    node* next;
};

node *head = NULL;
node *tail = NULL;

int cnt;

void insert_last(int value)
{
    node *temp;

    temp = (node*) malloc(sizeof(node));

    temp->data = value;
    temp->next = NULL;
    temp->pre = NULL;

    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }

    else
    {
        tail->next = temp;
        temp->pre = tail;
        tail = temp;
    }
}

void insert_first(int value)
{
    node *temp;

    temp = (node*) malloc(sizeof(node));

    temp->data = value;
    temp->next = NULL;
    temp->pre = NULL;

    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }

    else
    {
        head->pre = temp;
        temp->next = head;
        head = temp;
    }
}

void insert_middle(int value, int position)
{
    node *temp;
    node *temp1,*temp2;

    temp1 = (node*) malloc(sizeof(node));

    temp = head;
    temp2 = head;

    while(true)
    {
        if(cnt == position)
        {
            temp1->data = value;
            temp1->next = temp;
            temp1->pre = temp2;

            temp->pre = temp1;
            temp2->next = temp1;

            break;
        }

        if(cnt>1)
        {
            temp2->next = temp;
            temp->pre = temp2;

            temp2 = temp;
        }

        temp = temp->next;
        cnt++;
    }
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

        temp = temp->next;

        if(temp==NULL) break;

        cnt++;
    }

    if(!f)
        cout<<"\nValue not Found.."<<endl;
}

void delete_value(int pos)
{
    node *temp1,*temp2;
    node *temp;

    temp1 = (node*) malloc(sizeof(node));
    temp2 = (node*) malloc(sizeof(node));

    temp1 = NULL;
    temp2 = NULL;

    temp = head;

    if(pos==1) /// delete 1st position...
    {
        head = temp->next;
    }

    else
    {
        int f=1;

        while(true)
        {
            if(cnt==pos) break;

            temp1 = temp;
            temp = temp->next;

            if(temp->next == NULL)  /// delete last position...
            {
                f=0;
                temp1->next = NULL;
                tail = temp1;
                break;
            }
            cnt++;
        }

        if(f) /// delete any position without 1st and last position...
        {
            temp1 = temp->pre;
            temp2 = temp->next;
            temp1->next = temp2;
            temp2->pre = temp1;
        }
    }
}

void print_forward()
{
    node *myList;
    myList = head;

    while(true)
    {
        //if(head==NULL || tail==NULL) break;

        cout<<myList->data<<" ";

        if(myList==tail) break;

        myList = myList->next;
    }

    cout<<endl;
}

void print_backward()
{
    node *myList;

    myList = tail;

    while(true)
    {
        //if(head == NULL || tail == NULL) break;

        cout<<myList->data<<" ";

        if(myList == head) break;

        myList = myList->pre;
    }

    cout<<endl;
}

int main()
{
    cout<<"\n # 1 -> Press '1' to insert value at last.."<<endl;
    cout<<" # 2 -> press '2' to insert value at first.."<<endl;
    cout<<" # 3 -> press '3' to insert value at middle.."<<endl;
    cout<<" # 4 -> press '4' to search value from list.."<<endl;
    cout<<" # 5 -> press '5' to delete value from list.."<<endl;
    cout<<" # 6 -> press '6' to print forward the total list.."<<endl;
    cout<<" # 7 -> press '7' to print backward the total list.."<<endl;

    while(true)
    {
        int choice,value,position;
        cout<<"\nEnter your choice: ";
        cin>>choice;

        if(choice>=1 && choice<=4)
        {
            cout<<"Enter a value: ";
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
            cnt=1;

            cout<<"Enter the position: ";
            cin>>position;

            insert_middle(value,position);
            break;
        }

        case 4:
        {
            cnt=1;
            search_value(value);
            break;
        }

        case 5:
        {
            cout<<"Enter position to be deleted: ";
            cin>>position;

            cnt=1;
            delete_value(position);
            break;
        }

        case 6:
        {
            cout<<"\nLinked list contains:  ";
            print_forward();
            cout<<endl;

            break;
        }

        case 7:
        {
            cout<<"\nLinked list contains:  ";
            print_backward();
            cout<<endl;

            break;
        }

        }
    }

    return 0;
}

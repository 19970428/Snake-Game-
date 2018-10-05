#include<iostream>
#include <conio.h>
#include<windows.h>
using namespace std;
void print();
void matrix();
struct food
{
   int x;
   int y;
   char value='X';
};
struct food f1;
struct snake
{
    int x;
    int y;
    char value;
    struct snake *next;
};
struct snake *head=NULL;
struct snake *nn;
struct snake *ptr;
struct snake *tail;
void create()
{
    int x1,y1;
    int x,y;
    cin>>x>>y;
    while(x!=-1)
    {
         if(head == NULL)
         {
         nn=new snake;
         nn->x=x;
         nn->y=y;
         nn->value='C';
         nn->next=NULL;
         head=nn;
         }
         else
         {
             nn=new snake;
             nn->x=x;
             nn->y=y;
             nn->value='O';
             nn->next=head;
             head=nn;
         }
         cin>>x>>y;
    }
head->value='A';
}

int operation(char dir)
{
    int x1,y1;
    static char k='L';
    if(dir=='L')
    {
         int x,y;
       x=head->x;
       y=head->y;
       ptr=head->next;
       while(ptr!=NULL)
       {
          // int x1,y1;
           x1=ptr->x;
           y1=ptr->y;
           ptr->x=x;
           ptr->y=y;
           x=x1;
           y=y1;
           ptr=ptr->next;
       }
k='L';
       if(head->y==0)
       {
           head->y=9;
       }
       head->y=head->y-1;
    }
   else  if(dir == 'R' && k!='L')
    {
         int x,y;
       x=head->x;
       y=head->y;
       ptr=head->next;
       while(ptr!=NULL)
       {
         //  int x1,y1;
           x1=ptr->x;
           y1=ptr->y;
           ptr->x=x;
           ptr->y=y;
           x=x1;
           y=y1;
           ptr=ptr->next;
       }
       if(head->y==9)
       {
           head->y=0;
       }
       else
       head->y=head->y+1;
       k='R';
    }
   else if(dir=='D' && k!='U')
   {
 int x,y;
       x=head->x;
       y=head->y;
       ptr=head->next;
       while(ptr!=NULL)
       {

           x1=ptr->x;
           y1=ptr->y;

           ptr->x=x;
           ptr->y=y;
           x=x1;
           y=y1;
           ptr=ptr->next;
       }

       if(head->x==9)
       {
           head->x=0;
       }
       else
       head->x=head->x+1;
       k='D';
    }
    else if(dir=='U' && k!='D')
    {
 int x,y;
       x=head->x;
       y=head->y;
       ptr=head->next;
       while(ptr!=NULL)
       {

           x1=ptr->x;
           y1=ptr->y;
           ptr->x=x;
           ptr->y=y;
           x=x1;
           y=y1;
           ptr=ptr->next;
       }
       if(head->x==0)
       {
           head->x=9;
       }
       else
       head->x=head->x-1;
       k='U';
       // cout<<"x1 : "<<ptr->x1<<" y1 : "<<ptr->y1;
    }
else
{
    cout<<"No such operation\n";
}
 //cout<<"x1 = "<<x1<<" y1 = "<<y1;
//cout<<"head->x : "<<head->x<<" "<<"head->y :"<<head->y<<"\nf1.x :"<<f1.x<<" f1.y: "<<f1.y<<"\n";
int flag=0;
if(head->x == f1.x && head->y==f1.y)
{
   f1.x=rand()%9;
   f1.y=rand()%9;
   ptr=head;
   while(ptr!=NULL)
   {
       while(ptr->x == f1.x && ptr->y==f1.y)
       {
        f1.x=rand()%9;
        f1.y=rand()%9;
       }
       ptr=ptr->next;
   }
  ptr=head;
  while(ptr->next!=NULL)
  {
      ptr=ptr->next;
  }
  nn=new snake;
  ptr->value='O';
  ptr->next=nn;
  nn->x=x1;
  nn->y=y1;
  nn->value='C';
}
else
{
ptr=head->next;
while(ptr!=NULL)
{
    if(ptr->x == head->x && ptr->y == head->y)
    {
        cout<<"Game Over!";
        flag=1;
        break;
    }
    ptr=ptr->next;
}
}
if(flag==1)
{
    return 1;
}
else
{
    matrix();
    return 0;
}
}
void matrix()
{
    char board[100][100];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            board[i][j]=' ';
        }
    }
    ptr=head;
    while(ptr!=NULL)
    {
        board[ptr->x][ptr->y]=ptr->value;
        ptr=ptr->next;
    }

    //f1=new food;
    board[f1.x][f1.y]=f1.value;

     for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }


}

void print()
{
    ptr=head;
    while(ptr!=NULL)
    {

        cout<<ptr->value<<"";
        ptr=ptr->next;
    }
    //cout<<tail->value;
}
int main()
{
    create();
    print();
    cout<<"\n";
    matrix();
    int i=0;
    f1.x=rand()%9;
    f1.y=rand()%9;
    while(1)
    {
    char dir;
    cin>>dir;
    while(!kbhit())
    {
    int r=operation(dir);
    if(r==1)
    {
        break;
    }
    Sleep(1000);
    cout<<"\n";

    }
    }

}
# Snake-Game-
# Snake-Game-

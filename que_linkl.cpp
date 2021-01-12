//Implementing Queue with Linked list
#include <iostream>
#include <conio.h>
#include <stdlib.h>

struct node
 {  char name[15];
    int age;
    float height;
    node *next;
 };
node *ptr=NULL;

int main()
{

  void push ();
  void pop();
  char in;
  
  

  do
  {
   std::cout<<"Operation To be Performed?";
   std::cout<<"a->push";
   std::cout<<"b->pop";
   std::cout<<"c->exit";

   std::cin>>in;

   switch(in)

    case 'a':
        push();
        break;
    case 'b':
        pop();
        break;
    case 'c':
        exit(0);
   }
   }while(in!='c');

        return 0;

}

void pop()
{
 node *tmp1,*tmp2;
 if(ptr==NULL)
   std::cout<<"Empty List";
 else
  {
   tmp1=ptr;
   tmp2=tmp1;
  while(tmp1->next!=NULL)
   {
    tmp2=tmp1;
    tmp1=tmp1->next;
   }
  if(tmp1==tmp2)
    {
     std::cout<<tmp1->name<<",";
     std::cout<<tmp1->age<<", ";
     std::cout<<tmp1->height;
     ptr=NULL;
    }
  else
    {
     std::cout<<tmp1->name<<", ";
     std::cout<<tmp1->age<<", ";
     std::cout<<tmp1->height;
     tmp2->next=NULL;
     delete tmp1;
    }
 }
}

void push ()
 {
    node *tmp;

    tmp = new node;
    std::cout << "Name : ";
    std::cin >> tmp->name;
    std::cout << "Age : ";
    std::cin >> tmp->age;
    std::cout << "Height : ";
    std::cin >> tmp->height;
    if (ptr == NULL)
                {
                 tmp->next=NULL;
                 ptr = tmp;
                }
    else
                {
      tmp->next=ptr;
      ptr=tmp;

                }
  }
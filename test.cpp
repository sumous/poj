#include <iostream>
using namespace std;
void f1(int i)
{
    cout<<"this is f1, and i = "<<i<<endl;
}
void f2(void (*f)(int) , int i)
{
    cout<<"this is f2, and i = "<<i<<endl;
 //   f = f1;
   // f(i++);
}
void f3(void (*f)(void (*f1)(int), int) , int i)
{
    cout<<"this is f3, and i = "<<i<<endl;
  //  f = f2;
   // f(f1,++i);
}
int main()
{
   int *p;
   while(1)
   {
       p = new(int);
   }
    return 0;
}

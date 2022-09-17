/* header file for storing intiger type of adress of node in stack */

#include<bits/stdc++.h>

#ifndef stackForIpost_h
#define stackForIpost_h

using namespace std;

template<class T>
class Stack1
{
 private:
  T *st;
  int size;
  int top;
  public:
  Stack1(){size=10;top=-1;st=new T[size];}
  Stack1(int size){this->size=size;top=-1;st=new T[this->size];}
  void push(T x);
  T pop();
  T peek(int index);
  int stacktop();
  int isEmpty();
  int isFull(); 
  void Display();

};

 template<class T>
 void Stack1<T>::push(T x)
 {
    if(isFull())
     cout<<"Stack Overflow"<<endl;
  else
  {
    top++;
    st[top]=x;
  }

}

template<class T>
T Stack1<T>::pop()
{
  T x=-1;
  if(isEmpty())
   cout<<"Stack underlfow"<<endl;
  else
  {
   x=st[top];
   top--;
  }
 return x;
}

 template<class T>
T Stack1<T>::peek(int index)
{
  T x=-1;
  if(top-index+1<0)
  cout<<"Invalid Index"<<endl;
  else
  x=st[top-index+1];
  return x;
}

template<class T>
int Stack1<T>::stacktop()
{
  if(isEmpty())
  return -1;
  return st[top];
}

template<class T>
int Stack1<T>::isFull()
{
  return top==size-1;
}

template<class T>
int Stack1<T>::isEmpty()
{
 return top==-1;
}

template<class T>
void Stack1<T>::Display()
{
  for(int i=top;i>=0;i--)
  cout<<st[i]<<" ";
  cout<<endl;
}

#endif /*StackCpp_h  */
#include<iostream>
#include<conio.h>
#include<vector>
#include<list>
#include<deque>
#include<stack>
using namespace std;
template<class T> void pushelement(T & s);	
template<class T> void popelement(T & s);	
int main(){
	stack <int> dequestack;	
	stack <int,vector<int> > vectorstack;
	stack <int,list<int> > liststack;  
	cout<<"\npushing elements onto dequestack : ";
	pushelement(dequestack);
	cout<<"\npushing elements onto vectorstack : ";
	pushelement(vectorstack);
	cout<<"\npushing elements onto liststack : ";
	pushelement(liststack);
	cout<<"\n------------------------------------------------";
	cout<<"\npopping element from dequestack : ";
	popelement(dequestack);
	cout<<"\npopping element from vectorstack : ";
	popelement(vectorstack);
	cout<<"\npopping element from liststack : ";
	popelement(liststack);
	getch();
	return 0;
}
template<class T>
void pushelement(T & s){
	for(int i=0;i<10;i++)		{
		s.push(i);
		cout<<s.top()<<" ";
	}
}

template<class T>
void popelement(T & s)
{
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}








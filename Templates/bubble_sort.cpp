//BUBBLE SORT using Templates
#include<iostream>
using namespace std;

template<typename X> void swapit(X &a,X &b)
{   X temp=a;
    a=b;
    b=temp;
}
template<typename T> void selectsort(T a[],int n)
{
    int i,j;  
    for(i=0;i<(n-1);i++)
    { 
        for(j=0;j<(n-i-1);j++)
        {   if(a[j]>a[j+1])
	    {    swapit(a[j],a[j+1]);
	    }
	}	
    }
    cout<<"\tSORTED ARRAY :\n";
    for(i=0;i<10;i++)
    {   cout<<a[i]<<"\t";
    }
}
int main()
{   int i;
    int x[10]={2,23,56,43,78,40,20,44,267,90};
    cout<<"\t\nUNSORTED ARRAY :\n";
    for(i=0;i<10;i++)
    {   cout<<x[i]<<"\t";
    }
    selectsort(x,10);

    char y[10]={'a','A','-','1','*','6','Y','D','~','/'};
    cout<<"\t\nUNSORTED ARRAY :\n";
    for(i=0;i<10;i++)
    {   cout<<y[i]<<"\t";
    }
    selectsort(y,10);

return 0;
}

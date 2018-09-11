//SELECTION SORT using function template :

#include<iostream>
using namespace std;

template<typename X> void swapit(X &a,X &b)
{   X temp=a;
    a=b;
    b=temp;
}
template<typename T> void selectsort(T a[],int n)
{
    int i,j,pos;
    T mini;
    for(i=0;i<n;i++)
    {   mini=a[i];
        pos=i;
        for(j=i+1;j<n;j++)
        {   if(mini>a[j])
            {   mini=a[j];
                pos=j;
            }
        }
        swapit(a[i],a[pos]);
    }
    cout<<"\tSORTED ARRAY :\n";
    for(i=0;i<10;i++)
    {   cout<<a[i]<<"\t";
    }
}
int main()
{   int i;
    int x[10]={2,23,56,43,78,40,20,44,267,90};
    cout<<"\tUNSORTED ARRAY :\n";
    for(i=0;i<10;i++)
    {   cout<<x[i]<<"\t";
    }
    selectsort(x,10);

    char y[10]={'a','A','-','1','*','6','Y','D','~','/'};
    cout<<"\tUNSORTED ARRAY :\n";
    for(i=0;i<10;i++)
    {   cout<<y[i]<<"\t";
    }
    selectsort(y,10);

    return 0;
}

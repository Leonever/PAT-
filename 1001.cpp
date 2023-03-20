#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int c=a+b;
    if(c==0)
        cout<<c;
    else{
        if(c<0){
            cout<<"-";
            c=-c;
        }  
        int digit[12];
        for(int i=0;i<12;i++)
            digit[i]=0;
        int i=0;
        while(c){
            int d=c%10;
            digit[i++]=d;
            c=c/10;
        }
        int len=i-1;
        for(i=len;i>=0;i--){
            if((i+1)%3==0&&i!=len)
                cout<<",";
            cout<<digit[i];
        }
    }
    return 0;
}
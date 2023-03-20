#include<iostream>
using namespace std;
struct sign{
    string id;
    string signin;
    string signout;
}member[100];
int main()
{
    int total;
    cin>>total;
    for(int i=0;i<total;i++){
        cin>>member[i].id>>member[i].signin>>member[i].signout;
    }
    int loc0=0,loc1=0;
    string in=member[0].signin;
    string out=member[0].signout;
    for(int i=1;i<total;i++){
        if(member[i].signin<in){
            loc0=i;
            in=member[i].signin;
        }
        if(member[i].signout>out){
            loc1=i;
            out=member[i].signout;
        }
    }
    cout<<member[loc0].id<<" "<<member[loc1].id;
    return 0;
}
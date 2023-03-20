#include<iostream>
using namespace std;
struct student{
    string ID;
    int point_A;
    int rank_A;
    int point_C;
    int rank_C;
    int point_M;
    int rank_M;
    int point_E;
    int rank_E;
}students[2000];
int main()
{
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>students[i].ID;
        cin>>students[i].point_C;
        cin>>students[i].point_M;
        cin>>students[i].point_E;
        students[i].point_A=(students[i].point_C+students[i].point_E+students[i].point_M)/3;
    }
    for(int i=0;i<N;i++){
        int ranking=1;
        for(int k=0;k<N;k++)
            if(students[i].point_A<students[k].point_A)
                ranking++;
        students[i].rank_A=ranking;
        ranking=1;
        for(int k=0;k<N;k++)
            if(students[i].point_C<students[k].point_C)
                ranking++;
        students[i].rank_C=ranking;
        ranking=1;
        for(int k=0;k<N;k++)
            if(students[i].point_M<students[k].point_M)
                ranking++;
        students[i].rank_M=ranking;
        ranking=1;
        for(int k=0;k<N;k++)
            if(students[i].point_E<students[k].point_E)
                ranking++;
        students[i].rank_E=ranking;
    }
    string ID;
    for(int i=0;i<M;i++){
        bool flag=false;
        cin>>ID; 
        for(int k=0;k<N;k++){     
            if(ID==students[k].ID){
                flag=true;
                for(int p=0;p<N;p++){
                    if(p+1==students[k].rank_A){
                        cout<<p+1<<" "<<"A"<<endl;
                        break;
                    }
                    else if(p+1==students[k].rank_C){
                        cout<<p+1<<" "<<"C"<<endl;
                        break;
                    }
                    else if(p+1==students[k].rank_M){
                        cout<<p+1<<" "<<"M"<<endl;
                        break;
                    }
                    else if(p+1==students[k].rank_E){
                        cout<<p+1<<" "<<"E"<<endl;
                        break;
                    }  
                }
            }
        if(flag)
            break;     
        }
        if(!flag){
            cout<<"N/A"<<endl;
        }
    } 
    return 0;
}
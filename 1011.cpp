#include<iostream>
using namespace std;
float betting[3][3]={0};
char radio[3]={'0'};
float rate[3]={0};
int main()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin>>betting[i][j];
    for(int i=0;i<3;i++){
        float max=0;
        for(int j=0;j<3;j++){
            if(betting[i][j]>max&&j==0){
                radio[i]='W';
                max=rate[i]=betting[i][j];
            }
            else if(betting[i][j]>max&&j==1){
                radio[i]='T';
                max=rate[i]=betting[i][j];
            }
            else if(betting[i][j]>max&&j==2){
                radio[i]='L';
                max=rate[i]=betting[i][j];
            }
        }
    }
    for(int i=0;i<3;i++)
        cout<<radio[i]<<" ";
    printf("%.2lf",2*(rate[0]*rate[1]*rate[2]*0.65-1));
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,ind[n];cout<<"Enter number of productions: ";cin>>n;
    string p[n];cout<<"Enter productions as E->E+T|T:\n";
    for(int i=0;i<n;i++){
    cin>>p[i];
    ind[i]=p[i].find("|");
    }
    for(int i=0;i<n;i++){
        if(p[i][4]=='^'){
            cout<<p[i][0]<<"->"<<p[i][0]<<"'"<<p[i].substr(4,ind[i]-4)<<endl;
            cout<<p[i][0]<<"'->"<<p[i].substr(ind[i]+1)<<endl;
        }
        else{
            cout<<p[i].substr(0,ind[i]-1)<<p[i][0]<<"'"<<endl;
            cout<<p[i][0]<<"'->"<<p[i].substr(ind[i]+1)<<endl;
        }
    }
    return 0;
}

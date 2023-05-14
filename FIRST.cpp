#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,ind[n];cout<<"Enter number of productions: ";cin>>n;string stuff="+-*/(@";
    string p[n],f[n];cout<<"Enter productions as E->AB|C (Enter @ for epsilon):\n";
    for(int i=0;i<n;i++){
    cin>>p[i];
    ind[i]=p[i].find("|");
        f[i]="";
    }
    for(int i=n-1;i>=0;i--){
        if(islower(p[i][3]) or stuff.find(p[i][3])!=-1)
        f[i]+=p[i][3];
        else{
            for(int j=0;j<n;j++)
            if(p[j][0]==p[i][3])
            f[i]+=f[j];
        }
        int x=ind[i]+1;
        if(islower(p[i][x]) or stuff.find(p[i][x])!=-1)
        f[i]+=p[i][x];
        else{
            for(int j=0;j<n;j++)
            if(p[j][0]==p[i][x])
            f[i]+=f[j];
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("First(%c) : ",p[i][0]);
        set<char>l(f[i].begin(),f[i].end());
        for(auto it:l)
        cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}

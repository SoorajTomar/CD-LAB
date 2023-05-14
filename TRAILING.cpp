#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cout<<"Enter number of productions: ";cin>>n;string op="+-*/";
    string p[n],trail[n];int ind[n];cout<<"Enter productions as E->E+T|T:\n";
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        ind[i]=p[i].find("|");
        trail[i]="";
    }
    for(int i=n-1;i>=0;i--){
        if(islower(p[i][p[i].length()-1]) or p[i][p[i].length()-1]==')')
        trail[i]+=p[i][p[i].length()-1];
        else{
            for(int k=0;k<n;k++)
            if(p[k][0]==p[i][p[i].length()-1])
            trail[i]+=trail[k];
        }
        if(ind[i]!=-1){
            int x=ind[i]-1;
        if(islower(p[i][x]) or p[i][x]==')')
        trail[i]+=p[i][x];
        else{
            for(int k=0;k<n;k++)
            if(p[k][0]==p[i][x])
            trail[i]+=trail[k];
        }
        x=ind[i]+1;
        if(isupper(p[i][x]) and op.find(p[i][x+1])!=-1 and isupper(p[i][x+2]))
        trail[i]+=p[i][x+1];
        }
        if(isupper(p[i][3]) and op.find(p[i][4])!=-1 and isupper(p[i][5]))
        trail[i]+=p[i][4];
    }
    for(int i=0;i<n;i++)
    {printf("Trail(%c) : ",p[i][0]);
    set<char> l(trail[i].begin(),trail[i].end());
    for(auto it:l)
    cout<<it<<" ";
    cout<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cout<<"Enter number of productions: ";cin>>n;string op="+-*/";
    string p[n],lead[n];int ind[n];cout<<"Enter productions as E->E+T|T:\n";
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        ind[i]=p[i].find("|");
        lead[i]="";
    }
    for(int i=n-1;i>=0;i--){
        if(islower(p[i][3]) or p[i][3]=='(')
        lead[i]+=p[i][3];
        else{
            for(int k=0;k<n;k++)
            if(p[k][0]==p[i][3])
            lead[i]+=lead[k];
        }
        int x=ind[i]+1;
        if(islower(p[i][x]) or p[i][x]=='(')
        lead[i]+=p[i][x];
        else{
            for(int k=0;k<n;k++)
            if(p[k][0]==p[i][x])
            lead[i]+=lead[k];
        }
        if(isupper(p[i][3]) and op.find(p[i][4])!=-1 and isupper(p[i][5]))
        lead[i]+=p[i][4];
        if(isupper(p[i][x]) and op.find(p[i][x+1])!=-1 and isupper(p[i][x+2]))
        lead[i]+=p[i][x+1];
    }
    for(int i=0;i<n;i++)
    {printf("Lead(%c) : ",p[i][0]);
    set<char> l(lead[i].begin(),lead[i].end());
    for(auto it:l)
    cout<<it<<" ";
    cout<<endl;
    }
    return 0;
}

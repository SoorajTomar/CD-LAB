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
        if(p[i][3]==p[i][0])
        {
            cout<<p[i]<<" is left recursive\n";
            if(ind[i]==-1)
            cout<<"It cannot be removed\n";
            else
            {
                string s=p[i].substr(ind[i]+1);
                s+=p[i][0];
                s+="'";
                cout<<p[i][0]<<"->"<<s<<endl;
                cout<<p[i][0]<<"'->"<<p[i].substr(4,ind[i]-4)<<p[i][0]<<"'|epsilon"<<endl;
            }
        }
        else{
            cout<<p[i]<<" is not left recursive\n";
        }
    }
    return 0;
}

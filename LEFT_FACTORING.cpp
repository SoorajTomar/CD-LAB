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
        if(ind[i]!=-1){
            int x=3,y=ind[i]+1;
            while(x<ind[i] and y<p[i].length()){
                if(p[i][x]!=p[i][y])
                break;
                x++;
                y++;
            }
            if(x==3 and y==ind[i]+1)
            cout<<p[i]<<" does not need left factoring\n";
            else{
                cout<<p[i]<<" needs left factoring\n";
            string s="",c="";
            for(int j=3;j<x;j++)
            c+=p[i][j];
            if(x==ind[i]){
                s+="epsilon";
            }
            else{
                for(int j=x;j<ind[i];j++)
                s+=p[i][j];
            }
            s+="|";
            if(y==ind[i]){
                s+="epsilon";
            }
            else{
                for(int j=y;j<p[i].length();j++)
                s+=p[i][j];
            }
            cout<<p[i][0]<<"->"<<c<<endl;
            cout<<p[i][0]<<"'->"<<s<<endl;
            }
        }
        else{
            cout<<p[i]<<" does not need left factoring\n";
        }
    }
    return 0;
}

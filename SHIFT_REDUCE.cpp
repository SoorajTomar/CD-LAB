#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cout<<"Enter number of productions: ";cin>>n;
    string p[n],inp;cout<<"Enter productions as E->E+E:\n";
    for(int i=0;i<n;i++)
    cin>>p[i];
    cout<<"Enter input string: ";cin>>inp;
    int i=0;
    string s="";
    while(i<inp.length()){
        if(s.length()!=0){
            if(islower(s[s.length()-1])){
                for(int j=0;j<n;j++)
                if(p[j][3]==s[s.length()-1])
                s[s.length()-1]=p[j][0];
                cout<<"Reduce\n";
            }
            if(isupper(s[s.length()-1]) and s.length()==3){
                for(int j=0;j<n;j++)
                if(p[j].substr(3)==s)
                s=p[j][0];
                cout<<"Reduce\n";
            }
        }
        cout<<"Shift\n";
        s+=inp[i++];
        cout<<"Stack: $"<<s<<endl;
    }
    if(islower(s[s.length()-1])){
                for(int j=0;j<n;j++)
                if(p[j][3]==s[s.length()-1])
                s[s.length()-1]=p[j][0];
                cout<<"Reduce\n";
            }
            if(isupper(s[s.length()-1]) and s.length()==3){
                for(int j=0;j<n;j++)
                if(p[j].substr(3)==s)
                s=p[j][0];
                cout<<"Reduce\n";
            }
    if(s.length()==1)
    cout<<"String Accepted";
    else
    cout<<"String Rejected";
    return 0;
}

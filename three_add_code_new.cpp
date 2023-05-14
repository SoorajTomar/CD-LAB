#include <bits/stdc++.h>
using namespace std;
char f(int x){
    return (char)(x+48);
}
int pred(char c){
    if(c=='+' || c=='-')
    return 1;
    else
    return 2;
}
int main()
{
    string a,b="+-*/";cout<<"Enter the code: ";
    cin>>a;
    int x1=1,h=0,d=0;
    while(a.length()!=3){
        int hp=0,k=0;
        for(int i=2;i<a.length();i++)
        if(b.find(a[i])!=-1)
        if(hp<pred(a[i])){
            hp=pred(a[i]);
            k=i;
        }
        //cout<<hp<<" "<<k<<endl;
        string x="";
        if(h==0 and d==0)
        {
            x+=a[k-1];
            x+=a[k];
            x+=a[k+1];
        }
        if(a[k-1]=='$')
        {x+="t";
        x+=f(x1-1);
        d=0;x+=a[k];}
        else if(a[k-1]=='#')
        {x+="t";
        if(d==0)
        x+=f(x1-1);
        else
        x+=f(x1-2);
        h=0;x+=a[k];}
        else
        {x+=a[k-1];
        x+=a[k];}
        if(a[k+1]=='$')
        {x+="t";
        x+=f(x1-1);
        d=0;}
        else if(a[k+1]=='#')
        {x+="t";
        if(d==0)
        x+=f(x1-1);
        else
        x+=f(x1-2);
        h=0;}
        else
        x+=a[k+1];
        cout<<"t"<<x1<<"="<<x<<endl;
        x1++;
        string s="";
        for(int i=0;i<a.length();i++){
            if(i!=k&&i!=k+1&&i!=k-1){
                s+=a[i];
            }
            else if(i==k-1){
                if(h==0){
                    h=1;
                    s+='#';
                }
                else{
                    d=1;
                    s+='$';
                }
            }
        }
        a=s;
        cout<<a<<endl;
    }
    return 0;
}

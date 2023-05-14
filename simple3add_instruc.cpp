#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cout<<"Enter number of 3 address codes: ";
    cin>>n;
    string a[n];cout<<"Enter the codes:\n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    int x=0;
    for(int i=0;i<n;i++){
        printf("MOV R%d , %c\n",x,a[i][2]);
        switch(a[i][3]){
            case '+': printf("ADD");break;
            case '-': printf("SUB");break;
            case '*': printf("MUL");break;
            case '/': printf("DIV");break;
        }
        printf(" R%d , %c\n",x,a[i][4]);
        printf("MOV %c , R%d\n",a[i][0],x);
        x++;
    }
    return 0;
}

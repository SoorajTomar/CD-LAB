#include <iostream>
using namespace std;
int main()
{
    string stack[10];
    int top=-1;
    char cont='y';
    while(cont=='y'){
        int c;
        cout<<"Enter :\n1 - To Display contents of stack\n2 - To push an element into the stack\n3 - To pop an element from the stack\n4 - Display top element of stack\n";
        cout<<"Enter your choice (1-4): ";
        cin>>c;
        switch(c){
            case 1:
            if(top==-1)
            cout<<"STACK IS EMPTY!!\n";
            else
            for(int i=top;i>=0;i--)
            cout<<stack[i]<<endl;
            break;
            case 2:
            if(top==9)
            cout<<"STACK OVERFLOW!!\n";
            else{
            cout<<"Enter the element: ";
            cin>>stack[++top];}
            break;
            case 3:
            if(top==-1)
            cout<<"STACK UNDERFLOW!!\n";
            else
            cout<<"Popped Element: "<<stack[top--]<<endl;
            break;
            case 4:
            cout<<"Top Element: "<<stack[top]<<endl;
            break;
            default:
            cout<<"Invalid Choice!!";
        }
        cout<<"Do you want to continue?(y/n): ";
        cin>>cont;
    }cout<<"\t***";
    return 0;
}

#include<iostream>
#include<fstream>
using namespace std;

void reg();
void login();







int main(){
    int choice;
    cout<<"\t\t===========================";
    cout<<"\t\t { WEL-COME }"<<endl;
    cout<<"\t\t Press 1 for Register===";
    cout<<"\t\t Press 2 for LOGIN";
    cin>>choice;
    
    switch(choice){
        case 1:
        reg();
        break;
        case 2:
        login();
        break;
        default: 
        cout<<"dekhe k enter kar andhe"<<endl;
        cout<<"Phir se main menu m jaa "<<endl;
        main();
    }


return 0;
}


void reg()
{
    
    string rusername,rpassword;
    cout<<"\n\n WELCOME TO REGISTRATION"<<endl;    
    cout<<"\n\n ENTER DETAILS "<<endl;    
    cout<<"\n\n USERNAME "<<endl;
    cin>>rusername;
    cout<<"\n\n password"<<endl;
    cin>>rpassword;
    ofstream f1;
    f1.open("bahi.txt" , ios::app);
}
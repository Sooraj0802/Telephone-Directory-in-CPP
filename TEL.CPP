#include<iostream>
#include<fstream>
using namespace std;
void reg();
void login();
void operation();

int main(){
    int choice;
    cout<<"\t\t========================"<<endl;
    cout<<"\t\t\tWELCOME"<<endl;
    cout<<"\t\t========================"<<endl;
    cout<<"\t\t\t1. REGISTER  |"<<endl;
    cout<<"\t\t\t2. LOGIN     |"<<endl<<endl<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
        reg();
        break;
        case 2:
        login();
        break;
        default:
        cout<<"Please choose from given options"<<endl; 
        main();

    }
    
return 0;
}
 void operation(){
        int n;
        cout<<"\t\t\t****************"<<endl;
        cout<<"\t\t\t|    Press 1 for serch people    |"<<endl;
        cout<<"\t\t\t|    Press 2 to |"<<endl; 
        cout<<"\t\t\t|    Press 3 to         |"<<endl; 
        cout<<"\t\t\t****************"<<endl<<endl;
        cout<<"\t\t\tEnter your choice :"<<endl;
        cin>>n;
        switch(n){
            case 1:
            cout<<"case 1"<<endl;
            break;
            case 2:
            cout<<"case 2"<<endl;
            break;
            case 3:
            cout<<"case 3"<<endl;
            break;
            default :
            cout<<"\t\t\tPlease choose from given option"<<endl;
        }
    } 
    
void reg()
    {
        string rusername, rpassword,rnumber;
        cout<<"\t\t\t WELCOME TO REGISTRATION"<<endl;
        cout<<"\t\t\t ENTER DETAILS"<<endl;

        cout<<"\t\t\t USERNAME :"<<endl;
        cin>>rusername;
        cout<<"\t\t\t PASSWORD :"<<endl;
        cin>>rpassword;
        cout<<"\t\t telephone number:"<<endl;
        cin>>rnumber;
        ofstream f1;
        f1.open("record.txt", ios::app);
        f1<<rusername<<' '<<rpassword<<endl;
        f1.close();
        ofstream f2;
        f2.open("telephone.txt", ios::app);
        f2<<rnumber<<endl;
        f2.close();
        cout<<"\t\t\tREGISTRATION SUCESSFUL! PLEASE LOGIN"<<endl;
        main();
    }
    void login()
    {
        int count=0;
        string lnumber, lpasswod, ltel, lpass;
        cout<<"\t\t\tWELCOME TO LOGIN"<<endl;
        cout<<"\t\t\tENTER DETAILS"<<endl;
        cout<<"\t\t\tUSERNAME :"<<endl;
        cin>>lnumber;
        cout<<"\t\t\tPASSWORD :"<<endl;
        cin>>lpasswod;
        ifstream f2;
        f2.open("record.txt");

        while(f2>>ltel>>lpass){
            if(ltel==lnumber && lpass==lpasswod){
                count++;

            }
        }
        f2.close();
        if(count == 1){
            cout<<"Hello "<<lnumber<<" You are sucessfully logined"<<endl;
            operation();
        }else{
            cout<<"Incorrect id or password, Or you have to register first"<<endl;
            main();
        }
       
    }
  
      
   
   
    
    
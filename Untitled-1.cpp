#include<iostream>
#include<fstream>
#include<cstring>
#include<limits>
#include<iomanip>

using namespace std;
void reg();
void login();
void operation();
class phoneBook{
    char name[20],phno[15];
    public:
    void getdata();
    void showdata();
    char *getname(){ return name; }
    char *getphno(){ return phno; }
    void update(char *nm,char *telno){
        strcpy(name,nm);
        strcpy(phno,telno);
    }
};

void phoneBook :: getdata(){
    cout<<"\nEnter New record Details";
    cout<<"\nEnter New Name : ";
    cin>>name;
    cout<<"Enter New Telephone Number : ";
    cin>>phno;
}

void phoneBook :: showdata(){
    cout<<"\n";
    cout<<setw(20)<<name;
    cout<<setw(15)<<phno;
}


int main(){

    int path;
    cout<<"\t\t===========================";
    cout<<"\t\t { WEL-COME }"<<endl;
    cout<<"\t\t Press 1 for Register===";
    cout<<"\t\t Press 2 for LOGIN";
    cin>>path;
      switch(path){
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
   
    
void operation(){
  phoneBook rec;
    int flag;
    fstream file;
    char ch,nm[20],telno[15];
    int choice,found=0;
    while(1){
        system("color 9C");
         
        cout<<"\n\t*******WELCOME TO TELEPHONE DIRECTORY*****\n";
        cout<<"\n\t\t*****PHONE BOOK*****\n";
         cout<<"\n\t\t*******************\n";
        cout<<"\t\t1) Add New Record\n";
        cout<<"\t\t2) Display All Records\n";
        cout<<"\t\t3) Search Telephone Number\n";
        cout<<"\t\t4) Search Person's Name\n";
        cout<<"\t\t5) Update Telephone Number\n";
        cout<<"\t\t6) Delete Telephone Number\n";
        cout<<"\t\t7) Exit\n\n";
        
        cout<<"Select your choice : ";
        cin>>choice;
        switch(choice){
            case 1 : //New Record
                  file.open("phonebk.dat", ios::out | ios::app|ios::binary);
                  rec.getdata();
                  rec.showdata();
                  file.write((char *) &rec, sizeof(rec));
                  file.close();
                  break;

            case 2 : //Display All Records
                  file.open("phonebk.dat", ios::in|ios::binary);
                  char ch,nm[20],telno[6];
                  file.seekg(0,ios::beg);
                  cout<<"\n\nRecords in Phone Book\n\n";
                  while(file.read((char *) &rec, sizeof(rec))){
                        rec.showdata();
                  }
                  file.close();
                  break;

            case 3 : //Search Tel. no. when person's name is known.
                  file.open("phonebk.dat", ios::in|ios::binary);
                  cout<<"\n\nEnter Name of the Person : ";
                  cin>>nm;
                  file.seekg(0,ios::beg);
                  found=0;
                  while(file.read((char *) &rec, sizeof(rec))){
                    if(strcmp(nm,rec.getname())==0){
                        found=1;
                        rec.showdata();
                    }
                  }
                  file.clear();
                  if(found==0)
                     cout<<"\n\tWARNING: Record Not found \n\n";
                  getchar();
                  file.close();
                  break;

            case 4 : //Search name on basis of tel. no
                 file.open("phonebk.dat", ios::in|ios::binary);
                 cout<<"\n\nEnter Telephone Number of the person : ";
                 cin>>telno;
                 file.seekg(0,ios::beg);
                 found=0;
                 while(file.read((char *) &rec, sizeof(rec))){
                    if(strcmp(telno,rec.getphno())==0){
                        found=1;
                        rec.showdata();
                    }
                 }
                 file.clear();
                 if(found==0)
                    cout<<"\n\tWARNING: Record Not found \n\n";
                 getchar();
                 file.close();
                 break;

            case 5 : //Update Telephone No.
                 file.open("phonebk.dat", ios::in|ios::out|ios::binary|ios::ate);
                 cout<<"\n\nEnter Name : ";
                 cin>>nm;
                 file.seekg(0);
                 while(file.read((char *) &rec, sizeof(rec)))
                 {
                    if(strcmp(nm,rec.getname())==0)
                    {
                        cout<<"Enter New Telephone Number"<<endl;
                        cin>>telno;
                        file.seekp(-sizeof(rec),ios::cur);
                        rec.update(nm,telno);
                        file.write((char *) &rec, sizeof(rec));
                    }
                 }
                 file.clear();
                 file.close();
                 break;

            case 6 :{//Delete
                  fstream temp1;
                  temp1.open("tempbk.dat", ios::out|ios::binary|ios::app);
                  file.open("phonebk.dat", ios::in|ios::binary);
                  cout<<"\n\nEnter Name You want to Delete : ";
                  cin>>nm;
                  file.seekg(0);
                  while(1){
                    flag=0;
                    file.read((char *) &rec, sizeof(rec));
                    if(file.eof()) break;
                    if(strcmp(nm,rec.getname())==0){
                      flag++;
                    }
                    if(!flag)
                          temp1.write((char *) &rec, sizeof(rec));
                  }
                  file.close();
                  temp1.close();
                  remove("phonebk.dat");
                  rename("tempbk.dat","2phonebk.dat");
                  break;}

               case 7 : //file.close();
                      exit (0);

             default : std::cout << "\n\t wrong choice !" << '\n';
        }
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

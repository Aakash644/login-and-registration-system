#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string> 
using namespace std; 
int main();
void login(string user,string pass ){ 
    string u,p; 
    int count=0; 
    cout<<"\nWelcome to Login Page"<<endl;
        cout<<"USERNAME :"<<endl;
        cin>>user;
        cout<<"PASSWORD :"<<endl;
        cin>>pass;  
ifstream input;
input.open("database.txt");  
         while(input>>u>>p) {
             
           if(u==user &&p==pass){
                 count=1; 
               break;
             } 
         }
    if(count==1){ 
                  
            printf("\n------------------------------------Login success!--------------------------------------------------");
            cout<<"\nwelcome "<<user<<"!"<<endl;
        } 

        else{ 
           
            printf("\n------------------------------------login failed!--------------------------------------------------\n"); 
            
        
         } 
input.close() ; 

        }
void registr(){  
    string user,pass,x=" ",y="\n";
    cout<<"\nWelcome to registration page"<<endl;
        cout<<"USERNAME :"<<endl;
        cin>>user;
        cout<<"PASSWORD :"<<endl;
        cin>>pass; 
        ofstream output;
        output.open("database.txt",ios::app);  
        
        output<<user<<x<<pass<<y;   
     
        output.close();  
        system("cls");
        cout<<"Registration successful!"<<endl;
}
void forgotbyusername(){   
        string password,user,pass,user1;
        cout<<"\nEnter your password:\n"; 
        cin>>password;
        bool found=false; 
        
        ifstream in;
        in.open("database.txt");
        while(in>>user>>pass){
            if(pass==password){
                found=true;   
                user1=user;
                break;
            }  
        }
            if(found==true){ 
               
                cout<<"Your username is: "<<user1<<endl;
            }
            else{ 
               
                cout<<"Your password did not matched the records!"<<endl;
            }
          
        in.close();
    } 
void forgotbypassword(){   
        string username,user,pass,pass1;
        cout<<"\nEnter your username:\n"; 
        cin>>username;
        bool found=false; 
        
        ifstream in;
        in.open("database.txt");
        while(in>>user>>pass){
            if(user==username){
                found=true; 
                pass1=pass; 
               break;     
            }  
        }
            if(found==true){ 
            
                cout<<"Your password is: "<<pass1<<endl;
            }
            else{ 
               
                cout<<"Your username did not matched the records!"<<endl;
            }
         
        in.close();
    }
void forgot(){ 
    //forgot username 
    
    int choice;
    cout<<("\nWelcome to Forgot page\nchoose a option:\n") ; 
    cout<<"1.Forgot your username"<<endl;  
    cout<<"2.Forgot your Password"<<endl; 
    cin>>choice;
    switch(choice){
        case 1:
        
        forgotbyusername();
        break;
        case 2:
        
        forgotbypassword(); 
        break;
        default:
        cout<<"invalid option\n"<<endl;
        break;
    }

}
int main(){ 

 string username,password;  

 int choice; 
  
cout<<"------------------------------------Welcome to student portal-----------------------------------------------------\n\n";
top: 

 cout<<"----------------------------------------Enter your choice---------------------------------------------------------\n";
 cout<<"\n1.Login"<<endl;
 cout<<"2.registration"<<endl;
 cout<<"3.forgot username or password"<<endl; 
 cout<<"4.EXIT"<<endl; 
 cout<<"\nEnter your choice:"<<endl;
 cin>>choice;  

 
switch(choice){
    case 1: 
    login(username,password);
    goto top;
    break;
    case 2:
    registr(); 
    goto top;
    break;
    case 3: 
    forgot(); 
    goto top;
    break;
    case 4:
    cout<<"Have a nice day!"; 
    break;
    
    default :
    cout<<"Invalid input"<<endl; 
    goto top;
    break;
} 
return 0;
}

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
    int a,i=0;
    string text ,old,password1,password2,pass,name,password0,age,user,word,word1;
    string creds[2],cp[2];

    cout<<"   Security system"<<endl;

    cout<<"_____________________________"<<endl<<endl;
    cout<<"|       1.Register          |"<<endl;
    cout<<"|       2.Login             |"<<endl;
    cout<<"|       3.Change password   |"<<endl;
    cout<<"|_______4.End Program_______|"<<endl<<endl;

   do{
    cout<<endl<<endl;
    cout<<"Enter your choice:-";
    cin>>a;
    switch(a)
    {

        case 1:{
            cout<<"|____________________________|"<<endl<<endl;
            cout<<"|----------Register----------|"<<endl;
            cout<<"|____________________________|"<<endl<<endl;
            cout<<"please enter username:-";
            cin>>name;
            cout<<"please enter the password:-";
            cin>>password0;
            cout<<"please enter your address:-";
            cin>>age;
            

            ofstream of1;
            of1.open("file.txt");
            if(of1.is_open()){
                of1<<name<<"\n";
                of1<<password0;
                cout<<"Registration successfull"<<endl;
            }



            break;
        }
        case 2:{
        i=0;
        cout<<"______________________________"<<endl<<endl;
        cout<<"|----------Login-------------|"<<endl;
        cout<<"|____________________________|"<<endl<<endl;

        ifstream of2;
        of2.open("file.txt");
        cout<<"please enter the username:-";
        cin>>user;
        cout<<"please enter the password:-";
        cin>>pass;

        if (of2.is_open())
        {
            while(!of2.eof())
            {
                while(getline(of2,text)){
                    istringstream iss(text);
                    iss>>word;
                    creds[i]=word;
                    i++;
                }
                if(user==creds[0]&&pass==creds[1])

            {
                cout<<"----log in successfull----";
                cout<<endl<<endl;

                cout<<"details:"<<endl;

                cout<<"username:"+name<<endl;
                cout<<"password:"+pass<<endl;
                cout<<"Age:"+age<<endl;

            }

            else{
                cout<<endl<<endl;
                cout<<"Incorrect credential"<<endl;
                cout<<"|     1.press 2 for login           |"<<endl;
                cout<<"|     2.press 3 to change password  |"<<endl;
                break;
            }

          }
        }

            break;
        }
        case 3:{
            i=0;
            cout<<"----------------------!!!!!! CHANGE PASSWORD !!!!!!!-----------------------"<<endl;

            ifstream of0;
            of0.open("file.txt");
            cout<<"Enter the old password:-";
            cin>>old;
            if(of0.eof())
            {
                while(of0.eof())
                {
                    while(getline(of0,text)){
                        istringstream iss(text);
                        iss>>word;
                        cp[i]=word;
                        i++;
                    }
                    if(old==cp[1])
                    {
                        of0.close();
                        
                        ofstream of1;
                        if(of1.is_open())
                        {
                            cout<<"enter your new passwords :-";
                            cin>>password1;
                            cout<<"Enter your password again:-";
                            cin>>password2;

                            if(password1==password2)
                            {
                                of1<<cp[0]<<"\n";
                                of1<<password1;
                                cout<<"password change sucessfully"<<endl;

                            }
                            else{
                                of1<<cp[0]<<"\n";
                                of1<<old;
                                cout<<"password do not match"<<endl;
                            }
                        }
                    }
                    else{
                        cout<<"please enter a valid password"<<endl;
                        break;
                    }
                }
            }
            break;
               }
             case 4:
            {
             cout<<"____________Thankyou!__________";
             
                break;
                
                                    }

                    default:
                    cout<<"enter a valid choice";

                }
                   
            }
while(a!=4);
return 0;

   }

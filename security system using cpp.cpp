#include<iostream>
#include<fstream>//file handling operations
#include<sstream>//enables operations between string buffers and string objects
#include<string>

using namespace std;

int main(){
	int a,i=0;
	string text,old,password1,password2,pass,name,password0,age,user,word,word1;
	string creds[2],cp[2];
	
	cout<<"                             Security System                            "<<endl;
	cout<<"                       ___________________________                      "<<endl<<endl<<endl;
	
	cout<<"|      1. Register        |"<<endl;
	cout<<"|      2. Login           |"<<endl;
	cout<<"|      3. Change Password |"<<endl;
	cout<<"|______4. End Program_____|"<<endl<<endl;
	
	
	do{
		cout<<endl<<endl;
		cout<<"Enter your choice:- ";
		cin>>a;
		switch(a){
			
			case(1):{
				cout<<" ___________________________"<<endl;
				cout<<"|__________Register_________|"<<endl<<endl;
				cout<<"Please Enter Username:- ";
				cin>>name;
				cout<<"Please Enter the Password:- ";
				cin>>password0;
				cout<<"Please Enter your Age:- ";
				cin>>age;
				
				ofstream of1;//use file for writing purpose therefore we use ofstream
				of1.open("file.txt");
				if(of1.is_open()){
					of1<<name<<"\n";
					of1<<password0<<"\n";
					cout<<"Registration Successful"<<endl;
				}
				break;
			}
			
			case(2):{
				
				i=0;
				
				cout<<" ____________________________"<<endl;
				cout<<" |___________Login___________|"<<endl<<endl;
				
				
				ifstream of2;//use to open and read from file
				of2.open("file.txt");
				cout<<"Please Enter the Username:- ";
				cin>>user;
				cout<<"Please Enter the Password:- ";
				cin>>pass;
				
				if(of2.is_open()){
					while(!of2.eof())//eof-end of file function.
					{
						while(getline(of2,text))/*used to read the file line-by-line*/{
							istringstream iss(text);//used to stream the string and store it using the extraction operator
							iss>>word;
							creds[i]=word;
							i++;
							
							
						}
						
						if(user==creds[0]  && pass==creds[1]){
							cout<<"----Login Successful----"<<endl<<endl;
							
							
							
							cout<<"Details: "<<endl;
							
							cout<<"Username:- "<<name<<endl;
							cout<<"Password:- "<<pass<<endl;
							cout<<"Age:- "<<age<<endl;
						}
						
						
						
						else{
							cout<<endl<<endl;
							cout<<"Incorrect Credentials.\n";
							cout<<"|    1.Press 2 to Login            |"<<endl;
							cout<<"|    2.Press 3 to Change Password  |"<<endl;
							break;
						}
					}
				}
				break;
			}
			
			case(3):{
				i=0;
				
				cout<<"_____________Change Password_____________"<<endl;
				ifstream of0;
				of0.open("file.txt");
				cout<<"Enter the old Password:- ";
				cin>>old;
				if(of0.is_open())
				{
					while(!of0.eof())
					{
						while(getline(of0,text)){
							istringstream iss(text);
						iss>>word1;
						cp[i]=word1;
						i++;
						}
						
					}
					
					if(old==cp[1])
					{
						of0.close();
						
						ofstream of1;
						if(of1.is_open())
						{
							cout<<"Enter your new password:- ";
							cin>>password1;
							cout<<"Enter you password again:- ";
							cin>>password2;
							
							if(password1==password2)
							{
								of1<<cp[0]<<"\n";
								of1<<password1;
								cout<<"   Password Changed Successfully   "<<endl;
							}
							
							else{
								of1<<cp[0]<<"\n";
								of1<<old;
								cout<<"Password doesn't match."<<endl;
								
							}
						}
					}
					}
					
					
					else{
						cout<<"Please enter a valid password"<<endl;
						break;
					}
				}
					
			case 4:{
						cout<<"____________________Thankyou so much!_____________________"<<endl;
						
						break;
					}
					
					default:
						cout<<"Enter a valid choice";
				}
				
				
			}while(a!=4);
	
	return 0;
}

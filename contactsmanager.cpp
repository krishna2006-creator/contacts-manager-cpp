#include<iostream>
#include<vector>
#include <cctype>
using namespace std;
int j=0;
struct contacts{
	string name;
  string number;
};
vector<contacts*>children;
void add_contacts();
void deletephonenumber();
void searchpn();
void display();
contacts *insert(string name,string number){
contacts *newnode=new contacts();
newnode->name=name;
newnode->number=number;
return newnode;
}
void deletephonenumber(){
	if(children.empty()){
		cout<<"there is no contacts in the contacts manager"<<endl; 
	}
	cout<<"enter name or number to delete the contact"<<endl;
	string name;
	string number;
      long long	int choice=0;
	do{
	cout<<"choose 1.name or 2.number or 3.exit"<<endl;
	cin>>choice;
		if(choice==1){
		cout<<"enter the name to delete"<<endl;
		cin.ignore();
		getline(cin,name);
		for(auto it=children.begin();it!=children.end();it++){
			contacts *node=*it;
			if(node->name==name){
				cout<<"phone number is deleting"<<endl;
				cout<<node->name<<endl;
				cout<<node->number<<endl;
                          children.erase(it);
			  delete node;
			  break;
			}
		}
	}
	else if(choice==2){
		cout<<"enter the number to delete"<<endl;
		cin.ignore();
		getline(cin,number);
		for(auto it=children.begin();it!=children.end();it++){
			contacts *node=*it;
			if(node->number==number){
                                cout<<"phone number is deleting"<<endl;
				cout<<node->name<<endl;
				cout<<node->number<<endl;
				children.erase(it);
				delete node;
				break;
			}
		}
	}
	}while(choice!=3);
}
void searchpn(){
if(children.empty()){
	cout<<"there is no contacts in the contacts manager"<<endl;
}
int choice=0;
string name="";
string number="";
do{
	cout<<"enter the choice to search the contacts in the contacts"<<endl;
	cout<<"1.by name"<<endl;
	cout<<"2.by number"<<endl;
	cin>>choice;
	if(choice==1){
		cout<<"enter the name to search"<<endl;
		cin.ignore();
		getline(cin,name);
		for(auto it=children.begin();it!=children.end();it++){
			contacts *result=*it;
			if(result->name==name){
				cout<<"the contact found "<<endl;
				cout<<result->name<<endl;
				cout<<result->number<<endl;
				break;
			}
        	}
             }
	else if(choice==2){
		cout<<"enter the number to search"<<endl;
		cin.ignore();
		getline(cin,number);
		for(auto it=children.begin();it!=children.end();it++){
			contacts *result=*it;
			if(result->number==number){
				cout<<"the contact found"<<endl;
				cout<<result->name<<endl;
				cout<<result->number<<endl;
				break;
			}
	}
}
}while(choice!=3);
}
int main(){
	int choice=0;
 do{
	 cout<<"********************"<<endl;
	 cout<<"contacts manager"<<endl;
	 cout<<"1.add_contacts"<<endl;
	 cout<<"2.displaythecontacts"<<endl;
	 cout<<"3.searchpn"<<endl;
	 cout<<"4.deletephonenumber"<<endl;
	 cout<<"5.exit"<<endl;
	 cout<<"enter the choice"<<endl;
	 cin>>choice;
	 if(choice==1){
		 add_contacts();
	 }
	 else if(choice==2){
		 display();
	 }
	 else if(choice==3){
		 searchpn();
	 }
	 else if(choice==4)
	{
		deletephonenumber();
	 }
 }while(choice!=5);
  for(auto node : children) {
        delete node;
    }
	return 0;
}
void add_contacts(){
	contacts *node=NULL;
	cout<<"add_contacts page"<<endl;
	cout<<"enter the name of the person"<<endl;
	string name="";
	cin.ignore();
	getline(cin,name);
	cout<<"enter the number of the person"<<endl;
string number;
getline(cin,number);
	int length=number.length();
		cout<<"the number phone length is"<<":"<<length<<endl;
if(length==10){
	node=insert(name,number);
	children.push_back(node);
       j++;
       cout<<"************************************************"<<endl;
       cout<<"the number of contacts are added"<<":"<<j<<endl;
       cout<<"************************************************"<<endl;
}
else{
	cout<<"invalid phone number try again !"<<endl;
}
}
void display(){
	if(children.empty()){
		cout<<"there is no contacts inside the  vector"<<endl;
	}
	else{
		int i=0;
		for(auto it=children.begin();it!=children.end();it++){
			contacts *result=*it;
			i++;
	        cout<<i<<"."<<"Name"<<":"<<result->name<<endl;
		cout<<"Number"<<":"<<result->number<<endl;
		}
}
}

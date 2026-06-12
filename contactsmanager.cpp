#include<iostream>
#include<vector>
using namespace std;
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
}
void searchpn(){
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
	node=insert(name,number);
	children.push_back(node);
       int j=0;
       j++;
       cout<<"************************************************"<<endl;
       cout<<"the number of contacts are added"<<":"<<j<<endl;
       cout<<"************************************************"<<endl;
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
		delete result;
		}
}
}

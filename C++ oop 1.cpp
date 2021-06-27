#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

class human{
	private:
		int age;
		string name;
	public:
		human()
		{
			age=0;
			name="noname";
			cout<<"default constructor"<<endl;
		}
	public:
		human(string inputname)
		{
			name=inputname;
			age=0;
			cout<<"another constructor"<<endl;
		}
		void display()
		{
			cout<<age<<endl<<name<<endl;
		}
		human(int inputage)
		{
			name="noname";
			age=inputage;
			cout<<"another constructor"<<endl;
		}		
};

int main()
{
	human kasun;
	human kasu("fhfhgfhg");
	kasu.display();
	human kas(22);
	kas.display();  
	
	return 0;
}

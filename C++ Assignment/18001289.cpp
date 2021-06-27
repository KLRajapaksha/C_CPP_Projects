#include<iostream>
#include<string>
#include <fstream> 
#include<iterator>
#include<vector>
#include<sstream>
using namespace std;

int objcount=0;

class FlightDetails
{
private:
	string flightnum;
	string DateTime;
	string DeptAir_code; 
	string ArrAir_code; 
	string NoofSeats_Avail[60][3];
public:	
    void setflightnum(string FLno)
    {
    	flightnum=FLno;
	}
	string getflightnum()
    {
    	return this->flightnum;
	}
	
	void setdatetime(string datet)
    {
    	DateTime=datet;
	} 
	string getdatetime()
    {
    	return this->DateTime;
	} 
	
	void setdeptcode(string dept)
    {
    	DeptAir_code=dept;
	} 
	string getdeptcode()
    {
    	return this->DeptAir_code;
	} 
	
	void setarrcode(string arr)
    {
    	ArrAir_code=arr;
	}
	string getarrcode()
    {
    	return this->ArrAir_code;
	}	
	
	void setseats(string arr[60][3],int seatcount)
	{
		int m,n;
		for(m=0;m<seatcount;m++)
		{
			for(n=0;n<3;n++)
			{
				NoofSeats_Avail[m][n]=arr[m][n];
			}
		}
	}
	
	friend int* getseats(FlightDetails flights);
	friend void DisplayseatsOP2(FlightDetails flights2);
	friend FlightDetails DisplayseatsOP3(FlightDetails flights3,string rows,string columns);
	friend string readfile(FlightDetails flightss[],int lines);
	
};

int* getseats(FlightDetails flights)
{
	int Bcount=0,k=0,Ecount=0;
	while(flights.NoofSeats_Avail[k][0]!="")
	{
		if(flights.NoofSeats_Avail[k][1] == "B"){
			string temp1 = flights.NoofSeats_Avail[k][2];
			Bcount = Bcount + temp1.length();
		}
		else if(flights.NoofSeats_Avail[k][1] == "E"){
			string temp2 = flights.NoofSeats_Avail[k][2];
			Ecount = Ecount + temp2.length();
		}
		k++;
	}

	int* temp2 = new int[2];
	temp2[0] = Bcount;
	temp2[1] = Ecount;
	return temp2;
}

void DisplayseatsOP2(FlightDetails flights2)
{
	int b=0;

   	    while(flights2.NoofSeats_Avail[b][0]!="")
    	{
		cout<<flights2.NoofSeats_Avail[b][0]<<" "<<flights2.NoofSeats_Avail[b][1]<<" "<<flights2.NoofSeats_Avail[b][2]<<endl;
		b++;
    	}

		
}

FlightDetails DisplayseatsOP3(FlightDetails flights3,string rows,string columns)
{
     	int b=0,letter;
     	string seatList;

        
   	    while(flights3.NoofSeats_Avail[b][0]!="")
    	{
    		if(flights3.NoofSeats_Avail[b][0]==rows)
    		{
    			seatList=flights3.NoofSeats_Avail[b][2];
				letter=seatList.find(columns);	
    		    if(letter>=0)
    		    {
    		    	seatList.erase(seatList.begin()+letter);
    		    	flights3.NoofSeats_Avail[b][2]=seatList;
				}
			}
    		
            b++;
    	}
    	
    	
    	return flights3;
		
}




void DisplayAvailableFlights(FlightDetails flights[],int ob)
{
   for(int i=0 ; i<ob ; i++){
       	int * seatDetails = getseats(flights[i]);
		  	cout<<flights[i].getflightnum()<<endl;
		  	cout<<flights[i].getdatetime()<<endl;
		  	cout<<flights[i].getdeptcode()<<endl;
		  	cout<<flights[i].getarrcode()<<endl;        	
       		cout<<*seatDetails<<" B class seats here!"<<endl;
		  	cout<<*(seatDetails+1)<<" E class seats here!"<<endl<<endl;
	   }	
}

//display the number of seats in each flight
int DisplayAvailableFlightsOP2(FlightDetails flights1)
{
 
       	int * seatDetails = getseats(flights1);
     	
       		cout<<*seatDetails<<" B class seats here!"<<endl;
		  	cout<<*(seatDetails+1)<<" E class seats here!"<<endl<<endl;
		  	cout<<*seatDetails+*(seatDetails+1)<<endl;
		  	return *seatDetails+*(seatDetails+1);
}	
string readfile(FlightDetails flightss[],int lines)
{
   int c=0,j=0,k=0;
   string createfile1,createfile2,finalstring;
   for(c=0;c<lines;c++)
   {
	   createfile1=flightss[c].getflightnum()+"\n"+flightss[c].getdatetime()+"\n"+flightss[c].getdeptcode()+"\n"+flightss[c].getarrcode()+"\n";
	   j=0;
	   createfile2="";
	   while(flightss[c].NoofSeats_Avail[j][0]!="")
	   {
	   	createfile2=createfile2+flightss[c].NoofSeats_Avail[j][0]+" "+flightss[c].NoofSeats_Avail[j][1]+" "+flightss[c].NoofSeats_Avail[j][2]+"\n";
	   	j++;
	   }
	   if(c==lines-1){
	   	finalstring=finalstring+createfile1+createfile2;
	   }else{
	   	finalstring=finalstring+createfile1+createfile2+"\n";
	   }

   }
    return finalstring;
}	



	


int main(){
   fstream newfile("flights.dat");
   int i=0,j=0,seatcount=0;
   string fnum,rows,columns,newstring;
   int a=0,counter=0,counter1=0,counter2=0,counter3=0,counter4=0;
   int seatsneeded;
  bool found;

      string read, rowNum, seatClass, column;
      string fno,dt,dept_a_c,arr_a_c,SEATS;
      
        while(getline(newfile,read))
        {
        	getline(newfile,read);
        	getline(newfile,read);
        	getline(newfile,read);
        	while(!read.empty())
		  		getline(newfile, read);
        	
        	objcount++;
        	
		}
		    newfile.close();
		    fstream newfile2("flights.dat");
		
		FlightDetails flights[objcount];
		
        while(getline(newfile2, read)) //read data from file object and put it into string.
	    {
		  	fno=read;
		  	
		  	getline(newfile2,read);
		  	dt=read;
		  	
		  	getline(newfile2,read);
		  	dept_a_c=read;
		  	
		  	getline(newfile2,read);
		  	arr_a_c=read;
		  	
		    flights[i].setflightnum(fno);
			flights[i].setdatetime(dt);
			flights[i].setdeptcode(dept_a_c);
			flights[i].setarrcode(arr_a_c);
		  	getline(newfile2, read);
		  	string array[60][3];
		  	while(!read.empty())
		  	{
		  		
		  		
		  		stringstream word(read);
		  		word>>rowNum;
		  		word>>seatClass;
		  		word>>column;
		  		array[j][0]=rowNum;
		  		array[j][1]=seatClass;
		  		array[j][2]=column;
		  		j++;
		  		seatcount++;
		  		getline(newfile2, read);
		  	}
		  	j=0;
		  	flights[i].setseats(array,seatcount);
		  	 	
	  	i++;
        
        }
        
    
        
      newfile2.close(); //close the file object.
   
   while(1)
   {

        cout << "1.Display available flights " << endl;
        cout << "2.View flight " << endl;
        cout << "3.Seat availability " << endl;
        cout << "4.Seat booking " << endl;
        cout << "5.exit" << endl<<endl;
        int option;
        cout << "Select Option :"<<endl<<endl;
        cin >> option;

            if(option==1)
            {
            	 DisplayAvailableFlights(flights,objcount) ;
			}  

			else if(option==2)
			{
			
			cout<<"Enter flight number:"<<endl<<endl;
			cin>>fnum;
			found=false;
	            for(a=0;a<objcount;a++)
				{ 
	                if(flights[a].getflightnum() ==fnum)
	                {
	                	found=true;
		            cout<<flights[a].getflightnum()<<endl;
				  	cout<<flights[a].getdatetime()<<endl;
				  	cout<<flights[a].getdeptcode()<<endl;
				  	cout<<flights[a].getarrcode()<<endl;  
				  	DisplayseatsOP2(flights[a]);
					DisplayAvailableFlightsOP2(flights[a]); 
					counter++;
				    }
		    
			    }if(found==false){
			    	cout<<"Invalid Entry"<<endl;
				}

				if(counter==0)
				{
				cout<<"wrong entry!"<<endl<<endl;
				}

            }

            else if(option==3)
            {
				cout<<"Enter flight number:"<<endl;
				cin>>fnum;
				found=false;
              
	            while(flights[counter4].getflightnum()!=fnum)
			    {
			    	counter4++;
				}
			
	            for(a=0;a<objcount;a++)
				{ 
	                if(flights[a].getflightnum() ==fnum)
	                {
	                     found=true;
	                     cout<<"Enter number of seats needed:"<<endl;
	                     cin>>seatsneeded;
	               
		               	 if(DisplayAvailableFlightsOP2(flights[counter4])>=seatsneeded)
		               	 {
		               	    DisplayseatsOP2(flights[counter4]);	
						 }
						 else
						 {
						 	cout<<"No enough seats"<<endl;
						 }
		        	}
	

			    }
				if(found==false)
				{
				    cout<<"Invalid Entry"<<endl;
				}
	    
			}

			else if(option==4)
			{
			
				cout<<"Enter flight number:"<<endl;
				cin>>fnum;
				int t;
				for(t=0;t<seatsneeded;t++)
				{
					cout<<"Enter seat ROW:";
					cin>>rows;
					cout<<"Enter seat COLUMN:";
					cin>>columns;
		    	
                    counter1=0;
				    for(a=0;a<objcount;a++)
					{ 
				        if(flights[a].getflightnum() !=fnum)
				        {
							counter1++;
					    }
				    }
				    flights[counter1]=DisplayseatsOP3(flights[counter1],rows,columns);
				}
			}
  
            else if(option==5) 
			   {
			    ofstream myfile;
		        myfile.open("flights.dat");    	
            	newstring=readfile(flights,objcount);
            	myfile << newstring;
            	myfile.close();
                exit(0);
            }
            else
            {
			
            cout << "Invalid grade" << endl;
            exit(0);

            }

       }
   
   
   
   }



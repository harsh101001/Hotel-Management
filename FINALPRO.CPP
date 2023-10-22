#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
class hotel
{       int roomno;
	char roomtype[20];
	char custname[30];
	char addr[50];
	char phn[12];
	char fromdate[25], todate[25];
	public:
	  void typeofroom()
	{	if((roomno>=1)&&(roomno<=10))
		 strcpy(roomtype, "Deluxe");
		 else if((roomno>=11)&&(roomno<=20))
		 strcpy(roomtype, "Executive");
		 else if((roomno>=21)&&(roomno<=30))
		 strcpy(roomtype, "Suit");
	}

	void homemenu();
	void roombook();
	void displayrecord();
	 void roomallot();
	 void editrecord();
	 int check(int);
	 void modifyrecord(int);
	 void deleterec(int);
	 void calcbill();
}H ;
void hotel::homemenu()
{
	   int ch;
	  while(ch!=5)
	{       clrscr();
		cout<<"\n\t\t"<<"*******THE HERITAGE INN*******";
		cout<<"\n\t\t"<<" Your comfort, our passion. ";
		cout<<"\n\n"<<"********************************************************************************";
		cout<<"\n\n\t\t"<<"MAIN MENU";
		cout<<"\n\t\t"<<"1. Book a room";
		cout<<"\n\t\t"<<"2. Display customer record";
		cout<<"\n\t\t"<<"3. Display rooms alloted";
		cout<<"\n\t\t"<<"4. Edit customer record";
		cout<<"\n\t\t"<<"5. Calculate bill of a customer";
		cout<<"\n\t\t"<<"6. Exit";
		cout<<"\n\n"<<" Enter your choice: ";
		cin>>ch;
		switch(ch)
		{      case 1: roombook();
				break;
		       case 2: displayrecord();
				break;
		       case 3: roomallot();
				  break;
		       case 4: editrecord();
				 break;
		       case 5: calcbill();
			       break;
		      case 6: break;
		      default: cout<<"\n"<<" Please enter proper choice";

		}

	    }
 }

 void hotel:: roombook()
 {      clrscr();
       int r, flag;
       ofstream fout("Hotelrec.dat", ios::app);
       cout<<"\n\t\t"<<"CUSTOMER DETAILS";
       cout<<"\n\n\t\t"<<" Enter room number: ";
       cin>>r;
       flag=check(r);
       if(flag)
       cout<<"\n"<<"Could not book the room as it is already booked";
       else
       {    roomno=r;
	    cout<<"\n\n\t\t"<<" Enter name: ";
	    gets(custname);
	    cout<<"\n\n\t\t"<<" Enter address: ";
	    gets(addr);
	    cout<<"\n\n\t\t"<<" Enter contact number: ";
	    cin>>phn;
	    cout<<"\n\n\t\t"<<"Enter check-in date: ";
	    gets(fromdate);
	    cout<<"\n\n\t\t"<<"Enter check-out date: ";
	    gets(todate);
	    typeofroom();
	    fout.write((char*)&H, sizeof(H));
	    cout<<"\n\n"<<" Room is booked";

       }
       getch();
       fout.close();
 }

 void hotel:: displayrecord()
 {         clrscr();
	  ifstream fin("Hotelrec.dat", ios::in|ios::binary);
	  int r, flag=0;
	  cout<<"\n"<<" Enter the room number of the customer: ";
	  cin>>r;
	  while(fin.read((char*)&H, sizeof(H)))
	  {
		if(roomno==r)
		{     cout<<"\n\t\t"<<"CUSTOMER DETAILS";
		      cout<<"\n\t\t"<<"Room number: "<<roomno;
		      cout<<"\n\t\t"<<"Room category: "<<roomtype;
		      cout<<"\n\t\t"<<"Name: "<<custname;
		      cout<<"\n\t\t"<<"Address: "<<addr;
		      cout<<"\n\t\t"<<"Contact number: "<<phn;
		      cout<<"\n\t\t"<<"Check-in date: "<<fromdate;
		      cout<<"\n\t\t"<<"Check-out date: "<<todate;
		      flag=1;
		     break;
		}
	  }
	  if(flag==0)
	  {  cout<<"\n"<<" Room found to be vacant";
	  }
	  getch();
	  fin.close();
 }
 void hotel:: roomallot()
 {     clrscr();
       ifstream fin("Hotelrec.dat", ios::in|ios::binary);
       cout<<"\n\t\t"<<"RECORD OF ROOMS ALLOTED";
       cout<<"\n"<<"*********************************************************************";
	while(fin.read((char*)&H, sizeof(H)))
       {
	      cout<<"\n"<<"Room number: "<<roomno;
	      cout<<"\n"<<"Room category: "<<roomtype;
	      cout<<"\n"<<"Customer name: "<<custname;
	      cout<<"\n"<<"Address: "<<addr;
	      cout<<"\n"<<"Contact number: "<<phn;
	      cout<<"\n"<<"Check-in date:  "<<fromdate;
	      cout<<"\n"<<"Check-out date:  "<<todate;
	      cout<<endl<<endl;
       }
       getch();
       fin.close();
 }
 void hotel:: editrecord()
{    clrscr();
     cout<<"\n\t"<<" EDIT MENU";
     cout<<"\n\n\t"<<"1. Modify customer record";
     cout<<"\n\n\t"<<"2. Delete customer record";
     int choice, r;
     cout<<"\n\n"<<" Enter your choice: ";
     cin>>choice;
     cout<<"\n\n"<<" Enter room number of the customer: ";
     cin>>r;
     switch(choice)
     {   case 1:  modifyrecord(r);
		 break;
	 case 2: deleterec(r);
		 break;
	 default: cout<<"\n"<<"Please enter proper choice";
     }
}
int hotel:: check(int r)
{    int flag=0;
     ifstream fin("Hotelrec.dat", ios::in|ios::binary);
     while(!fin.eof())
   {  fin.read((char*)&H, sizeof(H));
     if(roomno==r)
     {   flag=1;
	  break;
     }
   }
   fin.close();
   return flag;
}
void hotel:: modifyrecord(int r)
{       int flag=0; long pos;
       fstream file("Hotelrec.dat", ios::in|ios::out|ios::binary);
       while(!file.eof())
       { pos=file.tellg();
	 file.read((char*)&H, sizeof(H));
	    if(roomno==r)
	    {  cout<<"\n\n"<<"Enter new record: ";
	       cout<<"\n"<<"Room number: ";
	       cin>>roomno;
	       typeofroom();
	       cout<<"\n"<<"Name: ";
	       gets(custname);
	       cout<<"\n"<<"Phone number: ";
	       cin>>phn;
	       cout<<"\n"<<" Address: ";
	       gets(addr);
	       cout<<"\n"<<"Check-in date: ";
	       gets(fromdate);
	       cout<<"\n"<<"Check-out date: ";
	       gets(todate);
	       file.seekg(pos);
	       file.write((char*)&H, sizeof(H));
	       cout<<"\n\n"<<" Record successfully modified ";
	       flag=1;

	       break;
	    }
       }
       if(flag==0)
       cout<<"\n\n"<<"Room found to be vacant";
       file.close();
}
void hotel:: deleterec(int r)
{        char ch; int flag=0;
	ifstream fin("Hotelrec.dat",ios::in|ios::binary);
	ofstream fout("abc.dat", ios::out|ios::binary);
	while(!fin.eof())
       {   fin.read((char*)&H, sizeof(H));
	  if(roomno==r)
	  { cout<<"\n\n\t"<<"Name: "<<custname;
	    cout<<"\n\n\t"<<"Address: "<<addr;
	    cout<<"\n\n\t"<<"Contact number: "<<phn;
	    cout<<"\n\n\t"<<"Room number: "<<roomno;
	    cout<<"\n\n\t"<<"Room category: "<<roomtype;
	    cout<<"\n\n\t"<<"Check-in date: "<<fromdate;
	    cout<<"\n\n\t"<<"Check-out date: "<<todate;
	    cout<<"\n\n"<<" Are you sure you want to delete this record (y/n)?";
	    cin>>ch;
	    flag=1;
	    if(ch=='n')
	    fout.write((char*)&H, sizeof(H));
	  }
	  else fout.write((char*)&H, sizeof(H));
       }
       fin.close();
       fout.close();
       if(flag==0)
       cout<<"\n"<<" Room number found to be vacant";
       else
       {  remove("Hotelrec.dat");
	  rename("abc.dat", "Hotelrec.dat");
       }
}
void hotel::calcbill()
{ clrscr();	int r, d;
		int amt;
	cout<<"\n\t\t"<<"Enter the room number of the customer:  ";
	cin>>r;
	cout<<"\n\t\t"<<"Enter the number of days stayed:  ";
	cin>>d;
	ifstream fin("Hotelrec.dat", ios::in|ios::binary);
	while(fin.read((char*)&H, sizeof(H)))
	{     if(roomno==r)
	      break;  }
	      if((r>=1)&&(r<=10))
	      amt= d*400;
	      else if((r>=11)&&(r<=20))
	      amt= d*600;
	      else if((r>=21)&&(r<=30))
	      amt= d*900;


		     cout<< "\n\n\t\t"<<"CUSTOMER DETAILS";
		     cout<<"\n\t\t"<<"Room number: "<<r;
		     cout<<"\n\t\t"<<"Room category: "<<roomtype;
		     cout<<"\n\t\t"<<"Name: "<<custname;
		     cout<<"\n\t\t"<<"Address: "<<addr;
		     cout<<"\n\t\t"<<"Contact number: "<<phn;
		     cout<<"\n\t\t"<<"Check-in date: "<<fromdate;
		     cout<<"\n\t\t"<<"Check-out date: "<<todate;
		     cout<<"\n\t\t"<<"Net payable amount: "<<amt;


	fin.close();
}
void main()
{
      H.homemenu();
      getch();
}
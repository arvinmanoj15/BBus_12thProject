#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<stdlib.h>
#include<dos.h>
void process();
void seat(int);
class cstdt//Class to store info abt Coustomer
{
	char Name[25];
	int cid;
	char bldgrp[2];//
	int nbk;//number of bookings made by this coustomer
	char phno[10];//store phone number
	int filenumber;
	char pin[5];
	public:
	void getdata();
	void putdata();
	void idgen(int num)
	{
	    cid = 1000 + num;
	}
	int retcid()
	{
		return(cid);
	}
	char* retbldgrp()
	{
		return(bldgrp);
	}
	void printB();//spcl printing while searching for blood
	char* retpin()
	{
		return(pin);
	}
	int retnbk()
	{
		return(nbk);
	}
	void incrinbk()
	{
		nbk++;
	}
	cstdt()
	{
		//strcpy(pin,NULL);
		pin[5] = '\0';
		strcpy(Name,NULL);
		strcpy(bldgrp,NULL);
		nbk=0;
		cid=0;
	}
};
void cstdt::getdata()
{
	char p;
	clrscr();
	cout<<"Enter your name "<<endl;
	gets(Name);
	cout<<"Your coustomer ID is: "<<cid<<endl;
	cout<<"This is important for your next login."<<endl<<endl;
	cout<<"Enter a pin code of 5 digits "<<endl;

	for(int i=0;i<5;i++)
	{
		pin[i] = ' ';
	}
	pin[5] = '\0';
	cout<<"Enter your pin ";
	for(int j=0;j<5;j++)
	{
	     p=getch();
	     cout<<"*";
	     pin[j]=p;
	}
	cout<<endl;
	cout<<"Enter your blood group "<<endl;
	cin>>bldgrp;
	cout<<endl;
	cout<<"Enter your contact number "<<endl;
	gets(phno);
}
void cstdt::putdata()
{
	clrscr();
	cout<<"Your Profile"<<endl;
	cout<<"Name                : "<<Name<<endl;
	cout<<"Blood Group         : "<<bldgrp<<endl;
	cout<<"Phone Number        : "<<phno<<endl;
	cout<<"No. of times Booked : "<<nbk<<endl;
}
void cstdt::printB()
{
	cout<<"Name         : "<<Name<<endl;
	cout<<"Phone Number : "<<phno<<endl;
}
class Bus
{
	int No;
	int Seat[50];
	char from[25];
	char stops[25][5];
	char to[25];
	public:
	void getdata()
	{
		cout<<"Bus No"<<endl;
		cin>>No;
		cout<<"From"<<endl;
		gets(from);
		cout<<"To "<<endl;
		gets(to);
		cout<<"Enter major 5 stops";
		int j;
		for(j=0;j<5;j++)
		{
			gets(stops[j]);
		}
	}
	Bus()
	{
		No=0;
		strcpy(from,NULL);
		strcpy(to,NULL);
		int i;
		for(i=0;i<50;i++)
		{
			Seat[i]=0;
		}
	}
};
void signup()
{
	cstdt x;
	int n;
	fstream f1;
	f1.open("cst.dat",ios::binary|ios::app);
	f1.seekg(0,ios::end);
	n=f1.tellg()/sizeof(cstdt);
	x.idgen(n);
	x.getdata();
	f1.seekp(0,ios::end);
	f1.write((char*)&x,sizeof(x));
	f1.seekg(0,ios::beg);
	process();
	f1.close();
}
void login()
{
	int f=0,i=0;
	int id;
	char pin[5],p;
	cstdt x;
	cout<<"Enter coustomer ID ";
	cin>>id;
	fstream f1;
	f1.open("cst.dat",ios::binary|ios::in);
	f1.seekg(0,ios::beg);
	f1.seekp(0,ios::beg);
	while(!f1.eof())
	{
		f1.read((char*)&x,sizeof(x));
		if(id==x.retcid())
			f=1;
	}
	if(f==1)
	{
		do
		{
			for(int i=0;i<5;i++)
			{
				pin[i] = ' ';
			}
			cout<<"Enter your pin ";
			for(int j=0;j<5;j++)
			{
			     p=getch();
			     cout<<"*";
			     pin[j]=p;

			}
			if(strcmpi(pin,x.retpin())==0)
			{
				process();
				i=1;
			}
			else
			{
				cout<<"Pin doesn't match "<<endl;
				cout<<"Select        1.Reenter    2.Escape";
				int a;
				cin>>a;
				if(a==2)
				break;
			}
		}while(i!=1);
	}
	else if(f==0)
	{
		cout<<"No profile found with this ID ";
	}
	f1.close();
}
void process()
{
	cleardevice();
	int gdriver=DETECT,gmode,n,s;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	setbkcolor(2);
	setcolor(4);
	settextstyle(4,0,7);
	outtextxy(100,100,"1.Book My Seat");
	outtextxy(100,200,"2.Exit");
	gotoxy(75,25);
	cin>>n;
	switch(n)
	{
	case 1:
		clrscr();
		setbkcolor(7);
		setcolor(4);
		settextstyle(4,0,7);
		outtextxy(100,200,"Enter no of seats ");
		gotoxy(50,20);
		cin>>s;
		seat(s);
		break;
	case 2:
		break;
	}
	closegraph();
}


//void BloodBank()
//void Ticket();
void movingbus()
{
	int gdriver = DETECT, gmode, errorcode;
	int i;
	initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
	for(i=0;i<450;i++)
	{
		cleardevice();
		setbkcolor(15);
		setcolor(1);
		line(30+i,100,110+i,100);
		line(110+i,100,130+i,120);
		line(130+i,120,130+i,150);
		line(30+i,150,50+i,150);
		line(60+i,150,100+i,150);
		line(110+i,150,130+i,150);
		line(30+i,100,30+i,150);
		line(30+i,105,114+i,105);
		line(30+i,115,124+i,115);
		circle(55+i,150,5);	// Back tyres of bus
		circle(55+i,150,2);
		circle(105+i,150,5);    // Front tyres of bus
		circle(105+i,150,2);
		setcolor(4);
		outtextxy(35+i,130, "   B-BUS");
		delay(5);
	}
	setcolor(15);
	outtextxy(400,400,"Press Any Key");
	getch();
	closegraph();
}
void seat(int s)
{
	int gdriver=DETECT,gmode,n;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	setbkcolor(3);
	setcolor(5);
	for(int i=0;i<10;i++)
	{
		rectangle(60,90+(30*i)+(5*i),95,120+(30*i)+(5*i));
		rectangle(100,90+(30*i)+(5*i),135,120+(30*i)+(5*i));
		rectangle(140,90+(30*i)+(5*i),175,120+(30*i)+(5*i));
		rectangle(220,90+(30*i)+(5*i),255,120+(30*i)+(5*i));
		rectangle(260,90+(30*i)+(5*i),295,120+(30*i)+(5*i));
	}
	settextstyle(0,0,2);
	setcolor(4);
	outtextxy(300,100,"Enter seat Number");
	for(i=0;i<s;i++)
	{
		setcolor(4);
		gotoxy(40,8+i);
		cin>>n;
	}
	getch();
	closegraph();
}
int Dis(cstdt x,int MTB)//to calculate discound percentage
{
	while(MTB<10)
	{
		int n;
		n=x.retnbk();
		if(n>=25)
			return(15);
		else if(n>=20)
			return(10);
		else if(n>=15)
			return(9);
		else if(n>=10)
			return(7);
		else if(n>=5)
			return(5);
	}
	return(MTB);
}
void main()
{
	movingbus();
	int gdriver=DETECT,gmode,n;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	setbkcolor(15);
	settextstyle(4,0,12);
	setcolor(1);
	outtextxy(120,150,"B-BUS");
	settextstyle(2,0,5);
	setcolor(4);
	outtextxy(400,400,"Press any key");
	getch();
	closegraph();
	clrscr();
	do
	{
		initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
		setbkcolor(15);
		settextstyle(4,0,8);
		setcolor(8);
		outtextxy(100,100,"1. LOGIN ");
		outtextxy(100,200,"2. SIGNUP ");
		outtextxy(100,300,"3. QUIT ");
		settextstyle(2,0,5);
		setcolor(2);
		outtextxy(400,400,"Select your Preference");
		gotoxy(75,25);
		cin>>n;
		closegraph();
		initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
		switch(n)
		{
		case 1:
			setbkcolor(12);
			login();
			break;
		case 2:
			setbkcolor(12);
			signup();
			break;
		case 3:
			break;
		}
		getch();
	}while(n!=3);
	closegraph();
}

#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
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
void main()
{
	fstream f;
	f.open("Bus.dat",ios::binary|ios::app);
	Bus x;
	x.getdata();
	f.write((char*)&x,sizeof(Bus));
}

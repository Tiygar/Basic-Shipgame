#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;
/* run this program using the console pauser or add columnsour own getch, scolumnsstem("pause") or input loop */
const int rows=10, columns=10, altrows=10, altcolumns=10;
int i, j, mesa[rows][columns], x, y, s, altmesa[altrows][altcolumns];//
int ms=(rows+columns)/2;//maxships
void clc()
{
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			mesa[i][j]=48;
		}
	}
}
void showmesa()
{
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		cout<<(char)mesa[i][j]<<" ";
		cout<<endl;
	}
	
}
void setjuego()
{
	s=0;//ships
	while(s<ms)
	{	
		x=rand() % rows;
		y=rand() % columns;
		if(mesa[x][y]==48)
		{
			mesa[x][y]=86;
			s++;	
		}
		
	}
	//cout<<"game set x="<<x<<" y="<<y<<endl;
}
int ataque(int x, int y)
{
	if(mesa[x][y]==86)
	{
		mesa[x][y]=88;
		s--;
		return 1;
	}
	else
	return 0;
}
void altclc()//alternative mesa create
{
	for(i=0;i<altrows;i++)
	{
		for(j=0;j<altcolumns;j++)
		{
			altmesa[i][j]=48;
		}
	}	
}
void setaltmesa(int x,int y)// if atatack is successful
{
	altmesa[x][y]=88;
}
void showaltmesa()
{
	cout<<"-------------------------------\n";
	for(i=0;i<altrows;i++)
	{
		for(j=0;j<altcolumns;j++)
		cout<<(char)altmesa[i][j]<<" ";
		cout<<endl;
	}
}
int main() {
	char get;
	srand(time(NULL));
	clc();
	altclc();
	setjuego();
	int ff=0;
	int f=0;// number of wrong guesses
	int t=0;// number of true guesses
	char ekis='V';
	//showmesa();
	int posx, posy;
	
	cout<<"welcome to ship game, your aim is to hit the hidden ships positions are from 1 to 10\nfor commands type 13\n";
	//cout<<(int)ekis<<endl;
	while(1)
	{
		cout<<"tell the position to attack: "; 
		cin>>posx;
		while(posx==0)
		{
			showaltmesa();
			cout<<"tell the position to attack: "; 
			cin>>posx;			
		}
		while(posx==11)
		{
			cout<<"you tried "<<t+f<<" times\n"<<"hit "<<t<<" times\n"<<"missed "<<f<<" times\n";
			cout<<"tell the position to attack: "; 
			cin>>posx;			
		}
		if(posx==12)
		{
			cout<<"do you really want to ff: (y/n))";
			do{
				if(ff==2)
				cout<<"type y or n: ";
				cin>>ekis;
				if(ekis=='y')
				{
					ff=1;
					break;
				}
				if(ekis=='n')
				{
					ff=0;
					continue;
				}
				else
				ff=2;
			}
			while(ff==2);
			
		}
		if(posx==13)
		{
			cout<<"0 shows the ships that you have hit\n11 shows the times that you have tried\n12 means ff\n";
			continue;	
		}
		if(ff==1)
		break;
		//cout<<posx<<" ";
		cin>>posy;
		//cout<<posy<<endl;
		posx--;
		posy--;
		if(ataque(posx,posy))
		{
			cout<<"success!\n";
			t++;
			setaltmesa(posx, posy);
			showaltmesa();
		}
		else if(ataque(posx,posy)==0)
		cout<<"try again missed\n"; f++;
		if(t==10)
		{
			cout<<"congrats you did it admiral o7\n"; break;
		}
		
	}
	showmesa();
	cout<<"gg";
	if(ff==1)
	cout<<" better luck next time\n";
	system("pause");
	return 0;
}



















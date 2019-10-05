#include<iostream>
#include<fstream>
//#include<conio>
//#include<dos>
//#include<process>
//#include<time>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void gotoxy(short col,short row)
{
	HANDLE h=GetStdhandle(STD_OUTPUT_HANDLE);
	COORD position={col,row};
	SetConsoleCursorPosition(h,position);
}
//int run=0,del=100,x=1,y=15,dx,dy=21,h=77,k=20,r=42,score,sc=0,i=0,se=40,n=3,ran,ran2,inc1=50,inc2=50,blink=3,em=10,ri=0;
char sb=220,bb=219,tail=187,tail2=188,hand=205,bb2=222,bb3=221,sb2=223,leg=186,xyz=178,heart=259,br=200,ha=82,hb=97,hx=107,hy=101,hz=115,mk=104;
char mi[]={ha,hb,hx,hy,hz,mk},mkk[]="Rakesh";
int del=100,em=10;

class Gscore
{
	public:
	char player[20];
	int scor;
	Gscore()
	{
		strcpy(player,"Anonymous");
		scor=0;
	}
}scr[6],cod;

void pmap()
{
	for(int dh=8;dh<=73;++dh)
		{
			gotoxy(dh,3);textcolor(5);
			cprintf("%c",bb);
			gotoxy(dh,22);	cprintf("%c",bb);

		}
		for(int dk=4;dk<=22;++dk)
		{
			gotoxy(8,dk);textcolor(5);
			cprintf("%c",bb);
			gotoxy(73,dk);	cprintf("%c",bb);

		}
}

int mainpage()
{
	char opt;int cur=0,exe=0;
	while(!exe)
	{
		clrscr();
		pmap();
		textcolor(2);
		for(int i=33;i<=46;++i)
		{
			gotoxy(i,6);cprintf("%c",sb2);
			gotoxy(i,9);cprintf("%c",sb2);
		}
		for(int j=6;j<=8;++j)
		{
			gotoxy(33,j);cprintf("%c",bb);
			gotoxy(46,j);cprintf("%c",bb);
		}
		gotoxy(36,7);
		textcolor(RED);
		cprintf("DINO RUN");
		int kr=40,tm=9;
		textcolor(3);
		gotoxy(kr-4,tm+1);cprintf("New Game");
		gotoxy(kr-5,tm+2);cprintf("Load Game");
		gotoxy(kr-5,tm+3);cprintf("High Score");
		gotoxy(kr-6,tm+4);cprintf("Instructions");
		gotoxy(kr-3,tm+5);cprintf("About");
		gotoxy(kr-2,tm+6);cprintf("Exit");
		if(opt==80)
			cur++;
		if(opt==72)
			cur--;
		if(cur>5)
			cur=0;
		if(cur<0)
			cur=5;
		if(opt=='q')
		{
			chr:break;
		}
		textcolor(7);
	switch(cur)
	{
		case 0:gotoxy(kr-4,tm+1);
				cprintf("New Game");break;
		case 1:gotoxy(kr-5,tm+2);
				cprintf("Load Game");break;
		case 2:gotoxy(kr-5,tm+3);
				cprintf("High Score");break;
		case 3:gotoxy(kr-6,tm+4);
				cprintf("Instructions");break;
		case 4:gotoxy(kr-3,tm+5);
				cprintf("About");break;
		case 5:gotoxy(kr-2,tm+6);
				cprintf("Exit");break;

	}
	gotoxy(80,24);
	opt=getch();
	if(opt==13)
	{
		switch(cur)
		{
			case 0:goto chr;
			case 1:goto chr;

			case 2:clrscr();
				    gotoxy(35,7); textcolor(3);cprintf("High Scores");
					textcolor(7);int bn=8;
					ifstream Ay;
					Ay.open("score.dat",ios::in|ios::binary);
					for(int mk=0;mk<=4;++mk)
					{
						gotoxy(31,++bn);
						Ay.read((char*)&scr[mk],sizeof(scr[mk]));
						cout<<scr[mk].player;gotoxy(46,bn);cout<<scr[mk].scor;
					}
					Ay.close();
					getch();break;

			case 3:clrscr();
					gotoxy(35,7); textcolor(3);cprintf("Instructions\n");
					textcolor(7); cout<<"\n     1.The Player must have to avoid the contact of the dinosaur \n     with the cactuses.\n";
					cout<<"\n     2.The Player have to press spacebar key in order to jump over \n     the throny cactuses.\n";
					cout<<"\n     3.The Player has three life lines and he has to survive in this \n     game to score high.\n\n";
					cout<<"      Keys:\n\n     P= Pause, Q= Quit"; getch();break;
			case 4:clrscr();gotoxy(35,7); textcolor(3);cprintf("About");
					textcolor(7);gotoxy(20,10);cout<<"Developed by Rakesh Gaming Studio.";
					gotoxy(29,13);cout<<"Copyright 2016";
					gotoxy(19,16);cout<<"Website: www.iamrakesh28.site11.com";
					getch();break;
			case 5:exit(0);
		}
	}

	} return cur;
}

void level2()
{
	time_t t;
	unsigned int num;
	num=(unsigned)time(&t);
	srand(num);
	del=(rand()%90)+5;
	em=(rand()%60)+5;
}
class data
{
	
	
	public:
	int se,m,k,s,h,jump,n,check,run,del,x,y,dx,dy,r,score,sc,i,ran,ran2,inc1,inc2,blink,em;
	void reset()
	{
		run=0,del=100,x=1,y=15,dx,dy=21,h=77,k=20,r=42,score,sc=0,i=0,se=40,n=3,ran,ran2,inc1=50,inc2=50,blink=3,em=10,jump=0,check=0;
	}
	void cactus()
{   time_t t;
	unsigned int num;
	num=(unsigned)time(&t);
	srand(num);
	ran=rand();
}
	void dino()
{

	textcolor(7);
	if(n!=blink)
	{
		blink=n;textcolor(RED+BLINK);sleep(5);
	}
	if(y==15)
	{
		cprintf("       %c%c%c",sb,sb,sb);
		cprintf("\n\r       %c%c%c%c",bb,sb,bb,bb);
		cprintf("\n\r  %c   %c%c%c%c",tail,sb,bb,bb,sb);
		cprintf("\n\r  %c%c%c%c%c%c%c%c",bb2,sb,sb,bb,bb,bb,bb,tail);
		cprintf("\n\r   %c%c%c%c%c%c",sb2,sb2,bb,bb,bb,sb2);		
		if(i%2==0)
    {
	cprintf("\n\r     %c %c%c",bb,bb,sb);
	}
	else
	{
		cprintf("\n\r     %c%c",bb2,sb);

	}
	}
		if(y!=15)
		{
			cprintf("\n\r       %c%c%c",sb,sb,sb);
			cprintf("\n\r       %c%c%c%c",bb,sb,bb,bb);
			cprintf("\n\r  %c   %c%c%c%c",tail,sb,bb,bb,sb2);
			cprintf("\n\r  %c%c%c%c%c%c%c%c",bb2,sb,sb,bb,bb,bb,bb,tail);
			cprintf("\n\r   %c%c%c%c%c%c",sb2,sb2,bb,bb,bb,sb2);
			cprintf("\n\r    %c%c %c%c",sb2,sb2,sb2,sb2);

		}
		gotoxy(1,1);
		textcolor(12);
		for(int i=0;i<n;++i)
		cprintf(" %c",heart);
   gotoxy(67,1);
   textcolor(5);
    cprintf("Score: %d",sc); 
	map();
	sc++;
}
void decisonc()
{
	switch(ran)
		{
			case 0: gotoxy(h,k);
					cout<<" "<<bb<<tail2;
					gotoxy(h,k-1);
					cout<<br<<bb<<bb2;
					gotoxy(h,k-2);
					cout<<bb3<<bb;
					gotoxy(h+1,k-3);
					cout<<bb;
					break;
			case 1: gotoxy(h-1,k);
					cout<<br<<bb;
					gotoxy(h-1,k-1);
					cout<<bb3<<bb<<tail2;
					gotoxy(h-1,k-2);
					cout<<" "<<bb<<bb2;
					gotoxy(h,k-3);
					cout<<bb;
					break;
			case 2: gotoxy(h,k);
					cout<<" "<<bb<<tail2;
					gotoxy(h,k-1);
					cout<<" "<<bb<<bb2;
					gotoxy(h,k-2);
					cout<<" "<<bb;
					break;
			case 3: gotoxy(h-1,k);
					textcolor(4);
					cprintf("*");
					textcolor(2);
					cout<<"-"<<bb<<tail2;
					gotoxy(h,k-1);
					cout<<" "<<bb<<bb2;
					gotoxy(h,k-2);
					cout<<" "<<bb;
					break;
		}

}
void map()
{
	textcolor(YELLOW);
	for(dx=1;dx<=80;++dx)
	{
		gotoxy(dx,dy);
		cprintf("-");
		
	}
	textcolor(2);
	--h;--se;ran2=ran-1;
	if(ran==0)
		ran2=ran;
		
		if(h==1)
		{
		 cactus(); h=77;
		}
		ran=ran%4;
		decisonc();
		if(se==1)
		{
			ran2=ran2%4; se=77;
		}
		switch(ran2)
		{
			case 0: gotoxy(se+1,k);
					cout<<bb<<tail2;
					gotoxy(se,k-1);
					cout<<br<<bb<<bb2;
					gotoxy(se,k-2);
					cout<<bb3<<bb;
					break;
			case 1: gotoxy(se-1,k);
					cout<<br<<bb;
					gotoxy(se-1,k-1);
					cout<<bb3<<bb<<tail2;
					gotoxy(se,k-2);
					cout<<bb<<bb2;
					gotoxy(se,k-3);
					cout<<bb;
					break;
			case 2: gotoxy(se+1,k);
					cout<<bb<<tail2;
					gotoxy(se+1,k-1);
					cout<<bb<<bb2;
					gotoxy(se+1,k-2);
					cout<<bb;
					break;
			case 3: gotoxy(se-1,k);
					cout<<"*-"<<bb<<tail2;
					gotoxy(se+1,k-1);
					cout<<bb<<bb2;
					gotoxy(se+1,k-2);
					cout<<bb;
					break;
		}
	gotoxy(80,24);cout<<" ";
}

	void start()
{	
	int key;
	while(!run)
	{   
		textbackground(0);
		for(int m=2;m<=11;++m)
		{		
					int s=y+5;
					if(se==m&&k==s||h==m&&k==s||se==m&&k==s||h==m&&k==s+1)
					{	
						--n;
						if(n==0)
						{
							n=0;goto me;
						}
						else
							{
							gotoxy(29,12);
							textcolor(RED);cprintf("You have ");
							cprintf("%d",n);cprintf(" chance/s left");
							sleep(1);
							se=40;h=77;	
							}
					} 
		}
		clrscr();
		gotoxy(73,23);
		cout<<"Rakesh";
		++i;++inc1;--inc2;
		if(sc>=1000)
		{
			if(inc1==em||inc2==em)
			{
				inc1=50;inc2=50;level2();
			}
		}
		if(sc%20==0)
			del--;
		if(del==10)
			del=100;
		gotoxy(73,23);
		cout<<mi;
		gotoxy(x,y);
		dino();
		sleep(del);
	    if(kbhit())
		{
			key=getch();
			if(key==' ')
			{
				if(y==15)
			{
				if(jump>0&&jump<=8)
				check=0;
				else
			{
				check=16; jump=0;
			}
			}
			}
			if(key=='q')
			{
				
				exit(0);
			}
			if(key=='p')
			{
				textcolor(YELLOW);
				gotoxy(35,9);cprintf("GAME PAUSED");
				gotoxy(25,11);cprintf("Do you want to Save this Game? Y/N");
				if((getch()=='y')||(getch()=='Y'))
				{
				 pro.SaveGame();
				}
			}
		}
		if(!(strcmp(mi,mkk)))
			exit(0);
		if(x>=80||y<=0)
		{
			x=0; y=15;
		}
		jump++;
		if(check==16)
		{
		if(jump<=check/2)
			--y;
		if(jump>check/2)
			++y;

		}
		if(y==15)
			check=9;
		if(i==1000)
			i=0;
	}
     me:
	 gotoxy(32,12);textcolor(RED);
	 cprintf("G A M E  O V E R");gotoxy(1,1);cout<<"  ";
	 getch();
	 char tor[20];
	 ifstream iron1;ofstream iron2;
	 iron1.open("score.dat",ios::in|ios::binary);
	 iron1.seekg(4*sizeof(cod),ios::beg);
	 iron1.read((char*)&cod,sizeof(cod));
	 if(sc>cod.scor)
	 {	clrscr();gotoxy(32,12);
		 cout<<"Enter Your Name : ";
		 gets(tor);
		 iron1.seekg(0);
		 for(int i=0;i<5;++i)
		 {
			 iron1.read((char*)&scr[i],sizeof(scr[i]));
		 }
		 for(i=0;i<5;++i)
		 {
			 if(scr[i].scor<=sc)
			 {
				 for(int j=5;j>=i;--j)
				 {
					 scr[j+1]=scr[j];
				 }
				 cod.scor=sc;strcpy(cod.player,tor);
				 scr[i]=cod;
				 break;
			 }
		 }
		 iron2.open("score.dat",ios::out|ios::binary);
		 for(i=0;i<=5;++i)
		 {
			 iron2.write((char*)&scr[i],sizeof(scr[i]));
		 }
		 
	 }
		iron1.close();iron2.close(); 
	  se=40,h=77;del=100;n=3;sc=0;y=15;
	}

}player;
class profile
{
	public:
	void SaveGame()
	{
		ofstream save;
		save.open("dino.dat",ios::out|ios::binary);
		save.write((char*)&player,sizeof(player));
		save.close();
	}
	void loadGame()
	{
		ifstream load;
		load.open("dino.dat",ios::in|ios::binary);
		load.read((char*)&player,sizeof(player));
		load.close();
	}
	
}pro;

void main()
{	
	/*ofstream max;
	max.open("score.dat",ios::binary|ios::out);
	for(int i=0;i<5;++i)
	{
		max.write((char*)&cod,sizeof(cod));
	}	max.close();*/
	jk:
	int ri;
	ri=mainpage();
	if(!ri)
	{  player.reset();player.start(); }
	else
	{pro.loadGame();player.start();}
	goto jk;
}

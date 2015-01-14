#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>

struct player
{
 char name[20];
 int score;
};


void paddle(int &x)
{
 setfillstyle(1,RED);
 bar(x,450,x+40,460);
}

class ball
{
 float x,y;
 public:

 int xt,yt;

 ball()
 {
  x=250;
  y=430;
  int r=random(2);
  if(r==0)
  xt=-1;
  else
   xt=1;
  yt=-1;
 }
 float rety()
 {return y;}
 float retx()
 {return x;}
 void chgx(int X,int Y)
 {x=X;y=Y;}     /*
 int retyt()
 {return yt;}
    */
 void disp()
 {
  circle(x,y,7);
  setfillstyle(1,RED);
  floodfill(x+1,y+1,BLUE);
 }
 void move()
 {
  x+=xt*1.2;
  y+=yt*1.2;
 }

 void left()
 {
  if(x<10 || x>600)
   xt=-xt;
 }
 int down(int X);
};
 int ball::down(int X)
 {

  if(y<10)
   yt=-yt;
  else if((y>=445&&y<=460) && (x>=X && x<=X+40))
   yt=-1;
  else if(y>445)
   return 0;
  return 1;

 }

class level1
{
  int a[15];
 public:

 level1();
 int size()
 {return 15;}

 void rect()
 {
  setfillstyle(8,RED);
  if(a[0]==1)
  {
   bar(90,50,130,70);
   rectangle(90,50,130,70);
  }
  if(a[1]==1)
  {
   bar(130,50,170,70);
   rectangle(130,50,170,70);
  }
  if(a[2]==1)
  {
   bar(170,50,210,70);
   rectangle(170,50,210,70);
  }
  if(a[3]==1)
  {
   bar(210,50,250,70);
   rectangle(210,50,250,70);
  }
  if(a[4]==1)
  {
   bar(250,50,290,70);
   rectangle(250,50,290,70);
  }
  if(a[5]==1)
  {
   bar(290,50,330,70);
   rectangle(290,50,330,70);
  }
  if(a[6]==1)
  {
   bar(330,50,370,70);
   rectangle(330,50,370,70);
  }
  if(a[7]==1)
  {
  bar(370,50,410,70);
  rectangle(370,50,410,70);
  }
  if(a[8]==1)
  {
   bar(410,50,450,70);
   rectangle(410,50,450,70);
  }
  if(a[9]==1)
  {
   bar(450,50,490,70);
   rectangle(450,50,490,70);
  }
  if(a[10]==1)
  {
   bar(180,70,220,90);
   rectangle(180,70,220,90);
  }
  if(a[11]==1)
  {
   bar(220,70,260,90);
   rectangle(220,70,260,90);
  }
  if(a[12]==1)
  {
   bar(260,70,300,90);
   rectangle(260,70,300,90);
  }
  if(a[13]==1)
  {
   bar(300,70,340,90);
   rectangle(300,70,340,90);
  }
  if(a[14]==1)
  {
   bar(340,70,380,90);
   rectangle(340,70,380,90);
  }
 }

 int score();

 void check(int ,int ,int& , int&);

 int reta(int i)
 {return a[i];}
};

void level1::level1()
{
 for(int i=0;i<15;i++)
  a[i]=1;
}

void level1::check(int x,int y,int &xt,int &yt)
{
 int m=90,n=50;
 for(int i=0;i<15;i++,m+=40)
 {
  if(i==10)
   {
    m=180;
    n=70;
   }
  if(a[i])
  {
   if((x>=m && x<=m+40) && (y==50 || y==70 || y==90))
    {
     //sound(500);
    // delay(70);
    // nosound();
     yt=-yt;
     a[i]=0;
    }
   if(y>=n && y<=n+20)
     if(x==m || x==m+40)
    {
     //sound(300);
     //delay(50);
     //nosound();
     xt=-xt;
     a[i]=0;
     break;
    }
  }
 }
}

class level2
{
 int b[20][2];
 public:

 level2();

 void rect();
 void check(int ,int ,int &,int&);
 int reta(int i)
 {return b[i][0];}
 int retb(int i)
 {return b[i][1];}


};
level2::level2()
{
 for(int i=0;i<20;i++)
 {
  b[i][0]=1;
  if(i%2)
   b[i][1]=1;
  else
   b[i][1]=0;
 }
}

void level2::rect()
{
 int m=90,n=50;
 for(int i=0;i<20;i++,n+=30)
 {
  if(i==10)
  {
   m=430;
   n=50;
  }
  if(b[i][0]==1)
  {
   if(b[i][1]==1)
    setfillstyle(1,BLUE);
   else
    setfillstyle(8,RED);
   bar(m,n,m+40,n+20);
   rectangle(m,n,m+40,n+20);
  }
 }
 setfillstyle(1,RED);
}

void level2::check(int x,int y,int &xt,int &yt)
{
 int m=90,n=50;
 for(int i=0;i<20;i++,n+=30)
 {
  if(i==10)
  {
   m=430;
   n=50;
  }
  if(b[i][0])
  {
  if(x>=m && x<=m+40)
   if(y>=n && y<n+20)
   { yt=-yt;
   // sound(500);
   // delay(70);
   // nosound();
    if(b[i][1]==1)
     b[i][1]=0;
    else
     b[i][0]=0;
   }
  if(y>=n && y<=n+20)
   if(x==m || x==m+40)
   {
    //sound(200);
    //delay(70);
    //nosound();
    xt=-xt;
    if(b[i][1]==1)
     b[i][1]=0;
    else
     b[i][0]=0;
    break;
   }
  }
 }
}

void help()
{
 cleardevice();
 setcolor(11);
 setbkcolor(BLACK);
 settextstyle(5,0,7);
 outtextxy(170,20,"HELP");
 settextstyle(3,0,2);
 setcolor(9);
 outtextxy(90,190,"1.Destroy all the bricks using the ball");
 outtextxy(90,220,"2.Use your paddle to deflect the ball");
 outtextxy(90,250,"3.If the ball goes below the paddle, then its...");
 outtextxy(140,280,"...GAME OVER for you");
 getch();
}

int play(int level,ball b,int x)
{
 int a,c,score=0,i;
 level1 l1;
 level2 l2;
 setbkcolor(WHITE);
 setcolor(BLUE);
 setfillstyle(1,RED);
 do
 {
  cleardevice();
  if(level==1)
  {
   l1.rect();
   l1.check(b.retx(),b.rety(),b.xt,b.yt);
  }
  else if(level==2)
  {
   l2.rect();
   l2.check(b.retx(),b.rety(),b.xt,b.yt);
  }
  paddle(x);
  b.disp();
  a=b.down(x);
  b.left();
  b.move();
  if(kbhit())
  {
   c=getch();
   if(c==0)
    c=getch();
   if(c==77)
    x+=20;
   else if(c==75)
    x-=20;
   else if(c=='q')
    exit(1);
  }
  if(level==1)
  delay(0.4);
  else
   delay(1.5);
 }while(a!=0);
 cleardevice();
 if(level==1)
 for(i=0;i<15;i++)
  score+=!l1.reta(i);
 else if(level==2)
  for(i=0;i<20;i++)
   score+=!l2.reta(i);
 return score;
}


void read(char *A,player p)
{
 player S[20];
 ofstream fout(A,ios::binary|ios::app);
 fout.write((char*)&p,sizeof(p));
 fout.close();
}

void disp(char *A)
{
 int i=0;
 ifstream fin(A,ios::binary);
 player s[30];
 cout<<"\n\tNAME\t\tSCORE\n";
 while(fin.read((char*)&s[i],sizeof(s[i++])))
  cout<<"\n\t"<<s[i].name<<"\t\t"<<s[i].score;
 fin.close();
}

void del(char *A)
{
 player S[20],t;
 int i=0,j,k;
 ifstream fin(A,ios::binary);
 ofstream fout("New",ios::binary|ios::noreplace);
 cout<<"\n\tDEL";
 while(fin.read((char*)&S[i],sizeof(S[i])))
 {
  cout<<"\n\t"<<S[i].name<<"\t"<<S[i].score;
  i++;
 }
 cout<<"i: "<<i;
 getch();
 clrscr();
 for(j=0;j<i;j++)
  cout<<S[j].name<<"  "<<S[j].score<<'\n';
 getch();
 for(j=0;j<i-1;j++)
  for(k=0;k<i-1-j;k++)
   if(S[k].score<S[k+1].score)
   {
    t=S[k];
    S[k]=S[k+1];
    S[k+1]=t;
   }
 cout<<"\n\nSorted array: ";
 for(j=0;j<i;j++)
  cout<<"\n"<<S[j].name<<"  "<<S[j].score;

 for(j=0;j<5 && j<i;j++)
  fout.write((char*)&S[j],sizeof(player));
 fout.close();
 fin.close();
 remove(A);
 rename("NEW",A);
 cout<<"\nEND";
 for(j=0;j<=i;j++)
  cout<<S[j].name<<"  "<<S[j].score<<'\n';
 getch();
}

void modify(char *A,player p)
{
 fstream f(A,ios::binary|ios::out|ios::in);
 player S;
 long int a;
 cout<<"\n\t\tMODIFYING!!!!!!      "<<A;
 cout<<p.name<<"    "<<p.score;
 getch();

 while(f.read((char*)&S,sizeof(S)))
  if(strcmpi(S.name,p.name)==0)
   {
    strcpy(S.name,p.name);
    S.score=p.score;
    cout<<"\nModifying:::::::::\a\a\a\a"<<sizeof(S);
    delay(5000);
    a=f.tellp();
    a-=sizeof(S);
    f.seekg(a,ios::beg);
    f.write((char *)&p,sizeof(p));
   }
 f.close();
}


void main()
{
 int gd=DETECT,gm,x=250,c,ch,i,k,y,score,a,flag=0,xm,ym;
 char cho;
 ball b;
 player p,S;
 ifstream fin("hscore.dat",ios::binary);

 p.score=0;

 clrscr();

 cout<<"\n\t\t\t\tBRICK BREAKER";
 cout<<"\nEnter your name: ";
 gets(p.name);

 while(fin.read((char*)&S,sizeof(S)))
  if(strcmpi(S.name,p.name)==0)
   {
    cout<<S.name<<flag<<"  "<<S.score;
    flag++;
    getch();
    break;
   }
 if(flag!=0)
 {
  cout<<"\nThat name already exists...\nDo you want to overwrite?(Y/N)";
  cin>>cho;
 }
 fin.close();
 cout<<"\Level?";
 cin>>a;

 clrscr();

 initgraph(&gd,&gm,"C:\TC\BGI");

 xm=getmaxx();
 ym=getmaxy();
 setbkcolor(WHITE);
 setcolor(BLUE);
 settextstyle(1,0,4);
 outtextxy(xm/3-15,ym/8,"BRICK BREAKER");
 settextstyle(7,0,2);
 outtextxy(xm/3+40,ym/8+40,"Done By");
 outtextxy(xm/3,ym/8+70,"Laksha Prashanth");
 outtextxy(xm/3+50,ym/8+120,"and");
 outtextxy(xm/3-10,ym/8+170,"Katyayan Mishra");

 outtextxy(xm/4,ym-200,"Your Game is Loading  .  .  .  .");
 delay(10);
 settextstyle(0,0,1);
 for(i=0,k=25;i<200;i++,delay(5+k))
 {
  setcolor(WHITE);
  bar(xm/4-10,ym-105,xm/4+250,ym-40);

  if(i<50)
  {
   k+=0.1;
   setcolor(BLUE);
   outtextxy(xm/4+15,ym-100,"Gathering Files..");
  }
  else if(i<100)
  {
   k+=0.5;
   setcolor(GREEN);
   outtextxy(xm/4+15,ym-100,"Formulating Pixels..");
  }
  else if(i<150)
  {
   k+=1;
   setcolor(YELLOW);
   outtextxy(xm/4+15,ym-100,"Calculating Memory space..");
  }
  else
  {
   if(i==152)
    k=20;
   k+=0.8;
   setcolor(RED);
   outtextxy(xm/4+15,ym-100,"Drawing API and GUI..");
  }
  line(xm/3-20+i,ym/2+100,xm/3-20+i,ym/2+100+20);
 }
 bar(xm/4-10,ym-105,xm/4+250,ym-40);
 outtextxy(xm/4+15,ym-100,"Your game has loaded");

 getch();

 do
 {
 cleardevice();
 setcolor(RED);
 setbkcolor(WHITE);
 settextstyle(7,0,5);
 outtextxy(140,45,"BRICK");
 outtextxy(190,90,"BREAKER");
 settextstyle(3,0,3);
 outtextxy(150,210,"1.PLAY");
 outtextxy(150,230,"2.HELP");
 outtextxy(150,250,"3.HIGH SCORE");
 outtextxy(150,270,"4.EXIT");
 ch=getch();
 cleardevice();

 y=getbkcolor();
 cout<<y;

 if(ch=='2')
  help();

 else if(ch=='1')
 {
  score = play(a,b,x);
  if(score)
  {
   p.score=score;
   cleardevice();
   settextstyle(5,0,4);
   setcolor(BLUE);
   outtextxy(250,90,"!!CONGRATS!!");
   settextstyle(1,0,3);
   outtextxy(150,160,"You Finished level 1");
   outtextxy(150,180,"Get ready for level 2");
   getch();
   x=250;
   b.chgx(250,430);
   score=play(2,b,x);
  }
  p.score+=score;
  getch();
  cout<<"\nName: ";
  puts(p.name);
  cout<<"Score: "<<p.score;
  getch();
  if(cho=='y'||cho=='Y')
   {
    cout<<"\nModifying.....";
    delay(700);
    modify("hscore.dat",p);
   }
  else
   read("hscore.dat",p);
 }
 else if(ch=='3')
 {
 closegraph();
 restorecrtmode();
 clrscr();
 del("hscore.dat");
 disp("hscore.dat");
 getch();
 initgraph(&gd,&gm,"C:/TC/BGI");
 }
 }while(ch!='4');
 closegraph();
 restorecrtmode();
 cout<<"\n\n\n\t\t\t\tTHANK YOU";
 getch();
}
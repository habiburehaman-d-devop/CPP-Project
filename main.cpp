#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
using namespace std;

bool gameOver;
int i,width,j,height,fruitx,fruity,x,y,score,tailx[100],taily[100],ntail;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;

void setup()
{
    gameOver=false;
    dir=STOP;
    width=25;
    height=25;
    x=width/2;
    y=height/2;
    fruitx= rand()% width;
    fruity = rand()% height;
    score=0;
}
void draw()
{
    system("cls");

    for(i=0;i<width+2;i++)
    cout << "_";

    cout<<endl;
    for(i=0;i<height;i++)
    {
        for(j=0;j<=width;j++)
        {
            if(j==0)
            cout<<"|";



            if(j==x && i==y)
                  cout<<"O";

            else if(i==fruitx && j==fruity)
                  cout<<"F";

            else if(j==width)
            cout<<"|";

            else
            {
                int k;
                    bool print=false;
                for(k=0;k<ntail;k++)
                {
                    if(tailx[k]==j&&taily[k]==i)
                    {
                        cout<<"o";
                        print=true;
                    }
                }
                    if(!print)
                    cout<<" ";

            }

        }
        cout<<endl;
    }

        for(i=0;i<width+2;i++)
        cout << "-";
        cout<<endl;
        cout<<"Score:"<<score<<endl;

}

void input()
{
    if(_kbhit())
    {

        switch(_getch())
        {
        case 'a':
            dir=LEFT;
            break;

        case 'd':
            dir=RIGHT;
            break;

        case 'w':
            dir=UP;
            break;

        case 's':
            dir=DOWN;
            break;

        case 'x':
            gameOver=true;
            break;

        default:
                        system("pause");
                        break;
        }
    }
}

void Logic()
{
    int prevx=tailx[0];
    int prevy=taily[0];
    int prev2x,prev2y;
    tailx[0]=x;
    taily[0]=y;
    for(i=1;i<ntail;i++)
    {
        prev2x=tailx[i];
        prev2y=taily[i];
        tailx[i]=prevx;
        taily[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;

    }
        switch(dir)
        {
    case LEFT:
        x--;
        break;

        case RIGHT:
            x++;
            break;

        case UP:
            y--;
            break;

        case DOWN:
            y++;
            break;
        default:

            break;
        }

            if(x>width||x<0||y>height||y<0)
            {
                gameOver=true;
            }
            for(int i=0;i<ntail;i++)
                if(tailx[i]==x&&taily[i]==y)
                gameOver=true;
            if(x==fruity && y==fruitx)
            {
                score += 10;
                fruitx = rand()% width;
                fruity = rand()% height;
                ntail++;


            }

}


int main()
{
    system("pause");
    setup();
    while(!gameOver)
    {
                draw();
                input();
                Logic();

                Sleep(100);
    }

    return 0;
}

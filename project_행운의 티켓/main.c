#include <stdio.h>
#include <string.h> //fgets(���ڿ�)�Լ�
#include <windows.h> //Ű�Է� �Լ� ��
#include <stdlib.h> // rand(),srand �Լ� ���� ���̺귯��
#include <conio.h> //_getch�� ���ԵǾ��ִ� ���
#include <time.h> // time()�Լ� ���� ���̺귯��
#include <mbstring.h> //mbslen()�Լ�
#include <mmsystem.h> //playsound�Լ�

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define ESC 27

int music=0;

int never_num = 0, nerver_money=0, never_lucky_ticket=0;

void investor(void);
void choice(void);
int sub(void);
int thank(void);
void game(int *m);

unsigned short text=0;
unsigned short back=15;

void gotoxy(int x,int y) //gotoxy�Լ�
{
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void setColor(unsigned short text, unsigned short back)
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), text | (back<<4));
}

void esc(int f)
{
    int x=0, y=0;
    char e;
    while(1)
    {
        system("cls");
        gotoxy(x,y);printf("������ �����Ͻðڽ��ϱ�?[ Y or N ] : ");
        re:
        gotoxy(x+37,y);scanf("%c", &e);
        if(e=='Y')
        {
            gotoxy(x,y+1);printf("������ �����մϴ�.....");
            gotoxy(x,y+3);printf("��");Sleep(100);
            gotoxy(x,y+3);printf("����");Sleep(100);
            gotoxy(x,y+3);printf("������");Sleep(100);
            gotoxy(x,y+3);printf("��������");Sleep(100);
            gotoxy(x,y+3);printf("����������");Sleep(100);
            gotoxy(x,y+3);printf("������������");Sleep(100);
            gotoxy(x,y+3);printf("��������������");Sleep(100);
            gotoxy(x,y+3);printf("����������������");Sleep(100);
            gotoxy(x,y+3);printf("������������������");Sleep(100);
            gotoxy(x,y+3);printf("��������������������");Sleep(100);
            gotoxy(x,y+3);printf("����������������������");Sleep(100);
            gotoxy(x,y+3);printf("������������������������");Sleep(100);
            gotoxy(x,y+3);printf("��������������������������");Sleep(100);
            gotoxy(x,y+3);printf("����������������������������");Sleep(100);
            gotoxy(x,y+3);printf("������������������������������");Sleep(100);
            gotoxy(x,y+3);printf("��������������������������������");Sleep(2000);
            gotoxy(x,y+3);printf("����������������������������������������!");Sleep(1000);
            exit(0);
        }
        else if(e=='N')
        {
            if(f==0)
            {
                system("cls");
                investor();
            }

            else if(f==1)
            {
                system("cls");
                return 0;
            }
            else if(f==2)
            {
                system("cls");
                gametwo();
            }
            else if(f==3)
            {
                system("cls");
                loginmain();
            }
        }
        else
        {
            gotoxy(x+37,y);printf("                                                            ");
            goto re;
        }
    }
}

void guji(void)
{
    int x=0;
    int y=2;
    int b;
    int back;

    system("cls");

    setColor(text=2, back);

    gotoxy(x,y-2);printf("Money : %d��", nerver_money);
    gotoxy(x,y-1);printf("lucky ticket : %d��", never_lucky_ticket);

    setColor(text=0, back);

    gotoxy(x,y);printf("Ƽ�Ϻ���!!");
    gotoxy(x,y+1);printf("Ƽ���� �����Ͻðڽ��ϱ�?[1�� 2000��]");
    gotoxy(x,y+2);scanf("%d", &b);

    if(b>=0 && nerver_money>=b*2000)
    {
        never_lucky_ticket+=b;
        nerver_money-=b*2000;
        gotoxy(x,y+4);printf("Ƽ�� %d�� �����Ͽ����ϴ�", b);Sleep(2000);
    }
    else
    {
        gotoxy(x,y+4);printf("���� �����մϴ�");Sleep(2000);
    }

    system("cls");

    gametwo();
}

void maint(void)
{
    re:

    system("color F4");
    char c; //Ű����
    int x=45; //Ÿ��Ʋȭ���� ǥ�õǴ� x��ǥ
    int y=4; //Ÿ��Ʋȭ���� ǥ�õǴ� y��ǥ
    int f=1;

    gotoxy(x-2,y+0);printf("������������������");Sleep(150);
    gotoxy(x-2,y+1);printf("������������������");Sleep(150);
    gotoxy(x-2,y+2);printf("������������������");Sleep(150);
    gotoxy(x-2,y+3);printf("�����                  �����");Sleep(150);
    gotoxy(x-2,y+4);printf("�����                  �����");Sleep(150);
    gotoxy(x-2,y+5);printf("�����                  �����");Sleep(150);
    gotoxy(x-2,y+6);printf("������������������");Sleep(150);
    gotoxy(x-2,y+7);printf("������������������");Sleep(150);
    gotoxy(x-2,y+8);printf("������������������");Sleep(150);

    setColor(text=2, back);

    gotoxy(x+6,y+4);printf("��");Sleep(150);
    gotoxy(x+8,y+4);printf("  ��");Sleep(150);
    gotoxy(x+8,y+4);printf("    ��");Sleep(150);
    gotoxy(x+8,y+4);printf("      ��");Sleep(150);
    gotoxy(x+8,y+4);printf("         ");Sleep(150);
    gotoxy(x+8,y+4);printf("         Ƽ");Sleep(150);
    gotoxy(x+8,y+4);printf("           ��");Sleep(150);
    gotoxy(x+22,y+4);printf("��");Sleep(150);
    gotoxy(x+8,y+4);printf("         Ƽ");Sleep(150);
    gotoxy(x+8,y+4);printf("         ");Sleep(150);
    gotoxy(x+8,y+4);printf("      ��");Sleep(150);
    gotoxy(x+8,y+4);printf("    ��");Sleep(150);
    gotoxy(x+8,y+4);printf("  ��");Sleep(150);
    gotoxy(x+8,y+4);printf("  ����� Ƽ��");Sleep(150);

    setColor(text=0, back);

    gotoxy(x,y+14);printf(" ____________________________");
    gotoxy(x+8,y+16);printf("ENTER : Start");
    gotoxy(x+8,y+17); printf("ESC   : Quit");
    gotoxy(x+1,y+19); printf("[Ű�� �ѹ��� Ŭ���Ͻʽÿ�!!]");

    while(1)
    {
        gotoxy(x-3,y+12);printf("|����������������������������������|");Sleep(100);
        gotoxy(x-3,y+12);printf("|�ܡ�������������������������������|");Sleep(100);
        gotoxy(x-3,y+12);printf("|�ܡܡ�����������������������������|");Sleep(100);
        gotoxy(x-3,y+12);printf("|���ܡܡ���������������������������|");Sleep(100);
        gotoxy(x-3,y+12);printf("|�����ܡܡ�������������������������|");Sleep(100);
        gotoxy(x-3,y+12);printf("|�������ܡܡ�����������������������|");Sleep(100);
        gotoxy(x-3,y+12);printf("|���������ܡܡ���������������������|");Sleep(100);
        gotoxy(x-3,y+12);printf("|�����������ܡܡ�������������������|");Sleep(100);
        gotoxy(x-3,y+12);printf("|�������������ܡܡ�����������������|");Sleep(100);
        gotoxy(x-3,y+12);printf("|���������������ܡܡ���������������|");Sleep(100);
        gotoxy(x-3,y+12);printf("|�����������������ܡܡ�������������|");Sleep(100);
        gotoxy(x-3,y+12);printf("|�������������������ܡܡ�����������|");Sleep(100);
        gotoxy(x-3,y+12);printf("|���������������������ܡܡ���������|");Sleep(100);
        gotoxy(x-3,y+12);printf("|�����������������������ܡܡ�������|");Sleep(100);
        gotoxy(x-3,y+12);printf("|�������������������������ܡܡ�����|");Sleep(100);
        gotoxy(x-3,y+12);printf("|���������������������������ܡܡ���|");Sleep(100);
        gotoxy(x-3,y+12);printf("|�����������������������������ܡܡ�|");Sleep(100);
        gotoxy(x-3,y+12);printf("|�������������������������������ܡ�|");Sleep(100);
        gotoxy(x-3,y+12);printf("|����������������������������������|");Sleep(100);

        if(kbhit()) break; //Ű�Է��� ������ ���ѷ��� ����
    }

    while(1)
    {
        if (_kbhit()) //Ű���� �Է� Ȯ�� (true / false)
        {
            c = _getch(); // Ű input
            switch (c)
            {
                case ESC:
                    esc(f);
                    goto re;
                case ENTER:
                    system("cls");
                    investor();
            }
        }
    }

}

void investor(void)
{
    int x=0;
    int y=0;

    gotoxy(x,y);printf("P");Sleep(100);
    gotoxy(x+1,y);printf("l");Sleep(100);
    gotoxy(x+2,y);printf("e");Sleep(100);
    gotoxy(x+3,y);printf("a");Sleep(100);
    gotoxy(x+4,y);printf("s");Sleep(100);
    gotoxy(x+5,y);printf("e");Sleep(100);
    gotoxy(x+6,y);printf(" ");Sleep(100);
    gotoxy(x+7,y);printf("s");Sleep(100);
    gotoxy(x+8,y);printf("e");Sleep(100);
    gotoxy(x+9,y);printf("l");Sleep(100);
    gotoxy(x+10,y);printf("e");Sleep(100);
    gotoxy(x+11,y);printf("c");Sleep(100);
    gotoxy(x+12,y);printf("t");Sleep(100);
    gotoxy(x+13,y);printf(" ");Sleep(100);
    gotoxy(x+14,y);printf("a");Sleep(100);
    gotoxy(x+15,y);printf("n");Sleep(100);
    gotoxy(x+16,y);printf(" ");Sleep(100);
    gotoxy(x+17,y);printf("i");Sleep(100);
    gotoxy(x+18,y);printf("n");Sleep(100);
    gotoxy(x+19,y);printf("e");Sleep(100);
    gotoxy(x+20,y);printf("s");Sleep(100);
    gotoxy(x+21,y);printf("t");Sleep(100);
    gotoxy(x+22,y);printf("o");Sleep(100);
    gotoxy(x+23,y);printf("r");Sleep(100);
    gotoxy(x+24,y);printf(".");Sleep(100);
    gotoxy(x+25,y);printf(".");Sleep(100);
    gotoxy(x+26,y);printf(".");Sleep(100);
    gotoxy(x+28,y);printf("( EXIT : ESC )");Sleep(100);
    gotoxy(x,y+1);printf("________________________________________________________________________________");
    gotoxy(x+3,y+3);printf("�����");
    gotoxy(x+3,y+4);printf("������ �����ִ� ����");
    gotoxy(x+3,y+5);printf("��ǰ�� ���� �θ� ������");

    choice();
}

void choice(void)
{
    int x=0;
    int y=1;
    char c;
    int cnt=1;
    int select = 0;
    int f=0;

    srand((unsigned int)time(NULL)); // �Ź� �ٸ� �õ尪 ����

    gotoxy(x,y+2);printf("��");

    while(select==0)
    {
        if (_kbhit()) //Ű���� �Է� Ȯ�� (true / false)
        {
            c = _getch(); // Ű input
            switch (c)
            {
                case UP:
                    if(cnt==2)
                    {
                        gotoxy(x,y+3);printf("  ");
                        gotoxy(x,y+2);printf("��");
                        cnt=1;
                    }
                    else if(cnt==3)
                    {
                        gotoxy(x,y+4);printf("  ");
                        gotoxy(x,y+3);printf("��");
                        cnt=2;
                    }
                    break;
                case DOWN:
                    if(cnt==2)
                    {
                        gotoxy(x,y+3);printf("  ");
                        gotoxy(x,y+4);printf("��");
                        cnt=3;
                    }
                    else if(cnt==1)
                    {
                        gotoxy(x,y+2);printf("  ");
                        gotoxy(x,y+3);printf("��");
                        cnt=2;
                    }
                    break;
                case ENTER:
                    select=cnt;
                    break;
                case ESC:
                    esc(f);
            }
        }
    }

    switch(select)
    {
        case 1:
            system("cls");
            gotoxy(x,y-1);printf("�ڳ����(������)��  [���ں�:10000�� ~ 300000��]");
            gotoxy(x,y);printf("________________________________________________________________________________");
            break;
        case 2:
            system("cls");
            gotoxy(x,y-1);printf("�ڻ����� �����ִ� ����(������)��  [���ں�:10000�� ~ 300000��]");
            gotoxy(x,y);printf("________________________________________________________________________________");
            break;
        case 3:
            system("cls");
            gotoxy(x,y-1);printf("�ڸ�ǰ�� ���� �θ� ������(������)��  [���ں�:10000�� ~ 300000��]");
            gotoxy(x,y);printf("________________________________________________________________________________");
            break;
    }

    int givemoney;

    if(select==1)
    {
        gotoxy(x,y+2);printf("����� : ���� ���� �ŷڵ��� ��ġ�� ���غ�!");
    }
    if(select==2)
    {
        gotoxy(x,y+2);printf("������ �����ִ� ���� : ���� ���� �ŷڵ��� ��ġ�� ���غ���.");
    }
    if(select==3)
    {
        gotoxy(x,y+2);printf("��ǰ�� ���� �θ� ������ : ���� ���� �ŷڵ��� ��ġ�� ���غ�!");
    }

    gotoxy(x,y+3);printf("________________________________________________________________________________");
    gotoxy(x+2,y+5);printf("�ŷڵ��� ��ġ�� �Է��ϼ���. (���������� 10�� ���� �Է��ϼ���. ���� : 1~10)");
    gotoxy(x,y+9);printf("________________________________________________________________________________");
    gotoxy(x+0,y+7);printf(": ");

    r:

    fflush(stdin);

    gotoxy(x+2,y+7);scanf("%d", &givemoney);

    if(givemoney<1 || givemoney>10)
    {
        gotoxy(x+2,y+7);printf("!����!                                                                                                         ");Sleep(1500);
        gotoxy(x+2,y+7);printf("      ");
        goto r;
    }

    int money = sub();

    if(select==1)
    {
        gotoxy(x,y+11);printf("����ڿ��� %d���� �޾ҽ��ϴ�!", money);

        if(money==300000)
        {
            gotoxy(x,y+12);printf("(����ڴ� �Ｚ�� ȸ����־����ϴ�!)", money);
        }

        if(money==10000)
        {
            gotoxy(x,y+12);printf("(����ڴ� ���� ������� ����� �ϰ� �����Ͽ����ϴ�!)", money);
        }
    }

    if(select==2)
    {
        gotoxy(x,y+11);printf("������ �����ִ� ���� %d���� �޾ҽ��ϴ�!", money);

        if(money==300000)
        {
            gotoxy(x,y+12);printf("(������ �����ִ� ������ ������ ���ô��־����ϴ�!)", money);
        }

        if(money==10000)
        {
            gotoxy(x,y+12);printf("(������ �����ִ� ������ ��ſ��� �ŷ��ϴ� �������� �����Ͽ����ϴ�!)", money);
        }
    }

    if(select==3)
    {
        gotoxy(x,y+11);printf("��ǰ�� ���� �θ� ������ %d���� �޾ҽ��ϴ�!", money);

        if(money==300000)
        {
            gotoxy(x,y+12);printf("(��ǰ�� ���� �θ� �������� �μ� ���� ��ǰ�̼̽��ϴ�!)", money);
        }

        if(money==10000)
        {
            gotoxy(x,y+12);printf("(��ǰ�� ���� �θ� �������� ����� ���� �ǽ��ϸ� �Ҿ��� �����Ͽ����ϴ�!)", money);
        }
    }

    gotoxy(x,y+14);printf("��������(100�����̳��� �ѱ۷� �Է��Ͻʽÿ�!): ");

    thank();

    int s=thank();

    printf("\n>�������� �߼ۿϷ�!");Sleep(100);

    if (100 <= s)
    {
        printf("\n\n100�ڸ� �ʰ��Ͽ����ϴ�. ������ �������� �����ڰ� �δ��� ������ �β������� �׳� �����Ƚ��ϴ�.");Sleep(2000);
    }
    else if (90 <= s)
    {
        printf("\n\n�����ڰ� ����� ������ �����Ͽ� 10000���� �߰������Ͽ����ϴ�!!");Sleep(2000);
        money+=10000;
    }

    Sleep(1000);

    game(&money);

}

int sub(void)
{
    int money = 0; // ������ ���� ����
	int a=0;
    int b=1;

    for(int i = 1; i <= b; i++)
    {
        money = rand()%4; // ���� ����

        if(money==0)
        {
            b++;
        }

        a = rand()%2;
    }

    if(a==0)
    {
        a=10000;
    }
    if(a==1)
    {
        a=100000;
    }

    money*=a;

    return money;
}

int thank(void){

	unsigned char h[1000];
	int su=0;

	fgets(h, 1000, stdin);

	su=_mbslen(h)-1;

	return su;
}

void game(int *m){
    int t=0;
    int b=1;

    system("cls");

    for(int i = 1; i <= b; i++)
    {
        t = rand()%11; // ���� ����

        if(t<5)
        {
            b++;
        }
    }

    nerver_money=*m;
    never_lucky_ticket=t;

    never_num+=1;
    main();
}

void gametwo()
{
    int x=2;
    int y=0;

    setColor(text=2, back);

    gotoxy(x,y);printf("Money : %d��", nerver_money);
    gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

    setColor(text=0, back);

    gotoxy(x,y+3);printf("| ����                                                                                                        |");
    gotoxy(x,y+4);printf("| �������������� �������������� �������������� �������������� |");
    gotoxy(x,y+5);printf("| ��                      �� ��                      �� ��                      �� ��                      �� |");
    gotoxy(x,y+6);printf("| ��                      �� ��                      �� ��                      �� ��                      �� |");
    gotoxy(x,y+7);printf("| ��                      �� ��                      �� ��                      �� ��                      �� |");
    gotoxy(x,y+8);printf("| ��                      �� ��                      �� ��                      �� ��                      �� |");
    gotoxy(x,y+9);printf("| ��    1. RED or BLACK   �� ��     2. Ȧ or ¦      �� ��    3. ���� ���߱�    �� ��     4. ���� ��Ī     �� |");
    gotoxy(x,y+10);printf("| ��                      �� ��                      �� ��                      �� ��                      �� |");
    gotoxy(x,y+11);printf("| ��                      �� ��                      �� ��                      �� ��                      �� |");
    gotoxy(x,y+12);printf("| ��                      �� ��                      �� ��                      �� ��                      �� |");
    gotoxy(x,y+13);printf("| ��                      �� ��                      �� ��                      �� ��                      �� |");
    gotoxy(x,y+14);printf("| �������������� �������������� �������������� �������������� |");

    y=14;

    gotoxy(x,y+3);printf("| AI����                                                | | ��Ʈ����                   |");
    gotoxy(x,y+4);printf("| �������������� �������������� | | �������������� |");
    gotoxy(x,y+5);printf("| ��                      �� ��                      �� | | ��                      �� |");
    gotoxy(x,y+6);printf("| ��                      �� ��                      �� | | ��                      �� |");
    gotoxy(x,y+7);printf("| ��                      �� ��                      �� | | ��                      �� |");
    gotoxy(x,y+8);printf("| ��                      �� ��                      �� | | ��                      �� |");
    gotoxy(x,y+9);printf("| ��    1. �ֻ��� ����    �� ��    2. ����������     �� | | ��      3. ��Ʈ����     �� |");
    gotoxy(x,y+10);printf("| ��                      �� ��                      �� | | ��                      �� |");
    gotoxy(x,y+11);printf("| ��                      �� ��                      �� | | ��                      �� |");
    gotoxy(x,y+12);printf("| ��                      �� ��                      �� | | ��                      �� |");
    gotoxy(x,y+13);printf("| ��                      �� ��                      �� | | ��                      �� |");
    gotoxy(x,y+14);printf("| �������������� �������������� | | �������������� |");

    y=0;

    if((nerver_money==0 && never_lucky_ticket==0))
    {
        system("cls");

        int x=27;
        int y=10;
        gotoxy(x-27,y-4);printf("�������������������������������������������������������������");
        gotoxy(x,y);printf(" #####     #    #     # ####### ####### #     # ####### ######");
        gotoxy(x,y+1);printf("#     #   # #   ##   ## #       #     # #     # #       #     #");
        gotoxy(x,y+2);printf("#        #   #  # # # # #       #     # #     # #       #     #");
        gotoxy(x,y+3);printf("#  #### #     # #  #  # #####   #     # #     # #####   ######");
        gotoxy(x,y+4);printf("#     # ####### #     # #       #     #  #   #  #       #   #");
        gotoxy(x,y+5);printf("#     # #     # #     # #       #     #   # #   #       #    #");
        gotoxy(x,y+6);printf(" #####  #     # #     # ####### #######    #    ####### #     #");
        gotoxy(x-27,y+10);printf("�������������������������������������������������������������");

        Sleep(2000);

        exit(1);
    }

    games();
}

void games(void)
{
    int x=0;
    int y=0;
    char c;
    int cnt=1;
    int select = 0;
    int f=2;

    gotoxy(x,y+9);printf("��");

    while(select==0)
    {
        if (_kbhit()) //Ű���� �Է� Ȯ�� (true / false)
        {
            c = _getch(); // Ű input
            switch (c)
            {
                case UP:
                    if(cnt==2)
                    {
                        gotoxy(x,y+23);printf("  ");
                        gotoxy(x,y+9);printf("��");
                        cnt=1;
                    }
                    break;
                case DOWN:
                    if(cnt==1)
                    {
                        gotoxy(x,y+9);printf("  ");
                        gotoxy(x,y+23);printf("��");
                        cnt=2;
                    }
                    break;
                case ENTER:
                    select=cnt;
                    break;
                case ESC:
                    esc(f);
            }
        }
    }

    switch(select)
    {
        case 1:
            system("cls");
            game_one();
            break;
        case 2:
            system("cls");
            game_two();
            break;
    }
}


void game_one(void)
{
    int x=2;
    int y=0;

    setColor(text=2, back);

    gotoxy(x,y);printf("Money : %d��", nerver_money);
    gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

    setColor(text=0, back);

    gotoxy(x,y+3);printf("| ����                                                                                                        |");
    gotoxy(x,y+4);printf("| �������������� �������������� �������������� �������������� |");
    gotoxy(x,y+5);printf("| ��                      �� ��                      �� ��                      �� ��                      �� |");
    gotoxy(x,y+6);printf("| ��                      �� ��                      �� ��                      �� ��                      �� |");
    gotoxy(x,y+7);printf("| ��                      �� ��                      �� ��                      �� ��                      �� |");
    gotoxy(x,y+8);printf("| ��                      �� ��                      �� ��                      �� ��                      �� |");
    gotoxy(x,y+9);printf("| ��    1. RED or BLACK   �� ��     2. Ȧ or ¦      �� ��    3. ���� ���߱�    �� ��     4. ���� ��Ī     �� |");
    gotoxy(x,y+10);printf("| ��                      �� ��                      �� ��                      �� ��                      �� |");
    gotoxy(x,y+11);printf("| ��                      �� ��                      �� ��                      �� ��                      �� |");
    gotoxy(x,y+12);printf("| ��                      �� ��                      �� ��                      �� ��                      �� |");
    gotoxy(x,y+13);printf("| ��                      �� ��                      �� ��                      �� ��                      �� |");
    gotoxy(x,y+14);printf("| �������������� �������������� �������������� �������������� |");

    choco();
}

void game_two(void)
{
    int x=2;
    int y=0;

    setColor(text=2, back);

    gotoxy(x,y);printf("Money : %d��", nerver_money);
    gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

    setColor(text=0, back);

    gotoxy(x,y+3);printf("| AI����                                                | | ��Ʈ����                   |");
    gotoxy(x,y+4);printf("| �������������� �������������� | | �������������� |");
    gotoxy(x,y+5);printf("| ��                      �� ��                      �� | | ��                      �� |");
    gotoxy(x,y+6);printf("| ��                      �� ��                      �� | | ��                      �� |");
    gotoxy(x,y+7);printf("| ��                      �� ��                      �� | | ��                      �� |");
    gotoxy(x,y+8);printf("| ��                      �� ��                      �� | | ��                      �� |");
    gotoxy(x,y+9);printf("| ��    1. �ֻ��� ����    �� ��    2. ����������     �� | | ��      3. ��Ʈ����     �� |");
    gotoxy(x,y+10);printf("| ��                      �� ��                      �� | | ��                      �� |");
    gotoxy(x,y+11);printf("| ��                      �� ��                      �� | | ��                      �� |");
    gotoxy(x,y+12);printf("| ��                      �� ��                      �� | | ��                      �� |");
    gotoxy(x,y+13);printf("| ��                      �� ��                      �� | | ��                      �� |");
    gotoxy(x,y+14);printf("| �������������� �������������� | | �������������� |");

    choco2();
}

void choco(void)
{
    int num;
    int x=1;
    int y=1;

    gotoxy(x+1,y+15);printf("���ӹ�ȣ�� �Է��ϼ���... [ �ڷΰ��� : 8 ]");
    gotoxy(x+1,y+16);printf(":");
    gotoxy(x+2,y+16);scanf("%d", &num);

    switch(num)
    {
        case 1:
            system("cls");
            Individualgame1();
            break;
        case 2:
            system("cls");
            Individualgame2();
            break;
        case 3:
            system("cls");
            Individualgame3();
            break;
        case 4:
            system("cls");
            Individualgame4();
            break;
        case 8:
            system("cls");
            gametwo();
            break;
        default:
            if(num!=1 || num!=2 || num!=3)
            {
                gotoxy(x+2,y+16);printf("                                                                                                                         ");
                choco();
            }
    }
}

void choco2(void)
{
    int num;
    int x=1;
    int y=1;

    gotoxy(x+1,y+15);printf("���ӹ�ȣ�� �Է��ϼ���...  [ �ڷΰ��� : 8 ]");
    gotoxy(x+1,y+16);printf(":");
    gotoxy(x+2,y+16);scanf("%d", &num);

    switch(num)
    {
        case 1:
            system("cls");
            AIbattlegame1();
            break;
        case 2:
            system("cls");
            AIbattlegame2();
            break;
        case 3:
            system("cls");
            bitcoin();
            break;
        case 8:
            system("cls");
            gametwo();
            break;
        default:
            if(num!=1 || num!=2 || num!=3)
            {
                gotoxy(x+2,y+16);printf("                                                                                                                         ");
                choco2();
            }
    }
}

void Individualgame1(void)
{
    if(never_lucky_ticket<=0)
    {
        guji();
    }

    never_lucky_ticket-=1;

    int x=0;
    int y=0;

    setColor(text=2, back);

    gotoxy(x,y);printf("Money : %d��", nerver_money);
    gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

    setColor(text=0, back);

    gotoxy(x,y+3);printf("1. RED or BLACK [ ��ġ : +2000�� +Ƽ��3�� | ����ġ : -2000�� -Ƽ��1�� ]");

    char c;
    int cnt=1, select=0;

    gotoxy(x,y+5);printf(" �����ϼ���.");

    gotoxy(x,y+7);printf(" RED  BLACK");

    gotoxy(x+1,y+8);printf("www");

    while(select==0)
    {
        if (_kbhit())
        {
            c = _getch();
            switch (c)
            {
                case RIGHT:
                    gotoxy(x+1,y+8);printf("   ");
                    gotoxy(x+7,y+8);printf("www");
                    cnt=2;
                    break;
                case LEFT:
                    gotoxy(x+7,y+8);printf("   ");
                    gotoxy(x+1,y+8);printf("www");
                    cnt=1;
                    break;
                case ENTER:
                    select=cnt;
                    break;
            }
        }
    }

    int a[2]={4,0}, r;

    r=rand()%2;

    if(r==0) //red
    {
        setColor(text=a[r], back);

        gotoxy(x+6,y+10);printf("�á����������");Sleep(200);
        gotoxy(x+6,y+11);printf("��ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ� ��");Sleep(200);
        gotoxy(x+6,y+12);printf("��� ��������� ��");Sleep(200);
        gotoxy(x+6,y+13);printf("��� ��������� ��");Sleep(200);
        gotoxy(x+6,y+14);printf("��� ��������� ��");Sleep(200);
        gotoxy(x+6,y+15);printf("��� ��������� ��");Sleep(200);
        gotoxy(x+6,y+16);printf("��� ���ˢˢˡ��� ��");Sleep(200);
        gotoxy(x+6,y+17);printf("��� ���ˢˢˡ��� ��");Sleep(200);
        gotoxy(x+6,y+18);printf("��� ���ˢˢˡ��� ��");Sleep(200);
        gotoxy(x+6,y+19);printf("��� ��������� ��");Sleep(200);
        gotoxy(x+6,y+20);printf("��� ��������� ��");Sleep(200);
        gotoxy(x+6,y+21);printf("��� ��������� ��");Sleep(200);
        gotoxy(x+6,y+22);printf("��� ��������� ��");Sleep(200);
        gotoxy(x+6,y+23);printf("��ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ� ��");Sleep(200);
        gotoxy(x+6,y+24);printf("�á����������");Sleep(200);
        gotoxy(x+6,y+25);printf("         -RED-");Sleep(1000);

        setColor(text=0, back);
    }
    if(r==1) //black
    {
        gotoxy(x+6,y+10);printf("�á����������");Sleep(200);
        gotoxy(x+6,y+11);printf("��ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ� ��");Sleep(200);
        gotoxy(x+6,y+12);printf("��� ��������� ��");Sleep(200);
        gotoxy(x+6,y+13);printf("��� ��������� ��");Sleep(200);
        gotoxy(x+6,y+14);printf("��� ��������� ��");Sleep(200);
        gotoxy(x+6,y+15);printf("��� ��������� ��");Sleep(200);
        gotoxy(x+6,y+16);printf("��� ���ˢˢˡ��� ��");Sleep(200);
        gotoxy(x+6,y+17);printf("��� ���ˢˢˡ��� ��");Sleep(200);
        gotoxy(x+6,y+18);printf("��� ���ˢˢˡ��� ��");Sleep(200);
        gotoxy(x+6,y+19);printf("��� ��������� ��");Sleep(200);
        gotoxy(x+6,y+20);printf("��� ��������� ��");Sleep(200);
        gotoxy(x+6,y+21);printf("��� ��������� ��");Sleep(200);
        gotoxy(x+6,y+22);printf("��� ��������� ��");Sleep(200);
        gotoxy(x+6,y+23);printf("��ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ� ��");Sleep(200);
        gotoxy(x+6,y+24);printf("�á����������");Sleep(200);
        gotoxy(x+6,y+25);printf("        -BLACK-");Sleep(1000);
    }

    if(select-1==r)
    {
        setColor(text=2, back);

        gotoxy(x,y+27);printf("��ġ [ +2000�� +Ƽ��3�� ]");Sleep(1000);

        setColor(text=0, back);

        nerver_money+=2000;
        never_lucky_ticket+=3;
    }
    else
    {
        setColor(text=4, back);

        gotoxy(x,y+27);printf("����ġ [ -2000�� -Ƽ��1�� ]");Sleep(1000);

        setColor(text=0, back);

        nerver_money-=2000;
        never_lucky_ticket-=1;
    }

    setColor(text=2, back);

    gotoxy(x,y);printf("Money : %d��  ", nerver_money);
    gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

    setColor(text=0, back);

    char replay;
    gotoxy(x,y+29);printf("�ٽ� �Ͻðڽ��ϱ�[Y or N]:");
    r:
    gotoxy(x+26,y+29);scanf("%c", &replay);

    if(replay=='Y')
    {
        system("cls");
        Individualgame1();
    }
    else if(replay=='N')
    {
        system("cls");
        game_one();
    }
    else
    {
        gotoxy(x+26,y+29);printf("                                                            ");
        goto r;
    }
}

void Individualgame2(void)
{
    if(never_lucky_ticket<=0)
    {
        guji();
    }

    never_lucky_ticket-=1;

    int x=0;
    int y=0;

    setColor(text=2, back);

    gotoxy(x,y);printf("Money : %d��", nerver_money);
    gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

    setColor(text=0, back);

    gotoxy(x,y+3);printf("2. Ȧ or ¦ [ ���߸� +2000�� +Ƽ��2�� �����߸� -1000��");

    int num;
    char c;
    int cnt=1, select=0;

    gotoxy(x,y+5);printf("�����ϼ���.[ Ȧ or ¦ ]");

    gotoxy(x,y+7);printf("Ȧ  ¦");

    gotoxy(x,y+8);printf("��");

    while(select==0)
    {
        if (_kbhit())
        {
            c = _getch();
            switch (c)
            {
                case RIGHT:
                    gotoxy(x,y+8);printf("  ");
                    gotoxy(x+4,y+8);printf("��");
                    cnt=2;
                    break;
                case LEFT:
                    gotoxy(x+4,y+8);printf("  ");
                    gotoxy(x,y+8);printf("��");
                    cnt=1;
                    break;
                case ENTER:
                    select=cnt;
                    break;
            }
        }
    }

    int b=1;

    for(int i = 1; i <= b; i++)
    {
        num=rand()%11;

        if(num==0)
        {
            b++;
        }
    }

    gotoxy(x,y+9);printf("���� ������...");Sleep(1000);
    gotoxy(x,y+9);printf("              ");

    if(num==1)
    {
        gotoxy(x,y+10);printf("   #");Sleep(600);
        gotoxy(x,y+11);printf("  ##");Sleep(600);
        gotoxy(x,y+12);printf(" # #");Sleep(600);
        gotoxy(x,y+13);printf("   #");Sleep(600);
        gotoxy(x,y+14);printf("   #");Sleep(600);
        gotoxy(x,y+15);printf("   #");Sleep(600);
        gotoxy(x,y+16);printf(" #####");Sleep(600);
    }
    if(num==2)
    {
        gotoxy(x,y+10);printf(" #####");Sleep(600);
        gotoxy(x,y+11);printf("#     #");Sleep(600);
        gotoxy(x,y+12);printf("      #");Sleep(600);
        gotoxy(x,y+13);printf(" #####");Sleep(600);
        gotoxy(x,y+14);printf("#");Sleep(600);
        gotoxy(x,y+15);printf("#");Sleep(600);
        gotoxy(x,y+16);printf("#######");Sleep(600);
    }
    if(num==3)
    {
        gotoxy(x,y+10);printf(" #####");Sleep(600);
        gotoxy(x,y+11);printf("#     #");Sleep(600);
        gotoxy(x,y+12);printf("      #");Sleep(600);
        gotoxy(x,y+13);printf(" #####");Sleep(600);
        gotoxy(x,y+14);printf("      #");Sleep(600);
        gotoxy(x,y+15);printf("#     #");Sleep(600);
        gotoxy(x,y+16);printf(" #####");Sleep(600);
    }
    if(num==4)
    {
        gotoxy(x,y+10);printf("   #");Sleep(600);
        gotoxy(x,y+11);printf("  # #");Sleep(600);
        gotoxy(x,y+12);printf(" #  #");Sleep(600);
        gotoxy(x,y+13);printf("#   #");Sleep(600);
        gotoxy(x,y+14);printf("#######");Sleep(600);
        gotoxy(x,y+15);printf("    #");Sleep(600);
        gotoxy(x,y+16);printf("    #");Sleep(600);
    }
    if(num==5)
    {
        gotoxy(x,y+10);printf("#######");Sleep(600);
        gotoxy(x,y+11);printf("#");Sleep(600);
        gotoxy(x,y+12);printf("#");Sleep(600);
        gotoxy(x,y+13);printf(" #####");Sleep(600);
        gotoxy(x,y+14);printf("      #");Sleep(600);
        gotoxy(x,y+15);printf("#     #");Sleep(600);
        gotoxy(x,y+16);printf(" #####");Sleep(600);
    }
    if(num==6)
    {
        gotoxy(x,y+10);printf(" #####");Sleep(600);
        gotoxy(x,y+11);printf("#     #");Sleep(600);
        gotoxy(x,y+12);printf("#");Sleep(600);
        gotoxy(x,y+13);printf("######");Sleep(600);
        gotoxy(x,y+14);printf("#     #");Sleep(600);
        gotoxy(x,y+15);printf("#     #");Sleep(600);
        gotoxy(x,y+16);printf(" #####");Sleep(600);
    }
    if(num==7)
    {
        gotoxy(x,y+10);printf("#######");Sleep(600);
        gotoxy(x,y+11);printf("#     #");Sleep(600);
        gotoxy(x,y+12);printf("     #");Sleep(600);
        gotoxy(x,y+13);printf("    #");Sleep(600);
        gotoxy(x,y+14);printf("   #");Sleep(600);
        gotoxy(x,y+15);printf("   #");Sleep(600);
        gotoxy(x,y+16);printf("   #");Sleep(600);
    }
    if(num==8)
    {
        gotoxy(x,y+10);printf(" #####");Sleep(600);
        gotoxy(x,y+11);printf("#     #");Sleep(600);
        gotoxy(x,y+12);printf("#     #");Sleep(600);
        gotoxy(x,y+13);printf(" #####");Sleep(600);
        gotoxy(x,y+14);printf("#     #");Sleep(600);
        gotoxy(x,y+15);printf("#     #");Sleep(600);
        gotoxy(x,y+16);printf(" #####");Sleep(600);
    }
    if(num==9)
    {
        gotoxy(x,y+10);printf(" #####");Sleep(600);
        gotoxy(x,y+11);printf("#     #");Sleep(600);
        gotoxy(x,y+12);printf("#     #");Sleep(600);
        gotoxy(x,y+13);printf(" ######");Sleep(600);
        gotoxy(x,y+14);printf("      #");Sleep(600);
        gotoxy(x,y+15);printf("#     #");Sleep(600);
        gotoxy(x,y+16);printf(" #####");Sleep(600);
    }
    if(num==10)
    {
        gotoxy(x,y+10);printf("   #     ###");Sleep(600);
        gotoxy(x,y+11);printf("  ##    #   #");Sleep(600);
        gotoxy(x,y+12);printf(" # #   #     #");Sleep(600);
        gotoxy(x,y+13);printf("   #   #     #");Sleep(600);
        gotoxy(x,y+14);printf("   #   #     #");Sleep(600);
        gotoxy(x,y+15);printf("   #    #   #");Sleep(600);
        gotoxy(x,y+16);printf(" #####   ###");Sleep(600);
    }

    if(num%2==0)
    {
        gotoxy(x,y+18);printf("¦�Դϴ�!");Sleep(200);
        if(select==2)
        {
            gotoxy(x,y+20);printf("+2000�� +Ƽ��2��");
            nerver_money+=2000;
            never_lucky_ticket+=2;
        }
        else
        {
            gotoxy(x,y+20);printf("-1000��");
            nerver_money-=2000;
        }
    }
    else
    {
        gotoxy(x,y+18);printf("Ȧ�Դϴ�!");Sleep(200);
        if(select==1)
        {
            gotoxy(x,y+20);printf("+2000�� +Ƽ��2��");
            nerver_money+=2000;
            never_lucky_ticket+=2;
        }
        else
        {
            gotoxy(x,y+20);printf("-1000��");
            nerver_money-=2000;
        }
    }

    setColor(text=2, back);

    gotoxy(x,y);printf("Money : %d��", nerver_money);
    gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

    setColor(text=0, back);

    char replay;
    gotoxy(x,y+22);printf("�ٽ� �Ͻðڽ��ϱ�[Y or N]:");
    r:
    gotoxy(x+26,y+22);scanf("%c", &replay);

    if(replay=='Y')
    {
        system("cls");
        Individualgame2();
    }
    else if(replay=='N')
    {
        system("cls");
        game_one();
    }
    else
    {
        gotoxy(x+26,y+22);printf("                                                            ");
        goto r;
    }
}

void Individualgame3(void)
{
    if(never_lucky_ticket<=0)
    {
        guji();
    }

    never_lucky_ticket-=1;

    int x=0;
    int y=0;

    setColor(text=2, back);

    gotoxy(x,y);printf("Money : %d��", nerver_money);
    gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

    setColor(text=0, back);

    gotoxy(x,y+3);printf("3. ���� ���߱�(=�ζ�)");
    gotoxy(x,y+4);printf("---------------------------------------");
    gotoxy(x,y+5);printf("1�� : 20000��");
    gotoxy(x,y+6);printf("2�� : 15000��");
    gotoxy(x,y+7);printf("3�� : 10000��");
    gotoxy(x,y+8);printf("4�� : 5000��");
    gotoxy(x,y+9);printf("5�� : 1000��");
    gotoxy(x,y+10);printf("6��(�õ�) : 0��");
    gotoxy(x,y+11);printf("---------------------------------------");


    int rotto[7];
    int num[6];
    int yes, u;
    yes=0;
    u=0;

    gotoxy(x,y+13);printf("�ζǹ�ȣ�� �Է��ϼ��� 6�� ����[ 0~20 ]");
    gotoxy(x,y+14);printf(">");
    n:
    gotoxy(x+1,y+14);scanf("%d %d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
    for(int i = 0; i <= 5; i++)
    {
        if(num[i]>20 || num[i]<0)
        {
            gotoxy(x+1,y+14);printf("[ 0~20 ]                                                                                      ");Sleep(2000);
            gotoxy(x+1,y+14);printf("                    ");
            goto n;
        }
    }

    srand((unsigned int)time(NULL)); // �Ź� �ٸ� �õ尪 ����

    gotoxy(x,y+16);printf("�ζǹ�ȣ�̴���..");Sleep(2000);
    gotoxy(x,y+16);printf("                ");
    gotoxy(x,y+16);printf("ROTTO : ");

    int ballcolor[7]={1,4,5,6,10,11,12}, bc, color=0;

    for(int i = 0; i <= 6; i++)
    {
        rotto[i] = rand()%21;

        rbc:

        bc=rand()%7;
        for(int i = 0; i <= 6; i++)
        {
            if(ballcolor[bc]==0)
            {
                goto rbc;
            }
            else
            {
                color=ballcolor[bc];
                ballcolor[bc]=0;
                break;
            }
        }

        setColor(text=color, back);

        printf("%d ", rotto[i]);

        setColor(text=0, back);
    }

    Sleep(1500);

    for(int i = 0; i <= 5; i++)
    {
       for(int j = 0; j <= 6; j++)
       {
           if(j==6)
           {
               if(num[i]==rotto[j])
               {
                   u+=1;
               }
           }
           else
           {
               if(num[i]==rotto[j])
               {
                   yes+=1;
               }
           }
       }
    }

    if (yes==6)
    {
        gotoxy(x,y+18);printf("1�� +20000�� +Ƽ��5��");
        nerver_money+=20000;
        never_lucky_ticket+=5;
    }
    else if (yes==5&&u==1)
    {
        gotoxy(x,y+18);printf("2�� +15000�� +Ƽ��4��");
        nerver_money+=15000;
        never_lucky_ticket+=4;
    }
    else if (yes==5)
    {
        gotoxy(x,y+18);printf("3�� +10000�� +Ƽ��3��");
        nerver_money+=10000;
        never_lucky_ticket+=3;
    }
    else if (yes==4)
    {
        gotoxy(x,y+18);printf("4�� +5000�� +Ƽ��2��");
        nerver_money+=5000;
        never_lucky_ticket+=2;
    }
    else if (yes==3)
    {
        gotoxy(x,y+18);printf("5�� +1000�� +Ƽ��1��");
        nerver_money+=1000;
        never_lucky_ticket+=1;
    }
    else if (yes<=2)
    {
        gotoxy(x,y+18);printf("6��(�õ�)  +Ƽ��1��");
        never_lucky_ticket+=1;
    }

    setColor(text=2, back);

    gotoxy(x,y);printf("Money : %d��", nerver_money);
    gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

    setColor(text=0, back);

    Sleep(1000);

    char replay;
    gotoxy(x,y+20);printf("�ٽ� �Ͻðڽ��ϱ�[Y or N]:");
    r:
    gotoxy(x+26,y+20);scanf("%c", &replay);

    if(replay=='Y')
    {
        system("cls");
        Individualgame3();
    }
    else if(replay=='N')
    {
        system("cls");
        game_one();
    }
    else
    {
        gotoxy(x+26,y+20);printf("                                                            ");
        goto r;
    }
}

void Individualgame4(void)
{
    if(never_lucky_ticket<=0)
    {
        guji();
    }

    never_lucky_ticket-=1;

    int x=0;
    int y=0;

    setColor(text=2, back);

    gotoxy(x,y);printf("Money : %d��", nerver_money);
    gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

    setColor(text=0, back);

    gotoxy(x,y+3);printf("4. ���� ��Ī");

    srand((unsigned int)time(NULL));

    char spin;

    gotoxy(x,y+4);printf("-----------------------------");
    gotoxy(x,y+5);printf("0 0 0 : +Ƽ��8��");
    gotoxy(x,y+6);printf("1 1 1 : +10000�� + Ƽ��2��");
    gotoxy(x,y+7);printf("2 2 2 : +20000�� + Ƽ��2��");
    gotoxy(x,y+8);printf("3 3 3 : +30000�� + Ƽ��2��");
    gotoxy(x,y+9);printf("4 4 4 : +40000�� + Ƽ��2��");
    gotoxy(x,y+10);printf("5 5 5 : +50000�� + Ƽ��2��");
    gotoxy(x,y+11);printf("6 6 6 : +100000�� +Ƽ��3��");
    gotoxy(x,y+11);printf("7 7 7 : +200000�� +Ƽ��5��");
    gotoxy(x,y+12);printf("-----------------------------");

    gotoxy(x,y+14);printf("SPIN�Ͻðڽ��ϱ�?[ Y or N ]");

    gotoxy(x,y+15);printf(":");

    s:
    gotoxy(x+1,y+15);scanf("%c",&spin);

    if(spin=='Y')
    {
        goto start;
    }
    else if(spin=='N')
    {
        system("cls");
        game_one();
    }
    else
    {
        gotoxy(x+1,y+15);printf("                                                            ");
        goto s;
    }

    start:

    y+=4;
    x=0;

    int rs[3], cnt=0;

    for(int k = 0; k <= 4; k+=2)
    {
        rs[cnt] = rand()%8;

        for(int i = 0; i <= 8; i++)
        {
            gotoxy(x=k,y+13);printf("%d", rand()%8);Sleep(400);

            if(i==8)
            {
                setColor(text=2, back);

                gotoxy(x=k,y+13);printf("%d", rs[cnt]);

                setColor(text=0, back);
            }
        }

        cnt+=1;
    }

    x=0;

    if(rs[0]==rs[1])
    {
        if(rs[1]==rs[2])
        {
            switch(rs[0])
            {
                case 0:
                    never_lucky_ticket+=8;
                    gotoxy(x,y+15);printf("+Ƽ��8��");
                    break;
                case 1:
                    never_lucky_ticket+=2;
                    gotoxy(x,y+15);printf("+10000�� +Ƽ��2��");
                    nerver_money+=10000;
                    break;
                case 2:
                    never_lucky_ticket+=2;
                    gotoxy(x,y+15);printf("+20000�� +Ƽ��2��");
                    nerver_money+=20000;
                    break;
                case 3:
                    never_lucky_ticket+=2;
                    gotoxy(x,y+15);printf("+30000�� +Ƽ��2��");
                    nerver_money+=30000;
                    break;
                case 4:
                    never_lucky_ticket+=2;
                    gotoxy(x,y+15);printf("+40000�� +Ƽ��2��");
                    nerver_money+=40000;
                    break;
                case 5:
                    never_lucky_ticket+=2;
                    gotoxy(x,y+15);printf("+50000�� +Ƽ��2��");
                    nerver_money+=50000;
                    break;
                case 6:
                    never_lucky_ticket+=3;
                    gotoxy(x,y+15);printf("+100000�� +Ƽ��3��");
                    nerver_money+=100000;
                    break;
                case 7:
                    never_lucky_ticket+=5;
                    gotoxy(x,y+15);printf("+200000�� +Ƽ��5��");
                    nerver_money+=200000;
                    break;
            }
        }
    }
    else
    {
        never_lucky_ticket+=1;
        gotoxy(x,y+15);printf("+Ƽ��1��");
    }

    x=0;
    y=0;

    setColor(text=2, back);

    gotoxy(x,y);printf("Money : %d��", nerver_money);
    gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

    setColor(text=0, back);

    y+=4;

    char replay;
    gotoxy(x,y+17);printf("�ٽ� �Ͻðڽ��ϱ�[Y or N]:");
    r:
    gotoxy(x+26,y+17);scanf("%c", &replay);

    if(replay=='Y')
    {
        system("cls");
        Individualgame4();
    }
    else if(replay=='N')
    {
        system("cls");
        game_one();
    }
    else
    {
        gotoxy(x+26,y+17);printf("                                                            ");
        goto r;
    }
}

void AIbattlegame1(void)
{
    if(never_lucky_ticket<=0)
    {
        guji();
    }

    never_lucky_ticket-=1;

    int x=0;
    int y=0;
    int t,t2;//�ֻ���
    int b=1;
    int h, h2;//�Է¼�
    int ai, ai2; //bot�� ������ ��

    setColor(text=2, back);

    gotoxy(x,y);printf("Money : %d��", nerver_money);
    gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

    setColor(text=0, back);

    gotoxy(x,y+3);printf("1. �ֻ��� ���� [ ���� -1000�� �̱�� +1000�� & Ƽ�� +2 ]");

    gotoxy(x,y+5);printf("�� ���ڸ� �Է��ϼ��� [ 1 ~ 6 ]");

    rr:
    gotoxy(x,y+6);scanf("%d %d", &h, &h2);

    if(h>6 || h<1 || h2>6 || h2<1)
    {
        gotoxy(x,y+6);printf("                                          ");
        goto rr;
    }

    srand((unsigned int)time(NULL)); // �Ź� �ٸ� �õ尪 ����

    //////////////////////////////////////////[ ai ]
    b=1;
    for(int i = 1; i <= b; i++)
    {
        ai = rand()%11; // ���� ����

        if(ai<1 || ai>6)
        {
            b++;
        }
    }
    gotoxy(x,y+8);printf("ai[%d", ai);
    for(int i = 1; i <= b; i++)
    {
        ai2 = rand()%11; // ���� ����

        if(ai2<1 || ai2>6)
        {
            b++;
        }
    }
    printf(" %d]", ai2);
    //////////////////////////////////////////

    b=1;
    for(int i = 1; i <= b; i++)
    {
        t = rand()%11; // ���� ����

        if(t<1 || t>6)
        {
            b++;
        }
    }

    for(int i = 1; i <= b; i++)
    {
        t2 = rand()%11; // ���� ����

        if(t2<1 || t2>6)
        {
            b++;
        }
    }

    gotoxy(x,y+10);printf("�ֻ��� ������....");Sleep(1000);
    gotoxy(x,y+10);printf("                 ");
    gotoxy(x,y+10);printf("�ֻ���[%d %d]", t, t2);Sleep(1000);

    int cnt=0, aicnt=0;

    if(h==t && h2==t2)
    {
        cnt=4;
    }
    else if(h==t2 && h2==t)
    {
        cnt=3;
    }
    else if(h==h2 && t==h || h==h2 && t==h2 || t==t2 && t==h || t==t2 && t==h2)
    {
        cnt=2;
    }
    else if(h==t)
    {
        cnt=1;
    }
    else if(h==t2)
    {
        cnt=1;
    }
    else if(h2==t2)
    {
        cnt=1;
    }
    else if(h2==t)
    {
        cnt=1;
    }


    ////////////////////////////////////////////////////////////////////////////////ai
    if(ai==t && ai2==t2)
    {
        aicnt=4;
    }
    else if(ai==t2 && ai2==t)
    {
        aicnt=3;
    }
    else if(ai==ai2 && t==ai || ai==ai2 && t==ai2 || t==t2 && t==ai || t==t2 && t==ai2)
    {
        aicnt=2;
    }
    else if(ai==t)
    {
        aicnt=1;
    }
    else if(ai==t2)
    {
        aicnt=1;
    }
    else if(ai2==t2)
    {
        aicnt=1;
    }
    else if(ai2==t)
    {
        aicnt=1;
    }
    ////////////////////////////////////////////////////////////////////////////////

    gotoxy(x,y+12);printf("����");
    gotoxy(x,y+13);printf("you : %d", cnt);
    gotoxy(x,y+14);printf("ai : %d", aicnt);

    if(aicnt>cnt)
    {
        gotoxy(x,y+16);printf("ai�¸�");
        nerver_money-=1000;
    }
    else if(aicnt<cnt)
    {
        gotoxy(x,y+16);printf("you �¸�");
        nerver_money+=1000;
        never_lucky_ticket+=2;
    }
    else
    {
        gotoxy(x,y+16);printf("���º�");
    }

    char replay;
    gotoxy(x,y+17);printf("�ٽ� �Ͻðڽ��ϱ�[Y or N]:");
    r:
    gotoxy(x+26,y+17);scanf("%c", &replay);

    if(replay=='Y')
    {
        system("cls");
        AIbattlegame1();
    }
    else if(replay=='N')
    {
        system("cls");
        game_two();
    }
    else
    {
        gotoxy(x+26,y+17);printf("                                                            ");
        goto r;
    }
}

void AIbattlegame2(void)
{
    if(never_lucky_ticket<=0)
    {
        guji();
    }

    never_lucky_ticket-=1;

    int x=0;
    int y=0;
    int c;
    int cnt=1;
    int select=0;
    int b=0;
    int t; // ai

    srand((unsigned int)time(NULL)); // �Ź� �ٸ� �õ尪 ����

    setColor(text=2, back);

    gotoxy(x,y);printf("Money : %d��", nerver_money);
    gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

    setColor(text=0, back);

    gotoxy(x,y+3);printf("2. ���������� [ ���� -1000�� �̱�� +1000�� & Ƽ�� +2 ]");

    gotoxy(x+2,y+5);printf("����");
    gotoxy(x+10,y+5);printf("����");
    gotoxy(x+18,y+5);printf("���ڱ�");

    gotoxy(x+1,y+5);printf(">");
    gotoxy(x+6,y+5);printf("<");

    b=1;
    for(int i = 1; i <= b; i++)
    {
        t = rand()%4; // ���� ����

        if(t==0)
        {
            b++;
        }
    }

    while(select==0)
    {
        if (_kbhit()) //Ű���� �Է� Ȯ�� (true / false)
        {
            c = _getch(); // Ű input
            switch (c)
            {
                case RIGHT:
                    if(cnt==1)
                    {
                        gotoxy(x+1,y+5);printf(" ");
                        gotoxy(x+6,y+5);printf(" ");
                        gotoxy(x+9,y+5);printf(">");
                        gotoxy(x+14,y+5);printf("<");
                        cnt=2;
                    }
                    else if(cnt==2)
                    {
                        gotoxy(x+9,y+5);printf(" ");
                        gotoxy(x+14,y+5);printf(" ");
                        gotoxy(x+17,y+5);printf(">");
                        gotoxy(x+24,y+5);printf("<");
                        cnt=3;
                    }
                    break;
                case LEFT:
                    if(cnt==2)
                    {
                        gotoxy(x+9,y+5);printf(" ");
                        gotoxy(x+14,y+5);printf(" ");
                        gotoxy(x+1,y+5);printf(">");
                        gotoxy(x+6,y+5);printf("<");
                        cnt=1;
                    }
                    else if(cnt==3)
                    {
                        gotoxy(x+17,y+5);printf(" ");
                        gotoxy(x+24,y+5);printf(" ");
                        gotoxy(x+9,y+5);printf(">");
                        gotoxy(x+14,y+5);printf("<");
                        cnt=2;
                    }
                    break;
                case ENTER:
                    select=cnt;
                    break;
            }
        }
    }

    if(t==1)
    {
        gotoxy(x+0,y+7);printf("AI : ����");
    }
    if(t==2)
    {
        gotoxy(x+0,y+7);printf("AI : ����");
    }
    if(t==3)
    {
        gotoxy(x+0,y+7);printf("AI : ���ڱ�");
    }

    if(select==1)
    {
        gotoxy(x+0,y+8);printf("YOU : ����");
    }
    if(select==2)
    {
        gotoxy(x+0,y+8);printf("YOU : ����");
    }
    if(select==3)
    {
        gotoxy(x+0,y+8);printf("YOU : ���ڱ�");
    }

    if(t==select)
    {
        gotoxy(x+0,y+11);printf("   #         ######  ######     #    #     #");
        gotoxy(x+0,y+12);printf("  # #        #     # #     #   # #   #  #  #");
        gotoxy(x+0,y+13);printf(" #   #       #     # #     #  #   #  #  #  #");
        gotoxy(x+0,y+14);printf("#     #      #     # ######  #     # #  #  #");
        gotoxy(x+0,y+15);printf("#######      #     # #   #   ####### #  #  #");
        gotoxy(x+0,y+16);printf("#     #      #     # #    #  #     # #  #  #");
        gotoxy(x+0,y+17);printf("#     #      ######  #     # #     #  ## ##");
        gotoxy(x+0,y+19);printf(":���º�:");
    }

    if(t==1 && select==3 || t==2 && select==1 || t==3 && select==2)
    {
        setColor(text=4, back);

        gotoxy(x+0,y+11);printf("   #      ###      #     #   ###   #     #");
        gotoxy(x+0,y+12);printf("  # #      #       #  #  #    #    ##    #");
        gotoxy(x+0,y+13);printf(" #   #     #       #  #  #    #    # #   #");
        gotoxy(x+0,y+14);printf("#     #    #       #  #  #    #    #  #  #");
        gotoxy(x+0,y+15);printf("#######    #       #  #  #    #    #   # #");
        gotoxy(x+0,y+16);printf("#     #    #       #  #  #    #    #    ##");
        gotoxy(x+0,y+17);printf("#     #   ###       ## ##    ###   #     #");

        setColor(text=0, back);

        gotoxy(x+0,y+19);printf(":AI �¸�:  -1000��");
        nerver_money-=1000;
    }

    if(t==1 && select==2 || t==2 && select==3 || t==3 && select==1)
    {
        setColor(text=2, back);

        gotoxy(x+0,y+11);printf("#     # ####### #     #      #     #   ###   #     #");
        gotoxy(x+0,y+12);printf(" #   #  #     # #     #      #  #  #    #    ##    #");
        gotoxy(x+0,y+13);printf("  # #   #     # #     #      #  #  #    #    # #   #");
        gotoxy(x+0,y+14);printf("   #    #     # #     #      #  #  #    #    #  #  #");
        gotoxy(x+0,y+15);printf("   #    #     # #     #      #  #  #    #    #   # #");
        gotoxy(x+0,y+16);printf("   #    #     # #     #      #  #  #    #    #    ##");
        gotoxy(x+0,y+17);printf("   #    #######  #####        ## ##    ###   #     #");

        setColor(text=0, back);

        gotoxy(x+0,y+19);printf(":YOU �¸�:  +1000�� +2Ƽ��");
        nerver_money+=1000;
        never_lucky_ticket+=2;
    }

    char replay;
    gotoxy(x,y+21);printf("�ٽ� �Ͻðڽ��ϱ�[Y or N]:");
    r:
    gotoxy(x+26,y+21);scanf("%c", &replay);

    if(replay=='Y')
    {
        system("cls");
        AIbattlegame2();
    }
    else if(replay=='N')
    {
        system("cls");
        game_two();
    }
    else
    {
        gotoxy(x+26,y+21);printf("                                                            ");
        goto r;
    }
}

void bitcoin(void)
{
    int x=0;
    int y=0;
    int beting;

    if(nerver_money<1000)
    {
        system("cls");
        gotoxy(x,y);printf("������");Sleep(1000);
        system("cls");
        gametwo();
    }

    srand((unsigned int)time(NULL)); // �Ź� �ٸ� �õ尪 ����

    int p[3], b=1, ps=0, pm=0;
    for(int j = 0; j <= 2; j++)
    {
        for(int i = 1; i <= b; i++)
        {
            ps = rand()%101;
            if(ps==0)
            {
                b++;
            }
            else
            {
                pm = rand()%2;
                if(pm==0)
                {
                    ps*=-1;
                }
                else if(pm==1)
                {
                    ps*=1;
                }
            }
            p[j]=ps;
        }
    }

    setColor(text=2, back);

    gotoxy(x,y);printf("Money : %d��", nerver_money);
    gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

    setColor(text=0, back);

    gotoxy(x,y+3);printf("3. ��Ʈ����");

    gotoxy(x,y+5);printf("�󸶸� �����Ͻðڽ��ϱ�? [1000 ~ ���� �Ӵ�]");

    r:

    gotoxy(x=0,y+6);scanf("%d", &beting);

    if(nerver_money<beting)
    {
        gotoxy(x,y+6);printf("�� ����                                                           ");Sleep(1000);
        gotoxy(x,y+6);printf("                                                                  ");
        goto r;
    }
    else if(beting<1000)
    {
        gotoxy(x,y+6);printf("�ּ� ���ñ� 1000��                                                ");Sleep(1000);
        gotoxy(x,y+6);printf("                                                                  ");
        goto r;
    }

    nerver_money-=beting;
    gotoxy(x,y+8);printf("���ñ� : %d��", beting);


    gotoxy(x+3,y+10);printf("�̶�����");
    gotoxy(x+3,y+11);printf("��������");
    gotoxy(x+3,y+12);printf("�׶�");

    y=8;

    char c;
    int cnt=1;
    int select = 0;

    srand((unsigned int)time(NULL)); // �Ź� �ٸ� �õ尪 ����

    gotoxy(x,y+2);printf("��");

    while(select==0)
    {
        if (_kbhit()) //Ű���� �Է� Ȯ�� (true / false)
        {
            c = _getch(); // Ű input
            switch (c)
            {
                case UP:
                    if(cnt==2)
                    {
                        gotoxy(x,y+3);printf("  ");
                        gotoxy(x,y+2);printf("��");
                        cnt=1;
                    }
                    else if(cnt==3)
                    {
                        gotoxy(x,y+4);printf("  ");
                        gotoxy(x,y+3);printf("��");
                        cnt=2;
                    }
                    break;
                case DOWN:
                    if(cnt==2)
                    {
                        gotoxy(x,y+3);printf("  ");
                        gotoxy(x,y+4);printf("��");
                        cnt=3;
                    }
                    else if(cnt==1)
                    {
                        gotoxy(x,y+2);printf("  ");
                        gotoxy(x,y+3);printf("��");
                        cnt=2;
                    }
                    break;
                case ENTER:
                    select=cnt;
                    break;
            }
        }
    }

    switch(select)
    {
        case 1:
            if(p[0]>10)
            {
                setColor(text=1, back);

                gotoxy(x,y+6);printf("�̶����� [ %d%%�� ]",p[0]);
                nerver_money+=beting+((beting/100)*p[0]);

                y=0;

                setColor(text=2, back);

                gotoxy(x,y);printf("Money : %d��", nerver_money);
                gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

                setColor(text=1, back);

                y=8;

                gotoxy(x,y+7);printf("+%d�� - �̵�", beting+((beting/100)*p[0]));

                setColor(text=0, back);
            }
            else if(p[0]<10)
            {
                setColor(text=4, back);

                gotoxy(x,y+6);printf("�̶����� [ %d%%�� ]",p[0]);
                nerver_money+=beting+((beting/100)*p[0]);

                y=0;

                setColor(text=2, back);

                gotoxy(x,y);printf("Money : %d��", nerver_money);
                gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

                setColor(text=4, back);

                y=8;

                gotoxy(x,y+7);printf("+%d�� - ����", beting+((beting/100)*p[0]));

                setColor(text=0, back);
            }
            break;
        case 2:
            if(p[1]>10)
            {
                setColor(text=1, back);

                gotoxy(x,y+6);printf("�̶����� [ %d%%�� ]",p[1]);
                nerver_money+=beting+((beting/100)*p[1]);

                y=0;

                setColor(text=2, back);

                gotoxy(x,y);printf("Money : %d��", nerver_money);
                gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

                setColor(text=1, back);

                y=8;

                gotoxy(x,y+7);printf("+%d�� - �̵�", beting+((beting/100)*p[1]));

                setColor(text=0, back);
            }
            else if(p[1]<10)
            {
                setColor(text=4, back);

                gotoxy(x,y+6);printf("�̶����� [ %d%%�� ]",p[1]);
                nerver_money+=beting+((beting/100)*p[1]);

                y=0;

                setColor(text=2, back);

                gotoxy(x,y);printf("Money : %d��", nerver_money);
                gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

                setColor(text=4, back);

                y=8;

                gotoxy(x,y+7);printf("+%d�� - ����", beting+((beting/100)*p[1]));

                setColor(text=0, back);
            }
            break;
        case 3:
            if(p[2]>10)
            {
                setColor(text=1, back);

                gotoxy(x,y+6);printf("�̶����� [ %d%%�� ]",p[2]);
                nerver_money+=beting+((beting/100)*p[2]);

                y=0;

                setColor(text=2, back);

                gotoxy(x,y);printf("Money : %d��", nerver_money);
                gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

                setColor(text=1, back);

                y=8;

                gotoxy(x,y+7);printf("+%d�� - �̵�", beting+((beting/100)*p[2]));

                setColor(text=0, back);
            }
            else if(p[2]<10)
            {
                setColor(text=4, back);

                gotoxy(x,y+6);printf("�̶����� [ %d%%�� ]",p[2]);
                nerver_money+=beting+((beting/100)*p[2]);

                y=0;

                setColor(text=2, back);

                gotoxy(x,y);printf("Money : %d��", nerver_money);
                gotoxy(x,y+1);printf("lucky ticket : %d��", never_lucky_ticket);

                setColor(text=4, back);

                y=8;

                gotoxy(x,y+7);printf("+%d�� - ����", beting+((beting/100)*p[2]));

                setColor(text=0, back);
            }
            break;
    }

    x+=1;
    char replay;
    gotoxy(x,y+8);printf("�ٽ� �Ͻðڽ��ϱ�[Y or N]:");
    r2:
    gotoxy(x+26,y+8);scanf("%c", &replay);

    if(replay=='Y')
    {
        system("cls");
        bitcoin();
    }
    else if(replay=='N')
    {
        system("cls");
        game_two();
    }
    else
    {
        gotoxy(x+26,y+8);printf("                                                            ");
        goto r2;
    }
}

void loginmain(void)
{
    system("color F4");

    int x=45; //Ÿ��Ʋȭ���� ǥ�õǴ� x��ǥ
    int y=4; //Ÿ��Ʋȭ���� ǥ�õǴ� y��ǥ
    char l;
    char trash=0;
    int f=3;

    gotoxy(x-2,y+0);printf("������������������");Sleep(150);
    gotoxy(x-2,y+1);printf("������������������");Sleep(150);
    gotoxy(x-2,y+2);printf("������������������");Sleep(150);
    gotoxy(x-2,y+3);printf("�����                  �����");Sleep(150);
    gotoxy(x-2,y+4);printf("�����                  �����");Sleep(150);
    gotoxy(x-2,y+5);printf("�����                  �����");Sleep(150);
    gotoxy(x-2,y+6);printf("������������������");Sleep(150);
    gotoxy(x-2,y+7);printf("������������������");Sleep(150);
    gotoxy(x-2,y+8);printf("������������������");Sleep(150);

    setColor(text=2, back);

    gotoxy(x+6,y+4);printf("��");Sleep(150);
    gotoxy(x+8,y+4);printf("  ��");Sleep(150);
    gotoxy(x+8,y+4);printf("    ��");Sleep(150);
    gotoxy(x+8,y+4);printf("      ��");Sleep(150);
    gotoxy(x+8,y+4);printf("         ");Sleep(150);
    gotoxy(x+8,y+4);printf("         Ƽ");Sleep(150);
    gotoxy(x+8,y+4);printf("           ��");Sleep(150);
    gotoxy(x+22,y+4);printf("��");Sleep(150);
    gotoxy(x+8,y+4);printf("         Ƽ");Sleep(150);
    gotoxy(x+8,y+4);printf("         ");Sleep(150);
    gotoxy(x+8,y+4);printf("      ��");Sleep(150);
    gotoxy(x+8,y+4);printf("    ��");Sleep(150);
    gotoxy(x+8,y+4);printf("  ��");Sleep(150);
    gotoxy(x+8,y+4);printf("  ����� Ƽ��");Sleep(150);

    setColor(text=0, back);

    gotoxy(x,y+14);printf(" ____________________________");
    gotoxy(x+4,y+16);printf("login�Ϸ�����[Y or N] : ");

    while(1)
    {
        gotoxy(x+28,y+16);

        fflush(stdin);

        scanf("%c", &l);

        scanf("%c", &trash);

        if(l == 'Y')
        {
            login();
            break;
        }

        else if(l == 'N')
        {
            esc(f);
            break;
        }

        else
        {
            gotoxy(x+28, y+16);printf("                                                                                  ");
        }
    }
}

void login(void)
{
    system("cls");
    fflush(stdin);

    char a[15], b[20], a2[15], b2[20];
    int i = 0, cnt;

    r:
    printf("[ �α��� ]\n\n");

    printf("id : ");
    fgets(a, 15, stdin);

    printf("bm : ");
    fgets(b, 20, stdin);

    FILE *fp = fopen("loginid.txt", "r");
    fscanf(fp, "%s", a2);
    fclose(fp);

    FILE *f2p = fopen("loginbm.txt", "r");
    fscanf(f2p, "%s", b2);

    if(asdf(a, a2) && asdf(b, b2))
    {
        printf("�α��� �Ϸ�...");Sleep(1000);

        fclose(f2p);

        system("cls");

        maint();
    }
    else
    {
        if(asdf(a, a2)!=1 && asdf(b, b2)!=1)
        {
            printf("���̵�� ��й�ȣ ����ġ");Sleep(2000);

            fclose(f2p);
            system("cls");
            goto r;
        }
        else if(asdf(a, a2)!=1)
        {
            printf("���̵� ����ġ");Sleep(2000);

            fclose(f2p);

            system("cls");

            goto r;
        }
        else if(asdf(b, b2)!=1)
        {
            printf("��й�ȣ ����ġ");Sleep(2000);

            fclose(f2p);

            system("cls");

            goto r;
        }
    }

}

int asdf(char a[], char b[])
{
    if(strlen(a)-1 != strlen(b)) // ���� ���
    {
        return 0;
    }

    for(int i = 0; i < strlen(a)-1; i++)
    {
        if(a[i] != b[i])

        return 0;
    }

    return 1;
}

//main(first page)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void backmusic()
{
    PlaySound("RUSH.wav",NULL,SND_ASYNC | SND_LOOP | SND_FILENAME);

    main();
}

int main()
{
    if(music==0)
    {
        music+=1;
        backmusic();
    }
    switch(never_num)
    {
        case 0:
            loginmain();
            break;
        case 1:
            never_num+=1;
            gametwo();
            break;
    }

    while(1){}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include<iostream>
#include<string>
#include<time.h>
using namespace std;

int harberfun(int day,int current_money,int previous_day)
{
	int arr[5][5] = {0};
	int arr1[5][5] = { 0 };
	for (int k = 0; k < 10; k++)
	{
		int i = rand() % 5;
		int j = rand() % 5;
		if (arr[i][j] == 0)
		{
			arr[i][j] = 1;
		}
	}
	cout << "---HARBER WATER AREA---" << endl;
	cout << "  ";
	for (int l = 0; l < 5; l++)
		cout << l << " ";
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i<<" ";
		for (int j = 0; j < 5; j++)
		{
			cout << arr1[i][j]<<" ";
		}
		cout << endl;
	}
	int temp1=0, temp2=0;
	cout << "WHERE YOU WANT TO PLACE THE POT?"<<endl;
	cout << "ENTER INDEX I(0-4):";
	cin >> temp1;
	while (temp1 > 4 || temp1 < 0)
	{
		cout << "INVALID INPUT! ENTER AGAIN(0-4):";
		cin >> temp1;
	}
	cout << "ENTER INDEX J(0-4):";
	cin >> temp2;
	while (temp2 > 4 || temp2 < 0)
	{
		cout << "INVALID INPUT! ENTER AGAIN(0-4):";
		cin >> temp2;
	}
	if (arr[temp1][temp2] == 1)
	{
		cout << "YOU CAUGHT A LOBSTER..." << endl;
		if (day == 4)
		{
			day = previous_day;
		}

		if (day == 1 || day == 2 || day == 3 )
		{
			cout << "2$ ADDED TO COST." << endl;
			current_money = current_money + 2;
		}
		else if (day == 5 || day == 6)
		{
			cout << "4$ ADDED TO COST." << endl;
			current_money = current_money + 4;
		}
	}
	else
	{
		cout << "POT LOST." << endl;
	}
	system("pause");
	return current_money;
}
int open_sea(int day,int current_money,int previous_day)
{
	int arr[10][10] = { 0 };
	int arr1[10][10] = { 0 };
	for (int k = 0; k < 45; k++)
	{
		int i = rand() % 10;
		int j = rand() % 10;
		if (arr[i][j] == 0)
		{
			arr[i][j] = 1;
		}
	}
	cout << "---OPEN SEA AREA---" << endl;
	cout << "  ";
	for (int l = 0; l < 10; l++)
		cout << l << " ";
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i << " ";
		for (int j = 0; j < 10; j++)
		{
			cout << arr1[i][j] << " ";
		}
		cout << endl;
	}
	int temp1 = 0, temp2 = 0;
	cout << "WHERE YOU WANT TO PLACE THE POT?" << endl;
	cout << "ENTER INDEX I(0-9):";
	cin >> temp1;
	while (temp1 > 9 || temp1 < 0)
	{
		cout << "INVALID INPUT! ENTER AGAIN(0-9):";
		cin >> temp1;
	}
	cout << "ENTER INDEX J(0-9):";
	cin >> temp2;
	while (temp2 > 9 || temp2 < 0)
	{
		cout << "INVALID INPUT! ENTER AGAIN(0-9):";
		cin >> temp2;
	}
	if (arr[temp1][temp2] == 1)
	{
		cout << "YOU CAUGHT A LOBSTER..." << endl;
		if (day == 4)
		{
			day = previous_day;
		}
		if (day == 1 || day == 2 || day == 3 )
		{
			cout << "4$ Added to Cost." << endl;
			current_money = current_money + 4;
		}
		else if (day == 5 || day == 6)
		{
			cout << "BUT DUE TO STORMY DAY POT LOST.  :(" << endl;
		}

	}
	else
	{
		cout << "POT LOST." << endl;
	}
	system("pause");
	return current_money;
}
int lastday(int i,int j,int current_money,int boats)
{
	if (i == 10 && j>=1)
	{
		char ch = ' ';
		cout << "ITS YOUR LAST DAY. YOU WANNA SELL YOUR REMIANING POTS (EACH 4$ AND 1BOAT FOR 80$?(y or n):";
		cin >> ch;
		if (ch == 'y')
		{
			current_money = current_money + (j * 4) + (boats*80);
		}

	}
	return current_money;
}
int loop2(int previous_day,int current_money,int boats,int i,int day,int j)
{
	int press1 = 0;
	system("cls");
	string arrayy[6] = { "CALM","CALM","CALM"," ","STROMY","STROMY"};
		cout << "ITS A "<<arrayy[day-1]<<" DAY." << endl;
	cout << "DAY NO: " << i << endl;
	cout << "YOU HAVE " << boats << " BOAT(s)." << endl;
	if (i == 10)
		current_money = lastday(i, j, current_money, boats);
	if (current_money >= 1000)
	{

		cout << "CONGRATULATION ! YOU GET A TICKET TO GO HOME." << endl;
		system("pause");
		exit(0);
	}
	if (i == 10 && current_money < 1000)
	{
		cout << "YOU ARE FAILED TO GET A TICKET!.TRY AGAIN..." << endl;
		system("pause");
		exit(0);
	}
	cout << "YOU HAVE NOW:" << current_money << "$" << endl;
	cout << "You Have " << j << " Number of Pots." << endl;
	//pots
	char a = ' ';
	cout << "WANT ADDITIONAL POTS? 1POT WORTH 5$(y or n):";
	cin >> a;
	if (a == 'y')
	{
		int N = 0;
		cout << "ENTER NUMBER OF POTS REQUIRED:";
		cin >> N;
		while (N < 0 && N>20)
		{
			cout << "INVALID INNPUT! ENTER NUMBER OF POTS REQUIRED:";
			cin >> N;
		}
		if (current_money > 5 * N && j + N <= 20 * boats)
		{
			j = j + N;
			cout << "PURCHASED SUCCESFUL." << endl;
			current_money = current_money - (5 * N);
		}
		else
			cout << "SORRY! PERCHASED ERROR." << endl << endl;
	}
	//boats
	char b = ' ';
	cout << "WANT ADDITIONAL BOATS? 1BOAT WORTH 100$(y or n):";
	cin >> b;
	if (b == 'y' && current_money >= 100)
	{
		cout << "PURCHASED SUCCESFUL." << endl;
		boats++;
		j = j + 10;
		current_money = current_money - 100;
	}
	else if (b == 'y' && current_money <= 100)
		cout << "SORRY! YOU DONT HAVE ENOUGH MONEY." << endl << endl;
	cout << "PRESS 1 TO PLACE IN HARBER WATER." << endl;
	cout << "PRESS 2 to PLACE IN OPEN SEA." << endl;
	cout << "PRESS 0 TO QUIT THE GAME." << endl;
	cout << "Press:";
	cin >> press1;
	while (press1 != 1 && press1 != 2 && press1 != 0)
	{
		cout << "INVALID INPUT. PLEASE ENTER AGAIN:";
		cin >> press1;
	}
	if (press1 == 1)
	{
		current_money = harberfun(day, current_money, previous_day);
	}
	else if (press1 == 2)
	{
		current_money = open_sea(day, current_money, previous_day);
	}
	else if (press1 == 0)
	{
		exit(0);
	}
	return current_money;
}
int loop1(int previous_day,int current_money,int boats,int i)
{
	srand(time(0));
	int day = rand() % 6 + 1;
	if (day != 4)
	{
		previous_day = day;
	}
	for (int j = 10; j > 0; j--)
	{
		current_money=loop2(previous_day,current_money,boats,i,day,j);
	}
	return current_money;
}
int main()
{
	int press = 0;
	while (1)
	{
		cout << "PRESS 1 TO PLAY THE GAME." << endl;
		cout << "PRESS 2 FOR HELP." << endl;
		cout << "PRESS 3 EXIT." << endl;
		cout << "PRESS:";
		cin >> press;
		if (press == 1)
		{
			int previous_day = 0;
			int current_money = 0;
			int boats = 1;
			for (int i = 1; i <= 10; i++)
			{
				current_money=loop1(previous_day, current_money, boats, i);			
			}
		}
		else if (press == 2)
		{
			//help Instructions
			cout << "INSTRUCTIONS" << endl;
			cout << "YOU HAVE 10 DAYS TO EARN ENOUGH MONEY TO GET TICKET OF WORTH 1000$ TO GO HOME" << endl;
			cout << "IT IS BY SELLING LOBSTERS." << endl;
			cout << "You have been given one boat and 10 lobster pots. You can choose to place your pots in the harbor waters or out in the open sea" << endl;
			cout << "A boat can carry you and 20 pots. you can make only one trip out per day to place your pots" << endl;
			cout << "On a calm day in harbor each pot will earn you $2, in the open sea $8.On a stormy day in harbor you will earn $4 but out at sea you will catch nothing and lose your pot." << endl;
			cout << "Additional pots can be bought for $5 each." << endl;	
			cout << "After your last catch on the tenth day you can sell your pots for $4 and boats for $80 each." << endl;
			system("pause");
			system("cls");
		}
		else if (press == 3)
		{
			exit(0);
		}
		else
		{
			cout << "INVALID INPUT!" << endl;
			system("pause");
		}
	
	}
	system("pause");
	return 0;
}

/*
寫出一飲料系統要以下功能
詢問顧客要的飲料 冰輛 糖量 杯數
印製訂購標籤紙標示客戶飲料內容
-----------
|XXX      |
|X糖X冰   |
-----------

印出點單
包含訂購號碼(取飲料)及明細&金額(收款)
統計每天賣出飲料杯數及當天營業額(作帳)
*/
#include <fstream>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include <iomanip>
using namespace std;
//標籤用 
static struct lebal
{
	string sugar,ice,product;
}leb;
//總數 
static struct total
{
	int green,red,tea,milk,sport,yaku,coffee,boba,latte;
	lebal n[100];
}total_person = {0,0,0,0,0,0,0,0,0};
//印製標籤
void output(lebal leb)
{
	ofstream afile("label.txt",ios::app);
	if(afile.is_open())
	{
		afile << "--------------" << endl;
		afile << "|" << leb.product  << setw(10) << "|" << endl;
		afile << "|" << leb.sugar << leb.ice <<setw(6) << "|" << endl;
		afile << "--------------" << endl;
	}
	afile.close();	
}
int main()
{
	//依序用途 是否再次使用系統,總共數量,總共金額,客人單號
	int check_all = 2,all = 0,money = 0,number = 1;
	do
	{
		//依序用途 檢查是否繼續訂購,需要飲料代號暫存,訂單開始位置,訂單結束位置
		int check = 1,tmp = -1;
		int start = 0,end;
		//菜單
		cout << "          ---歡迎光臨.以下是價目表---" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "(1)綠茶" << setw(7) << "20" << setw(9); 
		cout << "(4)奶茶" << setw(7) << "25" << setw(9);
		cout << "(7)咖啡" << setw(7) << "35" << endl;
		cout << "(2)紅茶" << setw(7) << "20" << setw(13); 
		cout << "(5)運動飲料" << setw(3) << "25" << setw(13);
		cout << "(8)波霸奶茶" << setw(3) << "35" << endl;
		cout << "(3)清茶" << setw(7) << "20" << setw(13); 
		cout << "(6)多多綠茶" << setw(3) << "30" << setw(9);
		cout << "(9)拿鐵" << setw(7) << "40" << endl << endl;
		cout << "冰量:(1)熱飲 (2)去冰 (3)微冰 (4)少冰 (5)全冰" << endl;
		cout << "糖量:(1)無糖 (2)微糖 (3)半糖 (4)少糖 (5)全糖" << endl << endl;
		cout << "系統使用方法:" << endl;
		cout << "1.輸入一種類飲料數量(甜度冰量一樣)" << endl;
		cout << "2.決定冰量及甜度" << endl;
		cout << "3.決定是否需要繼續點購飲料" << endl;
		cout << "注意事項:如欲購買不同甜度冰量之同一飲料,請分開選購" << endl << endl;
		//主系統-點餐 
		do
		{
			cout << "請問您需要幾杯飲料? ";
			cin >> end;
			end +=start;
			cout << "請問您需要甚麼飲料?(請填代碼) ";
			cin >> tmp;
			for(int i = start;i < end;i++)
			{
				switch(tmp)
				{
					//將數字轉為指定字串
					case 1:
						total_person.n[i].product = "綠茶";
						total_person.green++;
					break;
					case 2:
						total_person.n[i].product = "紅茶";
						total_person.red++;
					break;
					case 3:
						total_person.n[i].product = "清茶";
						total_person.tea++;
					break;
					case 4:
						total_person.n[i].product = "奶茶";
						total_person.milk++;
					break;
					case 5:
						total_person.n[i].product = "運動";
						total_person.sport++;
					break;
					case 6: 
						total_person.n[i].product = "多綠";
						total_person.yaku++;
					break;
					case 7:
						total_person.n[i].product = "咖啡";
						total_person.coffee++;
					break;
					case 8: 
						total_person.n[i].product = "波奶";
						total_person.boba++;
					break; 
					case 9:
						total_person.n[i].product = "拿鐵";
						total_person.latte++;
					break; 
				}
			}
			cout << "請問您的冰量?(請填代碼) ";
			cin >> tmp;
			for(int i = start;i < end;i++)
			{
				switch(tmp)
				{
					case 1:
						total_person.n[i].ice = "熱飲";
					break;
					case 2:
						total_person.n[i].ice = "去冰";
					break;
					case 3:
						total_person.n[i].ice = "微冰";
					break;
					case 4:
						total_person.n[i].ice = "少冰";
					break;
					case 5:
						total_person.n[i].ice = "全冰";
					break;
				}
			}
			cout << "請問您的甜度?(請填代碼) ";
			cin >> tmp;
			for(int i = start;i < end;i++)
			{
				switch(tmp)
				{
					case 1:
						total_person.n[i].sugar = "無糖";
					break;
					case 2:
						total_person.n[i].sugar = "微糖";
					break;
					case 3:
						total_person.n[i].sugar = "半糖";
					break;
					case 4:
						total_person.n[i].sugar = "少糖";
					break;
					case 5:
						total_person.n[i].sugar = "全糖";
					break;
				}
			}
			cout << "要繼續點飲料嗎? 1-要 2-不要 ";
			cin >> check;
			start += end;
		}while(check == 1);//檢查是否繼續點餐
		//印製標籤
		ofstream ofile("label.txt",ios::out);
		if(ofile.is_open())
		{
			ofile << "標籤" << endl; 
		}
		ofile.close();
		for(int i = 0;i < end;i++)output(total_person.n[i]);
		cout << "=========================================================" << endl;
		ofstream afile("label.txt",ios::app);
		if(afile.is_open())
		{
			//明細
			afile << " " <<endl;
			afile << "~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
			afile << "單號:" << number << endl;
			afile << "以下為您的訂單:" << endl;
			afile << "品名" << setw(8) << "數量" << setw(5) << "單價" << setw(5) << "總額" << endl;
			if(total_person.green != 0) afile << "綠茶" << setw(8) << total_person.green << setw(5) << "20" << setw(5) << total_person.green*20 << endl;
			if(total_person.red != 0)	afile << "紅茶" << setw(8) << total_person.red << setw(5) << "20" << setw(5) << total_person.red*20 << endl;
			if(total_person.tea != 0)	afile << "清茶" << setw(8) << total_person.tea << setw(5) << "20" << setw(5) << total_person.tea*20 << endl;
			if(total_person.milk != 0)	afile << "奶茶" << setw(8) << total_person.milk << setw(5) << "25" << setw(5) << total_person.milk*25 << endl;
			if(total_person.sport != 0)	afile << "運動" << setw(8) << total_person.sport << setw(5) << "25" << setw(5) << total_person.sport*25 << endl;
			if(total_person.yaku != 0)	afile << "多綠" << setw(8) << total_person.yaku << setw(5) << "30" << setw(5) << total_person.yaku*30 << endl;
			if(total_person.coffee != 0)afile << "咖啡" << setw(8) << total_person.coffee << setw(5) << "35" << setw(5) << total_person.coffee*35 << endl;
			if(total_person.boba != 0)	afile << "波奶" << setw(8) << total_person.boba << setw(5) << "35" << setw(5) << total_person.boba*35 << endl;
			if(total_person.latte != 0)	afile << "拿鐵" << setw(8) << total_person.latte << setw(5) << "40" << setw(5) << total_person.latte*40 << endl;
			int sum = total_person.green*20+total_person.red*20+total_person.tea*20+total_person.milk*25+total_person.sport*25+total_person.yaku*30+total_person.coffee*35+total_person.boba*35+total_person.latte*40;
			afile << "-------------------------" << endl;
			afile << setw(22) << sum << endl;
			number++;
			money += sum;
			all += total_person.green+total_person.red+total_person.tea+total_person.milk+total_person.sport+total_person.yaku+total_person.coffee+total_person.boba+total_person.latte;
			cout << "今日結束? 1-是 2-否 ";
			cin >> check_all;
			cout <<"========================================================="<< endl ;
		}
		afile.close();
	}while(check_all == 2);//檢查是否重複系統
	//一日總額
	cout << "今日已結束....." << endl;
	cout << "今日總營業額:" << money << endl;
	cout << "今日總售出:" << all << "杯" << endl;
	system("pause");
	return 0;
}

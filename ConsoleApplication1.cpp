// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include <fstream>
#include<vector>
#include<time.h>
#include <sstream>
#include<map>
int num= 0;

struct ordervalue
{

	std::string createtime = " ";;
	std::string amount = " ";
	std::string done = " ";
	


};
struct buyervalue
{
	std::string contactphone = " ";
	std::string address = " ";
	std::string buyername = " ";
};
struct goodvalue
{
	std::string salerid = " ";
	std::string goodname = " ";
	std::string price = " ";

};

std::map<std::string, struct ordervalue> orderid_ordervalue;
std::map<std::string, struct buyervalue> buyerid_buyervalue;
std::map<std::string, struct goodvalue> goodid_goodvalue;
std::map<std::string, std::string> orderid_buyerid;
std::map<std::string, std::string> orderid_goodid;


void ReadGoodFromFile()
{
	for (int m = 0; m < 3; m++)
	{
		std::ifstream fin;
		switch (m)
		{
		case 0: 
		{
			fin.open("G:/Download/data/good.0.0");
			break; 
		}
		case 1:
		{
			fin.open("G:/Download/data/good.1.1");
			break;
		}
		case 2:
		{
			fin.open("G:/Download/data/good.2.2");
			break;
		}
		}
		std::string s;
		std::string sv;
		const char *sep = ":";
		while (getline(fin, s, '\n'))
		{


			std::istringstream iss(s);
			std::string tmp;
			std::string goodid = " ";
			goodvalue value;

			while (iss >> tmp)
			{
				bool flag = 0;
				for (int i = 0; i < tmp.length(); i++)
				{
					if (tmp[i] == ':')
					{
						flag = 1;
						break;
					}
				}
				if (flag == 1)
				{
					int num2 = 0;
					if (tmp.substr(0, 7) == "goodid:")
					{
						goodid = tmp.substr(7, tmp.length());


					}
					if (tmp.substr(0, 8) == "salerid:")
					{
						value.salerid = tmp.substr(8, tmp.length());
					}
					if (tmp.substr(0, 10) == "good_name:")
					{
						value.goodname = tmp.substr(10, tmp.length());
					}
					if (tmp.substr(0, 6) == "price:")
					{
						value.price = tmp.substr(6, tmp.length());
					}





				}
			}
			goodid_goodvalue.insert(std::pair<std::string, struct goodvalue>(goodid, value));

		}
	}

}
void ReadBuyerFromFile()
{
	for (int m = 0; m < 2; m++)
	{
		std::ifstream fin;
		switch (m)
		{
		case 0 :
		{
			fin.open("G:/Download/data/buyer.0.0");
			break;
		}
		case 1 :
		{
			fin.open("G:/Download/data/buyer.1.1");
			break;
		}
		

		}

		
		std::string s;
		std::string sv;
		const char *sep = ":";
		while (getline(fin, s, '\n'))
		{


			std::istringstream iss(s);
			std::string tmp;
			std::string buyerid = " ";
			buyervalue value;

			while (iss >> tmp)
			{
				bool flag = 0;
				for (int i = 0; i < tmp.length(); i++)
				{
					if (tmp[i] == ':')
					{

						flag = 1;
						break;
					}
				}
				if (flag == 1)
				{
					if (tmp.substr(0, 8) == "buyerid:")
					{
						buyerid = tmp.substr(8, tmp.length());

					}
					if (tmp.substr(0, 13) == "contactphone:")
					{
						value.contactphone = tmp.substr(13, tmp.length());
					}
					if (tmp.substr(0, 8) == "address:")
					{
						value.address = tmp.substr(8, tmp.length());
					}
					if (tmp.substr(0, 10) == "buyername:")
					{

						value.buyername = tmp.substr(10, tmp.length());

					}





				}
			}
			buyerid_buyervalue.insert(std::pair<std::string, struct buyervalue>(buyerid, value));



		}
	}
	
}

void ReadOrderFromFile()
{
	for (int m=0; m < 4; m++)
	{
		std::ifstream fin;
		
		switch (m)
		{
		case 0:
		{
			
			fin.open("G:/Download/data/order.0.0");
			break;
		}
		case 1:
		{
			fin.open("G:/Download/data/order.0.3");
			break;
		}
		case 2:
		{
			fin.open("G:/Download/data/order.1.1");
			break;
		}
		case 3:
		{
			fin.open("G:/Download/data/order.2.2");
			break;
		}
		}
		std::string s;
		std::string sv;
		
		while (getline(fin, s, '\n'))
		{

			num++;
			std::istringstream iss(s);
			std::string tmp = " ";
			std::string orderid = " ";
			ordervalue value;
			while (iss >> tmp)
			{
				bool flag = 0;
				for (int i = 0; i < tmp.length(); i++)
				{
					if (tmp[i] == ':')
					{
						flag = 1;
						break;
					}
				}
				if (flag == 1)
				{

					if (tmp.substr(0, 8) == "orderid:")
					{
						orderid = tmp.substr(8, tmp.length());

					}
					if (tmp.substr(0, 11) == "createtime:")
					{
						value.createtime = tmp.substr(11, tmp.length());
					}
					if (tmp.substr(0, 8) == "buyerid:")
					{
						orderid_buyerid.insert(std::pair<std::string, std::string>(orderid, tmp.substr(8, tmp.length())));
					}
					if (tmp.substr(0, 7) == "goodid:")
					{

						orderid_goodid.insert(std::pair<std::string, std::string>(orderid, tmp.substr(7, tmp.length())));

					}
					if (tmp.substr(0, 7) == "amount:")
					{
						value.amount = tmp.substr(7, tmp.length());
					}
					if (tmp.substr(0, 5) == "done:")
					{
						value.done = tmp.substr(5, tmp.length());
					}






				}

			}
			orderid_ordervalue.insert(std::pair<std::string, struct  ordervalue>(orderid, value));



		}
		
	}
	
	
	

}

int main()
{
	clock_t startTime, endTime;
	std::string createtime = " ";;
	std::string amount = " ";
	std::string done = " ";
	std::string orderid = " ";
	std::string buyerid = " ";
	std::string goodid = " ";
	std::string contactphone = " ";
	std::string address = " ";
	std::string buyername = " ";
	std::string salerid = " ";
	std::string goodname = " ";
	std::string price = " ";


	startTime = clock();
	ReadOrderFromFile();
	ReadGoodFromFile();
	ReadBuyerFromFile();
	std::cout <<"number of order"<<num<<"\n";
	endTime = clock();
	std::cout << "Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << "\n";
	std::cout << "please input order id" << "\n";
	std::cin >> orderid;
	createtime = orderid_ordervalue[orderid].createtime;
	amount= orderid_ordervalue[orderid].amount;
	done= orderid_ordervalue[orderid].done;
	buyerid = orderid_buyerid[orderid];
	goodid = orderid_goodid[orderid];
	contactphone = buyerid_buyervalue[buyerid].contactphone;
	address = buyerid_buyervalue[buyerid].address;
	buyername = buyerid_buyervalue[buyerid].buyername;
	salerid = goodid_goodvalue[goodid].salerid;
	goodname = goodid_goodvalue[goodid].goodname;
	price = goodid_goodvalue[goodid].price;

	std::cout << createtime << '\n';
	std::cout << amount << '\n';
	std::cout << done << '\n';
	std::cout << buyerid << '\n';
	std::cout << goodid << '\n';
	std::cout << contactphone << '\n';
	std::cout << address << '\n';
	std::cout << buyername << '\n';
	std::cout << salerid << '\n';
	std::cout << goodname << '\n';
	std::cout << price << '\n';





	

	




}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

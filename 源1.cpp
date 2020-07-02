#include <iostream>
#include <cstdlib>
#include <cstring>
#include "function.h"

int main()
{
	ManageSystem Ms;
	std::string ID;
	std::string Password;
	int LoginCheck;
	int op;
LOGIN:
	system("cls");
	std::cout << "¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö" << std::endl;
	std::cout << "¡ö\t\t\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t\tWelcome to Chain Shop Manage System!\t\t¡ö" << std::endl;
	std::cout << "¡ö\t\t\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t\t\tPress 1 to login.\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t\t\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t\t\t  Username(ID):\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t\t\t  Password:\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t\t\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t\t\t\t\t\t\t  ver1.0¡ö" << std::endl;
	std::cout << "¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö" << std::endl;
	std::cin >> LoginCheck;
	if (LoginCheck != 1)
	{
		exit(0);
	}
	std::cin >> ID;
	std::cin >> Password;
	LoginCheck = Ms.Login(ID, Password);
	switch (LoginCheck)
	{
	case 0:
		std::cout << "Wrong username or password!" << std::endl;
		system("pause");
		goto LOGIN;
	case 1:
		std::cout << "Login successfully! Status: Staff." << std::endl;
		system("pause");
		goto STAFF;
	case 2:
		std::cout << "Login successfully! Status: Manager." << std::endl;
		system("pause");
		goto MANAGER;
	default:
		break;
	}
STAFF:
	system("cls");
	std::cout << "¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö" << std::endl;
	std::cout << "¡öStatus: Staff.\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t\t\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t1.Sell goods.\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t2.Reject goods.\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t3.Log out.\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t4.Quit.\t\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t\t\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t\t\t\t\t\t\t  ver1.0¡ö" << std::endl;
	std::cout << "¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö" << std::endl;
	std::cin >> op;
	switch (op)
	{
	case 1:
		Ms.SellGoods();
		goto STAFF;
	case 2:
		Ms.RejectGoods();
		goto STAFF;
	case 3:
		goto LOGIN;
	case 4:
		exit(0);
	default:
		goto STAFF;
	}
MANAGER:
	system("cls");
	std::cout << "¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö" << std::endl;
	std::cout << "¡öStatus: Manager.\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t\t\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t1.Sell goods.\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t2.Reject goods.\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t3.Add goods.\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t4.Delete goods.\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t5.Update goods.\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t6.View all staffs.\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t7.Search staff.\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t8.Add staff.\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t9.Delete Staff.\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t10.Update staff.\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t11.View purchase record.\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t12.Log out.\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t13.Quit.\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t\t\t\t\t\t\t\t¡ö" << std::endl;
	std::cout << "¡ö\t\t\t\t\t\t\t  ver1.0¡ö" << std::endl;
	std::cout << "¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö" << std::endl;
	std::cin >> op;
	switch (op)
	{
	case 1:
		Ms.SellGoods();
		goto MANAGER;
	case 2:
		Ms.RejectGoods();
		goto MANAGER;
	case 3:
		Ms.AddGoods();
		goto MANAGER;
	case 4:
		Ms.DeleteGoods();
		goto MANAGER;
	case 5:
		Ms.UpdateGoods();
		goto MANAGER;
	case 6:
		Ms.ViewAllStaffs();
		goto MANAGER;
	case 7:
		Ms.SearchStaff();
		goto MANAGER;
	case 8:
		Ms.AddStaff();
		goto MANAGER;
	case 9:
		Ms.DeleteStaff();
		goto MANAGER;
	case 10:
		Ms.UpdateStaff();
		goto MANAGER;
	case 11:
		Ms.ViewPurchaseRecord();
		goto MANAGER;
	case 12:
		goto LOGIN;
	case 13:
		exit(0);
	default:
		goto MANAGER;
	}
	system("pause");
	return 0;
}
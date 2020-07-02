#include <iostream>
#include <cstdlib>
#include <cstring>

struct Item
{
	std::string ItName;             //Item name
	std::string ItDescription;      //Item description
	std::string ItID;               //Item ID
	float ItPrice;                  //Item Price
	int ItAmount;                   //Item Amount
	Item* pNext;
};

struct Customer
{
	std::string CtName;             //Customer name
	std::string CtID;               //Customer ID
	float MoneyRemains;             //Money Remains
	Customer* pNext;
};

struct PurchaseRecord
{
	std::string ItID;               //Item ID
	std::string CtID;               //Customer ID
	int Num;                        //Num of the purchase
	float MoneyRemains;             //Money Remains
	PurchaseRecord* pNext;
};

struct Staff
{
	std::string StName;             //Staff name
	std::string StID;               //Staff ID
	std::string StPassword;         //Staff login password
	char Sex;                       //Sex
	Staff* pNext;
};

struct Manager
{
	std::string MnName;             //Manager name
	std::string MnID;               //Manager ID
	std::string MnPassword;         //Manager login password
};

class ManageSystem
{
private:
	Item It;
	Item* pIt;
	Customer Ct;
	Customer* pCt;
	PurchaseRecord Pr;
	PurchaseRecord* pPr;
	Staff St;
	Staff* pSt;
	Manager Mn;
public:
	ManageSystem();
	int Login(std::string ID, std::string Password);
	void AddGoods();
	void DeleteGoods();
	void UpdateGoods();
	void SellGoods();
	void RejectGoods();
	void ViewAllStaffs();
	void SearchStaff();
	void AddStaff();
	void DeleteStaff();
	void UpdateStaff();
	void ViewPurchaseRecord();
};
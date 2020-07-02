#include <iostream>
#include <cstdlib>
#include <cstring>
#include "class.h"

ManageSystem::ManageSystem()
{
	std::string Temp1;
	std::string Temp2;
	pIt = &It;
	pIt->pNext = NULL;
	pCt = &Ct;
	pCt->pNext = NULL;
	pPr = &Pr;
	pPr->pNext = NULL;
	pSt = &St;
	pSt->pNext = NULL;
	std::cout << "Hello, Manager! Please input your name:";
	std::cin >> Mn.MnName;
	std::cout << "Please create your ID:";
	std::cin >> Mn.MnID;
	while (1)
	{
		std::cout << "Please create your password:";
		std::cin >> Temp1;
		std::cout << "Please confirm your password:";
		std::cin >> Temp2;
		if (Temp1 == Temp2)
		{
			Mn.MnPassword = Temp1;
			break;
		}
		std::cout << "Input Error!" << std::endl;
	}
	std::cout << "Create complete!" << std::endl;
	system("pause");
}

int ManageSystem::Login(std::string ID, std::string Password)
{
	pSt = &St;
	if (ID == Mn.MnID && Password == Mn.MnPassword)
	{
		return 2;
	}
	else if (pSt->pNext == NULL)
	{
		return 0;
	}
	else
	{
		for (pSt = &St; pSt->pNext != NULL; pSt = pSt->pNext)
		{
			if (ID == pSt->StID && Password == pSt->StPassword)
			{
				return 1;
			}
		}
		return 0;
	}
}

void ManageSystem::SellGoods()
{
	std::string ID;
	int Num;
	int op;
	float Money;
	std::cout << "Please input the ID of the item:";
	std::cin >> ID;
	for (pIt = &It; pIt->pNext != NULL; pIt = pIt->pNext)
	{
		if (ID == pIt->ItID)
		{
			std::cout << "Please input the num of the item:";
			std::cin >> Num;
			if (pIt->ItAmount - Num < 0)
			{
				std::cout << "The item is running low." << std::endl;
				system("pause");
				return;
			}
			std::cout << "Item name:" << pIt->ItName << std::endl;
			std::cout << "Item ID:" << pIt->ItID << std::endl;
			std::cout << "Item desription:" << pIt->ItDescription << std::endl;
			std::cout << "Retail price:" << pIt->ItPrice << std::endl;
			std::cout << "Num:" << Num << std::endl;
			std::cout << "Total price:" << pIt->ItPrice * Num << std::endl;
			std::cout << "Item remains:" << pIt->ItAmount - Num << std::endl;
			std::cout << "Please input the ID of the customer:";
			std::cin >> ID;
			for (pCt = &Ct; pCt->pNext != NULL; pCt = pCt->pNext)
			{
				if (ID == pCt->CtID)
				{
					std::cout << "Customer name:" << pCt->CtName << std::endl;
					std::cout << "Customer ID:" << pCt->CtID << std::endl;
					std::cout << "Money remains:" << pCt->MoneyRemains << std::endl;
					if (pCt->MoneyRemains - pIt->ItPrice * Num < 0)
					{
						std::cout << "Money is running low. Press 1 to put more money." << std::endl;
						std::cin >> op;
						if (op != 1)
						{
							system("pause");
							return;
						}
						std::cout << "Please input the money:";
						std::cin >> Money;
						pCt->MoneyRemains = pCt->MoneyRemains + Money;
					}
					goto CONFIRM;
				}
			}
			std::cout << "This is a new customer. Press 1 to create a new profile." << std::endl;
			std::cin >> op;
			if (op == 1)
			{
				std::cout << "Please input the name of the customer:";
				std::cin >> pCt->CtName;
				std::cout << "Please input the ID of the customer:";
				std::cin >> pCt->CtID;
				std::cout << "Please input the money:";
				std::cin >> pCt->MoneyRemains;
				Customer* C = new Customer;
				C->pNext = NULL;
				pCt->pNext = C;
			}
			else
			{
				return;
			}
		CONFIRM:
			std::cout << "Press 1 to confirm:";
			std::cin >> op;
			if (op == 1)
			{
				if (pCt->MoneyRemains - pIt->ItPrice * Num < 0)
				{
					std::cout << "Money is running low. Press 1 to put more money." << std::endl;
					std::cin >> op;
					if (op != 1)
					{
						system("pause");
						return;
					}
					std::cout << "Please input the money:";
					std::cin >> Money;
					pCt->MoneyRemains = pCt->MoneyRemains + Money;
				}
				pIt->ItAmount = pIt->ItAmount - Num;
				pCt->MoneyRemains = pCt->MoneyRemains - pIt->ItPrice * Num;
				for (pPr = &Pr; pPr->pNext != NULL; pPr = pPr->pNext)
				{
					;
				}
				pPr->ItID = pIt->ItID;
				pPr->CtID = pCt->CtID;
				pPr->Num = Num;
				pPr->MoneyRemains = pCt->MoneyRemains;
				PurchaseRecord* P = new PurchaseRecord;
				P->pNext = NULL;
				pPr->pNext = P;
				std::cout << "Sell complete!" << std::endl;
				system("pause");
				return;
			}
			else
			{
				std::cout << "Sell failed!" << std::endl;
				system("pause");
				return;
			}
		}
	}
	std::cout << "Wrong ID!" << std::endl;
	system("pause");
}

void ManageSystem::RejectGoods()
{
	std::string ID1;
	std::string ID2;
	int i = 0;
	int j;
	int op;
	std::cout << "Please input the ID of the customer:";
	std::cin >> ID1;
	std::cout << "Please input the ID of the Item:";
	std::cin >> ID2;
	for (pPr = &Pr; pPr->pNext != NULL; pPr = pPr->pNext)
	{
		if (ID1 == pPr->CtID && ID2 == pPr->ItID)
		{
			i++;
			std::cout << "No." << i << ":" << std::endl;
			std::cout << "Customer:" << pPr->CtID << std::endl;
			std::cout << "Item:" << pPr->ItID << std::endl;
			std::cout << "Num:" << pPr->Num << std::endl;
			std::cout << "Money remains:" << pPr->MoneyRemains << std::endl;
		}
	}
	if (i == 0)
	{
		std::cout << "Wrong input!" << std::endl;
		return;
	}
	std::cout << "Please input the No. of the purchase:";
	std::cin >> j;
	i = 0;
	for (pPr = &Pr; pPr->pNext != NULL; pPr = pPr->pNext)
	{
		if (ID1 == pPr->CtID && ID2 == pPr->ItID && i < j)
		{
			i++;
			if (i == j)
			{
				std::cout << "Customer:" << pPr->CtID << std::endl;
				std::cout << "Item:" << pPr->ItID << std::endl;
				std::cout << "Num:" << pPr->Num << std::endl;
				std::cout << "Money remains:" << pPr->MoneyRemains << std::endl;
				std::cout << "Press 1 to confirm." << std::endl;
				std::cin >> op;
				if (op == 1)
				{
					for (pIt = &It; pIt->pNext != NULL; pIt = pIt->pNext)
					{
						if (pIt->ItID == pPr->ItID)
						{
							pIt->ItAmount = pIt->ItAmount + pPr->Num;
							break;
						}
					}
					for (pCt = &Ct; pCt->pNext != NULL; pCt = pCt->pNext)
					{
						if (pCt->CtID == pPr->CtID)
						{
							pCt->MoneyRemains = pCt->MoneyRemains + pPr->Num * pIt->ItPrice;
							op = 0 - pPr->Num;
							break;
						}
					}
					for (pPr = &Pr; pPr->pNext != NULL; pPr = pPr->pNext)
					{
						;
					}
					pPr->ItID = pIt->ItID;
					pPr->CtID = pCt->CtID;
					pPr->Num = op;
					pPr->MoneyRemains = pCt->MoneyRemains;
					PurchaseRecord* P = new PurchaseRecord;
					P->pNext = NULL;
					pPr->pNext = P;
					std::cout << "Reject complete!" << std::endl;
					system("pause");
					return;
				}
				else
				{
					std::cout << "Wrong input!" << std::endl;
					system("pause");
					return;
				}
			}
		}
	}
	system("pause");
	return;
}

void ManageSystem::AddGoods()
{
	std::string Name;
	std::string ID;
	std::string Description;
	int Amount;
	float Price;
	int op;
	std::cout << "Please input the name of the goods:";
	std::cin >> Name;
	std::cout << "Please input the ID of the goods:";
	std::cin >> ID;
	std::cout << "Please input the description of the goods:";
	std::cin >> Description;
	std::cout << "Please input the amount of the goods:";
	std::cin >> Amount;
	std::cout << "Please input the price of the goods:";
	std::cin >> Price;
	std::cout << "Press 1 to confirm." << std::endl;
	std::cin >> op;
	for (pIt = &It; pIt->pNext != NULL; pIt = pIt->pNext)
	{
		if (ID == pIt->ItID)
		{
			std::cout << "This item is already had!" << std::endl;
			system("pause");
			return;
		}
	}
	if (op == 1)
	{
		pIt->ItName = Name;
		pIt->ItID = ID;
		pIt->ItDescription = Description;
		pIt->ItAmount = Amount;
		pIt->ItPrice = Price;
		Item* I = new Item;
		I->pNext = NULL;
		pIt->pNext = I;
		std::cout << "Add complete!" << std::endl;
		system("pause");
		return;
	}
	std::cout << "Add failed!" << std::endl;
	system("pause");
	return;
}

void ManageSystem::DeleteGoods()
{
	int op;
	int i = 0;
	int j = 0;
	std::string ID;
	std::cout << "Please input the ID of goods:";
	std::cin >> ID;
	for (pIt = &It; pIt->pNext != NULL; pIt = pIt->pNext)
	{
		if (ID == pIt->ItID)
		{
			std::cout << "Item name:" << pIt->ItName << std::endl;
			std::cout << "Item ID:" << pIt->ItID << std::endl;
			std::cout << "Item desription:" << pIt->ItDescription << std::endl;
			std::cout << "Retail price:" << pIt->ItPrice << std::endl;
			std::cout << "Item remains:" << pIt->ItAmount << std::endl;
			std::cout << "Do you want to delete this item? Press 1 to confirm." << std::endl;
			std::cin >> op;
			if (op == 1)
			{
				if (i == 0)
				{
					It = *pIt->pNext;
					pIt = &It;
				}
				else
				{
					for (pIt = &It; j < i - 1; pIt = pIt->pNext)
					{
						j++;
					}
					pIt->pNext = pIt->pNext->pNext;
				}
				std::cout << "Delete complete!" << std::endl;
				system("pause");
				return;
			}
		}
		i++;
	}
	std::cout << "Wrong ID!" << std::endl;
	system("pause");
}

void ManageSystem::UpdateGoods()
{
	std::string Name;
	std::string ID;
	std::string Description;
	int Amount;
	float Price;
	int op;
	std::cout << "Please input the ID of the item:";
	std::cin >> ID;
	for (pIt = &It; pIt->pNext != NULL; pIt = pIt->pNext)
	{
		if (ID == pIt->ItID)
		{
			std::cout << "Item name:" << pIt->ItName << std::endl;
			std::cout << "Item ID:" << pIt->ItID << std::endl;
			std::cout << "Item desription:" << pIt->ItDescription << std::endl;
			std::cout << "Retail price:" << pIt->ItPrice << std::endl;
			std::cout << "Item remains:" << pIt->ItAmount << std::endl;
			std::cout << "Press 1 to upadte this item." << std::endl;
			std::cin >> op;
			if (op == 1)
			{
				std::cout << "Please input the name of the goods:";
				std::cin >> Name;
				std::cout << "Please input the ID of the goods:";
				std::cin >> ID;
				std::cout << "Please input the description of the goods:";
				std::cin >> Description;
				std::cout << "Please input the amount of the goods:";
				std::cin >> Amount;
				std::cout << "Please input the price of the goods:";
				std::cin >> Price;
				std::cout << "Press 1 to confirm." << std::endl;
				std::cin >> op;
				if (op == 1)
				{
					pIt->ItName = Name;
					pIt->ItID = ID;
					pIt->ItDescription = Description;
					pIt->ItAmount = Amount;
					pIt->ItPrice = Price;
					std::cout << "Update complete!" << std::endl;
					system("pause");
					return;
				}
				std::cout << "Add failed!" << std::endl;
				system("pause");
				return;
			}
		}
	}
}

void ManageSystem::ViewAllStaffs()
{
	int i = 0;
	for (pSt = &St; pSt->pNext != NULL; pSt = pSt->pNext)
	{
		std::cout << "Name:" << pSt->StName << std::endl;
		std::cout << "ID:" << pSt->StID << std::endl;
		std::cout << "Sex:" << pSt->Sex << std::endl;
		std::cout << "Password:" << pSt->StPassword << std::endl;
		i++;
	}
	std::cout << i << " in total." << std::endl;
	system("pause");
	return;
}

void ManageSystem::SearchStaff()
{
	std::string ID;
	std::cout << "Please input the ID of the staff:";
	std::cin >> ID;
	for (pSt = &St; pSt->pNext != NULL; pSt = pSt->pNext)
	{
		if (ID == pSt->StID)
		{
			std::cout << "Name:" << pSt->StName << std::endl;
			std::cout << "ID:" << pSt->StID << std::endl;
			std::cout << "Sex:" << pSt->Sex << std::endl;
			std::cout << "Password:" << pSt->StPassword << std::endl;
			std::cout << "Search complete!" << std::endl;
			system("pause");
			return;
		}
	}
	std::cout << "Search failed! Wrong input!" << std::endl;
	system("pause");
	return;
}

void ManageSystem::AddStaff()
{
	std::string Name;
	std::string ID;
	std::string Password1;
	std::string Password2;
	char Sex;
	int op;
	std::cout << "Please input the name of the staff:";
	std::cin >> Name;
	std::cout << "Please input the ID of the staff:";
	std::cin >> ID;
	std::cout << "Please input the password of the staff:";
	std::cin >> Password1;
	std::cout << "Please confirm the password:";
	std::cin >> Password2;
	if (Password1 != Password2)
	{
		std::cout << "Wrong input!" << std::endl;
		system("pause");
		return;
	}
	std::cout << "Please input the sex:";
	std::cin >> Sex;
	std::cout << "Press 1 to confirm." << std::endl;
	std::cin >> op;
	for (pSt = &St; pSt->pNext != NULL; pSt = pSt->pNext)
	{
		if (ID == pSt->StID)
		{
			std::cout << "This staff is already had!" << std::endl;
			system("pause");
			return;
		}
	}
	if (op == 1)
	{
		pSt->StName = Name;
		pSt->StID = ID;
		pSt->StPassword = Password1;
		pSt->Sex = Sex;
		Staff* S = new Staff;
		S->pNext = NULL;
		pSt->pNext = S;
		std::cout << "Add complete!" << std::endl;
		system("pause");
		return;
	}
	std::cout << "Add failed!" << std::endl;
	system("pause");
	return;
}

void ManageSystem::DeleteStaff()
{
	int op;
	int i = 0;
	int j = 0;
	std::string ID;
	pIt = &It;
	std::cout << "Please input the ID of staff:";
	std::cin >> ID;
	for (pSt = &St; pSt->pNext != NULL; pSt = pSt->pNext)
	{
		if (ID == pSt->StID)
		{
			std::cout << "Staff name:" << pSt->StName << std::endl;
			std::cout << "Staff ID:" << pSt->StID << std::endl;
			std::cout << "Password:" << pSt->StPassword << std::endl;
			std::cout << "Sex:" << pSt->Sex << std::endl;
			std::cout << "Do you want to delete this staff? Press 1 to confirm." << std::endl;
			std::cin >> op;
			if (op == 1)
			{
				if (i == 0)
				{
					St = *pSt->pNext;
					pSt = &St;
				}
				else
				{
					for (pSt = &St; j < i - 1; pSt = pSt->pNext)
					{
						j++;
					}
					pSt->pNext = pSt->pNext->pNext;
				}
				std::cout << "Delete complete!" << std::endl;
				system("pause");
				return;
			}
		}
		i++;
	}
	std::cout << "Wrong ID!" << std::endl;
	system("pause");
}

void ManageSystem::UpdateStaff()
{
	std::string Name;
	std::string ID;
	std::string Password1;
	std::string Password2;
	char Sex;
	int op;
	std::cout << "Please input the ID of the staff:";
	std::cin >> ID;
	for (pSt = &St; pSt->pNext != NULL; pSt = pSt->pNext)
	{
		if (ID == pSt->StID)
		{
			std::cout << "staff name:" << pSt->StName << std::endl;
			std::cout << "staff ID:" << pSt->StID << std::endl;
			std::cout << "Password:" << pSt->StPassword << std::endl;
			std::cout << "Sex:" << pSt->Sex << std::endl;
			std::cout << "Press 1 to upadte this staff." << std::endl;
			std::cin >> op;
			if (op == 1)
			{
				std::cout << "Please input the name of the staff:";
				std::cin >> Name;
				std::cout << "Please input the ID of the staff:";
				std::cin >> ID;
				std::cout << "Please input the password of the staff:";
				std::cin >> Password1;
				std::cout << "Please confirm the password:";
				std::cin >> Password2;
				if (Password1 != Password2)
				{
					std::cout << "Wrong input!" << std::endl;
					system("pause");
					return;
				}
				std::cout << "Please input the sex:";
				std::cin >> Sex;
				std::cout << "Press 1 to confirm." << std::endl;
				std::cin >> op;
				if (op == 1)
				{
					pSt->StName = Name;
					pSt->StID = ID;
					pSt->StPassword = Password1;
					pSt->Sex = Sex;
					std::cout << "Update complete!" << std::endl;
					system("pause");
					return;
				}
				std::cout << "Add failed!" << std::endl;
				system("pause");
				return;
			}
		}
	}
}

void ManageSystem::ViewPurchaseRecord()
{
	pPr = &Pr;
	std::string ID;
	std::cout << "Please input the ID of the customer:";
	std::cin >> ID;
	for (pPr = &Pr; pPr->pNext != NULL; pPr = pPr->pNext)
	{
		if (ID == pPr->CtID)
		{
			std::cout << "Customer:" << pPr->CtID << std::endl;
			std::cout << "Item:" << pPr->ItID << std::endl;
			std::cout << "Num:" << pPr->Num << std::endl;
			std::cout << "Money remains:" << pPr->MoneyRemains << std::endl;
		}
	}
	system("pause");
	return;
}

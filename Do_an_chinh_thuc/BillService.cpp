#include "BillService.h"
#include "MeterService.h"
#include "CustomerService.h"
int BillService::billAmount = 0;
BillService::BillService()
{
	this->pHead = NULL;
	this->pTail = NULL;
}
BillService::~BillService()
{

}
void  BillService::readTwoId(string path)
{
	path = "CongTo_KhachHang.txt";
	fstream file(path, ios::in);
	int count;
	if(file.is_open())
	{
		while (!file.eof())
		{
			string line;
			ElecBill* bill = new ElecBill();
			getline(file,line);
			bill->fromStringId(line);
			add(bill);
		}
	}
	else
	{
		cout << "Duong dan khong ton tai" << endl;
	}
}
void BillService::add()
{
	MeterService *meterList = new MeterService();
	CustomerService* cusList = new CustomerService();
	ElecBill* bill = pHead;
	while (bill != NULL)
	{
		bill = bill->next;
	}
	billAmount++;
}
void BillService::add(ElecBill* bill)
{
	if (pHead == NULL)
	{
		pHead = bill;
		pTail = pHead;
	}
	else
	{
		pTail->next = bill;
		pTail = bill;
	}
	billAmount++;
}

/*
* void BillService::add()
{
	ElecBill* bill = new ElecBill();
	bill->setAllData();
	if (pHead == NULL)
	{

	}
}
*/


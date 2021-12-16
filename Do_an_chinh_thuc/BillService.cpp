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
	if (file.is_open())
	{
		while (!file.eof())
		{
			string line;
			ElecBill* bill = new ElecBill();
			getline(file, line);
			bill->fromStringId(line);
			add(bill);
			billAmount++;
		}
	}
	else
	{
		cout << "Duong dan khong ton tai" << endl;
	}
}
void BillService::add()
{
	MeterService* meterList = new MeterService();
	CustomerService* cusList = new CustomerService();
	ElecBill* bill = pHead;
	while (bill != NULL)
	{
		int n_meterNumber = bill->meterNumber;
		string n_cusID = bill->cusID;
		bill->meter = meterList->getMeter(n_meterNumber);
		bill->customer = cusList->getACus(n_cusID);
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
void BillService::display()
{
	ElecBill* bill = pHead;
	while (bill != NULL)
	{
		bill->showBillOut();
		bill = bill->next;
	}
}
void BillService::displayWithArea(string address)
{
	ElecBill* bill = pHead;

	while (bill != NULL)
	{
		Customer* cus = &bill->customer;
		if (cus->getAddress().rfind(address)<=100) bill->showBillOut();
		bill = bill->next;
	}
}
void BillService::readAMonth(string path)
{
	fstream file(path);
	if (file.is_open())
	{
		string line;
		ElecBill* bill = pHead;
		while (getline(file, line)&&bill!=NULL)
		{
			bill->fromStringMonth(line);
			bill = bill->next;
		}
	}
	else
	{
		cerr << "File khong tim thay" << endl;
	}
}
void BillService::remove()
{
	bool check = false;
	cout << "Co muon xoa hay khong" << endl;;
	int choice;
	cout << "1- Xoa, 0- Huy" << endl;
	cin >> choice;
	check = choice;
	if (check)
	{
		if (pHead==NULL)
		{
			cout << "Danh sach cac hoa don trong rong";
		}
		else
		{
			int billID;
			do
			{
				cin.ignore();
				cout << "Nhap so cong to cua hoa don can xoa: " << endl;
				cin >> billID;
			} while (billID<0||billID>billAmount);
			ElecBill* after = pHead;
			ElecBill* before = after;
			while (after != NULL)
			{
				before = after;
				after = after->next;
			}
			if (after == nullptr)
			{
				throw "Khong tim thay con tro can xoa";
			}
			else
			{
				if (pHead == after)
				{
					pHead = after->next;
				}
				else
				{
					before->next = after->next;
				}
				cout << "Xoa thanh cong" << endl;
				billAmount--;
			}
		}
	}
}
void BillService::search()
{
	string input;
	cout << "Nhap id hoa don hoac so cong to" << endl;
	cin >> input;
	ElecBill* bill = pHead;
	while (bill != NULL)
	{
		if ((to_string(bill->getBillId()).rfind(input) <= 1) || (to_string(bill->meter.getMeterNumber()).rfind(input) <= 6))
		{
			bill->showBillOut();
		}
		bill = bill->next;
	}

}



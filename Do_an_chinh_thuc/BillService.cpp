#include "BillService.h"

int BillService::billAmount = 0;
BillService::BillService()
{
	this->pHead = NULL;
	this->pTail = NULL;
}
BillService::~BillService()
{

}
void BillService::readTwoId(string path)
{
	meterList.readFile("meter.txt");
	cusList.readDataInFile("customer.txt");
	path = "CongTo_KhachHang.txt";
	fstream file(path, ios::in);
	if (file.is_open())
	{
		string line;
		while (!file.eof())
		{
			int meterId;
			file >> meterId;
			cout << meterId;
			string cusId="";
			file >> cusId;
			cout << cusId;
			ElecMeter meter=meterList.getMeter(meterId);
			cout << meter.getMeterNumber();
			Customer cus = cusList.getACus(cusId);
			cout << cus.getAddress();
			Date date1;
			Date date2;
			UnitPrice uPrice;
			ElecBill* bill = new ElecBill(meter, cus, date1, date2, uPrice);
			add(bill);
		}
	}
	else
	{
		cout << "Duong dan khong ton tai" << endl;
	}
}
void BillService::writeIntoFile(string path)
{
	ofstream oFile(path);
	if (oFile.is_open())
	{
		ElecBill* bill = pHead;
		while (bill != NULL)
		{
			//Dinh dang 
			bill = bill->next;
		}
	}
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
bool BillService::isEmpty()
{
	if (pHead == NULL)
	{
		return true;
	}
	else return false;
}
bool BillService::contain(int billID)
{
	ElecBill* bill = pHead;
	while (bill != NULL)
	{
		if (bill->getBillId() == billID)
		{
			return true;
			break;
		}
		bill = bill->next;
	}
	return false;
}



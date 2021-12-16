#include "ElecBill.h"
int ElecBill::increment = 1;
ElecBill::ElecBill()
{
	this->next = NULL;
	this->billId = increment++;
	this->price = 0;

}

ElecBill::ElecBill(Date beginDate,Date endDate, UnitPrice& uPrice)
{
	this->billId = increment++;
	this->beginDate = beginDate;
	this->endDate = endDate;
	this->next = NULL;
	this->price = 0;
}
ElecBill::ElecBill(const ElecBill& bill)
{
	this->billId = bill.billId;
	this->beginDate = bill.beginDate;
	this->endDate = bill.endDate;
	this->next = NULL;
}
ElecBill::~ElecBill()
{
}
void ElecBill::setBillId(int Billid)
{
	this->billId = Billid;
}
void ElecBill::showUnitPrice()
{
	unitPrice.calcPrice();
	unitPrice.showUnitPrice();
}
// Nhap tu ban phim
void ElecBill::setBeginDate()
{
	Date date;
	date.setDate();
	beginDate = date;
}
void ElecBill::setEndDate()
{
	Date date;
	date.setDate();
	endDate = date;
}
Date& ElecBill::getBeginDate()
{
	return this->beginDate;
}
Date& ElecBill::getEndDate()
{
	return this->endDate;
}
void ElecBill::showBillOut()
{
	/*
	* cout << "So cong to: " << meter.getMeterNumber()
		<< "\n Ten Khach hang" << customer.getCusName()
		<< "\n so dien thoai" << customer.getPhoneNum()
		<< "\n Dia chi: " << customer.getAddress()
		<< "\n Gia dien\n"; unitPrice.showUnitPrice();
	cout << "Tong tien: " << unitPrice.getTotalPrice();
	*/
	cout << "-------------------------------------" << endl;
	cout << "|\nId hoa don" << this->getBillId();
	cout << "|\nTen Khach Hang: " << this->customer.getCusName() << "\t " << "Ma Khach Hang: " << "\t\t" << this->customer.getCusId();
	cout << "|\nSo dien thoai: " << this->customer.getPhoneNum();
	cout << "|\nDia chi: " << this->customer.getAddress();
	cout << "|\n so cong to" << this->meter.getMeterNumber();
	cout << "|\n so dien truoc " << this->meter.getPrevMeter() << "\t\t" << "so dien sau" << this->meter.getNextMeter();
	cout << "|\n ";
	this->showUnitPrice();
	cout << "--------------------------------------------" << endl;
}
void ElecBill::fromStringId(string line)
{
	string result[2];
	string cell;
	int count = 0;
	for (int i = 0; i <= line.length(); i++)
	{
		if (line[i] == ',' || i == line.length())
		{
			result[count++] = cell;
		}
		else
		{
			cell += line[i];
		}	
	}
	this->meterNumber=(stof(result[0]));
	this->cusID=result[1];
}
void ElecBill::fromStringMonth(string line)
{
	string result[2];
	string cell;
	int count = 0;
	for (int i = 0; i <= line.length(); i++)
	{
		if (line[i] == ';' || i == line.length())
		{
			result[count++] = cell;
		}
		else {
			cell += line[i];
		}
	}
	if (this->meter.getMeterNumber() == stof(result[0]))
	{
		int n_prevMeter = this->meter.getNextMeter();
		this->meter.setNextMeter(stof(result[1]));
	}	
}
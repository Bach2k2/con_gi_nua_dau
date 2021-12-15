#include "ElecBill.h"
int ElecBill::increment = 0;
ElecBill::ElecBill()
{
	this->next = NULL;
	this->billId = 0;
	this->price = 0;
}

ElecBill::ElecBill(int billId,Date beginDate,Date endDate, UnitPrice& uPrice)
{
	this->billId = billId;
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
	this->meter.setMeterNumber(stof(result[0]));
	this->customer.setCusId(result[1]);
}
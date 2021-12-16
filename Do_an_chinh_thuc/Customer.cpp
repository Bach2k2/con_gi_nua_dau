#include "Customer.h"
#include <iostream>
#include <string>
#include<fstream>
using namespace std;
Customer::Customer(string cusId, string customerName, string address, string phoneNum) :
	cusId(cusId), cusName(customerName), address(address), phoneNum(phoneNum)
{
	this->next = NULL;
}
Customer::Customer(const Customer& cus)
{
	this->cusId = cus.cusId;
	this->cusName = cus.cusName;
	this->address = cus.address;
	this->phoneNum = cus.phoneNum;
	this->next = cus.next;
}
Customer::~Customer() {}
void Customer::setCusId(string customerId)
{
	this->cusId = customerId;
}
void Customer::setCusName(string name) {
	cusName = name;
}
void Customer::setAddress(string address)
{
	this->address = address;
}
void Customer::setPhoneNum(string phoneNum)
{
	this->phoneNum = phoneNum;
}

void Customer::setCusData()
{
	bool check = true;
	string cusName;
	do
	{
		cout << "Nhap ten khach hang";
		cin.ignore(32767, '\n');
		getline(cin, cusName);
		if (cusName == "\n" || cusName == "")
		{
			check = false;
			cout << "Nhap lai" << endl;
		}
		else check = true;
	} while (!check);
	this->cusName = cusName;
	string address;
	do
	{
		cout << "Nhap dia chi: ";
		cin.ignore(32767, '\n');
		getline(cin, address);
		if (address == ""||address=="\n")
		{
			check = false;
			cout << "Nhap lai" << endl;
		}
		else check = true;
	} while (!check);
	this->address = address;

	string phoneNumber;
	do
	{
		cout << "Nhap so dien thoai: ";
		cin.ignore(32767, '\n');
		getline(cin, phoneNumber);
		for (int i = 0; i < phoneNumber.length(); i++)
		{
			if (!isdigit(phoneNumber[i])) { check = false; break; }
			check = true;
		}
		if (phoneNumber == "")check = false;
		else
		{
			check = true;
		}
	} while (!check);
	this->phoneNum = phoneNumber;
}
ostream& operator<<(ostream& o, const Customer& cus)
{
		o << "| Ma Khach Hang | " << "| Ten khach hang | " << " | Dia chi | " << "| So dien thoai | " << endl;
		o<< cus.cusId
		 << cus.cusName
		 << cus.address
		 << cus.phoneNum << endl;
	return o;
}
void Customer::fromString(string str)
{
	string arr[10];
	int count = 0;
	string word;
	for (int i = 0; i <= str.length(); i++)
	{
		if (str[i] == ' ' || i == str.length())
		{

			arr[count++] = word;
			word = "";
		}
		else
		{
			word += str[i];
		}
	}
	int length = count;
	cout << count;
	this->phoneNum = arr[length - 1];
	this->address = arr[length - 2];
	for (int i = 1; i < length - 2; i++)
	{
		this->cusName += arr[i];
		this->cusName += ' ';
	}
	this->cusName = this->cusName.substr(0, cusName.length() - 1);
	this->cusId = arr[0];
}


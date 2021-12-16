#include "CustomerService.h"
#include <string>
#include<fstream>
#include <iostream>
#include <string>
CustomerService::CustomerService()
{
	this->cusHead = NULL;
	cusTail = cusHead;
}
CustomerService::~CustomerService() {}
int CustomerService::cusAmount = 0;
//QUEUE
void CustomerService::enqueue()
{
	bool check = true;
	Customer* customer = new Customer();
	string cusID;
	do {
		cout << "Nhap Ma Khach Hang: " << endl;
		cin >> cusID;
		if (contain(cusID))
		{
			check = false;
			cout << "nhap lai ! Ma khach hang bi trung" << endl;
		}
		else
		{
			check = true;
		}
	} while (!check);
	customer->setCusId(cusID);
	customer->setCusData();
	if (cusHead == NULL)
	{
		cusHead = customer;
	}
	else
	{
		cusTail->next = customer;

	}
	cusTail = customer;
//	cusTail->next = cusHead;
	cusAmount++;
}
void CustomerService::enqueue(Customer* customer)
{
	if (cusHead == NULL)
	{
		cusHead = customer;
	}
	else
	{
		cusTail->next = customer;
	}
	cusTail = customer;
//	cusTail->next = cusHead;
	cusAmount++;
}
void CustomerService::dequeue()
{

	bool check = false;
	cout << "DO YOU WANT TO DELETE?" << endl;
	int choice;
	cout << "Enter 1 to delete,0 to exit";
	cin >> choice;
	check = choice;
	if (check) {
		if (isEmpty())
		{
			cout << "List is empty";
			return;
		}
		//	Customer* prev = head;
		if (cusHead == cusTail) {
			free(cusHead);
			cusHead = NULL;
			cusTail = NULL;
		}
		else {
			Customer* temp = cusHead;
			cusHead = cusHead->next;
//			cusTail->next = cusHead;
			free(temp);
		}
	}
}
void CustomerService::display()
{
	if (isEmpty())
	{
		cout << "Danh sach rong" << endl;
	}
	else
	{
		cout << "| Ma Khach Hang | " << "| Ten khach hang | " << "| Dia chi | " << "| So dien thoai | " << endl;
		Customer* temp = cusHead;
		while (temp->next != NULL)
		{
			cout << *temp;
			temp = temp->next;
		}
	}
	
}
bool CustomerService::isEmpty()
{
	if (cusHead == NULL) return true;
	else return false;
}
bool CustomerService::contain(string cusID)
{
	Customer* temp = cusHead;
	if (!isEmpty())
	{
		do
		{
			if ((temp->getCusId().compare(cusID)) == 0)return true;
			temp = temp->next;
		} while (temp != NULL);
	}
	return false;
}
void CustomerService::showInfoByMkh(string cusId)
{
	Customer* temp = cusHead;
	if (contain(cusId)) {
		cout << "Danh sach ko co khach hang nay" << endl;
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->getCusId().compare(cusId) == 0) {
				cout << "Ten khach hang :" << temp->getCusId() << endl;
				cout << "Dia chi: " << temp->getAddress() << endl;
				cout << "So dien thoai" << temp->getPhoneNum() << endl;
				break;
			}
			temp = temp->next;
		}
	}

}
void CustomerService::readDataInFile(string path)
{
	ifstream file(path, ios::in);//chua gt
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			Customer* cus = new Customer();
			cus->fromString(line);
			enqueue(cus);
		}
		cout << "\nDu lieu da them vao\n";
		file.close();
	}
	else
	{
		cout << "Duong dan khong dung. Hay thu lai" << endl;
	}
}
void CustomerService::writeDataInFile(string path)
{
	ofstream file(path, ios::out);
	file << "Ma khach hang \t| Ten khach hang \t| Tuoi \t So dien thoai\t Dia chi" << endl;;
	if (file.is_open())
	{
		Customer* cus = cusHead;
		while (cus != NULL)
		{
			file << *cus;
			cus = cus->next;
		}
	}
	else
	{
		cout << "khong the mo file" << endl;
	}
}
void CustomerService::update()
{
	Customer* temp = cusHead;
	int check;
	cout << "Ban co muon sua khong?" << endl;
	do
	{
		cout << "Nhan 1 de cap nhat  - Nhan 0 de quay lai " << endl;
		cin >> check;
		if (check == 1)
		{
			string cusId;
			cout << "Nhap ma khach hang muon sua" << endl;
			cin >> cusId;
			if (contain(cusId)) {
				cout << "THONG BAO:  Da tim thay khach hang " << endl;
				Customer* temp = &getACus(cusId);
				displayUpdateMenu();
				bool check = true;
				int choice = 0;
				do
				{
					cout << "Lua chon: " << endl;
					cin >> choice;
					switch (choice)
					{
					case 1:
					{
						string n_cusId;
						do
						{
							cout << "Nhap Ma Khach Hang moi: " << endl;
							cin >> n_cusId;
							if (n_cusId == "" || CustomerService::contain(n_cusId)) check = false;
							else check = true;
						} while (!check);
						temp->setCusId(n_cusId);
						break;
					}
					case 2:
					{
						string n_cusName;
						do
						{
							cout << "Nhap Ten Khach Hang moi: " << endl;
							cin >> n_cusName;
							if (n_cusName == "") check = false;
							else check = true;
						} while (!check);
						temp->setCusName(n_cusName);
						break;
					}
					case 3:
					{
						string n_address;
						do
						{
							cin.ignore(32767, '\n');
							cout << "Nhap Dia chi Khach Hang moi: " << endl;
							getline(cin, n_address);
							if (n_address == "") check = false;
							else check = true;
						} while (!check);
						temp->setAddress(n_address);
						break;
					}
					case 4:
					{

						string n_phoneNum;
						do
						{
							cin.ignore(32767, '\n');
							cout << "Nhap so dien thoai khach Hang moi: " << endl;
							getline(cin, n_phoneNum);
							if (n_phoneNum == "") check = false;
							else check = true;
							for (int i = 0; i < n_phoneNum.size(); i++)
							{
								if (!isdigit(n_phoneNum[i])) { check = false; 
								break; 
								}
								check = true;
							}
						} while (!check);
						temp->setPhoneNum(n_phoneNum);
						break;
					}
					case 0:
					{
						cout << "Da cap nhat xong khach hang " << temp->getCusId();
						delete temp;
						break;
					}
					default:
					{
						cout << "Nhap sai lua chon mat roi" << endl;
					}

					}
				} while (choice != 0);
			}
			else
			{
				cout << "Khong tim thay khach hang can tim " << endl;
			}
		}
	} while (check != 0);
}
Customer& CustomerService::getACus(string cusId)
{
	Customer* temp = cusHead;
	while (temp != NULL)
	{
		if (temp->getCusId().compare(cusId) == 0)
		{
			cout << " Tim thay kh" << endl;
			return *temp;
		}
		temp = temp->next;
	}
}
void CustomerService::displayUpdateMenu()
{
	cout << "1. Sua ma khach hang" << endl;
	cout << "2. Sua ten khach hang" << endl;
	cout << "3. Sua dia chi khach hang" << endl;
	cout << "4. Sua so dien thoai khach hang" << endl;
	cout << "0. Tro lai ";
}
void CustomerService::searchByName()
{
	bool check = true;
	string cusName;
	do
	{
		cin.ignore(32767, '\n');
		cout << "Nhap ten khach hang can tim kiem" << endl;
		getline(cin, cusName);
		cout << cusName;
		if (cusName == "")
		{
			check = false;
			cout << "Nhap ten khong hop le" << endl;
		}
		else
		{
			check = true;
		}
	} while (!check);

	int pos = 0;
	int count = 0;
	Customer* temp = cusHead;
	while (temp != NULL)
	{
		if (temp->getCusName().find(cusName, pos) != string::npos) {
			cout << *temp;
			cout << "ok";
			count++;
		}
		temp = temp->next;
	}
	cout << "Ket qua tim duoc " << count << " khach hang " << endl;
}
void CustomerService::sortByName()
{
	for (Customer* temp = cusHead; temp != NULL; temp = temp->next)
	{
		for (Customer* temp2 = temp->next; temp2 != NULL; temp2 = temp2->next)
		{
			if (temp->compareTo(*temp2))
			{
				Customer* holder=new Customer();
				holder->getOtherCus(*temp);
				temp->getOtherCus(*temp2);
				temp2->getOtherCus(*holder);
			}
		}
	}
}

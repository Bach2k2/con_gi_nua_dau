#include "MeterService.h"
#include <string>
#include <fstream>
using namespace std;
int MeterService::mAmount = 0;
MeterService::MeterService()
{
	this->mHead = NULL;
	this->mTail = NULL;
}
MeterService::~MeterService()
{
	delete mHead;
	delete mTail;
}
// Them moi 1 cong to vao danh sach
void MeterService::add()
{
	bool check = true;
	cin.ignore(32767, '\n');
	int n_meterNum;
	do
	{
		cout << "Nhap so cong to dien" << endl;
		cin >> n_meterNum;
		if (n_meterNum < 0 || contain(n_meterNum))
		{
			cout << "Nhap lai! So cong to khong hop le" << endl;
			check = false;
		}
		else {
			check = true;
			cout << "-----";
		}
		cout << "\n!----";
	} while (!check);
	ElecMeter* meter = new ElecMeter();
	meter->setMeterNumber(n_meterNum);
	system("pause");
	if (mHead == NULL)
	{
		mHead = meter;
		mTail = mHead;
	}
	else
	{
		mTail->next = meter;
		mTail = meter;
	}
	mAmount++;
}
void MeterService::add(ElecMeter* meter)
{
	if (isEmpty())
	{
		mHead = meter;
		mTail = meter;
	}
	else
	{
		mTail->next = meter;
		mTail = meter;
	}
	cout << " da add" << endl;
	mAmount++;
}
void MeterService::readFile(string path)
{
	fstream file(path, ios::in);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			ElecMeter* temp = new ElecMeter();
			temp->fromString(line);
			add(temp);
		}
		file.close();
	}

}
bool MeterService::contain(int meterNum)
{
	ElecMeter* meter = mHead;
	while (meter != NULL)
	{
		if (meter->getMeterNumber() == meterNum)
		{
			return true;
		}
		meter = meter->next;
	}
	return false;
}
bool MeterService::isEmpty()
{
	if (mHead == NULL) return true;
	else return false;
}

void MeterService::remove()
{
	bool check = false;
	cout << "Co muon xoa hay khong" << endl;;
	int choice;
	cout << "1- Xoa, 0- Huy" << endl;
	cin >> choice;
	check = choice;
	if (check)
	{
		if (isEmpty())
		{
			cout << "Danh sach cac hoa don trong rong";
		}
		else
		{
			int meterNumber;
			cin.ignore();
			cout << "Nhap so cong to cua hoa don can xoa: " << endl;
			cin >> meterNumber;
			ElecMeter* after = mHead;
			ElecMeter* before = after;
			while (after != NULL)
			{
				before = after;
				after = after->next;
			}
			if (after != NULL)
			{
				if (mHead == after)
				{
					mHead = after->next;
				}
				else
				{
					before->next = after->next;
				}
				cout << "Xoa thanh cong" << endl;
				mAmount--;
			}
		}
	}
}
void MeterService::display()
{
	ElecMeter* meter = mHead;
	cout << "So cong to " << "\t\t" << "so dien truoc" << "\t\t" << "so dien sau" << "\t\t" << "so dien tieu thu" << endl;
	while (meter != NULL)
	{
		cout << *meter;
		meter = meter->next;
	}
}
ElecMeter& MeterService::getMeter(int meterNumber)
{
	ElecMeter* temp = mHead;

	while (temp != NULL)
	{
		if (temp->getMeterNumber() == meterNumber)
		{
			cout << "da tim thay" << endl;
			return *temp;
		}
		temp = temp->next;
	}
	throw "Error! Khong tim duoc so cong to";
}
void MeterService::search()
{
	string n_meterNum;
	cout << "Nhap so cong to can tim kiem" << endl;
	cin >> n_meterNum;
	ElecMeter* temp = mHead;
	while (temp != NULL)
	{
		string str = to_string(temp->getMeterNumber());
		if (str.rfind(n_meterNum) <= 5)
		{
			cout << *temp;
		}
		temp = temp->next;
	}
}
// Chua hoan thien
void MeterService::update()
{
	int meterNum;
	cout << "\nNhap so cong to cua hoa don: ";
	cin >> meterNum;
	ElecMeter* temp = &getMeter(meterNum);
	cout << "----------------Cap nhat cong to-----------------------" << endl;
	cout << "1. So cong to" << endl;
	cout << "2. So chi dien dau" << endl;
	cout << "3. So chi dien sau " << endl;
	cout << "----------------------------------------------------------" << endl;
	int choice;
	bool check = true;
	cout << "Lua chon: " << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "so cong to moi: " << endl;
		int n_meterNum;
		do
		{
			cin >> n_meterNum;
			if (n_meterNum == temp->getMeterNumber())
			{
				check = true;
				cout << "giu nguyen gia tri cu";
				break;
			}
			else
			{
				if (contain(n_meterNum))
				{
					check = false;
					cout << "Da co so cong to nay" << endl;
				}
				check = true;
			}
		} while (!check);
		temp->setMeterNumber(n_meterNum);
		cout << "Da sua" << endl;
		break;
	}
	default:
		break;
	}
}
void MeterService::writeFile(string path)
{
	ofstream file(path, ios::out);
	if (file.is_open())
	{
		ElecMeter* meter = mHead;
		while (meter != NULL)
		{
			file << *meter;
			meter = meter->next;
		}
	}
	else
	{
		cout << "Khong tim thay duong dan" << endl;
	}
}
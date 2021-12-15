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
		}
	} while (!check);
	ElecMeter* meter = new ElecMeter(n_meterNum,0,0);

	if (mHead == NULL)
	{
		mHead = meter;
		mTail = meter;
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
	mAmount++;
}
void MeterService::readFile(string path)
{
	fstream file(path, ios::in);
	if (file.is_open())
	{
		ElecMeter* temp = mHead;
		while (temp->next != mHead)
		{
			string line;
			getline(file, line);
			temp->fromString(line);
		}
	}
}
bool MeterService::contain(int meterNum)
{
	ElecMeter* meter = mHead;
	while (meter!=NULL)
	{
		if (meter->getMeterNumber() == meterNum)
		{
			return true;
		}
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
	cout << "1- Xoa, 0- Huy"<<endl;
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
			do
			{
				cin.ignore();
				cout << "Nhap so cong to cua hoa don can xoa: " << endl;
				cin >> meterNumber;
			} while (contain(meterNumber));
			ElecMeter* after = mHead;
			ElecMeter* before = after;
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
				if (mHead == after)
				{
					mHead = after->next;
				}
				else
				{
					before->next = after->next;
				}
				mAmount--;
			}
		}
	}

}
void MeterService::display()
{
	ElecMeter* meter = mHead;
	cout<< "So cong to " << "\t\t" << "so dien truoc" << "\t\t" << "so dien sau" << "\t\t" << "so dien tieu thu" << endl;
	while (meter != NULL)
	{
		cout << *meter;
		meter = meter->next;
	}
}
const ElecMeter& MeterService::getMeter(int meterNumber)
{
	ElecMeter* temp = mHead;
	if (contain(meterNumber))
	{
		while (temp != NULL)
		{
			if (temp->getMeterNumber() == meterNumber)
			{
				cout << "da tim thay" << endl;
				return *temp;
			}
			temp = temp->next;
		}
	}

}
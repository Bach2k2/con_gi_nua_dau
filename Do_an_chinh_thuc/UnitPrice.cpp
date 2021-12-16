#include <iostream>
using namespace std;
#include "UnitPrice.h"
UnitPrice::UnitPrice(int unit)
{
	for (int i = 0; i < 6; i++)
	{
		this->unitRank[i] = 0;
		this->priceRank[i] = 0;
		this->rank[i] = 0;
	}
	this->unitMeter = unit;
	this->total = 0;
	this->peak = 1;
}
UnitPrice::~UnitPrice()
{
}
int UnitPrice::getUnit()
{
	return this->unitMeter;
}
void UnitPrice::setUnit(int unit)
{
	this->unitMeter = unit;
}
double UnitPrice::getPrice()
{
	cout << "Tong tien :";
	return this->total;
}
void UnitPrice::calcPrice()
{
	// Neu chi dien bac 1
	if (unitMeter <= 50)
	{
		peak = 1;
		unitRank[0] = unitMeter;
	}
	else
		//Neu chi dien bac 2:
		if (unitMeter <= 100)
		{
			peak = 2;
			unitRank[0] = 50;
			unitRank[1] = unitMeter - 50;
		}
		else
			//Neu chi dien bac 3:
			if (unitMeter <= 200)
			{
				peak = 3;
				unitRank[0] = 50;
				unitRank[1] = 50;
				unitRank[2] = unitMeter - 100;
			}
			else
				//Neu chi dien bac 4:
				if (unitMeter <= 300)
				{
					peak = 4;
					unitRank[0] = 50;
					unitRank[1] = 50;
					unitRank[2] = 100;
					unitRank[3] = unitMeter - 200;
				}
				else
					//Neu chi dien bac 5:
					if (unitMeter <= 400)
					{
						peak = 5;
						unitRank[0] = 50;
						unitRank[1] = 50;
						unitRank[2] = 100;
						unitRank[3] = 100;
						unitRank[4] = unitMeter - 300;
					}
	//Neu chi dien bac 6:
					else
					{
						peak = 6;
						unitRank[0] = 50;
						unitRank[1] = 50;
						unitRank[2] = 100;
						unitRank[3] = 100;
						unitRank[4] = 100;
						unitRank[5] = unitMeter - 400;
					}
	for (int i = 0; i < peak; i++)
	{
		priceRank[i] = unitRank[i] * rank[i];
		total += priceRank[i];
	}
}
void UnitPrice::showUnitPrice()
{
	cout << "\n Muc\tSo chi dien tai moi muc \t Gia tien tai moi muc" << endl;
	for (int i = 0; i < peak; i++)
	{
		cout << "\n" << i + 1 << "\t\t " << unitRank[i] << "  \t\t\t" << priceRank[i];
	}
	cout << "\n Muc cao nhat: " << this->peak;
	cout << "\n\t\t\t\t\t Tong tien:" << total << endl;
}
void UnitPrice::readData(string path)
{
	ifstream file(path, ios::in);
	if (file.is_open())
	{
		for (int i = 0; i < 6; i++) {
			file >> rank[i];
		}
	}
	for (int i = 0; i < 6; i++) {
		cout << rank[i] << endl;
	}
}
double UnitPrice::getTotalPrice()
{
	return total;
}
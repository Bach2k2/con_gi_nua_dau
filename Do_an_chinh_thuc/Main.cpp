#pragma once
#include<iostream>
#include "MeterService.h"
#include "CustomerService.h"
#include "BillService.h"
using namespace std;
BillService billManager;
MeterService meterManager;
CustomerService cusManager;
UnitPrice unitPrice;
void displayBillMenu();
void displayCustomerMenu();
void displayMainMenu();

int main()
{

	/*
	*/
	cout << "Nhap duong dan file bill  -- Nhap meter.txt" << endl;
	string mPath;
//	cin >> mPath;
	mPath = "meter.txt";
	meterManager.readFile(mPath);
	cout << "Calculate price" << endl;
	//	qli.calculatePrice();
	string path2;
	cout << "Nhap duong dan file customer  -- Nhap customer.txt" << endl;
	//cin >> path2;
	path2 = "customer.txt";
	cusManager.readDataInFile(path2);
	//	qli.display();
	displayMainMenu();
}
void displayBillMenu()
{
	int choice;
	do
	{
		system("cls");
		cout << "\n\n";
		cout << "\n\t\t\t|----------------------Menu---------------------|";
		cout << "\n\t\t\t|1. Them tat ca hoa don cho thang tiep theo|";
		cout << "\n\t\t\t|2. Cap nhat thong tin mot hoa don\t\t|";
		cout << "\n\t\t\t|3. Xuat ra mot hoa don\t\t\t|";
		cout << "\n\t\t\t|4. Xoa di mot hoa don\t\t\t\t|";
		cout << "\n\t\t\t|5. Hien thi het tat ca hoa don trong 1 thang\t\t\t|";
		cout << "\n\t\t\t|6. luu vao file tat ca hoa don\t\t\t|";
		cout << "\n\t\t\t|7. Quan ly hoa don theo tung khu vuc \t\t|";
		cout << "\n\t\t\t|0. Tro ve menu chinh\t\t\t|";
		cout << "\n\t\t\t|-----------------------------------------------|";
		cout << "\n\n\t\t\tNhap lua chon: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("cls");
			cout << "\nCHUC NANG: THEM MOI TAT CA HOA DON CHO THANG TIEP THEO" << endl;
			cout << "nhap file thang tiep theo can them" << endl;
			string monthPath;
			cin >> monthPath;
			billManager.readAMonth(monthPath);
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			cout << "\nCHUC NANG: CAP NHAT THONG TIN MOT HOA DON" << endl;

			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "\nCHUC NANG: TIM KIEM THONG TIN MOT HOA DON" << endl;
			cout << "\nNhap so cong to cua hoa don: ";
			billManager.search();
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "\nCHUC NANG: XOA MOT HOA DON";
			cout << "\nNhap so cong to cua hoa don can xoa: ";
			billManager.remove();
			cout << "Xoa thanh cong" << endl;
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			cout << "\nCHUC NANG: IN TAT CA HOA DON SAU KHI TINH TIEN";
			billManager.display();
			system("pause");
			break;
		}
		case 6:
		{
			cout << "\n CHUC NANG: IN TAT CA HOA DON THEO KHU VUC";
			cout << "Nhap khu vuc muon tim kiem:  " << endl;
			string area;
			getline(cin, area);
			billManager.displayWithArea(area);
			system("pause");
			break;
		}
		case 7:
		{
			/*
			* MonthList* qLiTheoThang = new MonthList();
			cout << "Quan ly danh sach cua hoa don theo thang" << endl;
			int MM, yy;
			cout << "Nhap thang: " << endl;
			cin >> MM;
			cout << "Nhap nam: " << endl;
			cin >> yy;
			qLiTheoThang->setMonthAndYear(MM, yy);
			qLiTheoThang->readFile(path);
			system("pause");
			qLiTheoThang->displayByMonth();
			cout << "Muon luu vao file ko?" << endl;
			qLiTheoThang->displayByMonth();
			int check = 0;
			cout << "Nhan 1 de co";
			cin >> check;
			if (check == 1)
			{
				string ofPath;
				cout << " Nhap duong dan: " << endl;
				cin >> ofPath;
				qLiTheoThang->printToFile(ofPath);
				system("pause");
			}
			delete qLiTheoThang;
			break;
			*/
			break;
		}
		case 0:
			cout << "\n\t\t\t------------------------Tam biet----------------------------------" << endl;
			break;
		default:
			cout << "Lua chon khong hop le" << endl;
			cout << "Moi nhap lai lua chon: " << endl;
			break;
		}
	} while (choice != 0);
}
void displayMeterMenu()
{
	int choice;
	do
	{
		system("cls");
		cout << "\n\n";
		cout << "\n\t\t\t|---------------------QUAN LY CONG TO DIEN---------------------|";
		cout << "\n\t\t\t|1. Them moi mot cong to  \t\t\t|";
		cout << "\n\t\t\t|2. Cap nhat thong tin mot cong to\t\t|";
		cout << "\n\t\t\t|3. Tim kiem mot cong to\t\t\t|";
		cout << "\n\t\t\t|4. Xoa mot cong to\t\t\t\t|";
		cout << "\n\t\t\t|5. Hien thi het tat ca cong to dang quan ly\t\t\t|";
		cout << "\n\t\t\t|6. In vao file tat ca cong to da cap nhat\t\t\t|";
		cout << "\n\t\t\t|7. Quan ly cong to theo tung thang  \t\t|";
		cout << "\n\t\t\t|0. Tro ve menu chinh\t\t\t|";
		cout << "\n\t\t\t|---------------------------------------------------------------|";
		cout << "\n\n\t\t\tNhap lua chon: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("cls");
			cout << "\nCHUC NANG: THEM MOI MOT CONG TO. " << endl;
			meterManager.add();
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			cout << "\nCHUC NANG: CAP NHAT THONG TIN MOT CONG TO" << endl;
			meterManager.update();
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "\nCHUC NANG: TIM KIEM THONG TIN MOT CONG TO" << endl;
			cout << "\nNhap so cong to cua hoa don: ";
			meterManager.search();
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "\nCHUC NANG: XOA MOT CONG TO";
			meterManager.remove();
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			meterManager.display();
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			cout << "\nCHUC NANG: IN VAO FILE TAT CA CONG TO DA NHAP" << endl;
			string mPath;
			cout << "nhap duong dan can luu" << endl;
			cin >> mPath;
			meterManager.writeFile(mPath);
			system("pause");
			break;
		}
		case 7:
		{
			/*
			* MonthList* qLiTheoThang = new MonthList();
			cout << "Quan ly danh sach cua hoa don theo thang" << endl;
			int MM, yy;
			cout << "Nhap thang: " << endl;
			cin >> MM;
			cout << "Nhap nam: " << endl;
			cin >> yy;
			qLiTheoThang->setMonthAndYear(MM, yy);
			qLiTheoThang->readFile(path);
			system("pause");
			qLiTheoThang->displayByMonth();
			cout << "Muon luu vao file ko?" << endl;
			qLiTheoThang->displayByMonth();
			int check = 0;
			cout << "Nhan 1 de co";
			cin >> check;
			if (check == 1)
			{
				string ofPath;
				cout << " Nhap duong dan: " << endl;
				cin >> ofPath;
				qLiTheoThang->printToFile(ofPath);
				system("pause");
			}
			delete qLiTheoThang;
			break;
			*/
			break;
		}
		case 0:
			cout << "\n\t\t\t------------------------Tam biet----------------------------------" << endl;
			break;
		default:
			cout << "Lua chon khong hop le" << endl;
			cout << "Moi nhap lai lua chon: " << endl;
			break;
		}
	} while (choice != 0);
}
void displayCustomerMenu()
{
	int choice;
	do
	{
		system("cls");
		cout << "\n\n";
		cout << "\n\t\t\t|----------------------Quan ly Khach Hang---------------------|";
		cout << "\n\t\t\t|1. Them moi khach hang \t\t\t|";
		cout << "\n\t\t\t|2. Cap nhat thong tin khach hang\t\t|";
		cout << "\n\t\t\t|3. Tim kiem mot khach hang\t\t\t|";
		cout << "\n\t\t\t|4. Xoa di mot khach hang\t\t\t|";
		cout << "\n\t\t\t|5. In danh sach cua tat ca khach hang\t\t|";
		cout << "\n\t\t\t|6. Dua du lieu vao file\t\t\t|";
		cout << "\n\t\t\t|7. Sap xep tat ca khach hang theo ten\t\t\t|";
		cout << "\n\t\t\t|0. Tro ve menu chinh   \t\t\t|";
		cout << "\n\t\t\t|-------------------------------------------------------------|";
		cout << "\n\n\t\t\tNhap lua chon : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("cls");
			cout << "\nCHUC NANG: THEM KHACH HANG " << endl;
			cusManager.enqueue();
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			cout << "\nCHUC NANG: THAY DOI THONG TIN CUA KHACH HANG " << endl;
			//	cout << "\nNhap so cong to cua khach hang:";
			cusManager.update();
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "\nCHUC NANG: TIM KIEM KHACH HANG " << endl;
			//	cout << "\nNhap so cong to cua khach hang:";
			cusManager.searchByName();
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "\nCHUC NANG: XOA KHACH HANG" << endl;
			//	cout << "\nNhap so cong to cua khach hang:";
			cout << "Xoa thanh cong" << endl;
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			cusManager.display();
			system("pause");
			break;
		}
		case 6:
		{
			cout << "Nhap ten file" << endl;
			string KhPath;
			cin >> KhPath;
			cusManager.writeDataInFile(KhPath);
			system("pause");
			break;
		}
		case 0:
			cout << "\n\t\t\t---------Trở về menu----------" << endl;
			system("pause");
			break;
		default:
			cout << "Nhap lua chon khong dung! ";
			break;
		}
	} while (choice != 0);
}
void displayMainMenu()
{
	int choice;
	do
	{
		system("cls");
		cout << "\n\n";
		cout << "\n\t\t\t|--------------------Menu chinh----------------|";
		cout << "\n\t\t\t|1. Quan ly cong to dien \t\t\t|";
		cout << "\n\t\t\t|2. Quan ly khach hang\t\t\t|";
		cout << "\n\t\t\t|3. Quan ly hoa don \t\t\t|";
		cout << "\n\t\t\t|0. Thoat\t\t\t\t\t|";
		cout << "\n\t\t\t|-----------------------------------------------|";
		cout << "\n\n\t\t\tNhap lua chon: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			displayMeterMenu();
			break;
		}
		case 2:
		{
			displayCustomerMenu();
			break;
		}
		case 3:
		{
			displayBillMenu();
			break;
		}
		case 0:
		{
			cout << "Tam biet" << endl;
			break;
		}
		default:
		{
			cout << "Lua chon sai!" << endl;
		}
		}
	} while (choice != 0);
}


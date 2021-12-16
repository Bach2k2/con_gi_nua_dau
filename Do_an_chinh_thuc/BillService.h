#pragma once
#include "ElecBill.h"
#include "MeterService.h"
#include "CustomerService.h"
class BillService
{
private:         //BillService
    ElecBill* pHead; //
    ElecBill* pTail;
    static int billAmount;
    
    
public:

    BillService();
    ~BillService();
    MeterService meterList;
    CustomerService cusList;
    void setMetAndCus();//Thêm nhập từ bàn phím
    void add(ElecBill*);// Nhận từ file
    bool isEmpty();// Danh sách có rỗng
    void remove();// Xóa
    void removeFirst();//Xóa
    void removeAll();// Xóa hết
    void update();  //chưa làm .
    void display(); // Rồi
    void search();  // chưa làm đc
    void readFile(string path); // Đọc file

    bool contain(int);
    void calculatePrice();

    void writeIntoFile(string path);
    void readTwoId(string path);
    void readAMonth(string path);
    void displayWithArea(string);
};


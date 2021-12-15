#include "ElecMeter.h"
class MeterService
{

private:        
        ElecMeter* mHead; //
        ElecMeter* mTail;
        static int mAmount;
   public:
        MeterService();
        ~MeterService();
        MeterService* next;
        void add();//Thêm nhập từ bàn phím
        void add(ElecMeter* bill);// Nhận từ file
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
        void MonthManger();
        const ElecMeter& getMeter(int meterNum);
 };



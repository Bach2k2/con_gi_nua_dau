#include <iostream>
using namespace std;
class Date
{
private:
	int day;
	int month;
	int year;
	static int days[];// Mang chu so ngay
	void increaseDay();//Ham tang ngay len 1
public:
	Date(int D = 1, int M = 1, int Y = 1900);
	void setDate(int, int, int);
	Date operator++(); //Tien to
	Date operator++(int);// Hau to
	const Date& operator +=(int);
	int isLeapYear(int); // Kiem tra nam nhuan
	int endOfMonth(int);//Kiem tra cuoi thang
	friend ostream& operator<<(ostream&, const Date&);
	int getMonth();
};


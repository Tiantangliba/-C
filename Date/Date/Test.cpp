 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;


class Date
{
public:
	//Date()//����
	//{
	//	_year = 1;
	//	_month = 1;
	//	_day = 1;
	//}
	//Date(int year, int month, int day)//���������
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	Date(int year=1, int month=1, int day=1)//����ȱʡֵ�Ĺ���
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)//�������죬һ����const����
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void Print()//��ͨ�������ᴫthisָ��
	{
		cout << _year << "��" << _month << "��" << _day << "��" << endl;
	}

	int GetMonthDday(int year,int month)
	{
		assert(month > 0 && month < 13);
		int monthArr[] = { 0, 13, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		return monthArr[month];
	}

	Date GetXDayAfter(int x)//+
	{
		//Date tmp(*this);
		Date tmp = *this;//�����м����������ԭ����d2ֵҲ����

		tmp._day += x;
		while (tmp._day > GetMonthDday(tmp._year, tmp._month))
		{
			tmp._day -= GetMonthDday(tmp._year, tmp._month);
			tmp._month++;
			if (tmp._month == 13)
			{
				tmp._year++;
				tmp._month = 1;
			}
		}
		return tmp;
	}

	Date& AddEqual(int x)   //+=  //����������*this���ڣ�������������
	{
		_day += x;
		while (_day > GetMonthDday(_year, _month))
		{
			_day -= GetMonthDday(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	Date d2(2023, 2, 9);
	Date d3(2023, 2);

	Date d4(d1);//��������
	Date d5 = d1;//��������

	//ʵ��һ����������ȡ�������Ժ������
	Date d6 = d2.GetXDayAfter(100);
	d1.Print();
	d2.Print();
	d3.Print();
	d6.Print();
	return 0;
}
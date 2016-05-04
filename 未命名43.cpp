#include<iostream>
#include<cstring>
using std::string;
using namespace std;
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
//	Sales_data data1, data2;
//	double price = 0;	//书的单价 
//	cin >> data1.bookNo >> data1.units_sold >> price;
//	data1.revenue = data1.units_sold * price;	//计算收入
//	
//	cin >> data2.bookNo >> data2.units_sold >> price;
//	data2.revenue = data2.units_sold * price;	//计算收入 
//	
//	if(data1.bookNo == data2.bookNo) {
//		unsigned totalCnt = data1.units_sold + data1.units_sold;
//		double totalRevenue = data1.revenue + data2.revenue;
//		//输出
//		cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " " ;
//		
//		if(totalCnt != 0) 
//			cout << totalRevenue / totalCnt << endl;
//		else
//			cout << "(no sales)" << endl;
//		return 0;
//	} else {
//		cerr << "Data must refer to the same ISBN" << endl;
//		return -1;
//	}

	string s(10, 'c');
	cout << s << endl;
	return 0;
}

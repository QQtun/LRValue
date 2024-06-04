#include <iostream>
#include <vector>
#include "DataV1.h"
#include "DataV2.h"
#include "DataV3.h"
#include "DataV4.h"
#include "DataV5.h"
#include "DataV6.h"


void TestV1() 
{
	typedef DataV1 Data;

	Data d(10, 123);
	Data d2 = Data::GenData(20, 456); // 編譯器優化掉一個拷貝建構式
	d.PrintData();
	d2.PrintData();

	Data d3 = d;
	d.PrintData();
	d3.PrintData();

	Data d4 = std::move(d2);
	d2.PrintData();
	d4.PrintData();

	Data d5;
	d5 = d;
	d.PrintData();
	d5.PrintData();

	Data d6;
	d6 = std::move(d);
	d.PrintData();
	d6.PrintData();
}

void TestV2()
{
	typedef DataV2 Data;

	Data d(10, 123);
	Data d2 = Data::GenData(20, 456);  // 編譯器優化掉一個移動建構式
	d.PrintData();
	d2.PrintData();

	//Data d3 = d; // compile error
	//d.PrintData();
	//d3.PrintData();

	Data d4 = std::move(d2);  // d2失效
	d2.PrintData();
	d4.PrintData();
}

void TestV3()
{
	typedef DataV3 Data;

	Data d(10, 123);
	Data d2 = Data::GenData(20, 456);  // 編譯器優化掉一個移動建構式
	d.PrintData();
	d2.PrintData();

	Data d3 = d; 
	d.PrintData();
	d3.PrintData();

	Data d4 = std::move(d2);  // d2失效
	d2.PrintData();
	d4.PrintData();
}

void TestV4()
{
	typedef DataV4 Data;

	Data d(10, 123);
	Data d2 = Data::GenData(20, 456);  // 編譯器優化掉一個移動建構式
	d.PrintData();
	d2.PrintData();

	Data d3 = d;
	d.PrintData();
	d3.PrintData();

	Data d4 = std::move(d2);  // d2失效
	d2.PrintData();
	d4.PrintData();

	Data d5;
	d5 = d;
	d.PrintData();
	d5.PrintData();

	Data d6;
	d6 = std::move(d);
	d.PrintData();
	d6.PrintData();
}

void TestV5()
{
	typedef DataV5 Data;

	Data d(10, 123);
	Data d2 = Data::GenData(20, 456);  // 編譯器優化掉一個移動建構式
	d.PrintData();
	d2.PrintData();

	Data d3 = d;
	d.PrintData();
	d3.PrintData();

	Data d4 = std::move(d2);  // d2失效
	d2.PrintData();
	d4.PrintData();

	//Data d5;
	//d5 = d;  // compile error
	//d.PrintData();
	//d5.PrintData();

	Data d6;
	d6 = std::move(d);  // d失效
	d.PrintData();
	d6.PrintData();
}

void TestV6()
{
	typedef DataV6 Data;

	Data d(10, 123);
	Data d2 = Data::GenData(20, 456);  // 編譯器優化掉一個移動建構式
	d.PrintData();
	d2.PrintData();

	Data d3 = d;
	d.PrintData();
	d3.PrintData();

	Data d4 = std::move(d2);  // d2失效
	d2.PrintData();
	d4.PrintData();

	Data d5;
	d5 = d;
	d.PrintData();
	d5.PrintData();

	Data d6;
	d6 = std::move(d);  // d失效
	d.PrintData();
	d6.PrintData();
}

void TestV7()
{
	typedef DataV6 Data;

	Data d(10, 123);
	Data&& d2 = Data::GenData(20, 456);  // 編譯器優化掉一個移動建構式
	d.PrintData();
	d2.PrintData();

	Data d3 = d;
	d.PrintData();
	d3.PrintData();

	Data&& d4 = std::move(d2);  // 沒有事情發生
	d2.PrintData();
	d4.PrintData();

	d4.ClearData();
	d2.PrintData(); // size 0
	d4.PrintData(); // size 0

	d4 = std::move(d3); // d3失效
	d3.PrintData();
	d4.PrintData();
}

void TestV8() 
{
	typedef DataV6 Data;

	Data a(1, 123); // init
	Data&& b = Data(2, 444);

	std::vector<Data> v;
	v.reserve(10);
	v.push_back(a); // copy
	v.push_back(b); // copy
	v.push_back(std::move(a)); // move
	v.push_back(Data(1, 222)); // init > move
	v.emplace_back(1, 333); // init

	std::cout << "v.size " << v.size() << std::endl;
}

int main(int* args)
{
	std::cout << "========== Test1 Start ============" << std::endl;
	TestV1();
	std::cout << "========== Test2 Start ============" << std::endl;
	TestV2();
	std::cout << "========== Test3 Start ============" << std::endl;
	TestV3();
	std::cout << "========== Test4 Start ============" << std::endl;
	TestV4();
	std::cout << "========== Test5 Start ============" << std::endl;
	TestV5();
	std::cout << "========== Test6 Start ============" << std::endl;
	TestV6();
	std::cout << "========== Test7 Start ============" << std::endl;
	TestV7();
	std::cout << "========== Test8 Start ============" << std::endl;
	TestV8();

	return 0;
}
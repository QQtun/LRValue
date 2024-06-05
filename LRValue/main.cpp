#include <iostream>
#include <vector>
#include <map>
#include "DataV1.h"
#include "DataV2.h"
#include "DataV3.h"
#include "DataV4.h"
#include "DataV5.h"
#include "DataV6.h"
#include "FullData.h"


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

void Push(std::vector<DataV6>& v, DataV6& d)
{
	v.push_back(std::move(d));
}

void TestV8() 
{
	typedef DataV6 Data;

	Data a(1, 123); // init
	Data&& b = Data(2, 444);

	std::vector<Data> v;
	v.reserve(10);
	//v.push_back(a); // copy
	//v.push_back(b); // copy
	//v.push_back(std::move(a)); // move
	//v.push_back(Data(1, 222)); // init > move
	//v.emplace_back(1, 333); // init
	Push(v, a);
	a.PrintData();

	std::cout << "v.size " << v.size() << std::endl;
}

void TestFullData()
{
	std::cout << "========== Ctor ============" << std::endl;
	FullData a(1);
	FullData b(2);
	FullData c(3);
	FullData f(3);
	FullData& d = a;
	FullData&& e = std::move(a);
	std::cout << "========== Ctor End ============" << std::endl;

	//std::vector<FullData> v;
	//v.reserve(1000);
	//std::cout << "========== push_back(a) ============" << std::endl;
	//v.push_back(a);
	//std::cout << "========== push_back(d) ============" << std::endl;
	//v.push_back(d);
	//std::cout << "========== push_back(e) ============" << std::endl;
	//v.push_back(e);
	//std::cout << "========== push_back(std::move(b)) ============" << std::endl;
	//v.push_back(std::move(b)); // b失效
	//std::cout << "========== push_back(FullData(4)) ============" << std::endl;
	//v.push_back(FullData(4));
	//std::cout << "========== push_back(5) ============" << std::endl;
	//v.push_back(5);
	//std::cout << "========== emplace_back(a) ============" << std::endl;
	//v.emplace_back(a);
	//std::cout << "========== emplace_back(d) ============" << std::endl;
	//v.emplace_back(d);
	//std::cout << "========== emplace_back(e) ============" << std::endl;
	//v.emplace_back(e);
	//std::cout << "========== emplace_back(std::move(c)) ============" << std::endl;
	//v.emplace_back(std::move(c)); // c 失效
	//std::cout << "========== emplace_back(FullData(4)) ============" << std::endl;
	//v.emplace_back(FullData(4));
	//std::cout << "========== emplace_back(5) ============" << std::endl;
	//v.emplace_back(5);
	//std::cout << "========== End ============" << std::endl;

	//for (auto it = v.begin(); it != v.end(); ++it)
	//{
	//	std::cout << *(*it).data << std::endl;
	//}

	std::pair<int, FullData> aPair(1, a);
	std::pair<int, FullData> bPair(2, b);
	std::pair<int, FullData> cPair(3, c);
	std::pair<int, FullData> fPair(4, f);


	{
		std::map<int, FullData> m;
		std::cout << "========== insert(aPair) ============" << std::endl;
		m.insert(aPair); // copy * 2
		std::cout << "========== insert({ 2, b }) ============" << std::endl;
		m.insert({ 2, b }); // copy *2 + move * 1
		std::cout << "========== insert(std::move(cPair)) ============" << std::endl;
		m.insert(std::move(cPair)); // copy * 2
	}

	{
		std::map<int, FullData> m;
		std::cout << "========== emplace(aPair) ============" << std::endl;
		m.emplace(aPair); // copy * 2
		std::cout << "========== emplace(2, b) ============" << std::endl;
		m.emplace(2, b); // copy * 1
		std::cout << "========== emplace(std::move(fPair)) ============" << std::endl;
		m.emplace(std::move(fPair)); // copy * 1 + move * 1
	}
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
	std::cout << "========== TestFullData Start =====" << std::endl;
	TestFullData();

	return 0;
}
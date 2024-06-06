#include <vector>
#include <iostream>

#pragma once


/// <summary>
/// 拷貝建構式 X
/// 移動建構式 X
/// </summary>
class DataV0
{
public:
	DataV0() {}

	DataV0(int l, int initValue) : m_data(l, initValue)
	{
		std::cout << "Init Ctor" << std::endl;
	}

	//DataV0(const DataV0& other) : m_data(other.m_data)
	//{
	//	std::cout << "Copy Ctor" << std::endl;
	//}

	//DataV0(DataV1&& other) noexcept : m_data(std::move(other.m_data))
	//{
	//	std::cout << "Move Ctor" << std::endl;
	//}
	//~DataV0()
	//{
	//	std::cout << "Dtor" << std::endl;
	//}

	static DataV0 GenData(int l, int initValue)
	{
		DataV0 d(l, initValue);
		std::cout << "Gen ";
		d.PrintData();
		return d;
	}

	void PrintData() const
	{
		std::cout << "data " << m_data.data() << " size " << m_data.size() << std::endl;
	}
private:
	std::vector<int> m_data;
};
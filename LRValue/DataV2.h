#include <vector>
#include <iostream>

#pragma once


/// <summary>
/// 拷貝建構式 X
/// 移動建構式 O
/// </summary>
class DataV2
{
public:
	DataV2() {}

	DataV2(int l, int initValue) : m_data(l, initValue)
	{
		std::cout << "Init Ctor" << std::endl;
	}

	//DataV2(const DataV2& other) : m_data(other.m_data)
	//{
	//	std::cout << "Copy Ctor" << std::endl;
	//}

	DataV2(DataV2&& other) noexcept : m_data(std::move(other.m_data))
	{
		std::cout << "Move Ctor" << std::endl;
	}

	static DataV2 GenData(int l, int initValue)
	{
		DataV2 d(l, initValue);
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
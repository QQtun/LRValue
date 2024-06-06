#include <vector>
#include <iostream>

#pragma once


/// <summary>
/// 拷貝建構式 O
/// 移動建構式 O
/// </summary>
class DataV3
{
public:
	DataV3() {}

	DataV3(int l, int initValue) : m_data(l, initValue)
	{
		std::cout << "Init Ctor" << std::endl;
	}

	DataV3(const DataV3& other) : m_data(other.m_data)
	{
		std::cout << "Copy Ctor" << std::endl;
	}

	DataV3(DataV3&& other) noexcept : m_data(std::move(other.m_data))
	{
		std::cout << "Move Ctor" << std::endl;
	}

	static DataV3 GenData(int l, int initValue)
	{
		DataV3 d(l, initValue);
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
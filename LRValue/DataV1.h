#include <vector>
#include <iostream>

#pragma once


/// <summary>
/// 拷貝建構式 O
/// 移動建構式 X
/// </summary>
class DataV1
{
public:
	DataV1() {}

	DataV1(int l, int initValue) : m_data(l, initValue)
	{
		std::cout << "Init Ctor" << std::endl;
	}

	DataV1(const DataV1& other) : m_data(other.m_data)
	{
		std::cout << "Copy Ctor" << std::endl;
	}	
	
	//DataV1(DataV1&& other) noexcept : m_data(std::move(other.m_data))
	//{
	//	std::cout << "Move Ctor" << std::endl;
	//}

	static DataV1 GenData(int l, int initValue)
	{
		DataV1 d(l, initValue);
		return d;
	}

	void PrintData()
	{
		std::cout << "data " << m_data.data() << " size " << m_data.size() << std::endl;
	}
private:
	std::vector<int> m_data;
};
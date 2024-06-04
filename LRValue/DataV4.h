#include <vector>
#include <iostream>

#pragma once


/// <summary>
/// ī篶Α O
/// 簿笆篶Α O
/// ī结才 O
/// 簿笆结才 X
/// </summary>
class DataV4
{
public:
	DataV4() {}

	DataV4(int l, int initValue) : m_data(l, initValue)
	{
		std::cout << "Init Ctor" << std::endl;
	}

	DataV4(const DataV4& other) : m_data(other.m_data)
	{
		std::cout << "Copy Ctor" << std::endl;
	}

	DataV4(DataV4&& other) noexcept : m_data(std::move(other.m_data))
	{
		std::cout << "Move Ctor" << std::endl;
	}

	static DataV4 GenData(int l, int initValue)
	{
		DataV4 d(l, initValue);
		return d;
	}

	void PrintData()
	{
		std::cout << "data " << m_data.data() << " size " << m_data.size() << std::endl;
	}

	DataV4& operator= (const DataV4& other) 
	{
		std::cout << "Copy Optor" << std::endl;
		m_data = other.m_data;
		return *this;
	}
private:
	std::vector<int> m_data;
};
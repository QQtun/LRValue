#include <vector>
#include <iostream>

#pragma once


/// <summary>
/// ī篶Α O
/// 簿笆篶Α O
/// ī结才 X
/// 簿笆结才 O
/// </summary>
class DataV5
{
public:
	DataV5() {}

	DataV5(int l, int initValue) : m_data(l, initValue)
	{
		std::cout << "Init Ctor" << std::endl;
	}

	DataV5(const DataV5& other) : m_data(other.m_data)
	{
		std::cout << "Copy Ctor" << std::endl;
	}

	DataV5(DataV5&& other) noexcept : m_data(std::move(other.m_data))
	{
		std::cout << "Move Ctor" << std::endl;
	}

	static DataV5 GenData(int l, int initValue)
	{
		DataV5 d(l, initValue);
		return d;
	}

	void PrintData()
	{
		std::cout << "data " << m_data.data() << " size " << m_data.size() << std::endl;
	}

	//DataV5& operator= (const DataV5& other)
	//{
	//	std::cout << "Copy Optor" << std::endl;
	//	m_data = other.m_data;
	//	return *this;
	//}

	DataV5& operator= (DataV5&& other) noexcept
	{
		std::cout << "Move Optor" << std::endl;
		m_data = std::move(other.m_data);
		return *this;
	}
private:
	std::vector<int> m_data;
};
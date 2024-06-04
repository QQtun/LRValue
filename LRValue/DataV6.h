#include <vector>
#include <iostream>

#pragma once


/// <summary>
/// 拷貝建構式 O
/// 移動建構式 O
/// 拷貝賦值符 O
/// 移動賦值符 O
/// </summary>
class DataV6
{
public:
	DataV6() {}

	DataV6(int l, int initValue) : m_data(l, initValue)
	{
		std::cout << "Init Ctor" << std::endl;
	}

	DataV6(const DataV6& other) : m_data(other.m_data)
	{
		std::cout << "Copy Ctor" << std::endl;
	}

	DataV6(DataV6&& other) noexcept : m_data(std::move(other.m_data))
	{
		std::cout << "Move Ctor" << std::endl;
	}

	static DataV6 GenData(int l, int initValue)
	{
		DataV6 d(l, initValue);
		return d;
	}

	void PrintData()
	{
		std::cout << "data " << m_data.data() << " size " << m_data.size() << std::endl;
	}

	void ClearData() 
	{
		m_data.clear();
		std::cout << "Clear data " << m_data.data() << " size " << m_data.size() << std::endl;
	}

	DataV6& operator= (const DataV6& other)
	{
		std::cout << "Copy Optor" << std::endl;
		m_data = other.m_data;
		return *this;
	}

	DataV6& operator= (DataV6&& other) noexcept
	{
		std::cout << "Move Optor" << std::endl;
		m_data = std::move(other.m_data);
		return *this;
	}
private:
	std::vector<int> m_data;
};
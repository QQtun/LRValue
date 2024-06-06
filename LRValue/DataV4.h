#include <vector>
#include <iostream>

#pragma once


/// <summary>
/// 拷貝建構式 O
/// 移動建構式 O
/// 拷貝賦值符 O
/// 移動賦值符 X
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
		std::cout << "Gen ";
		d.PrintData();
		return d;
	}

	void PrintData() const
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
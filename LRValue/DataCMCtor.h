#include <memory>
#include <iostream>
#include <vector>

#pragma once

class DataCMCtor
{
public:
	DataCMCtor() : m_data(nullptr) {}

	DataCMCtor(const char* c) : m_data(new std::string(c))
	{
		std::cout << "CM Init Ctor" << std::endl;
	}

	DataCMCtor(const DataCMCtor& other) : m_data(new std::string(*other.m_data))
	{
		std::cout << "CM Copy Ctor" << std::endl;
	}

	DataCMCtor(DataCMCtor&& other) noexcept : m_data(other.m_data)
	{
		std::cout << "CM Move Ctor" << std::endl;
		other.m_data = nullptr;
	}

	~DataCMCtor()
	{
		std::cout << "CM Dtor" << std::endl;
		if(m_data != nullptr)
		{
			delete m_data;
			m_data = nullptr;
		}
	}

	void PrintData() const
	{
		if (m_data != nullptr)
		{
			std::cout << "CM data " << m_data << " size " << m_data->size() << std::endl;
		}
		else
		{
			std::cout << "CM data nullptr" << std::endl;
		}
	}
private:
	std::string* m_data;
};

class DataCCtor
{
public:
	DataCCtor() : m_data(nullptr) {}

	DataCCtor(const char* c) : m_data(new std::string(c))
	{
		std::cout << "C Init Ctor" << std::endl;
	}

	DataCCtor(const DataCCtor& other) : m_data(new std::string(*other.m_data))
	{
		std::cout << "C Copy Ctor" << std::endl;
	}

	//DataCCtor(DataCCtor&& other) noexcept : m_data(other.m_data)
	//{
	//	std::cout << "C Move Ctor" << std::endl;
	//	other.m_data = nullptr;
	//}

	~DataCCtor()
	{
		std::cout << "C Dtor" << std::endl;
		if (m_data != nullptr)
		{
			delete m_data;
			m_data = nullptr;
		}
	}
public:
	void PrintData() const
	{
		if (m_data != nullptr)
		{
			std::cout << "C data " << m_data << " size " << m_data->size() << std::endl;
		}
		else
		{
			std::cout << "C data nullptr" << std::endl;
		}
	}
private:
	std::string* m_data;
};

class DataMCtor
{
public:
	DataMCtor() : m_data(nullptr) {}

	DataMCtor(const char* c) : m_data(new std::string(c))
	{
		std::cout << "M Init Ctor" << std::endl;
	}

	//DataMCtor(const DataMCtor& other) : m_data(new std::string(*other.m_data))
	//{
	//	std::cout << "CM Copy Ctor" << std::endl;
	//}

	DataMCtor(DataMCtor&& other) noexcept : m_data(other.m_data)
	{
		std::cout << "M Move Ctor" << std::endl;
		other.m_data = nullptr;
	}

	~DataMCtor()
	{
		std::cout << "M Dtor" << std::endl;
		if (m_data != nullptr)
		{
			delete m_data;
			m_data = nullptr;
		}
	}

	void PrintData() const
	{
		if (m_data != nullptr)
		{
			std::cout << "M data " << m_data << " size " << m_data->size() << std::endl;
		}
		else
		{
			std::cout << "M data nullptr" << std::endl;
		}
	}
private:
	std::string* m_data;
};

class DataNoCtorV1
{
public:
	DataNoCtorV1(const char* c1, const char* c2) : m_cmData(c1), m_cData(c2) {}

	void PrintData() const
	{
		std::cout << "=== DataNoCtorV1 Print Start ==" << std::endl;
		m_cmData.PrintData();
		m_cData.PrintData();
		std::cout << "=== DataNoCtorV1 Print End ==" << std::endl;
	}
private:
	DataCMCtor m_cmData;
	DataCCtor m_cData;
};

class DataNoCtorV2
{
public:
	DataNoCtorV2(const char* c1, const char* c2) : m_cmData(c1), m_mData(c2) {}

	void PrintData() const
	{
		std::cout << "=== DataNoCtorV2 Print Start ==" << std::endl;
		m_cmData.PrintData();
		m_mData.PrintData();
		std::cout << "=== DataNoCtorV2 Print End ==" << std::endl;
	}
private:
	DataCMCtor m_cmData;
	DataMCtor m_mData;
};

class DataNoCtorV3
{
public:
	DataNoCtorV3(const char* c1, const char* c2) : m_cData(c1), m_mData(c2) {}

	void PrintData() const
	{
		std::cout << "=== DataNoCtorV3 Print Start ==" << std::endl;
		m_cData.PrintData();
		m_mData.PrintData();
		std::cout << "=== DataNoCtorV3 Print End ==" << std::endl;
	}
private:
	DataCCtor m_cData;
	DataMCtor m_mData;
};

class DataNoCtorV4
{
public:
	DataNoCtorV4(const char* c1, const char* c2, const char* c3) : m_cmData(c1), m_cData(c2), m_mData(c3) {}

	void PrintData() const
	{
		std::cout << "=== DataNoCtorV4 Print Start ==" << std::endl;
		m_cmData.PrintData();
		m_cData.PrintData();
		m_mData.PrintData();
		std::cout << "=== DataNoCtorV4 Print End ==" << std::endl;
	}
private:
	DataCMCtor m_cmData;
	DataCCtor m_cData;
	DataMCtor m_mData;
};
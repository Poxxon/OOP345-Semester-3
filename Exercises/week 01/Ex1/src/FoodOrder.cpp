#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "FoodOrder.h"

using namespace std;

double g_taxrate = 0;
double g_dailydiscount = 0;

namespace seneca
{
	void FoodOrder::read(istream& is)
	{
		if (is)
		{
			//Reads up to 9 input stops when a comma is encountered
			is.getline(m_customerName, 10, ',');

			//if m_orderDesc already has allocated memory it will free the memory
			if (m_orderDesc)
				delete[] m_orderDesc;

			//creates tempt std::string to store the next line of input
			//reads the order desc
			string buffer;
			getline(is, buffer, ',');

			//dynamically allocate memory for order desc
			//copy buffer into order desc converted into c string
			m_orderDesc = new char[buffer.length() + 1];
			strcpy(m_orderDesc, buffer.c_str());

			//store price into m_price
			is >> m_price;
			char tmp{ 'N' };
			is.ignore();
			is >> tmp;
			tmp == 'N' ? m_dailyspecial = false : m_dailyspecial = true;
		}
	}

	void FoodOrder::display() const
	{
		//keeps track of the number of orders displayed
		static size_t numOrders = 0;
		//displays order num
		cout << left << setw(2) << ++numOrders << ". ";

		//checks to see if the customer name is not empty
		//if the first character is not null terminator
		if (m_customerName[0])
		{
			double priceTaxed = m_price + (m_price * g_taxrate);
			cout << setw(10) << m_customerName << "|"
				 << setw(25) << m_orderDesc << "|"
				 << fixed << setw(12) << setprecision(2) << priceTaxed << "|";
			if (m_dailyspecial)
				cout << right << setprecision(2) << setw(13) << priceTaxed - g_dailydiscount;
		}
		else
			cout << "No Order";
		cout << endl;
	}

	//Destructor
	FoodOrder::~FoodOrder()
	{
		delete [] m_orderDesc;
	}

	//Copy constructor
	//Copy foodOrder object to new object
	FoodOrder::FoodOrder(const FoodOrder& src)
	{
		*this = src;
	}

	//Assignment operator
	FoodOrder& FoodOrder::operator=(const FoodOrder& src)
	{
		if (this != &src)
		{
			delete [] m_orderDesc;
			m_orderDesc = nullptr;

			// Shallow copy
			strcpy(m_customerName, src.m_customerName);
			m_price = src.m_price;
			m_dailyspecial = src.m_dailyspecial;

			// Deep Copy
			if (src.m_orderDesc)
			{
				m_orderDesc = new char [strlen(src.m_orderDesc) + 1];
				strcpy(m_orderDesc, src.m_orderDesc);
			}
		}
		return *this;
	}
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename numberType>

struct IsMultiple
{
	numberType m_Divisor;
	//divisoralize the divisor
	IsMultiple (const numberType& divisor)
	{
		m_Divisor = divisor;
	}
	
	//The comparator of type: bool f(x)
	bool operator () (const numberType&element ) const 
	{
		//Check if the dividend is a multiple of the divisor
		return ((element % m_Divisor) == 0);		
	}
};
int main()
{
	std::vector<int> vInt;

	cout << "The vector contains the following sample values: ";

	for (int nCount = 25;nCount < 32 ; ++nCount)
	{
		vInt.push_back(nCount);
		cout << nCount << ' ';
	}	
	cout << endl;

	//Find the tirst element that is a multiple of 4 in the collection
	std::vector<int>::iterator iElement;
	iElement = find_if(vInt.begin()
		,vInt.end()
		,IsMultiple<int> (4) );

	if(iElement != vInt.end())
	{
		cout << "The first element in the vector divisible by 4 is: ";
		cout << *iElement << endl;
	}
	return 0;


}
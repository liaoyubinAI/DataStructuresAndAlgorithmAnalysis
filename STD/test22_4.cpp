#include <algorithm>
#include <iostream>
#include <vector>

template <typename elementType>
class CMultiply
{
public:
	elementType operator() (const elementType& elem1,
		const elementType&elem2)
	{
		return (elem1 * elem2);
	}	
};

int main()
{
	using namespace std;
	std::vector<int> v1,v2,result;
	for (int nCount = 0;nCount < 10; ++nCount)
		v1.push_back(nCount);
	for (int nCount1 = 100; nCount1 < 110; ++ nCount1)
		v2.push_back(nCount1);

	result.resize(10);
	transform (v1.begin(),
		v1.end(),
		v2.begin(),
		result.begin(),
		CMultiply<int>() );

	cout << "The contents of the first vector are: "<< endl;
	for (size_t nIndex1 = 0; nIndex1 < v1.size(); ++nIndex1)
		cout << v1[nIndex1] << ' ';
	cout << endl;

	cout << "The contents of the second vector are : " << endl;
	for (size_t nIndex2 = 0; nIndex2 < v2.size(); ++ nIndex2)
		cout << v2[nIndex2] <<  ' ' ;
	cout << endl << endl;

	cout << "The result of the multiplication is : " << endl;
	for (size_t nIndex = 0; nIndex < 10 ; ++nIndex) 
		cout << result[nIndex] << ' ';
	cout << endl;

	return 0;



}
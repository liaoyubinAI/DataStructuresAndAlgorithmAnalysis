#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename elementType>
struct DisplayElementKeepCount
{
	//Hold the count in a member variable
	int m_nCount;

	//constructor
	DisplayElementKeepCount ()
	{
		m_nCount = 0;		
	}

	//Display the element,hold count !
	void operator () (const elementType& element)
	{
		++ m_nCount;
		cout << element << ' ';		
	}	
};

int main()
{
	std::vector<int> vInt;
	for (int nCount = 0; nCount < 10; ++ nCount)
		vInt.push_back(nCount);

	cout << "Displaying the vector of the vInt: "<<endl;
	DisplayElementKeepCount<int> mResult;
	mResult = for_each(vInt.begin()
		,vInt.end()
		,DisplayElementKeepCount<int> () );
	cout << "'" << mResult.m_nCount << "'elements were displayed !" << endl;
	cout << endl << endl;

	/*
	DisplayElementKeepCount<int> mResult;
	list <char> lChar;
	for (char nChar = 'a';nChar < 'k'; ++nChar)
		lChar.push_back(nChar);
	cout << "Displaying the list of the lChar: " << ' ';
	mResult = for_each(lChar.begin()
		,lChar.end()
		,DisplayElementKeepCount<char> ());
	cout << "'" << mResult.m_nCount << "'elements were displayed !" << endl;
	*/

	return 0;
}
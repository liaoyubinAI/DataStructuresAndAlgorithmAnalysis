#include <set>
#include <iostream>
using namespace std;

template <typename Container>
void PrintContents (const Container & stlContainer);

int main()
{
	//create set and multiset!
	set <int> setIntegers;
	multiset <int> msetIntegers;
	//insert element to set
	setIntegers.insert(60);
	setIntegers.insert(-1);
	setIntegers.insert(3000);

	cout << "Writing the contents of the set to the screen" << endl;
	PrintContents(setIntegers);

	msetIntegers.insert(setIntegers.begin(),setIntegers.end());
	msetIntegers.insert(3000);

	cout << "Writing the contents of the multiset to the screen "<< endl;
	PrintContents(msetIntegers);

	cout << "Number of instances of '3000' in the multiset are : ";
	cout << msetIntegers.count(3000) << " ' " << endl;

	//find the element in set!
	set<int>::iterator ielementFound = setIntegers.find(-1);
	if (ielementFound != setIntegers.end())
		cout << "Element "<< *ielementFound << " found!"<< endl;
	else
		cout << "Element not found in set!"<<endl;

	//delete the element in multiset
	msetIntegers.erase(3000);
	cout << "After detele '3000' ,msetIntegers constains: "<< endl;
	PrintContents(msetIntegers);

	return 0;
}

template <typename Container>
void PrintContents(const Container & stlContainer)
{
	typename Container::const_iterator iElementLocator = stlContainer.begin();
	while (iElementLocator != stlContainer.end())
	{
		cout << *iElementLocator << endl;
		++iElementLocator;
	}
	cout << endl;
}
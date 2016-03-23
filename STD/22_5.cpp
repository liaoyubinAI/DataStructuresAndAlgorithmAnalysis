#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CCompareStringNoCase
{
public:
	bool operator() (const string& str1,const string& str2) const
	{
		string str1LowerCase,str2LowerCase;
		str1LowerCase.resize(str1.size());
		transform(str1.begin(),str1.end(),str1LowerCase.begin(),tolower);

		str2LowerCase.resize(str2.size() );
		transform(str2.begin(),str2.end(),str2LowerCase.begin(),tolower);

		return (str1LowerCase < str2LowerCase);
	}	
};

int main()
{
	typedef set <string,CCompareStringNoCase> SET_NAMES;
	SET_NAMES setNames;

	setNames.insert("Tina");
	setNames.insert("jim");
	setNames.insert("Jack");
	setNames.insert("sam");

	cout << "The sample names in the set are : " << endl;

	SET_NAMES::const_iterator iNameLocator;
	for (iNameLocator = setNames.begin()
		;iNameLocator != setNames.end()
		;++iNameLocator)
	{
		cout << *iNameLocator << endl;
	}

	cout << "Enter a name you wish to search the set for : ";
	string strUserInput;
	cin >> strUserInput;
	SET_NAMES::iterator iNameFound = setNames.find(strUserInput);
	if(iNameFound != setNames.end())
		cout << "'"<< strUserInput << "' was found in the set " <<endl;
	else
		cout << "Name '"<< strUserInput << "' was not found in the set";
	return 0;
}
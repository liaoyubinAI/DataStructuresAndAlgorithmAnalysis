#include <map>
#include <string>
#inlcude <algorithm>
#include <iostream>
using namespace std;

//Type-define the map and multimap definition for easy readability
typedef map <int ,string> MAP_INT_STRING;
typedef multimap<int, string> MULTIMAP_INT_STRING;

struct CCaseInsensitive
{
	bool operator()(const string& str1,const string&str2) const
	{
		string str1NoCase(str1),str2NoCase(str2);
		transform(str1.begin(),str1.end(),str1NoCase.begin(),tolower);
		transform(str2.begin(),str2.end(),str2NoCase.begin(),tolower);
		return (str1NoCase < str2NoCase);
	}
};

int main()
{
	MAP_INT_STRING mapIntToString;

	//Insert key-value pairs into the map using value_type
	mapIntToString.insert(MAP_INT_STRING::value_type(3,"Three"));

	//Insert a pair using function make_pair
	mapIntToString.insert(make_pair(-1,"Minus one"));

	//Insert a pair object directly
	mapIntToString.insert(pair<int,string>(1000,"One Thousand"));

	//Insert uising an array-like syntax for inserting key-value pairs
	mapIntToString[1000000] = "One Million";
	cout << "The map contains " << mapIntToString.size();
	cout << " key-value pairs. " << endl;
	cout << "The elements in the map are: " << endl;

	//Print the contents of the map to the screen
	MAP_INT_STRING::const_iterator iMapPairLocator;
	for(iMapPairLocator = mapIntToString.begin()
		;iMapPairLocator != mapIntToString.end()
		;++iMapPairLocator)
	{
		cout << "Key: " << iMapPairLocator->first;
		cout << " Value: " << iMapPairLocator->second.c_str();
		cout << endl;
	}

	MULTIMAP_INT_STRING mmapIntToString;

	//The insert function works the same way for multimap too.
	mmapIntToString.insert(MULTIMAP_INT_STRING::value_type (3,"Three"));
	mmapIntToString.insert(make_pair (-1,"Minus one"));
	mmapIntToString.insert(pair<int, string> (1000,"One Thousand"));
	mmapIntToString.insert(MULTIMAP_INT_STRING::value_type (1000,"Thousand"));

	cout << endl << "The multimap contains " << mmapIntToString.size();
	cout << " key-value pairs." <<endl;
	cout << "The elements in the multimap are: " <<endl;

	//Print the contents in the multimap to the screen
	MULTIMAP_INT_STRING::const_iterator iMultiMapPairLocator;

	for (iMultiMapPairLocator = mmapIntToString.begin()
		;iMultiMapPairLocator != mmapIntToString.end()
		;++iMultiMapPairLocator)
	{
		cout << "Key: " << iMultiMapPairLocator->first;
		cout << " Value: " << iMultiMapPairLocator->second.c_str();

		cout << endl;
	}

	//The multimap can also return the number of pairs with the same key.
	cout << "The number of pairs in the multimap with 1000 as their key: "
		<< mmapIntToString.count(1000) << endl;

	MULTIMAP_INT_STRING::const_iterator iElementFound;
	iElementFound = mmapIntToString.find(1000);

	//check if "find" succeeded
	if(iElementFound != mmapIntToString.end())
	{
		//Find the number of pairs that have the same supplied key
		size_t nNumPairsInMap = mmapIntToString.count(1000);
		cout << "The number of pairs in multimap with 1000 as key: ";
		cout << nNumPairsInMap << endl;

		//output those values to the screen
		cout << "The values corresponding to the key 1000 are: " << endl;
		for(size_t nValuesCounter = 0
			;nValuesCounter < nNumPairsInMap
			;++nValuesCounter)
		{
			cout << "Key: " <<iElementFound->first;
			cout << " ,Value:[" <<nValuesCounter<< "] ="<< iElementFound->second.c_str()<<endl;
			++iElementFound;
		}
	}
	else
		cout << "Element not found in the multimap";
	cout << endl;

	return 0;
}
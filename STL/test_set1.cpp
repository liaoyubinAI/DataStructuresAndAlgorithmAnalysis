#include <set>
#include <iostream>
#include <string>
using namespace std;

enum MenuOptionSelection
{
	InsertContactsetEntry = 0,
	DisplayEntries = 1,
	FindNumber = 2,
	EraseEntry = 3,
	QuitApplication = 4
};
struct ContactItem
{
	string strContactsName;
	string strPhoneNumber;

	//Constructor
	ContactItem(const string& strName,const string& strNumber)
	{
		strContactsName = strName;
		strPhoneNumber = strNumber;
	}

	bool operator == (const ContactItem& itemToCompare) const
	{
		return (itemToCompare.strContactsName == this->strContactsName);		
	}
	bool operator < (const ContactItem& itemToCompare) const
	{
		return (this->strContactsName < itemToCompare.strContactsName);
	}	
};

int ShowMenu();
ContactItem GetContactInfo();
void DisplayContactset(const set <ContactItem> & setContacts);
void FindContact(const set <ContactItem> & setContacts);
void EraseContact(set <ContactItem> & setContacts);

int main()
{
	set <ContactItem> setContacts;
	int nUserSelection = InsertContactsetEntry;
	while((nUserSelection = ShowMenu()) != (int) QuitApplication)
	{
		switch (nUserSelection)
		{
			case InsertContactsetEntry:
				setContacts.insert(GetContactInfo());
				cout << "Constacts set updated! "<< endl << endl;
				break;
			case DisplayEntries:
				DisplayContactset(setContacts);
				break;
			case FindNumber:
				FindContact(setContacts);
				break;
			case EraseEntry:
				EraseContact(setContacts);
				DisplayContactset(setContacts);				
				break;
			default:
				cout << "Invalid input '" <<nUserSelection;
				cout << ".' Please choose an option between 0 and 4 "<< endl;
				break;
		}
	}
	cout << "Quitting Bye!" <<endl;
	return 0;
}

void DisplayContactset(const set <ContactItem>& setContacts)
{
	cout << "*** Displaying contact information ***" << endl;
	cout << "There are " <<setContacts.size() << " entries : " << endl;
	set <ContactItem>::const_iterator iContact;
	for(iContact = setContacts.begin()
		;iContact != setContacts.end()
		;++iContact)
	{
		cout << "Name: '" << iContact->strContactsName << "' Number: '"
		<<iContact->strPhoneNumber << " ' " << endl;
	}
	cout << endl;
}

ContactItem GetContactInfo()
{
	cout << "*** Feed contact informaton ***" << endl;
	string strName;
	cout << "Please enterthe person's name : " << endl;
	cout << " > ";
	cin >> strName;

	string strPhoneNumber;
	cout << "Please enter " << strName << " 's phone number " << endl;
	cout << ">";
	cin >> strPhoneNumber;

	return ContactItem(strName,strPhoneNumber);
}

int ShowMenu()
{
	cout << "*** What would you like to do next ?***" << endl;
	cout << "Enter 0 to feed a name and phone number " << endl;
	cout << "Enter 1 to Displaying all entries " << endl;
	cout << "Enter 2 to find an entry " << endl;
	cout << "Enter 3 to erase an entry " << endl;
	cout << "Enter 4 to quit this application " << endl << endl;
	cout << "> ";
	int nOptionSelected;
	cin >> nOptionSelected;
	cout << endl;
	return nOptionSelected;
}
void FindContact(const set <ContactItem>& setContacts)
{
	cout << "*** Find a contact ***" << endl;
	cout << "Whose number do you wish to find?" << endl;
	cout << " > " ;
	string strName;
	cin >> strName;
	set<ContactItem>::const_iterator iContactFound 
		= setContacts.find(ContactItem(strName," "));
	if (iContactFound != setContacts.end())
	{
		cout << strName << " is reachable at number: " 
			<< iContactFound->strPhoneNumber << endl;
	}
	else
		cout << strName << "was not found in the contacts list" << endl;
	cout << endl;
	return;
}

void EraseContact(set <ContactItem>& setContacts)
{
	cout << "*** Erase a contacts ***"<< endl;
	cout << "Whose number do your wish to erase?" << endl;
	cout << "> ";
	string strName;
	cin >> strName;
	size_t nErased = setContacts.erase(ContactItem(strName," "));
	if(nErased > 0)
		cout << strName << "'s contact informaton erased." << endl;
	else
		cout << strName << " was not found!" << endl;
	cout << endl;
}
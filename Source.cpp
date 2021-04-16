#include <iostream>
#include <string>
#include <fstream>
#define ll long long
using namespace std;


struct information
{

	string email, name, gender, number;
	//string addres;

};

information contact[100000];
ll nc = 0,  ind;
string op, se;

void add();
void show();
void s_name();
void s_email();
void s_num();
void s_gender();
void update();
void delete_contact();
void readContact();
void save();

int main()
{
	readContact();

	cout << "#####################################################################################################################\n";
	cout << "#################                       Phone book Application                                        ###############\n\n";



	while (true)
	{
		cout << "Enter your Operation ( Add / Show / Search / Delete / Change ) : ";
		cin >> op;
		cin.ignore();

	
		if (op == "Add" || op == "add")
		{
			add();
		}
		else if (op == "Show" || op == "show")
		{
			if (nc == 0)
				cout << "There is no contacts . \n";
			else
			{
				show();
			}
		}
		else if (op == "Search" || op == "search")
		{
			cout << "DO You want to search with (name / email /number/ gender) : ";
			cin >> se;
			cin.ignore();
			if (se == "Name" | se == "name")
			{
				s_name();
			}
			else if (se == "email" | se == "Email")
			{
				s_email();
			}
			else if (se == "gender" | se == "Gender")
			{
				s_gender();
			}
			else if (se == "number" | se == "Number")
			{
				s_num();
			}
		}
		else if (op == "Delete" || op == "delete")
		{
			delete_contact();
		}
		else if (op == "Change" || op == "change")
		{
			update();
		}
		else
		{
			cout << "Invalid operation !! \n";
		}
		cout << "\n          *************   \n";
		
		bool in = 0 , end=0;
		do
		{
			bool  in= 0;
			cout << "DO you anther operation (yes/no) : ";
			cin >> op;
			if (op == "yes" || op == "Yes")
			{
				cout << "\n";
				break;
			}
			else if (op == "no" || op == "No")
			{
				cout << "End ... \n";
				save();
				end = 1;
				break;
			}
			else
			{
				cout << "Invalid option !! \n";
			}
		}
		while (!in);
		
		if (end)
			break;
	}
	system("pause");
	return 0;

}    //  end main








	//add
	void add()
	{
		cout << "Enter name : ";
		getline(cin, contact[nc].name);

		cout << "Enter Gender : ";
		cin >> contact[nc].gender;
		cout << "Enter Phone Number : ";
		cin >> contact[nc].number;
		cout << "Enter Email : ";
		cin >> contact[nc].email;
		nc++;

               cout<<"well done you add a new contact..";
	}


void show()
{
	ll k = 1;
	for (ll i = 0; i < nc; i++)
	{
		if (contact[i].name == "#")
		{
			continue;
		}

		cout << k << " )  \n";
		cout << "Name : " << contact[i].name << "\n";
		cout << "Gender : " << contact[i].gender << "\n";
		cout << "Phone Namber : " << contact[i].number << "\n";
		cout << "Email : " << contact[i].email << "\n";
		k++;
	}

}

//name search
void s_name()
{
	bool found = 0;
	cout << "Enter the contact name : ";
	getline(cin, se);
	cout << "\n";
	for (ll i = 0; i < nc; i++)
	{
		if (contact[i].name.find(se) != string::npos)
		{
			ind = i;
			found = 1;
			cout << "Name : " << contact[i].name << "\n";
			cout << "Gender : " << contact[i].gender << "\n";
			cout << "Phone Namber : " << contact[i].number << "\n";
			cout << "Email : " << contact[i].email << "\n\n";
		}
	}
	if (!found)
		cout << "Can not find this contact \n";
}

// email search

void s_email()
{
	bool found = 0;
	cout << "Enter the email : ";

	getline(cin, se);
	cout << "\n";
	for (ll i = 0; i < nc; i++)
	{
		if (contact[i].email.find(se) != string::npos)
		{
			found = 1;
			cout << "Name : " << contact[i].name << "\n";
			cout << "Gender : " << contact[i].gender << "\n";
			cout << "Phone Namber : " << contact[i].number << "\n";
			cout << "Email : " << contact[i].email << "\n\n";
		}
	}
	if (!found)
		cout << "Can not find this contact \n";
}

//number search
void s_num()
{
	bool found = 0;
	cout << "Enter the number : ";
	getline(cin, se);
	cout << "\n";
	for (ll i = 0; i < nc; i++)
	{
		if (contact[i].number.find(se) != string::npos)
		{
			found = 1;
			cout << "Name : " << contact[i].name << "\n";
			cout << "Gender : " << contact[i].gender << "\n";
			cout << "Phone Namber : " << contact[i].number << "\n";
			cout << "Email : " << contact[i].email << "\n\n";
		}
	}
	if (!found)
		cout << "Can not find this contact \n";
}
// gender search
void s_gender()
{
	bool found = 0;
	cout << "Enter gender : ";
	getline(cin, se);
	cout << "\n";
	for (ll i = 0; i < nc; i++)
	{
		if (se == contact[i].gender)
		{
			found = 1;
			cout << "Name : " << contact[i].name << "\n";
			cout << "Gender : " << contact[i].gender << "\n";
			cout << "Phone Namber : " << contact[i].number << "\n";
			cout << "Email : " << contact[i].email << "\n\n";
		}
	}
	if (!found)
		cout << "Can not find this contact \n";
}

//update

void update()
{
	int press_num;

	s_name();

	cout << "What do you want to Edit? \n" <<
		" If you want to edit the name of the contact press 1. \n" <<
		" If you want to edit the gender of the contact press 2. \n" <<
		" If you want to edit the number of the contact press 3. \n" <<
		" If you want to edit the email press 4. \n";
	cin >> press_num;
	cin.ignore();

	switch (press_num)
	{
	case 1:
		cout << "Enter the name : ";
		getline(cin, contact[ind].name);

		break;

	case 2:
		cout << "Enter the gender : ";
		cin >> contact[ind].gender;
		break;

	case 3:
		cout << "Enter the number : ";
		cin >> contact[ind].number;
		break;

	case 4:
		cout << "Enter the email : ";
		cin >> contact[ind].email;
		break;

	default:
		cout << "please inter a number from 1 to 4. ";
	}
}

// delete fun
void delete_contact()
{
   string Name;

	cout << "Enter deleted contact name : ";
	getline(cin, Name);
	for (ll i = 0; i < nc; i++)
	{
		if (Name == contact[i].name)
		{
			contact[i].name = '#';
			contact[i].email = '#';
			contact[i].gender = '#';
			contact[i].number = '#';
			break;
		}
	}
	cout << "Deleted .\n";
}


// readcotact
void readContact()
{
	ifstream myfile("contactData.txt");

	while ( getline(myfile, contact[nc].name) )
	{ 
		getline(myfile, contact[nc].gender);
		getline(myfile, contact[nc].number);
		getline(myfile, contact[nc].email);
		nc++;
	}
	myfile.close();
}



//save
void save() {
	ofstream myfile;
	myfile.open("contactData.txt");
	for (int i = 0; i < nc; i++)
	{
		if (contact[i].name == "#")
		{
			continue;
		}
		myfile << contact[i].name << endl;
		myfile << contact[i].gender << endl;
		myfile << contact[i].number << endl;
		myfile << contact[i].email << endl;
	}
	myfile.close();
}

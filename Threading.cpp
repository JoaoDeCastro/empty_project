/*File to use as a practice


Joao DeCastro

File to use as a practice threading


Do a program simulation a printer service

*/


using namespace System;
using namespace System::Threading;

public enum Document
{
	Word,
	PowerPoint,
	PDF,
	Picture,
	Unknown
};

ref class User
{
public:
	User();
	~User();
	

	//setting user
	void setUser(String^ user, Document type)
	{
		this->name = user;
		this->typeOfDocument = type;
	}

	//getting info from user and document
	String^ getUser()
	{
		return name;
	}
	Document getDocument()
	{
		return typeOfDocument;
	}


	protected:
	String^ name;
	Document typeOfDocument;



};

User::User()
{
	this->name = "";
	this->typeOfDocument = Unknown;
}

User::~User()
{
}



ref class Printer :  public User
{
public:
	Printer();
	~Printer();
	void print(User^ user, int copies);
	void scan(User^ user);
	void copy(User^ user, int copies);

private:
	int numberOfCopies;

};

Printer::Printer()
{
}

Printer::~Printer()
{
}



void Printer::print(User^ user, int copies)
{
	Console::WriteLine("Printing document");
	Console::WriteLine(user->getDocument());
	Console::WriteLine("Number of copies:{0}", copies);
	
	
}


void Printer::scan(User^ user)
{
	Console::WriteLine("Scanning document");
	Console::WriteLine(user->getDocument());
	

}

void Printer::copy(User^ user, int copies)
{
	Console::WriteLine("Copying document");
	Console::WriteLine(user->getDocument());
	Console::WriteLine("Number of copies:{0}", copies);
}

int main()
{
	Console::WriteLine("### WELCOME TO JHC PRINTER");

	User^ joao = gcnew User();
	joao->setUser("Joan", Picture);
	
	Printer^ printer1 = gcnew Printer();
	printer1->print(joao, 5);

	
}
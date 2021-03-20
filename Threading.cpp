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
	//TODO
	// get user input while printing documents

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

	//each function will take 100 cycle to be executed
	void print(User^ user, int copies);
	void scan(User^ user);
	void copy(User^ user, int copies);
	void userInteraction();
	void systemOperations();

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
	Console::WriteLine("Printing document: ");
	Console::Write("Document type: ");
	Console::WriteLine(user->getDocument());
	Console::WriteLine("Number of copies: {0}", copies);
	for (int i = 0; i <= 100; i++)
	{
		Console::WriteLine("Printing...");
	}
	Console::WriteLine("Printing was done successfully");
	
	
}


void Printer::scan(User^ user)
{
	Console::WriteLine("Scanning document");
	Console::WriteLine(user->getDocument());
	for (int i = 0; i <= 100; i++)
	{
		Console::WriteLine("Scanning...");

	}
	Console::WriteLine("Scanning was done successfully");
}

void Printer::copy(User^ user, int copies)
{
	Console::WriteLine("Copying document");
	Console::Write("Document type: ");
	Console::WriteLine(user->getDocument());
	Console::WriteLine("Number of copies:{0}", copies);
	for (int i = 0; i <= 100; i++)
	{
		Console::WriteLine("Copying... ");

	}
	Console::WriteLine(" was done successfully");
}

void Printer::userInteraction()
{
	
		Console::WriteLine("Do you want to print another document? ");
		String^ answer;
		answer = Console::ReadLine();

}

void Printer::systemOperations()
{
	for (int i = 0;i<100;i++)
	{
		Console::WriteLine("Performing system operations");
	}
	
}

int main()
{

	
	Console::WriteLine("### WELCOME TO JHC PRINTER");
	// creating an instance of a printer
	Printer^ printer1 = gcnew Printer();

	//creating thread
	// passing to Thread's constructor a delegate of type System::ThreadStart,
	// which supports any function taking no arguments and returning no value
	// it could encapsulated multiple functions
	Thread^ t1 = gcnew Thread(gcnew ThreadStart(printer1, &Printer::userInteraction));
	t1->Name = "t1";
	Thread^ t2 = gcnew Thread(gcnew ThreadStart(printer1, &Printer::systemOperations));
	t2->Name = "t2";
	t2->Start();
	
	

	// creating an instance of user
	User^ joao = gcnew User();
	joao->setUser("Joao", Picture);
	
	
	
	printer1->print(joao, 5);
	t1->Start();
	
	
	

	
}
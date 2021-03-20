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


private:
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



ref class Printer : public User
{
public:
	Printer();
	~Printer();
	void print(Document type, int copies);
	void scan(Document type);
	void copy(Document type, int copies);

private:
	int numberOfCopies;

};

Printer::Printer()
{
}

Printer::~Printer()
{
}



void Printer::print(Document type, int copies)
{
	Console::WriteLine("Printing document :{0}", type);
	Console::WriteLine("Number of copies:{0}", copies);
}


void Printer::scan(Document type)
{

}

void Printer::copy(Document type, int copies)
{

}

int main()
{
	Console::WriteLine("Hello World threading");
}
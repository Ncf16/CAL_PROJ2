#include "frmMain.h"
#include "parsing.h"
#include "wordForm.h"
#include <string>
#include<fstream>
#include "textBoxPopUp.h"
#include "trie.h"
using namespace CALProject2;

bool compare(String^ search, int size, wchar_t first, wchar_t last)
{
	for (int i = 0; i < search->Length && i < size; i++)
	{
		if (search[i] != first)
			return false;
	}
	return true;

}
[STAThreadAttribute]
int main(array<System::String ^> ^args) {



	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it

	vector<string> s = { "ola", "cores", "azuis" };
	wordForm^ w = gcnew wordForm();
	w->changeForm("teste", s);
	//w->Visible = true;
	//textBoxPopUp^ p = gcnew textBoxPopUp();
	/*cout << "Before" << endl;
	
	int a = 5;
		int b = 10;
		a = b;

		cout << a << endl;*/
	Application::Run( gcnew frmMain());
	cout << "end" << endl;
 
	/*Trie t;
	String^  s;
	s = L"12347";
	t.addWord(s);

	t.getRoot()->~Node();
	/*
	s = L"12568";
	t.addWord(s);
	t.print();*/
	_getch();
	//	menu(d);
	//initi();
	return 0;
}


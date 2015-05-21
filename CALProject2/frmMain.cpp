#include "frmMain.h"
#include "parsing.h"
#include "wordForm.h"
#include <string>
#include<fstream>
using namespace CALProject2;
void replaceWord(string word, string wordToBeChanged, ofstream file, string fileName)
{

	//go back till the word
	ifstream temp;
	string wordRead;
	file.seekp(-(int)word.size(), ios_base::cur);
	temp.seekg(file.ios_base::cur);
	std::getline(temp, wordRead, ' ');
	wordRead.replace(word.begin(), word.end(), word);


}
void initi()
{
	std::ofstream  off;
//	off.open(("teste.txt").c_str());
	//replaceWord("ola", "asdasdasdasdasdasdasdas", off, "teste.txt");
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
		w->Visible = true;
		cout << "Before" << endl;
		Application::Run(gcnew frmMain());
		cout << "end" << endl;



		
		File d;
	//	menu(d);
	//initi();
	return 0;
}


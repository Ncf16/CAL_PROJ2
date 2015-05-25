#include "frmMain.h"
#include "parsing.h"
#include "wordForm.h"
#include <string>
#include<fstream>
#include "textBoxPopUp.h"
using namespace CALProject2;


[STAThreadAttribute]
int main(array<System::String ^> ^args) {
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it


	
		vector<string> s = { "ola", "cores", "azuis" };
		//wordForm^ w = gcnew wordForm();
	//	w->changeForm("teste", s);
		//w->Visible = true;
		textBoxPopUp^ p = gcnew textBoxPopUp();
		cout << "Before" << endl;
		Application::Run(gcnew frmMain());
		cout << "end" << endl;



		
		dictionary d;
	//	menu(d);
	//initi();
	return 0;
}



#pragma once
#include <direct.h>
#include "parsing.h"
#include "dictionary.h"
#include <iostream>
#include "autocorrect.h"
#include "textBoxPopUp.h"
#include "wordForm.h"

namespace CALProject2 {

	dictionary d;
	string file;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	int contador = 0;
	autoCorrect corretor;
	string fileName;

	public ref class frmMain : public System::Windows::Forms::Form
	{
	public:
		System::String^ consoleFileName;

		frmMain(void)
		{
			InitializeComponent();

		}

	protected:
		~frmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::Button^  pickLanguageButton;
	private: System::Windows::Forms::Button^  pickTextButton;
	private: System::Windows::Forms::Button^  runButton;
	private: System::Windows::Forms::OpenFileDialog^  dialogLanguage;
	private: System::Windows::Forms::OpenFileDialog^  dialogText;
	private: System::Boolean text = false;
	private: System::Boolean language = false;
	private: System::String^ language_path = System::Environment::CurrentDirectory + L"\\dictionary";
	private: System::String^ text_path = System::Environment::CurrentDirectory + L"\\Text";

	private: System::ComponentModel::BackgroundWorker^  runWorker;

	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::ComponentModel::BackgroundWorker^  pickLanguageWorker;
	private: System::Windows::Forms::Button^  doNothingButton;
	private: System::ComponentModel::BackgroundWorker^  pickText;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

	protected:
		void InitializeComponent(void)
		{

			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->pickLanguageButton = (gcnew System::Windows::Forms::Button());
			this->pickTextButton = (gcnew System::Windows::Forms::Button());
			this->runButton = (gcnew System::Windows::Forms::Button());
			this->dialogLanguage = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dialogText = (gcnew System::Windows::Forms::OpenFileDialog());
			this->runWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->pickLanguageWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->doNothingButton = (gcnew System::Windows::Forms::Button());
			this->pickText = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// exitButton
			this->exitButton->Location = System::Drawing::Point(165, 179);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(91, 44);
			this->exitButton->TabIndex = 0;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &frmMain::exitButtom_Click);
			// pickLanguageButton
			this->pickLanguageButton->Location = System::Drawing::Point(26, 35);
			this->pickLanguageButton->Name = L"pickLanguageButton";
			this->pickLanguageButton->Size = System::Drawing::Size(91, 44);
			this->pickLanguageButton->TabIndex = 1;
			this->pickLanguageButton->Text = L"Pick Language";
			this->pickLanguageButton->UseVisualStyleBackColor = true;
			this->pickLanguageButton->Click += gcnew System::EventHandler(this, &frmMain::pickLanguageButton_Click);
			// pickTextButton
			this->pickTextButton->Location = System::Drawing::Point(165, 35);
			this->pickTextButton->Name = L"pickTextButton";
			this->pickTextButton->Size = System::Drawing::Size(91, 44);
			this->pickTextButton->TabIndex = 2;
			this->pickTextButton->Text = L"Pick text";
			this->pickTextButton->UseVisualStyleBackColor = true;
			this->pickTextButton->Click += gcnew System::EventHandler(this, &frmMain::pickTextButtom_Click);
			// runButton
			this->runButton->Location = System::Drawing::Point(26, 179);
			this->runButton->Name = L"runButton";
			this->runButton->Size = System::Drawing::Size(91, 44);
			this->runButton->TabIndex = 3;
			this->runButton->Text = L"Run";
			this->runButton->UseVisualStyleBackColor = true;
			this->runButton->Click += gcnew System::EventHandler(this, &frmMain::runButton_Click);
			// dialogLanguage
			this->dialogLanguage->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &frmMain::dialogLanguage_FileOk);
			// dialogText
			this->dialogText->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &frmMain::dialogText_FileOk);
			// runWorker
			this->runWorker->WorkerReportsProgress = true;
			this->runWorker->WorkerSupportsCancellation = true;
			this->runWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &frmMain::run_DoWork);
			this->runWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &frmMain::runProgressChanged);
			this->runWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &frmMain::runWorker_RunWorkerCompleted);
			// progressBar1
			this->progressBar1->Location = System::Drawing::Point(79, 6);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(135, 23);
			this->progressBar1->TabIndex = 4;
			// pickLanguageWorker
			this->pickLanguageWorker->WorkerReportsProgress = true;
			this->pickLanguageWorker->WorkerSupportsCancellation = true;
			this->pickLanguageWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &frmMain::pickLanguage);
			this->pickLanguageWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &frmMain::pickLanguageWorkerCompleted);

			// doNothingButton
			this->doNothingButton->Location = System::Drawing::Point(166, 35);
			this->doNothingButton->Name = L"doNothingButton";
			this->doNothingButton->Size = System::Drawing::Size(97, 43);
			this->doNothingButton->TabIndex = 5;
			this->doNothingButton->Text = L"doNothingButton";
			this->doNothingButton->UseVisualStyleBackColor = true;
			this->doNothingButton->Visible = false;
			this->doNothingButton->Click += gcnew System::EventHandler(this, &frmMain::doNothingButton_Click);
			// pickText
			this->pickText->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &frmMain::pickTextDoWork);
			this->pickText->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &frmMain::pickTextCompleted);
			// frmMain
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(297, 257);
			this->Controls->Add(this->doNothingButton);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->runButton);
			this->Controls->Add(this->pickTextButton);
			this->Controls->Add(this->pickLanguageButton);
			this->Controls->Add(this->exitButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"frmMain";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Corretor Ortográfico";
			this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			this->ResumeLayout(false);

		}
	private:
#pragma endregion

		//Button
	private: System::Void frmMain_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void doNothingButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void exitButtom_Click(System::Object^  sender, System::EventArgs^  e) {
		this->~frmMain();
	}
	private: System::Void runButtom_Click(System::Object^  sender, System::EventArgs^  e) {

		if (runButton->Text == L"Run")
		{
			if (text)
			{
				if (language)
				{//vais ser o algoritmo
					runButton->Text = L"Stop";
					if (!runWorker->IsBusy){
						contador = 0;
						runWorker->RunWorkerAsync();


						//System::Threading::Thread::Resume();
					}
				}
				else
				{
					MessageBox::Show("Selecione uma linguagem\n");
				}

			}
			else
			{
				MessageBox::Show("Selecione um texto\n");

			}
		}
		else if (runButton->Text == L"Stop")
		{
			runButton->Text = L"Run";
			runWorker->CancelAsync();


		}
	}

			 //Run
	private: System::Void run_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {


		while (this->pickLanguageWorker->IsBusy || this->pickLanguageWorker->IsBusy)
		{
			cout << "Wait" << endl;
		}
		while (1)
		{
			if (runWorker->CancellationPending) {
				cout << "CANCELATION PENDING HERE" << endl << endl;
				e->Cancel = true;
				break;
				//this->pickTextButton->Enabled = false;
				//	return;
			}
			System::Threading::Thread::Sleep(1);
			contador++;
			if (contador == 1000)
				return;
			cout << contador << endl;
		}
		//backgroundWorker1->ReportProgress(0);

	}
	private: System::Void runProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {

		progressBar1->Value = e->ProgressPercentage;

	}
	private: System::Void runWorker_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
		cout << "CANCEL" << endl << endl;

		if (e->Cancelled)
		{
			this->pickTextButton->Visible = false;
			this->doNothingButton->Visible = true;
			cout << "here" << endl;
			contador = 0;
			//System::ComponentModel::DoWorkEventArgs^ newE = gcnew DoWorkEventArgs(sender);
			//pickLanguage(sender, newE);
		}
		else
			if (e->Error)
			{
				MessageBox::Show("Error in the Autocorrect");
				this->~frmMain();
			}
			else
			{
				this->pickTextButton->Visible = true;
				this->doNothingButton->Visible = false;
			}

	}


			 //Text
	private: System::Void pickTextDoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		cout << "Here" << endl;
		cout << fileName << endl;
	}
	private: System::Void pickTextCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {

		if (e->Cancelled)
		{

		}
		else
			if (e->Error)
			{

			}
			else
			{
				text = true;
			}


	}
	private: System::Void pickTextButtom_Click(System::Object^  sender, System::EventArgs^  e) {
		textBoxPopUp^ console = gcnew textBoxPopUp();
		this->dialogText->InitialDirectory = text_path;
		this->dialogText->ShowDialog();


		if (this->dialogText->FileName->Length != 0)
		{

			fileName = toString(this->dialogText->FileName);
		}
		else
		{
			console->ShowDialog();
			cout << toString(this->dialogText->FileName) << endl;
			String^ tmp = console->getFileName();
			if (tmp->Length != 0){
				fileName = toString(tmp);

			}
			console->~textBoxPopUp();

		}
		this->pickText->RunWorkerAsync();


	}
	private: System::Void dialogText_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}


			 //Language
	private: System::Void pickLanguage(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

		wordForm^ options = gcnew wordForm();
		//corretor.getDic(0)

		language = true;
		if (loadParse(toString(this->dialogLanguage->FileName), d))
			language = true;


		pickLanguageWorker->ReportProgress(100);

	}
	private: System::Void pickLanguageWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {


		if (e->Cancelled)
		{

		}
		else
			if (e->Error)
			{

			}
			else
			{
			}


	}
	private: System::Void pickLanguageButtom_Click(System::Object^  sender, System::EventArgs^  e) {
		this->dialogLanguage->InitialDirectory = language_path;
		this->dialogLanguage->ShowDialog();
		this->pickLanguageWorker->RunWorkerAsync();

	}
	private: System::Void dialogLanguage_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}
	private: System::Void pickLanguageButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void runButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	};


}

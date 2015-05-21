
#pragma once
#include <direct.h>
#include "parsing.h"
#include "file.h"
#include <iostream>


namespace CALProject2 {

	dictionary d;
	string file;
	string toString(System::String^ str) {
		string tmp;

		for (int i = 0; i < str->Length; i++)
			tmp += (char)str[i];

		return tmp;
	}
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for frmMain
	/// </summary>
	public ref class frmMain : public System::Windows::Forms::Form
	{
	public:
		frmMain(void)
		{
			InitializeComponent();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::Button^  pickLanguageButton;
	protected:


	private: System::Windows::Forms::Button^  pickTextButton;

	private: System::Windows::Forms::Button^  runButton;

	private: System::Windows::Forms::OpenFileDialog^  dialogLanguage;
	private: System::Windows::Forms::OpenFileDialog^  dialogText;
	private: System::Boolean text = false;
	private: System::Boolean language = false;
	private: System::String^ language_path = System::Environment::CurrentDirectory + L"\\Dictionary";
	private: System::String^ text_path = System::Environment::CurrentDirectory + L"\\Text";
	private: System::String^ toBeCorrected = "";
	private: System::ComponentModel::BackgroundWorker^  runWorker;

	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::ComponentModel::BackgroundWorker^  pickLanguageWorker;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
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
			this->SuspendLayout();
			// 
			// exitButton
			// 
			this->exitButton->Location = System::Drawing::Point(165, 179);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(91, 44);
			this->exitButton->TabIndex = 0;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &frmMain::exitButtom_Click);
			// 
			// pickLanguageButton
			// 
			this->pickLanguageButton->Location = System::Drawing::Point(26, 35);
			this->pickLanguageButton->Name = L"pickLanguageButton";
			this->pickLanguageButton->Size = System::Drawing::Size(91, 44);
			this->pickLanguageButton->TabIndex = 1;
			this->pickLanguageButton->Text = L"Pick Language";
			this->pickLanguageButton->UseVisualStyleBackColor = true;
			this->pickLanguageButton->Click += gcnew System::EventHandler(this, &frmMain::pickLanguageButtom_Click);
			// 
			// pickTextButton
			// 
			this->pickTextButton->Location = System::Drawing::Point(165, 35);
			this->pickTextButton->Name = L"pickTextButton";
			this->pickTextButton->Size = System::Drawing::Size(91, 44);
			this->pickTextButton->TabIndex = 2;
			this->pickTextButton->Text = L"Pick text";
			this->pickTextButton->UseVisualStyleBackColor = true;
			this->pickTextButton->Click += gcnew System::EventHandler(this, &frmMain::pickTextButtom_Click);
			// 
			// runButton
			// 
			this->runButton->Location = System::Drawing::Point(26, 179);
			this->runButton->Name = L"runButton";
			this->runButton->Size = System::Drawing::Size(91, 44);
			this->runButton->TabIndex = 3;
			this->runButton->Text = L"Run";
			this->runButton->UseVisualStyleBackColor = true;
			this->runButton->Click += gcnew System::EventHandler(this, &frmMain::runButtom_Click);
			// 
			// dialogLanguage
			// 
			this->dialogLanguage->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &frmMain::dialogLanguage_FileOk);
			// 
			// dialogText
			// 
			this->dialogText->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &frmMain::dialogText_FileOk);
			// 
			// runWorker
			// 
			this->runWorker->WorkerReportsProgress = true;
			this->runWorker->WorkerSupportsCancellation = true;
			this->runWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &frmMain::run_DoWork);
			this->runWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &frmMain::runProgressChanged);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(88, 6);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(135, 23);
			this->progressBar1->TabIndex = 4;
			// 
			// pickLanguageWorker
			// 
			this->pickLanguageWorker->WorkerReportsProgress = true;
			this->pickLanguageWorker->WorkerSupportsCancellation = true;
			this->pickLanguageWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &frmMain::pickLanguage);
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(297, 257);
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
#pragma endregion

	private: System::Void frmMain_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void exitButtom_Click(System::Object^  sender, System::EventArgs^  e) {
		this->~frmMain();
	}
	private: System::Void pickLanguageButtom_Click(System::Object^  sender, System::EventArgs^  e) {
		this->dialogLanguage->InitialDirectory = language_path;
		this->dialogLanguage->ShowDialog();
		this->pickLanguageWorker->RunWorkerAsync();

	}
	private: System::Void pickTextButtom_Click(System::Object^  sender, System::EventArgs^  e) {
		this->dialogText->InitialDirectory = text_path;
		this->dialogText->ShowDialog();
		text = true;
		toBeCorrected = this->dialogText->FileName;
		cout << "Here" << endl;
		cout << toString(toBeCorrected) << endl;

	}
	private: System::Void runButtom_Click(System::Object^  sender, System::EventArgs^  e) {

		if (runButton->Text == L"Run")
		{
			if (text)
			{
				if (language)
				{//vais ser o algoritmo
					runButton->Text = L"Cancel";
					if (!runWorker->IsBusy)
						runWorker->RunWorkerAsync();
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
		else
		{
			runButton->Text = L"Run";
			runWorker->CancelAsync();

		}
	}

	private: System::Void dialogLanguage_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {


	}
	private: System::Void dialogText_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}
	private: System::Void pickLanguage(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

		language = true;
		loadParse(toString(this->dialogLanguage->FileName), d);
		cout << "Here" << endl;
		cout << toString(this->dialogLanguage->FileName) << endl;
		pickLanguageWorker->ReportProgress(100);

	}
	private: System::Void run_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

		if (runWorker->CancellationPending) {
			e->Cancel = true;
			//backgroundWorker1->ReportProgress(0);
		}
	}
	private: System::Void runProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {

		progressBar1->Value = e->ProgressPercentage;
	}


	};
}

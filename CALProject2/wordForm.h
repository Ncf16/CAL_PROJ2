#pragma once
#include <vector>
#include "vectorWords.h"
#include "frmMain.h"
namespace CALProject2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for wordForm
	/// </summary>



	VectorWords words;

	public ref class wordForm : public System::Windows::Forms::Form
	{

		string toString(System::String^ str) {
			string tmp;

			for (int i = 0; i < str->Length; i++)
				tmp += (char)str[i];

			return tmp;
		}
		String^ selectedWord;
	public:

		string getSelectedWord()
		{
			return toString(selectedWord);
		}

		wordForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void changeWords(std::vector<std::string> w)
		{
			words.changeWords(w);
		}
		void addWords(std::string word)
		{
			words.addWords(word);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~wordForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  wordToBeChanged;
	protected:

	protected:
	private: System::Windows::Forms::ComboBox^  alternatives;
	private: System::Windows::Forms::Button^  doneButton;
	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::Label^  label;




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
			this->wordToBeChanged = (gcnew System::Windows::Forms::Label());
			this->alternatives = (gcnew System::Windows::Forms::ComboBox());
			this->doneButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// wordToBeChanged
			// 
			this->wordToBeChanged->AutoSize = true;
			this->wordToBeChanged->Location = System::Drawing::Point(120, 47);
			this->wordToBeChanged->Name = L"wordToBeChanged";
			this->wordToBeChanged->Size = System::Drawing::Size(0, 13);
			this->wordToBeChanged->TabIndex = 0;
			// 
			// alternatives
			// 
			this->alternatives->FormattingEnabled = true;
			this->alternatives->Location = System::Drawing::Point(63, 84);
			this->alternatives->Name = L"alternatives";
			this->alternatives->Size = System::Drawing::Size(157, 21);
			this->alternatives->TabIndex = 1;
			this->alternatives->SelectedIndexChanged += gcnew System::EventHandler(this, &wordForm::alternatives_SelectedIndexChanged);
			// 
			// doneButton
			// 
			this->doneButton->Location = System::Drawing::Point(23, 178);
			this->doneButton->Name = L"doneButton";
			this->doneButton->Size = System::Drawing::Size(115, 54);
			this->doneButton->TabIndex = 2;
			this->doneButton->Text = L"Done";
			this->doneButton->UseVisualStyleBackColor = true;
			this->doneButton->Click += gcnew System::EventHandler(this, &wordForm::button1_Click);
			// 
			// exitButton
			// 
			this->exitButton->Location = System::Drawing::Point(155, 178);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(117, 54);
			this->exitButton->TabIndex = 3;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &wordForm::exitButton_Click);
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Location = System::Drawing::Point(120, 34);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(0, 13);
			this->label->TabIndex = 4;
			// 
			// wordForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(288, 266);
			this->Controls->Add(this->label);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->doneButton);
			this->Controls->Add(this->alternatives);
			this->Controls->Add(this->wordToBeChanged);
			this->Name = L"wordForm";
			this->Text = L"wordForm";
			this->Load += gcnew System::EventHandler(this, &wordForm::wordForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:
		void changeForm(std::string w, std::vector<std::string> vec)
		{
			if (vec.size() == 0)
				return;

			words.changeWords(vec);
			words.setWordToBeChanged(w);
			label->Text = gcnew String(w.c_str());
			for (size_t i = 0; i < vec.size(); i++)
			{
				alternatives->Items->Add(gcnew String(vec[i].c_str()));
			}
			alternatives->SelectedIndex = 0;

		}
	private: System::Void wordForm_Load(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		this->Visible = false;
	}
	private: System::Void alternatives_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		cout << alternatives->SelectedIndex << endl;
		selectedWord = (String^)alternatives->SelectedItem;
	}
	private: System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e) {

		//this->Close();
		this->~wordForm();
		//this->Visible = false;

	}
	};
}
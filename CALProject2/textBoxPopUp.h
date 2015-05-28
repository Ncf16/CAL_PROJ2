#pragma once

#include "dictionary.h"
#include<string>
#include "parsing.h"
#include <stdio.h>

namespace CALProject2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for textBoxPopUp
	/// </summary>
	public ref class textBoxPopUp : public System::Windows::Forms::Form
	{
	public:
		String^ fileName = gcnew String("");
		String^ text = gcnew String("");
		String^ getFileName()
		{
			return fileName;
		}
		String^ getText()
		{
			return text;

		}
		textBoxPopUp(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~textBoxPopUp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox;
	private: System::Windows::Forms::Button^  Done;
	protected:

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
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->Done = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox
			// 
			this->textBox->AcceptsReturn = true;
			this->textBox->Location = System::Drawing::Point(12, 4);
			this->textBox->Multiline = true;
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(638, 226);
			this->textBox->TabIndex = 7;
			this->textBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox->Visible = true;
			this->textBox->TextChanged += gcnew System::EventHandler(this, &textBoxPopUp::textBox_TextChanged);
			// 
			// Done
			// 
			this->Done->Location = System::Drawing::Point(269, 241);
			this->Done->Name = L"Done";
			this->Done->Size = System::Drawing::Size(117, 36);
			this->Done->TabIndex = 8;
			this->Done->Text = L"Done";
			this->Done->UseVisualStyleBackColor = true;
			this->Done->Click += gcnew System::EventHandler(this, &textBoxPopUp::Done_Click);
			// 
			// textBoxPopUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(662, 286);
			this->Controls->Add(this->Done);
			this->Controls->Add(this->textBox);
			this->Name = L"textBoxPopUp";
			this->Text = L"textBoxPopUp";
			this->Load += gcnew System::EventHandler(this, &textBoxPopUp::textBoxPopUp_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void textBoxPopUp_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void Done_Click(System::Object^  sender, System::EventArgs^  e) {
	/*	std::string temp;
		std::string fileNameTemp;*/

		this->Visible = false;
		text = this->textBox->Text;
		/*FILE *f;
		MessageBox::Show("Insert File name in cmd");
		this->textBox->Text = L"";
		this->Visible = true;
		this->textBox->Show();
		fileNameTemp = toString(this->textBox->Text);


		fileNameTemp += ".txt";
		f = fopen(fileNameTemp.c_str(), "w+");
		fwrite(temp.c_str(), 1, temp.size(), f);
		fclose(f);
		fileName = toString(fileNameTemp);*/


	}
	};
}

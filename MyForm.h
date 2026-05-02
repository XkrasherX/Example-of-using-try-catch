#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <msclr/marshal_cppstd.h>

#include "CDeque.h"
#include "CPolynom3.h"
#include "MyError.h"

namespace ooplab9prog {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
		}
			

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			delete myDeque;
			if (components)
			{
				delete components;
			}
		}
	private:
		void UpdateDeque() {
			std::stringstream s;
			s << *myDeque;
			std::string queueStr = s.str();
			ResultLabel->Text = "Now queue: " + gcnew String(queueStr.c_str());
			ErrorLabel->Text = "";
		}
		void ErrorDeque(const std::exception &e) {
			ErrorLabel->Text = gcnew String(e.what());
		}
	private: System::Windows::Forms::Button^ AddLeftButton;
	private: System::Windows::Forms::Button^ AddRightButton;
	protected:

	protected:

	private: System::Windows::Forms::Label^ EnterTextLabel;
	private: System::Windows::Forms::TextBox^ EnterTextTextBox;
	private: System::Windows::Forms::ComboBox^ SelectOptionComboBox;



	private: System::Windows::Forms::Button^ GetResultButton;
	private: System::Windows::Forms::Label^ SelectOptionLabel;


	private:
		CDeque<bool>* dequeBool;
		CDeque<float>* dequeFloat;
		CDeque<CPolynom3>* dequePolynom3;
		double value;
		int choise = 0;
	private: System::Windows::Forms::Label^ ResultLabel;
	private: System::Windows::Forms::Label^ ErrorLabel;


		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->AddLeftButton = (gcnew System::Windows::Forms::Button());
			this->AddRightButton = (gcnew System::Windows::Forms::Button());
			this->EnterTextLabel = (gcnew System::Windows::Forms::Label());
			this->EnterTextTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SelectOptionComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->GetResultButton = (gcnew System::Windows::Forms::Button());
			this->SelectOptionLabel = (gcnew System::Windows::Forms::Label());
			this->ResultLabel = (gcnew System::Windows::Forms::Label());
			this->ErrorLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// AddLeftButton
			// 
			this->AddLeftButton->Location = System::Drawing::Point(29, 107);
			this->AddLeftButton->Name = L"AddLeftButton";
			this->AddLeftButton->Size = System::Drawing::Size(33, 39);
			this->AddLeftButton->TabIndex = 0;
			this->AddLeftButton->Text = L"<-";
			this->AddLeftButton->UseVisualStyleBackColor = true;
			this->AddLeftButton->Click += gcnew System::EventHandler(this, &MyForm::AddLeftButton_Click);
			// 
			// AddRightButton
			// 
			this->AddRightButton->Location = System::Drawing::Point(96, 107);
			this->AddRightButton->Name = L"AddRightButton";
			this->AddRightButton->Size = System::Drawing::Size(33, 39);
			this->AddRightButton->TabIndex = 0;
			this->AddRightButton->Text = L"->";
			this->AddRightButton->UseVisualStyleBackColor = true;
			this->AddRightButton->Click += gcnew System::EventHandler(this, &MyForm::AddRightButton_Click);
			// 
			// EnterTextLabel
			// 
			this->EnterTextLabel->AutoSize = true;
			this->EnterTextLabel->Location = System::Drawing::Point(26, 27);
			this->EnterTextLabel->Name = L"EnterTextLabel";
			this->EnterTextLabel->Size = System::Drawing::Size(74, 16);
			this->EnterTextLabel->TabIndex = 1;
			this->EnterTextLabel->Text = L"Enter value";
			// 
			// EnterTextTextBox
			// 
			this->EnterTextTextBox->Location = System::Drawing::Point(29, 64);
			this->EnterTextTextBox->Name = L"EnterTextTextBox";
			this->EnterTextTextBox->Size = System::Drawing::Size(100, 22);
			this->EnterTextTextBox->TabIndex = 2;
			// 
			// SelectOptionComboBox
			// 
			this->SelectOptionComboBox->FormattingEnabled = true;
			this->SelectOptionComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(14) {
				L"GetSize", L"GetAvg", L"IsEmpty", L"ClearAll",
					L"operator+", L"operator-", L"operator*", L"operator=(copy)", L"operator=(moving)", L"operator<<", L"operator>>", L"DeleteLeft",
					L"DeleteRight", L"Simulate AllMem"
			});
			this->SelectOptionComboBox->Location = System::Drawing::Point(29, 230);
			this->SelectOptionComboBox->Name = L"SelectOptionComboBox";
			this->SelectOptionComboBox->Size = System::Drawing::Size(121, 24);
			this->SelectOptionComboBox->TabIndex = 3;
			this->SelectOptionComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// GetResultButton
			// 
			this->GetResultButton->Location = System::Drawing::Point(166, 222);
			this->GetResultButton->Name = L"GetResultButton";
			this->GetResultButton->Size = System::Drawing::Size(94, 39);
			this->GetResultButton->TabIndex = 4;
			this->GetResultButton->Text = L"Get Result";
			this->GetResultButton->UseVisualStyleBackColor = true;
			this->GetResultButton->Click += gcnew System::EventHandler(this, &MyForm::GetResultButton_Click);
			// 
			// SelectOptionLabel
			// 
			this->SelectOptionLabel->AutoSize = true;
			this->SelectOptionLabel->Location = System::Drawing::Point(26, 200);
			this->SelectOptionLabel->Name = L"SelectOptionLabel";
			this->SelectOptionLabel->Size = System::Drawing::Size(87, 16);
			this->SelectOptionLabel->TabIndex = 5;
			this->SelectOptionLabel->Text = L"Select Option";
			// 
			// ResultLabel
			// 
			this->ResultLabel->AutoSize = true;
			this->ResultLabel->Location = System::Drawing::Point(245, 36);
			this->ResultLabel->Name = L"ResultLabel";
			this->ResultLabel->Size = System::Drawing::Size(48, 16);
			this->ResultLabel->TabIndex = 6;
			this->ResultLabel->Text = L"Result:";
			this->ResultLabel->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// ErrorLabel
			// 
			this->ErrorLabel->AutoSize = true;
			this->ErrorLabel->Location = System::Drawing::Point(245, 84);
			this->ErrorLabel->Name = L"ErrorLabel";
			this->ErrorLabel->Size = System::Drawing::Size(36, 16);
			this->ErrorLabel->TabIndex = 7;
			this->ErrorLabel->Text = L"Error";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(571, 453);
			this->Controls->Add(this->ErrorLabel);
			this->Controls->Add(this->ResultLabel);
			this->Controls->Add(this->SelectOptionLabel);
			this->Controls->Add(this->GetResultButton);
			this->Controls->Add(this->SelectOptionComboBox);
			this->Controls->Add(this->EnterTextTextBox);
			this->Controls->Add(this->EnterTextLabel);
			this->Controls->Add(this->AddRightButton);
			this->Controls->Add(this->AddLeftButton);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AddLeftButton_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			value = Convert::ToT(EnterTextTextBox->Text);
			myDeque->addLeft(value);
			EnterTextTextBox->Clear();
			UpdateDeque();
	}
		catch (FormatException^) { ErrorLabel->Text = "Error: Wrong data in textbox!"; }
		catch (const std::exception& e) { ErrorDeque(e); }
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void AddRightButton_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		value = Convert::ToT(EnterTextTextBox->Text);
		myDeque->addRight(value);
		EnterTextTextBox->Clear();
		UpdateDeque();
	}
	catch (FormatException^) { ErrorLabel->Text = "Error: Wrong data in textbox!";}
	catch (const std::exception& e) { ErrorDeque(e); }
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void GetResultButton_Click(System::Object^ sender, System::EventArgs^ e) {

	choise = SelectOptionComboBox->SelectedIndex;
	switch (choise) {
	case 0: //Size
	{
		int size = myDeque->getSize();
		MessageBox::Show("Size is " + size.ToString(), "Result", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		break;
	}
	case 1: //Avg
	{
		try {
			T avg = myDeque->getAvg();
			MessageBox::Show("Avg is " + avg.ToString(), "Result", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			ErrorLabel->Text = "";
		}
		catch (const std::exception& e) { ErrorDeque(e); }
		break;
	}

	case 2: //IsEmpty
	{
		bool empty = myDeque->isEmpty();
		MessageBox::Show("Is empty? " + empty.ToString(), "Result", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		break;
	}
	case 3: //Clear all
		myDeque->clearAll();
		UpdateDeque();
		break;
	case 4: //op+
	{
		try {
			if (myDeque->isEmpty()) { throw Empty("Error: Trying to add empty queue!"); }
			CDeque other(myDeque->getSize(), 1.0);
			CDeque res = *myDeque + other;
			std::cout << res << std::endl;
		}
		catch (const std::exception& e) { ErrorDeque(e); }
		break;
	}
	case 5: //op-
	{
		try {
			if (myDeque->isEmpty()) { throw Empty("Error: Trying to subtract empty queue!"); }
			CDeque other(myDeque->getSize(), 1.0);
			CDeque res = *myDeque - other;
			std::cout << res << std::endl;
		}
		catch (const std::exception& e) { ErrorDeque(e); }
		break;
	}
	case 6: //op*
	{
		try {
			if (myDeque->isEmpty()) { throw Empty("Error: Trying to multiply empty queue!"); }
			*myDeque = *myDeque * 2.0;
			UpdateDeque();
			MessageBox::Show("All elements multiplied by 2", "Result");
		}
		catch (const std::exception& e) { ErrorDeque(e); }
		break;
	}
	case 7: //op copy
	{
		try {
			if (myDeque->isEmpty()) { throw Empty("Error: Trying to copy empty queue!"); }
			CDeque other;
			other = *myDeque;
			MessageBox::Show("data was copy to other succesfully!", "Result");
			std::cout << other << std::endl;
		}
		catch (const std::exception& e) { ErrorDeque(e); }
		break;
	}
	case 8: //op move
	{
			CDeque other;
			other = std::move(*myDeque);
			UpdateDeque();
			MessageBox::Show("data was moved to other succesfully!", "Result");
			std::cout << other << std::endl;
			break;
	}
	case 9: //op <<
		try {
		std::cout << *myDeque;
		UpdateDeque();
		MessageBox::Show("Operator << was called succesfully!", "Result");
		}
		catch (const std::exception& e) { ErrorDeque(e); }
		break;
	case 10: // op >>
		try {
			String^ input_text = EnterTextTextBox->Text;
			if (String::IsNullOrWhiteSpace(input_text)) {
				throw MyErrorClass("Error: enter Size value1 value2 value3 ...");
			}
			std::string s_input = msclr::interop::marshal_as<std::string>(input_text);
			std::stringstream ss(s_input);

			ss >> *myDeque;

			UpdateDeque();
			EnterTextTextBox->Clear();
			MessageBox::Show("Operator >> was called succesfully!", "Result");
		}
		catch (const std::exception& e) { ErrorDeque(e); }
		break;

	case 11: //delL
		try {
			myDeque->deleteLeft();
			UpdateDeque();
		}
		catch (const std::exception& e) {
			ErrorDeque(e);
		}
		break;
	case 12: //delR
		try {
			myDeque->deleteRight();
			UpdateDeque();
		}
		catch (const std::exception& e) {
			ErrorDeque(e);
		}
		break;
	case 13: //memAll
		try {
			CDeque big(1000000000, 1.0);
		}
		catch (const std::exception& e) { ErrorDeque(e);}
		break;
	default:
		break;
	}

}
};
}

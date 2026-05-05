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
			dequeBool = new CDeque<bool>();
			dequeFloat = new CDeque<float>();
			dequePolynom3 = new CDeque<CPolynom3>();
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			delete dequeBool;
			delete dequeFloat;
			delete dequePolynom3;
			if (components)
			{
				delete components;
			}
		}
	private:
		void UpdateDeque() {
			std::stringstream s;
			if (choise_type == 0) s << *dequeBool;
			else if (choise_type == 1) s << *dequeFloat;
			else if (choise_type == 2) {
				s << *dequePolynom3;
			}
			std::string queueStr = s.str();
			ResultLabel->Text = "Now queue: " + gcnew String(queueStr.c_str());
			ErrorLabel->Text = "";
		}
		void ErrorDeque(const std::exception& e) {
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
		int choise = 0;
		int choise_type = 0;
	private: System::Windows::Forms::Label^ ResultLabel;
	private: System::Windows::Forms::Label^ ErrorLabel;
	private: System::Windows::Forms::ComboBox^ SelectTypeComboBox;
	private: System::Windows::Forms::Label^ SelectTypeLabel;


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
			   this->SelectTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			   this->SelectTypeLabel = (gcnew System::Windows::Forms::Label());
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
				   L"GetSize", L"IsEmpty", L"ClearAll",
					   L"operator+", L"operator-", L"operator*", L"operator=(copy)", L"operator=(moving)", L"operator<<", L"operator>>", L"DeleteLeft",
					   L"DeleteRight", L"FindElementInArray", L"operator=="
			   });
			   this->SelectOptionComboBox->Location = System::Drawing::Point(248, 210);
			   this->SelectOptionComboBox->Name = L"SelectOptionComboBox";
			   this->SelectOptionComboBox->Size = System::Drawing::Size(121, 24);
			   this->SelectOptionComboBox->TabIndex = 3;
			   // 
			   // GetResultButton
			   // 
			   this->GetResultButton->Location = System::Drawing::Point(385, 202);
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
			   this->SelectOptionLabel->Location = System::Drawing::Point(245, 180);
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
			   // SelectTypeComboBox
			   // 
			   this->SelectTypeComboBox->FormattingEnabled = true;
			   this->SelectTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"bool", L"float", L"CPolynom3" });
			   this->SelectTypeComboBox->Location = System::Drawing::Point(29, 210);
			   this->SelectTypeComboBox->Name = L"SelectTypeComboBox";
			   this->SelectTypeComboBox->Size = System::Drawing::Size(121, 24);
			   this->SelectTypeComboBox->TabIndex = 8;
			   this->SelectTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			   // 
			   // SelectTypeLabel
			   // 
			   this->SelectTypeLabel->AutoSize = true;
			   this->SelectTypeLabel->Location = System::Drawing::Point(26, 181);
			   this->SelectTypeLabel->Name = L"SelectTypeLabel";
			   this->SelectTypeLabel->Size = System::Drawing::Size(80, 16);
			   this->SelectTypeLabel->TabIndex = 5;
			   this->SelectTypeLabel->Text = L"Select Type";
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(571, 453);
			   this->Controls->Add(this->SelectTypeComboBox);
			   this->Controls->Add(this->ErrorLabel);
			   this->Controls->Add(this->ResultLabel);
			   this->Controls->Add(this->SelectTypeLabel);
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
			String^ input = EnterTextTextBox->Text;
			if (choise_type == 0) {
				if (Convert::ToInt32(input)) dequeBool->addLeft(1);
				else if(Convert::ToInt32(input)==0) dequeBool->addLeft(0);
			}
			else if (choise_type == 1) {
				float value = Convert::ToSingle(input);
				dequeFloat->addLeft(value);
			}
			else if (choise_type == 2) {
			std::string s_input = msclr::interop::marshal_as<std::string>(input);
			std::stringstream ss(s_input);
			CPolynom3 poly;
			ss >> poly;
			dequePolynom3->addLeft(poly);
			}

			EnterTextTextBox->Clear();
			UpdateDeque();
		}
		catch (FormatException^) { ErrorLabel->Text = "Error: Wrong data in textbox!"; }
		catch (const std::exception& e) { ErrorDeque(e); }
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void AddRightButton_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ input = EnterTextTextBox->Text;
			if (choise_type == 0) {
				if (Convert::ToInt32(input)) dequeBool->addRight(1);
				else if (Convert::ToInt32(input) == 0) dequeBool->addRight(0);
			}
			else if (choise_type == 1) {
				float value = Convert::ToSingle(input);
				dequeFloat->addRight(value);
			}
			else if (choise_type == 2) {
				std::string s_input = msclr::interop::marshal_as<std::string>(input);
				std::stringstream ss(s_input);
				CPolynom3 poly;
				ss >> poly;
				dequePolynom3->addRight(poly);
			}
			UpdateDeque();
			EnterTextTextBox->Clear();

			
		}
		catch (FormatException^) { ErrorLabel->Text = "Error: Wrong data in textbox!"; }
		catch (const std::exception& e) { ErrorDeque(e); }
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		choise_type = SelectTypeComboBox->SelectedIndex;
		UpdateDeque();
	}
	private: System::Void GetResultButton_Click(System::Object^ sender, System::EventArgs^ e) {

		choise = SelectOptionComboBox->SelectedIndex;
		switch (choise) {
		case 0: //Size
		{
			int size = 0;
			if (choise_type == 0) size = dequeBool->getSize();
			else if (choise_type == 1) size = dequeFloat->getSize();
			else if (choise_type == 2) size = dequePolynom3->getSize();

			MessageBox::Show("Size is " + size.ToString(), "Result", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			break;
		}
		case 1: //IsEmpty
		{
			bool empty = true;
			if (choise_type == 0) empty = dequeBool->isEmpty();
			else if (choise_type == 1) empty = dequeFloat->isEmpty();
			else if (choise_type == 2) empty = dequePolynom3->isEmpty();
			MessageBox::Show("Is empty? " + empty.ToString(), "Result", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			break;
		}
		case 2: //Clear all

			if (choise_type == 0) dequeBool->clearAll();
			else if (choise_type == 1) dequeFloat->clearAll();
			else if (choise_type == 2) dequePolynom3->clearAll();

			UpdateDeque();
			break;

		case 3: //op+
		{
			try {
				if (choise_type == 0) {
					if (dequeBool->isEmpty()) throw Empty("Error: Trying to add empty queue!");
					CDeque<bool> other(dequeBool->getSize(), 1);
					CDeque<bool> res;
					res = *dequeBool + other;
					std::stringstream ss;
					ss << res;
					MessageBox::Show(gcnew String(ss.str().c_str()), "Result");
					std::cout << res << std::endl;
				}
				else if (choise_type == 1) {
					if (dequeFloat->isEmpty()) throw Empty("Error: Trying to add empty queue!");
					CDeque<float> other(dequeFloat->getSize(), 1.0f);
					CDeque<float> res;
					res = *dequeFloat + other;
					std::stringstream ss;
					ss << res;
					MessageBox::Show(gcnew String(ss.str().c_str()), "Result");
					std::cout << res << std::endl;
				}
				else if (choise_type == 2) {
					if (dequePolynom3->isEmpty()) throw Empty("Error: Trying to add empty queue!");
					CDeque<CPolynom3> other(dequePolynom3->getSize(), CPolynom3(1, 2, 3));
					CDeque<CPolynom3> res;
					res = *dequePolynom3 + other;
					std::stringstream ss;
					ss << res;
					MessageBox::Show(gcnew String(ss.str().c_str()), "Result");
					std::cout << res << std::endl;
				}
				UpdateDeque();
			}
			catch (const std::exception& e) { ErrorDeque(e); }
			break;
		}
		case 4: //op-
		{
			try {
				if (choise_type == 0) {
					if (dequeBool->isEmpty()) throw Empty("Error: Trying to add empty queue!");
					CDeque<bool> other(dequeBool->getSize(), 1);
					CDeque<bool> res;
					res = *dequeBool - other;
					std::stringstream ss;
					ss << res;
					MessageBox::Show(gcnew String(ss.str().c_str()), "Result");
					std::cout << res << std::endl;
				}
				else if (choise_type == 1) {
					if (dequeFloat->isEmpty()) throw Empty("Error: Trying to add empty queue!");
					CDeque<float> other(dequeFloat->getSize(), 1.0f);
					CDeque<float> res;
					res = *dequeFloat - other;
					std::stringstream ss;
					ss << res;
					MessageBox::Show(gcnew String(ss.str().c_str()), "Result");
					std::cout << res << std::endl;
				}
				else if (choise_type == 2) {
					if (dequePolynom3->isEmpty()) throw Empty("Error: Trying to add empty queue!");
					CDeque<CPolynom3> other(dequePolynom3->getSize(), CPolynom3(1, 2, 3));
					CDeque<CPolynom3> res;
					res = *dequePolynom3 - other;
					std::stringstream ss;
					ss << res;
					MessageBox::Show(gcnew String(ss.str().c_str()), "Result");
					std::cout << res << std::endl;
				}
				UpdateDeque();
			}
			catch (const std::exception& e) { ErrorDeque(e); }
			break;
		}
		case 5: //op*
		{
			try {
				float scalar = Convert::ToSingle(EnterTextTextBox->Text);
				if (choise_type == 0) *dequeBool = *dequeBool * (bool)scalar;
				else if (choise_type == 1) *dequeFloat = *dequeFloat * scalar;
				else if (choise_type == 2) *dequePolynom3 = *dequePolynom3 * (int)scalar;

				UpdateDeque();
				MessageBox::Show("All elements multiplied by " + scalar, "Result");
			}
			catch (const std::exception& e) { ErrorDeque(e); }
			break;
		}
		case 6: //op copy
		{
			try {
				if (choise_type == 0) {
					if (dequeBool->isEmpty())throw Empty("Error: Trying to copy empty queue!");
					CDeque<bool> other;
					other = *dequeBool;
					MessageBox::Show("data was copy to other succesfully!", "Result");
					std::cout << other << std::endl;
				}
				else if (choise_type == 1) {
					if (dequeFloat->isEmpty())throw Empty("Error: Trying to copy empty queue!");
					CDeque<float> other;
					other = *dequeFloat;
					MessageBox::Show("data was copy to other succesfully!", "Result");
					std::cout << other << std::endl;
				}
				else if (choise_type == 2) {
					if (dequePolynom3->isEmpty())throw Empty("Error: Trying to copy empty queue!");
					CDeque<CPolynom3> other;
					other = *dequePolynom3;
					MessageBox::Show("data was copy to other succesfully!", "Result");
					std::cout << other << std::endl;
				}
			}
			catch (const std::exception& e) { ErrorDeque(e); }
			break;
		}
		case 7: //op move
		{
			if (choise_type == 0) {
				CDeque<bool> other;
				other = std::move(*dequeBool);
				UpdateDeque();
				MessageBox::Show("data was moved to other succesfully!", "Result");
				std::cout << other << std::endl;
			}
			if (choise_type == 1) {
				CDeque<float> other;
				other = std::move(*dequeFloat);
				UpdateDeque();
				MessageBox::Show("data was moved to other succesfully!", "Result");
				std::cout << other << std::endl;
			}
			if (choise_type == 2) {
				CDeque<CPolynom3> other;
				other = std::move(*dequePolynom3);
				UpdateDeque();
				MessageBox::Show("data was moved to other succesfully!", "Result");
				std::cout << other << std::endl;
			}
			break;
		}
		case 8: //op <<
			try {
				if (choise_type == 0) std::cout << *dequeBool;
				else if (choise_type == 1) std::cout << *dequeFloat;
				else if (choise_type == 2) std::cout << *dequePolynom3;

				UpdateDeque();
				MessageBox::Show("Operator << was called succesfully!", "Result");
			}
			catch (const std::exception& e) { ErrorDeque(e); }
			break;
		case 9: // op >>
			try {
				std::string input = msclr::interop::marshal_as<std::string>(EnterTextTextBox->Text);
				std::stringstream ss(input);

				if (choise_type == 0) ss >> *dequeBool;
				else if (choise_type == 1) ss >> *dequeFloat;
				else if (choise_type == 2) ss >> *dequePolynom3;

				UpdateDeque();
				EnterTextTextBox->Clear();
				MessageBox::Show("Operator >> was called succesfully!", "Result");
			}
			catch (const std::exception& e) { ErrorDeque(e); }
			break;

		case 10: //delL
			try {
				if (choise_type == 0)  dequeBool->deleteLeft();
				else if (choise_type == 1) dequeFloat->deleteLeft();
				else if (choise_type == 2) dequePolynom3->deleteLeft();

				UpdateDeque();
			}
			catch (const std::exception& e) {
				ErrorDeque(e);
			}
			break;
		case 11: //delR
			try {
				if (choise_type == 0)  dequeBool->deleteRight();
				else if (choise_type == 1) dequeFloat->deleteRight();
				else if (choise_type == 2) dequePolynom3->deleteRight();

				UpdateDeque();
			}
			catch (const std::exception& e) {
				ErrorDeque(e);
			}
			break;
		case 12: // FindElementInArray
		{
			try {
				String^ input = EnterTextTextBox->Text;
				if (String::IsNullOrWhiteSpace(input)) {
					MessageBox::Show("Error: enter data!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					break;
				}

				int index = -1;
				int size = 0;

				if (choise_type == 0) {
					bool val = Convert::ToInt32(input) != 0;
					size = dequeBool->getSize();
					index = FindElementInArray(dequeBool->getArray(), size, val);
				}
				else if (choise_type == 1) {
					float val = Convert::ToSingle(input);
					size = dequeFloat->getSize();
					index = FindElementInArray(dequeFloat->getArray(), size, val);
				}
				else if (choise_type == 2) {
					std::string s_input = msclr::interop::marshal_as<std::string>(input);
					std::stringstream ss(s_input);
					CPolynom3 val;
					ss >> val;
					size = dequePolynom3->getSize();
					index = FindElementInArray(dequePolynom3->getArray(), size, val);
				}

				if (index == size || size == 0) {
					MessageBox::Show("Result: Element NOT found.");
				}
				else {
					MessageBox::Show("Result: Element found at index [" + index + "]");
				}

				EnterTextTextBox->Clear();
				ErrorLabel->Text = "";
			}
			catch (FormatException^) { ErrorLabel->Text = "Error: Wrong search data!"; }
			catch (const std::exception& e) { ErrorDeque(e); }
			break;
		}
		case 13:
		{
			try {
				String^ input = EnterTextTextBox->Text;
				if (String::IsNullOrWhiteSpace(input)) {
					MessageBox::Show("Error: Enter data!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					break;
				}
				std::string s_input = msclr::interop::marshal_as<std::string>(input);
				std::stringstream ss(s_input);
				bool isEqual = false;

				if (choise_type == 0) {
					CDeque<bool> tempDeque;
					ss >> tempDeque;
					isEqual = (*dequeBool == tempDeque);
				}
				else if (choise_type == 1) {
					CDeque<float> tempDeque;
					ss >> tempDeque;
					isEqual = (*dequeFloat == tempDeque);
				}
				else if (choise_type == 2) {
					CDeque<CPolynom3> tempDeque;
					ss >> tempDeque;
					isEqual = (*dequePolynom3 == tempDeque);
				}
				isEqual ? MessageBox::Show("Result: Queues are equal!") : MessageBox::Show("Result: Queues are not equal!");

				EnterTextTextBox->Clear();
				ErrorLabel->Text = "";
			}
			catch (const std::exception& e) { ErrorDeque(e); }
			break;
		}
		default:
			break;
		}

	}
	};
}

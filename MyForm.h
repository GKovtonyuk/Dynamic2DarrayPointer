#pragma once
#include <cstdlib> // Підключення заголовочного файлу
#include <ctime>   // Підключення заголовочного файлу для функції time()
namespace Project1 {

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
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Button^ button1;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(45, 52);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(477, 235);
			this->dataGridView1->TabIndex = 0;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(563, 52);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(487, 235);
			this->dataGridView2->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Black;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(401, 366);
			this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(213, 63);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Обчислити";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1094, 508);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// створення та заповнення випадковими числами двовимірного масиву
		int rows = 3;
		int cols = 4;
		int** arr = new int* [rows];
		for (int i = 0; i < rows; i++) {
			arr[i] = new int[cols];
			for (int j = 0; j < cols; j++) {
				arr[i][j] = rand() % 21 - 10;
			}
		}

		// виведення двовимірного масиву в datagrid1
		dataGridView1->RowCount = rows;
		dataGridView1->ColumnCount = cols;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				dataGridView1->Rows[i]->Cells[j]->Value = arr[i][j];
			}
		}

		// обчислення суми квадратів елементів
		int sum = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				sum += arr[i][j] * arr[i][j];
			}
		}

		

		// піднесення до квадрату всіх елементів масиву та виведення його в datagrid2
		dataGridView2->RowCount = rows;
		dataGridView2->ColumnCount = cols;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				int square = arr[i][j] * arr[i][j];
				dataGridView2->Rows[i]->Cells[j]->Value = square;
			}
		}

		// виведення суми квадратів елементів в MessageBox
		String^ message = String::Format("Сума квадратів: {0}", sum);
		MessageBox::Show(message);

		// звільнення пам'яті масиву
		for (int i = 0; i < rows; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}
	};
}

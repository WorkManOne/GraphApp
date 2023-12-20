#pragma once
#include "Graph.h"
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <Map>
#include <queue>
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h> 

namespace GraphApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Threading;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Thread^ myThread;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox;
	protected:


	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ grdAlgo;






	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::Button^ btn_AddV;
	private: System::Windows::Forms::Button^ btnAddCon;










	private: System::Windows::Forms::TextBox^ textBoxAddV;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1V;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox2V;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBoxW;

	private: System::Windows::Forms::CheckBox^ orBoxTrue;
	private: System::Windows::Forms::CheckBox^ orBoxFalse;
	private: System::Windows::Forms::CheckBox^ wBoxFalse;
	private: System::Windows::Forms::CheckBox^ wBoxTrue;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ btnDelV;
	private: System::Windows::Forms::Button^ btnDelCon;
	private: System::Windows::Forms::Button^ btnNextStep;
	private: System::Windows::Forms::Button^ btnSolveToEnd;
	private: System::Windows::Forms::TextBox^ txtBoxOutput;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ iter;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ isAll;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ minPair;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ comps;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ finComps;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ txtBoxPauses;
	private: System::Windows::Forms::Button^ button6;








































	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->grdAlgo = (gcnew System::Windows::Forms::DataGridView());
			this->iter = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->isAll = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->minPair = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->comps = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->finComps = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btn_AddV = (gcnew System::Windows::Forms::Button());
			this->btnAddCon = (gcnew System::Windows::Forms::Button());
			this->textBoxAddV = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1V = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2V = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxW = (gcnew System::Windows::Forms::TextBox());
			this->orBoxTrue = (gcnew System::Windows::Forms::CheckBox());
			this->orBoxFalse = (gcnew System::Windows::Forms::CheckBox());
			this->wBoxFalse = (gcnew System::Windows::Forms::CheckBox());
			this->wBoxTrue = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->btnDelV = (gcnew System::Windows::Forms::Button());
			this->btnDelCon = (gcnew System::Windows::Forms::Button());
			this->btnNextStep = (gcnew System::Windows::Forms::Button());
			this->btnSolveToEnd = (gcnew System::Windows::Forms::Button());
			this->txtBoxOutput = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->txtBoxPauses = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdAlgo))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(199, 68);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Создать граф";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox
			// 
			this->pictureBox->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->pictureBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->pictureBox->Location = System::Drawing::Point(12, 475);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(2540, 926);
			this->pictureBox->TabIndex = 2;
			this->pictureBox->TabStop = false;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(2324, 8);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(228, 72);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Открыть граф";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(217, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(372, 25);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Ориентированный\?    Взвешенный\?";
			// 
			// grdAlgo
			// 
			this->grdAlgo->AllowUserToAddRows = false;
			this->grdAlgo->AllowUserToDeleteRows = false;
			this->grdAlgo->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grdAlgo->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->iter, this->isAll,
					this->minPair, this->comps, this->finComps
			});
			this->grdAlgo->Location = System::Drawing::Point(12, 86);
			this->grdAlgo->Name = L"grdAlgo";
			this->grdAlgo->ReadOnly = true;
			this->grdAlgo->RowHeadersWidth = 82;
			this->grdAlgo->RowTemplate->Height = 20;
			this->grdAlgo->Size = System::Drawing::Size(2540, 311);
			this->grdAlgo->TabIndex = 6;
			this->grdAlgo->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// iter
			// 
			this->iter->HeaderText = L"Итерация";
			this->iter->MinimumWidth = 10;
			this->iter->Name = L"iter";
			this->iter->ReadOnly = true;
			this->iter->Width = 153;
			// 
			// isAll
			// 
			this->isAll->HeaderText = L"Все вершины в компоненте\?";
			this->isAll->MinimumWidth = 10;
			this->isAll->Name = L"isAll";
			this->isAll->ReadOnly = true;
			this->isAll->Width = 315;
			// 
			// minPair
			// 
			this->minPair->HeaderText = L"Пара с минимальным весом";
			this->minPair->MinimumWidth = 10;
			this->minPair->Name = L"minPair";
			this->minPair->ReadOnly = true;
			this->minPair->Width = 311;
			// 
			// comps
			// 
			this->comps->HeaderText = L"Компоненты пары";
			this->comps->MinimumWidth = 10;
			this->comps->Name = L"comps";
			this->comps->ReadOnly = true;
			this->comps->Width = 220;
			// 
			// finComps
			// 
			this->finComps->HeaderText = L"Итоговые компоненты";
			this->finComps->MinimumWidth = 10;
			this->finComps->Name = L"finComps";
			this->finComps->ReadOnly = true;
			this->finComps->Width = 257;
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			this->openFileDialog->Filter = L"Все файлы (*.*)|*.*";
			this->openFileDialog->Title = L"Открыть файл";
			// 
			// btn_AddV
			// 
			this->btn_AddV->Location = System::Drawing::Point(609, 8);
			this->btn_AddV->Name = L"btn_AddV";
			this->btn_AddV->Size = System::Drawing::Size(211, 72);
			this->btn_AddV->TabIndex = 7;
			this->btn_AddV->Text = L"Добавить вершину";
			this->btn_AddV->UseVisualStyleBackColor = true;
			this->btn_AddV->Click += gcnew System::EventHandler(this, &MyForm::btn_AddV_Click);
			// 
			// btnAddCon
			// 
			this->btnAddCon->Location = System::Drawing::Point(1187, 8);
			this->btnAddCon->Name = L"btnAddCon";
			this->btnAddCon->Size = System::Drawing::Size(199, 72);
			this->btnAddCon->TabIndex = 8;
			this->btnAddCon->Text = L"Добавить связь";
			this->btnAddCon->UseVisualStyleBackColor = true;
			this->btnAddCon->Click += gcnew System::EventHandler(this, &MyForm::btnAddCon_Click);
			// 
			// textBoxAddV
			// 
			this->textBoxAddV->Location = System::Drawing::Point(826, 42);
			this->textBoxAddV->Name = L"textBoxAddV";
			this->textBoxAddV->Size = System::Drawing::Size(150, 31);
			this->textBoxAddV->TabIndex = 13;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(826, 8);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(150, 25);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Имя вершины";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1392, 8);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(168, 25);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Имя вершины 1";
			// 
			// textBox1V
			// 
			this->textBox1V->Location = System::Drawing::Point(1392, 42);
			this->textBox1V->Name = L"textBox1V";
			this->textBox1V->Size = System::Drawing::Size(168, 31);
			this->textBox1V->TabIndex = 15;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(1566, 8);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(168, 25);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Имя вершины 2";
			// 
			// textBox2V
			// 
			this->textBox2V->Location = System::Drawing::Point(1566, 42);
			this->textBox2V->Name = L"textBox2V";
			this->textBox2V->Size = System::Drawing::Size(168, 31);
			this->textBox2V->TabIndex = 17;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(1740, 8);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(166, 25);
			this->label5->TabIndex = 20;
			this->label5->Text = L"Вес (если есть)";
			// 
			// textBoxW
			// 
			this->textBoxW->Location = System::Drawing::Point(1740, 42);
			this->textBoxW->Name = L"textBoxW";
			this->textBoxW->Size = System::Drawing::Size(168, 31);
			this->textBoxW->TabIndex = 19;
			// 
			// orBoxTrue
			// 
			this->orBoxTrue->AutoSize = true;
			this->orBoxTrue->Location = System::Drawing::Point(222, 37);
			this->orBoxTrue->Name = L"orBoxTrue";
			this->orBoxTrue->Size = System::Drawing::Size(72, 29);
			this->orBoxTrue->TabIndex = 21;
			this->orBoxTrue->Text = L"Да";
			this->orBoxTrue->UseVisualStyleBackColor = true;
			this->orBoxTrue->CheckedChanged += gcnew System::EventHandler(this, &MyForm::orBoxTrue_CheckedChanged);
			// 
			// orBoxFalse
			// 
			this->orBoxFalse->AutoSize = true;
			this->orBoxFalse->Location = System::Drawing::Point(333, 37);
			this->orBoxFalse->Name = L"orBoxFalse";
			this->orBoxFalse->Size = System::Drawing::Size(81, 29);
			this->orBoxFalse->TabIndex = 22;
			this->orBoxFalse->Text = L"Нет";
			this->orBoxFalse->UseVisualStyleBackColor = true;
			this->orBoxFalse->CheckedChanged += gcnew System::EventHandler(this, &MyForm::orBoxFalse_CheckedChanged);
			// 
			// wBoxFalse
			// 
			this->wBoxFalse->AutoSize = true;
			this->wBoxFalse->Location = System::Drawing::Point(509, 36);
			this->wBoxFalse->Name = L"wBoxFalse";
			this->wBoxFalse->Size = System::Drawing::Size(81, 29);
			this->wBoxFalse->TabIndex = 24;
			this->wBoxFalse->Text = L"Нет";
			this->wBoxFalse->UseVisualStyleBackColor = true;
			this->wBoxFalse->CheckedChanged += gcnew System::EventHandler(this, &MyForm::wBoxFalse_CheckedChanged);
			// 
			// wBoxTrue
			// 
			this->wBoxTrue->AutoSize = true;
			this->wBoxTrue->Location = System::Drawing::Point(431, 36);
			this->wBoxTrue->Name = L"wBoxTrue";
			this->wBoxTrue->Size = System::Drawing::Size(72, 29);
			this->wBoxTrue->TabIndex = 23;
			this->wBoxTrue->Text = L"Да";
			this->wBoxTrue->UseVisualStyleBackColor = true;
			this->wBoxTrue->CheckedChanged += gcnew System::EventHandler(this, &MyForm::wBoxTrue_CheckedChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(2119, 8);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(199, 72);
			this->button2->TabIndex = 25;
			this->button2->Text = L"Стереть граф";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// btnDelV
			// 
			this->btnDelV->Location = System::Drawing::Point(982, 8);
			this->btnDelV->Name = L"btnDelV";
			this->btnDelV->Size = System::Drawing::Size(199, 72);
			this->btnDelV->TabIndex = 26;
			this->btnDelV->Text = L"Удалить вершину";
			this->btnDelV->UseVisualStyleBackColor = true;
			this->btnDelV->Click += gcnew System::EventHandler(this, &MyForm::btnDelV_Click);
			// 
			// btnDelCon
			// 
			this->btnDelCon->Location = System::Drawing::Point(1914, 8);
			this->btnDelCon->Name = L"btnDelCon";
			this->btnDelCon->Size = System::Drawing::Size(199, 72);
			this->btnDelCon->TabIndex = 27;
			this->btnDelCon->Text = L"Удалить связь";
			this->btnDelCon->UseVisualStyleBackColor = true;
			this->btnDelCon->Click += gcnew System::EventHandler(this, &MyForm::btnDelCon_Click);
			// 
			// btnNextStep
			// 
			this->btnNextStep->Location = System::Drawing::Point(217, 401);
			this->btnNextStep->Name = L"btnNextStep";
			this->btnNextStep->Size = System::Drawing::Size(199, 68);
			this->btnNextStep->TabIndex = 28;
			this->btnNextStep->Text = L"Следущий шаг";
			this->btnNextStep->UseVisualStyleBackColor = true;
			this->btnNextStep->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// btnSolveToEnd
			// 
			this->btnSolveToEnd->Location = System::Drawing::Point(12, 401);
			this->btnSolveToEnd->Name = L"btnSolveToEnd";
			this->btnSolveToEnd->Size = System::Drawing::Size(199, 68);
			this->btnSolveToEnd->TabIndex = 29;
			this->btnSolveToEnd->Text = L"Запустить алгоритм";
			this->btnSolveToEnd->UseVisualStyleBackColor = true;
			this->btnSolveToEnd->Click += gcnew System::EventHandler(this, &MyForm::btnSolveToEnd_Click);
			// 
			// txtBoxOutput
			// 
			this->txtBoxOutput->Location = System::Drawing::Point(1054, 420);
			this->txtBoxOutput->Name = L"txtBoxOutput";
			this->txtBoxOutput->ReadOnly = true;
			this->txtBoxOutput->Size = System::Drawing::Size(922, 31);
			this->txtBoxOutput->TabIndex = 30;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(422, 401);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(199, 68);
			this->button4->TabIndex = 31;
			this->button4->Text = L"Решить до конца";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click_1);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(627, 401);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(199, 68);
			this->button5->TabIndex = 32;
			this->button5->Text = L"Решить с паузами (мс)";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// txtBoxPauses
			// 
			this->txtBoxPauses->Location = System::Drawing::Point(832, 420);
			this->txtBoxPauses->Name = L"txtBoxPauses";
			this->txtBoxPauses->Size = System::Drawing::Size(150, 31);
			this->txtBoxPauses->TabIndex = 33;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button6->Location = System::Drawing::Point(2355, 406);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(197, 57);
			this->button6->TabIndex = 34;
			this->button6->Text = L"Справка";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(2564, 1416);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->txtBoxPauses);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->txtBoxOutput);
			this->Controls->Add(this->btnSolveToEnd);
			this->Controls->Add(this->btnNextStep);
			this->Controls->Add(this->btnDelCon);
			this->Controls->Add(this->btnDelV);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->wBoxFalse);
			this->Controls->Add(this->wBoxTrue);
			this->Controls->Add(this->orBoxFalse);
			this->Controls->Add(this->orBoxTrue);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBoxW);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2V);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1V);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxAddV);
			this->Controls->Add(this->btnAddCon);
			this->Controls->Add(this->btn_AddV);
			this->Controls->Add(this->grdAlgo);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->pictureBox);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdAlgo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		String^ wayToFile = "defaultGraph";
		int numCircles = 5;
		int R = 10 * (numCircles * 0.6);
		int radius = 50 * (numCircles * 0.9); // Задайте радиус вашей окружности
		bool isPaused = true;
		bool solveToEnd = false;
		int pauseInt = 0;
		// данный метод будет исполняться в отдельном потоке
	public: void Print(Graph m) {

		// создаем изображение
		Bitmap^ image = gcnew Bitmap(pictureBox->Width, pictureBox->Height);

		// получаем объект для рисования
		Graphics^ g = Graphics::FromImage(image);

		map<string, set<pair<string, int>>> newV = m.getList();
		numCircles = newV.size();
		R = 30 * pow(0.96, numCircles);

		double step = 360.0 / numCircles;

		for (int l = 0; l < numCircles; ++l)
		{
			double angle = l * step * 3.14159265 / 180.0; // Преобразование градусов в радианы
			int x = pictureBox->Width / 2 + radius * cos(angle);
			int y = pictureBox->Height / 2 + radius * sin(angle);

			Pen^ blackPen = gcnew Pen(Color::Black, 3);

			for (int ln = 0; ln < numCircles; ++ln)
			{
				if (ln == l) continue; //FIX THIS!!!!!!!!!!!!!!!!!!!!!
				auto It = next(newV.begin(), l);
				auto It2 = next(newV.begin(), ln);
				if (!m.findInCertainNode(It->first, It2->first)) continue;
				double angle_to = ln * step * 3.14159265 / 180.0; // Преобразование градусов в радианы
				int x_to = pictureBox->Width / 2 + radius * cos(angle_to);
				int y_to = pictureBox->Height / 2 + radius * sin(angle_to);

				if (abs(ln - l) <= 1 || abs(ln - l) == numCircles - 1)
				{
					// Если да, то не изменяем длину линии
					int difference = abs(ln - l);
					int newDistance = radius - 30 * numCircles * pow(0.945, numCircles);
					double angle = atan2(y_to - y, x_to - x);
					x_to = x + newDistance * cos(angle);
					y_to = y + newDistance * sin(angle);
					g->DrawLine(blackPen, x, y, x_to, y_to);
					g->FillEllipse(Brushes::Red, int(x_to - 10 * pow(0.94, numCircles)), y_to - 10 * pow(0.94, numCircles), 20 * pow(0.94, numCircles), 20 * pow(0.94, numCircles));
				}
				else
				{
					// Если нет, то укорачиваем линию
					int difference = abs(ln - l);
					int newDistance = radius - 20 * numCircles * pow(0.977, numCircles) + (difference <= numCircles / 2 ? difference : (numCircles - difference)) * 23;
					double angle = atan2(y_to - y, x_to - x);
					x_to = x + newDistance * cos(angle);
					y_to = y + newDistance * sin(angle);

					g->DrawLine(blackPen, x, y, x_to, y_to);
					g->FillEllipse(Brushes::Red, int(x_to - 10 * pow(0.94, numCircles)), y_to - 10 * pow(0.94, numCircles), 20 * pow(0.94, numCircles), 20 * pow(0.94, numCircles));
				}
			}
		}
		for (int l = 0; l < numCircles; ++l)
		{
			double angle = l * step * 3.14159265 / 180.0; // Преобразование градусов в радианы
			int x = pictureBox->Width / 2 + radius * cos(angle);
			int y = pictureBox->Height / 2 + radius * sin(angle);

			int circleX = x - R; // Половина ширины круга
			int circleY = y - R; // Половина высоты круга

			SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 30 * pow(0.95, numCircles));
			auto It = next(newV.begin(), l);
			String^ nameOfNode = gcnew String(It->first.c_str());
			g->FillEllipse(Brushes::Green, circleX, circleY, 2 * R, 2 * R);
			g->DrawString(nameOfNode, drawFont, drawBrush, circleX + R / 2, circleY + R / 2);
			for (int ln = 0; ln < numCircles; ++ln)
			{
				if (ln == l) continue; //FIX THIS!!!!!!!!!!!!!!!!!!!!!
				auto It = next(newV.begin(), l);
				auto It2 = next(newV.begin(), ln);
				if (!m.findInCertainNode(It->first, It2->first)) continue;
				double angle_to = ln * step * 3.14159265 / 180.0; // Преобразование градусов в радианы
				int x_to = pictureBox->Width / 2 + radius * cos(angle_to);
				int y_to = pictureBox->Height / 2 + radius * sin(angle_to);

				if (abs(ln - l) <= 1 || abs(ln - l) == numCircles - 1)
				{
					int difference = abs(ln - l);
					int newDistance = radius - 30 * numCircles * pow(0.945, numCircles);
					double angle = atan2(y_to - y, x_to - x);
					x_to = x + newDistance * cos(angle);
					y_to = y + newDistance * sin(angle);
				}
				else
				{
					int difference = abs(ln - l);
					int newDistance = radius - 20 * numCircles * pow(0.977, numCircles) + (difference <= numCircles / 2 ? difference : (numCircles - difference)) * 23;
					double angle = atan2(y_to - y, x_to - x);
					x_to = x + newDistance * cos(angle);
					y_to = y + newDistance * sin(angle);
				}
				SolidBrush^ drawBrush = gcnew SolidBrush(Color::White);
				System::Drawing::Font^ drawFont2 = gcnew System::Drawing::Font("Arial", 15 * pow(0.95, numCircles));
				g->DrawString(m.getPairWithName(It->first, It2->first).second.ToString(), drawFont2, drawBrush, x_to, y_to);

			}
		}
		SetImageToPictureBox(image);
	}

	public: void SetImageToPictureBox(Bitmap^ image) {
		pictureBox->Image = image;
	}

	public: void extraPrint(Graph m, set<Triplet> colorized, set<Triplet> colorizedOstov) {

		// создаем изображение
		Bitmap^ image = gcnew Bitmap(pictureBox->Width, pictureBox->Height);

		// получаем объект для рисования
		Graphics^ g = Graphics::FromImage(image);

		map<string, set<pair<string, int>>> newV = m.getList();
		numCircles = newV.size();
		R = 30 * pow(0.96, numCircles);

		double step = 360.0 / numCircles;

		for (int l = 0; l < numCircles; ++l)
		{
			double angle = l * step * 3.14159265 / 180.0; // Преобразование градусов в радианы
			int x = pictureBox->Width / 2 + radius * cos(angle);
			int y = pictureBox->Height / 2 + radius * sin(angle);

			for (int ln = 0; ln < numCircles; ++ln)
			{
				if (ln == l) continue; //FIX THIS!!!!!!!!!!!!!!!!!!!!!
				auto It = next(newV.begin(), l);
				auto It2 = next(newV.begin(), ln);
				if (!m.findInCertainNode(It->first, It2->first)) continue;
				bool coloring = false;
				for (auto& elem : colorized) {
					if (It->first == elem.first && It2->first == elem.second
						|| It2->first == elem.first && It->first == elem.second) {
						coloring = true;
						break;
					}
				}
				bool coloringOstov = false;
				for (auto& elem : colorizedOstov) {
					if (It->first == elem.first && It2->first == elem.second
						|| It2->first == elem.first && It->first == elem.second) {
						coloringOstov = true;
						break;
					}
				}
				Pen^ specPen = gcnew Pen(Color::Black, 3);
				if (coloringOstov) {
					specPen = gcnew Pen(Color::Orange, 3);
				}
				else if (coloring) {
					specPen = gcnew Pen(Color::Pink, 3);
				}
				else {
					specPen = gcnew Pen(Color::Black, 3);
				}
				double angle_to = ln * step * 3.14159265 / 180.0; // Преобразование градусов в радианы
				int x_to = pictureBox->Width / 2 + radius * cos(angle_to);
				int y_to = pictureBox->Height / 2 + radius * sin(angle_to);

				if (abs(ln - l) <= 1 || abs(ln - l) == numCircles - 1)
				{
					// Если да, то не изменяем длину линии
					int difference = abs(ln - l);
					int newDistance = radius - 30 * numCircles * pow(0.945, numCircles);
					double angle = atan2(y_to - y, x_to - x);
					x_to = x + newDistance * cos(angle);
					y_to = y + newDistance * sin(angle);
					g->DrawLine(specPen, x, y, x_to, y_to);
					g->FillEllipse(Brushes::Red, int(x_to - 10 * pow(0.94, numCircles)), y_to - 10 * pow(0.94, numCircles), 20 * pow(0.94, numCircles), 20 * pow(0.94, numCircles));
				}
				else
				{
					// Если нет, то укорачиваем линию
					int difference = abs(ln - l);
					int newDistance = radius - 20 * numCircles * pow(0.977, numCircles) + (difference <= numCircles / 2 ? difference : (numCircles - difference)) * 23;
					double angle = atan2(y_to - y, x_to - x);
					x_to = x + newDistance * cos(angle);
					y_to = y + newDistance * sin(angle);

					g->DrawLine(specPen, x, y, x_to, y_to);
					g->FillEllipse(Brushes::Red, int(x_to - 10 * pow(0.94, numCircles)), y_to - 10 * pow(0.94, numCircles), 20 * pow(0.94, numCircles), 20 * pow(0.94, numCircles));
				}
			}
		}
		for (int l = 0; l < numCircles; ++l)
		{
			double angle = l * step * 3.14159265 / 180.0; // Преобразование градусов в радианы
			int x = pictureBox->Width / 2 + radius * cos(angle);
			int y = pictureBox->Height / 2 + radius * sin(angle);

			int circleX = x - R; // Половина ширины круга
			int circleY = y - R; // Половина высоты круга

			SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 30 * pow(0.95, numCircles));
			auto It = next(newV.begin(), l);
			String^ nameOfNode = gcnew String(It->first.c_str());
			g->FillEllipse(Brushes::Green, circleX, circleY, 2 * R, 2 * R);
			g->DrawString(nameOfNode, drawFont, drawBrush, circleX + R / 2, circleY + R / 2);
			for (int ln = 0; ln < numCircles; ++ln)
			{
				if (ln == l) continue; //FIX THIS!!!!!!!!!!!!!!!!!!!!!
				auto It = next(newV.begin(), l);
				auto It2 = next(newV.begin(), ln);
				if (!m.findInCertainNode(It->first, It2->first)) continue;
				double angle_to = ln * step * 3.14159265 / 180.0; // Преобразование градусов в радианы
				int x_to = pictureBox->Width / 2 + radius * cos(angle_to);
				int y_to = pictureBox->Height / 2 + radius * sin(angle_to);

				if (abs(ln - l) <= 1 || abs(ln - l) == numCircles - 1)
				{
					int difference = abs(ln - l);
					int newDistance = radius - 30 * numCircles * pow(0.945, numCircles);
					double angle = atan2(y_to - y, x_to - x);
					x_to = x + newDistance * cos(angle);
					y_to = y + newDistance * sin(angle);
				}
				else
				{
					int difference = abs(ln - l);
					int newDistance = radius - 20 * numCircles * pow(0.977, numCircles) + (difference <= numCircles / 2 ? difference : (numCircles - difference)) * 23;
					double angle = atan2(y_to - y, x_to - x);
					x_to = x + newDistance * cos(angle);
					y_to = y + newDistance * sin(angle);
				}
				SolidBrush^ drawBrush = gcnew SolidBrush(Color::White);
				System::Drawing::Font^ drawFont2 = gcnew System::Drawing::Font("Arial", 15 * pow(0.95, numCircles));
				g->DrawString(m.getPairWithName(It->first, It2->first).second.ToString(), drawFont2, drawBrush, x_to, y_to);

			}
		}
		SetImageToPictureBox(image);
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		bool orient = orBoxTrue->Checked;
		bool weight = wBoxTrue->Checked;
		Graph mainG = Graph(weight, orient);
		mainG.Writefile("defaultGraph");
		wayToFile = "defaultGraph";
		Print(mainG);
	}
	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		Refresh();
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	System::IO::Stream^ myStream;
	if (this->openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		msclr::interop::marshal_context context;
		wayToFile = this->openFileDialog->FileName;

		string sw = context.marshal_as<std::string>(wayToFile);
		Graph(sw).Writefile("defaultGraph");
		wayToFile = "defaultGraph";
		Print(Graph(sw));
	}
}

private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}

private: System::Void orBoxTrue_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (orBoxFalse->Checked) orBoxTrue->Checked = false;
}
private: System::Void orBoxFalse_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (orBoxTrue->Checked) orBoxFalse->Checked = false;
}
private: System::Void wBoxTrue_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (wBoxFalse->Checked) wBoxTrue->Checked = false;
}
private: System::Void wBoxFalse_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (wBoxTrue->Checked) wBoxFalse->Checked = false;
}
private: System::Void btn_AddV_Click(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;
	string sw = context.marshal_as<std::string>(wayToFile);
	Graph mainG = Graph(sw);
	mainG.NodeAdd(context.marshal_as<std::string>(textBoxAddV->Text));
	Print(mainG);
	mainG.Writefile("defaultGraph");
	wayToFile = "defaultGraph";
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Print(Graph());
	Graph(0, 0).Writefile("defaultGraph");
	wayToFile = "defaultGraph";
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;
	string sw = context.marshal_as<std::string>(wayToFile);
	Graph mainG = Graph(sw);
	Print(mainG);
}
private: System::Void btnDelV_Click(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;
	string sw = context.marshal_as<std::string>(wayToFile);
	Graph mainG = Graph(sw);
	mainG.NodeDel(context.marshal_as<std::string>(textBoxAddV->Text));
	Print(mainG);
	mainG.Writefile("defaultGraph");
	wayToFile = "defaultGraph";
}
private: System::Void btnAddCon_Click(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;
	string sw = context.marshal_as<std::string>(wayToFile);
	Graph mainG = Graph(sw);
	int x = 0;
	mainG.NodeConnect(context.marshal_as<std::string>(textBox1V->Text), 
						context.marshal_as<std::string>(textBox2V->Text),
							Int32::TryParse(textBoxW->Text, x) ? x : 0);
	
	Print(mainG);
	mainG.Writefile("defaultGraph");
	wayToFile = "defaultGraph";
}
private: System::Void btnDelCon_Click(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;
	string sw = context.marshal_as<std::string>(wayToFile);
	Graph mainG = Graph(sw);
	mainG.NodeDisconnect(context.marshal_as<std::string>(textBox1V->Text),
							context.marshal_as<std::string>(textBox2V->Text));
	Print(mainG);
	mainG.Writefile("defaultGraph");
	wayToFile = "defaultGraph";
}
private: System::String^ toStringComponent(set<string> way) {
	String^ s = "{";
	for (auto& elem : way) {
		s += gcnew String(elem.c_str()) + ", ";
	}
	s = s->Substring(0, s->Length - 2);
	s += "}";
	return s;
}
private: System::Void ostovKraskalView() {
	txtBoxOutput->BeginInvoke(gcnew InvokeDelegateTxtBox(this, &MyForm::SetTextToTextBoxOutput), "Выполнение...");
	set<Triplet> visited;
	set<Triplet> inOstov;
	grdAlgo->BeginInvoke(gcnew InvokeDelegateClearGrid(this, &MyForm::ClearGrid));
	msclr::interop::marshal_context context;
	string sw = context.marshal_as<std::string>(wayToFile);
	Graph m = Graph(sw);
	int count = 0;
	Graph tempErrored = m;
	map<string, set<pair<string, int>>> mList = m.getList();
	if (m.isOriented() || !m.isWeighted() || mList.empty()) {
		txtBoxOutput->BeginInvoke(gcnew InvokeDelegateTxtBox(this, &MyForm::SetTextToTextBoxOutput), "Введен пустой или ориентированный или невзвешенный граф");
		Print(tempErrored);
		myThread->Abort();
		return;
	}

	Graph newG(1, 0);
	map<string, set<pair<string, int>>> newV = mList;

	for (auto const& element : mList) {
		newG.NodeAdd(element.first);
	}
	txtBoxOutput->BeginInvoke(gcnew InvokeDelegateTxtBox(this, &MyForm::SetTextToTextBoxOutput), "Выполнение...");
	extraPrint(m, visited, inOstov);
	//STEP-1(show that graph has built)==================================================
	txtBoxOutput->BeginInvoke(gcnew InvokeDelegateTxtBox(this, &MyForm::SetTextToTextBoxOutput), gcnew String("Ожидание нажатия кнопки СЛЕДУЮЩИЙ ШАГ"));
	isPaused = true;
	while (isPaused && !solveToEnd) {

	}
	Thread::Sleep(pauseInt);
	txtBoxOutput->BeginInvoke(gcnew InvokeDelegateTxtBox(this, &MyForm::SetTextToTextBoxOutput), "Выполнение...");
	int iteration = 0;
	grdAlgo->BeginInvoke(gcnew InvokeDelegateAddRow(this, &MyForm::AddRow), iteration.ToString(), 0);
	grdAlgo->BeginInvoke(gcnew InvokeDelegateAddRow(this, &MyForm::EditRow), m.allNodesConnected(newG).ToString(), 1);
	while (!m.allNodesConnected(newG)) {
		Triplet way = m.NodesMinWeight(newV);
		String^ fr = gcnew String(way.first.c_str());
		String^ sc = gcnew String(way.second.c_str());
		String^ th = way.third.ToString();
		if (way.third == INT_MAX) {
			txtBoxOutput->BeginInvoke(gcnew InvokeDelegateTxtBox(this, &MyForm::SetTextToTextBoxOutput), "Невозможно получить остов, одна из вершин ''отрезана'' от других");
			Print(tempErrored);
			myThread->Abort();
			return;
		}
		visited.insert(way);
		extraPrint(m, visited, inOstov);
		//Thread::Sleep(5000);
		//STEP-2 (show visited)====================================================
		txtBoxOutput->BeginInvoke(gcnew InvokeDelegateTxtBox(this, &MyForm::SetTextToTextBoxOutput), gcnew String("Ожидание нажатия кнопки СЛЕДУЮЩИЙ ШАГ"));
		isPaused = true;
		while (isPaused && !solveToEnd) {

		}
		Thread::Sleep(pauseInt);
		txtBoxOutput->BeginInvoke(gcnew InvokeDelegateTxtBox(this, &MyForm::SetTextToTextBoxOutput), "Выполнение...");
		grdAlgo->BeginInvoke(gcnew InvokeDelegateAddRow(this, &MyForm::EditRow), 
								fr + " - " +
								sc + 
								" : " + th, 2);
		grdAlgo->BeginInvoke(gcnew InvokeDelegateAddRow(this, &MyForm::EditRow), 
								toStringComponent(newG.showComponentContain(way.first)) + " " +
								toStringComponent(newG.showComponentContain(way.second)), 3);

		if (newG.showComponentContain(way.first) == newG.showComponentContain(way.second)) {
			//ничего не делаем и просто удаляем ребро
			grdAlgo->BeginInvoke(gcnew InvokeDelegateEditRow(this, &MyForm::EditRow),
				toStringComponent(newG.showComponentContain(way.first)), 4);
		}
		else {
			newG.NodeConnect(way.first, way.second, way.third);
			grdAlgo->BeginInvoke(gcnew InvokeDelegateEditRow(this, &MyForm::EditRow),
				toStringComponent(newG.showComponentContain(way.first)), 4);
			inOstov.insert(way);
			extraPrint(m, visited, inOstov);
			//Thread::Sleep(5000);
		}
		//STEP-3(show all in all: ostov or not and table)=================================================
		txtBoxOutput->BeginInvoke(gcnew InvokeDelegateTxtBox(this, &MyForm::SetTextToTextBoxOutput), gcnew String("Ожидание нажатия кнопки СЛЕДУЮЩИЙ ШАГ"));
		isPaused = true;
		while (isPaused && !solveToEnd) {

		}
		Thread::Sleep(pauseInt);
		txtBoxOutput->BeginInvoke(gcnew InvokeDelegateTxtBox(this, &MyForm::SetTextToTextBoxOutput), "Выполнение...");
		for (auto it = newV[way.first].begin(); it != newV[way.first].end(); it++) {
			if (it->first == way.second) {
				newV[way.first].erase(it);
				break;
			}
		}
		for (auto it = newV[way.second].begin(); it != newV[way.second].end(); it++) {
			if (it->first == way.first) {
				newV[way.second].erase(it);
				break;
			}
		}
		
		iteration++;
		grdAlgo->BeginInvoke(gcnew InvokeDelegateAddRow(this, &MyForm::AddRow), iteration.ToString(), 0);
		grdAlgo->BeginInvoke(gcnew InvokeDelegateAddRow(this, &MyForm::EditRow), m.allNodesConnected(newG).ToString(), 1);
	}
	extraPrint(m, visited, inOstov);
	txtBoxOutput->BeginInvoke(gcnew InvokeDelegateTxtBox(this, &MyForm::SetTextToTextBoxOutput), "Успешно выполнено");
	solveToEnd = false;
	pauseInt = 0;
	myThread->Abort();
}

public: void ClearGrid() {
	grdAlgo->Rows->Clear();
}
delegate void InvokeDelegateClearGrid();

public: void EditRow(String^ text, int n) {
	int i = grdAlgo->Rows->Count - 1;
	grdAlgo->Rows[i]->Cells[n]->Value = text;
}
delegate void InvokeDelegateEditRow(String^ text, int n);

public: void AddRow(String^ text, int n) {
	grdAlgo->Rows->Add();
	int i = grdAlgo->Rows->Count - 1; 
	grdAlgo->Rows[i]->Cells[n]->Value = text;
}
delegate void InvokeDelegateAddRow(String^ text, int n);

public: void SetTextToTextBoxOutput(System::String^ text) {
	txtBoxOutput->Text = text;
}
delegate void InvokeDelegateTxtBox(String^ text);

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	isPaused = false;
}
private: System::Void btnSolveToEnd_Click(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;
	string sw = context.marshal_as<std::string>(wayToFile);
	Graph mainG = Graph(sw);
	myThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::ostovKraskalView));
	myThread->Start();
}
private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {

}
private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {
	solveToEnd = true;
	pauseInt = 0;
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	solveToEnd = true;
	int x;
	bool tryx = Int32::TryParse(txtBoxPauses->Text, x);
	if (tryx) pauseInt = x;
	else pauseInt = 0;
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show(
		"Это приложение с визуализацией алгоритма Краскала нахождения минимального каркаса. \nОно может также использоваться для визуализации некоторых других графов с помощью кнопок интерфейса. \n\nДля того чтобы познакомиться с устройством синтаксиса файла который сохраняется/открывается (чтобы не получать ошибок) рекомендуется создать пробный граф, сохранить и просмотреть его с помощью текстового редактора (обратите внимание на НЕОБХОДИМЫЕ пробелы в конце некоторых строк). \n\nАлгоритм для работы с программой:\n1. Загрузите корректный(!!!) файл с графом или создайте свой с помощью интерфейса приложения. \n2. Нажмите кнопку Запустить алгоритм \n3. Исследуйте работу алгоритма с помощью кнопок: \n\nСледующий шаг - для просмотра его работы по шагам \nРешить до конца - представления конечного решения \nРешить с паузами - пошагового решения без нужды нажатия кнопки Следующий шаг \n\nP.S. \nОтслеживайте статус выполнения в текстовой строке над полем рисунка графа. \nНа графе розовым отмечаются посещенные ребра, оранжевым - включенные в каркас. \nПо красным кружочкам на концах ребер можно понимать направление ребра в графе.", 
		"Справка", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
};
}

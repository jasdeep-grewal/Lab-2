#pragma once
#include "stdafx.h"
#include "CStudent.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>

using namespace std;

class CStudent
{
	private:
		//CStudent(string student_number, float lab, float quiz, float midterm, float final_exam);
		string student_number;
		float lab;
		float quiz;
		float midterm;
		float final_exam;	
	public:
		void setstudent_number(string nstudent_number);
		string getstudent_number();

		void setlab(float nlab);
		float getlab();

		void setquiz(float nquiz);
		float getquiz();

		void setmidterm(float nmidterm);
		float getmidterm();

		void setfinal_exam(float nfinal_exam);
		float getfinal_exam();
};

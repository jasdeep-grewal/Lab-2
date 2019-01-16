#include "stdafx.h"
#include "CStudent.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
using namespace std;

CStudent::CStudent(string student_number, float lab, float quiz, float midterm, float final_exam) 
	{
		CStudent::student_number = student_number;
		CStudent::lab = lab;
		CStudent::quiz = quiz;
		CStudent::midterm = midterm;
		CStudent::final_exam = final_exam;
};



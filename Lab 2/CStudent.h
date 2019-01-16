#pragma once
#include "stdafx.h"
#include "CStudent.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include "CCourse.h"
using namespace std;

class CStudent
{
	public:
		CStudent(string student_number, float lab, float quiz, float midterm, float final_exam);

		string student_number;
		float lab;
		float quiz;
		float midterm;
		float final_exam;	
};
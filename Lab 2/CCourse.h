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


class CCourse
{
	public:

		void addStudent();
		void editStudent();
		void printStudent();
		void deleteStudent();
		void saveStudent();
		void loadStudent();
		bool getStudentInfo(CStudent &student);

		void setvector(vector <CStudent> students);
		vector<CStudent> getStudents();

	private:
		vector <CStudent> students;

		bool isFloat(string number);
		string trim(string myString);
		float getValidFloat(string inputDescription, float min, float max);
};
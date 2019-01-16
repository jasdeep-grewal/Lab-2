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
		CCourse(vector<CStudent> students);

		void addStudent(CStudent student);
		void editStudent(CStudent student);
		void printStudent();
		void deleteStudent();
		void saveStudent();

		vector<CStudent> students;
};
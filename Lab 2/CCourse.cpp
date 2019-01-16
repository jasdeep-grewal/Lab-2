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

CCourse::CCourse(vector<CStudent> students)
{
	CCourse::students = students;
}

void CCourse::addStudent(CStudent student) {
	students.push_back(student);
}

void CCourse::editStudent(CStudent student) {
	int edit;
	cout << "\nStudent to edit: ";
	cin >> edit;
	cout << endl;

	while (cin.fail()) // got fromhttps://cboard.cprogramming.com/cplusplus-programming/11365-how-do-you-check-see-if-input-int.html
	{
		cin.clear();
		cin.ignore();
		cout << "Not a valid entry! Please re-enter.\n\nStudent to edit: ";
		cin >> edit;
		cout << endl;
	}
	if ((edit > 0) && (edit <= students.size()))
	{
		if (getStudentInfo(student))
			students[edit - 1] = student;
	}
	else
	{
		cout << "Student does not exist!\n";
	}

}

void CCourse::printStudent() {

	cout << "\n#" << setw(13);
	cout << "Student" << setw(11);
	cout << "Lab" << setw(8);
	cout << "Quiz" << setw(11);
	cout << "Midterm" << setw(18);
	cout << "Final Exam" << setw(15);
	cout << "Final Grade" << endl;

	for (int i = 0; i < students.size(); i++) {
		cout << i + 1 << setw(15);
		cout << students[i].student_number << setw(10);
		cout << fixed << setprecision(1) << students[i].lab << setw(7);
		cout << fixed << setprecision(1) << students[i].quiz << setw(8);
		cout << fixed << setprecision(1) << students[i].midterm << setw(15);
		cout << fixed << setprecision(1) << students[i].final_exam << setw(15);

		double finalGrade;
		finalGrade = (students[i].lab)*0.4 + (students[i].quiz)*0.1 + (students[i].midterm)*0.2 + (students[i].final_exam)*0.3;

		cout << fixed << setprecision(2) << finalGrade << endl;
	}
}
void CCourse::deleteStudent() {
	cout << "\nChoose a student to delete: ";
	int del;
	cin >> del;
	students.erase(students.begin() + del - 1);
}
void CCourse::saveStudent() {
	cout << "\nName of save file: ";
	//ofstream output_file("4618.txt");
	//ostream_iterator < CStudent > output_iterator(output_file, "\n");
	//copy(students.begin(), students.end(), output_iterator);
}

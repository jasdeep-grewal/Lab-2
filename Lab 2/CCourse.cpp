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

/*CCourse::CCourse(vector<CStudent> students)
{
	CCourse::students = students;
}*/

void CCourse::setvector(vector<CStudent> nstudents) {
	students = nstudents;
}
vector <CStudent> CCourse::getStudents() {
	return students;
}

void CCourse::addStudent() {
	CStudent student;
	if(getStudentInfo(student))
		students.push_back(student);
}

void CCourse::editStudent() {
	int edit;
	CStudent student;
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
		cout << students[i].getstudent_number() << setw(10);
		cout << fixed << setprecision(1) << students[i].getlab() << setw(7);
		cout << fixed << setprecision(1) << students[i].getquiz() << setw(8);
		cout << fixed << setprecision(1) << students[i].getmidterm() << setw(15);
		cout << fixed << setprecision(1) << students[i].getfinal_exam() << setw(15);

		double finalGrade;
		finalGrade = (students[i].getlab())*0.4 + (students[i].getquiz())*0.1 + (students[i].getmidterm())*0.2 + (students[i].getfinal_exam())*0.3;

		cout << fixed << setprecision(2) << finalGrade << endl;
	}
}
void CCourse::deleteStudent() {
	cout << "\nChoose a student to delete: ";
	int del;
	cin >> del;
	while (cin.fail()) // got fromhttps://cboard.cprogramming.com/cplusplus-programming/11365-how-do-you-check-see-if-input-int.html
	{
		cin.clear();
		cin.ignore();
		cout << "\nNot a valid entry! Please re-enter.\n\nChoose a student to delete: ";
		cin >> del;
		cout << endl;
	}
	if ((del > 0) && (del <= students.size())) {
		students.erase(students.begin() + del - 1);
	}
	else {
		cout << "\nStudent does not exist!\n";
	}
}

void CCourse::saveStudent() {
	cout << "\nName of save file: ";
	string saveName;
	cin >> saveName;
	ofstream outfile(saveName);
	for (int i = 0; i < students.size(); i++) {
		outfile << this->students[i].getstudent_number() << " " << this->students[i].getlab() << " ";
		outfile << this->students[i].getquiz() << " " << this->students[i].getmidterm() << " ";
		outfile << this->students[i].getfinal_exam() << "\n";
}

	outfile.close();

}

bool CCourse::getStudentInfo(CStudent &student) {
	string studentNum;
	cout << "Student Number: ";

	cin >> studentNum;

	if (toupper(studentNum.at(0)) != 'A') {
		cout << "\nInvalid Student Number" << endl;
		return false;
	}
	else if (studentNum.size() != 9) {
		cout << "\nInvalid Student Number" << endl;
		return false;
	}
	else if (!((studentNum.substr(1, 2) == "00") || (studentNum.substr(1, 2) == "01"))) {
		cout << "\nInvalid Student Number" << endl;
		return false;
	}
	for (int x = 3; x < studentNum.size(); x++) {
		if (!(isdigit(studentNum[x])))
		{
			cout << "\nInvalid Student Number" << endl;
			return false;
		}
	}
	studentNum.at(0) = toupper(studentNum.at(0));

	float labMark;
	cout << "Lab Grade: ";
	cin >> labMark;

	float quizMark;
	cout << "Quiz Grade: ";
	cin >> quizMark;

	float midtermMark;
	cout << "Midterm Grade: ";
	cin >> midtermMark;

	float final_examMark;
	cout << "Final Exam Grade: ";
	cin >> final_examMark;

	if ((labMark < 0) || (quizMark < 0) || (midtermMark < 0) || (final_examMark < 0) || (labMark > 100) || (quizMark > 100) || (midtermMark > 100) || (final_examMark > 100)) {
		cout << "\nEntered values are incorrect!";
		return false;
	}

	student.setstudent_number(studentNum);
	student.setlab(labMark);
	student.setquiz(quizMark);
	student.setmidterm(midtermMark);
	student.setfinal_exam(final_examMark);

	return true;
}

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
		outfile << this->students[i].getstudent_number() << "," << this->students[i].getlab() << ",";
		outfile << this->students[i].getquiz() << "," << this->students[i].getmidterm() << ",";
		outfile << this->students[i].getfinal_exam() << "\n";
}
	cout << "\nFile saved!\n";
	outfile.close();
}

void CCourse::loadStudent() {
	cout << "\nName of load file: ";
	string fileName;
	string data;
	cin >> fileName;
	ifstream infile(fileName);

	CStudent student;
	
	if (infile.is_open())
	{
		while (getline(infile, data))
		{
			student.setstudent_number(data.substr(0, data.find(",")));

			data.erase(0, data.find(",") + 1);

			student.setlab(stof(data.substr(0, data.find(","))));

			data.erase(0, data.find(",") + 1);

			student.setquiz(stof(data.substr(0, data.find(","))));

			data.erase(0, data.find(",") + 1);

			student.setmidterm(stof(data.substr(0, data.find(","))));

			data.erase(0, data.find(",") + 1);

			student.setfinal_exam(stof(data));

			students.push_back(student);
		}
	}
	
	cout << "\nFile loaded!\n";
	infile.close();
}

bool CCourse::getStudentInfo(CStudent &student) {
	string studentNum;
	cout << "Student Number: ";

	cin.clear();
	cin.ignore();

	//cin >> studentNum;
	getline(cin, studentNum, '\n');
	studentNum = trim(studentNum);

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
	student.setstudent_number(studentNum);

	float labMark = getValidFloat("Lab Grade", 0, 100);
	student.setlab(labMark);

	float quizMark = getValidFloat("Quiz Grade", 0, 100);
	student.setquiz(quizMark);

	float midtermMark = getValidFloat("Midterm Grade", 0, 100);
	student.setmidterm(midtermMark);

	float final_examMark = getValidFloat("Final Exam Grade", 0, 100);
	student.setfinal_exam(final_examMark);
	
	return true;
}
bool CCourse::isFloat(string number)
{
	int decCount = 0;

	// check if string is blank
	if (number == "")
		return false;

	// check if string is contains any chanrater other than "0123456789."
	for (int i = 0; i < number.size(); i++)
	{
		if (!(isdigit(number[i]) || number[i] == '.'))
			return false;

		if (number[i] == '.')
			decCount++;
	}

	// check if decimal pointed more tha once
	if (decCount > 1)
		return false;

	// else must be valid float
	return true;
}

string CCourse::trim(string myString)
{
	// if blank string return as is
	if (myString == "")
		return myString;

	//Trim leading spaces
	while (myString.at(0) == ' ') {
		myString.erase(0, 1);
	}

	//Trim trailing spaces
	while (myString.at(myString.size() - 1) == ' ') {
		myString.erase((myString.size() - 1), 1);
	}

	return myString;
}

float CCourse::getValidFloat(string inputDescription, float min, float max)
{
	float marks;
	string number;

	bool success = true;

	do {
		cout << inputDescription << ": ";
		getline(cin, number, '\n');
		number = trim(number);

		if (!isFloat(number))
		{
			cout << "\nError! Invalid input \n\n";
			success = false;
		}
		else
		{
			marks = stof(number);
			if (marks < min || marks > max) {
				cout << "\nError! Out of Range input \n\n";
				success = false;
			}
			else
				success = true;
		}

	} while (!success);

	return marks;
}
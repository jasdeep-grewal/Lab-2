// Lab 1.cpp : Defines the entry point for the console application.
//
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

void printMenu(CCourse &myClass);



//vector <CStudent> students;
//CCourse students();

int main()
{
	CCourse myClass;
	while (1) 
	{
		printMenu(myClass);		
	}
}

void printMenu(CCourse &myClass) {
	CCourse students();

	cout << "\n****************************************" << endl << endl;
	cout << "ELEX4618 Grade System, by STUDENT NAME" << endl << endl;
	cout << "****************************************" << endl << endl;
	cout << "(A)dd student" << endl << endl;
	cout << "(E)dit student" << endl << endl;
	cout << "(D)elete student" << endl << endl;
	cout << "(P)rint grades" << endl << endl;
	cout << "(S)ave class" << endl << endl;
	cout << "(L)oad class" << endl << endl;
	cout << "(Q)uit" << endl << endl;

	char check;
	cout << "CMD> ";
	cin >> check;
	
	switch (toupper(check)) {
	case 'A':
		cout << "\nAdding Student" << endl << endl;
		myClass.addStudent();
		break;
	case 'E':
		myClass.editStudent();
		break;
	case 'D':
		myClass.deleteStudent();
		break;
	case 'P':
		myClass.printStudent();
		break;
	case 'S':
		myClass.saveStudent();
		break;
	case 'L':
		myClass.loadStudent();
		break;
	case 'Q':
		exit(0);
	}



	/*if ((check == 'a') || (check == 'A')) {
		//if max count > 100 dont do it
		cout << "\nAdding Student" << endl << endl;
		students.addStudent();
	}
	else if ((check == 'e') || (check == 'E')) {
		students.editStudent();
	}
	else if ((check == 'd') || (check == 'D')) {
		function.deleteStudent();
	}
	else if ((check == 'p') || (check == 'P')) {
		function.printStudent();
	}
	else if ((check == 's') || (check == 'S')) {
		function.saveStudent();
	}
	else if ((check == 'q') || (check == 'Q')) {
		exit(0);
	}
	else {
		cout << "\nError" << endl;
	}*/
}




/*
void CCourse::addStudent() {
	CStudent student;
	if (getStudentInfo(student))
		students.push_back(student);
}

void CCourse::editStudent() {
	CStudent student;

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
bool getStudentInfo(CStudent &student){
	cout << "Student Number: ";
	cin >> student.student_number;
	if (!((student.student_number.substr(0, 1) == "A") || (student.student_number.substr(0, 1) == "a"))) {
		cout << "\nInavlid Student Number" << endl;
		return false;
	}
	else if ((student.student_number.size() < 9) || (student.student_number.size() > 9)) {
		cout << "\nInavlid Student Number" << endl;
		return false;
	}
	else if (!((student.student_number.substr(1, 2) == "00") || (student.student_number.substr(1, 2) == "01"))) {
		cout << "\nInavlid Student Number" << endl;
		return false;
	}
	student.student_number.at(0) = toupper(student.student_number.at(0));
	cout << "Lab Grade: ";
	cin >> student.lab;
	cout << "Quiz Grade: ";
	cin >> student.quiz;
	cout << "Midterm Grade: ";
	cin >> student.midterm;
	cout << "Final Exam Grade: ";
	cin >> student.final_exam;
	if ((student.lab < 0) || (student.quiz < 0) || (student.midterm <0) || (student.final_exam < 0) || (student.lab > 100) || (student.quiz > 100) || (student.midterm > 100) || (student.final_exam > 100)) {
		cout << "\nEntered values are incorrect!";
		return false;
	}
	else
	return true;
}
*/
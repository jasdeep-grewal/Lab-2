#include "stdafx.h"
#include "CStudent.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
using namespace std;


void CStudent::setstudent_number(string nstudent_number) {
	student_number = nstudent_number;
}
string CStudent::getstudent_number() {
	return student_number;
}


void CStudent::setlab(float nlab) {
	lab = nlab;
}
float CStudent::getlab() {
	return lab;
}


void CStudent::setquiz(float nquiz) {
	quiz = nquiz;
}
float CStudent::getquiz() {
	return quiz;
}


void CStudent::setmidterm(float nmidterm) {
	midterm = nmidterm;
}
float CStudent::getmidterm() {
	return midterm;
}


void CStudent::setfinal_exam(float nfinal_exam) {
	final_exam = nfinal_exam;
}
float CStudent::getfinal_exam() {
	return final_exam;
};



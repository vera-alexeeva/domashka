#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

//Задача 1
//переменные типа String: firstName, lastName, group. А также, переменную типа double - averageMark, содержащую среднюю оценку;

class Student{
private:
	string firstName, lastName, group;
protected:
	double averageMark;
public:
	Student() { };
	Student(string firstName, double averageMark){
		this->firstName = firstName;
		this->averageMark = averageMark;
	}
	
	int getScholarship(){
		if(round(this->averageMark)==5) return 100;
		else return 80;
	}
};

//класс Aspirant, аспирант отличается от студента наличием некой научной работы,
//в классе Aspirant: если средняя оценка аспиранта равна 5, то сумма 200$, иначе 180$

class Aspirant : public Student {
private:
	string decertation;
public:
	Aspirant(string firstName, double averageMark) : Student(firstName, averageMark) {}
	int getScholarship(){
		if (round(this->averageMark)==5) return 200;
		else return 180;
	}
};

//-------------------------------------------------------------

//Задача 2

class Book{
protected:
	string author;
public:
	Book(string author){
		this->author = author;
	}
	virtual Book* getBook() = 0;
	virtual string getTitle() = 0;
	string toString() {
		return author + ' ' +  this->getTitle();
	}	
};

class MarkTwainBook : public Book{
private:
	string title;
public:
	MarkTwainBook(string title): Book("Mark Twain") {
		this->title = title;
	}
	string getTitle(){
		return this->title;
	}
	MarkTwainBook* getBook() {
		return this;
	}
};

class AgathaChristieBook : public Book{
private:
	string title;
public:
	AgathaChristieBook(string title): Book("Agatha Christie") {
		this->title = title;
	}
	
	string getTitle(){
		return this->title;
	}
	AgathaChristieBook* getBook() {
		return this;
	}
};

int main(){
	
	Aspirant Sasha("Sasha", 3.67), Anna("Anna", 4.76);
	Student* Vera = &Sasha;
	Student Nikolai("Nikolai", 3.47);
	
	vector<Student> group(3);
	group[0] = Anna;
	group[1] = Nikolai;
	group[2] = Sasha;

	
//-------------------------------------------------------------
	
	MarkTwainBook TomSawyer("The Adventures of Tom Sawyer");
	cout << TomSawyer.getBook()->toString() << endl;
	AgathaChristieBook OrientExpress("Murder on the Orient Express");
	cout << OrientExpress.toString() << endl;
	
	return 0;
}

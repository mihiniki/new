#pragma once
#include<cstring>
#include<fstream>
class Book {
private:
	char* autor;
	char* title;
	char* fileName;
	char* resume;
	unsigned rate;
	unsigned ibn;
	void copy(const char* autor, const char* title, const char* fileName, const char* resume, unsigned rate, unsigned ibn);
	void clear();
public:
	Book();

	Book(const char* autor, const char* title, const char* fileName, const char* resume, unsigned rate, unsigned ibn);
	Book& operator=(Book const& other);
	Book(Book const& other);
	~Book();
	char* getAutor() const;
	char* getTitle() const;
	char* getFileName() const;
	char* getResume() const;
	unsigned getRate() const;
	unsigned getIbn() const;
	friend std::ostream& operator<<(std::ostream& os, const Book& obj);
	//friend std::istream& operator>>(std::istream& is, Book& obj);
	void writeToTextFileB(const char* fileName) const;
	char* takeNameFrTextFile(const char* fileName, int place);
	char* takeAutorFrTextFile(const char* fileName, int place);
	unsigned takeRateFrTextFile(const char* fileName, int place);
	void writeDscrToTextFile(const char* fileName, int numbSymb) const;
	void readDscrFrTextFileLines(const char* fileName, int number);
	void readDscrFrTextFileSent(const char* fileName, int number);
	void deleteFile(const char* fileName);
	//void serailize()
};
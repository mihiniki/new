#pragma once
#include"Book.h"
class Library {
private:
	Book** books;
	unsigned capacity;
	unsigned currCt;
	void clear();
	void copy( Book** books, unsigned capacity, unsigned currCt);
	void resize();
public:
	Library();
	Library( Book**  books, unsigned capacity, unsigned currCt);
	Library& operator=(Library const& other);
	Library(Library const& other);
	~Library();
	unsigned getCap() const;
	void setCap(unsigned cap) {
		capacity = cap;
	}
	unsigned getCt() const;
	void setCt(unsigned ct) {
		currCt = ct;
	}
	void sortByAutorUp(const char* fileName);
	void sortByAutorDown(const char* fileName);
	void sortByTitleUp(const char* fileName);
	void sortByTitleDown(const char* fileName);
	void sortByRateUp(const char* fileName);
	void sortByRateDown(const char* fileName);

	void findTheBookByTitle(const char* searchedTitle);
	void findTheBookByAutor(const char* searchedAutor);
	void findTheBookByIbn(unsigned ibn);
	void findTheBookByDescriptiion(const char* searchedDescr);

	bool isThisPartFrDscr(const char* text, int index);

	void printArr();
	void addBook(const char* autor, const char* title, const char* fileName, const char* resume, unsigned rate, unsigned ibn, const char* bigFile);
	void deleteBook(const char* Title, const char* fileName);

	void writeToTextFile(const char* fileName) const;
	bool isTheSameLetter(const char symb,const char othSymb)const;
	bool areTheStrigsEqaul(const char* str1, const char* str2) const;
	void saveBooksInFiles(int numbSymb);
	void readBooksLines(int n);
	void readBookSent(int n);
	//void sortUp();
};

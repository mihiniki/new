#include"Library.h"
#include<iostream>
const int capDefSize = 5;
Library::Library() : capacity(capDefSize),books(new Book*[capDefSize]), currCt(0) {
	for (int i = 0; i < capacity; i++) {
		books[i] = nullptr;
	}
}
Library::Library( Book** books, unsigned capacity, unsigned currCt) {
	copy(books, capacity, currCt);
}
Library& Library::operator=( const Library& other) {
	if (this != &other) {
		clear();
		copy(other.books, other.capacity, other.currCt);
	}
	return *this;
}
Library::Library(Library const& other) {
	copy(other.books, other.capacity, other.currCt);
}
Library::~Library() {
	clear();
}
void Library::clear() {
	
	for (int i = 0; i < currCt; i++) {
		
		delete books[i];
		//books[i] = nullptr;
	}
	delete[]books;
	//books = nullptr;
	
}
void Library::copy( Book** books, unsigned capacity, unsigned currCt) {
	this->capacity = capacity;
	this->currCt = currCt;

	this->books = new Book * [capacity];
	for (int i = 0; i < capacity; i++) {
		if (books[i] != nullptr) {
			this->books[i] = new Book(*books[i]);
		}
		else {
			this->books[i] = nullptr;
		}
		
	}
	
}
void Library::sortByAutorUp(const char* fileName) {
	
	char arr[100][100];
	for(int i=0;i<currCt;i++){
		int j = 0;
		for(j=0;j<strlen(books[i]->takeAutorFrTextFile(fileName,i))+1;j++){
			arr[i][j] = books[i]->takeAutorFrTextFile(fileName, i)[j];
		}
		arr[i][j] = '\0';
	}
	
	for (int i = 0; i < currCt; i++) {
		int min = i;
		for (int j = i + 1; j < currCt; j++) {
			if (strcmp(arr[j], arr[min]) < 0) {
				min = j;
			}
		}
		if (min != i) {
			Book* temp = books[i];
			books[i] = books[min];
			books[min] = temp;
			char* temp1 = new char[strlen(arr[min]) + strlen(arr[i])];
			strcpy(temp1, arr[min]);
			strcpy(arr[min], arr[i]);
			strcpy(arr[i], temp1);
			delete[]temp1;
		}
	}
	printArr();
}

void Library::sortByAutorDown(const char* fileName) {
	char arr[10][10];
	for (int i = 0; i < currCt; i++) {
		int j = 0;
		for (j = 0; j < strlen(books[i]->takeAutorFrTextFile(fileName, i)) + 1; j++) {
			arr[i][j] = books[i]->takeAutorFrTextFile(fileName, i)[j];
		}
		arr[i][j] = '\0';
	}
	for (int i = 0; i < currCt; i++) {
		std::cout << arr[i] << std::endl;
	}
	for (int i = 0; i < currCt; i++) {
		int max = i;
		for (int j = i + 1; j < currCt; j++) {
			if (strcmp(arr[j], arr[max]) > 0) {
			//	std::cout << arr[max] << " " << arr[j] << std::endl;
				max = j;
			}
		}
		if (max != i) {
			Book* temp = books[i];
			books[i] = books[max];
			books[max] = temp;
			char* temp1 = new char[strlen(arr[max]) + strlen(arr[i])];
			strcpy(temp1, arr[max]);
			strcpy(arr[max],arr[i]);
			strcpy(arr[i],temp1);
			
			delete[]temp1;
		}
	}
	printArr();
}

void Library::sortByTitleUp(const char* fileName) {
	char arr[100][100];
	for (int i = 0; i < currCt; i++) {
		int j = 0;
		for (j = 0; j < strlen(books[i]->takeNameFrTextFile(fileName, i)) + 1; j++) {
			arr[i][j] = books[i]->takeNameFrTextFile(fileName, i)[j];
		}
		arr[i][j] = '\0';
	}
	for (int i = 0; i < currCt; i++) {
		int min = i;
		for (int j = i + 1; j < currCt; j++) {
			if (strcmp(arr[j],arr[min]) < 0) {
				min = j;
			}
		}
		if (min != i) {
			Book* temp = books[i];
			books[i] = books[min];
			books[min] = temp;
			char* temp1 = new char[strlen(arr[min]) + strlen(arr[i])];
			strcpy(temp1, arr[min]);
			strcpy(arr[min], arr[i]);
			strcpy(arr[i], temp1);
			delete[]temp1;
		}
	}
	printArr();
}

void Library::sortByTitleDown(const char* fileName) {
	char arr[100][100];
	for (int i = 0; i < currCt; i++) {
		int j = 0;
		for (j = 0; j < strlen(books[i]->takeNameFrTextFile(fileName, i)) + 1; j++) {
			arr[i][j] = books[i]->takeNameFrTextFile(fileName, i)[j];
		}
		arr[i][j] = '\0';
	}
	for (int i = 0; i < currCt; i++) {
		int max = i;
		for (int j = i + 1; j < currCt; j++) {
			if (strcmp(arr[j],arr[i]) > 0) {
				max = j;
			}
		}
		if (max != i) {
			Book* temp = books[i];
			books[i] = books[max];
			books[max] = temp;
			char* temp1=new char[strlen(arr[max])+strlen(arr[i])];
			strcpy(temp1, arr[max]);
			strcpy(arr[max], arr[i]);
			strcpy(arr[i], temp1);
			delete[]temp1;
		}
	}
	printArr();
}

void Library::sortByRateUp(const char* fileName) {
	int arr[100];
	for (int i = 0; i < currCt; i++) {
		arr[i] = books[i]->takeRateFrTextFile(fileName, i);
	}
	for (int i = 0; i < currCt; i++) {
		int min = i;
		for (int j = i + 1; j < currCt; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		if (min != i) {
			Book* temp = books[i];
			books[i] = books[min];
			books[min] = temp;
			int temp1 = arr[min];
			arr[min] = arr[i];
			arr[i] = temp1;
		}
	}
	printArr();
}

void Library::sortByRateDown(const char* fileName) {
	int arr[100];
	for (int i = 0; i < currCt; i++) {
		arr[i] = books[i]->takeRateFrTextFile(fileName, i);
	}
	
	for (int i = 0; i <currCt; i++) {
		int max = i;
		for (int j = i + 1; j < currCt; j++) {
			if (arr[max]<arr[j]) {
				
				max = j;
			}
		}
		if (max != i) {
			Book *temp = books[i];
			books[i] = books[max];
			books[max] = temp;
			int temp1 = arr[max];
			arr[max] = arr[i];
			arr[i] = temp1;
		}
	}
	printArr();
}

void Library::printArr() {
	for (int i = 0; i < currCt; i++) {
		
		std::cout << i << *books[i]<<std::endl;
		
	}
}

void Library::findTheBookByTitle(const char* sTitle) {
	for (int i = 0; i < currCt; i++) {
		if (strcmp(sTitle, books[i]->getTitle()) == 0) {
			std::cout << *books[i];
			break;
		}
	}
}
void Library::findTheBookByAutor(const char* sAutor) {
	for (int i = 0; i < currCt; i++) {
		if (strcmp(sAutor, books[i]->getAutor())==0) {
			std::cout << *books[i];
			break;
		}
	}
}
void Library::findTheBookByIbn(unsigned sIbn) {
	for (int i = 0; i < currCt; i++) {
		if (sIbn == books[i]->getIbn()) {
			std::cout << *books[i];
			break;
		}
	}
}
bool Library::isTheSameLetter(const char symb, const char symb1) const{
	return (symb == symb1) || (symb==symb1-32) || (symb==symb1+32);
}
bool Library::areTheStrigsEqaul(const char* str1, const char* str2) const {
	if (strcmp(str1, str2) == 0) {
		return true;
	}
	if (strlen(str1) == strlen(str2)) {
		for (int i = 0; i < strlen(str1); i++) {
			if (!isTheSameLetter(str1[i], str2[i])) {
				return false;
			}
		}
	}
	return true;
}
bool Library::isThisPartFrDscr(const char* text, int index) {
	int size = strlen(books[index]->getResume()) + 1;
	for (int i = 0; i < size; i++) {
		
		if (isTheSameLetter(books[index]->getResume()[i], text[0]) ) {
			int size = i + strlen(text);
			if( isTheSameLetter(books[index]->getResume()[size-1] , text[strlen(text)-1])){
				
				
			int j = i + 1;
			int p = 0;
			for (j = i; j < size; j++, p++) {
				if (isTheSameLetter(books[index]->getResume()[j], text[p]) == false) {
					
					break;
				}
			}
			if (j == size) {
				return true;
			}
			}
			

		}
		
	}
	return false;
}
void Library::findTheBookByDescriptiion(const char* sDscr) {
	for (int i = 0; i < currCt; i++) {
		if (isThisPartFrDscr(sDscr, i)) {
			std::cout << *books[i];
			break;
		}
	}
}
void Library::addBook(const char* autor, const char* title, const char* fileName, const char* resume, unsigned rate, unsigned ibn, const char* bigFile) {
	
	if (capacity - currCt == 1) {
		resize();
	}
	
		books[currCt++] =new Book(autor, title, fileName, resume, rate, ibn);
		

	
}
unsigned Library::getCap() const {
	return capacity;
}
unsigned Library::getCt() const {
	return currCt;
}
void Library::deleteBook(const char* title, const char* fileName) {
	for (int i = 0; i < currCt; i++) {
		if (strcmp(books[i]->getTitle(), title) == 0) {
		
			books[i]->deleteFile(books[i]->getFileName());
			delete books[i];
			books[i] = nullptr;

		}
		for (int j = i; j < currCt; j++) {
			books[j] = books[j + 1];
		}
		books[--currCt] = nullptr;
		break;
	}
	
	
	std::ofstream out;
	out.open(fileName, std::ios::trunc);
	out.close();
	writeToTextFile(fileName);
}
void Library::writeToTextFile(const char* fileName) const {

	for (int i = 0; i < currCt; i++) {

		books[i]->writeToTextFileB(fileName);
		
	}
}
void Library::saveBooksInFiles(int numbSymb) {
	for (int i = 0; i < currCt; i++) {
		books[i]->writeDscrToTextFile(books[i]->getFileName(), numbSymb);
	}
}
void Library::readBooksLines(int n) {
	for (int i = 0; i < currCt; i++) {
		books[i]->readDscrFrTextFileLines(books[i]->getFileName(),n);
	}
}
void Library::readBookSent(int n) {
	for (int i = 0; i < currCt; i++) {
		books[i]->readDscrFrTextFileSent(books[i]->getFileName(), n);
	}
}
void Library::resize() {
	Book** buffer = new Book*[capacity*2];
	for (int i = 0; i < capacity; i++) {
		
		buffer[i] = books[i];
	}
	capacity *= 2;
	delete[]books;
	
	books = buffer;
	
}
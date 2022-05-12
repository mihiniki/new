#include"Book.h"
#include<iostream>
const int LEN = 1;
Book::Book() :autor(new char[LEN]), title(new char[LEN]), fileName(new char[LEN]), resume(new char[LEN]), rate(0), ibn(0) {
	autor[0] = '\0';
	title[0] = '\0';
	fileName[0] = '\0';
	resume[0] = '\0';
}
Book::Book(const char* autor, const char* title, const char* file, const char* resum, unsigned rate, unsigned ibn) {
	copy(autor, title, file, resum, rate, ibn);
}
Book::~Book() {
	clear();
}
Book& Book::operator=(Book const& other) {
	if (this != &other) {
		clear();
		//other.autor
		copy(other.autor, other.title, other.fileName, other.resume, other.rate, other.ibn);
	}
	return *this;
}
Book::Book(Book const& other) {
	copy(other.autor, other.title, other.fileName, other.resume, other.rate, other.ibn);
}
void Book::clear() {
	//std::cout << "clear()";
	delete[]autor;
	autor = nullptr;

	delete[]title;
	title = nullptr;

	delete[]fileName;
	fileName = nullptr;

	delete[]resume;
	resume = nullptr;
}
void Book::copy(const char* autor, const char* title, const char* fileName, const char* resume, unsigned rate, unsigned ibn) {
	unsigned size = strlen(autor) + 1;
	this->autor = new char[size];
	strcpy(this->autor, autor);

	size = strlen(title) + 1;
	this->title = new char[size];
	strcpy(this->title, title);

	unsigned size1 = strlen(fileName) + 1;
	this->fileName = new char[size1];
	strcpy(this->fileName, fileName);

	size1 = strlen(resume) + 1;
	this->resume = new char[size1];
	strcpy(this->resume, resume);

	this->rate = rate;
	this->ibn = ibn;
}
char* Book::getAutor() const {
	return autor;
}
char* Book::getFileName() const {
	return fileName;
}
char* Book::getTitle() const {
	return title;
}
char* Book::getResume() const {
	return resume;
}
unsigned Book::getIbn() const {
	return ibn;
}
unsigned Book::getRate() const {
	return rate;
}

std::ostream& operator<<(std::ostream& os, const Book& obj) {
	os << obj.autor << '/' << obj.title << '/' << obj.fileName << '/' << obj.resume << '/' << obj.rate << '/' << obj.ibn;
	return os;
}
/*std::istream& operator>>(std::istream& is, Book& obj) {
	obj.clear();
	char buffer[4024];
	is.getline(buffer, 4024);

	obj.autor = new char[strlen(buffer) + 1];
	strcpy(obj.autor, buffer);

	obj.title = new char[strlen(buffer) + 1];
	strcpy(obj.title, buffer);

	obj.fileName = new char[strlen(buffer) + 1];
	strcpy(obj.fileName, buffer);

	obj.resume = new char[strlen(buffer) + 1];
	strcpy(obj.resume, buffer);

	is >> obj.rate;
	is >> obj.ibn;
}*/
void Book::writeToTextFileB(const char* fileName) const {
	std::ofstream out(fileName, std::ios::app);
	if (!out) {
		return;
	}

	out << *this <<'+';
	out.close();
}
char* Book::takeAutorFrTextFile(const char* fileName, int place) {
	char* autor;
	std::ifstream in(fileName);

	if (!in) {
		return 0;
	}

	char buffer[1024];
	in.getline(buffer, 1024);
	//std::cout << buffer;
	int p = 0;
	int br = 0;
	autor = new char[strlen(buffer)];
	//std::cout << buffer;
	int size= strlen(buffer);
	for (int i = 0; i < size; i++) {
		if (buffer[i] == '+') {
			br++;
		}
		if (br == place) {
			int j = i + 1;
			if (place == 0) {
				j = i;
			}
			while (buffer[j] != '/') {
				autor[p++] = buffer[j++];
				//std::cout << autor[p++];
				//cout << "1";
			}
			//std::cout << autor[p-1]<<std::endl;
			//std::cout << p;
			autor[p] = '\0';
			//std::cout << autor<<std::endl;
			break;
		}
	}
	in.close();
	//std::cout<<autor;
	return autor;
}
char* Book::takeNameFrTextFile(const char* fileName, int place) {
	char* name;
	std::ifstream in(fileName);
	if (!in) {
		return 0;
	}
	char buffer[1024];
	in.getline(buffer, 1024);
	//std::cout << buffer;
	//std::cout <<"ff"<< buffer;
	int br = 0;
	//int size = 0;
	name = new char[strlen(buffer)+1];
	int p = 0;
	int brRazd = 0;
	//std::cout << buffer;
	int size = strlen(buffer) + 1;
	for (int i = 0; i < size; i++) {
		if (buffer[i] == '+') {
			brRazd++;
			//std::cout << i;
		}
		if (brRazd == place) {
			for (int j = i; j < size; j++) {
				if (buffer[j] == '/') {
					//std::cout << "tuk stawa 1";
					//std::cout << j;
					br++;
				}
				if (br == 1) {
					//std::cout << i;
					//i++;
					j++;
					while (buffer[j] != '/') {
						//std::cout << buffer[i] << " ";
						name[p++] = buffer[j++];
					}
					name[p] = '\0';
					break;
				}
			}
			
		}
		if (br == 1) {
			break;
		}
	}
	
	in.close();
	//std::cout << name;
	return name;
}
unsigned Book::takeRateFrTextFile(const char* fileName,int place) {
	unsigned rate = 0;
	std::ifstream in(fileName);

	if (!in) {
		return 0;
	}

	char buffer[1024];
	in.getline(buffer, 1024);
	int br = 0;
	char rateChar[10];
	int rInd = 0;
	int brRazd = 0;
	int size = strlen(buffer) + 1;
	//std::cout << buffer;
	for (int i = 0; i < size; i++) {
		if (buffer[i] == '+') {
			brRazd++;
			//std::cout << i;
		}
		if (brRazd == place) {
		//	std::cout <<"i "<< i << std::endl;
			for (int j = i; j < size; j++) {
				if (buffer[j] == '/') {
					br++;
				}
				if (br == 4) {
					j++;
					while (buffer[j] != '/') {
						rateChar[rInd++] = buffer[j++];
					}
					rateChar[rInd] = '\0';
					//std::cout << rateChar;
					break;
				}
			}
		}
		if (br == 4) {
			break;
		}
	}
	rate = atoi(rateChar);
	in.close();
	return rate;
}
void Book::writeDscrToTextFile(const char* fileName, int numbSymb) const {
	std::ofstream out(fileName, std::ios::app);
	if (!out) {
		return;
	}
	char buffer[1024];
	char text[4024];
	std::cin.getline(buffer, 1024);
	strcpy(text, buffer);
	int size = strlen(buffer);
	while (true) {
		//std::cout << size;
		std::cin.getline(buffer, 1024);
		strcat(text, buffer);
		size += strlen(buffer);
		if (size > numbSymb) {
			break;
		}
	}

	out << text;

	out.close();
}
void Book::readDscrFrTextFileLines(const char* fileName, int numb) {
	std::ifstream in(fileName);

	if (!in) {
		return ;
	}
	int count = 0;
	
		while (true) {
			char buffer[1024];
			in.getline(buffer, 1024);
			std::cout << buffer;
			count++;
			if (count == numb || in.eof()) {
				break;
			}
		}
	
	in.close();
}
void Book::readDscrFrTextFileSent(const char* fileName, int numb) {
	std::ifstream in(fileName);

	if (!in) {
		return;
	}
	int count = 0;

	while (true) {
		char buffer[1024];
		in.getline(buffer, 1024);
		
		for (int i = 0; i < strlen(buffer) + 1; i++) {
			std::cout << buffer[i];
			if (buffer[i] == '.') {
				count++;
			}
			if (count == numb) {
				break;
			}
		}
		
		if (count == numb || in.eof()) {
			break;
		}
	}

	in.close();
}
void Book::deleteFile(const char* fileName) {
	int status;
	status = remove(fileName);
}
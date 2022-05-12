#include"Book.h"
#include"Library.h"
#include<iostream>

int main() {
	const char* password = "WdHuRT768K.jdso&";
	int numberOfOperations;
	//1- dobavq kniga
	//2- trie kniga
	
	std::cin >> numberOfOperations;
	if (numberOfOperations == 1 || numberOfOperations == 2) {

		//std::cout << "a";
		char userPass[100];
		//std::cin >> userPass;
		std::cin.get();
		std::cin.getline(userPass, 100);
		if (strcmp(userPass, password) == 0) {
			//call one of the functions
		}
	}
	Book firstBook("martin", "kniga za kotkite", "file10.txt", "imalo edno vreme edna kotka", 5, 10);
	firstBook.writeToTextFileB("filename5.txt");
	
	//std::cout << std::endl;
	//std::cout << firstBook.takeRateFrTextFile("filename3.txt")<<std::endl;
	Book secBook("maxi", "kniga za kuchetata", "file.txt", "imalo edno vreme edno kuche", 3, 12);
	Book thBook("munco", "kniga za kucheta", "file.txt", "imalo edno vreme  kuche", 1, 12);
	secBook.writeToTextFileB("filename5.txt");
	thBook.writeToTextFileB("filename5.txt");
	std::cout << firstBook.takeAutorFrTextFile("filename5.txt", 2);
	std::cout << std::endl;
	std::cout << firstBook.takeNameFrTextFile("filename5.txt", 2);
	std::cout << std::endl;
	std::cout << firstBook.takeNameFrTextFile("filename5.txt", 0);
	std::cout << std::endl;
	std::cout << firstBook.takeNameFrTextFile("filename5.txt", 1);
	std::cout << std::endl;
	std::cout << firstBook.takeAutorFrTextFile("filename5.txt", 0);
	std::cout << std::endl;
	std::cout << firstBook.takeAutorFrTextFile("filename5.txt", 1);
	std::cout << std::endl;
	std::cout << firstBook.takeRateFrTextFile("filename5.txt",1)<<std::endl;
	std::cout << firstBook.takeRateFrTextFile("filename5.txt", 2) << std::endl;
	std::cout << firstBook.takeRateFrTextFile("filename5.txt", 0) << std::endl;
	//firstBook.writeDscrToTextFile("filename8.txt");
	//firstBook.writeDscrToTextFile(firstBook.getFileName());
	firstBook.readDscrFrTextFileLines(firstBook.getFileName(), 2);
	std::cout << std::endl;
	firstBook.readDscrFrTextFileSent(firstBook.getFileName(), 7);
	//firstBook.deleteFile(firstBook.getFileName());
	Library books;
	
	books.addBook("martin", "kniga za kotkite", "file.txt", "imalo edno vreme edna kotka", 8, 10, "file.txt");
	
	books.addBook("tanya", "kniga za konete", "file.txt", "imalo edno malko kuche", 22, 10, "file.txt");
	
	books.addBook("toncho", "kniga za ", "file.txt", "nqma nishto imalo", 10, 12, "file.txt");
	
	books.addBook("timcho", "kniga za ", "file.txt", "imalo edno vreme edna Tanya", 9, 15, "file.txt");
	books.addBook("timkkcho", "kniga za gushteriiii ", "file.txt", "imalo edno vreme edno kozle", 10, 20, "file.txt");
	books.addBook("Dimityr dimov", "Tyutyun", "file.txt", "ttyutyun", 10, 20, "file.txt");
	//std::cout << books.getCt()<<std::endl;
//	books.printArr();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
//	books.printArr();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	books.findTheBookByAutor("timkkcho");
	std::cout<< std::endl;
	books.writeToTextFile("filename6.txt");
	
	std::cout << std::endl;
	//std::cout<<books.
	books.printArr();
	std::cout<<books.isThisPartFrDscr("Kozle", 4);
	std::cout << std::endl;
	//books.sortByRateDown("filename6.txt");
	//books.printArr();
	books.sortByRateUp("filename6.txt");
	//books.sortByTitleDown("filename6.txt");
	 if (strcmp("kniga za konete", "kniga za ") > 0) {
		 std::cout << "a";
	}
	 books.findTheBookByDescriptiion("Kozle");
	 //books.deleteBook("kniga za kotkite", "filename6.txt");
	//std::cout << firstBook;
	//books.deleteBook("kniga za konete");
	//std::cout <<"GETTTTTETR"<< firstBook.getFileName();
	
	
	
	return 0;
}

// Task_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

void set() {
	system("cls");
	std::string path;
	std::string second_path;
	std::string combo;
	std::cout << "Enter the path to file. Path must be like C:\\n\\text.txt\n";
	std::cout << "Path: ";
	std::cin >> path;
	if (path == "") set();
	std::cout << "Enter path to enother folder. Path must be like C:\\n \n";
	std::cout << "Path: ";
	std::cin >> second_path;
	combo ="COPY "+ path +" "+ second_path;
	std::cout << combo<<"\n";
	int r= system(combo.data());
	if (r) {
		int a;
		std::cout << "\nYou entered wrong path, try again.\n Click 1 to continue: ";
		std::cin >> a;
		if(a==1)set();
		exit(0);
	}
	std::cout << "\nEverything was successful!\n";
	
}
int main()
{
	std::cout << "This program help you to copy some file from one to enother folder";
	set();
	system("pause");
    return 0;
}


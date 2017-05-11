// Planner.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>

void menu();
void set();
void get();


void set() {
	std::string date;
	char topic[30];
	char inf[300];
	std::ofstream file_date;
	std::ofstream file_topic;
	std::ofstream file_inf;
	file_date.open("date.txt", std::ios_base::app);
	file_topic.open("topic.txt", std::ios_base::app);
	file_inf.open("inf.txt", std::ios_base::app);
	if (!file_date.is_open()|| !file_topic.is_open()|| !file_inf.is_open()) {
		std::cout << "File with information doesn't exist.\n";
	}

	system("cls");
	std::cout << "\t\t\t\t  Your notes.\n";
	std::cout << "Today's date: ";
	std::cin >> date;
	std::cin.get();
	std::cout << "\n\tTopic for your note: ";
	std::cin.getline(topic,30);
	//std::cin.get();
	std::cout << "\nMain information: ";
	std::cin.getline(inf, 30);
	std::cin.get();
	
	file_date << date<<"\n";          //Write to file  date
	file_topic << topic << "\n";      //Write to file topic
	file_inf << inf << "\n";       //Write to file all inf

	file_date.close();             //Close file 
	file_topic.close();
	file_inf.close();
	std::cout << "\nDo you want to write something else? (y/n): ";
	char r;
	std::cin >> r;
	if (r == 'y') set();
	else menu();

	
}
	
void get() {
	std::string date;

	system("cls");
	std::cout << "write the date of note: ";
	std::cin >> date;
	std::ifstream file_date("date.txt");
	std::ifstream file_topic("topic.txt");
	std::ifstream file_inf("inf.txt");
	if (!file_date.is_open() || !file_topic.is_open() || !file_inf.is_open()) {
		std::cout << "File with information doesn't exist.\n";
	}
	std::string date_line, topic_line, inf_line;
	
	while (getline(file_date,date_line)&& getline(file_topic, topic_line) && getline(file_inf, inf_line)) {
	
		if (date_line == date) {
			std::cout << "\n\t\t\t " << topic_line<<"\n";
			std::cout << inf_line << "\n";
		}
	}

	file_date.close();             //Close file 
	file_topic.close();
	file_inf.close();
	
	std::cout << "\nDo you want to read something else? (y/n): ";
	char r;
	std::cin >> r;
	if (r == 'y') get();
	else menu();
	
}
void menu() {
	int res;
	system("cls");
	std::cout << "Dear user. This program is like your dairy, you can write everything here.\n\n";
	std::cout << "|---------------------------------------|\n";
	std::cout << "|1) Write something | 2) Read last notes|\n";
	std::cout << "|---------------------------------------|\n";
	std::cout << "Choose 1 or 2: ";
	std::cin >> res;
	switch (res)
	{
	case 1: set(); break;
	case 2: get(); break;
	}
}


int main()
{
	 menu();
	system("pause");
    return 0;
}


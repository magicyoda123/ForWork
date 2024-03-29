// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <string>
#include <iostream>
#include <filesystem>


int main()
{
	system("chcp 1251");	// Устанавливаем кодировку 1251
	namespace fs = std::filesystem;	// Объявляем файловую систему, с которой будем работать.
	fs::path ProgramDirectory = fs::current_path(); // Определеяем текущий путь, где располагается исполняемый файл
	ProgramDirectory += fs::path("\\logs"); // Добавляем к текущему пути адрес папки logs
	fs::path ProgramDirectoryGroupTest; // Тесты имеют иерархию и подразделяются на группы. Путь до группы теста
	fs::path TestDirectory; // Путь до конкретного теста
	std::cout << "Current path is " << ProgramDirectory << '\n'; // Вывод текущего пути.

	// цикл для каждой группы тестов в папке logs
	for (const auto & entryGroup : fs::directory_iterator(ProgramDirectory))
	{
		//std::cout << entryGroup.path() << std::endl; // В entry.path() храниться текущий путь из подкаталогов logs 
												// (Название папки группы тестов)
		ProgramDirectoryGroupTest += entryGroup.path(); // logs/TestGroupCURRENT
		
		for (const auto & entryTest : fs::directory_iterator(ProgramDirectoryGroupTest))
		{
			TestDirectory += entryTest.path(); // Путь до текущего теста
			std::cout << TestDirectory <<'\n'<< std::endl;
			TestDirectory.clear(); // стираем содержимое о текущем пути
		}
		ProgramDirectoryGroupTest.clear(); // стираем содержимое о текущем пути
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

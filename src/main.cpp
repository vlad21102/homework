#include "../header/List.h"
#include <clocale>
#include <iostream>

/**
* @brief Точка входа в программу
* @return Если программа выполнена корректно - 0, иначе 1
*/
int main()
{
	setlocale(LC_ALL, "Russian");

	List firstList = { 1, 2, 3, 4 };

	std::cout << "Исходный список: " << firstList.ToString() << std::endl;

	firstList.PushFront(0);
	firstList.PushBack(5);
	firstList.Insert(3, 10);

	std::cout << "Список после добавления элементов: " << firstList.ToString() << std::endl;

	std::cout << "Элемент 10 находится в списке: " << firstList.Contains(10) << std::endl;

	firstList.Change(10, 100);

	std::cout << "Список после изменения элемента: " << firstList.ToString() << std::endl;

	firstList.Remove(2);

	std::cout << "Список после удаления элемента: " << firstList.ToString() << std::endl;

	firstList << 6;

	std::cout << "Список после оператора <<: " << firstList.ToString() << std::endl;

	int value = 0;

	firstList >> value;

	std::cout << "Извлечённый элемент: " << value << std::endl;
	std::cout << "Список после оператора >>: " << firstList.ToString() << std::endl;

	const List secondList = { 7, 8, 9 };

	std::cout << "Второй список: " << secondList.ToString() << std::endl;
	std::cout << "Количество элементов первого списка: " << firstList.GetSize() << std::endl;

	return 0;
}

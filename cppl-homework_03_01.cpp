#include <iostream>

class Smart_array {
	int* arr;
	int size = 0;
	int number_of_filled_items = 0;    //количество заполненных элементов

public:
	Smart_array(int size) {
		this->size = size;
		arr = new int[size];
		set_arr(size);
	}

	int add_element(int value) {
		number_of_filled_items++;
		return value;
	}

	int* set_arr(int size) {
		std::cout << number_of_filled_items << std::endl;
		if (size < number_of_filled_items)
			for (int i = 0; i < size; i++)
				std::cout << arr[i] << std::endl;
		return arr;
	}

	~Smart_array() {
		delete arr;
	}

	int get_element(int elem) {
		return elem;
	}
};

int main()
{
	try {
		Smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		arr.add_element(17);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}




/*
Задача 1. Умный массив
Описание

Вам нужно реализовать умный массив для данных типа int в духе идиомы RAII, который сам управляет своей памятью: самостоятельно выделяет её при создании и очищает, когда объект данного класса не используется.

Должны быть реализованы следующие функции:

	Конструктор, принмающий количество элементов, которое будет хранить массив.
	Функция добавления нового элемента в массив. Не забудьте обработать случай, когда количество элементов больше количества элементов, на которую выделена память.
	Функция получения элемента по индексу. Не забудьте проверку на корректность индекса.
	Деструктор.

Пример правильной работы программы

Работа с вашим классом должна происходить так:

try {
	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);
	arr.add_element(14);
	arr.add_element(15);
	std::cout << arr.get_element(1) << std::endl;
}
catch (const std::exception& ex) {
	std::cout << ex.what() << std::endl;
}

*/
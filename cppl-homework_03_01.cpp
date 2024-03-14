#include <iostream>

class smart_array {
public:
	smart_array(int size) {
		set_arr(size);
	}

	int add_element(int value) {
		std::cout << value << std::endl;
		return value;
	}

	int* set_arr(int size) {
		int* arr = new int[size];

		for (int i = 0; i < size; i++)
			std::cout << arr[i] << std::endl;
		return arr;
	}
	~smart_array() {

	}

	int get_element(int elem) {
		return elem;
	}
};

int main()
{
	try {
		smart_array arr(5);
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
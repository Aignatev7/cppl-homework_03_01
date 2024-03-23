#include <iostream>

class Smart_array {
	int* arr;
	int size = 0;					   //������ �������
	int number_of_filled_items = 0;    //���������� ����������� ���������
	int i = 0;
public:
	Smart_array(int size) {
		this->size = size;
		arr = new int[size];
	}

	int add_element(int value) {
		arr[i] = value;
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
		i++;
		number_of_filled_items++;
		if (number_of_filled_items == size)
		{
			throw std::runtime_error("���������� ��������� ������ ���������� ���������, �� ������� �������� ������");
		}
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
	setlocale(0, "rus");
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
������ 1. ����� ������
��������

��� ����� ����������� ����� ������ ��� ������ ���� int � ���� ������ RAII, ������� ��� ��������� ����� �������: �������������� �������� � ��� �������� � �������, ����� ������ ������� ������ �� ������������.

������ ���� ����������� ��������� �������:

	�����������, ���������� ���������� ���������, ������� ����� ������� ������.
	������� ���������� ������ �������� � ������. �� �������� ���������� ������, ����� ���������� ��������� ������ ���������� ���������, �� ������� �������� ������.
	������� ��������� �������� �� �������. �� �������� �������� �� ������������ �������.
	����������.

������ ���������� ������ ���������

������ � ����� ������� ������ ����������� ���:

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
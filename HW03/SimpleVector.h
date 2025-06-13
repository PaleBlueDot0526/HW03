#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class SimpleVector
{
private:
	T* data; // ���� �迭
	int currentSize; // ���� �迭 ���� ��� ����
	int currentCapacity; // �迭�� ��ü ũ��(����)

	void resize(int newCapacity)
	{
		if (newCapacity <= currentCapacity)
		{
			return; //  ���� �迭�� ũ�⺸�� ������ ���� ���� ����.
		}

		else
		{
			T* newData = new T[newCapacity];

			for (int i = 0; i < currentSize; i++)
			{
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
			currentCapacity = newCapacity;
		}
	}

public:
	SimpleVector() // �⺻ ������ 
	{
		data = new T[10];
		currentSize = 0;
		currentCapacity = 10;
	}
	SimpleVector(int capacity) // ���� 1���� �޴� ������
	{
		if (capacity <= 0) // 0���� ũ�� ���
			capacity = 10;

		data = new T[capacity];
		currentCapacity = capacity;
		currentSize = 0;


	}

	~SimpleVector() // �Ҹ���
	{
		delete[] data;
	}

	void push_back(const T& value)
	{
		if (currentSize >= currentCapacity)
		{
			resize(currentCapacity + 5);

			data[currentSize++] = value;

		}

		else
		{
			data[currentSize++] = value;
		}




	}

	void pop_back()
	{
		if (currentSize > 0)
		{
			currentSize--;
		}
	}

	int size() const
	{
		return currentSize;
	}

	int capacity() const
	{
		return currentCapacity;
	}

	void sortData()
	{
		sort(data, data + currentSize);
	}

	T& operator[](int index)
	{
		return data[index];
	}

	const T& operator[](int index) const
	{
		return data[index];
	}
};
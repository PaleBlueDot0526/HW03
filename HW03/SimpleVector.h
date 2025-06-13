#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class SimpleVector
{
private:
	T* data; // 동적 배열
	int currentSize; // 현재 배열 내부 요소 개수
	int currentCapacity; // 배열의 전체 크기(길이)

	void resize(int newCapacity)
	{
		if (newCapacity <= currentCapacity)
		{
			return; //  현재 배열의 크기보다 작으면 동작 하지 않음.
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
	SimpleVector() // 기본 생성자 
	{
		data = new T[10];
		currentSize = 0;
		currentCapacity = 10;
	}
	SimpleVector(int capacity) // 숫자 1개를 받는 생성자
	{
		if (capacity <= 0) // 0이하 크기 방어
			capacity = 10;

		data = new T[capacity];
		currentCapacity = capacity;
		currentSize = 0;


	}

	~SimpleVector() // 소멸자
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
#pragma once
#include <iostream>
#include <exception>
#include "Compare.h"
class ioob_e : public std::exception {
	virtual const char* what() const throw() {
		return "Index out of bounds";
	}
};
class idne_e : public std::exception {
	virtual const char* what() const throw() {
		return "Item does not exist";
	}
};
class af_e : public std::exception {
	virtual const char* what() const throw() {
		return "Destination array is full";
	}
};

class ae_e : public std::exception {
	virtual const char* what() const throw() {
		return "Destination array is empty";
	}
};
class nrfe_e : public std::exception {
	virtual const char* what() const throw() {
		return "There's not enough room for this element to be added";
	}
};
class ic_sgtcolt0_e : public std::exception {
	virtual const char* what() const throw() {
		return "Destination array has a size that's either greater than its capacity or lower than zero";
	}
};


template<class T>

class Array

{

private:

	T** List; // lista cu pointeri la obiecte de tipul T*

	int Capacity; // dimensiunea listei de pointeri

	int Size; // cate elemente sunt in lista

public:

	Array() { // Lista nu e alocata, Capacity si Size = 0
		this->List = nullptr;
		Capacity = 0;
		Size = 0;
	}
	~Array() { // destructor
		for (int i = 0; i < Capacity; i++)
			delete List[i];
		delete[]List;
	}
	Array(int capacity) { // Lista e alocata cu 'capacity' elemente
		Capacity = capacity;
		Size = 0;
		List = new T*[capacity];
		for (int i = 0; i < capacity; i++) List[i] = nullptr;
	}
	Array(const Array<T>& otherArray) { // constructor de copiere
		this->Capacity = otherArray.Capacity;
		this->Size = otherArray.Size;
		this->List = new T * [otherArray.Capacity];
		for(int i=0;i<this->Capacity;i++)
			if (otherArray.List[i] != nullptr) {
				this->List[i] = new T(otherArray.List[i]);
			}
			else {
				this->List[i] = nullptr;
			}
	}


	T& operator[] (int index) { // arunca exceptie daca index este out of range
		ioob_e ioob; idne_e idne;
		try {
			if (index >= this->Capacity) {
				throw ioob;
			}
			if (this->List[index] == nullptr) {
				throw idne;
			}
			return this->List[index];
		}
		catch (std::exception& ex) {
			printf("Exception: %s.\n", ex.what());
		}
	
	}


	const Array<T>& operator+=(const T& newElem) { // adauga un element de tipul T la sfarsitul listei si returneaza this
		ic_sgtcolt0_e ic_sgtcolt0; af_e af;
		try {
			if (this->Size == this->Capacity) { //aloc memorie in plus?
				throw af;
			}
			else if (this->Size > this->Capacity) {
				throw ic_sgtcolt0;
			}
			this->List[this->Size] = new T(newElem);
			++this->Size;
			return *this;
		}
		catch (std::exception& ex) {
			printf("Exception: %s.\n", ex.what());
			return *this;
		}
	}
	const Array<T>& Insert(int index, const T& newElem) { // adauga un element pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
		ioob_e ioob; ic_sgtcolt0_e ic_sgtcolt0; af_e af; //suprascriu? mut toate elem de dupa?
		try {
			if (index >= this->Capacity)
			{
				throw ioob;
			}
			if (this->Size == this->Capacity) {
				throw af;
			}
			else if (this->Size > this->Capacity) {
				throw ic_sgtcolt0;
			}
			if (this->List[index] == nullptr) {
				this->List[index] = new T(newElem);
				++this->Size;
				return *this;
			}
			else {
				for (int i = Size; i > index; i--)
					List[i] = List[i - 1];
				List[index] = new T(newElem);
				Size++;
				return *this;
			}
		}
		catch (std::exception& ex) {
			printf("Exception: %s.\n", ex.what());
			return *this;
		}
	}
	const Array<T>& Insert(int index, const Array<T> otherArray) { // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
		ioob_e ioob; ic_sgtcolt0_e ic_sgtcolt0; af_e af;
		try {
			if (index >= this->Capacity || index + otherArray.Capacity - 1 >= this->Capacity) {
				throw ioob;
			}
			else if (this->Size == this->Capacity) {
				throw af;
			}
			else if (this->Size > this->Capacity) {
				throw ic_sgtcolt0;
			}
			if (index < this->Size) {
				for (int i = this->Size + otherArray->Size; i > index; i--)
					List[i] = List[i - otherArray->Size];
			}
			int i = index;
			while (i < otherArray.Size) {
				if (otherArray.List[i] != nullptr) {
					this->List[i] = new T(otherArray.List[i]);
				}
				++i;
			}
			
		}
		catch (std::exception& ex) {
			printf("Exception: %s.\n", ex.what());
			return *this;
		}
	}
	const Array<T>& Delete(int index) { // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
		ioob_e ioob; ae_e ae; ic_sgtcolt0_e ic_sgtcolt0; idne_e idne;
		try {
			if (index >= this->Capacity) {
				throw ioob;
			}
			if (this->Size == 0) {
				throw ae;
			}
			else if (this->Size >= this->Capacity) {
				throw ic_sgtcolt0;
			}
			if (this->List[index] == nullptr) {
				throw idne;
			}
			delete this->List[index];
			this->List[index] = nullptr;
			for (int i = index; i < Size - 1; i++)
				List[i] = List[i + 1];
			this->List[Size-1] = nullptr;
			--this->Size;
			return *this;
		}
		catch (std::exception& ex) {
			printf("Exception: %s.\n", ex.what());
			return *this;
		}

	}

	const Array<T>& operator=(const Array<T>& otherArray) {
		if (this != &otherArray) {
			int i = 0;
			if (this->Size == otherArray.Size) {
				while (i < this->Size) {
					if (this->List[i] == nullptr && otherArray.List[i] != nullptr) {
						this->List[i] = new T(otherArray.List[i]);
					}
					else
					{
						delete this->List[i];
						if (otherArray.List[i] != nullptr)
							this->List[i] = new T(otherArray.List[i]);
						else
							this->List[i] = nullptr;
					}
					++i;
				}
			}
			else {
				while (i < this->Size) {
					if (this->List[i] != nullptr) {
						delete this->List[i];
						this->List = nullptr;
					}
					++i;
				}
				delete[] this->List;
				this->List = new T * [otherArray.Capacity];
				i = 0;
				while (i < otherArray.Size) {
					if (otherArray.List[i] != nullptr) {
						this->List[i] = new T(otherArray.List[i]);
					}
					else {
						this->List[i] = nullptr;
					}
					++i;
				}
				this->Size = otherArray.Size;
				this->Capacity = otherArray.Capacity;
			}
		}
		return *this;
	}



	void Sort() { // sorteaza folosind comparatia intre elementele din T
		T* aux;
		int i = 0, j;
		while (i < this->Size - 1) {
			j = i + 1;
			while (j < this->Size) {
				if (this->List[i] != nullptr && this->List[j] != nullptr && *(this->List[i])> *(this->List[j])) {
					aux = this->List[i];
					this->List[i] = this->List[j];
					this->List[j] = aux;
					aux = nullptr;
				}
				++j;
			}
			++i;
		}
	}
	void Sort(int(*compare)(const T&, const T&)) { // sorteaza folosind o functie de comparatie
		T* aux;
		int i = 0, j;
		while (i < this->Size - 1) {
			j = i + 1;
			while (j < this->Size) {
				if (this->List[i] != nullptr && this->List[j] != nullptr && compare(*(this->List[i]), *(this->List[j]))) {
					aux = this->List[i];
					this->List[i] = this->List[j];
					this->List[j] = aux;
					aux = nullptr;
				}
				++j;
			}
			++i;
		}
	}
	void Sort(Compare* comparator) { // sorteaza folosind un obiect de comparatie
		T* aux;
		int i = 0, j;
		while (i < this->Size - 1) {
			j = i + 1;
			while (j < this->Size) {
				if (this->List[i] != nullptr && this->List[j] != nullptr && comparator->CompareElements((void*)*(this->List[i]),(void*)*(this->List[j]))) {
					aux = this->List[i];
					this->List[i] = this->List[j];
					this->List[j] = aux;
					aux = nullptr;
				}
				++j;
			}
			++i;
		}
	}


	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

	int BinarySearch(const T& elem) { // cauta un element folosind binary search in Array
		int begin = 0, end = this->Size;

		while (begin <= end) {
			int middle = (begin + end) / 2;
			if (*(this->List[middle])== elem) {
				return middle;
			}
			if (*(this->List[middle]) > elem)
				end = middle - 1;
			else
				begin = middle + 1;
		}
		return this->Capacity;
	}
	int BinarySearchHelper(const T& elem, int begin, int end, int (*compare)(const T&, const T&)) {
		if (begin <= end) {
			int middle = (begin + end) / 2;
			if (compare(*(this->List[middle]), elem) == 0) {
				return middle;
			}
			if (compare(*(this->List[middle]), elem) > 0)
				return BinarySearchHelper(elem, begin, middle, compare);
			if (compare(*(this->List[middle]), elem) < 0)
				return BinarySearchHelper(elem, middle + 1, end, compare);
		}
		
		return this->Capacity;
	}
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {//  cauta un element folosind binary search si o functie de comparatie
		return BinarySearchHelper(elem, 0, this->Capacity, compare);
	}
	int BinarySearchHelper(const T& elem, int begin, int end, Compare* comparator) {
		if (begin <= end) {
			int middle = (begin + end) / 2;
			if (comparator->CompareElements((void*)*(this->List[middle]),(void*) elem)==0) {
				return middle;
			}
			if (comparator->CompareElements((void*)*(this->List[middle]),(void*) elem) > 0)
				return BinarySearchHelper(elem, begin, middle, comparator);
				if (comparator->CompareElements((void*)*(this->List[middle]),(void*) elem) < 0)
				return BinarySearchHelper(elem, middle + 1, end, comparator);
			
		}
		return this->Capacity;
	}
	int BinarySearch(const T& elem, Compare* comparator) {//  cauta un element folosind binary search si un comparator
		return BinarySearchHelper(elem, 0, this->Capacity, comparator);
	}


	int Find(const T& elem) { // cauta un element in Array
		for (int i = 0; i < Size; i++)
			if (*List[i] == elem)
				return i;
		return this->Capacity;
	}
	int Find(const T& elem, int(*compare)(const T&, const T&)) {//  cauta un element folosind o functie de comparatie
		for (int i = 0; i < Size; i++)
			if (compare(*(this->List[i]), elem))
				return i;
		return this->Capacity;
	}
	int Find(const T& elem, Compare* comparator) {//  cauta un element folosind un comparator
		for (int i = 0; i < Size; i++)
			if (comparator->CompareElements((void*)*(this->List[i]), (void*)elem))
				return i;
		return this->Capacity;
	}


	int GetSize() {
		return this->Size;
	}

	int GetCapacity() {
		return this->Capacity;
	}
	template<typename T>
	class ArrayIterator

	{

	private:
		friend class Array;
		Array<T>* _array;
		int Current; // mai adaugati si alte date si functii necesare pentru iterator

	public:

		ArrayIterator(Array<T>*_array) {
			this->_array = _array;
			this->Current = 0;
		}
		ArrayIterator(Array<T>*_array, int position) {
			this->_array = _array;
			this->Current = position;
		}

		ArrayIterator<T>& operator ++ () {
			++this->Current;
			return *this;

		}

		ArrayIterator<T>& operator -- () {
			--this->Current;
			return *this;
		}
		T& operator*() {
			return *(this->_array->List[this->Current]);
		}
		friend bool operator==(const ArrayIterator<T>& a,const ArrayIterator<T>&b) {
			return b._array == a._array && b.Current == a.Current;
		}

		friend bool operator!=(const ArrayIterator<T>& b, const ArrayIterator<T>& a) {
			return a._array != b._array || a.Current != b.Current;
		}

		T* GetElement() {
			return *(this->_array->List[this->Current]);
		}

	};
	ArrayIterator<T> begin() {
		return ArrayIterator<T>(this, 0);
	}
	ArrayIterator<T> end() {
		return ArrayIterator<T>(this, this->Size);
	}

	ArrayIterator<T> GetBeginIterator() {
		return ArrayIterator<T>(this, 0);
	}

	ArrayIterator<T> GetEndIterator() {
		return ArrayIterator<T>(this, this->Size);
	}
	void Print() {
		for (int i = 0; i < Size; i++)
			std::cout << *List[i] << " ";
		std::cout << std::endl;
	}
};


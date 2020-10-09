#include <iostream>
#include <string>
#include <streambuf>
#include <ctime>
using namespace std;

int input();

class mass {
private:
	int* massad = nullptr;
	int size;
public:
	mass();
	mass(int _size);
	mass(const mass& drob);
	~mass();

	mass& operator= (const mass& drob);
	mass& operator++();
	friend mass operator+(mass a1, mass a2);
	friend mass operator+(mass a1, int k);
	friend mass operator-(mass a1, mass a2);
	int operator[](const int i);

	void set_size(int _size) {
		mass a0(_size);
		for (int i = 0; i < size; i++)
			a0.massad[i] = massad[i];
		for (int i = size; i < _size; i++)
			a0.massad[i] = 0;
		*this = a0;
	}
	void set_value() {
		int i;
		cout << "\n>Input number of element:";
		do {
			i = input();
			rewind(stdin);
		} while (i < 0 || i>=size);
		cout << "\n>Input value:";
		massad[i] = input();
	}
	void output() {
		int i = 0;
		cout << "\n{  ";
		for (i = 0; i < size; i++) {
			cout <<massad[i] << "  ";
		}
		cout << "}\n";
	}
	void sort() {
		int step = size / 2;
		while (step > 0)
		{
			for (int i = 0; i < (size - step); i++) {
				int j = i;
				while (j >= 0 && massad[j] < massad[j + step]) {
					int temp = massad[j];
					massad[j] = massad[j + step];
					massad[j + step] = temp;
					j--;
				}
			}
			step = step / 2;
		}
	}
};



mass::mass() {
	cout << "\n>Try to create\n";
	massad = new(int);
}

mass::mass(int _size) {
	size = _size;
	massad = new int[size];
	for (int i = 0; i < size; i++) {
		massad[i] = rand()%10000;
	}
}

mass::mass(const mass& drob) {
	cout << "\nTry to copy\n";
	massad = new int[drob.size];
	for (int i = 0; i < drob.size; i++) {
		massad[i] = drob.massad[i];
	}
	size = drob.size;
}

mass::~mass() {
	delete[] massad;
	cout << "\nOOOOH-YEEEEAAAAH, MASS DESTRUCTION<\n";
}

int mass::operator[](const int i) {
	return massad[i];
}

mass& mass::operator= (const mass& drob) {
	massad = new int[drob.size];
	for (int i = 0; i < drob.size; i++) {
		massad[i] = drob.massad[i];
	}
	size = drob.size;
	return *this;
}

mass& mass::operator++() {
	output();
	cout << "\n*double*\n";
	for (int i = 0; i < size; i++) {
		massad[i]*=2;
	}
	return *this;
}

mass operator+(mass a1, mass a2) {
	a1.output();
	cout << "+plus+";
	a2.output();
	int msize;
	if (a1.size < a2.size)msize = a1.size;
	else msize = a2.size;
	mass res(msize);
	res.size = msize;
	for (int i = 0; i < msize; i++)
		res.massad[i] = a1[i] + a2[i];
	return res;
}

mass operator-(mass a1, mass a2) {
	a1.output();
	cout << "\n -minus- ";
	a2.output();
	int msize;
	if (a1.size < a2.size) msize = a1.size;
	else msize = a2.size;
	mass res(msize);
	res.size = msize;
	for (int i = 0; i < msize; i++)
		res.massad[i] = a1[i] - a2[i];
	return res;
}

mass operator+(mass a1, int k) {
	a1.output();
	for (int i = 0; i < a1.size; i++)
		a1.massad[i] = a1[i] + k;
	return a1;
}

int main()
{
	srand(time(NULL));

	const int _num = 3;
	int x, y, o,_size;

	mass* wasd = new mass[_num];
	mass();
	_size = input();
	mass a1(_size);
	a1.output();

	for (int i = 0; i < _num; i++) {
		wasd[i] = mass(input());
		wasd[i].output();
	}
	cout << endl;
	while (1) {
		cout << endl;
		cout << "1-Sum of 2 arrays;" << endl;
		cout << "2-Subtraction of 2 arrays;" << endl;
		cout << "3-Sum of array & number;" << endl;
		cout << "4-Sorting array;" << endl;
		cout << "5-Set size;" << endl;
		cout << "6-Set one element;" << endl;
		cout << "0-Finish program;" << endl;
		switch (input()) {
		case 1:
			cout << "\n>Input number of array:";
			do {
				x = input();
				rewind(stdin);
			} while (x < 0 || x >= _num);
			cout << "\n>Input number of array:";
			do {
				y = input();
				rewind(stdin);
			} while (y < 0 || y >= _num);
			if (x == y) {
				(++wasd[x]).output();
			}
			else {
				(wasd[x] + wasd[y]).output();
			}
			break;
		case 2:
			cout << "\n>Input number of array";
			do {
				x = input();
				rewind(stdin);
			} while (x < 0 || x >= _num);
			do {
				y = input();
				rewind(stdin);
			} while (y < 0 || y >= _num);
			(wasd[x] - wasd[y]).output();
			break;
		case 3:
			cout << "\n>Input number of array";
			do {
				x = input();
				rewind(stdin);
			} while (x < 0 || x >= _num);
			(wasd[x] + input()).output();
			break;
		case 4:
			cout << "\n>Input number of array";
			do {
				x = input();
				rewind(stdin);
			} while (x < 0 || x >= _num);
			wasd[x].sort();
			wasd[x].output();
			break;
		case 5:
			cout << "\n>Input number of array";
			do {
				x = input();
				rewind(stdin);
			} while (x < 0 || x >= _num);
			do {
				o = input();
			} while (o < 1);
			wasd[x].set_size(o);
			wasd[x].output();
			break;
		case 6:
			cout << "\n>Input number of array";
			do {
				x = input();
				rewind(stdin);
			} while (x < 0 || x >= _num);
			wasd[x].set_value();
			wasd[x].output();
			break;
		case 0:
			cout << "\n>end\n";
			delete[] wasd;
			return 0;
		}
	}
}

int input() {
	int i;
	bool fail = true;
	cout << "\nInput:";
	do
	{
		cin >> i;
		if (cin.fail() || cin.rdbuf()->in_avail() > 1)
			cout << "\nError" << endl;
		else
			fail = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (fail);
	return i;
}

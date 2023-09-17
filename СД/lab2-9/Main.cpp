#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cctype>
#include <locale>
#include <cmath>
#include <algorithm>
#include <type_traits>
#include <limits>
#include <iomanip>

using namespace std;
int _stateMenu;

template <typename T, typename std::enable_if<std::is_same<T, int>::value || std::is_same<T, double>::value || std::is_same<T, long int>::value || std::is_same<T, unsigned int>::value>::type* = nullptr>
void GetValueFromUser(T & variable) {
	std::string input_str;
	bool input_error;

	do {
		input_error = false;

		// ������������� ������� ����� ������ ����� ����������� ����� ������������
		if (std::cin.peek() == '\n') {
			std::cin.ignore();
		}

		std::getline(std::cin, input_str);

		// ������ ������� �� ����� ��� ����� � ��������� ������
		if constexpr (std::is_same<T, double>::value) {
			std::replace(input_str.begin(), input_str.end(), ',', '.');
		}

		// �������� ������������ ��� ����
		if constexpr (std::is_same<T, unsigned int>::value) {
			input_str.erase(std::remove(input_str.begin(), input_str.end(), '/'), input_str.end());
		}

		std::stringstream ss(input_str);

		if (ss >> variable) {
			if constexpr (std::is_same<T, int>::value) {
				if (variable >= 0 && variable <= (1 << 15) - 1 && ss.eof()) {
					// Success: Do nothing.
				}
				else {
					std::cerr << "������: ������� ����� ����� � ��������� [0, " << ((1 << 15) - 1) << "]!" << std::endl;
					input_error = true;
				}
			}
			else if constexpr (std::is_same<T, double>::value) {
				if (variable >= 0 && variable <= std::numeric_limits<double>::max() && ss.eof()) {
					// Success: Do nothing.
				}
				else {
					std::cerr << "������: ������� ����� � ��������� ������ � ��������� [0, " << std::numeric_limits<double>::max() << "]!" << std::endl;
					input_error = true;
				}
			}
			else if constexpr (std::is_same<T, long int>::value) {
				if ((variable >= 250000000 && variable <= 259999999) || (variable >= 330000000 && variable <= 339999999) || (variable >= 440000000 && variable <= 449999999) || (variable >= 290000000 && variable <= 299999999) || (variable >= 240000000 && variable <= 249999999) && ss.eof()) {
					// Success: Do nothing.
				}
				else {
					std::cerr << "������: ������� ���������� ����� ��������! �������������� ���������: A1 (44,29), MTC (33), Life:) (25), Beltelecom (24)." << std::endl;
					input_error = true;
				}
			}
			else if constexpr (std::is_same<T, unsigned int>::value) {
				if (variable >= 20000101 && variable <= 21000101 && ss.eof()) {
					// Check if the year is valid
					unsigned int year = variable / 10000;
					if (year < 2000 || year > 2100) {
						std::cerr << "������: ��� ������ ���� � ��������� �� 2000 �� 2100!" << std::endl;
						input_error = true;
					}

					// Check if the month is valid
					unsigned int month = (variable / 100) % 100;
					if (month < 1 || month > 12) {
						std::cerr << "������: ����� ������ ���� � ��������� �� 1 �� 12!" << std::endl;
						input_error = true;
					}

					// Check if the day is valid
					unsigned int day = variable % 100;
					if (day < 1 || day > 31) {
						std::cerr << "������: ���� ������ ���� � ��������� �� 1 �� 31!" << std::endl;
						input_error = true;
					}
				}
				else {
					std::cerr << "������: ������� ���� � ������� ����/��/��, ��� ���� - ���, �� - �����, �� - ����, � ��������� �� 2000 ���� �� 2100 ����!" << std::endl;
					input_error = true;
				}
			}
		}
		else {
			std::cerr << "������: ��������� �������� �� ������������� ���� ����������!" << std::endl;
			input_error = true;
		}
	} while (input_error);
}


void GetStringValueFromUser(std::string& variable, bool allow_digits_and_symbols = false) {
	std::string user_input;
	bool input_error;

	do {
		input_error = false;

		// ������� ������ ����� �� ������� ����� ������, ���� �� ����
		if (std::cin.peek() == '\n') {
			std::cin.ignore();
		}

		// ���������� ����� ������ �� ��������
		user_input.clear();
		char c;
		while (std::cin.get(c)) {
			if (c == '\n') {
				break;
			}
			user_input += c;
		}

		// �������� �� ������ �����
		if (!user_input.empty()) {
			for (const char c : user_input) {
				if ((!allow_digits_and_symbols && !isalpha(c) && c != '\'') || (allow_digits_and_symbols && !isalnum(c) && c != '\'' && c != '/' && c != ' ' && c != '-' && c != '�')) {
					std::cerr << "������: ������ �������� ������������ �������!" << std::endl;
					input_error = true;
					break;
				}
			}
		}
		else {
			std::cerr << "������: ������ �� ����� ���� ������!" << std::endl;
			input_error = true;
		}

	} while (input_error);

	variable = user_input;
}

std::string FormatDate(unsigned int date) {
	unsigned int year = date / 10000;
	unsigned int month = (date % 10000) / 100;
	unsigned int day = date % 100;

	std::ostringstream oss;
	oss << std::setw(4) << std::setfill('0') << year << '/'
		<< std::setw(2) << std::setfill('0') << month << '/'
		<< std::setw(2) << std::setfill('0') << day;
	return oss.str();
}

void Menu() {
	cout << "--------�����������--------\n" << endl;
	cout << "1. ���� ������" << endl;
	cout << "2. ��������� ������" << endl;
	cout << "3. ����� ������" << endl;
	cout << "4. ����� ������ �� �������" << endl;
	cout << "5. ���������� ������ � ����" << endl;
	cout << "6. ������ ������ �� �����" << endl;
	cout << "7. �������� �����" << endl;
	cout << "8. ��������" << endl;
	cout << "9. ����������" << endl;
	cout << "10. �����" << endl;

	cout << "0. �����" << endl;

	cout << "\n�������� ��������: ";
	GetValueFromUser(_stateMenu);
}

void DeletionMenu() {
	cout << "1. ������� ������� �� �������" << endl;
	cout << "2. ������� ��� ��������" << endl;
	cout << "0. ��������� � ������� ����" << endl;
	cout << "�������� ��������: ";
}

void SortingMenu() {
	cout << "-----�� ������ ��������-----" << endl;
	cout << "1. Insertion sort" << endl;
	cout << "----------�� ����-----------" << endl;
	cout << "2. Bubble Sort" << endl;
	cout << "3. Selection Sort" << endl;
	cout << "4. Merge Sort" << endl;
	cout << "5. Quick Sort" << endl;
	cout << "----------------------------" << endl;
	cout << "0. ��������� � ������� ����" << endl;
	cout << "�������� ����� ����������: ";
}

void SearchMenu() {
	cout << "1. ����� ������� �� �����" << endl;
	cout << "2. ����� ������� �� ������ ��������" << endl;
	cout << "0. ��������� � ������� ����" << endl;
	cout << "�������� ����� ������: ";
}

struct Tovar {
	unsigned int data_dost = 0;
	string product;
	double cost = 0.0;
};

struct Client {
	string Name, Fam, Otch;
	Tovar tovar[9];
	long int TelephoneNumber = 0;
	string Email;
};

bool file_exists(const char* filename) {
	std::ifstream infile(filename);
	return infile.good();
}

void remove_file(const char filename[]) {
	if (file_exists(filename)) {
		if (remove(filename) != 0) {
			std::cerr << "������: �� ������� ������� ���� " << filename << "." << std::endl;
		}
	}
	else {
		std::cerr << "������: ���� " << filename << " �� ���������� � �� ����� ���� ������." << std::endl;
	}
}

void print_all_struct(Client* t, int kol, int kolvo)
{
	for (int i = 0; i < kol; i++)
	{
		cout << "\n----------------������ " << i << " ----------------";
		cout << "\n���: " << t[i].Name << "\n�������: " << t[i].Fam << "\n��������: " << t[i].Otch << "\n�������: " << t[i].TelephoneNumber << "\nEmail: " << t[i].Email;
		cout << endl;

		for (int k = 0; k < kolvo; k++)
		{
			cout << "\n�������: " << t[i].tovar[k].product << "\n��� ������: " << t[i].tovar[k].cost << "\n�������� ���� �������� (����/��/��): " << FormatDate(t[i].tovar[k].data_dost);
			cout << endl;
		}

	}
}

void findin(Client* t, int index, int kolvo)
{
	for (int i = 0; i <= index; i++)
	{
		if (i == index) {
			cout << "\n----------------������ " << i << " ----------------";
			cout << "\n���: " << t[i].Name << "\n�������: " << t[i].Fam << "\n��������: " << t[i].Otch << "\n�������: " << t[i].TelephoneNumber << "\nEmail: " << t[i].Email;
			cout << endl;

			for (int k = 0; k < kolvo; k++)
			{
				cout << "\n�������: " << t[i].tovar[k].product << "\n��� ������: " << t[i].tovar[k].cost << "\n�������� ���� �������� (����/��/��): " << FormatDate(t[i].tovar[k].data_dost);
				cout << endl;
			}
		}
	}
}

void savin(Client* d, int n, string fileName, int l)
{
	ofstream record(fileName, ios::out);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << d[i].Name << endl;
			record << d[i].Fam << endl;
			record << d[i].Otch << endl;
			record << d[i].TelephoneNumber << endl;
			record << d[i].Email << endl;

			// ������ �������� size2 ����� ����������� ���������� � �������
			record << l << endl;

			for (int k = 0; k < l; k++)
			{
				record << d[i].tovar[k].product << endl;
				record << d[i].tovar[k].cost << endl;
				record << d[i].tovar[k].data_dost << endl;
			}
		}
		cout << "������ ��������!" << endl;
	}
	else
		cout << "������ �������� �����!" << endl;

	record.close();
}

void read(Client* (&d), int& n, int& l, const std::string& fileName)
{
	ifstream record(fileName);

	if (record) {
		record >> n;
		d = new Client[n];

		for (int i = 0; i < n; i++) {
			record >> d[i].Name;
			record >> d[i].Fam;
			record >> d[i].Otch;
			record >> d[i].TelephoneNumber;
			record >> d[i].Email;

			// ������ �������� size2 �� �����
			record >> l;

			for (int k = 0; k < l; k++)
			{
				record >> d[i].tovar[k].product;
				record >> d[i].tovar[k].cost;
				record >> d[i].tovar[k].data_dost;
			}
		}
		cout << "������ �������!" << endl;
	}
	else {
		cout << "������ �������� �����!" << endl;
	}
	record.close();
}

void Copy(Client* (&d_n), Client* (&d_o), int n)
{

	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}

bool del(Client* (&t), int& size)
{
	if (size <= 0) {
		cout << "������: ��� ��������� ��� ��������!" << endl;
		return false;
	}

	int _n;
	cout << "������� ����� �������� (�� 0 �� " << size - 1 << "): ";
	GetValueFromUser(_n);
	system("cls");

	if (_n >= 0 && _n < size) {
		Client* new_t = new Client[size - 1];

		std::copy(t, t + _n, new_t);
		std::copy(t + _n + 1, t + size, new_t + _n);

		delete[] t;
		t = new_t;
		--size;

		cout << "������ �������!" << endl;
		return true;
	}
	else {
		cout << "������: ������� ����� �������� � ��������� [0, " << size - 1 << "]!" << endl;
		return false;
	}
}



void Change(Client* (&t), int n, int l)
{
	int i;
	cout << "������� ����� �������� (�� 0 �� " << n - 1 << "): ";
	GetValueFromUser(i);
	system("cls");

	if (i >= 0 && i < n) {
		cout << "\n���: "; GetStringValueFromUser(t[i].Name);
		cout << "\n�������: "; GetStringValueFromUser(t[i].Fam);
		cout << "\n��������: "; GetStringValueFromUser(t[i].Otch);
		cout << "\n������� (��� +375 � ������� 444948232): "; GetValueFromUser(t[i].TelephoneNumber);
		cout << "\nEmail: "; cin >> t[i].Email;

		for (int k = 0; k < l; k++)
		{
			cout << "\n�������: "; GetStringValueFromUser(t[i].tovar[k].product, true);
			cout << "\n�������� ���� ($): "; GetValueFromUser(t[i].tovar[k].cost);
			cout << "\n�������� ���� �������� (����/��/��): "; GetValueFromUser(t[i].tovar[k].data_dost);
		}
		system("cls");
		cout << "������ ��������!" << endl;
	}
	else
		cout << "������: ������� ����� �������� � ��������� [0, " << n - 1 << "]!" << endl;
}

void FindStr(Client* (&a), int n)
{
	string Name;
	cout << "������� ��� �������: ";
	GetStringValueFromUser(Name);
	system("cls");

	for (int i = 0; i < n; i++)
	{
		int l = a->Name.size();
		int l2 = Name.size();
		int fg = 0;
		string x = a[i].Name;

		for (int j = 0; j < l; j++) {

			if (j + l2 > l + fg)break;
			if (Name[fg] != x[j])
			{
				fg = 0;
				continue;
			}
			fg++;
			if (fg == l2)
			{

				cout << "\n----------------������ " << i << " ----------------";
				cout << "\n���: " << a[i].Name << "\n�������: " << a[i].Fam << "\n��������: " << a[i].Otch << "\n�������: " << a[i].TelephoneNumber << "\nEmail: " << a[i].Email;
				cout << endl;
				cout << endl;
				break;
			}
		}
	}
}

void InsertSort(Client* (&t), int n)
{
	Client key;
	int i = 0;

	for (int j = 1; j < n; j++) {
		key = t[j];
		i = j - 1;

		while (i >= 0 && t[i].TelephoneNumber > key.TelephoneNumber)
		{
			t[i + 1] = t[i];
			i--;
			t[i + 1] = key;
		}
	}
}

void BubbleSort(Client* (&t), int n)
{
	for (int i = 0; i < n; i++)
	{

		for (int j = i + 1; j < n; j++) {

			if (t[i].tovar->cost > t[j].tovar->cost) {

				swap(t[i], t[j]);
			}
		}
	}
}

void SelectionSort(Client* (&t), int n) {

	for (int i = 0; i < n - 1; i++) {
		int min_index = i;

		for (int j = i + 1; j < n; j++) {

			if (t[j].tovar->cost < t[min_index].tovar->cost) {
				min_index = j;
			}
		}
		if (min_index != i) {
			swap(t[i], t[min_index]);
		}
	}
}

void Merge(Client* (&t), int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	Client* L = new Client[n1];
	Client* R = new Client[n2];

	for (int i = 0; i < n1; i++)
		L[i] = t[left + i];

	for (int j = 0; j < n2; j++)
		R[j] = t[mid + 1 + j];

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2) {

		if (L[i].tovar->cost <= R[j].tovar->cost) {
			t[k] = L[i];
			i++;
		}
		else {
			t[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		t[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		t[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;
}

void MergeSort(Client* (&t), int left, int right) {

	if (left < right) {
		int mid = left + (right - left) / 2;
		MergeSort(t, left, mid);
		MergeSort(t, mid + 1, right);
		Merge(t, left, mid, right);
	}
}

int Partition(Client* (&t), int low, int high) {
	int pivot = t[high].tovar->cost;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (t[j].tovar->cost < pivot) {
			i++;
			swap(t[i], t[j]);
		}
	}

	swap(t[i + 1], t[high]);
	return (i + 1);
}

void QuickSort(Client* (&t), int low, int high) {

	if (low < high) {
		int pi = Partition(t, low, high);
		QuickSort(t, low, pi - 1);
		QuickSort(t, pi + 1, high);
	}
}

int InterpolationSearch(Client* (&t), int size, int x)
{
	int lo = 0, hi = size - 1;
	int range = t[hi].TelephoneNumber - t[lo].TelephoneNumber;

	while (lo < hi) {
		int pos = lo + ((double)(hi - lo) / range) * (x - t[lo].TelephoneNumber);

		if (t[pos].TelephoneNumber == x)
			return pos;

		if (t[pos].TelephoneNumber < x)
			lo = pos + 1;
		else
			hi = pos - 1;
	}

	return (t[lo].TelephoneNumber == x) ? lo : -1;
}


int main()
{
	setlocale(LC_ALL, "rus");
	int in, size, size2;
	int n = 1;
	long int x;
	int index;
	std::string fileName;
	cout << "������� ���������� ��������: \n";
	GetValueFromUser(size);
	Client* t = new Client[size];
	cout << "������� ���������� ������ ��������� ��� ������� �������: \n";
	GetValueFromUser(size2);
	system("cls");
	int* p = new int[size2];
	char filename[80];
	Menu();
	while (_stateMenu) {

		switch (_stateMenu)
		{
		case 1:
			system("cls");

			for (int i = 0; i < size; i++)
			{
				cout << "\n���: "; GetStringValueFromUser(t[i].Name);
				cout << "\n�������: "; GetStringValueFromUser(t[i].Fam);
				cout << "\n��������: "; GetStringValueFromUser(t[i].Otch);
				cout << "\n������� (��� +375 � ������� 444948232): "; GetValueFromUser(t[i].TelephoneNumber);
				cout << "\nEmail: "; cin >> t[i].Email;

				for (int k = 0; k < size2; k++)
				{
					cout << "\n�������: "; GetStringValueFromUser(t[i].tovar[k].product, true);
					cout << "\n��� ������ ($): "; GetValueFromUser(t[i].tovar[k].cost);
					cout << "\n�������� ���� �������� (����/��/��): "; GetValueFromUser(t[i].tovar[k].data_dost);
				}
			}
			system("pause");
			system("cls");
			Menu();
			break;


		case 2:
			if (size != 0) {
				Change(t, size, size2);
				system("pause");
				system("cls");
				Menu();
				break;
			}
			else
			{
				cout << "������ �����!" << endl;
				break;
			}


		case 3:
			system("cls");
			print_all_struct(t, size, size2);
			cout << "\n\n������ ��������!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;


		case 4:
			system("cls");
			cout << "����� ������ �������? ";
			GetValueFromUser(in);
			findin(t, in, size2);
			system("pause");
			system("cls");
			Menu();
			break;


		case 5:
			system("cls");
			cout << "������� �������� �����: ";
			cin >> filename;
			savin(t, size, filename, size2);
			system("pause");
			system("cls");
			Menu();
			break;


		case 6:
			system("cls");
			cout << "������� �������� �����: ";
			cin >> fileName;
			read(t, size, size2, fileName);
			system("pause");
			system("cls");
			Menu();
			break;


		case 7:
			cout << "������� �������� �����: ";
			cin >> filename;
			remove_file(filename);
			system("pause");
			system("cls");
			Menu();
			break;


		case 8:
			system("cls");
			int deletionChoice;
			bool deletionValidChoice;
			do {
				deletionValidChoice = true;
				DeletionMenu();
				GetValueFromUser(deletionChoice);
				switch (deletionChoice) {
				case 1:
					deletionValidChoice = del(t, size);
					break;
				case 2:
					size = 0;
					delete[]t;
					t = new Client[size];
					break;
				case 0:
					// ������� � ������� ����
					break;
				default:
					// �������� �����
					system("cls");
					cout << "������� ������ ����� ��������! ���������� ��� ���.\n" << endl;
					deletionValidChoice = false;
					break;
				}
			} while (!deletionValidChoice);
			system("cls");
			Menu();
			break;


		case 9:
			system("cls");
			int sortingChoice;
			bool validChoice;
			do {
				validChoice = true;
				SortingMenu();
				GetValueFromUser(sortingChoice);
				switch (sortingChoice) {

				case 1:
					InsertSort(t, size);
					break;
				case 2:
					BubbleSort(t, size);
					break;
				case 3:
					SelectionSort(t, size);
					break;
				case 4:
					MergeSort(t, 0, size - 1);
					break;
				case 5:
					QuickSort(t, 0, size - 1);
					break;

				case 0:
					// ������� � ������� ����
					break;
				default:
					// �������� �����
					system("cls");
					cout << "������� ������ ����� ��������! ���������� ��� ���.\n" << endl;
					validChoice = false;
					break;
				}
			} while (!validChoice);

			if (sortingChoice != 0) {
				system("cls");
				print_all_struct(t, size, size2);
				cout << "\n������ ��������!" << endl;
				system("pause");
			}
			system("cls");
			Menu();
			break;


		case 10:
			system("cls");
			int searchChoice;
			do {
				SearchMenu();
				GetValueFromUser(searchChoice);
				switch (searchChoice) {
				case 1:
					FindStr(t, size);
					break;
				case 2:
					cout << "������� ������� ����� �������� (��� +375): ";
					GetValueFromUser(x);
					index = InterpolationSearch(t, size, x);
					if (index == -1) {
						system("cls");
						cout << "������� �� ������\n" << endl;
					}
					else {
						system("cls");
						cout << "������� ������� ��������� � ������ " << index << endl;
						cout << "\n���������� � �������: \n" << endl;
						cout << "���: " << t[index].Name << endl;
						cout << "�������: " << t[index].Fam << endl;
						cout << "��������: " << t[index].Otch << endl;
						cout << "������� (��� +375): " << t[index].TelephoneNumber << endl;
						cout << "Email: " << t[index].Email << endl;
						cout << endl;

						for (int k = 0; k < size2; k++) {
							cout << "������� " << k + 1 << ": " << t[index].tovar[k].product << endl;
							cout << "��� ������ ($): " << t[index].tovar[k].cost << endl;
							cout << "\n�������� ���� �������� (����/��/��): " << FormatDate(t[index].tovar[k].data_dost) << endl;
							cout << endl;
						}
					}
					break;
				case 0:
					// ������� � ������� ����
					break;
				default:
					// �������� �����
					system("cls");
					cout << "������� ������ ����� ��������! ���������� ��� ���.\n" << endl;
					break;
				}
			} while (searchChoice != 0);
			system("cls");
			Menu();
			break;


		case 0:
			break;
		default:
			system("cls");
			cout << "������� ������ ����� ��������!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}
}
#include <iostream>
#include <vector>

using namespace std;

// Структура для представления информации о сданных студентом экзаменах 
struct Exam {
	string name; // ФИО студента
	int exams_num; // Число экзаменов
	vector<int> marks; // Полученные оценки
};

// Функция для проверки, сданы ли все экзамены на 4 и/или 5
bool check_exams(Exam ex) {
	bool flag = true;
	for (int i = 0; i < ex.exams_num; i++) {
		if (ex.marks[i] < 4)
			flag = false;
	}
	return flag;
}

// Функция для обработки массива структур Exam
int exam_statistic(vector<Exam> exams) {
	int total_num = exams.size(); // Общее число студентов
	int passed_num = 0; // Число студентов, сдавших экзамены на 4 и 5
	for (int i = 0; i < total_num; i++) {
		if (check_exams(exams[i]))
			passed_num++;
	}
	return (passed_num * 100 / total_num);
}

int main() {
	// Пример использования функции exam_statistic
	setlocale(LC_ALL, "RUS");
	vector<Exam> exams = {
		{"Иванов Иван Иванович", 3, {4, 5, 5}},
		{"Сидоров Сидор Сидорович", 2, {2, 4}},
		{"Петров Петр Петрович", 4, {4, 4, 5, 5}}
	};
	int statistic = exam_statistic(exams);
	cout << "Характеристика успеваемости студентов: " << statistic << "%" << endl;
	return 0;
}
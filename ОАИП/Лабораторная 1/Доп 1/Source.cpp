#include <iostream>
#include <vector>

using namespace std;

// ��������� ��� ������������� ���������� � ������� ��������� ��������� 
struct Exam {
	string name; // ��� ��������
	int exams_num; // ����� ���������
	vector<int> marks; // ���������� ������
};

// ������� ��� ��������, ����� �� ��� �������� �� 4 �/��� 5
bool check_exams(Exam ex) {
	bool flag = true;
	for (int i = 0; i < ex.exams_num; i++) {
		if (ex.marks[i] < 4)
			flag = false;
	}
	return flag;
}

// ������� ��� ��������� ������� �������� Exam
int exam_statistic(vector<Exam> exams) {
	int total_num = exams.size(); // ����� ����� ���������
	int passed_num = 0; // ����� ���������, ������� �������� �� 4 � 5
	for (int i = 0; i < total_num; i++) {
		if (check_exams(exams[i]))
			passed_num++;
	}
	return (passed_num * 100 / total_num);
}

int main() {
	// ������ ������������� ������� exam_statistic
	setlocale(LC_ALL, "RUS");
	vector<Exam> exams = {
		{"������ ���� ��������", 3, {4, 5, 5}},
		{"������� ����� ���������", 2, {2, 4}},
		{"������ ���� ��������", 4, {4, 4, 5, 5}}
	};
	int statistic = exam_statistic(exams);
	cout << "�������������� ������������ ���������: " << statistic << "%" << endl;
	return 0;
}
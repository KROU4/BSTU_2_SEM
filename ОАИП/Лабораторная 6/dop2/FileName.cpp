#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

struct Student {
    std::string lastName;
    std::string firstName;
    std::string middleName;
    int birthYear;
    int course;
    int groupNumber;
    std::vector<int> grades;

    // Конструктор структуры Student
    Student(std::string ln, std::string fn, std::string mn, int by, int c, int gn, std::vector<int> g)
        : lastName(ln), firstName(fn), middleName(mn), birthYear(by), course(c), groupNumber(gn), grades(g) {}
};

// Функция для сравнения студентов по курсу и алфавиту
bool compareStudents(const Student& a, const Student& b) {
    if (a.course == b.course)
        return a.lastName < b.lastName;
    return a.course < b.course;
}

int main() {
    // Создание списка студентов
    setlocale(LC_ALL, "RUS");
    std::list<Student> students = {
        {"Иванов", "Иван", "Иванович", 1999, 3, 101, {5, 4, 5, 4, 5}},
        {"Петров", "Петр", "Петрович", 2000, 2, 201, {5, 4, 4, 5, 3}},
        {"Сидоров", "Сергей", "Сергеевич", 1998, 3, 101, {3, 3, 4, 4, 5}},
        {"Смирнов", "Алексей", "Алексеевич", 2001, 1, 301, {5, 5, 5, 5, 5}},
        {"Кузнецов", "Дмитрий", "Дмитриевич", 1997, 4, 401, {4, 4, 4, 4, 4}}
    };

    // Сортировка студентов по курсу и алфавиту
    students.sort(compareStudents);

    // Расчет среднего балла каждой группы по каждому предмету
    std::map<int, std::vector<double>> avgGradesByGroup;
    for (const Student& student : students) {
        if (avgGradesByGroup.find(student.groupNumber) == avgGradesByGroup.end()) {
            avgGradesByGroup[student.groupNumber] = std::vector<double>(5, 0.0);
        }
        for (size_t i = 0; i < student.grades.size(); ++i) {
            avgGradesByGroup[student.groupNumber][i] += student.grades[i];
        }
    }

    for (auto& group : avgGradesByGroup) {
        for (double& avg : group.second) {
            avg /= students.size();
        }
    }

    // Определение самого старшего и самого младшего студентов
    std::list<Student>::iterator youngestStudent = students.begin();
    std::list<Student>::iterator oldestStudent = students.begin();
    std::list<Student>::iterator it = students.begin();

    for (; it != students.end(); ++it) {
        if (it->birthYear > youngestStudent->birthYear) {
            youngestStudent = it;
        }
        if (it->birthYear < oldestStudent->birthYear) {
            oldestStudent = it;
        }
    }


    // Нахождение лучшего студента с точки зрения успеваемости для каждой группы
    std::map<int, const Student*> bestStudentsByGroup;
    for (const Student& student : students) {
        if (bestStudentsByGroup.find(student.groupNumber) == bestStudentsByGroup.end()) {
            bestStudentsByGroup[student.groupNumber] = &student;
        }
        else {
            int currentBestSum = 0, currentSum = 0;
            for (size_t i = 0; i < student.grades.size(); ++i) {
                currentBestSum += bestStudentsByGroup[student.groupNumber]->grades[i];
                currentSum += student.grades[i];
            }
            if (currentSum > currentBestSum) {
                bestStudentsByGroup[student.groupNumber] = &student;
            }
        }
    }

    // Вывод результатов
    std::cout << "Отсортированный список студентов:\n";
    for (const Student& student : students) {
        std::cout << student.lastName << " " << student.firstName << " " << student.middleName
            << " - курс: " << student.course << ", группа: " << student.groupNumber << std::endl;
    }

    std::cout << "\nСредний балл каждой группы по каждому предмету:\n";
    for (const auto& group : avgGradesByGroup) {
        std::cout << "Группа " << group.first << ": ";
        for (const double& avg : group.second) {
            std::cout << avg << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nСамый молодой студент: " << youngestStudent->lastName << " " << youngestStudent->firstName
        << " " << youngestStudent->middleName << std::endl;
    std::cout << "Самый старый студент: " << oldestStudent->lastName << " " << oldestStudent->firstName
        << " " << oldestStudent->middleName << std::endl;

    std::cout << "\nЛучший студент в каждой группе:\n";
    for (const auto& group : bestStudentsByGroup) {
        std::cout << "Группа " << group.first << ": " << group.second->lastName << " "
            << group.second->firstName << " " << group.second->middleName << std::endl;
    }

    return 0;
}

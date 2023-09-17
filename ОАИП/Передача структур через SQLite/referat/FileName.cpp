#include <iostream>
#include <string>
#include <sqlite3.h> //SQLite
#include <iomanip> //��������� ���������� ������� ����� ��� ������� ���������� ������ ����� �������
#include <Windows.h> //����������� �������

// ���������� ��������� Data
struct Data {
    int integer;
    double decimal;
    std::string text;
};

int main() {
    // ��������� ��������� �������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ������������� �������� � �������
    const Data data1 = { 11, 1.8, "������1" }; //������� ���� ����� �����, ������� �����, ������ �������������
    const Data data2 = { 7, 3.14, "������2" }; //���� ����

    // ��������� ���� ������ � ������
    sqlite3* db = nullptr;
    int rc = sqlite3_open(":memory:", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }

    // ������� �������
    const char* create_table = "CREATE TABLE IF NOT EXISTS data1 (integer INTEGER, decimal REAL, text TEXT); "
        "CREATE TABLE IF NOT EXISTS data2 (integer INTEGER, decimal REAL, text TEXT);";
    rc = sqlite3_exec(db, create_table, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Can't create table: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }

    // ��������� ������ � �������
    std::string insert_data1 = "INSERT INTO data1 (integer, decimal, text) VALUES (" + std::to_string(data1.integer) + ", " + std::to_string(data1.decimal) + ", '" + data1.text + "');";
    std::string insert_data2 = "INSERT INTO data2 (integer, decimal, text) VALUES (" + std::to_string(data2.integer) + ", " + std::to_string(data2.decimal) + ", '" + data2.text + "');";
    rc = sqlite3_exec(db, insert_data1.c_str(), nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Can't insert data into table: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }

    rc = sqlite3_exec(db, insert_data2.c_str(), nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Can't insert data into table: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }

    // ��������� ������ �� ��������� ������
    const char* multiply_query = "SELECT d1.integer * d2.integer, d1.decimal * d2.decimal, d1.text || d2.text FROM data1 AS d1, data2 AS d2;";
    sqlite3_stmt* stmt = nullptr;
    rc = sqlite3_prepare_v2(db, multiply_query, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Can't prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        std::cerr << "Can't execute statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
    }

    // �������� ���������� �������
    const Data result = { int(sqlite3_column_int(stmt, 0)),
    double(sqlite3_column_double(stmt, 1)),
    std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)))
    };

    // ������� ���������� �������
    std::cout << "��������� (3-� ���������): " << std::endl;
    std::cout << "����� �����: " << result.integer << std::endl;
    std::cout << "������� �����: " << result.decimal << std::endl;
    std::cout << "����� (������������ �����): " << result.text << std::endl;

    // ����������� �������
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}
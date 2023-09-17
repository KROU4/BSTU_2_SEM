#include <iostream>
#include "tinyxml2.h" // ����������� ���������� TinyXML - 2

int main() {
    setlocale(0, "rus"); // ��������� ������ ��� ����������� ����������� ���������

    tinyxml2::XMLDocument doc; // �������� ������� XML-���������
    tinyxml2::XMLError loadResult = doc.LoadFile("example.xml"); // �������� XML-�����

    // �������� ���������� �������� XML-�����
    if (loadResult == tinyxml2::XML_SUCCESS) {
        std::cout << "XML-���� �������� �������." << std::endl;

        // ��������� ��������� �������� XML-���������
        tinyxml2::XMLElement* root = doc.FirstChildElement("RootElement");

        // �������� ������� ��������� ��������
        if (root) {
            std::cout << "�������� ������� ������." << std::endl;
            // ��������� ������� ��������� �������� � ������ "ChildElement"
            tinyxml2::XMLElement* child = root->FirstChildElement("ChildElement");

            // ����� ���� �������� ��������� � ������ "ChildElement"
            while (child) {
                std::cout << "�������� ������� ������." << std::endl;
                // ��������� �������� �������� � ������ "attribute_name"
                const char* value = child->Attribute("attribute_name");

                // �������� ������� �������� � ����� ��� ��������
                if (value) {
                    std::cout << "�������� ��������: " << value << std::endl;
                }
                else {
                    std::cout << "������� '���_��������' �� ������." << std::endl;
                }

                // ������� � ���������� ��������� �������� � ������ "ChildElement"
                child = child->NextSiblingElement("ChildElement");
            }
        }
        else {
            std::cout << "�������� ������� �� ������." << std::endl;
        }
    }
    else {
        std::cout << "�� ������� ��������� XML-����." << std::endl;
    }

    return 0;
}

#include"Func.h"
using namespace std;



int chooseMenu;
void Menu() {
	std::cout << "  1.���� ������ � ������������: " << std::endl;
	std::cout << "  2.�������� ������: " << std::endl;
	std::cout << "  3.��������������: " << std::endl;
	std::cout << "  4.������� ������������" << std::endl;
	std::cout << "  5.�������� ������������" << std::endl;
	std::cout << "  6.���������� " << std::endl;
	std::cout << "  7.�����" << std::endl;
	cin >> chooseMenu;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	DataInitalization();
	string FileName;

	Menu();

	while (chooseMenu != 7) {
		switch (chooseMenu)
		{
		case 1:
			system("CLS");
			DataEntry();
			system("PAUSE");
			system("CLS");
			Menu();
			break;
		case 2:
			system("CLS");
			OutData();
			system("PAUSE");
			system("CLS");
			Menu();
			break;
		case 3:
			system("CLS");
			EditData();
			system("PAUSE");
			system("CLS");
			Menu();
			break;
		case 4:
			system("CLS");
			DelUser();
			system("PAUSE");
			system("CLS");
			Menu();
			break;
		case 5:
			system("CLS");
			AddUser();
			system("PAUSE");
			system("CLS");
			Menu();
			break;
		case 6:
			system("CLS");
			cout << "������� �������� ����� � ������� ������ ��������� ������!" << endl;
			cin >> FileName;
			SaveData(FileName);
			system("PAUSE");
			system("CLS");
			Menu();
			break;
		default:
			cout << "��������� �������!!" << endl;
			break;

		}

	}

}




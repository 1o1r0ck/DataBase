#include"Func.h"
using namespace std;



int chooseMenu;
void Menu() {
	std::cout << "  1.Ввод данных о пользователе: " << std::endl;
	std::cout << "  2.Просмотр данных: " << std::endl;
	std::cout << "  3.Редактирование: " << std::endl;
	std::cout << "  4.Удалить пользователя" << std::endl;
	std::cout << "  5.Добавить пользователя" << std::endl;
	std::cout << "  6.Сохранение " << std::endl;
	std::cout << "  7.Выход" << std::endl;
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
			cout << "Введите название файла в который хотите сохранить Данные!" << endl;
			cin >> FileName;
			SaveData(FileName);
			system("PAUSE");
			system("CLS");
			Menu();
			break;
		default:
			cout << "Повторите попытку!!" << endl;
			break;

		}

	}

}




#include"Func.h"
#include<fstream>


void DataInitalization() {
	ofstream _dat("Data.txt");
	if (!_dat)
		cout << "Файл не создан!" << endl;
 
	_dat.close();
}

void DataEntry() {
	string name, surname;
	int number; // номер студака
	string gruppa; // номер группы
	int n;


	cout << "Введите количество пользователей, которых вы хотите зарегестрировать" << endl;
	cin >> n;


	ofstream write("Data.txt", ios::app);

	if (write) {
		write << n << endl;

		for (int i = 0; i < n; i++) {
			cout << "Введите имя: " << endl;
			cin >> name;

			cout << "Введите Фамилию: " << endl;
			cin >> surname;

			cout << "Введите номер студенческого билета: " << endl;
			cin >> number;

			cout << "Введите номер группы: " << endl;
			cin >> gruppa;

			write << name << endl;
			write << surname << endl;
			write << number << endl;
			if (i < n - 1)
				write << gruppa << endl;
			else
				write << gruppa;
			cout << "________________________________" << endl;

		}
	}

	else
		cout << "Ошибка открытия файла" << endl;

	write.close();
}

void OutData() {

	ifstream read("Data.txt");

	if (read) {
		string name, surname;
		int number; // номер студака
		string gruppa; // номер группы
		int n;

		read >> n;
		cout << "Количество пользователей: " << n << endl;

		for (int i = 0; i < n; i++) {
			cout << "Информация о пользователей - " << i + 1 << endl;
			read >> name;
			cout << "Имя: " << name << endl;
			read >> surname;
			cout << "Фамилия: " << surname << endl;
			read >> number;
			cout << "Номер Студенческого: " << number << endl;
			read >> gruppa;
			cout << "Номер группы: " << gruppa << endl;
			cout << "___________________" << endl;
		}
	}
	else
		cout << "Ошибка открытия файла" << endl;
	read.close();
}

void EditData() {
	Copy();

	ifstream read("DBuffer.txt");
	ofstream write("Data.txt", ios::out);

	if (read) {

		if (write) {
			string name, surname;
			int number; // номер студака
			string gruppa; // номер группы
			int n, Nn;

			read >> n;
			cout << "Выберите пользователя, данные которого вы хотите изменить." << endl;
			cout << "от 1 до " << n << endl;
			cin >> Nn;
			Nn--;

			write << n << endl;

			if (Nn >= 0 && Nn < n) {
				for (int i = 0; i < n; i++) {
					if (i != Nn) {
						read >> name;
						write << name << endl;

						read >> surname;
						write << surname << endl;

						read >> number;
						write << number << endl;


						read >> gruppa;
						write << gruppa << endl;
					}
					else {
						cout << "Введите имя: ";
						cin >> name;

						cout << "Введите фамилию: ";
						cin >> surname;

						cout << "Введите номер студенческого: ";
						cin >> number;

						cout << "Введите номер группы: ";
						cin >> gruppa;

						write << name << endl;
						write << surname << endl;
						write << number << endl;
						write << gruppa << endl;

						read >> name;
						read >> surname;
						read >> number;
						read >> gruppa;
					}


				}
				cout << "Новые данные внесены!!" << endl;

			}
			else
				cout << "Номер пользователя введен неверно!!" << endl;
		}
		else
			cout << "Ошибка открытия файла!!!" << endl;
	}
	else
		cout << "Ошибка открытия буфферного файла!!!" << endl;

	write.close();
	read.close();

}

void Copy() {
	ifstream read("Data.txt");
	ofstream write("DBuffer.txt", ios::out);

	if (read) {

		if (write) {
			string name, surname;
			int number; // номер студака
			string gruppa; // номер группы
			int n;
			read >> n;
			write << n << endl;

			for (int i = 0; i < n; i++) {
				read >> name;
				write << name << endl;

				read >> surname;
				write << name << endl;

				read >> number;
				write << name << endl;

				read >> gruppa;
				write << gruppa << endl;
			}
		}
		else
			cout << "Ошибка открытия файла!!!" << endl;
	}
	else
		cout << "Ошибка открытия буфферного файла!!!" << endl;

	write.close();
	read.close();
}

void DelUser() {

	Copy();
	ifstream read("DBuffer.txt");
	ofstream write("Data.txt", ios::out);

	if (read) {

		if (write) {
			string name, surname;
			int number; // номер студака
			string gruppa; // номер группы
			int n, Nn;

			read >> n;
			int b = n - 1;

			cout << "Выберите пользователя, данные которого вы хотите удалить." << endl;
			cout << "от 1 до " << n << endl;
			cin >> Nn;
			Nn--;

			write << b << endl;

			if (Nn >= 0 && Nn < n) {
				for (int i = 0; i < n; i++) {
					if (i != Nn) {
						read >> name;
						write << name << endl;

						read >> surname;
						write << surname << endl;

						read >> number;
						write << number << endl;


						read >> gruppa;
						if (i < n - 1)
							write << gruppa << endl;
						else
							write << gruppa;
					}
					else {
						read >> name;
						read >> surname;
						read >> number;
						read >> gruppa;
					}


				}
				cout << "Данные удалены!!" << endl;

			}
			else
				cout << "Номер пользователя введен неверно!!" << endl;
		}
		else
			cout << "Ошибка открытия файла!!!" << endl;
	}
	else
		cout << "Ошибка открытия буфферного файла!!!" << endl;

	write.close();
	read.close();


}

void AddUser() {

	string name, surname;
	int number; // номер студака
	string gruppa; // номер группы
	int n = DataAmount() + 1;

	ofstream write("Data.txt", ios::app);
	ofstream write_("Data.txt", ios::out | ios::in);
	if (write_) {
		write_ << n << endl;
	}
	else
		cout << "Ошибка открытия файла!!" << endl;
	if (write) {
		write << endl;

		cout << "Введите имя: " << endl;
		cin >> name;

		cout << "Введите Фамилию: " << endl;
		cin >> surname;

		cout << "Введите номер студенческого билета: " << endl;
		cin >> number;

		cout << "Введите номер группы: " << endl;
		cin >> gruppa;

		write << name << endl;
		write << surname << endl;
		write << number << endl;
		write << gruppa << endl;
	}
	else
		cout << "Ошибка открытия файла!!" << endl;

	write.close();
	write_.close();
}

int DataAmount() {
	ifstream _dat("Data.txt");
	int n;

	if (_dat) {
		_dat >> n;
	}
	else
		cout << "Ошибка открытия файла!!!" << endl;
	_dat.close();
	return n;
}

void SaveData(string FileName) {

	ifstream  read("Data.txt");
	ofstream write(FileName, ios::out);

	if (read) {
		if (write) {
			string name, surname;
			int number; // номер студака
			string gruppa; // номер группы
			int n;
			read >> n;
			write << n << endl;

			for (int i = 0; i < n; i++) {
				read >> name;
				write << name << endl;

				read >> surname;
				write << surname << endl;

				read >> number;
				write << number << endl;

				read >> gruppa;
				if (i < n - 1)
					write << gruppa << endl;
				else
					write << gruppa;
			}

			cout << "Данные сохранены в файле " << FileName << endl;
		}
		else
			cout << "Ошибка открытия файла!!! " << endl;
	}
	else 
		cout << "Ошибка открытия файла!!! " << endl;
	write.close();
	read.close();
}
#include"Func.h"
#include<fstream>


void DataInitalization() {
	ofstream _dat("Data.txt");
	if (!_dat)
		cout << "���� �� ������!" << endl;
 
	_dat.close();
}

void DataEntry() {
	string name, surname;
	int number; // ����� �������
	string gruppa; // ����� ������
	int n;


	cout << "������� ���������� �������������, ������� �� ������ ����������������" << endl;
	cin >> n;


	ofstream write("Data.txt", ios::app);

	if (write) {
		write << n << endl;

		for (int i = 0; i < n; i++) {
			cout << "������� ���: " << endl;
			cin >> name;

			cout << "������� �������: " << endl;
			cin >> surname;

			cout << "������� ����� ������������� ������: " << endl;
			cin >> number;

			cout << "������� ����� ������: " << endl;
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
		cout << "������ �������� �����" << endl;

	write.close();
}

void OutData() {

	ifstream read("Data.txt");

	if (read) {
		string name, surname;
		int number; // ����� �������
		string gruppa; // ����� ������
		int n;

		read >> n;
		cout << "���������� �������������: " << n << endl;

		for (int i = 0; i < n; i++) {
			cout << "���������� � ������������� - " << i + 1 << endl;
			read >> name;
			cout << "���: " << name << endl;
			read >> surname;
			cout << "�������: " << surname << endl;
			read >> number;
			cout << "����� �������������: " << number << endl;
			read >> gruppa;
			cout << "����� ������: " << gruppa << endl;
			cout << "___________________" << endl;
		}
	}
	else
		cout << "������ �������� �����" << endl;
	read.close();
}

void EditData() {
	Copy();

	ifstream read("DBuffer.txt");
	ofstream write("Data.txt", ios::out);

	if (read) {

		if (write) {
			string name, surname;
			int number; // ����� �������
			string gruppa; // ����� ������
			int n, Nn;

			read >> n;
			cout << "�������� ������������, ������ �������� �� ������ ��������." << endl;
			cout << "�� 1 �� " << n << endl;
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
						cout << "������� ���: ";
						cin >> name;

						cout << "������� �������: ";
						cin >> surname;

						cout << "������� ����� �������������: ";
						cin >> number;

						cout << "������� ����� ������: ";
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
				cout << "����� ������ �������!!" << endl;

			}
			else
				cout << "����� ������������ ������ �������!!" << endl;
		}
		else
			cout << "������ �������� �����!!!" << endl;
	}
	else
		cout << "������ �������� ���������� �����!!!" << endl;

	write.close();
	read.close();

}

void Copy() {
	ifstream read("Data.txt");
	ofstream write("DBuffer.txt", ios::out);

	if (read) {

		if (write) {
			string name, surname;
			int number; // ����� �������
			string gruppa; // ����� ������
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
			cout << "������ �������� �����!!!" << endl;
	}
	else
		cout << "������ �������� ���������� �����!!!" << endl;

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
			int number; // ����� �������
			string gruppa; // ����� ������
			int n, Nn;

			read >> n;
			int b = n - 1;

			cout << "�������� ������������, ������ �������� �� ������ �������." << endl;
			cout << "�� 1 �� " << n << endl;
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
				cout << "������ �������!!" << endl;

			}
			else
				cout << "����� ������������ ������ �������!!" << endl;
		}
		else
			cout << "������ �������� �����!!!" << endl;
	}
	else
		cout << "������ �������� ���������� �����!!!" << endl;

	write.close();
	read.close();


}

void AddUser() {

	string name, surname;
	int number; // ����� �������
	string gruppa; // ����� ������
	int n = DataAmount() + 1;

	ofstream write("Data.txt", ios::app);
	ofstream write_("Data.txt", ios::out | ios::in);
	if (write_) {
		write_ << n << endl;
	}
	else
		cout << "������ �������� �����!!" << endl;
	if (write) {
		write << endl;

		cout << "������� ���: " << endl;
		cin >> name;

		cout << "������� �������: " << endl;
		cin >> surname;

		cout << "������� ����� ������������� ������: " << endl;
		cin >> number;

		cout << "������� ����� ������: " << endl;
		cin >> gruppa;

		write << name << endl;
		write << surname << endl;
		write << number << endl;
		write << gruppa << endl;
	}
	else
		cout << "������ �������� �����!!" << endl;

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
		cout << "������ �������� �����!!!" << endl;
	_dat.close();
	return n;
}

void SaveData(string FileName) {

	ifstream  read("Data.txt");
	ofstream write(FileName, ios::out);

	if (read) {
		if (write) {
			string name, surname;
			int number; // ����� �������
			string gruppa; // ����� ������
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

			cout << "������ ��������� � ����� " << FileName << endl;
		}
		else
			cout << "������ �������� �����!!! " << endl;
	}
	else 
		cout << "������ �������� �����!!! " << endl;
	write.close();
	read.close();
}
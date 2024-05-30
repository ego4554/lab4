#include "file_reader.h"
#include "filter.h"
#include <Windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    exchange_rate* rate[100];
    int size;
    try
    {
        read_file("data.txt", rate, size);
        for (int i = 0; i < size; i++)
        {
            cout << "����: ";
            cout << rate[i]->some_bank.bank_name << "\n�������/�������:\n" << rate[i]->bying.some_oper << " " << rate[i]->selling.some_oper;
            cout << "\n����� �����: " << rate[i]->some_address.bank_address <<"\n\n";
        }
        bank* temp = new bank;
        cout << "�������� ���� ����: ";
        cin >> temp->bank_name;
        only_one_bank(rate, *temp, size);
        cout << "�������� ����� ������� ������� ������: ";
        operations* otemp = new operations;
        cin >> otemp->some_oper;
        better_value(rate, *otemp, size);
        for (int i = 0; i < size; i++)
        {
            delete rate[i];
        }
        delete temp, otemp;
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
	return 0;
}
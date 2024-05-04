#include <iostream>
#include <algorithm>
#include <sstream>
#include <windows.h>
#include <vector>

using namespace std;

int Menu( const int low, const int high, const string &mes );
int GetNaturalNumber( const int low, const int high, const string &mes = "" );
template< typename T >
void GetValueIn( T &value, const string &mes = "" );//функция проверки ввода(шаблонная функция)
void PrintVec( const vector< int > &vec );

int main() {
     SetConsoleCP( 1251 );
    SetConsoleOutputCP( 1251 );
	vector< int > iVec;

	while ( true ) {
		int key = Menu( 0, 5, "Выберите пункт" );

		if ( !key )
			break;

		switch ( key ) {

		case 1: {
			int val;
			cout << "\nВведите элемент вектора для добавления: ";
			GetValueIn( val );
			iVec.push_back( val ); // добавляем ОДИН элемент в конец вектора с помощью метода erase
			break;
		}
		case 2: {
			int val;
			cout << "\nВведите элемент для удаления из вектора: ";
			GetValueIn( val );
			// ищем элемент в векторе и запоминаем положение в итератор
			vector< int >::iterator it = find( iVec.begin(), iVec.end(), val ); // функция find ищет элемент
			// если итератор it имеет значение НЕ end(), то значит нашли элемент для удаления
			if ( it != iVec.end() ) {
				iVec.erase( it ); // удаляем ОДИН ПЕРВЫЙ ПОПАВШИЙСЯ искомый элемент
				cout << "\nЭлемент успешно удалён" << endl;
			} else
				cout << "\nИскомый элемент НЕ найден в векторе!" << endl;
			break;
		}

		case 3: {
			PrintVec( iVec );
			cout << endl;
			break;
		}

		case 4: {

			if ( iVec.size() ) {
				int ind = GetNaturalNumber( 0, iVec.size() - 1, "Введите ИНДЕКС для удаления элемента из вектора: " );
				iVec.erase( iVec.begin() + ind );

			}

			else
				cout << "Вектор пустой" << endl;

			break;
		}
			case 5: {
			if ( iVec.size() ) {
				iVec.pop_back();
				cout << "Последний элемент удалён!" << endl;
			} else
				cout << "Вектор пустой" << endl;
			break;
		}

		}
	}

	return 0;
}

int Menu( const int low, const int high, const string &mes = "" ) {

	cout << "1 - Добавить элемент в вектор\n";
	cout << "2 - Удалить элемент по значению\n";
	cout << "3 - Вывести вектор\n";
	cout << "4 - Удалить по индексу\n";
	cout << "5 - удалить последний\n";

	cout << "0 - выход" << endl;

	int key = GetNaturalNumber( low, high, mes );

	return key;

}
int GetNaturalNumber( const int low, const int high, const string &mes ) {
	string nStr;
	int n;
	while ( true ) {
		cout << mes << " от " << low << " до " << high << ": ";
		getline( cin, nStr ); // считываем строку неограниченной длины, до нажатия Enter
		// пробуем найти ЛЮБОЙ символ, НЕ входящий в набор 0123456789
		if ( nStr.find_first_not_of( "0123456789" ) == string::npos ) { // если НЕ нашли, то введено целое число
			stringstream ss;
			ss << nStr; // отдаём строковому потоку строку, которая представляет собой запись целого полоительного числа
			ss >> n; // просим строковый поток вернуть нам int значение
			if ( n >= low && n <= high )
				break;
		}
		cout << "Ошибка ввода! Значение должно быть " << "от " << low << " до " << high << "!" << endl;
	}
	return n;
}

template< typename T >
void GetValueIn( T &value, const string &mes ) {
	bool flag;
	cout << mes;
	do {
		cin >> value;
		flag = true;
		if ( !cin ) {
			flag = false;
			cin.clear();
		}
		string input;
		getline( cin, input );
		if ( input.find_first_not_of( " " ) != string::npos )
			flag = false;
		if ( !flag )
			cout << "Неверно введено число! Повторите ввод: ";
	} while ( !flag );
}

void PrintVec( const vector< int > &vec ) {

	for ( auto &elem : vec )
		cout << elem << " ";
}

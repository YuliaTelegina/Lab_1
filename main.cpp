#include <iostream>
#include <algorithm>
#include <sstream>
#include <windows.h>
#include <vector>

using namespace std;

int Menu( const int low, const int high, const string &mes );
int GetNaturalNumber( const int low, const int high, const string &mes = "" );
template< typename T >
void GetValueIn( T &value, const string &mes = "" );//������� �������� �����(��������� �������)
void PrintVec( const vector< int > &vec );

int main() {
     SetConsoleCP( 1251 );
    SetConsoleOutputCP( 1251 );
	vector< int > iVec;

	while ( true ) {
		int key = Menu( 0, 5, "�������� �����" );

		if ( !key )
			break;

		switch ( key ) {

		case 1: {
			int val;
			cout << "\n������� ������� ������� ��� ����������: ";
			GetValueIn( val );
			iVec.push_back( val ); // ��������� ���� ������� � ����� ������� � ������� ������ erase
			break;
		}
		case 2: {
			int val;
			cout << "\n������� ������� ��� �������� �� �������: ";
			GetValueIn( val );
			// ���� ������� � ������� � ���������� ��������� � ��������
			vector< int >::iterator it = find( iVec.begin(), iVec.end(), val ); // ������� find ���� �������
			// ���� �������� it ����� �������� �� end(), �� ������ ����� ������� ��� ��������
			if ( it != iVec.end() ) {
				iVec.erase( it ); // ������� ���� ������ ���������� ������� �������
				cout << "\n������� ������� �����" << endl;
			} else
				cout << "\n������� ������� �� ������ � �������!" << endl;
			break;
		}

		case 3: {
			PrintVec( iVec );
			cout << endl;
			break;
		}

		case 4: {

			if ( iVec.size() ) {
				int ind = GetNaturalNumber( 0, iVec.size() - 1, "������� ������ ��� �������� �������� �� �������: " );
				iVec.erase( iVec.begin() + ind );

			}

			else
				cout << "������ ������" << endl;

			break;
		}
			case 5: {
			if ( iVec.size() ) {
				iVec.pop_back();
				cout << "��������� ������� �����!" << endl;
			} else
				cout << "������ ������" << endl;
			break;
		}

		}
	}

	return 0;
}

int Menu( const int low, const int high, const string &mes = "" ) {

	cout << "1 - �������� ������� � ������\n";
	cout << "2 - ������� ������� �� ��������\n";
	cout << "3 - ������� ������\n";
	cout << "4 - ������� �� �������\n";
	cout << "5 - ������� ���������\n";

	cout << "0 - �����" << endl;

	int key = GetNaturalNumber( low, high, mes );

	return key;

}
int GetNaturalNumber( const int low, const int high, const string &mes ) {
	string nStr;
	int n;
	while ( true ) {
		cout << mes << " �� " << low << " �� " << high << ": ";
		getline( cin, nStr ); // ��������� ������ �������������� �����, �� ������� Enter
		// ������� ����� ����� ������, �� �������� � ����� 0123456789
		if ( nStr.find_first_not_of( "0123456789" ) == string::npos ) { // ���� �� �����, �� ������� ����� �����
			stringstream ss;
			ss << nStr; // ����� ���������� ������ ������, ������� ������������ ����� ������ ������ ������������� �����
			ss >> n; // ������ ��������� ����� ������� ��� int ��������
			if ( n >= low && n <= high )
				break;
		}
		cout << "������ �����! �������� ������ ���� " << "�� " << low << " �� " << high << "!" << endl;
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
			cout << "������� ������� �����! ��������� ����: ";
	} while ( !flag );
}

void PrintVec( const vector< int > &vec ) {

	for ( auto &elem : vec )
		cout << elem << " ";
}

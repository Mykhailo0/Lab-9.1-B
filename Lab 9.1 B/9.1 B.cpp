#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Spec { КН, ІНФ, МТЕ, ФТІ, ТН };
string specStr[] = { "КН", "ІНФ", "МТЕ", "ФТІ", "ТН" };

struct Student
{
	string prizv;
	unsigned physics;
	unsigned math;
	unsigned kurs;
	Spec spec;
	union
	{
		unsigned prog;
		unsigned chuslo;
		unsigned ped;
	};
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
int Physics(Student* p, const int N);
int Math(Student* p, const int N);
int Physics_Math(Student* p, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "Введіть N: "; cin >> N;
	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);

	int Number1 = Physics(p, N);
	cout << "кількість оцінок задовільно з фізики:" << Number1 << endl;
	int Number2 = Math(p, N);
	cout << "кількість оцінок задовільно з математики:" << Number2 << endl;

	int Number3 = Physics_Math(p, N);
	cout << "кількість студентів з задовільними оцінками з фіз. та мат.:" << Number3 << endl;

	return 0;
}

void Create(Student* p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " курс: "; cin >> p[i].kurs;
		cout << " спеціальність (0 - КН, 1 - ІНФ, 2 - МТЕ, 3 - ФТІ, 4 - ТН): ";
		cin >> spec;
		p[i].spec = (Spec)spec;
		cout << " оцінка з фізики: "; cin >> p[i].physics;
		cout << " оцінка з математики: "; cin >> p[i].math;
		switch (p[i].spec)
		{
		case КН:
			cout << " оцінка з програмування: "; cin >> p[i].prog;
			break;
		case ІНФ:
			cout << " оцінка з чисельних методів: "; cin >> p[i].chuslo;
			break;
		case МТЕ:
		case ФТІ:
		case ТН:
			cout << " оцінка з педагогіки: "; cin >> p[i].ped;
			break;
		}
		cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "==============================================================================================================="
		<< endl;
	cout << "|  № |   прізвище   |  курс |  спец. |  фіз. |  мат. |  прог. | числ. |  педг. |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(13) << right << p[i].prizv
			<< "| " << setw(5) << right << p[i].kurs << " "
			<< "| " << setw(7) << right << specStr[p[i].spec]
			<< "| " << setw(5) << right << p[i].physics << " "
			<< "| " << setw(5) << right << p[i].math << " ";

		switch (p[i].spec)
		{
		case КН:
			cout << "| " << setw(6) << right << p[i].prog << " " << "| " << setw(8) << "| " << setw(8);
			break;
		case ІНФ:
			cout << "| " << setw(9) << "| " << setw(5) << right << p[i].chuslo << " " << "| " << setw(8);
			break;
		case МТЕ:
		case ФТІ:
		case ТН:
			cout << "| " << setw(9) << "| " << setw(8) << "| " << setw(6) << right << p[i].ped << " ";
			break;
		}
		cout << "|"
			<< endl;
	}
	cout << "==============================================================================================================="
		<< endl;
	cout << endl;
}


int Physics(Student* p, const int N)
{
	int n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].physics == 3)
			n++;
	}
	return n;
}
int Math(Student* p, const int N)
{
	int n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].math == 3)
			n++;
	}
	return n;
}
int Physics_Math(Student* p, const int N)
{
	int students = 0;

	for (int i = 0; i < N; i++) {
		if ((p[i].physics == 5 && p[i].math == 4) &&
			(p[i].math == 5 && p[i].physics == 4)) {
			students++;
		}
	}
	return students;
}
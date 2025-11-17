/*
´
*/

#include <iostream>
using namespace std;

class Student 
{
public:
    Student(string name, int anzahlNoten) {
        this->name = name;
        this->anzahlNoten = anzahlNoten;
        grades = new float[anzahlNoten];
    }

    void Noten()
    {
        for (int i = 0; i < anzahlNoten; i++)
        {
            cout << "Note " << i + 1 << ": " << endl;
            cin >> grades[i];
            summ = summ + grades[i];
        }
        average = (float)summ / anzahlNoten;
    }

    void free()
    {
        delete[] grades;
    }

    string name;
private:
    int anzahlNoten;
    float average = 0;
    float* grades;
    int summ = 0;

};

void erstelleStundenten(Student** students, int anzahl_students)
{
    string name;
    int anzahl_Noten = 0;

    for (int i = 0; i < anzahl_students; i++)
    {
        cout << " Name von Student " << i + 1 << endl;
        cin >> name;

        cout << "Anzahl der Noten von " << name << ": " << endl;
        cin >> anzahl_Noten;

        students[i] = new Student(name, anzahl_Noten);
        students[i]->Noten();
    }
}

void free(Student** students, int anzahl_students)
{
    for (int i = 0; i < anzahl_students; i++)
    {
        students[i]->free();
        delete(students[i]);
    }

    delete[] students;
}

int main()
{
    int anzahl_students = 0;

    cout << "Anzahl der Studenten: " << endl;
    cin >> anzahl_students;

    Student** students = new Student * [anzahl_students];

    erstelleStundenten(students, anzahl_students);
    cout << "Name: " << students[0]->name;
    free(students, anzahl_students);
}


//Lösung von Trainer:

//#include <iostream>
//using namespace std;
//
//
//class Student {
//public:
//    Student(string name, int anzahlNoten) {
//        this->name = name;
//        this->anzahlNoten = anzahlNoten;
//        grades = new float[anzahlNoten];
//    }
//
//    void Noten()
//    {
//        for (int i = 0; i < anzahlNoten; i++)
//        {
//            cout << "Note " << i + 1 << ": " << endl;
//            cin >> grades[i];
//            summ = summ + grades[i];
//        }
//        average = (float)summ / anzahlNoten;
//    }
//
//    ~Student() {
//        delete[] grades;
//    }
//
//
//private:
//    string name;
//    int anzahlNoten;
//    float average = 0;
//    float* grades;
//    int summ = 0;
//
//};
//
//Student** readstudent(int anzahl_students);
//void free(Student** students, int anzahl_students);
//
//
//Student** readstudent(int anzahl_students)
//{
//
//    Student** students = new Student * [anzahl_students];
//
//    string name;
//    int anzahl_Noten;
//
//    for (int i = 0; i < anzahl_students; i++)
//    {
//        cout << " Name von Student " << i + 1 << endl;
//        cin >> name;
//
//        cout << "Anzahl der Noten von " << name << ": " << endl;
//        cin >> anzahl_Noten;
//
//        students[i] = new Student(name, anzahl_Noten);
//        students[i]->Noten();
//    }
//
//    return students;
//
//}
//
//void free(Student** students, int anzahl_students)
//{
//    for (int i = 0; i < anzahl_students; i++)
//    {
//        delete(students[i]);
//    }
//
//    delete[] students;
//}
//
//
//int main()
//{
//
//    int anzahl_students = 0;
//    int anzahl_Noten = 0;
//
//    cout << "Anzahl der Studenten: " << endl;
//    cin >> anzahl_students;
//
//    Student** students = readstudent(anzahl_students);
//
//    free(students);
//}

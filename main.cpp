#include <iomanip>
#include <ios>
#include <iostream>
#include <String>
#include <vector>
#include <algorithm>



using namespace std;

int main()
{
    typedef vector<double>::size_type vec_sz;
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << "Please enter your midterm and final grades: ";
    double midterm, final;
    cin >> midterm >> final;

    cout << "Enter all your homework grades, "
            "followed by end_of_file: ";

    vector<double> homework;
    double x;
    while (cin >> x) {
        homework.push_back(x);
    }
    sort(homework.begin(), homework.end());
    vec_sz size = homework.size();
    if (size == 0) {
        cout << endl << "You must enter your homework grades."
                    << "Please try again. " << endl;
        return 1;
    }
    streamsize prec = cout.precision();
    vec_sz mid = size/2;
    double median;
    median = size % 2 == 0 ? homework[mid] / 2 + homework[mid+1] / 2 :
             homework[mid];
    cout << "Your final grade is " << setprecision(3)
            << 0.2 * midterm + 0.4 * final + 0.4 * median
            <<setprecision(prec) << endl;

    return 0;
}
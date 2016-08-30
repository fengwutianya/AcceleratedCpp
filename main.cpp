#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>       //vector
#include <algorithm>    //sort
#include <stdexcept>    //domain_error extends from exception


using namespace std;

double median(vector<double>);
double grade(double midterm, double final, const vector<double>& hw);

int main()
{
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
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
            << grade(midterm, final, homework)
            <<setprecision(prec) << endl;

    return 0;
}

double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0) {
        throw domain_error("median of an empty vector.");
    }
    sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;

    return size % 2 == 0 ? (vec[mid] + vec[mid + 1]) / 2 : vec[mid];
}

double grade(double midterm, double final, double median)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * median;
}

double grade(double midterm, double final, const vector<double>& hw)
{
    if (hw.size() == 0) {
        throw domain_error("student has done no homework!");
    }
    return grade(midterm, final, median(hw));
}
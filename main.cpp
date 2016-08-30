#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>       //vector
#include <algorithm>    //sort
#include <stdexcept>    //domain_error extends from exception


using namespace std;

double median(vector<double>);
double grade(double midterm, double final, const vector<double>& hw);
istream& read_hw(istream& in, vector<double>& hw);

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
    read_hw(cin, homework);
    try {
        //可能抛出异常的语句最好独立出来，不然中间发生错误
        //准则是每个语句副作用不超过一个，这里改变输出和抛出异常都属于副作用
        double final_grade = grade(midterm, final, homework);
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3)
        << final_grade
        <<setprecision(prec) << endl;
    } catch (domain_error) {        //throw exception的时候保证程序能够完整结束
                                    //否则windows上进程死
        cout << endl << "You must enter your homework grades"
            << "Please try again." << endl;
        return 1;
    }

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

istream& read_hw(istream& in, vector<double>& hw)       //istream不能被复制，因此参数必须要引用
{
    if (in) {
        hw.clear();     //使用的是引用，可更改，里面可能有我们不想要的东东
        double x;
        while (in >> x) {   //in错误的时候退出循环，此时要清理错误状态in.clear()
            hw.push_back(x);
        }
        in.clear();     //ready for the next student.
    }
    return in;
}
//
// Created by xuan on 2016/8/31.
//
#include "Student_info.h"
#include <iostream>
#include <vector>

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

std::istream& read(std::istream& is, Student_info& s)
{
    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework);
    return is;
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw)       //istream不能被复制，因此参数必须要引用
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
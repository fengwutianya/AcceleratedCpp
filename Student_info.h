//
// Created by xuan on 2016/8/31.
//

#ifndef ACCELERATEDCPP_STUDENT_INFO_H
#define ACCELERATEDCPP_STUDENT_INFO_H

#include <vector>
#include <iostream>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info& x, const Student_info& y);
std::istream& read(std::istream& is, Student_info& s);
std::istream& read_hw(std::istream& in, std::vector<double>& hw);


#endif //ACCELERATEDCPP_STUDENT_INFO_H

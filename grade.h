//
// Created by xuan on 2016/8/31.
//

#ifndef ACCELERATEDCPP_GRADE_H
#define ACCELERATEDCPP_GRADE_H

#include <vector>
#include "Student_info.h"
double grade(const Student_info& s);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(double midterm, double final, double median);

#endif //ACCELERATEDCPP_GRADE_H

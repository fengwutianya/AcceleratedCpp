//
// Created by xuan on 2016/8/31.
//
#include "grade.h"
#include "median.h"
#include "Student_info.h"
#include <vector>
#include <stdexcept>

double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}

double grade(double midterm, double final, const std::vector<double>& hw)
{
    if (hw.size() == 0) {
        throw std::domain_error("student has done no homework!");
    }
    return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double median)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * median;
}

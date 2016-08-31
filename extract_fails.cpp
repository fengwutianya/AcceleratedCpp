//
// Created by xuan on 2016/8/31.
//

#include "Student_info.h"
#include "grade.h"
#include "extract_fails.h"
#include <vector>

bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

std::vector<Student_info> extract_fails(std::vector<Student_info>& students)
{
    std::vector<Student_info> fail;

    std::vector<Student_info>::size_type i = 0;
    while (i != students.size()) {
        if (fgrade(students[i])) {
            fail.push_back(students[i]);
            students.erase(students.begin() + i);
        }
        else
            ++i;
    }
    return fail;
}

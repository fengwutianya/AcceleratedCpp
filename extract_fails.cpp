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
    std::vector<Student_info> pass, fail;

    for (std::vector<Student_info>::size_type i = 0;
         i != students.size(); ++i) {
        if (fgrade(students[i]))
            fail.push_back(students[i]);
        else
            pass.push_back(students[i]);
    }
    students = pass;
    return fail;
}

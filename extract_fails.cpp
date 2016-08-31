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

    std::vector<Student_info>::iterator iter = students.begin();
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);    //删除操作使iter失效
                                            //erase返回新值
                                            //vector此处和以后的iterator全部失效
        }
        else
            ++iter;
    }
    return fail;
}

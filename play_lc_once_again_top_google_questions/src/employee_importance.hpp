#ifndef __employee_importance_HPP_INCLUDED__
#define __employee_importance_HPP_INCLUDED__

#include <vector>

/*
	https://leetcode.com/problems/employee-importance/


You are given a data structure of employee information,
which includes the employee's unique id, their importance value and their direct subordinates' id.

For example,
	employee 1 is the leader of employee 2,
	and employee 2 is the leader of employee 3.
	They have importance value 15, 10 and 5, respectively.
	Then employee 1 has a data structure like [1, 15, [2]],
	and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []].
	Note that although employee 3 is also a subordinate of employee 1, the relationship is not direct.

Now given the employee information of a company, and an employee id,
you need to return the total importance value of this employee and all their subordinates.

Example 1:

Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
Output: 11
Explanation:
Employee 1 has importance value 5, and he has two direct subordinates:
employee 2 and employee 3. They both have importance value 3.
So the total importance value of employee 1 is 5 + 3 + 3 = 11.


Note:

One employee has at most one direct leader and may have several subordinates.
The maximum number of employees won't exceed 2000.
Accepted
102,868
Submissions
175,226
*/
namespace lc
{

    typedef int type_employee_id_t;
    typedef int type_importance_t;
    typedef std::vector<type_importance_t> type_subordinates_list_t;
    typedef std::pair<type_importance_t, type_subordinates_list_t> type_employee_map_value_t;
    typedef std::pair<type_employee_id_t, type_employee_map_value_t> type_employee_map_key_value_t;
    typedef std::unordered_map< type_employee_id_t, type_employee_map_value_t > type_employee_map_t;

    // Definition for Employee.
    class Employee
    {

    public:
    	Employee(int id_, int importance_, std::vector<int> v_ )
    	{
    		id = id_;
    		importance = importance_;
    		subordinates = v_;
    	}
        int id;
        int importance;
        std::vector<int> subordinates;
    };

    int dfs(type_employee_map_t &employees, int id) ;
    int getImportance(std::vector<Employee *> employees, int id) ;
}

#endif

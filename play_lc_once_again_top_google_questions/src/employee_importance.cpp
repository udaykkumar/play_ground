#include <employee_importance.hpp>

namespace lc
{
	int getImportance(std::vector<Employee *> employees, int id)
	{
		int importance = employees[id]->importance;
		if( employees[id]->subordinates.size() > 0 ) {
			for( auto sid : employees[id]->subordinates ) {
				importance += getImportance( employees, sid );
			}	
		}
		
		return importance;
	}
}


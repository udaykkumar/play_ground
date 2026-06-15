/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
   
public:
   typedef int type_employee_id_t;
	typedef int type_importance_t;
	typedef std::vector<type_importance_t> type_subordinates_list_t;
	typedef std::pair<type_importance_t, type_subordinates_list_t> type_employee_map_value_t;
    typedef std::pair<type_employee_id_t, type_employee_map_value_t> type_employee_map_key_value_t;
	typedef std::unordered_map< type_employee_id_t, type_employee_map_value_t > type_employee_map_t;

		
	int getImportance(std::vector<Employee *> employees, int id)
	{
		type_employee_map_t emap;
		for ( auto e : employees )
		{
			auto k = e->id;
			type_employee_map_value_t val( e->importance, e->subordinates );
	    	emap.insert(type_employee_map_key_value_t(k, val));
		}
		return dfs(emap, id);
	}

	int dfs(type_employee_map_t &emap, int id)
	{
		auto kvp = emap.find(id);
		auto e  = kvp->second;
		int i = e.first;
		auto s = e.second;
		if( s.size() > 0 ) {
			for( auto sid : s ) {
				i += dfs( emap, sid );
			}	
		}
		return i;
	}
};
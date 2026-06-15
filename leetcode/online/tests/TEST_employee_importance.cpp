#include <employee_importance.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_employee_importance )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	std::vector<lc::Employee*> employees;
	employees.push_back(new lc::Employee(1, 5, std::vector<int>(
	{ 2, 3 })));
	employees.push_back(new lc::Employee(2, 3, std::vector<int>()));
	employees.push_back(new lc::Employee(3, 3, std::vector<int>()));

	BOOST_CHECK(lc::getImportance(employees, 1) == 11);

}
BOOST_AUTO_TEST_SUITE_END()


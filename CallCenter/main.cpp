#include <iostream>
#include <vector>
#include <unordered_map>
#include "Employee.h"
#include "CallCenter.h"

namespace {
	const int NUM_RESPONDENTS = 10;
	const int NUM_MANAGERS = 4;
	const int NUM_DIRECTORS = 2;

	static int employeeId = 1;

	std::unordered_map <Role, int> numEmployeesMap = { { Role::Respondent, NUM_RESPONDENTS }, { Role::Manager, NUM_MANAGERS }, { Role::Director, NUM_DIRECTORS } };

	void registerEmployees(std::vector<Employee>& employees) {
		for (const auto& [role, numEmployees] : numEmployeesMap) {
			for (int i = 0; i < numEmployees; i++) {
				employees.push_back(Employee(employeeId++, role));
			}
		}
	}
}

int main() {
    std::vector<Employee> employees;
	registerEmployees(employees);

	CallCenter callCenter(employees);

	callCenter.addWaitingCall();
	Employee* employee = callCenter.dispatchCall();

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Employee.h"
#include "CallCenter.h"

namespace {
	static int employeeId = 1;

	void registerEmployees(const std::unordered_map <Role, int>& numEmployeesMap, std::vector<Employee>& employees) {
		for (const auto& [role, numEmployees] : numEmployeesMap) {
			for (int i = 0; i < numEmployees; i++) {
				employees.push_back(Employee(employeeId++, role));
			}
		}
	}
}

int main() {
	const int NUM_RESPONDENTS = 10;
	const int NUM_MANAGERS = 4;
	const int NUM_DIRECTORS = 2;

	std::unordered_map <Role, int> numEmployeesMap = { { Role::Respondent, NUM_RESPONDENTS }, { Role::Manager, NUM_MANAGERS }, { Role::Director, NUM_DIRECTORS } };
    std::vector<Employee> employees;
	registerEmployees(numEmployeesMap, employees);

    CallCenter callCenter(employees);

	callCenter.addWaitingCall();
	if (callCenter.getNumWaitingCalls() > 0) {
		Employee* employee = callCenter.dispatchCall();
		if (employee) {
			std::cout << "Call connected to employee ID: " << employee->getId() << std::endl;
		} else {
			std::cout << "No available employees to take the call." << std::endl;
		}
	}

    return 0;
}
#include <iostream>
#include <vector>
#include "Employee.h"
#include "CallCenter.h"

namespace {
    const int NUM_RESPONDENTS = 1;
    const int NUM_MANAGERS = 4;
    const int NUM_DIRECTORS = 2;

	void registerEmployee(std::vector<Employee>& employees, Role role, int& id) {
		int numEmployees = 0;
		switch (role) {
			case Role::Respondent:
				numEmployees = NUM_RESPONDENTS;
				break;
			case Role::Manager:
				numEmployees = NUM_MANAGERS;
				break;
			case Role::Director:
				numEmployees = NUM_DIRECTORS;
				break;
		}

		for (int i = 0; i < numEmployees; i++) {
			employees.push_back(Employee(id++, role));
		}
	}

	void registerEmployees(std::vector<Employee>& respondents, std::vector<Employee> managers, std::vector<Employee> directors) {
		int id = 1;
		registerEmployee(respondents, Role::Respondent, id);
		registerEmployee(managers, Role::Manager, id);
		registerEmployee(directors, Role::Director, id);
	}
}

int main() {
    std::vector<Employee> respondents;
    std::vector<Employee> managers;
    std::vector<Employee> directors;
	registerEmployees(respondents, managers, directors);

    CallCenter callCenter(respondents, managers, directors);

    Employee* employee = callCenter.dispatchCall();
    if (employee) {
        std::cout << "Call connected to employee ID: " << employee->getId() << std::endl;
    } else {
        std::cout << "No available employees to take the call." << std::endl;
    }

    return 0;
}
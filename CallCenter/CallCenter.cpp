#include "CallCenter.h"
#include "Employee.h"
#include <iostream>

CallCenter::CallCenter(const std::vector<Employee>& employees) : numWaitingCalls(0) {
	for (const auto& employee : employees) {
		Role role = employee.getRole();
		if (respondents.find(role) == respondents.end()) {
			respondents[role] = std::queue<Employee>();
		}
		respondents[role].push(employee);
	}
}

Employee* CallCenter::dispatchCall() {
	if (numWaitingCalls <= 0) {
		std::cout << "No waiting calls" << std::endl;
		return nullptr;
	}

	for (auto& [role, employees] : respondents) {
		if (!employees.empty() && employees.front().isAvailable()) {
			Employee* employee = &employees.front();
			employee->setIsAvailable(false);
			employees.pop();
			numWaitingCalls--;
			std::cout << "Call connected to employee ID: " << employee->getId() << std::endl;
			return employee;
		}
	}

	std::cout << "No available employees" << std::endl;
	return nullptr;
}

void CallCenter::completeCall(Employee& employee)
{
	employee.setIsAvailable(true);
	respondents[employee.getRole()].push(employee);
}

void CallCenter::addWaitingCall(int numCalls) {
	numWaitingCalls += numCalls;
}

void CallCenter::addRespondent(const Employee& employee) {
	respondents[employee.getRole()].push(employee);
}
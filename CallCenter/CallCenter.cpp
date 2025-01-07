#include "CallCenter.h"

CallCenter::CallCenter(const std::vector<Employee>& employees) : numWaitingCalls(0) {
	for (const auto& employee : employees) {
		switch (employee.getRole()) {
			case Role::Respondent:
				respondents.push(employee);
				break;
			case Role::Manager:
				managers.push(employee);
				break;
			case Role::Director:
				directors.push(employee);
				break;
		}
	}
}

Employee* CallCenter::dispatchCall() {
    if (!respondents.empty() && respondents.front().isAvailable()) {
        Employee* employee = &respondents.front();
        employee->setIsAvailable(false);
        respondents.pop();
		numWaitingCalls--;
        return employee;
    } else if (!managers.empty() && managers.front().isAvailable()) {
        Employee* employee = &managers.front();
        employee->setIsAvailable(false);
        managers.pop();
		numWaitingCalls--;
        return employee;
    } else if (!directors.empty() && directors.front().isAvailable()) {
        Employee* employee = &directors.front();
        employee->setIsAvailable(false);
        directors.pop();
		numWaitingCalls--;
        return employee;
    } else {
        return nullptr; // No available employees
    }
}

void CallCenter::completeCall(Employee& respondent)
{
	respondent.setIsAvailable(true);
	switch (respondent.getRole()) {
		case Role::Respondent:
			respondents.push(respondent);
			break;
		case Role::Manager:
			managers.push(respondent);
			break;
		case Role::Director:
			directors.push(respondent);
			break;
	}
}

void CallCenter::addWaitingCall(int numCalls) {
	numWaitingCalls += numCalls;
}

int CallCenter::getNumWaitingCalls() const {
	return numWaitingCalls;
}

void CallCenter::addRespondent(const Employee& respondent) {
	switch (respondent.getRole()) {
	case Role::Respondent:
		respondents.push(respondent);
		break;
	case Role::Manager:
		managers.push(respondent);
		break;
	case Role::Director:
		directors.push(respondent);
		break;
	}
}
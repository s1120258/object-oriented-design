#include "CallCenter.h"

CallCenter::CallCenter(const std::vector<Employee>& respondents, const std::vector<Employee>& managers, const std::vector<Employee>& directors) : numWaitingCalls(0) {
	for (const auto& respondent : respondents) {
		this->respondents.push(respondent);
	}
	for (const auto& manager : managers) {
		this->managers.push(manager);
	}
	for (const auto& director : directors) {
		this->directors.push(director);
	}
}

Employee* CallCenter::dispatchCall() {
    if (!respondents.empty() && respondents.front().isAvailable()) {
        Employee* employee = &respondents.front();
        employee->setIsAvailable(false);
        respondents.pop();
        return employee;
    } else if (!managers.empty() && managers.front().isAvailable()) {
        Employee* employee = &managers.front();
        employee->setIsAvailable(false);
        managers.pop();
        return employee;
    } else if (!directors.empty() && directors.front().isAvailable()) {
        Employee* employee = &directors.front();
        employee->setIsAvailable(false);
        directors.pop();
        return employee;
    } else {
		numWaitingCalls++;
        return nullptr; // No available employees
    }
}

void CallCenter::completedCall(Employee& respondent)
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
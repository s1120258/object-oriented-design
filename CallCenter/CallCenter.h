#ifndef CALLCENTER_H
#define CALLCENTER_H

#include <queue>
#include <vector>
#include "Employee.h"

class CallCenter {
public:
    CallCenter(const std::vector<Employee>& respondents, const std::vector<Employee>& managers, const std::vector<Employee>& directors);

    Employee* dispatchCall();
    void completedCall(Employee& employee);
    void addRespondent(const Employee& respondent);

private:
	std::queue<Employee> respondents;
    std::queue<Employee> managers;
    std::queue<Employee> directors;

	int numWaitingCalls;
};

#endif // CALLCENTER_H

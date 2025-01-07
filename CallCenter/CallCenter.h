#ifndef CALLCENTER_H
#define CALLCENTER_H

#include <queue>
#include <vector>
#include "Employee.h"

class CallCenter {
public:
    CallCenter(const std::vector<Employee>& employees);

    Employee* dispatchCall();
    void completeCall(Employee& employee);

    void addWaitingCall(int numCalls = 1);
	int getNumWaitingCalls() const;

    void addRespondent(const Employee& employee);

private:
	std::queue<Employee> respondents;
    std::queue<Employee> managers;
    std::queue<Employee> directors;

	int numWaitingCalls;
};

#endif // CALLCENTER_H

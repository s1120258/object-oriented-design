#ifndef CALLCENTER_H
#define CALLCENTER_H

#include <queue>
#include <vector>
#include <map>
#include "Role.h"

class Employee;

class CallCenter {
public:
    CallCenter(const std::vector<Employee>& employees);

    Employee* dispatchCall();
    void completeCall(Employee& employee);

    void addWaitingCall(int numCalls = 1);
    void addRespondent(const Employee& employee);

private:
	std::map<Role, std::queue<Employee>> respondents;
	int numWaitingCalls;
};

#endif // CALLCENTER_H

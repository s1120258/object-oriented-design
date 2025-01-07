#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Role.h"

class Employee {
public:
    Employee(int id, Role role);

    bool isAvailable() const;
    void setIsAvailable(bool availability);

    int getId() const;
    Role getRole() const;

private:
    int id;
    Role role;
    bool availability;
};

#endif // EMPLOYEE_H

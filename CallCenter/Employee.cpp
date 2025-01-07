#include "Employee.h"

Employee::Employee(int id, Role role) : id(id), role(role), available(true) {}

bool Employee::isAvailable() const {
    return available;
}

void Employee::setIsAvailable(bool availability) {
    available = availability;
}

Role Employee::getRole() const {
    return role;
}

int Employee::getId() const {
    return id;
}

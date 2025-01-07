#include "Employee.h"

Employee::Employee(int id, Role role) : id(id), role(role), availability(true) {}

bool Employee::isAvailable() const {
    return availability;
}

void Employee::setIsAvailable(bool availability) {
    this->availability = availability;
}

int Employee::getId() const {
    return id;
}

Role Employee::getRole() const {
    return role;
}

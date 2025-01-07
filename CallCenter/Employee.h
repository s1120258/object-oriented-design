#ifndef EMPLOYEE_H
#define EMPLOYEE_H

enum class Role {
    Respondent,
    Manager,
    Director
};

class Employee {
public:
    Employee(int id, Role role);

    bool isAvailable() const;
    void setIsAvailable(bool availability);

    Role getRole() const;
    int getId() const;

private:
    int id;
    Role role;
    bool available;
};

#endif // EMPLOYEE_H

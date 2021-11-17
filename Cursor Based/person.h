#ifndef PERSON_H
#define PERSON_H

#include <stdio.h>
#include <string.h>

typedef char String[30];

typedef struct {
    String name;
    char sex;
    String city;
} Person;

Person createPerson(String name, char sex, String city);
void displayPersonInfo(Person p);
    // {name | sex | city}

Person createPerson(String name, char sex, String city) {

    Person p;

    strcpy(p.name, name);
    p.sex = sex;
    strcpy(p.city, city);

    return p;
}

void displayPersonInfo(Person p) {
    printf("\nName: %s", p.name);
    printf("\nSex: %c", p.sex);
    printf("\nCity: %s", p.city);
}


int main() {

    Person p;
    String name = "Roe Ann Kim";
    String city = "Cebu";
    char sex = 'F';

    p = createPerson(name, sex, city);
    displayPersonInfo(p);
}

#endif
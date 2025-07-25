#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Person
{
    char *name;
    int age;
    bool canDrive;
} Person;

bool _candrive(int age) {
    return age >= 18;
}

Person *createPerson(char *name, int age, bool (*function)(int age)) {
    Person *person = malloc(sizeof(Person));
    if (person == NULL) {
        fprintf(stderr, "error allocating memory for person\n");
        exit(1);
    }

    person->name = malloc(sizeof(char) * (strlen(name) + 1));
    if (person->name == NULL) {
        fprintf(stderr, "error allocating memory for name\n");
        free(person);
        exit(1);
    }

    strcpy(person->name, name);
    person->age = age;
    person->canDrive = function(age);

    return person;
}

int main() {
    int age = 20;
    char name[] = "Alana";

    Person *person = createPerson(name, age, _candrive);

    if (person->canDrive) {
        printf("%s can drive\n", person->name);
    } else {
        printf("%s can't drive\n", person->name);
    }


    free(person->name);
    free(person);

    return 0;
}

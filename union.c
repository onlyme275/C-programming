#include <stdio.h>
#include <string.h>

union Data {
    int intValue;
    float floatValue;
    char name[20];
};

int main() {
    union Data data;

    // Store an integer
    data.intValue = 100;
    printf("Integer: %d\n", data.intValue);

    // Store a float (overwrites previous value)
    data.floatValue = 98.5;
    printf("Float: %.2f\n", data.floatValue);

    // Store a string (overwrites previous values)
    strcpy(data.name, "Alice");
    printf("Name: %s\n", data.name);

    // Check what happened to other members
    printf("After storing name, intValue: %d\n", data.intValue);
    printf("After storing name, floatValue: %.2f\n", data.floatValue);

    return 0;
}


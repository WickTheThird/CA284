#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// Filip Bumbu, check the attendance of a stdudent...three A's mean 1, three L's mean one A, if there are not 3 A's or otherwise print 0, 13/11/22
// The way I went about this:
//      -> Firstly I have added everything to a linked list as i will need to iterate thorugh it linearly anyways and its better;
//      -> Then I have looped through the linked list while also looping through the string, checking the A's ad L's;
//      -> Then I print 1 or 0 depending on the number of A's counted;
//
// Libs used:
// -> #include <stdio.h>
// -> #include <stdlib.h>
// -> #include <string.h>
//

// declarations
typedef struct Student Student;

struct Student {
    char *attendance;
    Student *next;
};

Student *link_students(char *arr[], int len);
void compute_attendance(Student *start);

// main
int main(int argc, char* argv[]) {

    // declaring the head;
    Student *start = NULL;
    // assinging the attendance of students in a linked list;
    start = link_students(argv, argc - 1);
    // computing attendance of students
    compute_attendance(start);

    return 0;
}

// assinging the values from argv to a linked list which can be better handled
Student *link_students(char *arr[], int len){
    // initiating the current and the first (or head)
    Student *current, *first;
    // equating the current with the first
    first = (Student *)malloc(sizeof(Student));
    current = first;
    // filling the first node
    current->attendance = arr[1];
    // assigning the rest based on the head/first node
    for(int i = 2; i <= len; ++i) {
        // allocating the next
        current->next = (Student*)malloc(sizeof(Student));
        current = current->next;
        // allocating the string to the linked list
        current->attendance = arr[i];
    }
    // ending the array
    current->next = NULL;
    // returning the head
    return first;
}

// computing the attendance type and printing it
void compute_attendance(Student *start) {

    // decaring a pointer to assign the values constantly
    Student *p = NULL;
    // looping through the values constantly using p
    for (p = start; p != NULL; p = p->next) {
        // counting the a's (that's the only thing we need)
        int count_a = 0;
        // looping through the string
        for (int j = 0; j < strlen(p->attendance); ++j) {
            // ading up the a's
            if (*(p->attendance + j) == 'A') {
                ++count_a;
            }
            // checking if there are three l's in a row
            if ((*(p->attendance + j) == 'L') && (*(p->attendance + (j + 1)) == 'L') && (*(p->attendance + (j + 2)) == 'L')) {
                ++count_a; // three l's == one a
            }
        }
        // printing the correct state of the student based on the number of a's
        if (count_a >= 3) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
}

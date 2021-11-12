#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Structure Declaration (Template)
struct Clinic{

    //Data Field
    int numRoom;
    int numPatient;

    //Pointer (Link) Field
    struct Clinic *ptrNext;};

//Function Declaration (Prototype)
void read_patientNew();
void display_patientAll();

struct Clinic *ptrHead, *ptrNew, *ptrCurrent;

int main(void){

    char userChoice[5];
    int userExit=1;

    ptrHead=(struct Clinic *)NULL;

    while(userExit==1){

        printf("e - Enter new patient's number");
        printf("\nl - List all patients");
        printf("\nx - Exit");

        printf("\n\nEnter choice: ");
        scanf(" %s", &userChoice);

        if(strcasecmp(userChoice, "E") == 0){
            //Function Calling: read_patientNew
            read_patientNew();}

        else if(strcasecmp(userChoice, "L") == 0){
            //Function Calling: display_patientAll
            display_patientAll();}

        else if(strcasecmp(userChoice, "X") == 0){
            userExit=0;}

        else{
            system("cls");
            printf("Enter only one from the given options:-\n\n");}}

return 0;
}

//Function Definition: read_patientNew
void read_patientNew(){

    int listLocation;

    ptrNew=(struct Clinic *)malloc(sizeof(struct Clinic));

    printf("\nEnter room number       : ");
    scanf(" %d", &ptrNew->numRoom);

    printf("Enter patient number    : ");
    scanf(" %d", &ptrNew->numPatient);

    printf("\n");

    if(ptrHead==NULL){
        ptrHead=ptrNew;
        ptrNew->ptrNext=NULL;}

    else{
        display_patientAll();
        printf("Enter room number it's next to: ");
        scanf(" %d", &listLocation);

        ptrCurrent=ptrHead;

        while(ptrCurrent!=NULL){

            if(ptrCurrent->numRoom == listLocation){
                break;}

            else{
                ptrCurrent=ptrCurrent->ptrNext;}}

        if(ptrCurrent==NULL){
            printf("\nRoom no. %d isn't in the list.\n\n", listLocation);}

        else{
            ptrNew->ptrNext=ptrCurrent->ptrNext;
            ptrCurrent->ptrNext=ptrNew;
            printf("Done listed ROOM %d into the list!\n\n", ptrNew->numRoom);}
    }
}

//Function Definition: display_patientAll
void display_patientAll(){

    system("cls");

    if(ptrHead==NULL){
        printf("No clinic room occupied.\n");}

    else{
        printf("Room Number\t Patient Number\n");
        ptrCurrent=ptrHead;

        do{
            printf("%d\t\t %d", ptrCurrent->numRoom, ptrCurrent->numPatient);

            printf("\n");

            ptrCurrent=ptrCurrent->ptrNext;

        }while(ptrCurrent!=NULL);}

    printf("\n");
}

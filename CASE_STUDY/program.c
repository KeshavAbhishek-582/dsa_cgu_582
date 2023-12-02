#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int nStudents = 0;

// Defined a Self Referential Structure
typedef struct StudentManagement{
    struct StudentManagement * pre;
    char details[6][100];
    struct StudentManagement * next;
}SM;

// Required functions declared

// Creation of Node
SM * createStudentNode(SM * head);

// Insertion of Data
SM * insertAtFront(SM * head, SM * studentDetail);
SM * insertAtSpecificPosition(SM * head, SM * studentDetail);
SM * insertAfterSpecificPosition(SM * head, SM * studentDetail);
SM * insertAtEnd(SM * head, SM * studentDetail);

// Deletion of Data
SM * deleteAtFront(SM * head);
SM * deleteAtSpecificPosition(SM * head);
SM * deleteAtEnd(SM * head);

// Updation of Data
SM * updateDeatils(SM * head);

// Prints Details
void singleNodePrinter(SM * head);
void printData(SM * head);

// Duplicacy Checker
int checkDuplicacy(SM * head, char regno[]);

// Function Definition starts here. 
SM * createStudentNode(SM * head){
    SM * new;
    new = (SM *)malloc(sizeof(SM));

    printf("\n\nEnter Reg. No.:- ");
    scanf(" %[^\n]s", &new->details[0]);

    int DC = checkDuplicacy(head, new->details[0]);
    if(DC==0){
        printf("Enter Name:- ");
        scanf(" %[^\n]s", &new->details[1]);

        printf("Enter Gender [M/F]:- ");
        scanf(" %[^\n]s", &new->details[2]);

        printf("Enter DOB [dd-mm-yyyy]:- ");
        scanf(" %[^\n]s", &new->details[3]);

        printf("Enter Address:- ");
        scanf(" %[^\n]s", &new->details[4]);

        printf("\nDate of Registration:- %s", __DATE__);
        strcpy(new->details[5], __DATE__);
        printf("\n\n");

        new->pre=NULL;
        new->next=NULL;

        nStudents++;

        return new;
    }
    else{
        printf("\nStudent already exists vide %s registration number.\n", new->details[0]);
        return createStudentNode(head);
    }
}

SM * insertAtFront(SM * head, SM * studentDetail){
    if(head == NULL){
        head = studentDetail;
        return head;
    }

    SM * temp = head;
    SM * new = studentDetail;
    new->next = temp;
    temp->pre = new;
    head = new;

    return head;
}

SM * insertAtSpecificPosition(SM * head, SM * studentDetail){

    printf("\nEnter position at which you want to enter the student details : ");
    int pos = 0;
    scanf("%d", &pos);

    if(pos==1){
        return insertAtFront(head, studentDetail);
    }
    if(pos==nStudents-1){
        return insertAtEnd(head, studentDetail);
    }
    if(pos>1 && pos<nStudents-1){
        SM * temp = head;

        int i = 0;
        while(i!=pos-2){
            temp = temp->next;
            i++;
        }

        SM * address = temp->next;

        temp->next = studentDetail;
        studentDetail->next = address;
        studentDetail->pre = temp;
        (studentDetail->next)->pre = studentDetail;

        return head;
    }
}

SM * insertAfterSpecificPosition(SM * head, SM * studentDetail){

    printf("\nEnter position at which you want to enter the student details : ");
    int pos = 4;
    scanf("%d", &pos);

    if(pos==1){
        return insertAtFront(head, studentDetail);
    }
    if(pos==nStudents-1){
        return insertAtEnd(head, studentDetail);
    }
    if(pos>1 && pos<nStudents-1){
        SM * temp = head;

        int i = 0;
        while(i!=pos-1){
            temp = temp->next;
            i++;
        }

        SM * address = temp->next;

        temp->next = studentDetail;
        studentDetail->next = address;
        studentDetail->pre = temp;
        (studentDetail->next)->pre = studentDetail;

        return head;
    }
}

SM * insertAtEnd(SM * head, SM * studentDetail){
    if(head == NULL){
        head = studentDetail;
        return head;
    }

    SM * temp = head;
    SM * new = studentDetail;

    while (temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next = new;
    new->pre = temp;

    return head;
}

SM * deleteAtFront(SM * head){
    if(head!=NULL){
        SM * temp = head;
        printf("Student Details Deleted.\n");

        singleNodePrinter(head);

        head = head->next;
        head->pre = NULL;

        nStudents--;

        return head;
    }
}

SM * deleteAtSpecificPosition(SM * head){
    printf("\nEnter position at which you want to delete the student details : ");
    int pos = 0;
    scanf("%d", &pos);

    if(pos==1){
        return deleteAtFront(head);
    }

    if(pos==nStudents){
        return deleteAtEnd(head);
    }

    if(pos>1 && pos<nStudents){
        SM * temp = head;

        int i = 0;
        while(i!=pos-1){
            temp = temp->next;
            i++;
        }

        singleNodePrinter(temp);

        SM * temp1 = temp->pre;
        SM * temp2 = temp->next;

        temp = temp->pre;
        temp->next = temp2;
        temp2->pre = temp1;

        nStudents--;
        return head;
    }
}

SM * deleteAtEnd(SM * head){
    if(head!=NULL){
        SM * temp = head;
        printf("Student Details Deleted.\n");

        if(temp->next==NULL){
            head = deleteAtFront(head);
        }

        while(temp->next->next!=NULL){
            temp = temp->next;
        }

        singleNodePrinter(temp->next);

        temp->next->pre=NULL;
        temp->next = NULL;

        nStudents--;

        return head;
    }
}

SM * updateDeatils(SM * head){
    char tempRegNo[100];
    printf("\n\nEnter Reg. No.:- ");
    scanf(" %[^\n]s", &tempRegNo);

    SM * temp = head;
    while(strcmp(temp->details[0],tempRegNo)!=0){
        temp = temp->next;
    }

    printf("Want to change...\n1. Name\n2. Gender\n3. DOB\n4. Address\n\nSelect Option : ");
    int ch = 0;
    scanf("%d", &ch);

    if(ch>=1 && ch<=4){
        if(ch==1){
            printf("Enter Name:- ");
            scanf(" %[^\n]s", &temp->details[1]);
        }
        if(ch==2){
            printf("Enter Gender [M/F]:- ");
            scanf(" %[^\n]s", &temp->details[2]);
        }
        if(ch==3){
            printf("Enter DOB [dd-mm-yyyy]:- ");
            scanf(" %[^\n]s", &temp->details[3]);
        }
        if(ch==4){
            printf("Enter Address:- ");
            scanf(" %[^\n]s", &temp->details[4]);
        }
    }

    return head;
}

int checkDuplicacy(SM * head, char regno[]){
    SM * temp = head;

    while(temp!=NULL){
        if(strcmp(temp->details[0], regno)==0){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Prints whole data
void printData(SM * node){
    while(node!=NULL){
        printf("\nReg. No. : %s\n", node->details[0]);
        printf("Name : %s\n", node->details[1]);
        printf("Gender : %s\n", node->details[2]);
        printf("DOB : %s\n", node->details[3]);
        printf("Address : %s\n", node->details[4]);
        printf("Date of Registration : %s\n", node->details[5]);

        // printf("%p %p %p\n", node->pre, node, node->next);

        node = node->next;
    }
}

// Print Desired Details
void singleNodePrinter(SM * node){
    if(node!=NULL){
        printf("\nReg. No. : %s\n", node->details[0]);
        printf("Name : %s\n", node->details[1]);
        printf("Gender : %s\n", node->details[2]);
        printf("DOB : %s\n", node->details[3]);
        printf("Address : %s\n", node->details[4]);
        printf("Date of Registration : %s\n", node->details[5]);
    }
    else{
        printf("\nStudent Not Found\n");
    }
}

void showData(SM * node){
    int opt;
    char reg[20];
    printf("\n1. Single Student Detail\n2.All Students Details\n\nEnter choice : ");
    scanf("%d", &opt);

    if(opt==1){
        printf("\n\nEnter Reg. No.:- ");
        scanf(" %[^\n]s", &reg);

        SM * temp = node;
        while(strcmp(temp->details[0],reg)!=0){
            temp = temp->next;
        }
        
        singleNodePrinter(temp);
    }
    else if(opt==2){
        printData(node);
        printf("\n");
    }
    else{
        printf("! Invalid Choice Entered !");
    }
}

int main(){
    SM * node = NULL;
    int option=0;

    do
    {
        printf("\n\n\n\
=================== Student Management System ===================\n\n\
1. Add student details at the front of the link list.\n\
2. Add student details at n-th position of the link list.\n\
3. Add student details at after n-th position of the link list.\n\
4. Add student details at the end of the link list.\n\n\
5. Delete student details at front.\n\
6. Delete stduent details at specific position.\n\
7. Delete student details at end.\n\n\
8. Edit student details.\n\n\
9. Show data.\n\
10. Exit\n\
\n\
Enter option : ");
        
        scanf("%d", &option);

        if(option == 1){
            node = insertAtFront(node, createStudentNode(node));
        }
        if(option == 2){
            node = insertAtSpecificPosition(node, createStudentNode(node));
        }
        if(option == 3){
            node = insertAfterSpecificPosition(node, createStudentNode(node));
        }
        if(option == 4){
            node = insertAtEnd(node, createStudentNode(node));
        }
        if(option == 5){
            node = deleteAtFront(node);
        }
        if(option == 6){
            node = deleteAtSpecificPosition(node);
        }
        if(option == 7){
            node = deleteAtEnd(node);
        }
        if(option == 8){
            node = updateDeatils(node);
        }
        if(option == 9){
            if(node!=NULL){
                showData(node);
            }
            else{
                printf("\n\nNo Data.");
            }
        }
        if(option == 10){
            printf("\n\nExiting...");
            break;
        }
    } while (option>=1 && option<=10);
    return 0;
}
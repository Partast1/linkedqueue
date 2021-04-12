#include <stdio.h>
#include <stdlib.h>

struct Node {
    int number;
    struct Node* next;
};
//pr'vede at lave en funktion som retunere en Node hvor størrelsen er sat.
/**<
struct Node nodesizeconstuctor(struct Node* n){

   n=(struct Node *)malloc(sizeof(struct Node));
   return n;
}
 */

 //første led i linked list
 struct Node* head = NULL;

 //Prompter for at lave det første element af listen
void createlinkedlist(){
    struct Node *newNode;
    int val;
newNode=(struct Node *)malloc(sizeof(struct Node));

    printf("Skriv et nummer til det første element i linked list \n");
        scanf("%d", &val);

newNode->number = val;
newNode->next = head;
head = newNode;

}

//Printer en linked liste af Node(s)
void printList(struct Node* n)
{
    while (n != NULL) {
        printf(" %d ", n->number);
        n = n->next;
    }
}
//Opretter et element bagerest i listen.
void createLastInList(){
    int val;
    struct Node* newNode;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    printf("Skriv et nummer til det sidste element i linked list \n");
        scanf("%d", &val);

newNode->number = val;
newNode->next = NULL;

struct Node *temp = head;
while(temp->next != NULL){
  temp = temp->next;
}

temp->next = newNode;
}


//Sletter et tal i listen.
void deleteNode(struct Node** ref) {
    int val;
  struct Node *temp = *ref, *prev;

  printf("Skriv et nummer i linked list som skal slettes \n");
        scanf("%d", &val);

  if (temp != NULL && temp->number == val) {
    *ref = temp->next;
    free(temp);
    return;
  }
  // Finder tallet som skal slettes
  while (temp != NULL && temp->number != val) {
    prev = temp;
    temp = temp->next;
  }

  // Hvis nøglen ikke kan findes
  if (temp == NULL) return;

  // Fjerner Node
  prev->next = temp->next;

  free(temp);
}



int main()
{
    int input;

  createlinkedlist();


while(1){
    printf("Skriv 1 for at oprette bagerst i køen \n");
    printf("Skriv 2 for at print køen \n");
    printf("Skriv 3 for at slette et tal i køen \n");
        scanf("%d", &input);

switch(input){
case 1:
   createLastInList();
    break;
    case 2:
   printList(head);
    break;
    case 3:
   deleteNode(&head);
    break;

}

}


    return 0;
}

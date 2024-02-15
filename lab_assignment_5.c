#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char letter;
  struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
  int counter = 1;
  while((head != NULL) && (head->next != NULL))
  {
    head = head->next;
    counter++;
  }
  return counter;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
  int n = length(head);

  char* str = (char*) malloc(n*sizeof(char));
  for(int i=0; i<n; i++)
  {
    str[i] = head->letter;
    head = head->next;
  }

  return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
  node* in_node = (node*) malloc(sizeof(node));
  if(in_node != NULL)
  {
    in_node->letter = c;
    in_node->next = NULL;
  }
  node* temp;
  temp = *pHead;
  while((temp!=NULL)&&(temp->next!=NULL))
  {
    temp = temp->next;
  }
  if(temp == NULL)
  {
    *pHead = in_node;
  }
  else if(temp->next == NULL){
    temp->next = in_node;
  }

}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
  node* temp = NULL;

  while(*pHead!=NULL)
  {
    temp = *pHead;
	*pHead = (*pHead)->next;
    free(temp);
  }
  *pHead = NULL;
}

int main(void)
{
  int i, strLen, numInputs;
  node* head = NULL;
  char* str;
  char c;
  FILE* inFile = fopen("input.txt","r");

  fscanf(inFile, " %d\n", &numInputs);

  while (numInputs-- > 0)
  {
    fscanf(inFile, " %d\n", &strLen);
    for (i = 0; i < strLen; i++)
    {
      fscanf(inFile," %c", &c);
      insertChar(&head, c);
    }

    str = toCString(head);
    printf("String is : %s\n", str);

    free(str);
    deleteList(&head);

    if (head != NULL)
    {
      printf("deleteList is not correct!");
      break;
    }
  }

  fclose(inFile);
}
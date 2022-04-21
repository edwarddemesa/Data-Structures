/******************************************************************************

Author:  Edward DeMesa
Title: Linked List -- YouTube Tutorial series

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

// Function Prototypes
Node pushHead(Node **head, int data);
Node *pushHead1(Node *head, int data);
void print_list(Node *head);
int countNodes(Node *head);
Node pushTail(Node **head, int data);
Node *pushTail1(Node *head, int data);
Node pushAtIndex(Node **head, int index, int data);
Node *pushAtIndex1(Node *head, int index, int data);
void printIndex(Node *head, int index);
int getSum(Node *head);
float getAverage(Node *head);
Node popHead(Node **head);
Node *popHead1(Node *head);
Node popTail(Node **head);
Node *popTail1(Node *head);
Node popIndex(Node **head, int index);
Node *popIndex1(Node *head, int index);
Node popList(Node **head);
Node reverseList(Node **head);
Node *reverseList1(Node *head);



int main()
{
    Node *head = NULL;

    head = pushTail1(head, 30);
    head = pushHead1(head, 20);
    pushHead(&head, 10);
    pushTail(&head, 50);
    pushAtIndex(&head, 3, 40);

    //int sum = getSum(head);
    //float average = getAverage(head);
    //printf("\nSum = %d\n", sum);
    //printf("Average = %.2f\n", average);
    //head = popHead1(head);
    //popTail(&head);
    //head = popTail1(head);
    //popIndex(&head, 2);
    //head = popIndex1(head, 3);

    print_list(head);
    printf("\n\nAfter Reverse List function is called.\n\n");

    reverseList(&head);
    //head = reverseList1(head);

    print_list(head);

    return 0;
}


/******************************************************************************
*                                        pushHead() Function                                              *
******************************************************************************/
Node pushHead(Node **head, int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("Error: Memory not allocated.\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        new_node->next = *head;
        *head = new_node;
    }
}


/******************************************************************************
*                                        pushHead1() Function                                            *
******************************************************************************/
Node *pushHead1(Node *head, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("Error:  Memory not allocated. \n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;

    // If our list is empty
    if(head == NULL)
    {
        head = new_node;
    }
    // If we have one or more nodes in the list
    else
    {
        new_node->next = head;
        head = new_node;
    }

    return head;
}


/******************************************************************************
*                                          print_list() Function                                               *
******************************************************************************/
void print_list(Node *head)
{
    if(head == NULL)
    {
        printf("The list is empty. \n");
    }

    int i = 0;
    Node *current = head;
    while (current != NULL)
    {
        printf("Node[index: %d]:  %d \n", i, current->data);
        i++;
        current = current->next;
    }

    printf("\nNumber of Nodes:  %d\n", countNodes(head));
}


/******************************************************************************
*                                          countNodes() Function                                         *
******************************************************************************/
int countNodes(Node *head)
{
    if(head == NULL)
    {
        return 0;
    }

    int count = 0;
    Node *current = head;
    while(current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}


/******************************************************************************
*                                        pushTail() Function                                                 *
******************************************************************************/
Node pushTail(Node **head, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("Error:  Memory not allocated. \n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;

    Node *current = *head;

    // If the list is empty
    if(*head == NULL)
    {
        *head  = new_node;
    }

    // If the list contains one of more nodes
    else
    {
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}


/******************************************************************************
*                                        pushTail1() Function                                               *
******************************************************************************/
Node *pushTail1(Node *head, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("Error:  Memory not allocated. \n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;

    Node *current = head;

    // If the list is empty
    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    return head;
}


/******************************************************************************
*                                       pushAtIndex() Function                                            *
******************************************************************************/
Node pushAtIndex(Node **head, int index, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("Error:  Memory not allocated. \n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;

    Node *current = *head;
    int i = 0;  // Actual index
    int numNodes = countNodes(*head);

    // If list is empty
    if(*head == NULL)
    {
        *head = new_node;
    }

    // If we are adding at index 0
    else if(index == 0)
    {
        pushHead(head, data);
    }

    // Error check:  If index request is out of bounds
    else if(index < i || index > numNodes)
    {
        printf("Index request is out of bounds.  Must be"
                   "between %d and %d.\n\n", i, numNodes);
    }

    // If we are adding a node at any index inside our bounds
    else
    {
        while(i != index -1)
        {
            current = current->next;
            i++;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

}


/******************************************************************************
*                                       pushAtIndex1() Function                                          *
******************************************************************************/
Node *pushAtIndex1(Node *head, int index, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("Error:  Memory not allocated. \n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;

    Node *current = head;
    int i = 0;  // Actual index
    int numNodes = countNodes(head);

    // If list is empty
    if(head == NULL)
    {
        head = new_node;
    }

    // If we are adding at index 0
    else if(index == 0)
    {
        pushHead(&head, data);
    }

    // Error check:  If index request is out of bounds
    else if(index < i || index > numNodes)
    {
        printf("Index request is out of bounds.  Must be "
                   "between %d and %d.\n\n", i, numNodes);
    }

    // If we are adding a node at any index inside our bounds
    else
    {
        while(i != index -1)
        {
            current = current->next;
            i++;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    return head;
}


/******************************************************************************
*                                          printIndex() Function                                             *
******************************************************************************/
void printIndex(Node *head, int index)
{
    int i = 0;
    int numNodes = countNodes(head);
    Node *current = head;

    // If the list is empty
    if(head == NULL)
    {
        printf("The list is empty.\n");
    }

    // Error check: If index request is out of bounds
    else if(index < i || index > numNodes - 1)
    {
        printf("Index request is out of bounds.  Must be in the "
                   "index range of %d and %d.\n\n", i, numNodes - 1);
    }

    else
    {
        while (current != NULL && (i != index))
        {
            current = current->next;
            i++;
        }
        printf("Node[index: %d]: %d\n\n", i, current->data);
    }

    printf("Number of Nodes: %d\n\n", numNodes);
}


/******************************************************************************
*                                             getSum() Function                                             *
******************************************************************************/
int getSum(Node *head)
 {
     int sum = 0;
     Node *current = head;

     // If the list is empty
     if(head == NULL)
     {
         return 0;
     }
     else
     {
         while (current != NULL)
         {
             sum += current->data;
             current = current->next;
         }
         return sum;
     }
 }


 /******************************************************************************
*                                          getAverage() Function                                           *
******************************************************************************/
float getAverage(Node *head)
{
    return getSum(head)/(float)countNodes(head);
}


/******************************************************************************
*                                           popHead() Function                                             *
******************************************************************************/
Node popHead(Node **head)
{
    Node *temp = *head;
    int i = 0;
    //if the list is empty
    if(*head == NULL)
    {
        printf("\nThe list is empty\n");
        exit(0);
    }

    // if the list has one node
    else if(temp->next == NULL)
    {
        printf("Node[index: %d] -- Data: [%d] was "
                   "deleted.\n\n", i, temp->data);
        free(temp);
        *head = NULL;
        temp = NULL;
    }

    // if the list has more than one nodes
    else
    {
        *head = temp->next;
        printf("Node[index: %d] -- Data: [%d] was "
                   "deleted.\n\n", i, temp->data);
        free(temp);
        temp = NULL;
    }
}


/******************************************************************************
*                                         popHead1() Function                                             *
******************************************************************************/
Node *popHead1(Node *head)
{
    Node *temp = head;
    int i = 0;
    //if the list is empty
    if(head == NULL)
    {
        printf("\nThe list is empty\n");
        exit(0);
    }

    // if the list has one node
    else if(temp->next == NULL)
    {
        printf("Node[index: %d] -- Data: [%d] was "
                   "deleted.\n\n", i, temp->data);
        free(temp);
        head = NULL;
        temp = NULL;
    }

    // if the list has more than one nodes
    else
    {
        head = temp->next;
        printf("Node[index: %d] -- Data: [%d] was "
                   "deleted.\n\n", i, temp->data);
        free(temp);
        temp = NULL;
    }
    return head;
}


/******************************************************************************
*                                           popTail() Function                                               *
******************************************************************************/
Node popTail(Node **head)
{
    Node *temp = *head;
    Node *current = *head;
    int i = 0;

    // If the list is empty
    if(*head == NULL)
    {
        printf("The list is empty.\n");
        exit(0);
    }

     // If the list contains only one node
     else if(temp->next == NULL)
     {
         printf("Node[index: %d] -- Data: [%d] was "
                   "deleted.\n\n", i, temp->data);
         free(temp);
         *head = NULL;
         temp = NULL;
         current =NULL;
     }

    // if the list contains more than one node
    else
    {
        while(temp->next != NULL)
        {
            current = temp;
            temp = temp->next;
            i++;
        }
        printf("Node[index: %d] -- Data: [%d] was "
                   "deleted.\n\n", i, temp->data);
        free(temp);
        current->next = NULL;
        temp = NULL;
    }
}


/******************************************************************************
*                                           popTail1() Function                                             *
******************************************************************************/
Node *popTail1(Node *head)
{
    Node *temp = head;
    Node *current = head;
    int i = 0;

    // If the list is empty
    if(head == NULL)
    {
        printf("The list is empty.\n");
        exit(0);
    }

     // If the list contains only one node
     else if(temp->next == NULL)
     {
         printf("Node[index: %d] -- Data: [%d] was "
                   "deleted.\n\n", i, temp->data);
         free(temp);
         head = NULL;
         temp = NULL;
         current =NULL;
     }

    // if the list contains more than one node
    else
    {
        while(temp->next != NULL)
        {
            current = temp;
            temp = temp->next;
            i++;
        }
        printf("Node[index: %d] -- Data: [%d] was "
                   "deleted.\n\n", i, temp->data);
        free(temp);
        current->next = NULL;
        temp = NULL;
    }
    return head;
}


/******************************************************************************
*                                           popIndex() Function                                             *
******************************************************************************/
Node popIndex(Node **head, int index)
{
    Node *current = *head;
    Node *temp = *head;
    int i = 0;
    int numNodes = countNodes(*head);

    // If the list is empty
    if(*head == NULL)
    {
        printf("The list is empty.\n");
        exit(0);
    }

    // If the list has one node
    else if(temp->next == NULL)
    {
        printf("Node[index: %d] -- Data: [%d] was "
                   "deleted.\n\n", i, temp->data);
        free(temp);
        temp = NULL;
        current = NULL;
        *head = NULL;
    }

    // If we want to delete the first node
    else if(i == index)
    {
        *head = current->next;
        current = *head;
        printf("Node[index: %d] -- Data: [%d] was "
                   "deleted.\n\n", i, temp->data);
        free(temp);
        temp = NULL;
    }

    // Error check: If index request is out of bounds
    else if(index < i || index > numNodes - 1)
    {
        printf("Index request is out bounds.  Must be"
                  " between %d and %d.\n\n", i, numNodes - 1);
        exit(0);
    }

    // If our list has more than one nodes
    else
    {
        while(i != index)
        {
            current = temp;
            temp = temp->next;
            i++;
        }
        current->next = temp->next;
        printf("Node[index: %d] -- Data: [%d] was "
                   "deleted.\n\n", i, temp->data);
        free(temp);
        temp = NULL;
    }
}


/******************************************************************************
*                                         popIndex1() Function                                             *
******************************************************************************/
Node *popIndex1(Node *head, int index)
{
    Node *current = head;
    Node *temp = head;
    int i = 0;
    int numNodes = countNodes(head);

    // If the list is empty
    if(head == NULL)
    {
        printf("The list is empty.\n");
        exit(0);
    }

    // If the list has one node
    else if(temp->next == NULL)
    {
        printf("Node[index: %d] -- Data: [%d] was "
                   "deleted.\n\n", i, temp->data);
        free(temp);
        temp = NULL;
        current = NULL;
        head = NULL;
    }

    // If we want to delete the first node
    else if(i == index)
    {
        head = current->next;
        current = head;
        printf("Node[index: %d] -- Data: [%d] was "
                   "deleted.\n\n", i, temp->data);
        free(temp);
        temp = NULL;
    }

    // Error check: If index request is out of bounds
    else if(index < i || index > numNodes - 1)
    {
        printf("Index request is out bounds.  Must be"
                  " between %d and %d.\n\n", i, numNodes - 1);
        exit(0);
    }

    // If our list has more than one nodes
    else
    {
        while(i != index)
        {
            current = temp;
            temp = temp->next;
            i++;
        }
        current->next = temp->next;
        printf("Node[index: %d] -- Data: [%d] was "
                   "deleted.\n\n", i, temp->data);
        free(temp);
        temp = NULL;
    }
    return head;
}


/******************************************************************************
*                                           popList() Function                                                *
******************************************************************************/
Node popList(Node **head)
{
    Node *temp = *head;
    Node *current = *head;
    int i = 0;

    // If the list is empty
    if(*head == NULL)
    {
        printf("There is no list to delete.\n");
        exit(0);
    }

    // If the list has one or more nodes
    else
    {
        while(current != NULL)
        {
            temp = current;
            current = current->next;
            printf("Node[index: %d] -- Data: [%d] was "
                   "deleted.\n\n", i, temp->data);
            free(temp);
        }
        *head = NULL;
        temp = NULL;
        current = NULL;
    }

}


/******************************************************************************
*                                       reverseList() Function                                              *
******************************************************************************/
Node reverseList(Node **head)
{
    Node *current = *head;
    Node *previous = NULL;

    if(*head == NULL)
    {
        printf("The list is empty.  Reverse is not possible.\n");
        exit(0);
    }

    while(current->next != NULL)
    {
        *head = current->next;
        current->next = previous;
        previous = current;
        current = *head;
    }
    current->next = previous;
}


/******************************************************************************
*                                       reverseList1() Function                                            *
******************************************************************************/
Node *reverseList1(Node *head)
{
    Node *current = head;
    Node *previous = NULL;

    if(head == NULL)
    {
        printf("The list is empty.  Reverse is not possible.\n");
        exit(0);
    }

    while(current->next != NULL)
    {
        head = current->next;
        current->next = previous;
        previous = current;
        current = head;
    }
    current->next = previous;

    return head;
}


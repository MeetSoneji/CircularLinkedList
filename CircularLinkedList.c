#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        newNode->next = newNode;
    }
    else
    {
        struct Node *last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
    }
    *head = newNode;
    printf("%d inserted at the beginning of the list.\n", data);
}
void insertAfter(struct Node **head, int data, int key)
{
    if (*head == NULL)
    {
        printf("List is empty! Cannot insert after the given node.\n");
        return;
    }
    struct Node *temp = *head;
    do
    {
        if (temp->data == key)
        {
            struct Node *newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            printf("%d inserted after the given node.\n", data);
            return;
        }
        temp = temp->next;
    } while (temp != *head);
    printf("Node not found! Cannot insert after the given node.\n");
}
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
    }
    else
    {
        struct Node *last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
    }
    printf("%d inserted at the end of the list.\n", data);
}
void deleteNode(struct Node **head, int key)
{
    if (*head == NULL)
    {
        printf("List is empty! Cannot delete node.\n");
        return;
    }
    struct Node *curr = *head, *prev;
    while (curr->data != key)
    {
        if (curr->next == *head)
        {
            printf("Node not found! Cannot delete node.\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    if (curr == *head && curr->next == *head)
    {
        *head = NULL;
    }
    else if (curr == *head)
    {
        prev = *head;
        while (prev->next != *head)
        {
            prev = prev->next;
        }
        *head = (*head)->next;
        prev->next = *head;
    }
    else if (curr->next == *head)
    {
        prev->next = *head;
    }
    else
    {
        prev->next = curr->next;
    }
    free(curr);
    printf("Node with key %d deleted.\n", key);
}
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }
    struct Node *temp = head;
    printf("Circular Linked list elements:\n");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main()
{
    struct Node *head = NULL;
    int choice, data, key;

    while (1)
    {
        printf("\nCircular Linked List Operations\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert after a given node\n");
        printf("3. Insert at the end\n");
        printf("4. Delete a node\n");
        printf("5. Display the circular linked list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to insert at the beginning: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            printf("Enter the key after which to insert: ");
            scanf("%d", &key);
            insertAfter(&head, data, key);
            break;
        case 3:
            printf("Enter the data to insert at the end: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 4:
            printf("Enter the key of the node to delete: ");
            scanf("%d", &key);
            deleteNode(&head, key);
            break;
        case 5:
            display(head);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    }
    return 0;
}

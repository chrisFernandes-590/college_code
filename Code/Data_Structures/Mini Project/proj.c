#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_MSG 200

typedef struct Message
{
    char text[MAX_MSG];
    struct Message *next;
} Message;

typedef struct Chat
{
    int chatID;
    char customerName[MAX_NAME];
    Message *messages;
    struct Chat *next;
} Chat;

typedef struct Queue
{
    Chat *front;
    Chat *rear;
} Queue;

typedef struct Stack
{
    Chat *top;
} Stack;

typedef struct ActiveChatNode
{
    Chat *chat;
    struct ActiveChatNode *next;
} ActiveChatNode;

void initQueue(Queue *q)
{
    q->front = q->rear = NULL;
}

int isQueueEmpty(Queue *q)
{
    return q->front == NULL;
}

void enqueue(Queue *q, int id, char *name)
{
    Chat *newChat = (Chat *)malloc(sizeof(Chat));
    newChat->chatID = id;
    strcpy(newChat->customerName, name);
    newChat->messages = NULL;
    newChat->next = NULL;

    if (isQueueEmpty(q))
    {
        q->front = q->rear = newChat;
    }
    else
    {
        q->rear->next = newChat;
        q->rear = newChat;
    }

    printf("Chat request from '%s' (Chat ID: %d) added to queue.\n", name, id);
}

Chat *dequeue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("No chats in queue.\n");
        return NULL;
    }

    Chat *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    temp->next = NULL;
    return temp;
}

void displayQueue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("No pending chats.\n");
        return;
    }

    Chat *temp = q->front;
    printf("\nPending Chat Queue:\n");
    while (temp)
    {
        printf("   Chat ID: %d | Customer: %s\n", temp->chatID, temp->customerName);
        temp = temp->next;
    }
}

void addMessage(Chat *chat, char *msg)
{
    Message *newMsg = (Message *)malloc(sizeof(Message));
    strcpy(newMsg->text, msg);
    newMsg->next = NULL;

    if (chat->messages == NULL)
    {
        chat->messages = newMsg;
    }
    else
    {
        Message *temp = chat->messages;
        while (temp->next)
            temp = temp->next;
        temp->next = newMsg;
    }
}

void displayMessages(Chat *chat)
{
    if (!chat->messages)
    {
        printf("No messages in this chat.\n");
        return;
    }

    printf("Chat Log for '%s' (ID: %d):\n", chat->customerName, chat->chatID);
    Message *temp = chat->messages;
    int count = 1;
    while (temp)
    {
        printf("   %d. %s\n", count++, temp->text);
        temp = temp->next;
    }
}

void initStack(Stack *s)
{
    s->top = NULL;
}

int isStackEmpty(Stack *s)
{
    return s->top == NULL;
}

void push(Stack *s, Chat *chat)
{
    chat->next = s->top;
    s->top = chat;
    printf("Chat ID %d moved to resolved stack.\n", chat->chatID);
}

void pop(Stack *s)
{
    if (isStackEmpty(s))
    {
        printf("Stack is empty.\n");
        return;
    }
    Chat *temp = s->top;
    s->top = s->top->next;
    printf("Removed chat ID %d from resolved stack.\n", temp->chatID);
    free(temp);
}

void displayStack(Stack *s)
{
    if (isStackEmpty(s))
    {
        printf("No resolved chats.\n");
        return;
    }

    Chat *temp = s->top;
    printf("\nRecently Resolved Chats (Stack):\n");
    while (temp)
    {
        printf("   Chat ID: %d | Customer: %s\n", temp->chatID, temp->customerName);
        temp = temp->next;
    }
}

void addActiveChat(ActiveChatNode **head, Chat *chat)
{
    ActiveChatNode *newNode = (ActiveChatNode *)malloc(sizeof(ActiveChatNode));
    newNode->chat = chat;
    newNode->next = *head;
    *head = newNode;
    printf("Chat ID %d from '%s' is now active.\n", chat->chatID, chat->customerName);
}

Chat *findActiveChat(ActiveChatNode *head, int chatID)
{
    ActiveChatNode *temp = head;
    while (temp)
    {
        if (temp->chat->chatID == chatID)
            return temp->chat;
        temp = temp->next;
    }
    return NULL;
}

int removeActiveChat(ActiveChatNode **head, int chatID)
{
    ActiveChatNode *temp = *head, *prev = NULL;
    while (temp)
    {
        if (temp->chat->chatID == chatID)
        {
            if (prev)
                prev->next = temp->next;
            else
                *head = temp->next;
            free(temp);
            return 1;
        }
        prev = temp;
        temp = temp->next;
    }
    return 0;
}

void displayActiveChats(ActiveChatNode *head)
{
    if (head == NULL)
    {
        printf("No active chats.\n");
        return;
    }

    ActiveChatNode *temp = head;
    printf("\nActive Chats:\n");
    while (temp)
    {
        printf("   Chat ID: %d | Customer: %s\n", temp->chat->chatID, temp->chat->customerName);
        temp = temp->next;
    }
}

int main()
{
    Queue q;
    Stack s;
    ActiveChatNode *activeChats = NULL;
    int choice, idCounter = 1;
    char name[MAX_NAME], msg[MAX_MSG];
    int chatID;

    initQueue(&q);
    initStack(&s);

    while (1)
    {
        printf("\n==============================\n");
        printf(" CUSTOMER SERVICE CHAT SYSTEM \n");
        printf("==============================\n");
        printf("1. New chat request\n");
        printf("2. Attend next chat (add to active chats)\n");
        printf("3. Add message to active chat\n");
        printf("4. View active chat messages\n");
        printf("5. Resolve active chat\n");
        printf("6. View pending chat queue\n");
        printf("7. View resolved chats stack\n");
        printf("8. View active chats\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            printf("Enter customer name: ");
            fgets(name, MAX_NAME, stdin);
            name[strcspn(name, "\n")] = '\0';
            enqueue(&q, idCounter++, name);
            break;

        case 2:
        {
            Chat *nextChat = dequeue(&q);
            if (nextChat)
                addActiveChat(&activeChats, nextChat);
            break;
        }

        case 3:
            if (activeChats == NULL)
            {
                printf("No active chats. Attend a chat first.\n");
                break;
            }
            displayActiveChats(activeChats);
            printf("Enter Chat ID to add message: ");
            scanf("%d", &chatID);
            getchar();

            Chat *chatToMsg = findActiveChat(activeChats, chatID);
            if (chatToMsg == NULL)
            {
                printf("Chat ID %d not found among active chats.\n", chatID);
                break;
            }
            printf("Enter message: ");
            fgets(msg, MAX_MSG, stdin);
            msg[strcspn(msg, "\n")] = '\0';
            addMessage(chatToMsg, msg);
            break;

        case 4:
            if (activeChats == NULL)
            {
                printf("No active chats.\n");
                break;
            }
            displayActiveChats(activeChats);
            printf("Enter Chat ID to view messages: ");
            scanf("%d", &chatID);
            getchar();

            Chat *chatToView = findActiveChat(activeChats, chatID);
            if (chatToView == NULL)
            {
                printf("Chat ID %d not found among active chats.\n", chatID);
                break;
            }
            displayMessages(chatToView);
            break;

        case 5:
            if (activeChats == NULL)
            {
                printf("No active chats.\n");
                break;
            }
            displayActiveChats(activeChats);
            printf("Enter Chat ID to resolve: ");
            scanf("%d", &chatID);
            getchar();

            Chat *chatToResolve = findActiveChat(activeChats, chatID);
            if (chatToResolve == NULL)
            {
                printf("Chat ID %d not found among active chats.\n", chatID);
                break;
            }

            push(&s, chatToResolve);
            if (removeActiveChat(&activeChats, chatID))
            {
                printf("Chat ID %d resolved and removed from active chats.\n", chatID);
            }
            else
            {
                printf("Error removing chat from active list.\n");
            }
            break;

        case 6:
            displayQueue(&q);
            break;

        case 7:
            displayStack(&s);
            break;

        case 8:
            displayActiveChats(activeChats);
            break;

        case 9:
            printf("Exiting system. Goodbye!\n");
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

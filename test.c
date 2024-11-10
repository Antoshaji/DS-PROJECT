#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Name_length 100
#define Description_length 255

typedef struct Event
{
    char name[Name_length];
    char description[Description_length];
    char date[20];
    char time[20];
} Event;

typedef struct EventQueue
{
    Event *events;
    int front, rear, size, capacity;
} EventQueue;

void initQueue(EventQueue *q, int initialCapacity)
{
    q->events = (Event *)malloc(initialCapacity * sizeof(Event));
    if (!q->events)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = initialCapacity;
}

int isFull(EventQueue *q)
{
    return q->size == q->capacity;
}

int isEmpty(EventQueue *q)
{
    return q->size == 0;
}

void resizeQueue(EventQueue *q)
{
    q->capacity *= 2;
    q->events = (Event *)realloc(q->events, q->capacity * sizeof(Event));
    if (!q->events)
    {
        printf("Memory reallocation failed!\n");
        exit(1);
    }
}

void enqueue(EventQueue *q, Event e)
{
    if (isFull(q))
    {
        resizeQueue(q);
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->events[q->rear] = e;
    q->size++;
}

Event dequeue(EventQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty! Cannot dequeue.\n");
        Event emptyEvent = {"", "", "", ""};
        return emptyEvent;
    }
    Event e = q->events[q->front];
    printf("Dequeued Event: %s\n", e.name);
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return e;
}

void displayQueue(EventQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty! No events to display.\n");
        return;
    }
    printf("\nCurrent Events in the Queue:\n");
    int i = q->front;
    for (int count = 0; count < q->size; count++)
    {
        printf("Event %d: %s\n", count + 1, q->events[i].name);
        printf("  Date: %s\n", q->events[i].date);
        printf("  Time: %s\n", q->events[i].time);
        printf("  Description: %s\n\n", q->events[i].description);
        i = (i + 1) % q->capacity;
    }
}

Event getEventDetails()
{
    Event e;
    printf("Enter event name: ");
    getchar();
    fgets(e.name, sizeof(e.name), stdin);
    int i = 0;
    while (i < strlen(e.name))
    {
        if (e.name[i] == '\n')
        {
            e.name[i] = '\0';
        }
        i++;
    }
    printf("Enter event date (DD-MM-YYYY): ");
    fgets(e.date, sizeof(e.date), stdin);
    i=0;
    while (i < strlen(e.date))
    {
        if (e.date[i] == '\n')
        {
            e.date[i] = '\0';
        }
        i++;
    }

    printf("Enter event time: ");
    fgets(e.time, sizeof(e.time), stdin);
    i = 0;
    while (i < strlen(e.time))
    {
        if (e.time[i] == '\n')
        {
            e.time[i] = '\0';
        }
        i++;
    }

    printf("Enter event description: ");
    fgets(e.description, sizeof(e.description), stdin);
    i=0;
    while (i < strlen(e.description))
    {
        if (e.description[i] == '\n')
        {
            e.description[i] = '\0';
        }
        i++;
    }

    return e;
}

int main() {
    EventQueue queue;
    int initialCapacity = 2;
    initQueue(&queue, initialCapacity);

    int choice;
    Event e;

    while (1)
    {
        printf("\n\t EVENT MANAGEMENT SYSTEM \t\n");
        printf("1. Add Event (Enqueue)\n");
        printf("2. Remove Event (Dequeue)\n");
        printf("3. Display Events\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');
            printf("Invalid input! Please enter an integer.\n");
            continue;
        }

        switch (choice)
        {
            case 1:
                e = getEventDetails();
                enqueue(&queue, e);
                printf("Event added to the queue.\n");
                break;
            case 2:
                e = dequeue(&queue);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                free(queue.events);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

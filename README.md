# Event Management System in C

This program is a simple console-based Event Management System written in C. It manages events in a queue data structure, where each event has a name, description, date, and time. The program allows the user to add, remove, and display events in the queue. 

## Features
- **Enqueue (Add)**: Add an event to the queue. The program dynamically resizes the queue when it reaches capacity.
- **Dequeue (Remove)**: Remove an event from the queue.
- **Display Events**: Display all current events in the queue.

## Structure
The code uses two main structures:
1. `Event`: Holds details of an event including name, description, date, and time.
2. `EventQueue`: Manages the queue of events with dynamic resizing to handle an increasing number of events.

## Files
- `main.c`: Contains the complete code for the Event Management System.

## How to Use
1. **Compile the code** using any C compiler (e.g., GCC).
   ```bash
   gcc main.c -o event_manager
   ```
2. **Run the executable**:
   ```bash
   ./event_manager
   ```

## Menu Options
Upon running, the program displays a menu with the following options:
1. **Add Event**: Adds an event to the queue. You will be prompted to enter the event's name, date, time, and description.
2. **Remove Event**: Removes the oldest event from the queue and displays the removed event's name.
3. **Display Events**: Shows all events currently in the queue.
4. **Exit**: Exits the program and frees allocated memory.

## Code Summary
- **Queue Initialization**: Initializes the queue with a given capacity.
- **Dynamic Resizing**: Automatically doubles the queue's capacity if the queue is full.
- **Queue Functions**:
  - `enqueue(EventQueue *q, Event e)`: Adds an event to the rear of the queue.
  - `dequeue(EventQueue *q)`: Removes an event from the front of the queue.
  - `displayQueue(EventQueue *q)`: Displays all events currently in the queue.

## Example Usage
```plaintext
     EVENT MANAGEMENT SYSTEM     
1. Add Event (Enqueue)
2. Remove Event (Dequeue)
3. Display Events
4. Exit
Enter your choice: 1

Enter event name: Meeting
Enter event date (DD-MM-YYYY): 12-11-2023
Enter event time: 14:00
Enter event description: Project discussion
Event added to the queue.
```

## Requirements
- C compiler (e.g., GCC)
- Basic knowledge of C programming

## Memory Management
- The program uses `malloc` to allocate memory for the queue and `realloc` for resizing. Before exiting, it frees the allocated memory to prevent memory leaks.

## License
This project is licensed under the MIT License.

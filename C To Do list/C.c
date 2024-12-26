#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100

// Define a structure to hold the task information
typedef struct {
    char taskName[100];
    int completed; // 0 for not completed, 1 for completed
} Task;

Task taskList[MAX_TASKS];
int taskCount = 0;

// Function to display the tasks
void displayTasks() {
    if (taskCount == 0) {
        printf("\nNo tasks available.\n");
        return;
    }
    printf("\nTasks List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s [%s]\n", i + 1, taskList[i].taskName, taskList[i].completed ? "Completed" : "Pending");
    }
}

// Function to add a new task
void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("\nTask list is full. Cannot add more tasks.\n");
        return;
    }

    printf("\nEnter task name: ");
    getchar(); // Clear the input buffer
    fgets(taskList[taskCount].taskName, sizeof(taskList[taskCount].taskName), stdin);
    taskList[taskCount].taskName[strcspn(taskList[taskCount].taskName, "\n")] = 0; // Remove the newline character
    taskList[taskCount].completed = 0; // Set the task as not completed
    taskCount++;
    printf("\nTask added successfully!\n");
}

// Function to mark a task as completed
void markAsCompleted() {
    int taskNumber;
    printf("\nEnter the task number to mark as completed: ");
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > taskCount) {
        printf("\nInvalid task number.\n");
        return;
    }

    taskList[taskNumber - 1].completed = 1;
    printf("\nTask marked as completed.\n");
}

// Function to delete a task
void deleteTask() {
    int taskNumber;
    printf("\nEnter the task number to delete: ");
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > taskCount) {
        printf("\nInvalid task number.\n");
        return;
    }

    // Shift tasks after the deleted task to fill the gap
    for (int i = taskNumber - 1; i < taskCount - 1; i++) {
        taskList[i] = taskList[i + 1];
    }

    taskCount--;
    printf("\nTask deleted successfully.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nTo-Do List Application\n");
        printf("1. Add Task\n");
        printf("2. View All Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                markAsCompleted();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                printf("\nExiting the application...\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

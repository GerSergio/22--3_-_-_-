#include <iostream>
#include <vector>
#include <string>


struct Task {
    std::string description;
    bool completed;
};


std::vector<Task> tasks;


void addTask() {
    Task newTask;
    std::cout << "Enter task description: ";
    std::cin.ignore();
    std::getline(std::cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    std::cout << "Task added successfully." << std::endl;
}


void deleteTask() {
    int index;
    std::cout << "Enter the index of the task to delete: ";
    std::cin >> index;
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        std::cout << "Task deleted successfully." << std::endl;
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}


void updateTask() {
    int index;
    std::cout << "Enter the index of the task to update: ";
    std::cin >> index;
    if (index >= 0 && index < tasks.size()) {
        std::cout << "Enter new task description: ";
        std::cin.ignore();
        std::getline(std::cin, tasks[index].description);
        std::cout << "Task updated successfully." << std::endl;
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}


void displayTasks() {
    if (tasks.empty()) {
        std::cout << "No tasks to display." << std::endl;
    } else {
        std::cout << "Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i << ". " << tasks[i].description;
            if (tasks[i].completed) {
                std::cout << " (Completed)";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    
    void (*functionPtr[])() = {addTask, deleteTask, updateTask, displayTasks};
    
    while (true) {
        
        std::cout << "\nChoose an action:" << std::endl;
        std::cout << "1. Add a new task" << std::endl;
        std::cout << "2. Delete a task" << std::endl;
        std::cout << "3. Update a task" << std::endl;
        std::cout << "4. Display all tasks" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 4) {
            functionPtr[choice - 1](); 
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void addTask(vector<Task> &tasks, const string &description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully." << endl;
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks found." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << " - " << (tasks[i].completed ? "Completed" : "Pending") << endl;
        }
    }
}

void markTaskCompleted(vector<Task> &tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

void removeTask(vector<Task> &tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        cout << "Task removed successfully." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n===== TO-DO LIST MANAGER =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                size_t index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                markTaskCompleted(tasks, index - 1);
                break;
            }
            case 4: {
                size_t index;
                cout << "Enter task index to remove: ";
                cin >> index;
                removeTask(tasks, index - 1);
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}


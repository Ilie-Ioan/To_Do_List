# To-Do List Application

## Description

The To-Do List application is developed using C++ and the Qt framework. It allows users to create, manage, and track their tasks efficiently. The application includes a user authentication system, where users can sign up and log in, and a task management system that lets them add and view tasks with specific details such as title, description, due date, and priority.

## Features

- **User Authentication**: 
  - Users can register for new accounts and log in with existing credentials.
  - The sign-up process includes validation for username uniqueness, valid email format, and password complexity.
  
- **Task Management**:
  - Users can add tasks, which include a title, description, due date, and priority level.
  - The application displays tasks in a list, sorted by priority.

- **Dynamic User Interface**:
  - Provides immediate feedback for user actions, including error messages and confirmation dialogs.

- **Persistent Storage**:
  - User data and tasks are stored in text files, ensuring data retention across sessions.

## File Structure

The application is organized into several key components:

- **`login.h` / `login.cpp`**: Contains the `Login` class for user authentication and navigation to the task management interface.
- **`signup.h` / `signup.cpp`**: Implements the `SignUp` class, responsible for handling new user registrations, including validation and error handling.
- **`to_do.h` / `to_do.cpp`**: Defines the `To_Do` class, which manages task display and operations for the logged-in user.
- **`add.h` / `add.cpp`**: Implements the `add` class, responsible for adding new tasks to the user's task list.

## Installation

To build and run the application, follow these steps:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/Ilie-Ioan/To_Do_List.git
   cd To_Do_List
   
2. **Install Qt**: Ensure that you have Qt installed. You can download it from the [official Qt website](https://www.qt.io/download).

3. **Open the project**: Use Qt Creator to open the `.pro` file located in the project directory.

4. **Build the project**: Click on the "Build" button in Qt Creator to compile the application.

5. **Run the application**: After building, run the application through Qt Creator.

## Class Functionality

### Login Class
- **Constructor**: Initializes the login window and sets up connections to the sign-up and to-do windows.
- **on_SignUp_but_clicked()**: Displays the sign-up form and hides the login window.
- **on_Login_but_clicked()**: Validates user credentials and, if successful, opens the To-Do window.
- **isValidCredentials()**: Checks user credentials against the stored data in `utilizatori.txt`.
- **showMessage()**: Displays a message box with a confirmation or error message.
- **clearError()**: Clears error messages in the UI.

### SignUp Class
- **Constructor**: Initializes the sign-up window and loads existing users from the file.
- **on_SignUp_but_clicked()**: Validates user input and registers a new user if all checks pass.
- **loadUsers()**: Loads existing users from `utilizatori.txt` to check for unique usernames.
- **ValidateInput()**: Validates that all fields are filled and that passwords match.
- **isUserTaken()**: Checks if the entered username is already taken.
- **isEmailValid()**: Validates the format of the email address.
- **isValidPassword()**: Checks if the password meets the complexity requirements.
- **showMessage()**: Displays a confirmation message box.
- **saveUser()**: Saves the new user's details to the `utilizatori.txt` file.
- **on_Cancel_but_clicked()**: Cancels the sign-up process and returns to the login window.
- **on_checkBox_stateChanged()**: Toggles password visibility for the password field.
- **on_checkBox_2_stateChanged()**: Toggles password visibility for the confirmation field.

### To_Do Class
- **Constructor**: Initializes the To-Do window and sets up the task management interface.
- **set_Username()**: Displays the logged-in user's name and loads their tasks.
- **loadTasksForUser()**: Reads and displays tasks from the user's task file, sorted by priority.
- **on_add_but_clicked()**: Opens the task addition window and hides the current interface.
- **on_refresh_but_clicked()**: Reloads the tasks for the currently logged-in user.
- **on_exit_but_clicked()**: Exits the application.
- **on_sign_button_clicked()**: Returns to the login window.

### Add Class
- **Constructor**: Initializes the task addition window, including setting up the priority combo box.
- **on_add_butt_clicked()**: Validates the input fields and adds a new task to the user's task file.
- **setUsername()**: Sets the current username for the task file.
- **reset_fields()**: Resets the input fields to their default state.
- **on_close_butt_clicked()**: Closes the task addition window and returns to the To-Do list.

## Future Enhancements

- **Password Hashing**: Implement secure password storage using hashing (e.g., SHA-256) to enhance security.
- **Task Editing and Deletion**: Allow users to edit or delete existing tasks.
- **Sorting and Filtering**: Implement advanced sorting and filtering options for tasks.
- **Due Date Reminders**: Add a feature to notify users of upcoming due dates.
- **User Preferences**: Enable users to customize their application experience (e.g., themes, layouts).


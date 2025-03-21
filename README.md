# MyProjects
This Repo are containing all projects in Abo_Hadhood Course. Project Bank 

Got it! Here's a detailed description of the code above in English, focusing on the **Bank** and the enhancements made to it.

---

### **Code Description: Bank**

This code is a comprehensive banking system written in **C++**. It allows for the management of clients and users, as well as financial transactions such as deposits and withdrawals. The code includes significant improvements compared to the initial version, particularly in the area of transaction management.

---

### **Key Features:**

1. **Client Management:**
   - **Display Client List:** Displays the data of all clients stored in the `Clients.txt` file.
   - **Add New Client:** Adds a new client after ensuring that no account with the same number exists.
   - **Delete Client:** Deletes a client based on their account number after user confirmation.
   - **Update Client Data:** Modifies client data such as name, phone number, PIN code, and account balance.
   - **Find Client:** Searches for a client using their account number and displays their details.

2. **User Management:**
   - **Display User List:** Displays the data of all users stored in the `Users.txt` file.
   - **Add New User:** Adds a new user after ensuring that no user with the same username exists.
   - **Delete User:** Deletes a user based on their username after user confirmation (except for the "Admin" user).
   - **Update User Data:** Modifies user data such as password and permissions.
   - **Find User:** Searches for a user using their username and displays their details.

3. **Transaction Management:**
   - **Deposit:**
     - Allows users to deposit money into a client's account.
     - Ensures the account exists before processing the deposit.
     - Updates the account balance and saves the changes to the file.
   - **Withdraw:**
     - Allows users to withdraw money from a client's account.
     - Checks if the account has sufficient balance before allowing the withdrawal.
     - If the balance is insufficient, the user is prompted to enter a valid amount.
     - Updates the account balance and saves the changes to the file.
   - **Total Balances:**
     - Displays the total balance of all clients in the system.

4. **Permissions and Access Control:**
   - The system uses an enumeration (`enMainMenuePermissions`) to define different permissions.
   - The `CheckAccessPermission` function ensures that users can only perform actions they are authorized to do.
   - For example, only users with the appropriate permissions can add, delete, or update clients and users.

5. **File Handling:**
   - The program reads from and writes to two text files: `Clients.txt` and `Users.txt`.
   - Functions like `LoadCleintsDataFromFile`, `SaveCleintsDataToFile`, `LoadUsersDataFromFile`, and `SaveUsersDataToFile` handle file operations.
   - This ensures data persistence and consistency across multiple runs of the program.

6. **User-Friendly Interface:**
   - The program uses a **menu-driven approach** to make it easy for users to navigate and perform actions.
   - Each menu provides clear options and guides the user through the process.

7. **Error Handling and Validation:**
   - The program includes checks to ensure that accounts exist before performing transactions.
   - For withdrawals, it ensures that the account has sufficient balance.
   - It also validates user input to prevent errors.

---

### **How It Works:**

1. **Login Screen:**
   - The program starts with a login screen where users enter their username and password.
   - If the credentials are correct, the user is granted access to the main menu based on their permissions.

2. **Main Menu:**
   - The main menu provides options for managing clients, performing transactions, managing users, and logging out.
   - Each option leads to a sub-menu or screen where the user can perform specific actions.

3. **Transactions Menu:**
   - The transactions menu allows users to deposit, withdraw, or view total balances.
   - Each transaction is confirmed by the user before being processed.

4. **Data Persistence:**
   - All changes (e.g., adding, deleting, or updating clients and users) are saved to the respective files (`Clients.txt` and `Users.txt`).
   - This ensures that data is preserved even after the program is closed.

---

### **Example Workflow:**

1. **Login:**
   - The user logs in with their username and password.
   - If the credentials are valid, they are taken to the main menu.

2. **Add New Client:**
   - The user selects the "Add New Client" option from the main menu.
   - They enter the client's details (account number, PIN code, name, phone, and balance).
   - The program checks if the account number already exists and saves the new client to the file.

3. **Deposit Money:**
   - The user selects the "Deposit" option from the transactions menu.
   - They enter the account number and the amount to deposit.
   - The program updates the client's balance and saves the changes to the file.

4. **View Total Balances:**
   - The user selects the "Total Balances" option from the transactions menu.
   - The program calculates and displays the total balance of all clients.

5. **Log Out:**
   - The user selects the "Log Out" option from the main menu.
   - The program returns to the login screen.

---

### **Enhancements Compared to the Initial Version:**

1. **Transaction Management:**
   - The ability to deposit and withdraw money was added.
   - The program ensures that transactions are confirmed and valid before processing them.

2. **Permissions System:**
   - A permissions system was introduced to restrict access to certain features based on user roles.

3. **Improved File Handling:**
   - The program now handles file operations more efficiently, ensuring data integrity and persistence.

4. **User-Friendly Menus:**
   - The menu-driven interface makes the program easier to use and navigate.

---

### **Conclusion:**

This code is a robust and user-friendly banking system that allows for efficient management of clients, users, and financial transactions. The enhancements made in this version, particularly in transaction management and permissions, make it a significant improvement over the initial project. It is a great example of how to build a functional and secure system using C++.

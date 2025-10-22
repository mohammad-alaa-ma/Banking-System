https://github.com/user-attachments/assets/33bd3e9d-2a68-482a-a664-edff8e5ea87e


# Banking Management System

A comprehensive C++ console-based application designed to manage banking operations efficiently. This system provides a secure, user-friendly interface for managing clients, users, transactions, and currency exchanges with role-based access control.

## Table of Contents

- [Features](#features)
- [Architecture](#architecture)
- [Project Structure](#project-structure)
- [Data Models](#data-models)
- [Technical Specifications](#technical-specifications)
- [Installation & Setup](#installation--setup)
- [Usage](#usage)
- [Security Features](#security-features)
- [Contributing](#contributing)
- [License](#license)

## Features

### Core Banking Operations

#### Client Management
- **Client List**: View all registered clients with detailed account information
- **Add New Client**: Create new client accounts with personal and banking details
- **Delete Client**: Remove inactive or invalid client accounts
- **Update Client Info**: Modify existing client information
- **Find Client**: Search clients by account number or other identifiers

#### Transaction Management
- **Deposit**: Add funds to client accounts
- **Withdraw**: Remove funds from client accounts (with balance validation)
- **Transfer**: Transfer funds between client accounts with logging
- **Total Balances**: View aggregate balance across all accounts
- **Transfer Log**: Track all transfer transactions with timestamps

#### User Management
- **User Administration**: Create, update, delete, and find system users
- **Role-Based Access Control**: Assign permissions to users for different operations
- **Login/Register**: Secure authentication with activity logging

#### Currency Exchange
- **Currency List**: View all supported currencies and their rates
- **Find Currency**: Search for specific currency information
- **Update Rates**: Modify currency exchange rates
- **Currency Calculator**: Convert amounts between different currencies

## Architecture

### Design Patterns
- **Object-Oriented Design**: Extensive use of inheritance, polymorphism, and encapsulation
- **MVC Pattern**: Separation of data models, business logic, and user interface
- **Singleton Pattern**: Global user session management
- **Factory Pattern**: Object creation for different modes (Add/Update)

### Key Components

#### Core Classes
- `clsPerson`: Base class for personal information
- `clsBankClient`: Client account management with file-based persistence
- `clsUser`: System user management with permissions
- `clsCurrency`: Currency exchange functionality

#### Utility Classes
- `clsDate`: Date manipulation and formatting
- `clsString`: String processing utilities
- `clsInputValidate`: Input validation and sanitization
- `clsUtil`: General utilities including encryption

#### Screen Classes
- Menu-driven console interface
- Protected screen base class with access control
- Modular screen organization by functionality

## Project Structure

```
Banking-System/
├── main.cpp                    # Application entry point
├── Global.h                    # Global variables and includes
├── README.md                   # Project documentation
├── Classes/
│   ├── Core/
│   │   ├── clsBankClient.h     # Client account management
│   │   ├── clsCurrency.h       # Currency operations
│   │   ├── clsPerson.h         # Base person class
│   │   └── clsUser.h           # User management
│   ├── Screens/
│   │   ├── clsMainScreen.h     # Main application menu
│   │   ├── clsScreen.h         # Base screen class
│   │   ├── Client/
│   │   │   ├── clsAddNewClientScreen.h
│   │   │   ├── clsClientListScreen.h
│   │   │   ├── clsDeleteClientScreen.h
│   │   │   ├── clsDepositScreen.h
│   │   │   ├── clsFindClientScreen.h
│   │   │   ├── clsTotalBalancesScreen.h
│   │   │   ├── clsTransactionsScreen.h
│   │   │   ├── clsTransferScreen.h
│   │   │   ├── clsTransferLogScreen.h
│   │   │   ├── clsUpdateClientScreen.h
│   │   │   └── clsWithdrawScreen.h
│   │   ├── Currencies/
│   │   │   ├── clsCurrenciesListScreen.h
│   │   │   ├── clsCurrencyCalculatorScreen.h
│   │   │   ├── clsCurrencyExchangeMainScreen.h
│   │   │   ├── clsFindCurrencyScreen.h
│   │   │   └── clsUpdateCurrencyRateScreen.h
│   │   └── User/
│   │       ├── clsAddNewUserScreen.h
│   │       ├── clsDeleteUserScreen.h
│   │       ├── clsFindUserScreen.h
│   │       ├── clsListUsersScreen.h
│   │       ├── clsLoginRegisterScreen.h
│   │       ├── clsLoginScreen.h
│   │       ├── clsManageUsersScreen.h
│   │       └── clsUpdateUserScreen.h
│   └── Utilities/
│       ├── clsDate.h           # Date utilities
│       ├── clsInputValidate.h  # Input validation
│       ├── clsString.h         # String manipulation
│       └── clsUtil.h           # General utilities
└── TextFiles/
    ├── Clients.txt             # Client data storage
    ├── Currencies.txt          # Currency data storage
    ├── LoginRegister.txt       # Login activity log
    ├── TransfersLog.txt        # Transfer transaction log
    └── Users.txt               # User data storage
```

## Data Models

### Client Data Structure
```
FirstName#//#LastName#//#Email#//#Phone#//#AccountNumber#//#PinCode#//#AccountBalance
```

### User Data Structure
```
FirstName#//#LastName#//#Email#//#Phone#//#UserName#//#EncryptedPassword#//#Permissions
```

### Currency Data Structure
```
Country#//#CurrencyCode#//#CurrencyName#//#ExchangeRate
```

### Transfer Log Structure
```
DateTime#//#SourceAccount#//#DestinationAccount#//#Amount#//#SrcBalanceAfter#//#DestBalanceAfter#//#UserName
```

## Technical Specifications

### Programming Language
- **C++**: Standard C++ with console-based interface
- **Compiler**: Compatible with g++ or Visual Studio C++

### Dependencies
- **Standard Library**: iostream, string, vector, fstream, ctime
- **Platform**: Windows (uses `system("cls")` and `system("pause>0")`)

### Data Persistence
- **File-Based Storage**: Text files for data persistence
- **Encryption**: Simple Caesar cipher for password storage
- **Data Format**: Delimiter-separated values (#//#)

### Security Features
- **Authentication**: Username/password login with attempt limiting
- **Authorization**: Role-based permissions system
- **Encryption**: Password encryption in storage
- **Access Control**: Permission checks for all operations
- **Audit Trail**: Login and transfer activity logging

### Permissions System
- **Bitwise Permissions**: Efficient permission checking
- **Granular Control**: Specific permissions for different operations
- **Admin Override**: Full access for administrators

## Installation & Setup

### Prerequisites
- C++ compiler (g++, Visual Studio, or equivalent)
- Windows operating system

### Compilation
```bash
g++ main.cpp -o BankingSystem.exe
```

### Running the Application
```bash
./BankingSystem.exe
```

### Initial Setup
1. Run the application
2. Default admin credentials (if not set):
   - Username: admin
   - Password: admin123

## Usage

### Login Process
1. Enter valid username and password
2. System validates credentials and permissions
3. Access main menu based on user role

### Main Menu Options
1. **Show Client List**: View all clients
2. **Add New Client**: Create client account
3. **Delete Client**: Remove client account
4. **Update Client Info**: Modify client details
5. **Find Client**: Search for specific client
6. **Transactions**: Access transaction submenu
7. **Manage Users**: User administration (admin only)
8. **Login Register**: View login history
9. **Currency Exchange**: Currency operations
10. **Logout**: Secure logout

### Transaction Operations
- **Deposit**: Add funds to account
- **Withdraw**: Remove funds (balance validation)
- **Transfer**: Move funds between accounts
- **Total Balances**: View system-wide balances
- **Transfer Log**: Review transfer history

## Security Features

### Authentication
- Multi-attempt login with lockout after 3 failures
- Encrypted password storage
- Session management

### Authorization
- Permission-based access control
- Admin and regular user roles
- Operation-specific permissions

### Data Protection
- Encrypted sensitive data storage
- Input validation and sanitization
- Secure file operations

### Audit Trail
- Login activity logging
- Transfer transaction logging
- User activity tracking

## Contributing

### Code Standards
- Follow C++ best practices
- Use consistent naming conventions
- Add comments for complex logic
- Maintain modular design

### Development Guidelines
1. Create feature branches for new functionality
2. Test thoroughly before committing
3. Update documentation for changes
4. Follow existing code patterns

---

**Note**: This is a console-based banking system designed for educational and demonstration purposes. In a production environment, additional security measures, database integration, and compliance with banking regulations would be required.


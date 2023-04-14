----------------------------------------------------------------------------------------
CommuniTools

    Introduction:

    This proposal outlines the database application CommuniTools. The purpose of this application is to allow members of a community to share tools with one another, without the need for payment. 
    The application aims to facilitate the borrowing and lending of tools, making it easier for community members to complete DIY projects, repairs, and maintenance.

    The CommuniTools application is designed to promote collaboration and communication within communities by making tool sharing more accessible and convenient. 
    The application is targeted towards small communities where members are interested in sharing tools with one another. With this tool sharing application, 
    community members can borrow the tools they need for a specific amount of time without incurring additional costs.

    The CommuniTools application is developed using C++ and Oracle's OCCI library, iostream, termios, unistd, cstdlib, and iomanip.

    Audience:

    The target audience for the CommuniTools application is members of specific small communities who are interested in sharing tools with one another. 
    The application is designed to appeal to individuals who are community-minded, open to meeting new people, and interested in DIY projects, repairs, and maintenance. 
    CommuniTools is built for users who are comfortable with command line interfaces and enter honest information.
    The tool sharing application is designed to cater to the needs of people who might not have the resources to purchase their own tools, or who might not have access to the tools they need for their projects.

    Functionalities:

    The following requirements have been identified from the hypothetical user:

    - Registration: Users can create a new community member account. The registration process requires users to provide a referral member by ID, their community ID, their name, address, and contact information.

    - Tool Listing: Users can list the tools they own and are willing to lend to others. Each tool listed will be associated with one of the predetermined categories.
    
    - Tool View: Users can view all tools in the database, all tools in a given category, and all tools that they can currently borrow.
    
    - Tool Borrowing: Users can borrow available tools within their community. Users are limited on the number of tools they can borrow at one time.
    
    - Tool Return: Users can return a tool they are currently borrowing.
    
    - Tool Removal: Users can remove a tool if they no longer want to lend it out.
    
    - Login verification: Users must have valid login credentials to the Oracle database as well as the application.


    Constraints:

    - Character Limit: Users are limited to a character limit on the input data which is specified in the table descriptions.
    
    - Security and Validation: 
        - User input is not sanitized however all statements are prepared in construction of the program which prevents SQL injections.
        - Account passwords are stored in plain text which is also a security risk.
        - User input such as email, phone, and address is not verified to be in the correct format or a valid value.
----------------------------------------------------------------------------------------
How to Run:

    1. Enter sql/ folder.

    2. Run sqlplus.
        Enter @create_database.sql then @insert.sql.
    
    3. Return to CommuniTools/ folder and run makefile to compile.

    4. Run program executable: ./communiToolsx.
    
    5. Enter database login.
       Enter application login.
   
       Test login:
       username: user
       password: pass

       If login was successful, the option menu will be shown.
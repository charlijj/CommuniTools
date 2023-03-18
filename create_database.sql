-- Communities (comID, comName, comLocation, comSize)
-- Members (memberID, comID, memberName, address, email, phone)
-- Borrowers (memberID, numToolsBorrowing
-- Categories (catID, catName, catDescription)
-- Tools (toolID, catID, memberID, toolName, borrowStatus, condition
-- BorrowRecord (recordID, memberID, toolID, rentDate, returnDate)

DROP TABLE Communities;
DROP TABLE Members;
DROP TABLE Borrowers;
DROP TABLE Categories;
DROP TABLE Tools;
DROP TABLE BorrowRecord;

CREATE TABLE Communities (
    comID CHAR(5) PRIMARY KEY,
    comName VARCHAR(256),
    comLocation VARCHAR(256),
    comSize NUMBER (8, 0)
);

CREATE TABLE Members (
    memberID CHAR(5) PRIMARY KEY,
    comID CHAR(5) REFERENCES Communities,
    memberName VARCHAR(256),
    address VARCHAR(256),
    email VARCHAR(256),
    phone VARCHAR(11)
);

CREATE TABLE Borrowers (
    memberID CHAR(5) PRIMARY KEY REFERENCES Members,
    numToolsBorrowing NUMBER(1, 0)
);

CREATE TABLE Categories (
    catID CHAR(5) PRIMARY KEY,
    catName VARCHAR(256),
    catDescription VARCHAR(256)
);

CREATE TABLE Tools (
    toolID CHAR(5) PRIMARY KEY,
    catID CHAR(5) REFERENCES Categories,
    memberID CHAR(5) REFERENCES Members,
    toolName VARCHAR(256),
    borrowStatus NUMBER(1, 0),
    condition VARCHAR(32)
);

CREATE TABLE BorrowRecord (
    recordID CHAR(5) PRIMARY KEY,
    memberID CHAR(5) REFERENCES Members,
    toolID CHAR(5) REFERENCES Tools,
    rentDate DATE,
    returnDate DATE
);

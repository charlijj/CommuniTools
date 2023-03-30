-- Schema --------------------------------------------------------------

-- Communities (comID, comName, comLocation, comSize)
-- CommunityMembers (memberID, comID, memberName, address, email, phone)
-- Borrowers (memberID, numToolsBorrowing
-- Categories (catID, catName, catDescription)
-- Tools (toolID, catID, memberID, toolName, borrowStatus, condition
-- BorrowRecords (recordID, memberID, toolID, rentDate, returnDate)

-------------------------------------------------------------------------

DROP TRIGGER trg_Communities;
DROP SEQUENCE comID_seq;

DROP TRIGGER trg_CommunityMembers;
DROP SEQUENCE memberID_seq;

DROP TRIGGER trg_ToolCategories;
DROP SEQUENCE catID_seq;

DROP TRIGGER trg_CommunityTools;
DROP SEQUENCE toolID_seq;

DROP TRIGGER trg_BorrowRecords;
DROP SEQUENCE recordID_seq;

DROP TABLE BorrowRecords CASCADE CONSTRAINTS;
DROP TABLE CommunityTools CASCADE CONSTRAINTS;
DROP TABLE ToolCategories CASCADE CONSTRAINTS;
DROP TABLE Borrowers CASCADE CONSTRAINTS;
DROP TABLE CommunityMembers CASCADE CONSTRAINTS;
DROP TABLE Communities CASCADE CONSTRAINTS;

CREATE TABLE Communities (
    comID NUMBER(5) PRIMARY KEY ,
    comName VARCHAR(256),
    comLocation VARCHAR(256),
    comSize NUMBER (8, 0)
);

CREATE TABLE CommunityMembers (
    memberID NUMBER(5) PRIMARY KEY,
    comID NUMBER(5) REFERENCES Communities,
    firstName VARCHAR(256),
    lastName VARCHAR(256),
    address VARCHAR(256),
    email VARCHAR(256),
    phone VARCHAR(15),
    username VARCHAR(256),
    password VARCHAR(256)
);

CREATE TABLE Borrowers (
    memberID NUMBER(5) PRIMARY KEY REFERENCES CommunityMembers,
    numToolsBorrowing NUMBER(2, 0) DEFAULT 0
);

CREATE TABLE ToolCategories (
    catID NUMBER(5) PRIMARY KEY,
    catName VARCHAR(256),
    catDescription VARCHAR(256)
);

CREATE TABLE CommunityTools (
    toolID NUMBER(5) PRIMARY KEY,
    catID NUMBER(5) REFERENCES ToolCategories,
    memberID NUMBER(5) REFERENCES CommunityMembers,
    toolName VARCHAR(256),
    borrowStatus NUMBER(1, 0) DEFAULT 0,
    condition VARCHAR(256)
);

CREATE TABLE BorrowRecords (
    recordID NUMBER(5) PRIMARY KEY,
    memberID NUMBER(5) REFERENCES CommunityMembers,
    toolID NUMBER(5) REFERENCES CommunityTools,
    rentDate DATE,
    returnDate DATE
);

-- Create sequence to generate IDs for Communities table
CREATE SEQUENCE comID_seq
  START WITH 1
  INCREMENT BY 1;

-- Create trigger to generate IDs for Communities table
CREATE OR REPLACE TRIGGER trg_Communities
BEFORE INSERT ON Communities
FOR EACH ROW
BEGIN
  :NEW.comID := comID_seq.NEXTVAL;
END;
/

-- Create sequence to generate IDs for CommunityMembers table
CREATE SEQUENCE memberID_seq
  START WITH 1
  INCREMENT BY 1;

-- Create trigger to generate IDs for CommunityMembers table
CREATE OR REPLACE TRIGGER trg_CommunityMembers
BEFORE INSERT ON CommunityMembers
FOR EACH ROW
BEGIN
  :NEW.memberID := memberID_seq.NEXTVAL;
END;
/

-- Create sequence to generate IDs for ToolCategories table
CREATE SEQUENCE catID_seq
  START WITH 1
  INCREMENT BY 1;

-- Create trigger to generate IDs for ToolCategories table
CREATE OR REPLACE TRIGGER trg_ToolCategories
BEFORE INSERT ON ToolCategories
FOR EACH ROW
BEGIN
  :NEW.catID := catID_seq.NEXTVAL;
END;
/

-- Create sequence to generate IDs for CommunityTools table
CREATE SEQUENCE toolID_seq
  START WITH 1
  INCREMENT BY 1;

-- Create trigger to generate IDs for CommunityTools table
CREATE OR REPLACE TRIGGER trg_CommunityTools
BEFORE INSERT ON CommunityTools
FOR EACH ROW
BEGIN
  :NEW.toolID := toolID_seq.NEXTVAL;
END;
/

-- Create sequence to generate IDs for BorrowRecords table
CREATE SEQUENCE recordID_seq
  START WITH 1
  INCREMENT BY 1;

-- Create trigger to generate IDs for BorrowRecords table
CREATE OR REPLACE TRIGGER trg_BorrowRecords
BEFORE INSERT ON BorrowRecords
FOR EACH ROW
BEGIN
  :NEW.recordID := recordID_seq.NEXTVAL;
END;
/

-- describe Communities;
-- describe CommunityMembers;
-- describe Borrowers;
-- describe ToolCategories;
-- describe BorrowRecords;

commit;
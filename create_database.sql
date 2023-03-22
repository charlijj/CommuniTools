-- Communities (comID, comName, comLocation, comSize)
-- CommunityMembers (memberID, comID, memberName, address, email, phone)
-- Borrowers (memberID, numToolsBorrowing
-- Categories (catID, catName, catDescription)
-- Tools (toolID, catID, memberID, toolName, borrowStatus, condition
-- BorrowRecord (recordID, memberID, toolID, rentDate, returnDate)

DROP TABLE BorrowRecord;
DROP TABLE CommunityTools;
DROP TABLE ToolCategories;
DROP TABLE Borrowers;
DROP TABLE CommunityMembers;
DROP TABLE Communities;

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
    phone VARCHAR(15)
);

CREATE TABLE Borrowers (
    memberID NUMBER(5) PRIMARY KEY REFERENCES CommunityMembers,
    numToolsBorrowing NUMBER(1, 0)
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
    condition VARCHAR(32)
);

CREATE TABLE BorrowRecord (
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

-- Create sequence to generate IDs for Borrowers table
CREATE SEQUENCE borrowerID_seq
  START WITH 1
  INCREMENT BY 1;

-- Create trigger to generate IDs for Borrowers table
CREATE OR REPLACE TRIGGER trg_Borrowers
BEFORE INSERT ON Borrowers
FOR EACH ROW
BEGIN
  :NEW.memberID := borrowerID_seq.NEXTVAL;
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

-- Create sequence to generate IDs for BorrowRecord table
CREATE SEQUENCE recordID_seq
  START WITH 1
  INCREMENT BY 1;

-- Create trigger to generate IDs for BorrowRecord table
CREATE OR REPLACE TRIGGER trg_BorrowRecord
BEFORE INSERT ON BorrowRecord
FOR EACH ROW
BEGIN
  :NEW.recordID := recordID_seq.NEXTVAL;
END;
/


-- describe Communities;
-- describe CommunityMembers;
-- describe Borrowers;
-- describe ToolCategories;
-- describe BorrowRecord;

INSERT INTO Communities (comName, comLocation, comSize) VALUES ('Old City Quarter', 'Nanaimo BC', 2000);
INSERT INTO Communities (comName, comLocation, comSize) VALUES ('University Village', 'Nanaimo BC', 1200);
INSERT INTO Communities (comName, comLocation, comSize) VALUES ('Westwood Lake', 'Nanaimo BC', 1000);

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone) 
-- VALUES ('00001', 'Jasper', 'Char', '788 Street St, Nanaimo BC', 'mail@mail.com', '250-111-2222');
-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone) 
-- VALUES ('00001', 'Mary', 'Loop', '44 Mega St, Nanaimo BC', 'mail@mail.com', '250-555-4444');
-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone) 
-- VALUES ('00003', 'Jhon', 'Bee', '89 Last St, Nanaimo BC', 'mail@mail.com', '250-999-2222');

commit;
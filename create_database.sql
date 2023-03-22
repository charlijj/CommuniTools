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

CREATE SEQUENCE id_seq
  START WITH 1
  INCREMENT BY 1;

CREATE TABLE Communities (
    comID NUMBER(5) PRIMARY KEY ,
    comName VARCHAR(256),
    comLocation VARCHAR(256),
    comSize NUMBER (8, 0)
);

CREATE TABLE CommunityMembers (
    memberID NUMBER(5) PRIMARY KEY,
    comID CHAR(5) REFERENCES Communities,
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

CREATE SEQUENCE id_seq
  START WITH 1
  INCREMENT BY 1;


-- Create trigger to generate IDs for all tables

CREATE OR REPLACE TRIGGER trg_id_seq
BEFORE INSERT ON Communities
FOR EACH ROW
BEGIN
  :NEW.comID := id_seq.NEXTVAL;
END;
/

CREATE OR REPLACE TRIGGER trg_id_seq
BEFORE INSERT ON CommunityMembers
FOR EACH ROW
BEGIN
  :NEW.memberID := id_seq.NEXTVAL;
END;
/

CREATE OR REPLACE TRIGGER trg_id_seq
BEFORE INSERT ON Borrowers
FOR EACH ROW
BEGIN
  :NEW.memberID := id_seq.NEXTVAL;
END;
/

CREATE OR REPLACE TRIGGER trg_id_seq
BEFORE INSERT ON ToolCategories
FOR EACH ROW
BEGIN
  :NEW.catID := id_seq.NEXTVAL;
END;
/

CREATE OR REPLACE TRIGGER trg_id_seq
BEFORE INSERT ON CommunityTools
FOR EACH ROW
BEGIN
  :NEW.toolID := id_seq.NEXTVAL;
END;
/

CREATE OR REPLACE TRIGGER trg_id_seq
BEFORE INSERT ON BorrowRecord
FOR EACH ROW
BEGIN
  :NEW.recordID := id_seq.NEXTVAL;
END;
/

-- describe Communities;
-- describe CommunityMembers;
-- describe Borrowers;
-- describe ToolCategories;
-- describe BorrowRecord;

INSERT INTO Communities (comID, comName, comLocation, comSize) VALUES ('00001', 'Old City Quarter', 'Nanaimo BC', 2000);
INSERT INTO Communities (comID, comName, comLocation, comSize) VALUES ('00002', 'University Village', 'Nanaimo BC', 1200);
INSERT INTO Communities (comID, comName, comLocation, comSize) VALUES ('00003', 'Westwood Lake', 'Nanaimo BC', 1000);

INSERT INTO CommunityMembers (memberID, comID, firstName, lastName, address, email, phone) 
VALUES ('00001', '00001', 'Jasper', 'Char', '788 Street St, Nanaimo BC', 'mail@mail.com', '250-111-2222');
INSERT INTO CommunityMembers (memberID, comID, firstName, lastName, address, email, phone) 
VALUES ('00002', '00001', 'Mary', 'Loop', '44 Mega St, Nanaimo BC', 'mail@mail.com', '250-555-4444');
INSERT INTO CommunityMembers (memberID, comID, firstName, lastName, address, email, phone) 
VALUES ('00003', '00003', 'Jhon', 'Bee', '89 Last St, Nanaimo BC', 'mail@mail.com', '250-999-2222');

commit;
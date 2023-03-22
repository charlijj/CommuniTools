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

-- CREATE OR REPLACE SEQUENCE to generate IDs for Communities table
CREATE OR REPLACE SEQUENCE comID_seq
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

-- CREATE OR REPLACE SEQUENCE to generate IDs for CommunityMembers table
CREATE OR REPLACE SEQUENCE memberID_seq
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

-- CREATE OR REPLACE SEQUENCE to generate IDs for Borrowers table
CREATE OR REPLACE SEQUENCE borrowerID_seq
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

-- CREATE OR REPLACE SEQUENCE to generate IDs for ToolCategories table
CREATE OR REPLACE SEQUENCE catID_seq
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

-- CREATE OR REPLACE SEQUENCE to generate IDs for CommunityTools table
CREATE OR REPLACE SEQUENCE toolID_seq
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

-- CREATE OR REPLACE SEQUENCE to generate IDs for BorrowRecord table
CREATE OR REPLACE SEQUENCE recordID_seq
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
INSERT INTO Communities (comName, comLocation, comSize) VALUES ('Downtown Strip', 'Nanaimo BC', 3000);
INSERT INTO Communities (comName, comLocation, comSize) VALUES ('North Field', 'Nanaimo BC', 3000);
INSERT INTO Communities (comName, comLocation, comSize) VALUES ('Departure Bay', 'Nanaimo BC', 2000);
INSERT INTO Communities (comName, comLocation, comSize) VALUES ('Hammond Bay', 'Nanaimo BC', 1600);
INSERT INTO Communities (comName, comLocation, comSize) VALUES ('Woodgrove', 'Nanaimo BC', 4000);
INSERT INTO Communities (comName, comLocation, comSize) VALUES ('Lantzville', 'Lantzville BC', 4000);
INSERT INTO Communities (comName, comLocation, comSize) VALUES ('Cedar', 'Cedar BC', 4000);

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone) 
VALUES (1, 'Jasper', 'Char', '788 Street St, Nanaimo BC', 'mail@mail.com', '250-111-2222');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone) 
VALUES (2, 'Mary', 'Loop', '44 Mega St, Nanaimo BC', 'mail@mail.com', '250-555-4444');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone) 
-- VALUES (3, 'Jhon', 'Bee', '89 Last St, Nanaimo BC', 'mail@mail.com', '250-999-2222');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (1, 'John', 'Doe', '123 Main St', 'johndoe@email.com', '123-456-7890');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (1, 'Jane', 'Smith', '456 Oak St', 'janesmith@email.com', '234-567-8901');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (1, 'Bob', 'Johnson', '789 Maple St', 'bobjohnson@email.com', '345-678-9012');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (2, 'Alice', 'Lee', '321 Pine St', 'alicelee@email.com', '456-789-0123');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (2, 'Tom', 'Williams', '654 Birch St', 'tomwilliams@email.com', '567-890-1234');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (2, 'Samantha', 'Taylor', '987 Cedar St', 'samanthataylor@email.com', '678-901-2345');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (3, 'Mike', 'Brown', '753 Elm St', 'mikebrown@email.com', '789-012-3456');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (3, 'Emily', 'Davis', '159 Spruce St', 'emilydavis@email.com', '890-123-4567');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (4, 'David', 'Wilson', '951 Oak St', 'davidwilson@email.com', '901-234-5678');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (4, 'Linda', 'Miller', '753 Maple St', 'lindamiller@email.com', '012-345-6789');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (5, 'Jean-Luc', 'Picard', '123 Main St', 'jlpicard@enterprise.com', '555-555-1212');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (5, 'William', 'Riker', '456 Second St', 'wriker@enterprise.com', '555-555-2323');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (5, 'Geordi', 'La Forge', '789 Third St', 'glaforge@enterprise.com', '555-555-3434');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (5, 'Data', '', '321 Fourth St', 'data@enterprise.com', '555-555-4545');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (5, 'Deanna', 'Troi', '654 Fifth St', 'dtroi@enterprise.com', '555-555-5656');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (6, 'Kathryn', 'Janeway', '123 Voyager Way', 'kjaneway@voyager.com', '555-555-6767');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (6, 'Chakotay', '', '456 Voyager Way', 'chakotay@voyager.com', '555-555-7878');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (6, 'Tuvok', '', '789 Voyager Way', 'tuvok@voyager.com', '555-555-8989');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (6, 'Seven', 'of Nine', '321 Voyager Way', 'seven@voyager.com', '555-555-9090');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (6, 'Tom', 'Paris', '654 Voyager Way', 'tparis@voyager.com', '555-555-0101');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (7, 'Benjamin', 'Sisko', '123 Deep Space Nine', 'bsisko@ds9.com', '555-555-1212');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (7, 'Kira', 'Nerys', '456 Deep Space Nine', 'knerys@ds9.com', '555-555-2323');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (10, 'Odo', '', '789 Deep Space Nine', 'odo@ds9.com', '555-555-3434');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (8, 'Quark', '', '321 Deep Space Nine', 'quark@ds9.com', '555-555-4545');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (7, 'Luke', 'Skywalker', '123 Tatooine Way', 'lukeskywalker@email.com', '012-345-6789');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (8, 'Leia', 'Organa', '456 Alderaan Rd', 'leiaorgana@email.com', '012-345-6789');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (9, 'Han', 'Solo', '789 Millennium Falcon Dr', 'hansolo@email.com', '012-345-6789');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (10, 'Chewbacca', 'Wookie', '1011 Kashyyyk Blvd', 'chewie@wookie.com', '012-345-6789');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (7, 'Obi-Wan', 'Kenobi', '121 Naboo Rd', 'obiwankenobi@email.com', '012-345-6789');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (8, 'Darth', 'Vader', '141 Coruscant Ave', 'darthvader@sith.com', '012-345-6789');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (9, 'Boba', 'Fett', '161 Kamino Blvd', 'bobafett@mandalorian.com', '012-345-6789');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (10, 'Yoda', '', '181 Dagobah St', 'yoda@jedi.com', '012-345-6789');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (7, 'Padmé', 'Amidala', '202 Coruscant Blvd', 'padmeamidala@naboo.com', '012-345-6789');

-- INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
-- VALUES (8, 'Emperor', 'Palpatine', '222 Imperial Palace', 'emperorpalpatine@sith.com', '012-345-6789');

-- INSERT INTO ToolCategories (catName, catDescription) 
-- VALUES ('Hand Tools', 'Tools powered by hand, not electricity or other external power sources.');

-- INSERT INTO ToolCategories (catName, catDescription) 
-- VALUES ('Power Tools', 'Tools powered by electricity or other external power sources.');

-- INSERT INTO ToolCategories (catName, catDescription) 
-- VALUES ('Gardening Tools', 'Tools designed specifically for gardening and landscaping tasks.');

-- INSERT INTO ToolCategories (catName, catDescription) 
-- VALUES ('Woodworking Tools', 'Tools used in the crafting and shaping of wood.');

-- INSERT INTO ToolCategories (catName, catDescription)
-- VALUES ('Plumbing Tools', 'Tools designed for plumbing tasks, such as repairing pipes or installing fixtures.');

-- INSERT INTO ToolCategories (catName, catDescription) 
-- VALUES ('Automotive Tools', 'Tools used in the maintenance and repair of automobiles.');

-- INSERT INTO ToolCategories (catName, catDescription) 
-- VALUES ('Construction Tools', 'Tools used in the construction industry, such as hammers, saws, and drills.');

-- INSERT INTO ToolCategories (catName, catDescription) 
-- VALUES ('Cleaning Tools', 'Tools designed for cleaning tasks, such as brooms, mops, and vacuums.');

-- INSERT INTO ToolCategories (catName, catDescription) 
-- VALUES ('Electrical Tools', 'Tools used in electrical work, such as wire cutters and voltage testers.');

-- INSERT INTO ToolCategories (catName, catDescription) 
-- VALUES ('Painting Tools', 'Tools designed for painting tasks, such as paint brushes and rollers.');


commit;
-- Insert Communities ----------------------------------------------------
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
-----------------------------------------------------------------------------
-- Insert Members -----------------------------------------------------------
INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone) 
VALUES (1, 'Jasper', 'Char', '788 Street St, Nanaimo BC', 'mail@mail.com', '250-111-2222');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone) 
VALUES (2, 'Mary', 'Loop', '44 Mega St, Nanaimo BC', 'mail@mail.com', '250-555-4444');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone) 
VALUES (3, 'Jhon', 'Bee', '89 Last St, Nanaimo BC', 'mail@mail.com', '250-999-2222');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (1, 'John', 'Doe', '123 Main St', 'johndoe@email.com', '123-456-7890');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (1, 'Jane', 'Smith', '456 Oak St', 'janesmith@email.com', '234-567-8901');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (1, 'Bob', 'Johnson', '789 Maple St', 'bobjohnson@email.com', '345-678-9012');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (2, 'Alice', 'Lee', '321 Pine St', 'alicelee@email.com', '456-789-0123');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (2, 'Tom', 'Williams', '654 Birch St', 'tomwilliams@email.com', '567-890-1234');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (2, 'Samantha', 'Taylor', '987 Cedar St', 'samanthataylor@email.com', '678-901-2345');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (3, 'Mike', 'Brown', '753 Elm St', 'mikebrown@email.com', '789-012-3456');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (3, 'Emily', 'Davis', '159 Spruce St', 'emilydavis@email.com', '890-123-4567');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (4, 'David', 'Wilson', '951 Oak St', 'davidwilson@email.com', '901-234-5678');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (4, 'Linda', 'Miller', '753 Maple St', 'lindamiller@email.com', '012-345-6789');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (5, 'Jean-Luc', 'Picard', '123 Main St', 'jlpicard@enterprise.com', '555-555-1212');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (5, 'William', 'Riker', '456 Second St', 'wriker@enterprise.com', '555-555-2323');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (5, 'Geordi', 'La Forge', '789 Third St', 'glaforge@enterprise.com', '555-555-3434');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (5, 'Data', '', '321 Fourth St', 'data@enterprise.com', '555-555-4545');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (5, 'Deanna', 'Troi', '654 Fifth St', 'dtroi@enterprise.com', '555-555-5656');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (6, 'Kathryn', 'Janeway', '123 Voyager Way', 'kjaneway@voyager.com', '555-555-6767');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (6, 'Chakotay', '', '456 Voyager Way', 'chakotay@voyager.com', '555-555-7878');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (6, 'Tuvok', '', '789 Voyager Way', 'tuvok@voyager.com', '555-555-8989');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (6, 'Seven', 'of Nine', '321 Voyager Way', 'seven@voyager.com', '555-555-9090');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (6, 'Tom', 'Paris', '654 Voyager Way', 'tparis@voyager.com', '555-555-0101');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (7, 'Benjamin', 'Sisko', '123 Deep Space Nine', 'bsisko@ds9.com', '555-555-1212');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (7, 'Kira', 'Nerys', '456 Deep Space Nine', 'knerys@ds9.com', '555-555-2323');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (10, 'Odo', '', '789 Deep Space Nine', 'odo@ds9.com', '555-555-3434');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (8, 'Quark', '', '321 Deep Space Nine', 'quark@ds9.com', '555-555-4545');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (7, 'Luke', 'Skywalker', '123 Tatooine Way', 'lukeskywalker@email.com', '012-345-6789');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (8, 'Leia', 'Organa', '456 Alderaan Rd', 'leiaorgana@email.com', '012-345-6789');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (9, 'Han', 'Solo', '789 Millennium Falcon Dr', 'hansolo@email.com', '012-345-6789');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (10, 'Chewbacca', 'Wookie', '1011 Kashyyyk Blvd', 'chewie@wookie.com', '012-345-6789');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (7, 'Obi-Wan', 'Kenobi', '121 Naboo Rd', 'obiwankenobi@email.com', '012-345-6789');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (8, 'Darth', 'Vader', '141 Coruscant Ave', 'darthvader@sith.com', '012-345-6789');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (9, 'Boba', 'Fett', '161 Kamino Blvd', 'bobafett@mandalorian.com', '012-345-6789');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (10, 'Yoda', '', '181 Dagobah St', 'yoda@jedi.com', '012-345-6789');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (7, 'Padmé', 'Amidala', '202 Coruscant Blvd', 'padmeamidala@naboo.com', '012-345-6789');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone)
VALUES (8, 'Emperor', 'Palpatine', '222 Imperial Palace', 'emperorpalpatine@sith.com', '012-345-6789');
-----------------------------------------------------------------------------
-- Insert Categories --------------------------------------------------------

INSERT INTO ToolCategories (catName, catDescription) 
VALUES ('Hand Tools', 'Tools powered by hand, not electricity or other external power sources.');

INSERT INTO ToolCategories (catName, catDescription) 
VALUES ('Power Tools', 'Tools powered by electricity or other external power sources.');

INSERT INTO ToolCategories (catName, catDescription) 
VALUES ('Gardening Tools', 'Tools designed specifically for gardening and landscaping tasks.');

INSERT INTO ToolCategories (catName, catDescription) 
VALUES ('Woodworking Tools', 'Tools used in the crafting and shaping of wood.');

INSERT INTO ToolCategories (catName, catDescription)
VALUES ('Plumbing Tools', 'Tools designed for plumbing tasks, such as repairing pipes or installing fixtures.');

INSERT INTO ToolCategories (catName, catDescription) 
VALUES ('Automotive Tools', 'Tools used in the maintenance and repair of automobiles.');

INSERT INTO ToolCategories (catName, catDescription) 
VALUES ('Construction Tools', 'Tools used in the construction industry, such as hammers, saws, and drills.');

INSERT INTO ToolCategories (catName, catDescription) 
VALUES ('Cleaning Tools', 'Tools designed for cleaning tasks, such as brooms, mops, and vacuums.');

INSERT INTO ToolCategories (catName, catDescription) 
VALUES ('Electrical Tools', 'Tools used in electrical work, such as wire cutters and voltage testers.');

INSERT INTO ToolCategories (catName, catDescription) 
VALUES ('Painting Tools', 'Tools designed for painting tasks, such as paint brushes and rollers.');
-----------------------------------------------------------------------------
-- Insert Tools -------------------------------------------------------------

-- Hand Tools
INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (1, 1, 'Hammer', 0, 'Good condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (1, 2, 'Screwdriver Set', 0, 'Excellent condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (1, 3, 'Pliers', 0, 'Good condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (1, 4, 'Wrench Set', 0, 'Fair condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (1, 5, 'Hand Saw', 0, 'Good condition');

-- Power Tools
INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (2, 6, 'Power Drill', 0, 'Excellent condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (2, 7, 'Circular Saw', 0, 'Fair condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (2, 8, 'Jigsaw', 0, 'Good condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (2, 9, 'Angle Grinder', 0, 'Excellent condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (2, 10, 'Power Sander', 0, 'Fair condition');

-- Gardening Tools
INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (3, 11, 'Rake', 0, 'Good condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (3, 12, 'Hedge Trimmer', 0, 'Excellent condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (3, 13, 'Lawn Mower', 0, 'Fair condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (3, 14, 'Pruning Shears', 0, 'Good condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (3, 15, 'Garden Trowel', 0, 'Excellent condition');

-- Woodworking Tools
INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (4, 16, 'Chisel Set', 0, 'Good condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (4, 17, 'Hand Planer', 0, 'Excellent condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (4, 18, 'Woodworking Clamps', 0, 'Fair condition');

-- Automotive Tools

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (5, 3, 'Pipe Wrench', 0, 'Like new');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (5, 5, 'Pliers', 0, 'Good condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (5, 6, 'Socket Set', 0, 'New');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (5, 11, 'Jump Starter', 0, 'Fair condition');

-- Construction Tools

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (6, 2, 'Circular Saw', 0, 'Excellent condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (6, 8, 'Sledgehammer', 0, 'Like new');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (7, 10, 'Drill', 0, 'Good condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (7, 18, 'Sawzall', 0, 'Fair condition');

-- Cleaning Tools

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (8, 7, 'Vacuum Cleaner', 0, 'Like new');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (8, 15, 'Broom', 0, 'Good condition');

-- Electrical Tools

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (9, 1, 'Wire stripper', 0, 'Good condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (9, 2, 'Voltage tester', 0, 'Good condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (9, 3, 'Wire cutter', 0, 'Bad condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (9, 3, 'Multimeter', 0, 'Good condition');

-- Painting Tools

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (10, 4, 'Paint brush set', 0, 'New');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (10, 5, 'Roller set', 0, 'Good condition');

INSERT INTO CommunityTools (catID, memberID, toolName, borrowStatus, condition)
VALUES (10, 6, 'Paint sprayer', 0, 'Good condition');
-----------------------------------------------------------------------------
-- Insert records -----------------------------------------------------------

INSERT INTO BorrowRecords (memberID, toolID, rentDate, returnDate)
VALUES (16, 12, TO_DATE('2022-02-03', 'YYYY-MM-DD'), TO_DATE('2022-02-13', 'YYYY-MM-DD'));

INSERT INTO BorrowRecords (memberID, toolID, rentDate, returnDate)
VALUES (7, 18, TO_DATE('2022-03-17', 'YYYY-MM-DD'), TO_DATE('2022-03-24', 'YYYY-MM-DD'));

INSERT INTO BorrowRecords (memberID, toolID, rentDate, returnDate)
VALUES (13, 5, TO_DATE('2022-04-06', 'YYYY-MM-DD'), TO_DATE('2022-04-16', 'YYYY-MM-DD'));

INSERT INTO BorrowRecords (memberID, toolID, rentDate, returnDate)
VALUES (3, 19, TO_DATE('2022-05-12', 'YYYY-MM-DD'), TO_DATE('2022-05-22', 'YYYY-MM-DD'));

INSERT INTO BorrowRecords (memberID, toolID, rentDate, returnDate)
VALUES (9, 1, TO_DATE('2022-06-01', 'YYYY-MM-DD'), TO_DATE('2022-06-08', 'YYYY-MM-DD'));

INSERT INTO BorrowRecords (memberID, toolID, rentDate, returnDate)
VALUES (15, 16, TO_DATE('2022-07-05', 'YYYY-MM-DD'), TO_DATE('2022-07-12', 'YYYY-MM-DD'));

INSERT INTO BorrowRecords (memberID, toolID, rentDate, returnDate)
VALUES (1, 3, TO_DATE('2022-08-11', 'YYYY-MM-DD'), TO_DATE('2022-08-21', 'YYYY-MM-DD'));

INSERT INTO BorrowRecords (memberID, toolID, rentDate, returnDate)
VALUES (18, 14, TO_DATE('2022-09-02', 'YYYY-MM-DD'), TO_DATE('2022-09-12', 'YYYY-MM-DD'));

INSERT INTO BorrowRecords (memberID, toolID, rentDate, returnDate)
VALUES (11, 21, TO_DATE('2022-10-16', 'YYYY-MM-DD'), TO_DATE('2022-10-26', 'YYYY-MM-DD'));

INSERT INTO BorrowRecords (memberID, toolID, rentDate, returnDate)
VALUES (2, 17, TO_DATE('2022-11-05', 'YYYY-MM-DD'), TO_DATE('2022-11-12', 'YYYY-MM-DD'));

INSERT INTO BorrowRecords (memberID, toolID, rentDate, returnDate)
VALUES (6, 10, TO_DATE('2022-12-01', 'YYYY-MM-DD'), TO_DATE('2022-12-11', 'YYYY-MM-DD'));

INSERT INTO BorrowRecords (memberID, toolID, rentDate, returnDate)
VALUES (20, 8, TO_DATE('2023-01-09', 'YYYY-MM-DD'), TO_DATE('2023-01-19', 'YYYY-MM-DD'));

INSERT INTO BorrowRecords (memberID, toolID, rentDate, returnDate)
VALUES (4, 2, TO_DATE('2023-02-02', 'YYYY-MM-DD'), TO_DATE('2023-02-09', 'YYYY-MM-DD'));
-----------------------------------------------------------------------------

commit;
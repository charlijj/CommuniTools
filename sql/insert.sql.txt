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
INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password) 
VALUES (1, 'User', 'Test', '788 Street St, Nanaimo BC', 'mail@mail.com', '250-111-2222', 'user', 'pass');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password) 
VALUES (1, 'Jasper', 'Char', '788 Street St, Nanaimo BC', 'mail@mail.com', '250-111-2222', 'CharJ', 'repsaj');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password)
VALUES (1, 'Anakin', 'Skywalker', '1234 Tatooine Ave, Mos Espa', 'anakin@jediorder.com', '555-1234', 'SkywalkerA', 'TheChosenOne');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password)
VALUES (2, 'Luke', 'Skywalker', '1234 Rebel Way, Hoth', 'luke@rebels.com', '555-5678', 'SkywalkerL', 'TheLastJedi');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password)
VALUES (3, 'Leia', 'Organa', '1234 Alderaan St, Aldera', 'leia@rebels.com', '555-4321', 'OrganaL', 'PrincessLeia');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password)
VALUES (4, 'Han', 'Solo', '1234 Smuggler St, Corellia', 'han@falcon.com', '555-8765', 'SoloH', 'Ishotfirst');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password)
VALUES (5, 'Chewbacca', '', '1234 Kashyyyk Way, Kashyyyk', 'chewie@falcon.com', '555-2345', 'Chewie', 'Grrrrooooowwwwllll');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password)
VALUES (6, 'Obi-Wan', 'Kenobi', '1234 Jedi Temple, Coruscant', 'obi-wan@jediorder.com', '555-7890', 'KenobiO', 'HelloThere');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password)
VALUES (6, 'Jean-Luc', 'Picard', '1701 Enterprise Way, La Barre, France', 'captain@enterprise.com', '555-1234', 'CaptainPicard', 'Engage123');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password)
VALUES (7, 'William', 'Riker', '1701 Enterprise Way, Valdez, Alaska', 'will.riker@enterprise.com', '555-5678', 'CmdrRiker', 'NumberOne');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password)
VALUES (8, 'Data', '', '1701 Enterprise Way, Omicron Theta', 'data@enterprise.com', '555-9012', 'LtCmdrData', '1234567');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password)
VALUES (9, 'Deanna', 'Troi', '1701 Enterprise Way, Betazed', 'dtroi@enterprise.com', '555-3456', 'CounselorTroi', 'Betazoid1');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password)
VALUES (10, 'Worf', '', '1701 Enterprise Way, QonoS', 'worf@enterprise.com', '555-7890', 'LtWorf', 'Honor12');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password)
VALUES (6, 'Kathryn', 'Janeway', 'USS Voyager, Delta Quadrant', 'captain@voyager.com', '555-1234', 'CaptainJaneway', 'Coffee234');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password)
VALUES (7, 'Chakotay', '', 'USS Voyager, Dorvan V', 'chakotay@voyager.com', '555-5678', 'CmdrChakotay', 'Maquis123');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password)
VALUES (8, 'Tuvok', '', 'USS Voyager, Vulcan', 'tuvok@voyager.com', '555-9012', 'LtCmdrTuvok', 'Vulcan123');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password)
VALUES (9, 'B`Elanna', 'Torres', 'USS Voyager, Kessik IV', 'btorres@voyager.com', '555-3456', 'LtTorres', 'HalfKlingon1');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password)
VALUES (10, 'Seven', 'of Nine', 'USS Voyager, Borg Cube', 'seven@voyager.com', '555-7890', 'SevenOfNine', 'ResistanceIsFutile');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password) 
VALUES (1, 'Neo', 'Anderson', '101 Trinity Lane, The Matrix', 'neo@thematrix.com', '555-1234', 'TheOne', 'Matrix123');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password) 
VALUES (2, 'Trinity', 'Moss', '102 Trinity Lane, The Matrix', 'trinity@thematrix.com', '555-5678', 'NeoLover', 'ILoveNeo');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password) 
VALUES (3, 'Morpheus', 'Fishburne', '103 Zion Ave, Zion City', 'morpheus@zioncity.com', '555-9012', 'RedPill', 'WakeUpNeo');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password) 
VALUES (4, 'Agent', 'Smith', '104 Matrix Lane, The Matrix', 'smith@thematrix.com', '555-3456', 'TheEnemy', 'IHateNeo');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password) 
VALUES (4, 'Agent', 'Mike', '104 Matrix Lane, The Matrix', 'smith@thematrix.com', '555-3456', 'TheEnemy2', 'IHateNeo2');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password) 
VALUES (4, 'Agent', 'Bob', '104 Matrix Lane, The Matrix', 'smith@thematrix.com', '555-3456', 'TheEnemy3', 'IHateNeo3');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password) 
VALUES (4, 'Agent', 'Lary', '104 Matrix Lane, The Matrix', 'smith@thematrix.com', '555-3456', 'TheEnemy4', 'IHateNeo4');

INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password) 
VALUES (4, 'Agent', 'David', '104 Matrix Lane, The Matrix', 'smith@thematrix.com', '555-3456', 'TheEnemy5', 'IHateNeo5');
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

commit;
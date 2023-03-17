<h1>CommuniTools</h1>

<p>This repository is for a community tool sharing database application.</p>

<h2>Introduction:</h2>
<p>This proposal outlines a database application for community tool sharing. The purpose of this application is to allow members of a community to share tools with one another, without the need for payment. The application aims to facilitate the borrowing and lending of tools, making it easier for community members to complete DIY projects, repairs, and maintenance.</p>

<h2>Application Domain:</h2>

<p>The database application for community tool sharing aims to facilitate tool borrowing and lending among community members. The primary goal of the application is to promote communication and collaboration within communities while fostering a friendly and cooperative atmosphere. The application will feature a command line interface to provide a simple and efficient user experience.</p>

<h2>Audience:</h2>

<p>The audience for this application will be members of specific small communities, who are interested in sharing tools with one another. The application will be designed to appeal to individuals who are community-minded, open to meeting new people, and interested in DIY projects, repairs, and maintenance. The target audience will be individuals who are comfortable using technology and who are familiar with using common tools.</p>

<h2>Requirements:</h2>

<p>The following requirements have been identified from the hypothetical customer:</p>

<ul><li>Registration: Users must be able to register and create a profile on the application.</li>
<li>Tool Listing: Users must be able to list the tools they own and are willing to lend to others.</li>
<li>Tool Search: Users must be able to search for tools that they require and view the tools that are available for lending.</li>
<li>Tool Categories: Each tool must be associated with a category.</li>
<li>Communities: Each member must live in one of the predetermined categories.</li>
<li>Tool Borrowing: Users must be able to borrow tools for a specific amount of time.</li>
<li>Borrower Verification: Borrowers must be verified before they can borrow a tool.</li>
<li>Tool Return: Users must be able to record when a tool has been returned to the lender.</li>
</ul>

<h2>ER Diagram:</h2>

<img src="https://github.com/charlijj/CommuniTools/blob/main/communiTools_ER.jpg">

<h2>Schema:</h2>

<ul>
<li>Communities (comID, comName, comLocation, comSize)</li>
<li>Members (memberID, comID, memberName, address, email, phone)</li>
<li>Borrowers (memberID, numToolsBorrowing)</li>
<li>Tools (toolID, catID, memberID, toolName, borrowStatus, condition)</li>
<li>Categories (catID, catName, catDescription)</li>
<li>BorrowRecord (recordID, memberID, toolID, rentDate, returnDate)</li>
</ul>

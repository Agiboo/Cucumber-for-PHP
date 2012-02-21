Feature: Log in to the system
	As an authenticated user
	I want to log in to the system
	So that I can see or manage my profile
	
	Scenario: Log in as an authenticated user
		When I log in as an authenticated user
		Then I'm redirected to my profile
		And the message appears that the login was successful
		
	Scenario: Log in as an administrator
		When I log in as an administrator
		Then I'm redirected to the dashboard page
		And the message appears that the login was successful
		
	Scenario: Log in with wrong credentials
		When I log in as a user that doesn't exist in the system
		Then I stay on the same page
		And the message appears that the login was unsuccessful
#comments here
@users @drupal
Feature: Manage users in Drupal
	As a website administrator
	I want to manage users and their permissions
	So that I can control who can manage what on the site

	Background:
		Given I'm logged in as an administrator
		
	Scenario: Create a user
		When I fill and submit the user creation form properly
		Then that user account is created
		And the user can log in
		
	Scenario: Delete a user from the user list page
		When I select a user for deletion
		Then that user account is deleted
		And the user can no longer log in
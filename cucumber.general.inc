<?php
/**
 * CukeFlow is a PHP approach to Cucumber.  It's ought to be used in Drupal so sorry for the non-compliance to other development standards!
 * Also, this is a prototype...
 */

//$result = When('/^I visit the (.*) page$/');

function Given($regex)
{
	execute_test($regex, 'Given');
}

function When($regex)
{
	execute_test($regex, 'When');
}

function Then($regex)
{
	execute_test($regex, 'Then');
}

/**
 * This is the function that replaces the given/when/then/and functions defined in your Gherkin tests
 */
function execute_test($regex = NULL, $prefix = NULL)
{
	echo "<code><strong>$prefix</strong> $regex</code><br />";
}
?>
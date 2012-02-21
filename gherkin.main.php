<?php

require_once("helper.files.inc");
require_once("helper.main.inc");
require_once("class.feature.inc");

gherkin_initiate(); // SHOULD NOT BE CALLED HERE :-)

/**
 * This is the code where all the gherkin tests are loaded
 */
function gherkin_initiate($execute = 'all', $include = NULL, $exclude = NULL) {
	$pwd = getcwd();
	$directory_array = read_directory($pwd);

	$files = array();
	foreach ($directory_array as $key => $file) {
		$files[] = read_file("$pwd/features/$file");
	}

	// Validate each file
	foreach ($files as $key => $feature) {
		$validated = gherkin_validate($feature);
		nifty_print($feature,'Feature');
		echo ($validated ? "The gherkin is valid" : "The gherkin is not valid");
		if($validated) {
			$feature = new Feature($feature);
			echo $feature->toString();
		}
	}
}

/**
 * Analyzes output and validates a file at once
 */
function gherkin_validate($lines) {
	foreach( $lines as $linekey => $line ) {
		$hit = false;
		foreach( valid_prefixes() as $prefix ) {
			if( string_starts_with( $line,$prefix )) {
				echo "$line starts with $prefix<br />";
				$hit = true;
			}
		}
		if( !$hit )
			return false;
	}
	return true;	
}

/**
 * Returns valid prefixes for english scenario's
 *
 * @return array()
 * @author Tom Verhaeghe
 **/
function valid_prefixes() {
	return array(
		'Feature', 		// Feature definition
		'As a',			// Description
		'I want',	// Description
		'So that',		// Description
		'Scenario',		// Scenario name
		'Background:',	// Scenario background steps
		'Given',		// Given step
		'When',			// When step
		'Then',			// Then step
		'And',			// And step (can be any step of the three above)
		'@',			// Tags
		'#',			// Ignore any comments
	);
}






?>
<?php

require_once("helper.files.inc");
require_once("helper.main.inc");
require_once("class.feature.inc");
require_once("cucumber.general.inc");

$features = gherkin_initiate(); // SHOULD NOT BE CALLED HERE :-)
foreach ($features as $feature) {
	gherkin_run_tests($feature);
}

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
	$return = array();

	// Validate each file
	foreach ($files as $key => $feature) {
		$validated = gherkin_validate($feature);
		if($validated) {
			
			$feature = new Feature($feature);
			$return[] = $feature;
			//echo $feature->toString();
		}
	}
	return $return;
}

/**
 * This is the code that triggers a test
 */
function gherkin_run_tests($feature) {
	$scenarios = $feature->getScenarios();
	//echo $featureObj->toString();
	foreach($scenarios as $index => $scenario){
		echo "<h3>".$scenario['name']."</h3>";
		foreach($scenario['steps'] as $step_key => $step_value){
			$prefix = array_shift(explode(' ', $step_value));
			$rest_of_sentence = explode(' ',$step_value);
			unset($rest_of_sentence[0]);
			$rest_of_sentence = implode(' ', $rest_of_sentence);
			call_user_func($prefix,$rest_of_sentence);
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
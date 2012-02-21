<?php
/**
 * Feature class
 *
 * @author Tom Verhaeghe
 **/
class Feature
{
	private $feature_name;						// Feature name (string, first line of file)
	private $feature_description = array();		// Array with the feature description
	private $feature_tags = array();			// Tags for the feature
	private $scenario_background = array();		// Array with the background actions
	private $scenarios = array();				// Array with all of the different scenario's
	private $valid_gherkin;						// Boolean flag
	private $lines;								// Raw input (for debugging)
	
	/**
	 * Constructor
	 */
	function __construct($lines) {
		$this->lines = $lines;
		$this->feature_initiate($lines);
	}
	
	/**
	 * Debug function that prints out the feature object's variables.
	 * 
	 * @return void
	 */
	public function toString(){
		nifty_print($this->feature_name,'Feature name');
		nifty_print($this->feature_tags,'Feature tags');
		nifty_print($this->feature_description,'Feature description');
		nifty_print($this->scenario_background,'Scenario background');
		nifty_print($this->scenarios,'Scenarios');
		nifty_print($this->lines);
		return $output;
	}
	
	/**
	 * Analyses the array of feature file.
	 *
	 * @return void
	 **/
	private function feature_initiate($lines){
		$at_background = FALSE;
		$at_scenario = FALSE;
		
		foreach($lines as $index => $line){
			switch ($line) {
				case string_starts_with($line,'#'):
					// Ignore here, because it's a comment
					break;
				case string_starts_with($line,'@'):
					$this->feature_tags = explode(' ',$line);
					break;
				case string_starts_with($line,'Feature:'):
					$this->feature_name = $line;
					break;
				case string_starts_with($line,'As a'):
				case string_starts_with($line,'I want'):
				case string_starts_with($line,'So that'):
					$this->feature_description[] = $line;
					break;
				case string_starts_with($line,'Background'):
					$at_background = TRUE;
					break;
				case string_starts_with($line,'Scenario'):
					$at_background = FALSE;
					$at_scenario = TRUE;
					$this->scenarios[] = $line;
					break;
				case ($at_background === TRUE && $at_scenario === FALSE):
					$this->scenario_background[] = $line;
					break;
				default:
					$this->scenarios[] = $line;
					break;
			}
		}
	}
}
?>
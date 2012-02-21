<?php
/**
 * Reads a specific directory and returns
 * 
 * @param string $source
 * @return array() array of files in the directory (flat for now)
 */
function read_directory($source)
{
	$features_folder = '/features';
	$result = array();
	if ($handler = opendir($source.'/features')) {
	    while (false !== ($entry = readdir($handler))) {
	        if (string_ends_with($entry,'.feature')) {
	            $result[] = "$entry";
	        }
	    }
	    closedir($handler);
	}
	return $result;
}

/**
 * Reads a specific file and returns an array.
 */
function read_file($source)
{
	$result = array();
	$handler = fopen($source, "r");
	while (!feof($handler)) {
		$line = trim(fgets($handler));
		if($line != '')
		{
			$result[] = $line;
		}
	}
	fclose($handler);
	return $result;	
}
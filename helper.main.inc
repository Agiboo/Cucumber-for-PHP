<?php
/**
 * Tests whether the $string ends with the $test attribute
 * 
 * @param string $string
 * @param string $test
 * @return boolean
 */
function string_ends_with($string,$test)
{
	$strlen = strlen($string);
    $testlen = strlen($test);
    if ($strlen <= $testlen) {
		return false;
	} else 	{
		return substr_compare($string, $test, -$testlen) === 0;
	}
}

/**
 * Tests whether the $string starts with the $test attribute
 * 
 * @param string $string
 * @param string $test
 * @return boolean
 */
function string_starts_with($string, $test)
{
    $length = strlen($test);
    return (substr($string, 0, $length) === $test);
}

function nifty_print($array,$name = "array")
{
	print("<h3>$name</h3><code><pre>".print_r($array, TRUE) . "</pre></code>");
}
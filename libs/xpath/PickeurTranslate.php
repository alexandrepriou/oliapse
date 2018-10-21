<?php
/**
 * Permet de recuperer par mot clef la traduction des champs 
 * @author alexandre priou
 *
 */
class PickeurTranslate {
	private static $xpath;
	private static $dom;
	private function __construct()
	{
		self::$xpath = new DOMXPath(self::$dom);
	}
	public static function getInstance()
	{
		if(self::$instance==NULL || !is_object(self::$instance))
		{
			$c=__CLASS__;
			self::$instance=new $c();
			
		}
		return self::$instance;
	}
	public function getById($NameId)
	{
		$expression= "//root/motclef[@id=".$NameId."]/translate";
	}
	private static $instance;
}
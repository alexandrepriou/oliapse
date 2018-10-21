<?php
/**
 * Permet de manipuler les fichier de configuration des sites 
 * @author alexandre priou
 *
 */
class iniManipulator {
	private $fileIni;
	private $filename;
	private $data;
	public function __construct($filename) {
		$this->filename=$filename;
		$this->data = array();
	}
	public function loadIni()
	{
		$data = parse_ini_file($this->filename,true);
		$this->data= new ArrayObject($data);
		unset($data);
	}
	public function writeFile($data)
	{
		if(file_exists($this->filename))
		{
			unlink($this->filename);
		}
		$file= new File($this->filename,true);
		//$file->openW();
		$file->write($data);
	}
	public function makeFileData($sectionName,array $data)
	{
		$buff="";
		$buff.="[".$sectionName."]\n";
		foreach ($data as $key=>$item)
		{
			$buff.=$key."=".$item."\n";
		}
		return $buff;
	}
	public function modifEntry($sectionName,$key,$value)
	{
		if($this->data->offsetExists($sectionName))
		{
			$newArray = $this->data->offsetGet($sectionName);
			$newArray[$key]=$value;
			$this->data->offsetSet($sectionName,$newArray);
		}
	}
	public function addEntry($sectionName,$key,$value)
	{
		$newArray = $this->data->offsetGet($sectionName);
		$newArray[$key]=$value;
		$this->data->offsetSet($sectionName,$newArray);
	}
}
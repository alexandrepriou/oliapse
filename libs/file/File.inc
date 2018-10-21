<?php
/**
 * Gestion de manipulation de fichier 
 * @author Priou Alexandre
 * @version 0.1
 */
class File {
	public function __construct($name, $write = false) {
		self::setName ( $name );
		if ($write)
			self::openW ();
		else
			self::openR ();
	}
	public function __destruct() {
		unset ( $this->name );
		if ($this->fp)
			fclose ( $this->fp );
	}
	public function getNameFile() {
		return $this->name;
	}
	public function setName($name) {
		$this->name = $name;
	}
	private function openR() {
		$this->mode = false;
		$this->fp = fopen ( $this->name, "r" );
		if (! is_resource($this->fp)) {
			echo "error resource";
			return false;
		} else {
			return true;
		}
	}
	private function openW() {
		$this->mode = true;
		/* if(!file_exists($this->name)) {
			$this->fp = fopen ( $this->name, "a+" );
			fclose($this->fp);
			chmod($this->name,777);
		} */
		$this->fp = fopen ( $this->name, "a+" );
		if (!is_resource($this->fp)) {
			echo "error resource";
			return false;
		} else {
			return true;
		}
	}
	public function read() {
		$tmp = fread ( $this->fp, filesize ( $this->name ) );
		return $tmp;
	}
	public function write($chaine) {
		if ($this->mode)
			fwrite ( $this->fp, $chaine );
		else
			return $this->mode;
	}
	private $mode;
	private $name;
	private $fp;
}
?>

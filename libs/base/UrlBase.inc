<?php
/**
 * Objet générique du stockage des identifiants URLS
 * La base /.../
 *
 * utilisation : 
 * 		$url=new UrlBase();
 * 		$url->offsetSet(RACINE,"/");
 * 		$url->offsetSet(NIV1,'emission');
 * 		$url->offsetSet(NIV2,'toutes-emissions');
 * 
 * 		//ou : 
 * 		$url=new UrlBase();
 * 		$url->setArray($array);
 */
class UrlBase implements ArrayAccess {
	private $url;
	public function __construct() {
		$this->url = array ();
	}
	public function setArray(array $data) {
		$this->url = $data;
	}
	public function offsetExists($key) {
		return isset ( $this->url [$key] );
	}
	public function offsetGet($key) {
		if($this->offsetExists($key))
			return $this->url [$key];
		else
			return false;
	}
	public function offsetSet($key, $value) {
		$this->url [$key] = $value;
	}
	public function offsetUnset($key) {
		unset ( $this->url [$key] );
	}
	public function getSize() {
		return (sizeof ( $this->url ) - 2);
	}
}

?>
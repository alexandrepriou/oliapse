<?php
/**
 * Permet l'uniformisation des data dans le templateManager
 * @author : Alexandre Priou 
 * @version : beta 0.1 
 * @date : 11 déc. 08
 * @note dev : 
 * 		
 * @exemple 
 * 
 * 
 */
class DataMappeur extends ArrayObject {
	public function __construct() {
	}
	public function __desctruct() {
	}
	public function getElement($index, $name) {
		if (parent::offsetExists ( $index )) {
			$data = parent::offsetGet ( $index );
			if (isset ( $data [$name] )) {
				return $data [$name];
			}
		} else {
			return "";
		}
	}
	/**
	 * protection *
	 */
	private function __clone() {
	}
	public function __call($methode, $args) {
		print_r ( "<br />erreur dans L'appel a la classe : " . __CLASS__ );
		print_r ( "<br />Methode appeler : " . $methode );
		print_r ( "<br />Fichier : " . __FILE__ );
	}
}

?>
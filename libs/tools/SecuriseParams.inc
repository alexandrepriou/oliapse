<?php
/**
 * Permet de récupérer les paramettres en toute sécurité
 * @author alexandre priou
 *
 */
final class SecuriseParams {
	private function __construct() {
	}
	private function __destruct() {
	}
	/**
	 * Permet de récuperer les parametres n'ayant pas de contenu riche html
	 * 
	 * @param string $name
	 *        	nom du parametre
	 * @return false string
	 */
	public static function paramSimple($name) {
		if (isset ( $_REQUEST [$name] )) {
			return htmlentities ( addslashes ( strip_tags ( $_REQUEST [$name] ) ) );
		} else {
			return false;
		}
	}
	/**
	 * Permet de récupérer les parametres ayant un contenu riche html
	 * 
	 * @param string $name
	 *        	nom du parametre
	 * @return false string
	 */
	public static function paramRiche($name) {
		if (isset ( $_REQUEST [$name] )) {
			return htmlentities ( addslashes ( $_REQUEST [$name] ) );
		} else {
			return false;
		}
	}
	public static function epureData($name)
	{
		return htmlentities ( addslashes ( strip_tags ( $name )  ) );
	}
}
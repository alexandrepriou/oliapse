<?php
/**
 * Gestionnaire de logs
 *
 * @author Priou Alexandre
 * @version 0.1
 *
 *
 */
include_once (PATH_INSTALL.'classes/file/File.inc');
class Logs {
	public function __construct() {
	}
	/**
	 * permet l'écriture de log d'erreur normée
	 *
	 * @param string $class_name Le nom de la classe
	 * @param string $message le message d'erreur
	 *
	 */
	public static function Error($class_name, $message) {
        self::createDirIfNotExist();
		$namefile =PATH_LOG.'errors.log';
		$message = "[" . date ( "d-m-Y H:i:s" ) . "] [" . $class_name . "]" . $message;
		$file = new File ( $namefile, true );
		$file->Write ( $message . "\n" );
	}
	/**
	 * permet l'écriture de log warning  normée
	 *
	 * @param string $class_name Le nom de la classe
	 * @param string $message le message d'erreur
	 *
	 */
	public static function Warning($class_name, $message) {
        self::createDirIfNotExist();
		$namefile =PATH_LOG.'warning.log';
		$message = "[" . date ( "d-m-Y H:i:s" ) . "] [" . $class_name . "]" . $message;
		$file = new File ( $namefile, true );
		$file->Write ( $message . "\n" );
	}
	/**
	 * permet l'écriture de log debug normée
	 *
	 * @param string $class_name Le nom de la classe
	 * @param string $message le message d'erreur
	 *
	 */
	public static function Debug($class_name, $message) {
        self::createDirIfNotExist();
		$namefile =PATH_LOG.'debug.log';
		$message = "[" . date ( "d-m-Y H:i:s" ) . "] [" . $class_name . "]" . $message;
		$file = new File ( $namefile, true );
		$file->Write ( $message . "\n" );
	}

    private static function createDirIfNotExist() {
        if(!file_exists(PATH_LOG))
        {
            mkdir(PATH_LOG,0777,true);
        }
    }
}
?>

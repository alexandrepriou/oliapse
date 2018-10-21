<?php
/**
 * Classe contenant des outils 
 * @author alexandre priou
 *
 */
final class Tools {
	private function __construct(){}
	private function __destruct(){}
	
	/**
	 * Permet d'encrypter un Identifiant  suivant un dicotionnaire
	 * @param int|string $id l'identifiant numerique
	 * @return string  l'identifiant encrypté
	 */
	public static  function encryptId($id)
	{
		$id+=6943;
		$id=(string) $id;
		$chaine="";
		$code=array(0=>'1',1=>'f',2=>'8',3=>'z',4=>'6',5=>'m',6=>'e',7=>'0',8=>'n',9=>'s');
		$len=strlen($id);
		for($i=0;$i<$len;$i++)
		{
			$chaine.=$code[$id[$i]];
		}
		return base64_encode($chaine);
	
	}
	/**
	* Permet de désencrypter les Identifiants des membres suivant le dico définit
	 * @param string $chaine l'identifiant encrypté suivant le dico définit
	 * @return string l'identifiant désencrypté
	 */
	 public static function decryptId($chaine)
	 {
		 $decode=array('1'=>'0',"f"=>'1','8'=>'2','z'=>'3','6'=>'4','m'=>'5','e'=>'6','0'=>'7','n'=>'8','s'=>'9');
		 $dchaine="";
		 $chaine = base64_decode($chaine);
		 $len=strlen($chaine);
		 for($i=0;$i<$len;$i++)
		 {
		 	$dchaine.=$decode[$chaine[$i]];
		 }
		 $dchaine=(int) $dchaine - 6943;
		 return $dchaine;
	 }
	
	 /**
	 * Permet de vérifier si la chaine est du MD5 
	 * 
	 * @param string $chaine la chaine encrypté
	 * @return boolean true ou false suivant si c'est du MD5 ou pas
	 */
	 public static function checkIsMD5($chaine)
	 {
	 if(!empty($chaine) && preg_match('/^[a-f0-9]{32}$/', $chaine))
		{
			return true;
	 }
	 else
	 {
	 	return false;
	 }
	 }
	 /**
	 * Permet d'encrypter les parametres pour un URL
	 * @param string $chaine
	 */
	 public static function encryptUrl($chaine)
	 {
	 	return base64_encode($chaine);
	 }
	 /**
	 * Permet de décoder les parametres d'URL
	 * @return array
	 */
	 public static function decryptUrl($url="")
	 {
	 	if(empty($url))
	 	{
	 		$url=$_SERVER['REQUEST_URI'];
	 	}
	
	 	$url=explode('/',$url);
	 	$len=sizeof($url)-1;
	
	 	$url=base64_decode($url[$len]);
	
	 	$tab= explode("/",$url);
	
	 	$len=sizeof($tab);
	 	for($i=0;$i<$len;$i++)
	 	{
	 		$index=$i+1;
	 		$result[$tab[$i]]=$tab[$index];
	 		$i++;
	 	}
	
	 	return $result;
	 }
	 /**
	  * Permet de savoir si une chaine de caractère est encodé en base 64
	  * @param string $chaine la chaine de caractère a vérifier 
	  * @return boolean true/false
	  */
	 public static function isbase64($chaine)
	 {
	 	return (strlen($chaine) != 0 && strlen($chaine) % 4 == 0) && preg_match("/^[a-zA-Z0-9\/\r\n+]*={0,2}$/", $chaine);
	}
	/**
	 * Autre fonction pour couper un text ( a tester ... )
	 *
	 * @param string $chaine la chaine de carractere a couper 
	 * @param int $longueur sa longueur (default : 120 )
	 * @return string la chaine tronqué
	 */
	public static function tronque($chaine, $longueur = 120)
	{
		if (empty ($chaine))
		{
			return "";
		}
		elseif (strlen ($chaine) < $longueur)
		{
			return $chaine;
		}
		elseif (preg_match ("/(.{1,$longueur})\s./ms", $chaine, $match))
		{
			return $match [1] . "...";
		}
		else
		{
			return substr ($chaine, 0, $longueur) . "...";
		}
	}
		
		
	/**
	 * Permet la convertion des caractères spéciaux pour les urls
	 *
	 * @param string $chaine la chaine de caractère a convertir
	 * @return string la chaine de caractère pour l'url 
	 */
	public static function convertToUrl($chaine)
	{
		$search=array("é","è","ê","ë","à","@","&","%"," ","ù","l'","`",":","!","#","(",")","[","]","|","=",".","/",",","d'","ï","c'","ç","?","«","»","â","î","ô","n'","'");
		$replace=array("e","e","e","e","a","","_","","_","u","l_","","","",    "", "", "" ,"" ,"" ,"" ,"" ,"" ,"_","_","d_","i","c_","c","" ,"" ,"","a","i","o","n_","_");
		$chaine=str_ireplace($search,$replace,strtolower($chaine));
		$search=array("__","___","____","_____","__","_-_","'-",'$_',"Ça");
		$replace=array("_","_","_","_","_","_","_","s_","ca");
		$chaine= str_replace($search,$replace,$chaine);
		$len=strlen($chaine);
		if(substr($chaine,$len-1,$len)=="_")
		{
			return substr($chaine,0,$len-1);
		}else return $chaine;
	}
	/**
	 * Permet la convertion des caractères spéciaux pour les noms de fichiers
	 *
	 * @param string $chaine la chaine de caractère a convertir
	 * @return string la chaine de caractère pour le nom de fichier
	 */
	public static function convertChaineForNameFiles($chaine)
	{
		$search= array("é","è","ê","ë","à","@","&","%"," ","ù","l'","`",":","!","#","(",")","[","]","|","=",".","/",",","d'","ï","c'","ç","?","«","»","â","î","ô","n'","'");
		$replace=array("e","e","e","e","a","","_","","_","u","l_","","","","", "", "" ,"" ,"" ,"" ,"" ,"" ,"_","_","d_","i","c_","c","" ,"" ,"","a","i","o","n_","_");
		$chaine=str_replace($search,$replace,strtolower($chaine));
		$search=array("__","___","____","_____","__","_-_","'-",'$_',"Ça");
		$replace=array("_","_","_","_","_","_","_","s_","ca");
		$chaine= str_replace($search,$replace,$chaine);
		$len=strlen($chaine);
		if(substr($chaine,$len-1,$len)=="_")
		{
			return substr($chaine,0,$len-1);
		}else return $chaine;
	}
	/**
	 * permet de couper un text sans couper les mots apres n mots
	 *
	 * @param string $text le text a couper
	 * @param int $offset nombre de mot (par default : 300)
	 * @return String
	 */
	public static function cutAfterNWord($text, $offset = 300)
	{
		preg_match('!.{0,'.$offset.'}\s!si', $text, $match);
		return $match[0];
	}
	/**
	 * Verifie si l'extension est présente dans le nom du fichier $fileName
	 * @param string $fileName non du fichier  
	 * @param string $extension l'extension rechercher 
	 * @return boolean
	 */
	public static function checkExtension($fileName,$extension)
	{
		$ext=self::getExtension($fileName);
		if($ext==$extension)
		{
			return true;
		}else
		{
			return false;
		}
	}
	/**
	 * Permet de récuperer l'extension d'un fichier 
	 * @param string $filename le nom du fichier 
	 * @return string l'extension du fichier
	 */
	public static function getExtension($filename)
	{
		return substr($filename,strrpos($fileName, '.')+1,strlen($fileName));
	} 
}
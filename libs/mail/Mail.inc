<?php 
define("HTML",0);
define("MILTI",1);
define("TXT",3);

class Mail
{
	public function __construct($to,$subject,$from=null,$type=null)
	{
		if(!empty($to))$this->to=$to;
		if($type != null )$this->type=$type;
		if(!empty($subject))$this->subject=$subject;
		if($from != null) $this->from=$from;
		else self::setFrom();
		self::setHeader();
	}
	public function __destruct()
	{
		unset($this->header);	
		unset($this->to);
		unset($this->subject);
		unset($this->content);
		unset($this->conf);
		unset($this->type);
	}
	public function send()
	{
		$result=mail($this->to,$this->subject,$this->content,$this->header);
		if(!$result)
		{
			die("veuillez configurer votre serveur de mail");
		}else 
		{
			return true;
		}
	}
	public function setHeader()
	{
			if($this->type!=null)
			{
				switch($this->type)
				{
					case HTML:
						self::setHeadHTML();
					break;
					case MULTI:
						self::setHeadHTML();
					break;
					case TXT:
						self::setHeadTXT();
					break;
					default:
					die("Vous devez utiliser les constantes suivantes : HTML,MULTI ou TXT");
				}
			}else
			{
				$this->type=MULTI;
				sefl::setHeadMulti();
			}
	}
	private function setHeadHTML()
	{
		$this->header = "From: ".$this->from."\n";
 		$this->header .= "Reply-To: ".$this->conf["reply_to"]."\n";
 		$this->header .= "Content-Type: text/html; charset=\"UTF-8\"";
		
	}
	private function setHeadMULTI()
	{
		 
		 $this->boundary = '-----=' . md5( uniqid ( rand() ) );		
		 $this->header  = "From: ".$this->from."\n";
		 $this->header .= "Reply-To: ".$this->conf["reply_to"]."\n";
  		 $this->header .= "MIME-Version: 1.0\n";
  		 $this->header .= "Content-Type: multipart/mixed; boundary=\"$this->boundary\"";
	}
	private function setHeadTXT()
	{
		$this->header = "From: ".$this->from."\n";
 		$this->header .= "Reply-To: ".$this->conf["reply_to"]."\n";
		$this->header .= "Content-Type: text/plain; charset=\"UTF-8\"\n";
  		$this->header .= "Content-Transfer-Encoding: 8bit";
	}
	private function setFrom()
	{
		if(!empty($this->conf["service"]["emailFrom"]))
		$this->From=$this->conf["service"]["emailFrom"];
		else $this->From="noreply@mydomain.com";
	}
	public function setBody($content)
	{
		switch($this->type)
		{
			case HTML:
				$this->content=$content;
				break;
			case TXT:
				$this->content=$content;
				break;
			case MULTI:
				$this->content=$content;
				break;
		}
	}
	public function addAttachement($file)
	{
		  $path = $this->conf["upload"].'/'.$file;
  		  $fp = fopen($path, 'rb');
  		  $content = fread($fp, filesize($path));
          fclose($fp);
 		  $content_encode = chunk_split(base64_encode($content));
 		  $message  = "Ceci est un message au format MIME 1.0 multipart/mixed.\n\n";
  		  $message .= "--" . $this->boundary . "\n";
		  $message .= "Content-Type: text/plain; charset=\"UTF-8\"\n";
		  $message .= "Content-Transfer-Encoding: 8bit\n\n";
		  $message .= $this->content."\n";
		  $message .= "--" . $this->boundary . "\n";
		  $message .= "Content-Type: image/gif; name=\"fichier.gif\"\n";
		  $message .= "Content-Transfer-Encoding: base64\n";
		  // mettez inline au lieu de attachment
		  // pour que l'image s'affiche dans l'email
		  $message .= "Content-Disposition: attachment; filename=\"fichier.gif\"\n\n";
		  $message .= $content_encode . "\n";
		  $message .= "\n\n";
		  $message .= "--" . $this->boundary . "--\n";
		  $this->content=$message;
	}
	private $header;
	private $body;
	private $subject;
	private $from;
	private $conf;
	private $boundary;
}

?>
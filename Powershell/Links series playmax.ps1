
$tem = 1
$cap = 0


while($tem -ne 8)
{
$cap++
if($cap -eq 11)
{
$cap = 1
$tem++
}
$url = "http://playmax.cc/episodios/juego-de-tronos-temporada-"+$tem+"-capitulo-"+$cap+"/"

$text = (Invoke-WebRequest $url).toString()
$posta = $text.Substring($text.IndexOf("downace.com")-8,31)
$posta=$posta.Replace("embed/","")
$posta=$posta.Replace("`"","/")
$posta
$posta >> links.txt
} 
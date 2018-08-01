cls

$artista = "metallica"
$artista=$artista.Replace(" ","+")
$pagina = "https://www.google.com.ar/search?q=" + $artista + "+albums" 

(Invoke-WebRequest $pagina).allElements | Select -First 10 -ExpandProperty innerText

<#
$clave="><div id=`"_vBb`"><span class=`"_G0d`">"
$desde=$asd.IndexOf($clave)+$clave.Length
$hasta=$asd.IndexOf("</span><div class=`"_H0d`">")
$largo=$hasta-$desde
if($largo -gt 1)
{
$asd=$asd.Substring($desde)
$asd=$asd.Substring(0,$largo)
$asd=$asd.Replace("</span><span class=`"_G0d`">,<br>","
")
$asd

}
else 
{

$asd

}
#>
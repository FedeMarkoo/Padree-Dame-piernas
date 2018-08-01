foreach($line in dir | Select-Object name)
{
    [string]$nombre = $line
    [string]$nom =  $nombre
    $nom=$nom.Replace("@{Name=","").Replace("}","")
    $nombre=$nombre.Replace("."," ").Replace(" 1080p-dual-lat ",").").Replace("@{Name=","").Replace("}","").Replace("20","(20")
    $nom + "  
    a:
     " + $nombre

    Rename-Item $nom $nombre
}
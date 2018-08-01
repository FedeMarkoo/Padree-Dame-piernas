cls
$pag= Read-Host -Prompt "que saga buscas?"
$pag = "http://allcalidad.com/page/2/?s=" + $pag.Replace(" ","-")
$pag
$todo = (Invoke-WebRequest $pag | Select -ExpandProperty links | Select-Object href | Sort-Object href)
$ant = "asd"
$num = 3
foreach($line in $todo)
{
    if($num -ne 0)
    {
        $num--
    }
    else
    {
        [string]$val = $line
        if( -not $val.Contains("category") -and  -not $val.Contains("tag") -and  -not $val.Contains("page"))
            {
                $val = $val.Replace("@{href=http://","").Replace("}","")
                if($ant -ne $val)
                    {  
                        $ant = $val
                        $val
                  #      foreach($link in (Invoke-WebRequest $val | Select -ExpandProperty links | Select-Object href -ExpandProperty href| Sort-Object href))
                  #      {
                  #          [string]$cadl = $link
                  #          if($cadl.contains("mega") -or $cadl.contains("1fichier.com") -or $cadl.contains("mediafire"))
                  #          { 
                  #              $val.Replace("allcalidad.com/","").Replace("-"," ") + ":   " + $cadl
                  #              $cadl | Set-Clipboard
                  #          }
                  #      }
                    }
            }
    }
}

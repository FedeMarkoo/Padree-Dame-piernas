cls

$borrar = $true
$altoke_ameo = $true
$tabla = @()
$cant = 0
foreach($item in get-childitem -File -r -Exclude -System | Sort-Object -Property name)
{
    if($item.Length -match $ant.Length -and $item.Extension -match $ant.Extension -and $item.Length -and $item.ToString().substring(0,$item.toString().LastIndexOf("\")) )#-match $ant.ToString().substring(0,$ant.toString().LastIndexOf("\")))
    {
        $cant++
        $altoke_ameo = $false
        $ant | Select-Object -Property name, length, directory
        $item | Select-Object -Property name, length ,directory
        if($borrar) {Remove-Item -Path $ant.FullName}
    }
    $ant=$item
}
if($altoke_ameo) {"No tenéh archívó dúplíkáhdós"}
$cant
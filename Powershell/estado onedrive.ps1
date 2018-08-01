while([string[]](dir 'D:\Peliculas\' | Select-Object Name).Count)
{
    [string[]]$var = dir | Select-Object fullName , Attributes | Where-Object Attributes -EQ 'ReadOnly, Archive, SparseFile'
    if($var.Count -eq 0)
    {
        $dir = (dir 'D:\Peliculas\' | Select-Object fullname -First 1).fullName
        move $dir 'D:\OneDrive - Universidad Nacional de la Matanza\Peliculas'
    }
    else
    {
        foreach($line in $var)
        {
            $line.Substring(11,$line.IndexOf(";")-11)
        }
    }
    sleep -Milliseconds 500
    cls
}
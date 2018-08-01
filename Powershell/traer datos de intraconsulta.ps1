$user = '38858109'
$pass = 'NgC4h.35'

$pair = "$($user):$($pass)"

$encodedCreds = [System.Convert]::ToBase64String([System.Text.Encoding]::ASCII.GetBytes($pair))

$basicAuthValue = "Basic $encodedCreds"

$Headers = @{
    Authorization = $basicAuthValue
}

Invoke-WebRequest -Uri 'http://alumno2.unlam.edu.ar/index.jsp' -Headers $Headers | Select-Object -ExpandProperty Content

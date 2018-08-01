
$user = 'fede.markoo@gmail.com'
$pass = 'ASas123qwe'

$pair = "$($user):$($pass)"

$encodedCreds = [System.Convert]::ToBase64String([System.Text.Encoding]::ASCII.GetBytes($pair))

$basicAuthValue = "Basic $encodedCreds"

$Headers = @{
    Authorization = $basicAuthValue
}

Invoke-WebRequest -Uri 'https://www.facebook.com/Fede.Markoo/allactivity?privacy_source=activity_log_top_menu' -Headers $Headers
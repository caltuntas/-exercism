function calc(param) {
  num = strtonum(param)
  if (num<=0 || num>64) {
    print "square must be between 1 and 64"
    exit 1
  }
  power = num -1
  command = "echo '2^" power "' | /usr/bin/bc"
  command | getline result
  close(command)
  return result
}
{
  if ($0 == "total") {
    for (i=1; i<65; i++) {
      total += calc(i)
    }
    print total
  } else 
  print calc($0)
}

{
  rev=""
  split($0,chars,"")
  for (i=length($0);i>0; i--) {
    rev=rev chars[i]
  }
  $0 = rev
  print $0
}

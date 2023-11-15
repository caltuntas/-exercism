{
  year=strtonum($0)
  if (year % 400 == 0) {
    print "true"
    exit
  }
  else if (year % 100 == 0) {
    print "false"
    exit
  }
  else if (year % 4 == 0) {
    print "true"
    exit
  }

  print "false"
}

{
  alphabet = "abcdefghijklmnopqrstuvwxyz"

  text = tolower($0)
  if (length(text) < 26)
    print "false"
  else {
    split(alphabet,array,"")
    for (i=0; i<length(array); i++) {
      char = array[i]
      if (index(text,char) <= 0) {
        print "false"
        exit 0
        }
      }
      print "true"
    }
}

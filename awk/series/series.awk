# These variables are initialized on the command line (using '-v'):
# - len

{
  input = $0
  if (length(input) <= 0) {
    print "series cannot be empty"
    exit 1
    }
  if (len <=0 || length(input) < len) {
    print "invalid length"
    exit 1
    }
  j = 0
  split(input,chars,"")
  for (i=1; i<=length(chars); i++) {
    str = substr(input,i, len)
    if (length(str) == len) {
      result[j] = str
      j++
    }
  }

  for (i =0; i<length(result); i++) {
    val = result[i];
    final = final " " val
    }

  gsub(/^[ ]+/,"",final)
  print final
}

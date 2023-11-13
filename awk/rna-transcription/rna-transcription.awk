{
  seq=$0
  out=""
  if (length(seq)<=0)
    print ""
  split(seq,chars,"")
  for (i=1; i<= length(seq); i++) { 
    chr=chars[i]
    if (chr == "C")
      out=out"G"
    else if (chr == "G")
      out=out"C"
    else if (chr == "T")
      out=out"A"
    else if (chr == "A")
      out=out"U"
    else {
      print "Invalid nucleotide detected."
      exit 1 
    }
  }
  print out
}

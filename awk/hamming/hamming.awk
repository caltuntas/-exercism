{
  if(NR==1) dna1=$0
  if(NR==2) dna2=$0
}
END {
  split(dna1,chars1,"")
  split(dna2,chars2,"")
  if(length(chars1)!=length(chars2)){
    print "strands must be of equal length"
    exit 1
  }

  distance = 0
  for(i=0;i<length(chars1); i++) {
    if (chars1[i] != chars2[i]) distance++;
  }

  print distance
}

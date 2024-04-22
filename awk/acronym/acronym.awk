BEGIN {
  FS="[-_ ]"
}
{

  acronym = ""

  for (i=1; i<=NF; i++) {
     acronym=acronym "" toupper(substr($i,0,1))
  }
  print acronym
}

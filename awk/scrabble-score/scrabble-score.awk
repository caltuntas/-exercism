BEGIN {
  }
{
    sum=0
    text=""
    split($0,chars,"")
    for (i=0; i <= length($0); i++) {
      if (chars[i] ~ /[AaEeIiOoUuLlNnRrSsTt]/ ) {
        sum+=1
      }
      if (chars[i] ~ /[FfHhVvWwYy]/ ) {
        sum+=4
      }
      if (chars[i] ~ /[DdGg]/) {
        sum+=2
      }
      if (chars[i] ~ /[BbCcMmPp]/) {
        sum+=3
      }
      if (chars[i] ~ /[Kk]/) {
        sum+=5
      }
      if (chars[i] ~ /[JjXx]/) {
        sum+=8
      }
      if (chars[i] ~ /[QqZz]/) {
        sum+=10
      }
      text=text""toupper(chars[i])
    }
    print text","sum
}

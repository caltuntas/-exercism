BEGIN {
  FS=","
  allergens[0]="eggs"
  allergens[1]="peanuts"
  allergens[2]="shellfish"
  allergens[3]="strawberries"
  allergens[4]="tomatoes"
  allergens[5]="chocolate"
  allergens[6]="pollen"
  allergens[7]="cats"
}
{
  ops = $2
  score = $1
  item = $3

  len=length(allergens)
  while(score > 2^len){
    score = score - 2^len
  }

  for (i=len-1; i>=0; i--) {
    val = 2^i
    if( val > score )
      continue
    for (j=i; j>=0; j--) {
      val = 2^j
      if (total + val > score)
        continue
      total += val
      list = allergens[j] "," list
      if (total == score) {
        found = 1
        break
      }
    }
    if (found == 0)
      list = ""
  }

  if (ops == "allergic_to") {
    print index(list,item)?"true":"false"
  } else if (ops == "list" ) {
    gsub(/^,/, "", list)
    gsub(/,$/, "", list)
    print list
  }
}

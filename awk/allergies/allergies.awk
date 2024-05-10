
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

  for (i=len-1; i>=0; i--) {
    val = 2^i
    if( val > score )
      continue
    if(and(val, score) !=0) {
      list = allergens[i] "," list
    }
  }

  if (ops == "allergic_to") {
    print index(list,item)?"true":"false"
  } else if (ops == "list" ) {
    gsub(/^,/, "", list)
    gsub(/,$/, "", list)
    print list
  }
}

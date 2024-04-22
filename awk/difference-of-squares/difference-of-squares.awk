function square_of_sum(num) {
    sum = 0
    for (i=1; i<=num;i++) {
      sum +=i
      }
      return (sum*sum)
  }

  function sum_of_squares(num) {
    sum = 0
    for (i=1; i<=num;i++) {
      sum +=(i*i)
    }
    return sum
    }


BEGIN {
  FS=","
}
{

  if ($1=="square_of_sum") {
    print square_of_sum($2)
  }

  if ($1=="sum_of_squares") {
    print sum_of_squares($2)
  }

  if ($1=="difference") {
    print square_of_sum($2)-sum_of_squares($2)
  }

}

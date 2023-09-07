# These variables are initialized on the command line (using '-v'):
# - num

BEGIN {
  output = ""
  if (num % 3 == 0) {
    output=output "Pling"
  }
  if (num % 5 == 0) {
    output=output "Plang"
  }
  if (num % 7 == 0) {
    output=output "Plong"
  }

  if (length(output)==0) {
    output = num
  }

  print output
}

BEGIN {
    FS=OFS=","
}
END {
    who="you"
    if (NR > 0 && length($0) != 0) {
      who=$0
    }
    printf "One for %s, one for me.", who
  }

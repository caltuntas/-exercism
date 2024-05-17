{
  text = tolower($0)
  split(text,array,"")
  for (i=0; i<length(array); i++) {
    char = array[i]
    if (char ~ /[a-z]/)
      letters[char]++
  }
  print length(letters)==26?"true":"false"
}

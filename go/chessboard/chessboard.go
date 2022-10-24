package chessboard

type File []bool

type Chessboard map[string]File
// Declare a type named File which stores if a square is occupied by a piece - this will be a slice of bools

// Declare a type named Chessboard which contains a map of eight Files, accessed with keys from "A" to "H"

// CountInFile returns how many squares are occupied in the chessboard,
// within the given file.
func CountInFile(cb Chessboard, file string) int {
  row := cb[file]
  var count int
  for _, v := range row {
    if v == true {
      count ++
    }
  }
  return count
}

// CountInRank returns how many squares are occupied in the chessboard,
// within the given rank.
func CountInRank(cb Chessboard, rank int) int {
  var count int
  if rank < 1 && rank > 8 {
    return 0
  }
  for _,v := range cb {
    for i, val := range v {
      if (i + 1) == rank && val == true {
        count ++
      }
    }
  }
  return count
}

// CountAll should count how many squares are present in the chessboard.
func CountAll(cb Chessboard) int {
  var count int
  for _,v := range cb {
    count += len(v)
  }
  return count
}

// CountOccupied returns how many squares are occupied in the chessboard.
func CountOccupied(cb Chessboard) int {
  var count int
  for _,v := range cb {
    for _, val := range v {
      if val == true {
        count++
      }
    }
  }
  return count
}

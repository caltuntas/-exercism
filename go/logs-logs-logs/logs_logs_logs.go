package logs

import (
	"fmt"
	"unicode/utf8"
)

// Application identifies the application emitting the given log.
func Application(log string) string {
	for _,char := range log {

		// `recommendation` | ❗        | `U+2757`           |
		// `search`         | 🔍        | `U+1F50D`          |
		// `weather`        | ☀         | `U+2600`           |
		val := fmt.Sprintf("%U", char)
		if val == "U+2757" {
			return "recommendation"
		}
		if val == "U+1F50D" {
			return "search"
		}

		if val == "U+2600" {
			return "weather"
		}
	}
	return "default"
}

// Replace replaces all occurrences of old with new, returning the modified log
// to the caller.
func Replace(log string, oldRune, newRune rune) string {
  str := []rune(log)

  for i, char := range str {
    if char == oldRune {
      str[i] = newRune
    }
  }
  return string(str)
}

// WithinLimit determines whether or not the number of characters in log is
// within the limit.
func WithinLimit(log string, limit int) bool {
  return utf8.RuneCountInString(log) <= limit
}

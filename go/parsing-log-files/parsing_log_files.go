package parsinglogfiles

import (
	"regexp"
)

func IsValidLine(text string) bool {
  re := regexp.MustCompile(`^\[(TRC|DBG|INF|WRN|ERR|FTL)\].*`)
  return re.MatchString(text)
}

func SplitLogLine(text string) []string {
  if text == "" {
    return []string{""}
  }
  re := regexp.MustCompile(`([a-zA-Z]+ \d*)|<\w.*>`)
  return re.FindAllString(text, -1)
}

func CountQuotedPasswords(lines []string) int {
  re := regexp.MustCompile(`".*(?i)password.*"`)
  count := 0
  for _, str := range lines {
    if re.MatchString(str) {
      count ++
    }
  }
  return count
}

func RemoveEndOfLineText(text string) string {
  re := regexp.MustCompile(`end-of-line\d+`)
  return re.ReplaceAllString(text,"")
}

func TagWithUserName(lines []string) []string {
  re := regexp.MustCompile(`User\s+(\w+)`)
  newLines := make([]string, len(lines))
  for i, str := range lines {
    line := str
    if re.MatchString(str) {
      matches := re.FindAllStringSubmatch(str,-1)
      line = "[USR] " + matches[0][1] + " "+ line
    }
    newLines[i] = line
  }
  return newLines
}

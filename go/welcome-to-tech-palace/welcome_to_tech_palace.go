package techpalace

import "strings"

const message = "Welcome to the Tech Palace, "
// WelcomeMessage returns a welcome message for the customer.
func WelcomeMessage(customer string) string {
  return message + strings.ToUpper(customer)
}

// AddBorder adds a border to a welcome message.
func AddBorder(welcomeMsg string, numStarsPerLine int) string {
  stars := strings.Repeat("*",numStarsPerLine)
  output := stars + "\n" + welcomeMsg + "\n" + stars
  return output
}

// CleanupMessage cleans up an old marketing message.
func CleanupMessage(oldMsg string) string {
  msg := strings.ReplaceAll(oldMsg,"*","")
  return strings.TrimSpace(msg)
}

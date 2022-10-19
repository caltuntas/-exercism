package booking

import (
	"time"
)

// Schedule returns a time.Time from a string containing a date.
func Schedule(date string) time.Time {
  parsedTime, _ := time.Parse("1/2/2006 15:04:05",date)
  return parsedTime
}

// HasPassed returns whether a date has passed.
func HasPassed(date string) bool {
  parsedTime, _ := time.Parse("January 2, 2006 15:04:05",date)
  return parsedTime.Before(time.Now())
}

// IsAfternoonAppointment returns whether a time is in the afternoon.
func IsAfternoonAppointment(date string) bool {
  parsedTime, _ := time.Parse("Monday, January 2, 2006 15:04:05",date)
  return parsedTime.Hour() >= 12 && parsedTime.Hour() < 18
}

// Description returns a formatted string of the appointment time.
func Description(date string) string {
  parsedTime, _ := time.Parse("1/2/2006 15:04:05",date)
  return "You have an appointment on " + parsedTime.Format("Monday, January 2, 2006, at 15:04.")
}

// AnniversaryDate returns a Time with this year's anniversary.
func AnniversaryDate() time.Time {
		return time.Date(time.Now().Year(), time.September, 15, 0, 0, 0, 0, time.UTC)
}

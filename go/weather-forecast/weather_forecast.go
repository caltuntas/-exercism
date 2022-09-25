// Package weather provides almost perfect
// weather forecasts.
package weather

// CurrentCondition holds the value of condition.
var CurrentCondition string
// CurrentLocation holds the value of location.
var CurrentLocation string

// Forecast method provides a weather forecast.
func Forecast(city, condition string) string {
	CurrentLocation, CurrentCondition = city, condition
	return CurrentLocation + " - current weather condition: " + CurrentCondition
}

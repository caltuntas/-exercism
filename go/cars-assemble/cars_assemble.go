package cars

// CalculateWorkingCarsPerHour calculates how many working cars are
// produced by the assembly line every hour.
func CalculateWorkingCarsPerHour(productionRate int, successRate float64) float64 {
  return float64(productionRate) * successRate / 100
}

// CalculateWorkingCarsPerMinute calculates how many working cars are
// produced by the assembly line every minute.
func CalculateWorkingCarsPerMinute(productionRate int, successRate float64) int {
  return int(float64(productionRate) * (successRate / 100) / 60)
}

// CalculateCost works out the cost of producing the given number of cars.
func CalculateCost(carsCount int) uint {
  groups := carsCount / 10
  remaining := carsCount % 10

  cost := groups * 95000 + (remaining * 10000) 
  return uint(cost)
}

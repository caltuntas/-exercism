package purchase

import "fmt"

// NeedsLicense determines whether a license is needed to drive a type of vehicle. Only "car" and "truck" require a license.
func NeedsLicense(kind string) bool {
  if kind == "truck" || kind == "car" {
    return true
  }
  return false
}

// ChooseVehicle recommends a vehicle for selection. It always recommends the vehicle that comes first in lexicographical order.
func ChooseVehicle(option1, option2 string) string {
  var option string
  if option1 < option2 {
    option = option1
  } else {
    option = option2
  }
  return fmt.Sprintf("%s is clearly the better choice.", option)
}

// CalculateResellPrice calculates how much a vehicle can resell for at a certain age.
func CalculateResellPrice(originalPrice, age float64) float64 {
  var price float64
  if age >= 10 {
    price = originalPrice * 0.5
  } else if age >= 3 {
    price = originalPrice * 0.7
  } else {
    price = originalPrice * 0.8
  }
  return price
}

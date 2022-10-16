package lasagna

// TODO: define the 'PreparationTime()' function
func PreparationTime(layers []string, time int) int {
  avg := time
  if time == 0 {
    avg = 2
  }
  return len(layers) * avg
}

// TODO: define the 'Quantities()' function
func Quantities(layers []string ) (int, float64) {
  var noodles int
  var sauce float64

  for i:=0; i<len(layers); i++ {
    if layers[i] == "sauce" {
      sauce += 0.2
    }

    if layers[i] == "noodles" {
      noodles += 50
    }
  }
  return noodles,sauce
}

// TODO: define the 'AddSecretIngredient()' function
func AddSecretIngredient(friendsList []string, myList []string) {
  lastFriendItem := friendsList[len(friendsList)-1]
  myList[len(myList)-1] = lastFriendItem
}

// TODO: define the 'ScaleRecipe()' function
func ScaleRecipe(quantities []float64, number int) []float64 {
  list := make([]float64, len(quantities))
  for i,v := range quantities {
    list [i] = v * float64(number) / 2
  }
  return list
}

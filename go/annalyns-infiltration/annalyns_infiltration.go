package annalyn

// CanFastAttack can be executed only when the knight is sleeping
func CanFastAttack(knightIsAwake bool) bool {
  if knightIsAwake {
    return false
  }
  return true
}

// CanSpy can be executed if at least one of the characters is awake
func CanSpy(knightIsAwake, archerIsAwake, prisonerIsAwake bool) bool {
  if knightIsAwake || archerIsAwake || prisonerIsAwake {
    return true
  }
  return false
}

// CanSignalPrisoner can be executed if the prisoner is awake and the archer is sleeping
func CanSignalPrisoner(archerIsAwake, prisonerIsAwake bool) bool {
  if archerIsAwake {
    return false
  } else if prisonerIsAwake == false {
    return false
  }
  return true
}

// CanFreePrisoner can be executed if the prisoner is awake and the other 2 characters are asleep
// or if Annalyn's pet dog is with her and the archer is sleeping
func CanFreePrisoner(knightIsAwake, archerIsAwake, prisonerIsAwake, petDogIsPresent bool) bool {
  if archerIsAwake == false && petDogIsPresent {
    return true
  }

  if prisonerIsAwake && (knightIsAwake == false && archerIsAwake == false) {
    return true
  }
  return false
}

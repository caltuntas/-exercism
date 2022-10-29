package thefarm

import (
	"errors"
	"fmt"
)

type SillyNephewError struct {
  cows int
}

func(e *SillyNephewError) Error() string {
  return fmt.Sprintf("silly nephew, there cannot be %d cows", e.cows)
}
// See types.go for the types defined for this exercise.

// TODO: Define the SillyNephewError type here.

// DivideFood computes the fodder amount per cow for the given cows.
func DivideFood(weightFodder WeightFodder, cows int) (float64, error) {
  amount,err := weightFodder.FodderAmount()

  if cows < 0 {
    return 0,&SillyNephewError{
      cows: cows,
    }
  }

  if cows == 0 {
    return 0, errors.New("division by zero")
  }
  if err == nil {
    if amount < 0 {
      return 0, errors.New("negative fodder")
    }
    return amount / float64(cows), nil
  }

  if err == ErrScaleMalfunction {
    if amount >0 {
      return amount*2 / float64(cows), nil
    } else if amount < 0 {
      return 0, errors.New("negative fodder")
    }

  }
  return 0,err
}

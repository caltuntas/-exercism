package expenses

import "errors"

// Record represents an expense record.
type Record struct {
  Day      int
  Amount   float64
  Category string
}

// DaysPeriod represents a period of days for expenses.
type DaysPeriod struct {
  From int
  To   int
}

// Filter returns the records for which the predicate function returns true.
func Filter(in []Record, predicate func(Record) bool) []Record {
  list := make([]Record,0)
  for i:=0; i<len(in); i++ {
    r := in[i]
    if predicate(r) {
      list = append(list,r)
    }
  }
  return list
}

// ByDaysPeriod returns predicate function that returns true when
// the day of the record is inside the period of day and false otherwise.
func ByDaysPeriod(p DaysPeriod) func(Record) bool {
  predicate := func(r Record) bool {
    return r.Day >= p.From && r.Day <= p.To
  }
  return predicate
}

// ByCategory returns predicate function that returns true when
// the category of the record is the same as the provided category
// and false otherwise.
func ByCategory(c string) func(Record) bool {
  predicate := func(r Record) bool {
    return r.Category == c
  }
  return predicate
}

// TotalByPeriod returns total amount of expenses for records
// inside the period p.
func TotalByPeriod(in []Record, p DaysPeriod) float64 {
  total:= 0.0
  predicate := ByDaysPeriod(p)
  for i:=0; i<len(in); i++ {
    r := in[i]
    if predicate(r) {
      total += r.Amount
    }
  }
  return total
}

// CategoryExpenses returns total amount of expenses for records
// in category c that are also inside the period p.
// An error must be returned only if there are no records in the list that belong
// to the given category, regardless of period of time.
func CategoryExpenses(in []Record, p DaysPeriod, c string) (float64, error) {
  filtered := Filter(in, ByCategory(c))
  if len(filtered) <=0 {
    return 0.0, errors.New("there are no records")
  }
  total:= 0.0
  predicatePeriod := ByDaysPeriod(p)
  predicateCategory := ByCategory(c)
  for i:=0; i<len(in); i++ {
    r := in[i]
    if predicatePeriod(r) && predicateCategory(r) {
      total += r.Amount
    }
  }
  return total,nil
}

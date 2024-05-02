# The input will be null or an object that _may_ contain keys
#   actual_minutes_in_oven,
#   number_of_layers
#
# If the needed key is missing, use a default value:
#   zero minutes in oven,
#   one layer.
#
# Task: output a JSON object with keys:

. | (.actual_minutes_in_oven // 0) as $amin 
| (.number_of_layers // 1) as $layers 
| ($layers * 2) as $ptime
| 40 as $emin
|
{
  "expected_minutes_in_oven": $emin,
  "remaining_minutes_in_oven": ($emin - $amin),
  "preparation_time": $ptime,
  "total_time": ($amin + $ptime) 
}

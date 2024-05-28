local ArmstrongNumbers = {}

function ArmstrongNumbers.is_armstrong_number(number)
  local numstr = tostring(number)
  local sum = 0;
  for i=1, #numstr do
    local c = numstr:sub(i,i)
    sum = sum + (c ^ string.len(numstr)) 
  end
  return number == sum
end

return ArmstrongNumbers

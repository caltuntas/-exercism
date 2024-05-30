local EliudsEggs = {}

function EliudsEggs.egg_count(number)
  local count = 0
  while number~=0 do
    number = number & (number-1)
    count = count + 1
  end
  return count
end

return EliudsEggs

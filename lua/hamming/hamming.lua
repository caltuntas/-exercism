local Hamming = {}

function Hamming.compute(a,b)
  distance = 0
  lena = string.len(a)
  lenb = string.len(b)
  if lena ~= lenb then
    return -1
  end

  for i=1, #a do
    local c1 = a:sub(i,i)
    local c2 = b:sub(i,i)
    if c1 ~= c2 then
      distance = distance + 1
    end
  end
  return distance
end

return Hamming

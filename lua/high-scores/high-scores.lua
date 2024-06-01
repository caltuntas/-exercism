return function(scores)
  local obj = {  }
  local list = {table.unpack(scores)}
  function obj.scores()
    return list
  end

  function obj.latest()
    return list[#list]
  end

  function obj.personal_best()
    local l = {table.unpack(list)}
    table.sort(l)
    return l[#l]
  end

  function obj.personal_top_three()
    local values = scores
    table.sort(values,function(a,b) return a > b end)
    local top3 = {table.unpack(values,1,3)}
    values = { }
    for i,val in ipairs(top3) do
      table.insert(values,val)
    end
    return values
  end

  return obj
end

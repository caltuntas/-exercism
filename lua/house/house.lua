local house = {}

local text = { 
  "This is the horse and the hound and the horn",
  "that belonged to the farmer sowing his corn",
  "that kept the rooster that crowed in the morn",
  "that woke the priest all shaven and shorn",
  "that married the man all tattered and torn",
  "that kissed the maiden all forlorn",
  "that milked the cow with the crumpled horn",
  "that tossed the dog",
  "that worried the cat",
  "that killed the rat",
  "that ate the malt",
  "that lay in the house that Jack built."
}

house.verse = function(which)
  local i = #text+1-which
  local line = text[i]
  local m = string.match(line, "the %w+.*")
  local result = { "This is " .. m, table.unpack(text,i+1,#text) }
  return table.concat(result,'\n')
end

house.recite = function()
  local song = { }
    for i = 1, #text do
       local v = house.verse(i) 
       table.insert(song,v)
    end

  return table.concat(song,'\n')
end

return house

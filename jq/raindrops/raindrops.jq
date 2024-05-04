if (.number % 3) != 0 and (.number % 5) != 0 and (.number % 7) != 0 then .number 
else
if (.number % 3) == 0 then .res = (.res + "Pling")  end |
if (.number % 5) == 0 then .res = (.res + "Plang")  end |
if (.number % 7) == 0 then .res = (.res + "Plong")  end |
if .res == "" then .number else .res end
end



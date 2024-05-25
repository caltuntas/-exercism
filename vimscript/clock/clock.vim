
"
" Returns a clock that supports adding or subtracting minutes
" as well as formatting the current time for display
"

  function s:ToString() dict
    let total_mins = ((self.hours*60)+(self.minutes))
    let hours = ((float2nr(floor((24*60 + total_mins) / 60.0)) % 24) + 24) %  24
    let mins = total_mins % 60
    if mins < 0
      let mins += 60
    endif
    return printf("%02d:%02d",hours,mins)
  endfunction

  function! s:Add(minutes) dict
    let self.minutes += a:minutes
  endfunction

  function! s:Subtract(minutes) dict
    let self.minutes -= a:minutes
  endfunction

function! Clock(hours, minutes) abort
  return { 'hours': a:hours, 'minutes': a:minutes, 'ToString':function('s:ToString'), 'Add': function('s:Add'), 'Subtract': function('s:Subtract')  }
endfunction

"
" This function takes any remark and returns Bob's response.
"
function! Response(remark) abort
  let text = substitute(a:remark,'[^A-Za-z?]','','g') 
  if match(l:text, '^\C\u\+?$') > -1
    return "Calm down, I know what I'm doing!"
  elseif match(l:text,  '^\C\u\+$') > -1
    return "Whoa, chill out!"
  elseif match(l:text,  '?$') > -1
    return "Sure."
  endif
  if empty(substitute(a:remark,'\_s\|\r','','g'))
    return "Fine. Be that way!"
  endif

  return "Whatever."
endfunction

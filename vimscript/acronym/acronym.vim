"
" Convert a phrase into an uppercased acronym formed from
" the initial letter of each word, ignoring leading underscores
"
" Examples:
"
"   :echo Abbreviate('First In, First Out')
"   FIFO
"
"   :echo Abbreviate('The Road _Not_ Taken')
"   TRNT
"
function! Abbreviate(phrase) abort
  let words = split(toupper(a:phrase),'[^0-9A-Za-z'']')
  let result = ''
  for word in l:words 
    let result = result . word[0]
  endfor
  return result
endfunction 

"
" Create an implementation of the atbash cipher, an ancient encryption system
" created in the Middle East.
"
" Examples:
"
"   :echo AtbashEncode('test')
"   gvhg
"
"   :echo AtbashDecode('gvhg')
"   test
"
"   :echo AtbashDecode('gsvjf rxpyi ldmul cqfnk hlevi gsvoz abwlt')
"   thequickbrownfoxjumpsoverthelazydog
"

function! AtbashDecode(cipher) abort
  " your code goes here
  let start = 97
  let end = 97 + 25
  let encoded =""
  let counter = 1 
  let trimmed =  substitute(a:cipher, "\\s", "", "g")
  echo l:trimmed
  for c in tolower(trimmed)
    let cnr = char2nr(c) 
    if cnr >= l:start && cnr <= l:end
      let cn = l:end - (cnr - l:start)
      let l:encoded = l:encoded . nr2char(cn)
      let l:counter = l:counter + 1
    elseif cnr >= 48 && cnr <= 57
      let cn = l:cnr
      let l:encoded = l:encoded . nr2char(cn)
      let l:counter = l:counter + 1
    endif
  endfor
  return trim(l:encoded)
endfunction

function! AtbashEncode(plaintext) abort
  let start = 97
  let end = 97 + 25
  let encoded =""
  let counter = 1 
  for c in tolower(a:plaintext)
    let cnr = char2nr(c) 
    if cnr >= l:start && cnr <= l:end
      let cn = l:end - (cnr - l:start)
      let space = l:counter % 5 == 0 ? " ":""
      let l:encoded = l:encoded . nr2char(cn) . l:space
      let l:counter = l:counter + 1
    elseif cnr >= 48 && cnr <= 57
      let cn = l:cnr
      let space = l:counter % 5 == 0 ? " ":""
      let l:encoded = l:encoded . nr2char(cn) . l:space
      let l:counter = l:counter + 1
    endif
  endfor
  return trim(l:encoded)
endfunction

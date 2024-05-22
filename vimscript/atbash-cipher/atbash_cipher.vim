function! AtbashDecode(cipher) abort
  let text =  substitute(a:cipher, "\\s", "", "g")
  let text = tolower(text)
  let text =  substitute(l:text, "[a-z]", '\=nr2char(219-char2nr(submatch(0)))', "g")
  return trim(text)
endfunction

function! AtbashEncode(plaintext) abort
  let text = tolower(a:plaintext)
  let text =  substitute(l:text, "[^a-z0-9]", "", "g")
  let text =  substitute(l:text, "[a-z]", '\=nr2char(219-char2nr(submatch(0)))', "g")
  let text =  substitute(l:text, "\\w\\{1,5\\}", "& ", "g")
  return trim(l:text)
endfunction

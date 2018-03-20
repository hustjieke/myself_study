let Tlist_Ctags_Cmd='/usr/bin/ctags' 
set cindent
set tabstop=4
set shiftwidth=4
set softtabstop=4
set expandtab
set hlsearch
set encoding=utf-8 fileencoding=utf-8
set nu
set nocompatible
filetype on
filetype plugin indent on
syntax on
set autoindent
set smartindent
set showmatch
set incsearch
set nobackup
imap {} {}<ESC>i<CR><ESC>kl
imap () ()<ESC>i
imap <> <><ESC>i
imap [] []<ESC>i
imap "" ""<ESC>i
imap '' ''<ESC>i
imap <F3> <ESC>la

set tags+=./tags
set tags+=../tags

execute pathogen#infect()
set clipboard=unnamed
"set backspace=2
set foldmethod=indent
set foldlevel=99

map <F2> :NERDTreeToggle<CR>
map <F3> <plug>NERDTreeTabsToggle<CR>
map <Leader>f <plug>NERDTreeTabsFind<CR>

nmap <F8> :TagbarToggle<CR>
let g:tagbar_width = 30
let g:tagbar_sort = 0


"let g:tagbar_ctags_bin='/usr/local/bin/ctags'  " Proper Ctags locations
"let g:tagbar_width=26                          " Default is 40, seems too wide
"noremap <silent> <Leader>y :TagbarToggle       " Display panel with y (or ,y)
"autocmd BufReadPost *.cpp,*.c,*.h,*.hpp,*.cc,*.cxx call tagbar#autoopen()

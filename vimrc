
nmap <F7> :NERDTree<CR>
nmap <F8> :TlistToggle<CR>
"brew install macvim --with-override-system-vim

let g:ycm_global_ycm_extra_conf = '~/.vim/.ycm_extra_conf.py'
let g:ycm_confirm_extra_conf = 0 

filetype off                  " required
syntax on
set ignorecase
set nocompatible
set cindent
set ruler
set number
set hlsearch
set incsearch
set nu
set tabstop=8
set softtabstop=2
set shiftwidth=2
set smarttab
set expandtab
set smartcase
set shiftround
set helplang=ko
set expandtab
set fileencodings=ucs-bom,utf-8,default,euc-kr,latin1
set guifont=Bitstream\ Vera\ Sans\ Mono\ 9
set def=^\\s*#\\s*define
set inc=^\\s*#\\s*include
set scr=10
set nowrap
set cursorline
set nf=octal,hex
set cindent
set fen 
set foldlevel=2
set hls 
set list listchars=tab:»›,trail:·

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()


Plugin 'VundleVim/Vundle.vim'

" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
Plugin 'tpope/vim-fugitive'
" plugin from http://vim-scripts.org/vim/scripts.html
Plugin 'L9'
" Git plugin not hosted on GitHub
Plugin 'git://git.wincent.com/command-t.git'
Plugin 'The-NERD-tree'
Plugin 'tpope/vim-fugitive'
Plugin 'taglist.vim'
Plugin 'Valloric/YouCompleteMe'

call vundle#end()            " required
filetype plugin indent on    " required
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

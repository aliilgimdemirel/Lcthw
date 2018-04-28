# Lcthw / LCTHW
Learn C the Hard way


## VI Cheat sheet
In vim documentation CTRL is refered as ^, so will.

* mapping a key for example;
	``` 
	:map <C-A-PageUp> <C-W><C-W>
	```
	If I were to add PageDn version aswell I'll put this to my vimrc !! Yaay.
* **zz** Scrolls current line to the middle of your screen. 
* **AUTO FILL !!!** ^P or ^N. For more; [this](https://www.youtube.com/watch?v=3TX3kV3TICU) is quite nice




<table>
<tr><td>Tabs and Management</td></tr>
<tr><td>:split filename </td><td>- split window horizontally and load filename</td></tr>
<tr><td>:vsplit file </td><td>     - vertical split and open file</td></tr>
<tr><td>^w up arrow </td><td>  - move cursor up a window</td></tr>
<tr><td>^w ^w </td><td>    - move cursor to another window (cycle)</td></tr>
<tr><td>^w _ </td><td>         - maximize current window vertically</td></tr>
<tr><td>^w | </td><td>         - maximize current window horizontally</td></tr>
<tr><td>^w = </td><td>         - make all equal size</td></tr>
<tr><td>^w H </td><td>	       - resize cur Window to take all of the Left side</td></tr>
<tr><td>^w J </td><td>         - resize cur Window to take all of the Top side</td></tr>
<tr><td>^w K </td><td>         - resize cur Window to take all of the Bottom side</td></tr>
<tr><td>^w L </td><td>         - resize cur Window to take all of the Right side</td></tr>
<tr><td>^w ^7 </td><td>         - maximize cur Window in its current pane vertically</td></tr>
<tr><td>:sview file </td><td>      - same as split, but readonly</td></tr>
<tr><td>:close </td><td>           - close current window</td></tr>
<tr><td>TODO ADD tabs !! </td><td>           - TAAABS TODO </td></tr>
<tr><td>:tabdo {cmd} </td><td>           - does the **cmd** for all windows inside the current tab (e.g., s/join/merge/ge. e here is for ignoring errors if join is not found in a file perse.) </td></tr>
<tr><td>^W [N] - </td><td>  Decrease current window height by N (default 1)</td></tr>
<tr><td>^W [N] + </td><td>  Increase current window height by N (default 1)</td></tr>
<tr><td>^W [N] < </td><td>  Decrease current window width by N (default 1)</td></tr>
<tr><td>^W [N] > </td><td>  Increase current window width by N (default 1)</td></tr>
<tr><td>^W [N] > </td><td>  Increase current window width by N (default 1)</td></tr>
<tr><td>Session Save/Load</td></tr>
<tr><td>:mksession header-files-work.vim </td><td> Saves the session</td></tr>
<tr><td>$ vim -S header-files-work.vim   </td><td> Loads it from terminal</td></tr>
<tr><td>:source header-files-work.vim    </td><td> Loads it from inside VI</td></tr>
</table>


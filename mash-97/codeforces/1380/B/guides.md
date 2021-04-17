# Guides on using hbcli.rb program

## Description

It's a program to check what are the possible solutions for bot_strings (described in the problem statements).
With this program you can check for a single bot string or by feeding a input file based on the format prescribed in the problem.


## Requirements

  * You need to have installed ruby on your system.
  * You need to have `Thor` gem in your system. You can add the gem by running `gem install thor` from your command line.


## Uses

  * To check for a single bot string, type from the directory where the hbcli.rb and hard_brute_force.rb is placed in command line:
    `ruby hbcli.rb us RSP --max_show 10` which will print:
    
    ```bash
    Bot String: RSP
    max_average value is: 1.0
    Possible solutions(27 available | try showing 10): 
	["R", "R", "R"] ==>	RRR
	["R", "R", "P"] ==>	RRP
	["R", "R", "S"] ==>	RRS
	["R", "P", "R"] ==>	RPR
	["R", "P", "P"] ==>	RPP
	["R", "P", "S"] ==>	RPS
	["R", "S", "R"] ==>	RSR
	["R", "S", "P"] ==>	RSP
	["R", "S", "S"] ==>	RSS
	["P", "R", "R"] ==>	PRR
	["P", "R", "P"] ==>	PRP
    ```
    
  * To check from a input file, type (suppose input file name is 'input.tst'): 
    `ruby hbcli.rb usf input.tst --max_show 10`

  

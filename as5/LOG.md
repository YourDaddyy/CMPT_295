## ********************FAILED********************

****************************************
## ********************SUCCESS********************
#### *****make Relu.bin*****
 ```g++ -I./common -I./SoA -I./Relu -I./ReluEXT -I./Caxpy -I./Imax -DPREALLOCATE=1 -ggdb -ffast-math -fno-common -fno-builtin-printf -Wall -o Relu.bin ./Relu/main.cpp ./common/intrin.cpp ./common/logger.cpp -lm  

```
#### *****timeout 60 ./Relu.bin -l*****
 ```
[1;31mRELU [0m  
[1;31mRelu Serial [0m  
Results matched with answer!
Passed!!!
[1;31mRelu Vector [0m  
Results matched with answer!
***************** Printing Vector Unit Execution Log *****************
 Instruction | Vector Lane Occupancy ('*' for active, '_' for inactive)
------------- --------------------------------------------------------
        vset | ********
        vset | ********
       vload | ********
         vlt | ********
     masknot | ********
       vmove | _*___*_*
      vstore | ********
      vstore | _*___*_*
       vload | ********
         vlt | ********
     masknot | ********
       vmove | *_*_*__*
      vstore | ********
      vstore | *_*_*__*
       vload | ********
         vlt | ********
     masknot | ********
       vmove | *_*_*__*
      vstore | ********
      vstore | *_*_*__*
       vload | ********
         vlt | ********
     masknot | ********
       vmove | **_**_**
      vstore | ********
      vstore | **_**_**
       vload | ********
         vlt | ********
     masknot | ********
       vmove | _***___*
      vstore | ********
      vstore | _***___*
       vload | ********
         vlt | ********
     masknot | ********
       vmove | **__****
      vstore | ********
      vstore | **__****
       vload | ********
         vlt | ********
     masknot | ********
       vmove | _*__*__*
      vstore | ********
      vstore | _*__*__*
       vload | ********
         vlt | ********
     masknot | ********
       vmove | _**__*__
      vstore | ********
      vstore | _**__*__
       vload | ********
         vlt | ********
     masknot | ********
       vmove | ***_____
      vstore | ********
      vstore | ***_____
       vload | ********
         vlt | ********
     masknot | ********
       vmove | *****___
      vstore | ********
      vstore | *****___
       vload | ********
         vlt | ********
     masknot | ********
       vmove | _******_
      vstore | ********
      vstore | _******_
       vload | ********
         vlt | ********
     masknot | ********
       vmove | *_******
      vstore | ********
      vstore | *_******
       vload | ********
         vlt | ********
     masknot | ********
       vmove | ____**__
      vstore | ********
      vstore | ____**__
       vload | ********
         vlt | ********
     masknot | ********
       vmove | _*_***_*
      vstore | ********
      vstore | _*_***_*
       vload | ********
         vlt | ********
     masknot | ********
       vmove | _*_**_*_
      vstore | ********
      vstore | _*_**_*_
       vload | ********
         vlt | ********
     masknot | ********
       vmove | *___*_**
      vstore | ********
      vstore | *___*_**
       vload | ********
         vlt | ********
     masknot | ********
       vmove | *___**__
      vstore | ********
      vstore | *___**__
       vload | ********
         vlt | ********
     masknot | ********
       vmove | **_*___*
      vstore | ********
      vstore | **_*___*
       vload | ********
         vlt | ********
     masknot | ********
       vmove | *__*___*
      vstore | ********
      vstore | *__*___*
       vload | ********
         vlt | ********
     masknot | ********
       vmove | ********
      vstore | ********
      vstore | ********
       vload | ********
         vlt | ********
     masknot | ********
       vmove | ___**__*
      vstore | ********
      vstore | ___**__*
       vload | ********
         vlt | ********
     masknot | ********
       vmove | **__*___
      vstore | ********
      vstore | **__*___
       vload | ********
         vlt | ********
     masknot | ********
       vmove | ***___**
      vstore | ********
      vstore | ***___**
       vload | ********
         vlt | ********
     masknot | ********
       vmove | *_*_____
      vstore | ********
      vstore | *_*_____
       vload | ********
         vlt | ********
     masknot | ********
       vmove | ****____
      vstore | ********
      vstore | ****____
       vload | ********
         vlt | ********
     masknot | ********
       vmove | __*_*_**
      vstore | ********
      vstore | __*_*_**
       vload | ********
         vlt | ********
     masknot | ********
       vmove | *___**__
      vstore | ********
      vstore | *___**__
       vload | ********
         vlt | ********
     masknot | ********
       vmove | *__*_*__
      vstore | ********
      vstore | *__*_*__
       vload | ********
         vlt | ********
     masknot | ********
       vmove | *_*___**
      vstore | ********
      vstore | *_*___**
       vload | ********
         vlt | ********
     masknot | ********
       vmove | **_**__*
      vstore | ********
      vstore | **_**__*
       vload | ********
         vlt | ********
     masknot | ********
       vmove | *__*****
      vstore | ********
      vstore | *__*****
       vload | ********
         vlt | ********
     masknot | ********
       vmove | ******__
      vstore | ********
      vstore | ******__
****************** Printing Vector Unit Statistics *******************
Vector Width:              8
Total Vector Instructions: 194
Vector Utilization:        84.407216%
Utilized Vector Lanes:     1310
Total Vector Lanes:        1552
Passed!!!

```
#### *****make ReluEXT.bin*****
 ```g++ -I./common -I./SoA -I./Relu -I./ReluEXT -I./Caxpy -I./Imax -DPREALLOCATE=1 -ggdb -ffast-math -fno-common -fno-builtin-printf -Wall -o ReluEXT.bin ./ReluEXT/main.cpp ./common/intrin.cpp ./common/logger.cpp -lm  

```
#### *****timeout 60 ./ReluEXT.bin -l*****
 ```
[1;31mRELU [0m  
[1;31mRelu Serial [0m  
Results matched with answer!
Passed!!!
[1;31mRelu Vector [0m  
Results matched with answer!
***************** Printing Vector Unit Execution Log *****************
 Instruction | Vector Lane Occupancy ('*' for active, '_' for inactive)
------------- --------------------------------------------------------
        vset | ********
        vset | ********
       vload | ********
         vlt | ********
     masknot | ********
       vmove | *_*_***_
      vstore | ********
      vstore | *_*_***_
       vload | ********
         vlt | ********
     masknot | ********
       vmove | _***__**
      vstore | ********
      vstore | _***__**
       vload | ********
         vlt | ********
     masknot | ********
       vmove | _*_**__*
      vstore | ********
      vstore | _*_**__*
       vload | ********
         vlt | ********
     masknot | ********
       vmove | _*______
      vstore | ********
      vstore | _*______
       vload | ********
         vlt | ********
     masknot | ********
       vmove | **___*_*
      vstore | ********
      vstore | **___*_*
       vload | ********
         vlt | ********
     masknot | ********
       vmove | *_*_***_
      vstore | ********
      vstore | *_*_***_
       vload | ********
         vlt | ********
     masknot | ********
       vmove | *_**___*
      vstore | ********
      vstore | *_**___*
       vload | ********
         vlt | ********
     masknot | ********
       vmove | _**_____
      vstore | ********
      vstore | _**_____
       vload | ********
         vlt | ********
     masknot | ********
       vmove | __**__*_
      vstore | ********
      vstore | __**__*_
       vload | ********
         vlt | ********
     masknot | ********
       vmove | ___*_***
      vstore | ********
      vstore | ___*_***
       vload | ********
         vlt | ********
     masknot | ********
       vmove | __*__**_
      vstore | ********
      vstore | __*__**_
       vload | ********
         vlt | ********
     masknot | ********
       vmove | *___**_*
      vstore | ********
      vstore | *___**_*
       vload | ********
         vlt | ********
     masknot | ********
       vmove | ********
      vstore | ********
      vstore | ********
****************** Printing Vector Unit Statistics *******************
Vector Width:              8
Total Vector Instructions: 80
Vector Utilization:        83.750000%
Utilized Vector Lanes:     536
Total Vector Lanes:        640
Passed!!!

```
#### *****make Caxpy.bin*****
 ```g++ -I./common -I./SoA -I./Relu -I./ReluEXT -I./Caxpy -I./Imax -DPREALLOCATE=1 -ggdb -ffast-math -fno-common -fno-builtin-printf -Wall -o Caxpy.bin ./Caxpy/main.cpp ./common/intrin.cpp ./common/logger.cpp -lm  

```
#### *****timeout 60 ./Caxpy.bin -l*****
 ```
[1;31mCAXPY Serial [0m  
Results matched with answer!
Passed!!!
***************** Printing Vector Unit Execution Log *****************
 Instruction | Vector Lane Occupancy ('*' for active, '_' for inactive)
------------- --------------------------------------------------------
        vset | ********
       vload | ********
       vload | ********
       vload | ********
         veq | ********
     masknot | ********
        vset | ********
       vmult | __*_**__
        vadd | __*_**__
      vstore | __*_**__
       vload | ********
       vload | ********
       vload | ********
         veq | ********
     masknot | ********
        vset | ********
       vmult | **_____*
        vadd | **_____*
      vstore | **_____*
       vload | ********
       vload | ********
       vload | ********
         veq | ********
     masknot | ********
        vset | ********
       vmult | ___**_**
        vadd | ___**_**
      vstore | ___**_**
       vload | ********
       vload | ********
       vload | ********
         veq | ********
     masknot | ********
        vset | ********
       vmult | _**_*___
        vadd | _**_*___
      vstore | _**_*___
       vload | ********
       vload | ********
       vload | ********
         veq | ********
     masknot | ********
        vset | ********
       vmult | _*__*___
        vadd | _*__*___
      vstore | _*__*___
       vload | ********
       vload | ********
       vload | ********
         veq | ********
     masknot | ********
        vset | ********
       vmult | *_*__*__
        vadd | *_*__*__
      vstore | *_*__*__
       vload | ********
       vload | ********
       vload | ********
         veq | ********
     masknot | ********
        vset | ********
       vmult | **__*_*_
        vadd | **__*_*_
      vstore | **__*_*_
       vload | ********
       vload | ********
       vload | ********
         veq | ********
     masknot | ********
        vset | ********
       vmult | _**_**_*
        vadd | _**_**_*
      vstore | _**_**_*
       vload | ********
       vload | ********
       vload | ********
         veq | ********
     masknot | ********
        vset | ********
       vmult | **__***_
        vadd | **__***_
      vstore | **__***_
       vload | ********
       vload | ********
       vload | ********
         veq | ********
     masknot | ********
        vset | ********
       vmult | *______*
        vadd | *______*
      vstore | *______*
       vload | ********
       vload | ********
       vload | ********
         veq | ********
     masknot | ********
        vset | ********
       vmult | __*____*
        vadd | __*____*
      vstore | __*____*
       vload | ********
       vload | ********
       vload | ********
         veq | ********
     masknot | ********
        vset | ********
       vmult | ****_*_*
        vadd | ****_*_*
      vstore | ****_*_*
       vload | ********
       vload | ********
       vload | ********
         veq | ********
     masknot | ********
        vset | ********
       vmult | *_*_*___
        vadd | *_*_*___
      vstore | *_*_*___
****************** Printing Vector Unit Statistics *******************
Vector Width:              8
Total Vector Instructions: 118
Vector Utilization:        81.250000%
Utilized Vector Lanes:     767
Total Vector Lanes:        944
[1;31mCAXPY Vector [0m  
Results matched with answer!
Passed!!!

```
#### *****make SoA.bin*****
 ```g++ -I./common -I./SoA -I./Relu -I./ReluEXT -I./Caxpy -I./Imax -DPREALLOCATE=1 -ggdb -ffast-math -fno-common -fno-builtin-printf -Wall -o SoA.bin ./SoA/main.cpp ./common/intrin.cpp ./common/logger.cpp -lm  

```
#### *****timeout 60 ./SoA.bin -l*****
 ```
[1;31mARRAY SUM[0m (bonus) 
***************** Printing Vector Unit Execution Log *****************
 Instruction | Vector Lane Occupancy ('*' for active, '_' for inactive)
------------- --------------------------------------------------------
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
****************** Printing Vector Unit Statistics *******************
Vector Width:              8
Total Vector Instructions: 12
Vector Utilization:        100.000000%
Utilized Vector Lanes:     96
Total Vector Lanes:        96
Passed!!!

```
#### *****make Imax.bin*****
 ```g++ -I./common -I./SoA -I./Relu -I./ReluEXT -I./Caxpy -I./Imax -DPREALLOCATE=1 -ggdb -ffast-math -fno-common -fno-builtin-printf -Wall -o Imax.bin ./Imax/main.cpp ./common/intrin.cpp ./common/logger.cpp -lm  

```
#### *****timeout 60 ./Imax.bin -l*****
 ```
[1;31mIMAX [0m  
[1;31mIMAX Serial [0m  
Results matched with answer!
Passed!!!
[1;31mIMAX Vector [0m  
Results matched with answer!
***************** Printing Vector Unit Execution Log *****************
 Instruction | Vector Lane Occupancy ('*' for active, '_' for inactive)
------------- --------------------------------------------------------
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
       vload | ********
****************** Printing Vector Unit Statistics *******************
Vector Width:              8
Total Vector Instructions: 32
Vector Utilization:        100.000000%
Utilized Vector Lanes:     256
Total Vector Lanes:        256
Passed!!!

```

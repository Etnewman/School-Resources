
.386

.MODEL FLAT

ExitProcess PROTO NEAR32 stdcall, dwExitCode:DWORD

INCLUDE debug.h
INCLUDE sqrt.h

.STACK  4096           

.DATA                   

; declare these first so that they are all on WORD boundaries

eye_x       WORD    ?
eye_y       WORD    ?
eye_z       WORD    ?

eyexprompt      BYTE    "Enter the x-coordinate of the camera eyepoint:  ", 0
eyeyprompt      BYTE    "Enter the y-coordinate of the camera eyepoint:  ", 0
eyezprompt      BYTE    "Enter the z-coordinate of the camera eyepoint:  ", 0


display         		BYTE    50 DUP (?), 0 ; the text to display in (x, y, z) format
output_u        	BYTE    "u: ", 0
output_v        	BYTE    "v: ", 0
output_n        	BYTE    "n: ", 0

eol             		BYTE    CR, LF, 0     ; end of line

-----------------------------------------------------------------------------------------------
; TO DO  // define all relevant variables
-----------------------------------------------------------------------------------------------




.CODE          

getCoord    MACRO   prompt, var
               inputW  prompt, var
               mov     var, ax         ; store the result in memory
               outputW ax
            ENDM


get_and_display MACRO prompt1, prompt2, prompt3, prompt4, x1, x2, x3
                  getCoord prompt1, x1       

-----------------------------------------------------------------------------------------------
; TO DO  // rest of the relevant statements
-----------------------------------------------------------------------------------------------
 
				  
				  
				  
                  printPoint prompt4, x1, x2, x3  
                ENDM                            


printPoint  MACRO   point, xvar, yvar, zvar
               output eol
               mov     point, "("
               itoa    point + 1, xvar ; convert xvar to digits and place after the "("
               mov     point + 7, ","  ; insert the comma after the digits for xvar

			   
-----------------------------------------------------------------------------------------------
; TO DO  // rest of the relevant statements
-----------------------------------------------------------------------------------------------

			   
			   
			   
			   
            ENDM

printNormPoint  MACRO   point, xvar, yvar, zvar, len
               itoa point + 5, len
               itoa point + 16, len
               itoa point + 27, len

               output eol
               mov     point + 0, "("

               itoa    point + 1, xvar  
               mov     point + 7, "/"  
               mov     point + 11, ","


-----------------------------------------------------------------------------------------------
; TO DO  // rest of the relevant statements
-----------------------------------------------------------------------------------------------
			   
			   
			   
               output  point
               output  eol
            ENDM

; computes the dot product of two vectors
dot_product MACRO   x1, y1, z1, x2, y2, z2
               mov ax, x1
               mov bx, x2
               imul bx        ; x1 * x2 is in ax  (actually dx::ax, high order bits dropped)
               mov cx, ax     ; the accumulating result will be in cx

-----------------------------------------------------------------------------------------------
; TO DO  // rest of the relevant statements
-----------------------------------------------------------------------------------------------



            ENDM

; computes the cross product of two vectors
cross_product MACRO   x1, y1, z1, x2, y2, z2, x3, y3, z3
               mov ax, y1
               mov bx, z2
               mul bx         ; result in dx::ax
               mov cx, ax

               mov ax, z1     
               mov bx, y2
               mul bx         ; result in dx::ax
               neg ax

               add ax, cx
               mov x3, ax


-----------------------------------------------------------------------------------------------
; TO DO  // rest of the relevant statements
-----------------------------------------------------------------------------------------------




            ENDM

; performs point-point subtraction to obtain a vector
point_subtract MACRO x1, y1, z1, x2, y2, z2, vx, vy, vz
                  mov ax, x1
                  mov bx, x2
                  sub ax, bx
                  mov vx, ax

-----------------------------------------------------------------------------------------------
; TO DO  // rest of the relevant statements
-----------------------------------------------------------------------------------------------

				  
				  
               ENDM

; performs point-vector addition to obtain a new point
point_vector_add MACRO x, y, z, vx, vy, vz, xn, yn, zn
                  mov ax, x
                  mov bx, vx
                  add ax, bx
                  mov xn, ax

-----------------------------------------------------------------------------------------------
; TO DO  // rest of the relevant statements
-----------------------------------------------------------------------------------------------



				  ENDM


				  
				  
vector_length	MACRO x, y, z
                   
				   
-----------------------------------------------------------------------------------------------
; TO DO  // rest of the relevant statements
-----------------------------------------------------------------------------------------------
				   
				   
				   
                ENDM






_start:

          get_and_display eyexprompt, eyeyprompt, eyezprompt, display, eye_x, eye_y, eye_z
 




 
-----------------------------------------------------------------------------------------------
; TO DO  // rest of the relevant statements

; Hints: 

          ; calculate n 

          
          ; define ndotn

          ; find (n.n)v = -(vup.n)n + (n.n)vup

          ; compute (n.n)vup

          
          ; compute -(vup.n)n and add to previous
          

          ; claculate cross_product of v and n to get u 

          ; calculate the vector lengths of u, v and n 
-----------------------------------------------------------------------------------------------
		  
		  
		  

          
          
          output eol
          output eol
          output output_u
          printNormPoint display, u_x, u_y, u_z, length_u
          
-----------------------------------------------------------------------------------------------
; TO DO  // rest of the relevant statements
; Hint:

         ; print the rest of the points
-----------------------------------------------------------------------------------------------
		  
		  


        INVOKE  ExitProcess, 0  ; exit with return code 0

PUBLIC _start                   ; make entry point public

END                             ; end of source code
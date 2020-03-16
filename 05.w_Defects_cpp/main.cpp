/********Software Analysis - FY2013*************/
/*
* File Name: main.cpp
* Defect Classification
* ---------------------
* Defect Type: Inappropriate code
* Defect Sub-type: Improper error handling
* Description: Defect Code to identify improper try..catch error handling
* Created on: Nov 8, 2012
*     Author: caesaru01
*/

#include"HeaderFile.hpp"


volatile int vflag;
volatile int vflag_copy;
volatile int vflag_file;

int main(int argc,char*argv[])
{
        if(argv[1])
        {
            vflag_copy = atoi(argv[1]);
            vflag_file = (int)floor((double)vflag_copy/1000.0);
            vflag = (int)floor((int)vflag_copy%1000);
            printf("vflag_file = %d vflag_func = %d vflag_copy =%d \n" , vflag_file, vflag,vflag_copy);
            if(vflag_file == 1 || vflag_file == 888)
            {
                AllocatorTest_001();
            }
            if(vflag_file == 2 || vflag_file == 888)
            {
                AllocatorTest_002();
            }
            if(vflag_file == 3 || vflag_file == 888)
            {
                AllocatorTest_003();
            }
            if(vflag_file == 4 || vflag_file == 888)
            {
                AllocatorTest_004();
            }
            if(vflag_file == 5 || vflag_file == 888)
            {
                AllocatorTest_005();
            }
            if(vflag_file == 6 || vflag_file == 888)
            {
                ConstructorTest_001();
            }
            if(vflag_file == 7 || vflag_file == 888)
            {
                ConstructorTest_002();
            }
            if(vflag_file == 8 || vflag_file == 888)
            {
                ConstructorTest_003();
            }
            if(vflag_file == 9 || vflag_file == 888)
            {
                ConstructorTest_004();
            }
            if(vflag_file == 10 || vflag_file == 888)
            {
                ConstructorTest_005();
            }
            if(vflag_file == 11 || vflag_file == 888)
            {
                ConstructorTest_006();
            }
            if(vflag_file == 12 || vflag_file == 888)
            {
                LambdaTest_001();
            }
            if(vflag_file == 13 || vflag_file == 888)
            {
                LambdaTest_002();
            }
            if(vflag_file == 14 || vflag_file == 888)
            {
                LambdaTest_003();
            }
            if(vflag_file == 15 || vflag_file == 888)
            {
                LambdaTest_004();
            }
            if(vflag_file == 16 || vflag_file == 888)
            {
                LambdaTest_005();
            }
            if(vflag_file == 17 || vflag_file == 888)
            {
                LambdaTest_006();
            }
            if(vflag_file == 18 || vflag_file == 888)
            {
                LambdaTest_007();
            }
            if(vflag_file == 19 || vflag_file == 888)
            {
                OperatorsTest_001();
            }
            if(vflag_file == 20 || vflag_file == 888)
            {
                VirtualTest_001();
            }
			//asd
            if(vflag_file == 21 || vflag_file == 888)
            {
                DestructorTest_001();
            }
            if(vflag_file == 22 || vflag_file == 888)
            {
                DestructorTest_0011();
            }
            if(vflag_file == 23 || vflag_file == 888)
            {
                DestructorTest_0012();
            }
            if(vflag_file == 24 || vflag_file == 888)
            {
                DestructorTest_0013();
            }
            if(vflag_file == 25 || vflag_file == 888)
            {
                DestructorTest_002();
            }
            if(vflag_file == 26 || vflag_file == 888)
            {
                DestructorTest_0021();
            }
            if(vflag_file == 27 || vflag_file == 888)
            {
                DestructorTest_0022();
            }
            if(vflag_file == 28 || vflag_file == 888)
            {
                DestructorTest_0023();
            }
            if(vflag_file == 29 || vflag_file == 888)
            {
                DestructorTest_003();
            }
			if(vflag_file == 30 || vflag_file == 888)
            {
                DestructorTest_0031();
            }
			if(vflag_file == 31 || vflag_file == 888)
            {
                DestructorTest_0032();
            }
			if(vflag_file == 32 || vflag_file == 888)
            {
                DestructorTest_004();
            }
			if(vflag_file == 33 || vflag_file == 888)
            {
                DestructorTest_0041();
            }
			if(vflag_file == 34 || vflag_file == 888)
            {
                DestructorTest_0042();
            }
			if(vflag_file == 35 || vflag_file == 888)
            {
                DestructorTest_0043();
            }
			if(vflag_file == 36 || vflag_file == 888)
            {
                DestructorTest_005();
            }
			if(vflag_file == 37 || vflag_file == 888)
            {
                DestructorTest_0051();
            }
			if(vflag_file == 38 || vflag_file == 888)
            {
                DestructorTest_0052();
            }
			if(vflag_file == 39 || vflag_file == 888)
            {
                DestructorTest_0053();
            }
			if(vflag_file == 40 || vflag_file == 888)
            {
                DestructorTest_006();
            }
			if(vflag_file == 41 || vflag_file == 888)
            {
                DestructorTest_0061();
            }
			if(vflag_file == 42 || vflag_file == 888)
            {
                DestructorTest_0062();
            }
			if(vflag_file == 43 || vflag_file == 888)
            {
                DestructorTest_0063();
            }
			if(vflag_file == 44 || vflag_file == 888)
            {
                DestructorTest_007();
            }
			if(vflag_file == 45 || vflag_file == 888)
            {
                DestructorTest_0071();
            }
			if(vflag_file == 46 || vflag_file == 888)
            {
                DestructorTest_0072();
            }
			if(vflag_file == 47 || vflag_file == 888)
            {
                DestructorTest_0073();
            }
			if(vflag_file == 48 || vflag_file == 888)
            {
                DestructorTest_0074();
            }
			if(vflag_file == 49 || vflag_file == 888)
            {
                DestructorTest_008();
            }
				
			


            
        }
        else
        {
                printf("Enter File XXX and Function XXX \n");
                printf("Example: To Execute 1st File 3rd Function , Enter 001003 \n");
                printf("Example: To Execute All Files ,Enter 888888 \n");
                printf("Example: To Execute All functions in a File :Sample - To execute all functions in 1st file,Enter 001888 \n");
        }
    return 0;
}
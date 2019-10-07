*******************************************************
*  Name      :  Tobby Lie      
*  Student ID:  103385744      
*  Class     :  CSCI 2421           
*  HW#       :  Final Project              
*  Due Date  :  Nov. 20, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program is a data base that allows the user to perform operations 
on records. Operations such as searching, sorting, modifying etc. 

Extra credit completed. Created four special report functions which report 
statistics about the records.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions.

Name:  ActorActressRecord.h
   Contains the definition for the class ActorActressRecord.  

Name: ActorActressRecord.cpp
   Defines and implements the ActorActressRecord class.
   This class provides setters and getters for private variables.

Name:  PictureRecord.h
   Contains the definition for the class PictureRecord.  

Name: PictureRecord.cpp
   Defines and implements the PictureRecord class.
   This class provides setters and getters for private variables.

Name:  ActorBST
   Contains the definition for the class ActorBST.  

Name: ActorBST.cpp
   Defines and implements the ActorBST class.
   Functions implemented here are for key functions of a binary 
   search tree.

Name:  PictureBST.h
   Contains the definition for the class PictureBST.  

Name: PictureBST.cpp
   Defines and implements the PictureBST class.
   Functions implemented here are for key functions of a binary 

Name: Functions.h
   Implementation for functions utilized to operate on database
   records.
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on Xcode.  It was 
   compiled, run, and tested on gcc 4.8 on csegrid.ucdenver.pvt.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip LieFinalProject.zip

   Now you should see a directory named LieFinalProject with the files:
        main.cpp
        ActorActressRecord.h
	ActorActressRecord.cpp
	ActorBST.h
	ActorBST.cpp
	PictureRecord.h
	PictureRecord.cpp
	PictureBST.h
	PictureBST.cpp
	Functions.h
        makefile
        Readme.txt
	CSCI 2421 Data Structures - Final Project Design.pdf
	actor-actress.csv
	pictures.csv
	ActorReport.txt
	PictureReport.txt
	updatedFileActor.txt
	updatedFilePicture.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd LieFinalProject

    Compile the program by:
    % make

3. Run the program by:
   % ./finalproject

4. Delete the obj files, executables, and core dump by
   %./make clean

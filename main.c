#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
/******************************************************************************
# Author:           Liam Campbell
# Lab:              Assignment 6
# Date:             October 31st, 2023
# Description:    Encodes a file name using details from the user.
# Input:           
Char [] lastName
Char [] firstName
Bool lateSubmission
Char [] studentId
Int submitHour
Int submitMin
Char userOption
Char [] fileName

# Output:           char [] encodedFileName
# Sources:          None
#******************************************************************************/
int main(void) {
  char userOption, lateAnswer, submitHourOne, submitHourTwo, submitMinOne, submitMinTwo;
  char firstName[50], lastName[50], studentId[11], encodedFileName[100], fileName[50], submitTime[5];
  bool lateSubmission = false;
  int firstNameLength, lastNameLength, encodedFileLength = 0, submitHour, submitMin, currentSpot;
  
  printf("Welcome to my fileName encoding program!!\n");

  printf("Please pick an option below: \n");
  printf("e: encode file name\n");
  printf("q: quit\n");

  scanf(" %c", &userOption);

  if(userOption == 'e'){
    // get first name and last name
    printf("Enter your last name: ");
    scanf("%s", lastName);
    printf("Enter your first name: ");
    scanf("%s", firstName);

    lastNameLength = strlen(lastName);
    firstNameLength = strlen(firstName);
    
    // Add first and last names to encoded file name
    for(int i = 0; i < lastNameLength + 1; i++){
      encodedFileName[i] = tolower(lastName[i]);
      
    }
    strcat(encodedFileName, "_");
    encodedFileLength = strlen(encodedFileName);

    for(int i = 0; i < firstNameLength; i++){
      encodedFileName[i + encodedFileLength] = tolower(firstName[i]);
    }

    strcat(encodedFileName, "_");

    
  // if answer is yes apply late to name
  printf("Is your assignment late? (y/n)\n");
    scanf(" %c", &lateAnswer);
    if(lateAnswer == 'y' || lateAnswer == 'Y'){
      strcat(encodedFileName, "LATE_");
    }
    encodedFileLength = strlen(encodedFileName);
  //Get studentid
  printf("Enter your Student-ID (format: 222-22-2222): ");
  scanf("%s", studentId);
  for(int i = 7; i < 11; i++){
    encodedFileName[(i - 7) + encodedFileLength] = studentId[i];
  }
  strcat(encodedFileName, "_");

  printf("Enter the time submitted (military time - ex: 18:36 for 6:36p).\n");

  scanf("%d:%d", &submitHour, &submitMin);

  submitHourOne = (char)(floor(submitHour / 10.00) + 48);
  submitHourTwo = (char)((submitHour % 10) + 48);
  submitMinOne = (char)(floor(submitMin / 10.00) + 48);
  submitMinTwo = (char)((submitMin % 10) + 48);
  
  encodedFileLength = strlen(encodedFileName);
  
  for(int i = 0; i < 4; i ++ ){
    currentSpot = i + encodedFileLength;
   
    if(i == 0){
      encodedFileName[i + encodedFileLength] = submitHourOne;
    } else if (i == 1){
      encodedFileName[i + encodedFileLength] = submitHourTwo;
    } else if (i == 2) {
      encodedFileName[i + encodedFileLength] = submitMinOne;
    } else if (i == 3) {
      printf("%d\n", currentSpot);
      encodedFileName[i + encodedFileLength] = submitMinTwo;
    }
  }

  strcat(encodedFileName, "_");


  
  // Add file name to end
  printf("Enter the file name: \n");
  scanf("%s", fileName);
  strcat(encodedFileName, fileName);
  // Output new encoded file name
  printf("%s\n", encodedFileName);
  }

  printf("Thank you for using my file name generator!\n");
  
  return 0;
}
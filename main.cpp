/// ==============================================================================================================
/// The Leap Card Counter (LCC) for those moments when others can't do their job by Paul O'Callaghan
/// How To Use:
/// Edit values on line 14 for the number of tickets and line 16 for the combined price of tickets
/// ==============================================================================================================



#include <iostream>
#include <string>

    ///////////////////////////////////////////////////////////////////////////
    /// Chenge Values Here from 3 and 39.50 to match your report
    static int numberOfTickets = 24; // put in number of tickets here must be a whole number
    // Total Revenue on Leap Report Tickets
    static float totalAmount = 411.00f; // READ ME: Amount in euro must have decimal point and end with f eg 1.00f for 1 euro and 1.50f for €1.50
    ///////////////////////////////////////////////////////////////////////////
    
    
    
    // DONT GO PAST HERE OR EDIT UNLESS YOU KNOW WHAT YOU ARE DOING
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // You've been warned
    
const static int MAX_LOOP = 9000;
const static float ONE = 10,THREE = 19.50f,SEVEN = 40; // Price based on days of ticket

int main()
{
    
    
    
    // use to prevent while loop sticking
    int loopCounter = 0;
    
    // for assigning tickets
    int oneDayTicket = numberOfTickets;
    int threeDayTicket = 0;
    int sevenDayTicket = 0;
    
    // Set min max 
    float max = (float)numberOfTickets * SEVEN;
    float min = (float)numberOfTickets * ONE;
    
    //Check Value is possible and in between    
    if(totalAmount >= min && totalAmount <= max)
    {
        std::cout << "Counting... " << std::endl;
        
        while(loopCounter <= MAX_LOOP)
        {
            // Get current total of allocated tickets
            float currentTotal = (((float)oneDayTicket * ONE) + ((float)threeDayTicket * THREE) + ((float)sevenDayTicket * SEVEN));
        
            // Check it is equal to and if so break from loop 
            if(currentTotal == totalAmount)
            {
                std::cout << "One Day: " << oneDayTicket << std::endl; 
                std::cout << "Three Day: " << threeDayTicket << std::endl; 
                std::cout << "Seven Day: " << sevenDayTicket << std::endl; 
                break;   
            }
            else
            {
                   if(oneDayTicket > 0)
                   {
                       oneDayTicket--;
                       threeDayTicket++;
                   }
                   else if(threeDayTicket == numberOfTickets - sevenDayTicket)
                   {
                        threeDayTicket--; // Same as threeDayTicket -= 1; and threeDayTicket = threeDayTicket - 1;
                        sevenDayTicket++;
                        oneDayTicket = threeDayTicket;
                        threeDayTicket = 0;
                   }
                   else
                   {
                        std::cout << "Amount not possible enter in another price instead " << std::endl;
                        break;
                   }
                   
            } // END IF totalAmount = curretnAmount
            
            
            // For preveting infinite while loop happening
            loopCounter++;
            
            if(loopCounter > MAX_LOOP)
            {
                std::cout << "Error, Couldn't count with value, try another value" << std::endl;
                std::cout << currentTotal;
            }
        } // END WHILE LOOP
    }
    else
    {
        std::cout << "Value not possible" << std::endl;   
    }
}

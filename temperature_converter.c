#include <stdio.h>
#include <ctype.h>
float celsius_to_fahrenheit (float celsius);
float fahrenheit_to_celsius (float fahrenheit);
float celsius_to_kelvin (float celsius);
float kelvin_to_celsius (float kelvin);
void categorize_temperature(float celsius);


int main(){
    int pass = 1;
    char og;
    float temp;
    char change;
    printf("Enter what unit for original temperature, 'F'ahrenheit,'C'elcius, or 'K'elvin: ");
    scanf(" %c",&og);
    printf("Enter the temperature: ");
    scanf(" %f",&temp);
    printf("Enter which temperature to convert to 'F'ahrenheit,'C'elcius, or 'K'elvin: ");
    scanf(" %c",&change);
    float later_weather = 0;
    while(pass ==1){
        if(tolower(og)=='c'){
            later_weather=temp;
            if(celsius_to_kelvin(temp)<0){
                printf("Invalid temperature, below 0 Kelvin");
            }else{
                if(tolower(change)=='k'){
                    temp = celsius_to_kelvin(temp);
                    pass = 0;
                }else if(tolower(change)=='f'){
                    temp = celsius_to_fahrenheit(temp);
                    pass = 0;
                }else{
                    printf("Can't convert to that unit");
                }
            }
        }else if(tolower(og)=='f'){
            if (tolower(change)=='k'){
                temp = fahrenheit_to_celsius(temp);
                later_weather = temp;
                if(celsius_to_kelvin(temp)<0){
                    printf("Invalid temperature, below 0 Kelvin");
                }else{
                    temp =celsius_to_kelvin(temp);
                    pass=0;
                }
            }else if(tolower(change)=='c'){
                temp = fahrenheit_to_celsius(temp);
                later_weather = temp;
                if(celsius_to_kelvin(temp)<0){
                    printf("Invalid temperature, below 0 Kelvin");
                }else{
                    pass = 0;
                }
            }else{
                printf("Can't convert to that unit");
            }
        }else if(tolower(og)=='k'){
            if(temp<0){
                printf("Invalid temperature, below 0 Kelvin");
            }if(tolower(change)=='c'){
                temp = kelvin_to_celsius(temp);
                later_weather = temp;
                pass=0;
            }else if(tolower(change)=='f'){
                temp = kelvin_to_celsius(temp);
                later_weather = temp;
                temp = celsius_to_fahrenheit(temp);
                pass = 0;
            }else{
                printf("Can't convert to that unit");
            }
            
        }else{
            printf("Not a valid starting unit");
        }
        if(pass==1){
            printf("\n");
            printf("Enter what unit for original temperature, 'F'ahrenheit,'C'elcius, or 'K'elvin: ");
            scanf(" %c",&og);
            printf("Enter the temperature: ");
            scanf(" %f",&temp);
            printf("Enter which temperature to convert to 'F'ahrenheit,'C'elcius, or 'K'elvin:");
            scanf(" %c",&change);
        }
        

    }
    printf("Converted temperature: %f \n",temp);
        
    categorize_temperature(later_weather);


    return 0;
}

float celsius_to_fahrenheit (float celsius){
    return celsius*9/5+32;
}
float fahrenheit_to_celsius (float fahrenheit){
    return (fahrenheit-32)*5/9;
}
float celsius_to_kelvin (float celsius){
    return celsius-273.15;
}
float kelvin_to_celsius (float kelvin){
    return kelvin+273.15;
}

void categorize_temperature(float celsius){
    if(celsius<=0){
        printf("Wear a coat");
    }else if(celsius<=10){
        printf("Wear a jacket");
    }else if(celsius<=25){
        printf("Its nice weather");
    }else if(celsius<=35){
        printf("Drink lots of water");
    }else{
        printf("Stay indoors with some air conditioning");
    }
}
